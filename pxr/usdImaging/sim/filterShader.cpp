//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include <PxPhysicsAPI.h>
#include "PxRigidActor.h"
#include "PxShape.h"

#include "filterShader.h"
#include <iostream>

using namespace physx;

namespace {
#define GROUP_SIZE 32

struct PxCollisionBitMap {
    PX_INLINE PxCollisionBitMap() : enable(true) {}

    bool operator()() const { return enable; }
    bool& operator=(const bool& v) {
        enable = v;
        return enable;
    }

private:
    bool enable;
};

/**
\brief 64-bit mask used for collision filtering.

The collision filtering equation for 2 objects o0 and o1 is:

<pre> (G0 op0 K0) op2 (G1 op1 K1) == b </pre>

with

<ul>
<li> G0 = GroupsMask for object o0. See PxSetGroupsMask </li>
<li> G1 = GroupsMask for object o1. See PxSetGroupsMask </li>
<li> K0 = filtering constant 0. See PxSetFilterConstants </li>
<li> K1 = filtering constant 1. See PxSetFilterConstants </li>
<li> b = filtering boolean. See PxSetFilterBool </li>
<li> op0, op1, op2 = filtering operations. See PxSetFilterOps </li>
</ul>

If the filtering equation is true, collision detection is enabled.

@see PxSetFilterOps()
*/
class GroupsMask {
public:
    PX_INLINE GroupsMask() : bits0(0), bits1(0), bits2(0), bits3(0) {}
    PX_INLINE ~GroupsMask() = default;

    PxU16 bits0, bits1, bits2, bits3;
};

/**
\brief Collision filtering operations.

@see GroupsMask
*/
struct FilterOp {
    enum Enum {
        PX_FILTEROP_AND,
        PX_FILTEROP_OR,
        PX_FILTEROP_XOR,
        PX_FILTEROP_NAND,
        PX_FILTEROP_NOR,
        PX_FILTEROP_NXOR,
        PX_FILTEROP_SWAP_AND
    };
};

PxCollisionBitMap gCollisionTable[GROUP_SIZE][GROUP_SIZE];

FilterOp::Enum gFilterOps[3] = {FilterOp::PX_FILTEROP_AND, FilterOp::PX_FILTEROP_AND, FilterOp::PX_FILTEROP_AND};

GroupsMask gFilterConstants[2];

bool gFilterBool = false;

void gAND(GroupsMask& results, const GroupsMask& mask0, const GroupsMask& mask1) {
    results.bits0 = PxU16(mask0.bits0 & mask1.bits0);
    results.bits1 = PxU16(mask0.bits1 & mask1.bits1);
    results.bits2 = PxU16(mask0.bits2 & mask1.bits2);
    results.bits3 = PxU16(mask0.bits3 & mask1.bits3);
}
void gOR(GroupsMask& results, const GroupsMask& mask0, const GroupsMask& mask1) {
    results.bits0 = PxU16(mask0.bits0 | mask1.bits0);
    results.bits1 = PxU16(mask0.bits1 | mask1.bits1);
    results.bits2 = PxU16(mask0.bits2 | mask1.bits2);
    results.bits3 = PxU16(mask0.bits3 | mask1.bits3);
}
void gXOR(GroupsMask& results, const GroupsMask& mask0, const GroupsMask& mask1) {
    results.bits0 = PxU16(mask0.bits0 ^ mask1.bits0);
    results.bits1 = PxU16(mask0.bits1 ^ mask1.bits1);
    results.bits2 = PxU16(mask0.bits2 ^ mask1.bits2);
    results.bits3 = PxU16(mask0.bits3 ^ mask1.bits3);
}
void gNAND(GroupsMask& results, const GroupsMask& mask0, const GroupsMask& mask1) {
    results.bits0 = PxU16(~(mask0.bits0 & mask1.bits0));
    results.bits1 = PxU16(~(mask0.bits1 & mask1.bits1));
    results.bits2 = PxU16(~(mask0.bits2 & mask1.bits2));
    results.bits3 = PxU16(~(mask0.bits3 & mask1.bits3));
}
void gNOR(GroupsMask& results, const GroupsMask& mask0, const GroupsMask& mask1) {
    results.bits0 = PxU16(~(mask0.bits0 | mask1.bits0));
    results.bits1 = PxU16(~(mask0.bits1 | mask1.bits1));
    results.bits2 = PxU16(~(mask0.bits2 | mask1.bits2));
    results.bits3 = PxU16(~(mask0.bits3 | mask1.bits3));
}
void gNXOR(GroupsMask& results, const GroupsMask& mask0, const GroupsMask& mask1) {
    results.bits0 = PxU16(~(mask0.bits0 ^ mask1.bits0));
    results.bits1 = PxU16(~(mask0.bits1 ^ mask1.bits1));
    results.bits2 = PxU16(~(mask0.bits2 ^ mask1.bits2));
    results.bits3 = PxU16(~(mask0.bits3 ^ mask1.bits3));
}

void gSWAP_AND(GroupsMask& results, const GroupsMask& mask0, const GroupsMask& mask1) {
    results.bits0 = PxU16(mask0.bits0 & mask1.bits2);
    results.bits1 = PxU16(mask0.bits1 & mask1.bits3);
    results.bits2 = PxU16(mask0.bits2 & mask1.bits0);
    results.bits3 = PxU16(mask0.bits3 & mask1.bits1);
}

typedef void (*FilterFunction)(GroupsMask& results, const GroupsMask& mask0, const GroupsMask& mask1);

FilterFunction const gTable[] = {gAND, gOR, gXOR, gNAND, gNOR, gNXOR, gSWAP_AND};

PxFilterData convert(const GroupsMask& mask) {
    PxFilterData fd;

    fd.word2 = PxU32(mask.bits0 | (mask.bits1 << 16));
    fd.word3 = PxU32(mask.bits2 | (mask.bits3 << 16));

    return fd;
}

GroupsMask convert(const PxFilterData& fd) {
    GroupsMask mask;

    mask.bits0 = PxU16((fd.word2 & 0xffff));
    mask.bits1 = PxU16((fd.word2 >> 16));
    mask.bits2 = PxU16((fd.word3 & 0xffff));
    mask.bits3 = PxU16((fd.word3 >> 16));

    return mask;
}

bool getFilterData(const PxActor& actor, PxFilterData& fd) {
    PxActorType::Enum aType = actor.getType();
    switch (aType) {
        case PxActorType::eRIGID_DYNAMIC:
        case PxActorType::eRIGID_STATIC:
        case PxActorType::eARTICULATION_LINK: {
            const auto& rActor = static_cast<const PxRigidActor&>(actor);
            PX_CHECK_AND_RETURN_VAL(rActor.getNbShapes() >= 1, "There must be a shape in actor", false);

            PxShape* shape = nullptr;
            rActor.getShapes(&shape, 1);

            fd = shape->getSimulationFilterData();
        } break;

        case PxActorType::eACTOR_COUNT:
        case PxActorType::eACTOR_FORCE_DWORD:
            break;
    }

    return true;
}

PX_FORCE_INLINE void adjustFilterData(bool groupsMask, const PxFilterData& src, PxFilterData& dst) {
    if (groupsMask) {
        dst.word2 = src.word2;
        dst.word3 = src.word3;
    } else
        dst.word0 = src.word0;
}

template <bool TGroupsMask>
void setFilterData(PxActor& actor, const PxFilterData& fd) {
    PxActorType::Enum aType = actor.getType();
    switch (aType) {
        case PxActorType::eRIGID_DYNAMIC:
        case PxActorType::eRIGID_STATIC:
        case PxActorType::eARTICULATION_LINK: {
            const auto& rActor = static_cast<const PxRigidActor&>(actor);

            PxShape* shape;
            for (PxU32 i = 0; i < rActor.getNbShapes(); i++) {
                rActor.getShapes(&shape, 1, i);

                // retrieve current group mask
                PxFilterData resultFd = shape->getSimulationFilterData();

                adjustFilterData(TGroupsMask, fd, resultFd);

                // set new filter data
                shape->setSimulationFilterData(resultFd);
            }
        } break;
        case PxActorType::eACTOR_COUNT:
        case PxActorType::eACTOR_FORCE_DWORD:
            break;
    }
}
}  // namespace

PxFilterFlags TypeAffinityIgnoreFilterShader(PxFilterObjectAttributes attributes0,
                                             PxFilterData filterData0,
                                             PxFilterObjectAttributes attributes1,
                                             PxFilterData filterData1,
                                             PxPairFlags& pairFlags,
                                             const void* constantBlock,
                                             PxU32 constantBlockSize) {
    PX_UNUSED(constantBlock);
    PX_UNUSED(constantBlockSize);

    // let triggers through
    if (PxFilterObjectIsTrigger(attributes0) || PxFilterObjectIsTrigger(attributes1)) {
        pairFlags = PxPairFlag::eTRIGGER_DEFAULT;
        return PxFilterFlags();
    }

    // Collision Group
    if (!gCollisionTable[filterData0.word0][filterData1.word0]()) {
        return PxFilterFlag::eSUPPRESS;
    }

    // Filter function
    GroupsMask g0 = convert(filterData0);
    GroupsMask g1 = convert(filterData1);

    GroupsMask g0k0;
    gTable[gFilterOps[0]](g0k0, g0, gFilterConstants[0]);
    GroupsMask g1k1;
    gTable[gFilterOps[1]](g1k1, g1, gFilterConstants[1]);
    GroupsMask final;
    gTable[gFilterOps[2]](final, g0k0, g1k1);

    bool r = final.bits0 || final.bits1 || final.bits2 || final.bits3;
    if (r != gFilterBool) {
        return PxFilterFlag::eSUPPRESS;
    }

    pairFlags = PxPairFlag::eCONTACT_DEFAULT | PxPairFlag::eNOTIFY_TOUCH_FOUND | PxPairFlag::eNOTIFY_TOUCH_PERSISTS |
                PxPairFlag::eNOTIFY_TOUCH_LOST;

    return PxFilterFlags();
}

inline PxFilterFlags TypeAffinityIgnoreFilterShaderGpu(PxFilterObjectAttributes attributes0,
                                                       PxFilterData filterData0,
                                                       PxFilterObjectAttributes attributes1,
                                                       PxFilterData filterData1,
                                                       PxPairFlags& pairFlags,
                                                       const void* constantBlock,
                                                       PxU32 constantBlockSize) {
    if (PxFilterObjectIsTrigger(attributes0) || PxFilterObjectIsTrigger(attributes1)) {
        pairFlags = PxPairFlag::eTRIGGER_DEFAULT;
        return PxFilterFlag::eDEFAULT;
    }

    // if top 16 bits of word3 are different, the shapes will never collide
    // e.g. they are in different scenes
    if ((filterData0.word3 & 0xffff0000) != (filterData1.word3 & 0xffff0000)) {
        return PxFilterFlag::eKILL;
    }

    // if the lower 16 bits of word3 are the same (e.g. articulation id)
    // if word2 has a matching bit (e.g. door and frame both set the same bit)
    // the shapes will not collide (e.g. ignore collisions within each articulation)
    if ((filterData0.word2 & filterData1.word2) && ((filterData0.word3 & 0xffff) == (filterData1.word3 & 0xffff))) {
        return PxFilterFlag::eKILL;
    }

    // Otherwise, apply MuJoCo's collision model to word0 and word1
    if ((filterData0.word0 & filterData1.word1) || (filterData1.word0 & filterData0.word1)) {
        pairFlags = PxPairFlag::eCONTACT_DEFAULT;
        return PxFilterFlag::eDEFAULT;
    }
    return PxFilterFlag::eKILL;
}
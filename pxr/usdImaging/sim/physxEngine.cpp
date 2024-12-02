//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "physxEngine.h"
#include "pxr/base/tf/diagnostic.h"

using namespace physx;
using namespace pxr;

namespace sim {
static PxDefaultAllocator gDefaultAllocatorCallback;

class UsdErrorCallback : public PxErrorCallback {
    PxErrorCode::Enum mLastErrorCode = PxErrorCode::eNO_ERROR;

public:
    void reportError(PxErrorCode::Enum code, const char *message, const char *file, int line) override {
        mLastErrorCode = code;

#ifdef NDEBUG
        TF_WARN("{%s}", message);
#else
        TF_WARN("{%s}:{%i}: {%s}", file, line, message);
#endif
    }
    PxErrorCode::Enum getLastErrorCode() {
        auto code = mLastErrorCode;
        mLastErrorCode = PxErrorCode::eNO_ERROR;
        return code;
    }
};

static UsdErrorCallback gDefaultErrorCallback;

static std::weak_ptr<PhysxEngine> gEngine;
std::shared_ptr<PhysxEngine> PhysxEngine::Get(float toleranceLength, float toleranceSpeed) {
    auto engine = gEngine.lock();
    if (!engine) {
        gEngine = engine = std::make_shared<PhysxEngine>(toleranceLength, toleranceSpeed);
    }
    return engine;
}

std::shared_ptr<PhysxEngine> PhysxEngine::GetIfExists() { return gEngine.lock(); }

PhysxEngine::PhysxEngine(float toleranceLength, float toleranceSpeed) {
    mPxFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, gDefaultAllocatorCallback, gDefaultErrorCallback);
    if (!mPxFoundation) {
        throw std::runtime_error("PhysX foundation creation failed");
    }

    PxTolerancesScale toleranceScale(toleranceLength, toleranceSpeed);

    mPxPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *mPxFoundation, toleranceScale);
    if (!mPxPhysics) {
        throw std::runtime_error("PhysX creation failed");
    }
    if (!PxInitExtensions(*mPxPhysics, nullptr)) {
        throw std::runtime_error("PhysX extension initialization failed");
    }
}

PhysxEngine::~PhysxEngine() {
    PxCloseExtensions();
    mPxPhysics->release();
    mPxFoundation->release();
}
}  // namespace sim
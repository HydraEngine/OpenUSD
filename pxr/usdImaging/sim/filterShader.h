//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <PxPhysicsAPI.h>

physx::PxFilterFlags TypeAffinityIgnoreFilterShader(physx::PxFilterObjectAttributes attributes0,
                                                    physx::PxFilterData filterData0,
                                                    physx::PxFilterObjectAttributes attributes1,
                                                    physx::PxFilterData filterData1,
                                                    physx::PxPairFlags& pairFlags,
                                                    const void* constantBlock,
                                                    physx::PxU32 constantBlockSize);
//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <PxPhysicsAPI.h>
#include <memory>

namespace sim {
class PhysxEngine {
public:
    static std::shared_ptr<PhysxEngine> Get(float toleranceLength = 0.1f, float toleranceSpeed = 0.2f);

    static std::shared_ptr<PhysxEngine> GetIfExists();

    PhysxEngine(float toleranceLength, float toleranceSpeed);
    ::physx::PxPhysics *getPxPhysics() const { return mPxPhysics; }

    ~PhysxEngine();

private:
    ::physx::PxPhysics *mPxPhysics;
    ::physx::PxFoundation *mPxFoundation;
};
}  // namespace sim

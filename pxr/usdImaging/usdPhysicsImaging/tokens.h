//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/usdImaging/usdPhysicsImaging/api.h"
#include <pxr/imaging/hd/schema.h>

PXR_NAMESPACE_OPEN_SCOPE

#define HD_PHYSICS_SCHEMA_TOKENS     \
    (physicsScene)(physicsMaterial)( \
            physicsArticulationRoot)(physicsCollision)(physicsMeshCollision)(physicsDrive)(physicsFilteredPairs)(physicsLimit)(physicsMass)(physicsRigidBody)(physicsJoint)(physicsDistanceJoint)(physicsFixedJoint)

TF_DECLARE_PUBLIC_TOKENS(HdPhysicsSchemaTokens, USDPHYSICSIMAGING_API, HD_PHYSICS_SCHEMA_TOKENS);

PXR_NAMESPACE_CLOSE_SCOPE
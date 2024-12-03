//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include <PxPhysicsAPI.h>
#include "pxr/base/gf/vec4f.h"
#include "pxr/base/gf/vec3f.h"
#include "pxr/base/gf/vec2f.h"
#include "pxr/base/gf/quatf.h"
#include "pxr/base/gf/quatd.h"
#include "pxr/base/gf/matrix4f.h"
#include "pxr/base/gf/matrix4d.h"
#include "pxr/base/gf/rotation.h"

physx::PxVec3 convert(const pxr::GfVec3f &value);

physx::PxVec3 convert(const pxr::GfVec3d &value);

physx::PxVec4 convert(const pxr::GfVec4f &value);

physx::PxVec4 convert(const pxr::GfVec4d &value);

physx::PxQuat convert(const pxr::GfQuatf &value);

physx::PxQuat convert(const pxr::GfQuatd &value);

physx::PxTransform convert(const pxr::GfMatrix4f &value);

physx::PxTransform convert(const pxr::GfMatrix4d &value);

pxr::GfMatrix4d convert(const physx::PxTransform &value);

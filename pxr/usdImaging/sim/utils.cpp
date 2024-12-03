//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "utils.h"

physx::PxVec3 convert(const pxr::GfVec3f &value) { return {value[0], value[1], value[2]}; }

physx::PxVec4 convert(const pxr::GfVec4f &value) { return {value[0], value[1], value[2], value[3]}; }

physx::PxQuat convert(const pxr::GfQuatf &value) {
    auto img = value.GetImaginary();
    return {img[0], img[1], img[2], value.GetReal()};
}

physx::PxTransform convert(const pxr::GfMatrix4f &value) {
    const auto translation = value.ExtractTranslation();
    const auto rotation = value.ExtractRotationQuat();
    physx::PxTransform result;
    result.p = convert(translation);
    result.q = convert(rotation);
    return result;
}

physx::PxTransform convert(const pxr::GfMatrix4d &value) {
    const auto translation = value.ExtractTranslation();
    const auto rotation = value.ExtractRotationQuat();
    const auto img = rotation.GetImaginary();
    physx::PxTransform result;
    result.p = physx::PxVec3{static_cast<float>(translation[0]), static_cast<float>(translation[1]),
                             static_cast<float>(translation[2])};
    result.q = physx::PxQuat{static_cast<float>(img[0]), static_cast<float>(img[1]), static_cast<float>(img[2]),
                             static_cast<float>(rotation.GetReal())};
    return result;
}

pxr::GfMatrix4d convert(const physx::PxTransform &value) {
    const auto translation = value.p;
    const auto quat = value.q;
    const auto t = pxr::GfVec3d(translation.x, translation.y, translation.z);
    const auto q = pxr::GfQuatd(quat.w, {quat.x, quat.y, quat.z});
    const auto rot = pxr::GfRotation(q);
    return {rot, t};
}
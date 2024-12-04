//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
// GENERATED FILE.  DO NOT EDIT.
#include "pxr/external/boost/python/class.hpp"
#include "pxr/usd/usdPhysX/tokens.h"

PXR_NAMESPACE_USING_DIRECTIVE

#define _ADD_TOKEN(cls, name) \
    cls.add_static_property(#name, +[]() { return UsdPhysXTokens->name.GetString(); });

void wrapUsdPhysXTokens()
{
    pxr_boost::python::class_<UsdPhysXTokensType, pxr_boost::python::noncopyable>
        cls("Tokens", pxr_boost::python::no_init);
    _ADD_TOKEN(cls, jointState);
    _ADD_TOKEN(cls, jointState_MultipleApplyTemplate_PhysicsPosition);
    _ADD_TOKEN(cls, jointState_MultipleApplyTemplate_PhysicsVelocity);
    _ADD_TOKEN(cls, PhysxSchemaJointStateAPI);
}

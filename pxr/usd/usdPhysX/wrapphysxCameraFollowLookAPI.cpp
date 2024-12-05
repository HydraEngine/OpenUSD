//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxCameraFollowLookAPI.h"
#include "pxr/usd/usd/schemaBase.h"

#include "pxr/usd/sdf/primSpec.h"

#include "pxr/usd/usd/pyConversions.h"
#include "pxr/base/tf/pyAnnotatedBoolResult.h"
#include "pxr/base/tf/pyContainerConversions.h"
#include "pxr/base/tf/pyResultConversions.h"
#include "pxr/base/tf/pyUtils.h"
#include "pxr/base/tf/wrapTypeHelpers.h"

#include "pxr/external/boost/python.hpp"

#include <string>

PXR_NAMESPACE_USING_DIRECTIVE

using namespace pxr_boost::python;

namespace {

#define WRAP_CUSTOM                                                     \
    template <class Cls> static void _CustomWrapCode(Cls &_class)

// fwd decl.
WRAP_CUSTOM;

        
static UsdAttribute
_CreateDownHillGroundAngleAttr(UsdPhysXPhysxCameraFollowLookAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateDownHillGroundAngleAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateDownHillGroundPitchAttr(UsdPhysXPhysxCameraFollowLookAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateDownHillGroundPitchAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateFollowReverseDistanceAttr(UsdPhysXPhysxCameraFollowLookAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateFollowReverseDistanceAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateFollowReverseSpeedAttr(UsdPhysXPhysxCameraFollowLookAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateFollowReverseSpeedAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateUpHillGroundAngleAttr(UsdPhysXPhysxCameraFollowLookAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateUpHillGroundAngleAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateUpHillGroundPitchAttr(UsdPhysXPhysxCameraFollowLookAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateUpHillGroundPitchAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateVelocityBlendTimeConstantAttr(UsdPhysXPhysxCameraFollowLookAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateVelocityBlendTimeConstantAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}

static std::string
_Repr(const UsdPhysXPhysxCameraFollowLookAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdPhysX.PhysxCameraFollowLookAPI(%s)",
        primRepr.c_str());
}

struct UsdPhysXPhysxCameraFollowLookAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdPhysXPhysxCameraFollowLookAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdPhysXPhysxCameraFollowLookAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdPhysXPhysxCameraFollowLookAPI::CanApply(prim, &whyNot);
    return UsdPhysXPhysxCameraFollowLookAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdPhysXPhysxCameraFollowLookAPI()
{
    typedef UsdPhysXPhysxCameraFollowLookAPI This;

    UsdPhysXPhysxCameraFollowLookAPI_CanApplyResult::Wrap<UsdPhysXPhysxCameraFollowLookAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("PhysxCameraFollowLookAPI");

    cls
        .def(init<UsdPrim>(arg("prim")))
        .def(init<UsdSchemaBase const&>(arg("schemaObj")))
        .def(TfTypePythonClass())

        .def("Get", &This::Get, (arg("stage"), arg("path")))
        .staticmethod("Get")

        .def("CanApply", &_WrapCanApply, (arg("prim")))
        .staticmethod("CanApply")

        .def("Apply", &This::Apply, (arg("prim")))
        .staticmethod("Apply")

        .def("GetSchemaAttributeNames",
             &This::GetSchemaAttributeNames,
             arg("includeInherited")=true,
             return_value_policy<TfPySequenceToList>())
        .staticmethod("GetSchemaAttributeNames")

        .def("_GetStaticTfType", (TfType const &(*)()) TfType::Find<This>,
             return_value_policy<return_by_value>())
        .staticmethod("_GetStaticTfType")

        .def(!self)

        
        .def("GetDownHillGroundAngleAttr",
             &This::GetDownHillGroundAngleAttr)
        .def("CreateDownHillGroundAngleAttr",
             &_CreateDownHillGroundAngleAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetDownHillGroundPitchAttr",
             &This::GetDownHillGroundPitchAttr)
        .def("CreateDownHillGroundPitchAttr",
             &_CreateDownHillGroundPitchAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetFollowReverseDistanceAttr",
             &This::GetFollowReverseDistanceAttr)
        .def("CreateFollowReverseDistanceAttr",
             &_CreateFollowReverseDistanceAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetFollowReverseSpeedAttr",
             &This::GetFollowReverseSpeedAttr)
        .def("CreateFollowReverseSpeedAttr",
             &_CreateFollowReverseSpeedAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetUpHillGroundAngleAttr",
             &This::GetUpHillGroundAngleAttr)
        .def("CreateUpHillGroundAngleAttr",
             &_CreateUpHillGroundAngleAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetUpHillGroundPitchAttr",
             &This::GetUpHillGroundPitchAttr)
        .def("CreateUpHillGroundPitchAttr",
             &_CreateUpHillGroundPitchAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetVelocityBlendTimeConstantAttr",
             &This::GetVelocityBlendTimeConstantAttr)
        .def("CreateVelocityBlendTimeConstantAttr",
             &_CreateVelocityBlendTimeConstantAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))

        .def("__repr__", ::_Repr)
    ;

    _CustomWrapCode(cls);
}

// ===================================================================== //
// Feel free to add custom code below this line, it will be preserved by 
// the code generator.  The entry point for your custom code should look
// minimally like the following:
//
// WRAP_CUSTOM {
//     _class
//         .def("MyCustomMethod", ...)
//     ;
// }
//
// Of course any other ancillary or support code may be provided.
// 
// Just remember to wrap code in the appropriate delimiters:
// 'namespace {', '}'.
//
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--

namespace {

WRAP_CUSTOM {
}

}

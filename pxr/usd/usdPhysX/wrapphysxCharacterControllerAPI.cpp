//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxCharacterControllerAPI.h"
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
_CreateClimbingModeAttr(UsdPhysXphysxCharacterControllerAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateClimbingModeAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Token), writeSparsely);
}
        
static UsdAttribute
_CreateContactOffsetAttr(UsdPhysXphysxCharacterControllerAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateContactOffsetAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateInvisibleWallHeightAttr(UsdPhysXphysxCharacterControllerAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateInvisibleWallHeightAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMaxJumpHeightAttr(UsdPhysXphysxCharacterControllerAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMaxJumpHeightAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMoveTargetAttr(UsdPhysXphysxCharacterControllerAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMoveTargetAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Vector3f), writeSparsely);
}
        
static UsdAttribute
_CreateNonWalkableModeAttr(UsdPhysXphysxCharacterControllerAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateNonWalkableModeAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Token), writeSparsely);
}
        
static UsdAttribute
_CreateScaleCoeffAttr(UsdPhysXphysxCharacterControllerAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateScaleCoeffAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateSlopeLimitAttr(UsdPhysXphysxCharacterControllerAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSlopeLimitAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateStepOffsetAttr(UsdPhysXphysxCharacterControllerAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateStepOffsetAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateUpAxisAttr(UsdPhysXphysxCharacterControllerAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateUpAxisAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Token), writeSparsely);
}
        
static UsdAttribute
_CreateVolumeGrowthAttr(UsdPhysXphysxCharacterControllerAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateVolumeGrowthAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}

static std::string
_Repr(const UsdPhysXphysxCharacterControllerAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdPhysX.physxCharacterControllerAPI(%s)",
        primRepr.c_str());
}

struct UsdPhysXphysxCharacterControllerAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdPhysXphysxCharacterControllerAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdPhysXphysxCharacterControllerAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdPhysXphysxCharacterControllerAPI::CanApply(prim, &whyNot);
    return UsdPhysXphysxCharacterControllerAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdPhysXphysxCharacterControllerAPI()
{
    typedef UsdPhysXphysxCharacterControllerAPI This;

    UsdPhysXphysxCharacterControllerAPI_CanApplyResult::Wrap<UsdPhysXphysxCharacterControllerAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("physxCharacterControllerAPI");

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

        
        .def("GetClimbingModeAttr",
             &This::GetClimbingModeAttr)
        .def("CreateClimbingModeAttr",
             &_CreateClimbingModeAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetContactOffsetAttr",
             &This::GetContactOffsetAttr)
        .def("CreateContactOffsetAttr",
             &_CreateContactOffsetAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetInvisibleWallHeightAttr",
             &This::GetInvisibleWallHeightAttr)
        .def("CreateInvisibleWallHeightAttr",
             &_CreateInvisibleWallHeightAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMaxJumpHeightAttr",
             &This::GetMaxJumpHeightAttr)
        .def("CreateMaxJumpHeightAttr",
             &_CreateMaxJumpHeightAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMoveTargetAttr",
             &This::GetMoveTargetAttr)
        .def("CreateMoveTargetAttr",
             &_CreateMoveTargetAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetNonWalkableModeAttr",
             &This::GetNonWalkableModeAttr)
        .def("CreateNonWalkableModeAttr",
             &_CreateNonWalkableModeAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetScaleCoeffAttr",
             &This::GetScaleCoeffAttr)
        .def("CreateScaleCoeffAttr",
             &_CreateScaleCoeffAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSlopeLimitAttr",
             &This::GetSlopeLimitAttr)
        .def("CreateSlopeLimitAttr",
             &_CreateSlopeLimitAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetStepOffsetAttr",
             &This::GetStepOffsetAttr)
        .def("CreateStepOffsetAttr",
             &_CreateStepOffsetAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetUpAxisAttr",
             &This::GetUpAxisAttr)
        .def("CreateUpAxisAttr",
             &_CreateUpAxisAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetVolumeGrowthAttr",
             &This::GetVolumeGrowthAttr)
        .def("CreateVolumeGrowthAttr",
             &_CreateVolumeGrowthAttr,
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

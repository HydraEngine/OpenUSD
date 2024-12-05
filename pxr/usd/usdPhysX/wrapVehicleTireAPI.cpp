//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleTireAPI.h"
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
_CreateCamberStiffnessAttr(UsdPhysXVehicleTireAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateCamberStiffnessAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateFrictionVsSlipGraphAttr(UsdPhysXVehicleTireAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateFrictionVsSlipGraphAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float2Array), writeSparsely);
}
        
static UsdAttribute
_CreateLateralStiffnessGraphAttr(UsdPhysXVehicleTireAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLateralStiffnessGraphAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float2), writeSparsely);
}
        
static UsdAttribute
_CreateLongitudinalStiffnessAttr(UsdPhysXVehicleTireAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLongitudinalStiffnessAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateRestLoadAttr(UsdPhysXVehicleTireAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateRestLoadAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}

static std::string
_Repr(const UsdPhysXVehicleTireAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdPhysX.VehicleTireAPI(%s)",
        primRepr.c_str());
}

struct UsdPhysXVehicleTireAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdPhysXVehicleTireAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdPhysXVehicleTireAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdPhysXVehicleTireAPI::CanApply(prim, &whyNot);
    return UsdPhysXVehicleTireAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdPhysXVehicleTireAPI()
{
    typedef UsdPhysXVehicleTireAPI This;

    UsdPhysXVehicleTireAPI_CanApplyResult::Wrap<UsdPhysXVehicleTireAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("VehicleTireAPI");

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

        
        .def("GetCamberStiffnessAttr",
             &This::GetCamberStiffnessAttr)
        .def("CreateCamberStiffnessAttr",
             &_CreateCamberStiffnessAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetFrictionVsSlipGraphAttr",
             &This::GetFrictionVsSlipGraphAttr)
        .def("CreateFrictionVsSlipGraphAttr",
             &_CreateFrictionVsSlipGraphAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLateralStiffnessGraphAttr",
             &This::GetLateralStiffnessGraphAttr)
        .def("CreateLateralStiffnessGraphAttr",
             &_CreateLateralStiffnessGraphAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLongitudinalStiffnessAttr",
             &This::GetLongitudinalStiffnessAttr)
        .def("CreateLongitudinalStiffnessAttr",
             &_CreateLongitudinalStiffnessAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetRestLoadAttr",
             &This::GetRestLoadAttr)
        .def("CreateRestLoadAttr",
             &_CreateRestLoadAttr,
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

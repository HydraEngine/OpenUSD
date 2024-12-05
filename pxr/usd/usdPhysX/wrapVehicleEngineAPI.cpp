//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleEngineAPI.h"
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
_CreateDampingRateFullThrottleAttr(UsdPhysXVehicleEngineAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateDampingRateFullThrottleAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateDampingRateZeroThrottleClutchDisengagedAttr(UsdPhysXVehicleEngineAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateDampingRateZeroThrottleClutchDisengagedAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateDampingRateZeroThrottleClutchEngagedAttr(UsdPhysXVehicleEngineAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateDampingRateZeroThrottleClutchEngagedAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateIdleRotationSpeedAttr(UsdPhysXVehicleEngineAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateIdleRotationSpeedAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMaxRotationSpeedAttr(UsdPhysXVehicleEngineAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMaxRotationSpeedAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMoiAttr(UsdPhysXVehicleEngineAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMoiAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreatePeakTorqueAttr(UsdPhysXVehicleEngineAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreatePeakTorqueAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateTorqueCurveAttr(UsdPhysXVehicleEngineAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateTorqueCurveAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float2Array), writeSparsely);
}

static std::string
_Repr(const UsdPhysXVehicleEngineAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdPhysX.VehicleEngineAPI(%s)",
        primRepr.c_str());
}

struct UsdPhysXVehicleEngineAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdPhysXVehicleEngineAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdPhysXVehicleEngineAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdPhysXVehicleEngineAPI::CanApply(prim, &whyNot);
    return UsdPhysXVehicleEngineAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdPhysXVehicleEngineAPI()
{
    typedef UsdPhysXVehicleEngineAPI This;

    UsdPhysXVehicleEngineAPI_CanApplyResult::Wrap<UsdPhysXVehicleEngineAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("VehicleEngineAPI");

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

        
        .def("GetDampingRateFullThrottleAttr",
             &This::GetDampingRateFullThrottleAttr)
        .def("CreateDampingRateFullThrottleAttr",
             &_CreateDampingRateFullThrottleAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetDampingRateZeroThrottleClutchDisengagedAttr",
             &This::GetDampingRateZeroThrottleClutchDisengagedAttr)
        .def("CreateDampingRateZeroThrottleClutchDisengagedAttr",
             &_CreateDampingRateZeroThrottleClutchDisengagedAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetDampingRateZeroThrottleClutchEngagedAttr",
             &This::GetDampingRateZeroThrottleClutchEngagedAttr)
        .def("CreateDampingRateZeroThrottleClutchEngagedAttr",
             &_CreateDampingRateZeroThrottleClutchEngagedAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetIdleRotationSpeedAttr",
             &This::GetIdleRotationSpeedAttr)
        .def("CreateIdleRotationSpeedAttr",
             &_CreateIdleRotationSpeedAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMaxRotationSpeedAttr",
             &This::GetMaxRotationSpeedAttr)
        .def("CreateMaxRotationSpeedAttr",
             &_CreateMaxRotationSpeedAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMoiAttr",
             &This::GetMoiAttr)
        .def("CreateMoiAttr",
             &_CreateMoiAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetPeakTorqueAttr",
             &This::GetPeakTorqueAttr)
        .def("CreatePeakTorqueAttr",
             &_CreatePeakTorqueAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetTorqueCurveAttr",
             &This::GetTorqueCurveAttr)
        .def("CreateTorqueCurveAttr",
             &_CreateTorqueCurveAttr,
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

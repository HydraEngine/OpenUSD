//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleAPI.h"
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
_CreateHighForwardSpeedSubStepCountAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateHighForwardSpeedSubStepCountAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}
        
static UsdAttribute
_CreateLateralStickyTireDampingAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLateralStickyTireDampingAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateLateralStickyTireThresholdSpeedAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLateralStickyTireThresholdSpeedAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateLateralStickyTireThresholdTimeAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLateralStickyTireThresholdTimeAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateLimitSuspensionExpansionVelocityAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLimitSuspensionExpansionVelocityAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateLongitudinalStickyTireDampingAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLongitudinalStickyTireDampingAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateLongitudinalStickyTireThresholdSpeedAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLongitudinalStickyTireThresholdSpeedAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateLongitudinalStickyTireThresholdTimeAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLongitudinalStickyTireThresholdTimeAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateLowForwardSpeedSubStepCountAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLowForwardSpeedSubStepCountAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}
        
static UsdAttribute
_CreateMinActiveLongitudinalSlipDenominatorAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMinActiveLongitudinalSlipDenominatorAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMinLateralSlipDenominatorAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMinLateralSlipDenominatorAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMinPassiveLongitudinalSlipDenominatorAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMinPassiveLongitudinalSlipDenominatorAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateSubStepThresholdLongitudinalSpeedAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSubStepThresholdLongitudinalSpeedAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateSuspensionLineQueryTypeAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSuspensionLineQueryTypeAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Token), writeSparsely);
}
        
static UsdAttribute
_CreateVehicleEnabledAttr(UsdPhysXVehicleAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateVehicleEnabledAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}

static std::string
_Repr(const UsdPhysXVehicleAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdPhysX.VehicleAPI(%s)",
        primRepr.c_str());
}

struct UsdPhysXVehicleAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdPhysXVehicleAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdPhysXVehicleAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdPhysXVehicleAPI::CanApply(prim, &whyNot);
    return UsdPhysXVehicleAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdPhysXVehicleAPI()
{
    typedef UsdPhysXVehicleAPI This;

    UsdPhysXVehicleAPI_CanApplyResult::Wrap<UsdPhysXVehicleAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("VehicleAPI");

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

        
        .def("GetHighForwardSpeedSubStepCountAttr",
             &This::GetHighForwardSpeedSubStepCountAttr)
        .def("CreateHighForwardSpeedSubStepCountAttr",
             &_CreateHighForwardSpeedSubStepCountAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLateralStickyTireDampingAttr",
             &This::GetLateralStickyTireDampingAttr)
        .def("CreateLateralStickyTireDampingAttr",
             &_CreateLateralStickyTireDampingAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLateralStickyTireThresholdSpeedAttr",
             &This::GetLateralStickyTireThresholdSpeedAttr)
        .def("CreateLateralStickyTireThresholdSpeedAttr",
             &_CreateLateralStickyTireThresholdSpeedAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLateralStickyTireThresholdTimeAttr",
             &This::GetLateralStickyTireThresholdTimeAttr)
        .def("CreateLateralStickyTireThresholdTimeAttr",
             &_CreateLateralStickyTireThresholdTimeAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLimitSuspensionExpansionVelocityAttr",
             &This::GetLimitSuspensionExpansionVelocityAttr)
        .def("CreateLimitSuspensionExpansionVelocityAttr",
             &_CreateLimitSuspensionExpansionVelocityAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLongitudinalStickyTireDampingAttr",
             &This::GetLongitudinalStickyTireDampingAttr)
        .def("CreateLongitudinalStickyTireDampingAttr",
             &_CreateLongitudinalStickyTireDampingAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLongitudinalStickyTireThresholdSpeedAttr",
             &This::GetLongitudinalStickyTireThresholdSpeedAttr)
        .def("CreateLongitudinalStickyTireThresholdSpeedAttr",
             &_CreateLongitudinalStickyTireThresholdSpeedAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLongitudinalStickyTireThresholdTimeAttr",
             &This::GetLongitudinalStickyTireThresholdTimeAttr)
        .def("CreateLongitudinalStickyTireThresholdTimeAttr",
             &_CreateLongitudinalStickyTireThresholdTimeAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLowForwardSpeedSubStepCountAttr",
             &This::GetLowForwardSpeedSubStepCountAttr)
        .def("CreateLowForwardSpeedSubStepCountAttr",
             &_CreateLowForwardSpeedSubStepCountAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMinActiveLongitudinalSlipDenominatorAttr",
             &This::GetMinActiveLongitudinalSlipDenominatorAttr)
        .def("CreateMinActiveLongitudinalSlipDenominatorAttr",
             &_CreateMinActiveLongitudinalSlipDenominatorAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMinLateralSlipDenominatorAttr",
             &This::GetMinLateralSlipDenominatorAttr)
        .def("CreateMinLateralSlipDenominatorAttr",
             &_CreateMinLateralSlipDenominatorAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMinPassiveLongitudinalSlipDenominatorAttr",
             &This::GetMinPassiveLongitudinalSlipDenominatorAttr)
        .def("CreateMinPassiveLongitudinalSlipDenominatorAttr",
             &_CreateMinPassiveLongitudinalSlipDenominatorAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSubStepThresholdLongitudinalSpeedAttr",
             &This::GetSubStepThresholdLongitudinalSpeedAttr)
        .def("CreateSubStepThresholdLongitudinalSpeedAttr",
             &_CreateSubStepThresholdLongitudinalSpeedAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSuspensionLineQueryTypeAttr",
             &This::GetSuspensionLineQueryTypeAttr)
        .def("CreateSuspensionLineQueryTypeAttr",
             &_CreateSuspensionLineQueryTypeAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetVehicleEnabledAttr",
             &This::GetVehicleEnabledAttr)
        .def("CreateVehicleEnabledAttr",
             &_CreateVehicleEnabledAttr,
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

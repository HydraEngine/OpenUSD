//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleWheelAPI.h"
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
_CreateDampingRateAttr(UsdPhysXVehicleWheelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateDampingRateAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMassAttr(UsdPhysXVehicleWheelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMassAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMoiAttr(UsdPhysXVehicleWheelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMoiAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateRadiusAttr(UsdPhysXVehicleWheelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateRadiusAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateWidthAttr(UsdPhysXVehicleWheelAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateWidthAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}

static std::string
_Repr(const UsdPhysXVehicleWheelAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdPhysX.VehicleWheelAPI(%s)",
        primRepr.c_str());
}

struct UsdPhysXVehicleWheelAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdPhysXVehicleWheelAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdPhysXVehicleWheelAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdPhysXVehicleWheelAPI::CanApply(prim, &whyNot);
    return UsdPhysXVehicleWheelAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdPhysXVehicleWheelAPI()
{
    typedef UsdPhysXVehicleWheelAPI This;

    UsdPhysXVehicleWheelAPI_CanApplyResult::Wrap<UsdPhysXVehicleWheelAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("VehicleWheelAPI");

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

        
        .def("GetDampingRateAttr",
             &This::GetDampingRateAttr)
        .def("CreateDampingRateAttr",
             &_CreateDampingRateAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMassAttr",
             &This::GetMassAttr)
        .def("CreateMassAttr",
             &_CreateMassAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMoiAttr",
             &This::GetMoiAttr)
        .def("CreateMoiAttr",
             &_CreateMoiAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetRadiusAttr",
             &This::GetRadiusAttr)
        .def("CreateRadiusAttr",
             &_CreateRadiusAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetWidthAttr",
             &This::GetWidthAttr)
        .def("CreateWidthAttr",
             &_CreateWidthAttr,
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

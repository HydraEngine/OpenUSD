//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/vehicleWheelAttachmentAPI.h"
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
_CreateIndexAttr(UsdPhysXVehicleWheelAttachmentAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateIndexAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}
        
static UsdAttribute
_CreateSuspensionFrameOrientationAttr(UsdPhysXVehicleWheelAttachmentAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSuspensionFrameOrientationAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Quatf), writeSparsely);
}
        
static UsdAttribute
_CreateSuspensionFramePositionAttr(UsdPhysXVehicleWheelAttachmentAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSuspensionFramePositionAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Point3f), writeSparsely);
}
        
static UsdAttribute
_CreateSuspensionTravelDirectionAttr(UsdPhysXVehicleWheelAttachmentAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSuspensionTravelDirectionAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Vector3f), writeSparsely);
}
        
static UsdAttribute
_CreateWheelFrameOrientationAttr(UsdPhysXVehicleWheelAttachmentAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateWheelFrameOrientationAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Quatf), writeSparsely);
}
        
static UsdAttribute
_CreateWheelFramePositionAttr(UsdPhysXVehicleWheelAttachmentAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateWheelFramePositionAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Point3f), writeSparsely);
}

static std::string
_Repr(const UsdPhysXVehicleWheelAttachmentAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdPhysX.VehicleWheelAttachmentAPI(%s)",
        primRepr.c_str());
}

struct UsdPhysXVehicleWheelAttachmentAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdPhysXVehicleWheelAttachmentAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdPhysXVehicleWheelAttachmentAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdPhysXVehicleWheelAttachmentAPI::CanApply(prim, &whyNot);
    return UsdPhysXVehicleWheelAttachmentAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdPhysXVehicleWheelAttachmentAPI()
{
    typedef UsdPhysXVehicleWheelAttachmentAPI This;

    UsdPhysXVehicleWheelAttachmentAPI_CanApplyResult::Wrap<UsdPhysXVehicleWheelAttachmentAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("VehicleWheelAttachmentAPI");

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

        
        .def("GetIndexAttr",
             &This::GetIndexAttr)
        .def("CreateIndexAttr",
             &_CreateIndexAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSuspensionFrameOrientationAttr",
             &This::GetSuspensionFrameOrientationAttr)
        .def("CreateSuspensionFrameOrientationAttr",
             &_CreateSuspensionFrameOrientationAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSuspensionFramePositionAttr",
             &This::GetSuspensionFramePositionAttr)
        .def("CreateSuspensionFramePositionAttr",
             &_CreateSuspensionFramePositionAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSuspensionTravelDirectionAttr",
             &This::GetSuspensionTravelDirectionAttr)
        .def("CreateSuspensionTravelDirectionAttr",
             &_CreateSuspensionTravelDirectionAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetWheelFrameOrientationAttr",
             &This::GetWheelFrameOrientationAttr)
        .def("CreateWheelFrameOrientationAttr",
             &_CreateWheelFrameOrientationAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetWheelFramePositionAttr",
             &This::GetWheelFramePositionAttr)
        .def("CreateWheelFramePositionAttr",
             &_CreateWheelFramePositionAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))

        
        .def("GetWheelRel",
             &This::GetWheelRel)
        .def("CreateWheelRel",
             &This::CreateWheelRel)
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

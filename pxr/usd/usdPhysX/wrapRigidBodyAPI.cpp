//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/rigidBodyAPI.h"
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
_CreateAngularDampingAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateAngularDampingAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateCfmScaleAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateCfmScaleAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateContactSlopCoefficientAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateContactSlopCoefficientAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateDisableGravityAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateDisableGravityAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateEnableCCDAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateEnableCCDAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateEnableGyroscopicForcesAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateEnableGyroscopicForcesAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateEnableSpeculativeCCDAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateEnableSpeculativeCCDAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateLinearDampingAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLinearDampingAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateLockedPosAxisAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLockedPosAxisAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}
        
static UsdAttribute
_CreateLockedRotAxisAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateLockedRotAxisAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}
        
static UsdAttribute
_CreateMaxAngularVelocityAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMaxAngularVelocityAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMaxContactImpulseAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMaxContactImpulseAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMaxDepenetrationVelocityAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMaxDepenetrationVelocityAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMaxLinearVelocityAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMaxLinearVelocityAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateRetainAccelerationsAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateRetainAccelerationsAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateSleepThresholdAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSleepThresholdAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateSolveContactAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSolveContactAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateSolverPositionIterationCountAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSolverPositionIterationCountAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}
        
static UsdAttribute
_CreateSolverVelocityIterationCountAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSolverVelocityIterationCountAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}
        
static UsdAttribute
_CreateStabilizationThresholdAttr(UsdPhysXRigidBodyAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateStabilizationThresholdAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}

static std::string
_Repr(const UsdPhysXRigidBodyAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdPhysX.RigidBodyAPI(%s)",
        primRepr.c_str());
}

struct UsdPhysXRigidBodyAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdPhysXRigidBodyAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdPhysXRigidBodyAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdPhysXRigidBodyAPI::CanApply(prim, &whyNot);
    return UsdPhysXRigidBodyAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdPhysXRigidBodyAPI()
{
    typedef UsdPhysXRigidBodyAPI This;

    UsdPhysXRigidBodyAPI_CanApplyResult::Wrap<UsdPhysXRigidBodyAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("RigidBodyAPI");

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

        
        .def("GetAngularDampingAttr",
             &This::GetAngularDampingAttr)
        .def("CreateAngularDampingAttr",
             &_CreateAngularDampingAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetCfmScaleAttr",
             &This::GetCfmScaleAttr)
        .def("CreateCfmScaleAttr",
             &_CreateCfmScaleAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetContactSlopCoefficientAttr",
             &This::GetContactSlopCoefficientAttr)
        .def("CreateContactSlopCoefficientAttr",
             &_CreateContactSlopCoefficientAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetDisableGravityAttr",
             &This::GetDisableGravityAttr)
        .def("CreateDisableGravityAttr",
             &_CreateDisableGravityAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetEnableCCDAttr",
             &This::GetEnableCCDAttr)
        .def("CreateEnableCCDAttr",
             &_CreateEnableCCDAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetEnableGyroscopicForcesAttr",
             &This::GetEnableGyroscopicForcesAttr)
        .def("CreateEnableGyroscopicForcesAttr",
             &_CreateEnableGyroscopicForcesAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetEnableSpeculativeCCDAttr",
             &This::GetEnableSpeculativeCCDAttr)
        .def("CreateEnableSpeculativeCCDAttr",
             &_CreateEnableSpeculativeCCDAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLinearDampingAttr",
             &This::GetLinearDampingAttr)
        .def("CreateLinearDampingAttr",
             &_CreateLinearDampingAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLockedPosAxisAttr",
             &This::GetLockedPosAxisAttr)
        .def("CreateLockedPosAxisAttr",
             &_CreateLockedPosAxisAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetLockedRotAxisAttr",
             &This::GetLockedRotAxisAttr)
        .def("CreateLockedRotAxisAttr",
             &_CreateLockedRotAxisAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMaxAngularVelocityAttr",
             &This::GetMaxAngularVelocityAttr)
        .def("CreateMaxAngularVelocityAttr",
             &_CreateMaxAngularVelocityAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMaxContactImpulseAttr",
             &This::GetMaxContactImpulseAttr)
        .def("CreateMaxContactImpulseAttr",
             &_CreateMaxContactImpulseAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMaxDepenetrationVelocityAttr",
             &This::GetMaxDepenetrationVelocityAttr)
        .def("CreateMaxDepenetrationVelocityAttr",
             &_CreateMaxDepenetrationVelocityAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMaxLinearVelocityAttr",
             &This::GetMaxLinearVelocityAttr)
        .def("CreateMaxLinearVelocityAttr",
             &_CreateMaxLinearVelocityAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetRetainAccelerationsAttr",
             &This::GetRetainAccelerationsAttr)
        .def("CreateRetainAccelerationsAttr",
             &_CreateRetainAccelerationsAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSleepThresholdAttr",
             &This::GetSleepThresholdAttr)
        .def("CreateSleepThresholdAttr",
             &_CreateSleepThresholdAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSolveContactAttr",
             &This::GetSolveContactAttr)
        .def("CreateSolveContactAttr",
             &_CreateSolveContactAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSolverPositionIterationCountAttr",
             &This::GetSolverPositionIterationCountAttr)
        .def("CreateSolverPositionIterationCountAttr",
             &_CreateSolverPositionIterationCountAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSolverVelocityIterationCountAttr",
             &This::GetSolverVelocityIterationCountAttr)
        .def("CreateSolverVelocityIterationCountAttr",
             &_CreateSolverVelocityIterationCountAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetStabilizationThresholdAttr",
             &This::GetStabilizationThresholdAttr)
        .def("CreateStabilizationThresholdAttr",
             &_CreateStabilizationThresholdAttr,
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

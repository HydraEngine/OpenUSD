//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxJointAPI.h"
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
_CreateArmatureAttr(UsdPhysXphysxJointAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateArmatureAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateEnableProjectionAttr(UsdPhysXphysxJointAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateEnableProjectionAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateJointFrictionAttr(UsdPhysXphysxJointAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateJointFrictionAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMaxJointVelocityAttr(UsdPhysXphysxJointAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMaxJointVelocityAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}

static std::string
_Repr(const UsdPhysXphysxJointAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdPhysX.physxJointAPI(%s)",
        primRepr.c_str());
}

struct UsdPhysXphysxJointAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdPhysXphysxJointAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdPhysXphysxJointAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdPhysXphysxJointAPI::CanApply(prim, &whyNot);
    return UsdPhysXphysxJointAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdPhysXphysxJointAPI()
{
    typedef UsdPhysXphysxJointAPI This;

    UsdPhysXphysxJointAPI_CanApplyResult::Wrap<UsdPhysXphysxJointAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("physxJointAPI");

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

        
        .def("GetArmatureAttr",
             &This::GetArmatureAttr)
        .def("CreateArmatureAttr",
             &_CreateArmatureAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetEnableProjectionAttr",
             &This::GetEnableProjectionAttr)
        .def("CreateEnableProjectionAttr",
             &_CreateEnableProjectionAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetJointFrictionAttr",
             &This::GetJointFrictionAttr)
        .def("CreateJointFrictionAttr",
             &_CreateJointFrictionAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMaxJointVelocityAttr",
             &This::GetMaxJointVelocityAttr)
        .def("CreateMaxJointVelocityAttr",
             &_CreateMaxJointVelocityAttr,
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

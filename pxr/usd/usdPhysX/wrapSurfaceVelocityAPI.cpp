//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/surfaceVelocityAPI.h"
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
_CreateSurfaceAngularVelocityAttr(UsdPhysXSurfaceVelocityAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSurfaceAngularVelocityAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Vector3f), writeSparsely);
}
        
static UsdAttribute
_CreateSurfaceVelocityAttr(UsdPhysXSurfaceVelocityAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSurfaceVelocityAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Vector3f), writeSparsely);
}
        
static UsdAttribute
_CreateSurfaceVelocityEnabledAttr(UsdPhysXSurfaceVelocityAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSurfaceVelocityEnabledAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateSurfaceVelocityLocalSpaceAttr(UsdPhysXSurfaceVelocityAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSurfaceVelocityLocalSpaceAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}

static std::string
_Repr(const UsdPhysXSurfaceVelocityAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdPhysX.SurfaceVelocityAPI(%s)",
        primRepr.c_str());
}

struct UsdPhysXSurfaceVelocityAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdPhysXSurfaceVelocityAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdPhysXSurfaceVelocityAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdPhysXSurfaceVelocityAPI::CanApply(prim, &whyNot);
    return UsdPhysXSurfaceVelocityAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdPhysXSurfaceVelocityAPI()
{
    typedef UsdPhysXSurfaceVelocityAPI This;

    UsdPhysXSurfaceVelocityAPI_CanApplyResult::Wrap<UsdPhysXSurfaceVelocityAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("SurfaceVelocityAPI");

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

        
        .def("GetSurfaceAngularVelocityAttr",
             &This::GetSurfaceAngularVelocityAttr)
        .def("CreateSurfaceAngularVelocityAttr",
             &_CreateSurfaceAngularVelocityAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSurfaceVelocityAttr",
             &This::GetSurfaceVelocityAttr)
        .def("CreateSurfaceVelocityAttr",
             &_CreateSurfaceVelocityAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSurfaceVelocityEnabledAttr",
             &This::GetSurfaceVelocityEnabledAttr)
        .def("CreateSurfaceVelocityEnabledAttr",
             &_CreateSurfaceVelocityEnabledAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSurfaceVelocityLocalSpaceAttr",
             &This::GetSurfaceVelocityLocalSpaceAttr)
        .def("CreateSurfaceVelocityLocalSpaceAttr",
             &_CreateSurfaceVelocityLocalSpaceAttr,
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

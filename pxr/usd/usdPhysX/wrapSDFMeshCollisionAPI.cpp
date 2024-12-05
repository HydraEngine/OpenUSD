//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/sDFMeshCollisionAPI.h"
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
_CreateSdfBitsPerSubgridPixelAttr(UsdPhysXSDFMeshCollisionAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSdfBitsPerSubgridPixelAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Token), writeSparsely);
}
        
static UsdAttribute
_CreateSdfEnableRemeshingAttr(UsdPhysXSDFMeshCollisionAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSdfEnableRemeshingAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateSdfMarginAttr(UsdPhysXSDFMeshCollisionAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSdfMarginAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateSdfNarrowBandThicknessAttr(UsdPhysXSDFMeshCollisionAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSdfNarrowBandThicknessAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateSdfResolutionAttr(UsdPhysXSDFMeshCollisionAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSdfResolutionAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}
        
static UsdAttribute
_CreateSdfSubgridResolutionAttr(UsdPhysXSDFMeshCollisionAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSdfSubgridResolutionAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}
        
static UsdAttribute
_CreateSdfTriangleCountReductionFactorAttr(UsdPhysXSDFMeshCollisionAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateSdfTriangleCountReductionFactorAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}

static std::string
_Repr(const UsdPhysXSDFMeshCollisionAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdPhysX.SDFMeshCollisionAPI(%s)",
        primRepr.c_str());
}

struct UsdPhysXSDFMeshCollisionAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdPhysXSDFMeshCollisionAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdPhysXSDFMeshCollisionAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdPhysXSDFMeshCollisionAPI::CanApply(prim, &whyNot);
    return UsdPhysXSDFMeshCollisionAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdPhysXSDFMeshCollisionAPI()
{
    typedef UsdPhysXSDFMeshCollisionAPI This;

    UsdPhysXSDFMeshCollisionAPI_CanApplyResult::Wrap<UsdPhysXSDFMeshCollisionAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("SDFMeshCollisionAPI");

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

        
        .def("GetSdfBitsPerSubgridPixelAttr",
             &This::GetSdfBitsPerSubgridPixelAttr)
        .def("CreateSdfBitsPerSubgridPixelAttr",
             &_CreateSdfBitsPerSubgridPixelAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSdfEnableRemeshingAttr",
             &This::GetSdfEnableRemeshingAttr)
        .def("CreateSdfEnableRemeshingAttr",
             &_CreateSdfEnableRemeshingAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSdfMarginAttr",
             &This::GetSdfMarginAttr)
        .def("CreateSdfMarginAttr",
             &_CreateSdfMarginAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSdfNarrowBandThicknessAttr",
             &This::GetSdfNarrowBandThicknessAttr)
        .def("CreateSdfNarrowBandThicknessAttr",
             &_CreateSdfNarrowBandThicknessAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSdfResolutionAttr",
             &This::GetSdfResolutionAttr)
        .def("CreateSdfResolutionAttr",
             &_CreateSdfResolutionAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSdfSubgridResolutionAttr",
             &This::GetSdfSubgridResolutionAttr)
        .def("CreateSdfSubgridResolutionAttr",
             &_CreateSdfSubgridResolutionAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetSdfTriangleCountReductionFactorAttr",
             &This::GetSdfTriangleCountReductionFactorAttr)
        .def("CreateSdfTriangleCountReductionFactorAttr",
             &_CreateSdfTriangleCountReductionFactorAttr,
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

//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usd/usdPhysX/physxIsosurfaceAPI.h"
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
_CreateAnisotropyMaxAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateAnisotropyMaxAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateAnisotropyMinAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateAnisotropyMinAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateAnisotropyRadiusAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateAnisotropyRadiusAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateEnableAnisotropyAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateEnableAnisotropyAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateGridFilteringPassesAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateGridFilteringPassesAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->String), writeSparsely);
}
        
static UsdAttribute
_CreateGridSmoothingRadiusRelativeToCellSizeAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateGridSmoothingRadiusRelativeToCellSizeAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateGridSpacingAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateGridSpacingAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateIsoSurfaceEnabledAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateIsoSurfaceEnabledAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Bool), writeSparsely);
}
        
static UsdAttribute
_CreateIsosurfaceLevelAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateIsosurfaceLevelAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateKernelRadiusAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateKernelRadiusAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Float), writeSparsely);
}
        
static UsdAttribute
_CreateMaxSubgridsAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMaxSubgridsAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}
        
static UsdAttribute
_CreateMaxTrianglesAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMaxTrianglesAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}
        
static UsdAttribute
_CreateMaxVerticesAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateMaxVerticesAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}
        
static UsdAttribute
_CreateNumMeshSmoothingPassesAttr(UsdPhysXPhysxIsosurfaceAPI &self,
                                      object defaultVal, bool writeSparsely) {
    return self.CreateNumMeshSmoothingPassesAttr(
        UsdPythonToSdfType(defaultVal, SdfValueTypeNames->Int), writeSparsely);
}

static std::string
_Repr(const UsdPhysXPhysxIsosurfaceAPI &self)
{
    std::string primRepr = TfPyRepr(self.GetPrim());
    return TfStringPrintf(
        "UsdPhysX.PhysxIsosurfaceAPI(%s)",
        primRepr.c_str());
}

struct UsdPhysXPhysxIsosurfaceAPI_CanApplyResult : 
    public TfPyAnnotatedBoolResult<std::string>
{
    UsdPhysXPhysxIsosurfaceAPI_CanApplyResult(bool val, std::string const &msg) :
        TfPyAnnotatedBoolResult<std::string>(val, msg) {}
};

static UsdPhysXPhysxIsosurfaceAPI_CanApplyResult
_WrapCanApply(const UsdPrim& prim)
{
    std::string whyNot;
    bool result = UsdPhysXPhysxIsosurfaceAPI::CanApply(prim, &whyNot);
    return UsdPhysXPhysxIsosurfaceAPI_CanApplyResult(result, whyNot);
}

} // anonymous namespace

void wrapUsdPhysXPhysxIsosurfaceAPI()
{
    typedef UsdPhysXPhysxIsosurfaceAPI This;

    UsdPhysXPhysxIsosurfaceAPI_CanApplyResult::Wrap<UsdPhysXPhysxIsosurfaceAPI_CanApplyResult>(
        "_CanApplyResult", "whyNot");

    class_<This, bases<UsdAPISchemaBase> >
        cls("PhysxIsosurfaceAPI");

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

        
        .def("GetAnisotropyMaxAttr",
             &This::GetAnisotropyMaxAttr)
        .def("CreateAnisotropyMaxAttr",
             &_CreateAnisotropyMaxAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetAnisotropyMinAttr",
             &This::GetAnisotropyMinAttr)
        .def("CreateAnisotropyMinAttr",
             &_CreateAnisotropyMinAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetAnisotropyRadiusAttr",
             &This::GetAnisotropyRadiusAttr)
        .def("CreateAnisotropyRadiusAttr",
             &_CreateAnisotropyRadiusAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetEnableAnisotropyAttr",
             &This::GetEnableAnisotropyAttr)
        .def("CreateEnableAnisotropyAttr",
             &_CreateEnableAnisotropyAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetGridFilteringPassesAttr",
             &This::GetGridFilteringPassesAttr)
        .def("CreateGridFilteringPassesAttr",
             &_CreateGridFilteringPassesAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetGridSmoothingRadiusRelativeToCellSizeAttr",
             &This::GetGridSmoothingRadiusRelativeToCellSizeAttr)
        .def("CreateGridSmoothingRadiusRelativeToCellSizeAttr",
             &_CreateGridSmoothingRadiusRelativeToCellSizeAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetGridSpacingAttr",
             &This::GetGridSpacingAttr)
        .def("CreateGridSpacingAttr",
             &_CreateGridSpacingAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetIsoSurfaceEnabledAttr",
             &This::GetIsoSurfaceEnabledAttr)
        .def("CreateIsoSurfaceEnabledAttr",
             &_CreateIsoSurfaceEnabledAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetIsosurfaceLevelAttr",
             &This::GetIsosurfaceLevelAttr)
        .def("CreateIsosurfaceLevelAttr",
             &_CreateIsosurfaceLevelAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetKernelRadiusAttr",
             &This::GetKernelRadiusAttr)
        .def("CreateKernelRadiusAttr",
             &_CreateKernelRadiusAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMaxSubgridsAttr",
             &This::GetMaxSubgridsAttr)
        .def("CreateMaxSubgridsAttr",
             &_CreateMaxSubgridsAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMaxTrianglesAttr",
             &This::GetMaxTrianglesAttr)
        .def("CreateMaxTrianglesAttr",
             &_CreateMaxTrianglesAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetMaxVerticesAttr",
             &This::GetMaxVerticesAttr)
        .def("CreateMaxVerticesAttr",
             &_CreateMaxVerticesAttr,
             (arg("defaultValue")=object(),
              arg("writeSparsely")=false))
        
        .def("GetNumMeshSmoothingPassesAttr",
             &This::GetNumMeshSmoothingPassesAttr)
        .def("CreateNumMeshSmoothingPassesAttr",
             &_CreateNumMeshSmoothingPassesAttr,
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

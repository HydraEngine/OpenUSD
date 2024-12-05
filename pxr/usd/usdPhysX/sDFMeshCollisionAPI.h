//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_GENERATED_SDFMESHCOLLISIONAPI_H
#define USDPHYSX_GENERATED_SDFMESHCOLLISIONAPI_H

/// \file usdPhysX/sDFMeshCollisionAPI.h

#include "pxr/pxr.h"
#include "pxr/usd/usdPhysX/api.h"
#include "pxr/usd/usd/apiSchemaBase.h"
#include "pxr/usd/usd/prim.h"
#include "pxr/usd/usd/stage.h"
#include "pxr/usd/usdPhysX/tokens.h"

#include "pxr/base/vt/value.h"

#include "pxr/base/gf/vec3d.h"
#include "pxr/base/gf/vec3f.h"
#include "pxr/base/gf/matrix4d.h"

#include "pxr/base/tf/token.h"
#include "pxr/base/tf/type.h"

PXR_NAMESPACE_OPEN_SCOPE

class SdfAssetPath;

// -------------------------------------------------------------------------- //
// PHYSXSCHEMAPHYSXSDFMESHCOLLISIONAPI                                        //
// -------------------------------------------------------------------------- //

/// \class UsdPhysXSDFMeshCollisionAPI
///
/// 
/// PhysX SDF mesh extended parameters.
/// 
/// For any described attribute Fallback Value or Allowed Values below that are text/tokens, the actual token is published and defined in PhysxSchemaTokens. 
/// So to set an attribute to the value "rightHanded", use PhysxSchemaTokens->rightHanded as the value.
/// 
///
/// For any described attribute \em Fallback \em Value or \em Allowed \em Values below
/// that are text/tokens, the actual token is published and defined in \ref UsdPhysXTokens.
/// So to set an attribute to the value "rightHanded", use UsdPhysXTokens->rightHanded
/// as the value.
///
class UsdPhysXSDFMeshCollisionAPI : public UsdAPISchemaBase
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::SingleApplyAPI;

    /// Construct a UsdPhysXSDFMeshCollisionAPI on UsdPrim \p prim .
    /// Equivalent to UsdPhysXSDFMeshCollisionAPI::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysXSDFMeshCollisionAPI(const UsdPrim& prim=UsdPrim())
        : UsdAPISchemaBase(prim)
    {
    }

    /// Construct a UsdPhysXSDFMeshCollisionAPI on the prim held by \p schemaObj .
    /// Should be preferred over UsdPhysXSDFMeshCollisionAPI(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdPhysXSDFMeshCollisionAPI(const UsdSchemaBase& schemaObj)
        : UsdAPISchemaBase(schemaObj)
    {
    }

    /// Destructor.
    USDPHYSX_API
    virtual ~UsdPhysXSDFMeshCollisionAPI();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSX_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdPhysXSDFMeshCollisionAPI holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdPhysXSDFMeshCollisionAPI(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDPHYSX_API
    static UsdPhysXSDFMeshCollisionAPI
    Get(const UsdStagePtr &stage, const SdfPath &path);


    /// Returns true if this <b>single-apply</b> API schema can be applied to 
    /// the given \p prim. If this schema can not be a applied to the prim, 
    /// this returns false and, if provided, populates \p whyNot with the 
    /// reason it can not be applied.
    /// 
    /// Note that if CanApply returns false, that does not necessarily imply
    /// that calling Apply will fail. Callers are expected to call CanApply
    /// before calling Apply if they want to ensure that it is valid to 
    /// apply a schema.
    /// 
    /// \sa UsdPrim::GetAppliedSchemas()
    /// \sa UsdPrim::HasAPI()
    /// \sa UsdPrim::CanApplyAPI()
    /// \sa UsdPrim::ApplyAPI()
    /// \sa UsdPrim::RemoveAPI()
    ///
    USDPHYSX_API
    static bool 
    CanApply(const UsdPrim &prim, std::string *whyNot=nullptr);

    /// Applies this <b>single-apply</b> API schema to the given \p prim.
    /// This information is stored by adding "PhysxSchemaPhysxSDFMeshCollisionAPI" to the 
    /// token-valued, listOp metadata \em apiSchemas on the prim.
    /// 
    /// \return A valid UsdPhysXSDFMeshCollisionAPI object is returned upon success. 
    /// An invalid (or empty) UsdPhysXSDFMeshCollisionAPI object is returned upon 
    /// failure. See \ref UsdPrim::ApplyAPI() for conditions 
    /// resulting in failure. 
    /// 
    /// \sa UsdPrim::GetAppliedSchemas()
    /// \sa UsdPrim::HasAPI()
    /// \sa UsdPrim::CanApplyAPI()
    /// \sa UsdPrim::ApplyAPI()
    /// \sa UsdPrim::RemoveAPI()
    ///
    USDPHYSX_API
    static UsdPhysXSDFMeshCollisionAPI 
    Apply(const UsdPrim &prim);

protected:
    /// Returns the kind of schema this class belongs to.
    ///
    /// \sa UsdSchemaKind
    USDPHYSX_API
    UsdSchemaKind _GetSchemaKind() const override;

private:
    // needs to invoke _GetStaticTfType.
    friend class UsdSchemaRegistry;
    USDPHYSX_API
    static const TfType &_GetStaticTfType();

    static bool _IsTypedSchema();

    // override SchemaBase virtuals.
    USDPHYSX_API
    const TfType &_GetTfType() const override;

public:
    // --------------------------------------------------------------------- //
    // SDFBITSPERSUBGRIDPIXEL 
    // --------------------------------------------------------------------- //
    /// 
    /// Values of 8, 16 and 32 bits per subgrid pixel are supported.
    /// 
    /// Dense SDFs always use 32 bits per pixel. The less bits per pixel, the smaller the resulting SDF but also the less precise. 
    /// The SDF's memory consumption scales proportionally with the number of bits per subgrid pixel.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `uniform token physxSDFMeshCollision:sdfBitsPerSubgridPixel = "BitsPerPixel16"` |
    /// | C++ Type | TfToken |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Token |
    /// | \ref SdfVariability "Variability" | SdfVariabilityUniform |
    /// | \ref UsdPhysXTokens "Allowed Values" | BitsPerPixel8, BitsPerPixel16, BitsPerPixel32 |
    USDPHYSX_API
    UsdAttribute GetSdfBitsPerSubgridPixelAttr() const;

    /// See GetSdfBitsPerSubgridPixelAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateSdfBitsPerSubgridPixelAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // SDFENABLEREMESHING 
    // --------------------------------------------------------------------- //
    /// 
    /// Enables optional remeshing as a preprocessing step before the SDF is computed.
    /// 
    /// Remeshing can help generate valid SDF data even if the input mesh has bad properties like inconsistent winding or self-intersections. 
    /// The SDF distances (and therefore the collisions) will be slightly less accurate when remeshing is enabled.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `uniform bool physxSDFMeshCollision:sdfEnableRemeshing = 0` |
    /// | C++ Type | bool |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Bool |
    /// | \ref SdfVariability "Variability" | SdfVariabilityUniform |
    USDPHYSX_API
    UsdAttribute GetSdfEnableRemeshingAttr() const;

    /// See GetSdfEnableRemeshingAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateSdfEnableRemeshingAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // SDFMARGIN 
    // --------------------------------------------------------------------- //
    /// 
    /// Margin to increase the size of the SDF relative to the bounding box diagonal length of the mesh.
    /// 
    /// A sdf margin value of 0.01 means the sdf boundary will be enlarged in any direction by 1% of the mesh's bounding box diagonal length.
    /// Representing the margin relative to the bounding box diagonal length ensures that it is scale independent. 
    /// Margins allow for precise distance queries in a region slightly outside of the mesh's bounding box. Range: [0, inf) Units: dimensionless
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `uniform float physxSDFMeshCollision:sdfMargin = 0.01` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    /// | \ref SdfVariability "Variability" | SdfVariabilityUniform |
    USDPHYSX_API
    UsdAttribute GetSdfMarginAttr() const;

    /// See GetSdfMarginAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateSdfMarginAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // SDFNARROWBANDTHICKNESS 
    // --------------------------------------------------------------------- //
    /// 
    /// Size of the narrow band around the mesh surface where high resolution SDF samples are available.
    /// 
    /// Outside of the narrow band, only low resolution samples are stored. 
    /// Representing the narrow band thickness as a fraction of the mesh's bounding box diagonal length ensures that it is scale independent. 
    /// A value of 0.01 is usually large enough. The smaller the narrow band thickness, the smaller the memory consumption of the sparse SDF. 
    /// Range: [0, 1] Units: dimensionless
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `uniform float physxSDFMeshCollision:sdfNarrowBandThickness = 0.01` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    /// | \ref SdfVariability "Variability" | SdfVariabilityUniform |
    USDPHYSX_API
    UsdAttribute GetSdfNarrowBandThicknessAttr() const;

    /// See GetSdfNarrowBandThicknessAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateSdfNarrowBandThicknessAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // SDFRESOLUTION 
    // --------------------------------------------------------------------- //
    /// 
    /// The spacing of the uniformly sampled SDF is equal to the largest AABB extent of the mesh, divided by the resolution.
    /// 
    /// Choose the lowest possible resolution that provides acceptable performance; very high resolution results in large memory consumption, 
    /// and slower cooking and simulation performance. Range: (1, inf)
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `uniform int physxSDFMeshCollision:sdfResolution = 256` |
    /// | C++ Type | int |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Int |
    /// | \ref SdfVariability "Variability" | SdfVariabilityUniform |
    USDPHYSX_API
    UsdAttribute GetSdfResolutionAttr() const;

    /// See GetSdfResolutionAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateSdfResolutionAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // SDFSUBGRIDRESOLUTION 
    // --------------------------------------------------------------------- //
    /// 
    /// A positive subgrid resolution enables sparsity on signed-distance-fields (SDF) while a value of 0 leads to the usage of a dense SDF.
    /// 
    /// A value in the range of 4 to 8 is a reasonable compromise between block size and the overhead introduced by block addressing. 
    /// The smaller a block, the more memory is spent on the address table. The bigger a block, the less precisely the sparse SDF can adapt to the mesh's surface. 
    /// In most cases sparsity reduces the memory consumption of a SDF significantly. Range: [0, inf)
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `uniform int physxSDFMeshCollision:sdfSubgridResolution = 6` |
    /// | C++ Type | int |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Int |
    /// | \ref SdfVariability "Variability" | SdfVariabilityUniform |
    USDPHYSX_API
    UsdAttribute GetSdfSubgridResolutionAttr() const;

    /// See GetSdfSubgridResolutionAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateSdfSubgridResolutionAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // SDFTRIANGLECOUNTREDUCTIONFACTOR 
    // --------------------------------------------------------------------- //
    /// 
    /// Factor that quantifies the percentage of the input triangles to keep.
    /// 
    /// 1 means the input triangle mesh does not get modified. 
    /// 0.5 would mean that the triangle count gets reduced to half the amount of the original mesh such that the collider needs to process less data. 
    /// This helps to speed up collision detection at the cost of a small geometric error. 
    /// Range: [0, 1] Units: dimensionless
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `uniform float physxSDFMeshCollision:sdfTriangleCountReductionFactor = 1` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    /// | \ref SdfVariability "Variability" | SdfVariabilityUniform |
    USDPHYSX_API
    UsdAttribute GetSdfTriangleCountReductionFactorAttr() const;

    /// See GetSdfTriangleCountReductionFactorAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateSdfTriangleCountReductionFactorAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // ===================================================================== //
    // Feel free to add custom code below this line, it will be preserved by 
    // the code generator. 
    //
    // Just remember to: 
    //  - Close the class declaration with }; 
    //  - Close the namespace with PXR_NAMESPACE_CLOSE_SCOPE
    //  - Close the include guard with #endif
    // ===================================================================== //
    // --(BEGIN CUSTOM CODE)--
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif

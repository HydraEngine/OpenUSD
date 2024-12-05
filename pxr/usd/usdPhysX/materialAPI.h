//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_GENERATED_MATERIALAPI_H
#define USDPHYSX_GENERATED_MATERIALAPI_H

/// \file usdPhysX/materialAPI.h

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
// PHYSXSCHEMAPHYSXMATERIALAPI                                                //
// -------------------------------------------------------------------------- //

/// \class UsdPhysXMaterialAPI
///
/// PhysX material extended parameters.
/// For any described attribute Fallback Value or Allowed Values below that are text/tokens, the actual token is published and defined in PhysxSchemaTokens. 
/// So to set an attribute to the value "rightHanded", use PhysxSchemaTokens->rightHanded as the value.
/// 
///
/// For any described attribute \em Fallback \em Value or \em Allowed \em Values below
/// that are text/tokens, the actual token is published and defined in \ref UsdPhysXTokens.
/// So to set an attribute to the value "rightHanded", use UsdPhysXTokens->rightHanded
/// as the value.
///
class UsdPhysXMaterialAPI : public UsdAPISchemaBase
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::SingleApplyAPI;

    /// Construct a UsdPhysXMaterialAPI on UsdPrim \p prim .
    /// Equivalent to UsdPhysXMaterialAPI::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysXMaterialAPI(const UsdPrim& prim=UsdPrim())
        : UsdAPISchemaBase(prim)
    {
    }

    /// Construct a UsdPhysXMaterialAPI on the prim held by \p schemaObj .
    /// Should be preferred over UsdPhysXMaterialAPI(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdPhysXMaterialAPI(const UsdSchemaBase& schemaObj)
        : UsdAPISchemaBase(schemaObj)
    {
    }

    /// Destructor.
    USDPHYSX_API
    virtual ~UsdPhysXMaterialAPI();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSX_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdPhysXMaterialAPI holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdPhysXMaterialAPI(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDPHYSX_API
    static UsdPhysXMaterialAPI
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
    /// This information is stored by adding "PhysxSchemaPhysxMaterialAPI" to the 
    /// token-valued, listOp metadata \em apiSchemas on the prim.
    /// 
    /// \return A valid UsdPhysXMaterialAPI object is returned upon success. 
    /// An invalid (or empty) UsdPhysXMaterialAPI object is returned upon 
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
    static UsdPhysXMaterialAPI 
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
    // COMPLIANTCONTACTACCELERATIONSPRING 
    // --------------------------------------------------------------------- //
    /// If enabled, switches from force-based to acceleration-based compliant spring-damper contact effects.
    /// An acceleration-based spring-damper directly influences the acceleration of (rather than the force on) the contacting bodies, 
    /// which makes the sink-in depth independent of the mass. The setting has no effect if compliant contacts are disabled, i.e., if the compliant contact stiffness is zero.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `bool physxMaterial:compliantContactAccelerationSpring = 0` |
    /// | C++ Type | bool |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Bool |
    USDPHYSX_API
    UsdAttribute GetCompliantContactAccelerationSpringAttr() const;

    /// See GetCompliantContactAccelerationSpringAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateCompliantContactAccelerationSpringAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // COMPLIANTCONTACTDAMPING 
    // --------------------------------------------------------------------- //
    /// Damping coefficient for a compliant contact model using implicit springs.
    /// 
    /// Ignored if compliant contacts are disabled (compliantContactStiffness is set to zero), in which case rigid contacts are active. 
    /// Depending on the compliantContactAccelerationSpring setting, the damping is interpreted as a force or acceleration, respectively, per unit velocity. 
    /// Range: [0, inf) Units (force spring): force / (distance / seconds) = mass / seconds Units (acceleration spring): acceleration / (distance / seconds) = 1 / seconds
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physxMaterial:compliantContactDamping = 0` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetCompliantContactDampingAttr() const;

    /// See GetCompliantContactDampingAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateCompliantContactDampingAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // COMPLIANTCONTACTSTIFFNESS 
    // --------------------------------------------------------------------- //
    /// Spring stiffness for a compliant contact model using implicit springs.
    /// 
    /// A higher stiffness results in behavior closer to a rigid contact. The compliant contact model is only enabled if the stiffness is larger than 0. 
    /// Depending on the compliantContactAccelerationSpring setting, the stiffness is interpreted as a force or acceleration, respectively, per unit distance. 
    /// Range: [0, inf) Units (force spring): force/distance = mass / seconds / seconds Units (acceleration spring): acceleration/distance = 1 / seconds / seconds
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physxMaterial:compliantContactStiffness = 0` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetCompliantContactStiffnessAttr() const;

    /// See GetCompliantContactStiffnessAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateCompliantContactStiffnessAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DAMPINGCOMBINEMODE 
    // --------------------------------------------------------------------- //
    /// 
    /// Determines the way in which two material properties will be combined to yield a damping coefficient for a collision.
    /// 
    /// This value is only relevant for compliant contact interactions.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `uniform token physxMaterial:dampingCombineMode = "average"` |
    /// | C++ Type | TfToken |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Token |
    /// | \ref SdfVariability "Variability" | SdfVariabilityUniform |
    /// | \ref UsdPhysXTokens "Allowed Values" | average, min, multiply, max |
    USDPHYSX_API
    UsdAttribute GetDampingCombineModeAttr() const;

    /// See GetDampingCombineModeAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateDampingCombineModeAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // FRICTIONCOMBINEMODE 
    // --------------------------------------------------------------------- //
    /// 
    /// Determines the way in which two material properties will be combined to yield a friction coefficient for a collision.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `uniform token physxMaterial:frictionCombineMode = "average"` |
    /// | C++ Type | TfToken |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Token |
    /// | \ref SdfVariability "Variability" | SdfVariabilityUniform |
    /// | \ref UsdPhysXTokens "Allowed Values" | average, min, multiply, max |
    USDPHYSX_API
    UsdAttribute GetFrictionCombineModeAttr() const;

    /// See GetFrictionCombineModeAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateFrictionCombineModeAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // RESTITUTIONCOMBINEMODE 
    // --------------------------------------------------------------------- //
    /// 
    /// Determines the way in which two material properties will be combined to yield a restitution coefficient for a collision.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `uniform token physxMaterial:restitutionCombineMode = "average"` |
    /// | C++ Type | TfToken |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Token |
    /// | \ref SdfVariability "Variability" | SdfVariabilityUniform |
    /// | \ref UsdPhysXTokens "Allowed Values" | average, min, multiply, max |
    USDPHYSX_API
    UsdAttribute GetRestitutionCombineModeAttr() const;

    /// See GetRestitutionCombineModeAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateRestitutionCombineModeAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

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

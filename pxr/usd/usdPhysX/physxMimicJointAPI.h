//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_GENERATED_PHYSXMIMICJOINTAPI_H
#define USDPHYSX_GENERATED_PHYSXMIMICJOINTAPI_H

/// \file usdPhysX/physxMimicJointAPI.h

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
// PHYSXSCHEMAPHYSXMIMICJOINTAPI                                              //
// -------------------------------------------------------------------------- //

/// \class UsdPhysXPhysxMimicJointAPI
///
/// Applied to a Physics Joint that must be part of an articulation.
/// 
/// Supported joint types are: PhysicsRevoluteJoint (with a limit set), PhysicsPrismaticJoint as well as the more generic PhysicsJoint if all linear degrees of freedom are locked.
/// 
/// This schema allows to interconnect the degrees of freedom of two joints according to the relationship: jointPosition + (gearing * referenceJointPosition) + offset = 0. This can be used to have, for example, one joint mimic the motion of another joint. The term "position" does not necessarily mean a translational unit, in the case of an angular degree of freedom it is an angle. The mimic joint operates on a single degree of freedom which is specified through the instance name of this multiple apply schema. The allowed instance name tokens are "rotX", "rotY" and "rotZ". See the documentation of the attribute referenceJointAxis for more info related to specifying the degree of freedom to operate on. Notes: 1) the two joints have to be part of the same articulation. 2) once the simulation has started, a significant performance penalty will be incurred if a mimic joint is added or removed, if the referenceJoint relationship is changed or if the referenceJointAxis attributes is modified. 3) the mimic joint relationship is interpreted as a two-way interaction and an impulse will get applied to the reference joint as well.
/// 
/// For any described attribute Fallback Value or Allowed Values below that are text/tokens, the actual token is published and defined in PhysxSchemaTokens. So to set an attribute to the value "rightHanded", use PhysxSchemaTokens->rightHanded as the value.
/// 
///
/// For any described attribute \em Fallback \em Value or \em Allowed \em Values below
/// that are text/tokens, the actual token is published and defined in \ref UsdPhysXTokens.
/// So to set an attribute to the value "rightHanded", use UsdPhysXTokens->rightHanded
/// as the value.
///
class UsdPhysXPhysxMimicJointAPI : public UsdAPISchemaBase
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::MultipleApplyAPI;

    /// Construct a UsdPhysXPhysxMimicJointAPI on UsdPrim \p prim with
    /// name \p name . Equivalent to
    /// UsdPhysXPhysxMimicJointAPI::Get(
    ///    prim.GetStage(),
    ///    prim.GetPath().AppendProperty(
    ///        "physxMimicJoint:name"));
    ///
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysXPhysxMimicJointAPI(
        const UsdPrim& prim=UsdPrim(), const TfToken &name=TfToken())
        : UsdAPISchemaBase(prim, /*instanceName*/ name)
    { }

    /// Construct a UsdPhysXPhysxMimicJointAPI on the prim held by \p schemaObj with
    /// name \p name.  Should be preferred over
    /// UsdPhysXPhysxMimicJointAPI(schemaObj.GetPrim(), name), as it preserves
    /// SchemaBase state.
    explicit UsdPhysXPhysxMimicJointAPI(
        const UsdSchemaBase& schemaObj, const TfToken &name)
        : UsdAPISchemaBase(schemaObj, /*instanceName*/ name)
    { }

    /// Destructor.
    USDPHYSX_API
    virtual ~UsdPhysXPhysxMimicJointAPI();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSX_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes for a given instance name.  Does not
    /// include attributes that may be authored by custom/extended methods of
    /// the schemas involved. The names returned will have the proper namespace
    /// prefix.
    USDPHYSX_API
    static TfTokenVector
    GetSchemaAttributeNames(bool includeInherited, const TfToken &instanceName);

    /// Returns the name of this multiple-apply schema instance
    TfToken GetName() const {
        return _GetInstanceName();
    }

    /// Return a UsdPhysXPhysxMimicJointAPI holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  \p path must be of the format
    /// <path>.physxMimicJoint:name .
    ///
    /// This is shorthand for the following:
    ///
    /// \code
    /// TfToken name = SdfPath::StripNamespace(path.GetToken());
    /// UsdPhysXPhysxMimicJointAPI(
    ///     stage->GetPrimAtPath(path.GetPrimPath()), name);
    /// \endcode
    ///
    USDPHYSX_API
    static UsdPhysXPhysxMimicJointAPI
    Get(const UsdStagePtr &stage, const SdfPath &path);

    /// Return a UsdPhysXPhysxMimicJointAPI with name \p name holding the
    /// prim \p prim. Shorthand for UsdPhysXPhysxMimicJointAPI(prim, name);
    USDPHYSX_API
    static UsdPhysXPhysxMimicJointAPI
    Get(const UsdPrim &prim, const TfToken &name);

    /// Return a vector of all named instances of UsdPhysXPhysxMimicJointAPI on the 
    /// given \p prim.
    USDPHYSX_API
    static std::vector<UsdPhysXPhysxMimicJointAPI>
    GetAll(const UsdPrim &prim);

    /// Checks if the given name \p baseName is the base name of a property
    /// of PhysxSchemaPhysxMimicJointAPI.
    USDPHYSX_API
    static bool
    IsSchemaPropertyBaseName(const TfToken &baseName);

    /// Checks if the given path \p path is of an API schema of type
    /// PhysxSchemaPhysxMimicJointAPI. If so, it stores the instance name of
    /// the schema in \p name and returns true. Otherwise, it returns false.
    USDPHYSX_API
    static bool
    IsPhysxSchemaPhysxMimicJointAPIPath(const SdfPath &path, TfToken *name);

    /// Returns true if this <b>multiple-apply</b> API schema can be applied,
    /// with the given instance name, \p name, to the given \p prim. If this 
    /// schema can not be a applied the prim, this returns false and, if 
    /// provided, populates \p whyNot with the reason it can not be applied.
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
    CanApply(const UsdPrim &prim, const TfToken &name, 
             std::string *whyNot=nullptr);

    /// Applies this <b>multiple-apply</b> API schema to the given \p prim 
    /// along with the given instance name, \p name. 
    /// 
    /// This information is stored by adding "PhysxSchemaPhysxMimicJointAPI:<i>name</i>" 
    /// to the token-valued, listOp metadata \em apiSchemas on the prim.
    /// For example, if \p name is 'instance1', the token 
    /// 'PhysxSchemaPhysxMimicJointAPI:instance1' is added to 'apiSchemas'.
    /// 
    /// \return A valid UsdPhysXPhysxMimicJointAPI object is returned upon success. 
    /// An invalid (or empty) UsdPhysXPhysxMimicJointAPI object is returned upon 
    /// failure. See \ref UsdPrim::ApplyAPI() for 
    /// conditions resulting in failure. 
    /// 
    /// \sa UsdPrim::GetAppliedSchemas()
    /// \sa UsdPrim::HasAPI()
    /// \sa UsdPrim::CanApplyAPI()
    /// \sa UsdPrim::ApplyAPI()
    /// \sa UsdPrim::RemoveAPI()
    ///
    USDPHYSX_API
    static UsdPhysXPhysxMimicJointAPI 
    Apply(const UsdPrim &prim, const TfToken &name);

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
    // GEARING 
    // --------------------------------------------------------------------- //
    /// The gearing coefficient (see relationship formulation in the documentation part of PhysxMimicJointAPI).
    /// Range: (-inf, inf) Units: unitless or degrees/distance or distance/degrees (the last two refer to scenarios where a linear degree of freedom is connected to an angular one or vice versa)
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float gearing = 1` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetGearingAttr() const;

    /// See GetGearingAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateGearingAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // OFFSET 
    // --------------------------------------------------------------------- //
    /// The offset coefficient (see relationship formulation in the documentation part of PhysxMimicJointAPI).
    /// Range: (-inf, inf) Units: distance or degrees (depending on whether the mimic joint's degree of freedom is linear or angular)
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float offset = 0` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetOffsetAttr() const;

    /// See GetOffsetAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateOffsetAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // REFERENCEJOINTAXIS 
    // --------------------------------------------------------------------- //
    /// 
    /// The axis that marks the degree of freedom of the reference joint to mimic.
    /// 
    /// Has to be a valid degree of freedom on the reference joint. For joint types with a single degree of freedom (like PhysicsRevoluteJoint or PhysicsPrismaticJoint), 
    /// this attribute will be ignored since the axis is defined implicitly. 
    /// The mimic joint connects <targetJoint, targetJointAxis> to <referenceJoint, referenceJointAxis> with targetJoint being the prim that has PhysxMimicJointAPI applied 
    /// and targetJointAxis being defined through the instance name token of PhysxMimicJointAPI.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `uniform token referenceJointAxis = "rotX"` |
    /// | C++ Type | TfToken |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Token |
    /// | \ref SdfVariability "Variability" | SdfVariabilityUniform |
    /// | \ref UsdPhysXTokens "Allowed Values" | rotX, rotY, rotZ |
    USDPHYSX_API
    UsdAttribute GetReferenceJointAxisAttr() const;

    /// See GetReferenceJointAxisAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateReferenceJointAxisAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

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

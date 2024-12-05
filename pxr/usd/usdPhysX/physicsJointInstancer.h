//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_GENERATED_PHYSICSJOINTINSTANCER_H
#define USDPHYSX_GENERATED_PHYSICSJOINTINSTANCER_H

/// \file usdPhysX/physicsJointInstancer.h

#include "pxr/pxr.h"
#include "pxr/usd/usdPhysX/api.h"
#include "pxr/usd/usdPhysX/physicsInstancer.h"
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
// PHYSXSCHEMAPHYSXPHYSICSJOINTINSTANCER                                      //
// -------------------------------------------------------------------------- //

/// \class UsdPhysXPhysicsJointInstancer
///
/// Physics joint instancer, the prototypes are expected to be UsdPhysicsJoint prim types.
///
class UsdPhysXPhysicsJointInstancer : public UsdPhysXPhysicsInstancer
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::ConcreteTyped;

    /// Construct a UsdPhysXPhysicsJointInstancer on UsdPrim \p prim .
    /// Equivalent to UsdPhysXPhysicsJointInstancer::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysXPhysicsJointInstancer(const UsdPrim& prim=UsdPrim())
        : UsdPhysXPhysicsInstancer(prim)
    {
    }

    /// Construct a UsdPhysXPhysicsJointInstancer on the prim held by \p schemaObj .
    /// Should be preferred over UsdPhysXPhysicsJointInstancer(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdPhysXPhysicsJointInstancer(const UsdSchemaBase& schemaObj)
        : UsdPhysXPhysicsInstancer(schemaObj)
    {
    }

    /// Destructor.
    USDPHYSX_API
    virtual ~UsdPhysXPhysicsJointInstancer();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSX_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdPhysXPhysicsJointInstancer holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdPhysXPhysicsJointInstancer(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDPHYSX_API
    static UsdPhysXPhysicsJointInstancer
    Get(const UsdStagePtr &stage, const SdfPath &path);

    /// Attempt to ensure a \a UsdPrim adhering to this schema at \p path
    /// is defined (according to UsdPrim::IsDefined()) on this stage.
    ///
    /// If a prim adhering to this schema at \p path is already defined on this
    /// stage, return that prim.  Otherwise author an \a SdfPrimSpec with
    /// \a specifier == \a SdfSpecifierDef and this schema's prim type name for
    /// the prim at \p path at the current EditTarget.  Author \a SdfPrimSpec s
    /// with \p specifier == \a SdfSpecifierDef and empty typeName at the
    /// current EditTarget for any nonexistent, or existing but not \a Defined
    /// ancestors.
    ///
    /// The given \a path must be an absolute prim path that does not contain
    /// any variant selections.
    ///
    /// If it is impossible to author any of the necessary PrimSpecs, (for
    /// example, in case \a path cannot map to the current UsdEditTarget's
    /// namespace) issue an error and return an invalid \a UsdPrim.
    ///
    /// Note that this method may return a defined prim whose typeName does not
    /// specify this schema class, in case a stronger typeName opinion overrides
    /// the opinion at the current EditTarget.
    ///
    USDPHYSX_API
    static UsdPhysXPhysicsJointInstancer
    Define(const UsdStagePtr &stage, const SdfPath &path);

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
    // PHYSICSBODY0INDICES 
    // --------------------------------------------------------------------- //
    /// **Optional property.** Only applicable if body0s is a point instancer. An index specifies the per-instance body0 rel as the rigid body at the body0s-instancer's protoIndices[index].
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int[] physics:body0Indices` |
    /// | C++ Type | VtArray<int> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->IntArray |
    USDPHYSX_API
    UsdAttribute GetPhysicsBody0IndicesAttr() const;

    /// See GetPhysicsBody0IndicesAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreatePhysicsBody0IndicesAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // PHYSICSBODY1INDICES 
    // --------------------------------------------------------------------- //
    /// **Optional property.** Only applicable if body1s is a point instancer. An index specifies the per-instance body1 rel as the rigid body at the body1s-instancer's protoIndices[index].
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int[] physics:body1Indices` |
    /// | C++ Type | VtArray<int> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->IntArray |
    USDPHYSX_API
    UsdAttribute GetPhysicsBody1IndicesAttr() const;

    /// See GetPhysicsBody1IndicesAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreatePhysicsBody1IndicesAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // PHYSICSLOCALPOS0S 
    // --------------------------------------------------------------------- //
    /// **Required property.** Per-instance localPos0. This transformation is added on top of the joint localPos0.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `point3f[] physics:localPos0s` |
    /// | C++ Type | VtArray<GfVec3f> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Point3fArray |
    USDPHYSX_API
    UsdAttribute GetPhysicsLocalPos0sAttr() const;

    /// See GetPhysicsLocalPos0sAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreatePhysicsLocalPos0sAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // PHYSICSLOCALPOS1S 
    // --------------------------------------------------------------------- //
    /// **Required property.** Per-instance localPos1. This transformation is added on top of the joint localPos1.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `point3f[] physics:localPos1s` |
    /// | C++ Type | VtArray<GfVec3f> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Point3fArray |
    USDPHYSX_API
    UsdAttribute GetPhysicsLocalPos1sAttr() const;

    /// See GetPhysicsLocalPos1sAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreatePhysicsLocalPos1sAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // PHYSICSLOCALROT0S 
    // --------------------------------------------------------------------- //
    /// **Required property.** Per-instance localRot0. This transformation is added on top of the joint localPos0.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `quath[] physics:localRot0s` |
    /// | C++ Type | VtArray<GfQuath> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->QuathArray |
    USDPHYSX_API
    UsdAttribute GetPhysicsLocalRot0sAttr() const;

    /// See GetPhysicsLocalRot0sAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreatePhysicsLocalRot0sAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // PHYSICSLOCALROT1S 
    // --------------------------------------------------------------------- //
    /// **Required property.** Per-instance localRot1. This transformation is added on top of the joint localPos1.
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `quath[] physics:localRot1s` |
    /// | C++ Type | VtArray<GfQuath> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->QuathArray |
    USDPHYSX_API
    UsdAttribute GetPhysicsLocalRot1sAttr() const;

    /// See GetPhysicsLocalRot1sAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreatePhysicsLocalRot1sAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // PHYSICSBODY0S 
    // --------------------------------------------------------------------- //
    /// **Required property.** The rel must contain either exactly one UsdGeomPointInstancer that instances rigid bodies; or one or more rigid-body prims in the stage. If the rel is to a point instancer, the body0Indices must be specified.
    ///
    USDPHYSX_API
    UsdRelationship GetPhysicsBody0sRel() const;

    /// See GetPhysicsBody0sRel(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create
    USDPHYSX_API
    UsdRelationship CreatePhysicsBody0sRel() const;

public:
    // --------------------------------------------------------------------- //
    // PHYSICSBODY1S 
    // --------------------------------------------------------------------- //
    /// **Required property.** The rel must contain either exactly one UsdGeomPointInstancer that instances rigid bodies; or one or more rigid-body prims in the stage. If the rel is to a point instancer, the body0Indices must be specified.
    ///
    USDPHYSX_API
    UsdRelationship GetPhysicsBody1sRel() const;

    /// See GetPhysicsBody1sRel(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create
    USDPHYSX_API
    UsdRelationship CreatePhysicsBody1sRel() const;

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

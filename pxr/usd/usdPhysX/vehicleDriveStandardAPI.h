//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_GENERATED_VEHICLEDRIVESTANDARDAPI_H
#define USDPHYSX_GENERATED_VEHICLEDRIVESTANDARDAPI_H

/// \file usdPhysX/vehicleDriveStandardAPI.h

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
// PHYSXSCHEMAPHYSXVEHICLEDRIVESTANDARDAPI                                    //
// -------------------------------------------------------------------------- //

/// \class UsdPhysXVehicleDriveStandardAPI
///
/// 
/// Standard drive model for a PhysX vehicle.
/// 
/// The available drive torque will be split equally between all the wheels that are marked as driven (see PhysxVehicleMultiWheelDifferentialAPI or deprecated attribute "driven" in PhysxVehicleWheelAttachmentAPI) unless the torque distributon is configured explicitly (see PhysxVehicleMultiWheelDifferentialAPI for details).
/// 
/// If the drive setup does not need to be shared among vehicle instances, it can be applied to the prim which has PhysxVehicleAPI applied. If the intent is to share the drive setup, PhysxVehicleDriveStandardAPI can be applied to a separate prim which can be linked to (see PhysxVehicleAPI).
/// 
///
class UsdPhysXVehicleDriveStandardAPI : public UsdAPISchemaBase
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::SingleApplyAPI;

    /// Construct a UsdPhysXVehicleDriveStandardAPI on UsdPrim \p prim .
    /// Equivalent to UsdPhysXVehicleDriveStandardAPI::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysXVehicleDriveStandardAPI(const UsdPrim& prim=UsdPrim())
        : UsdAPISchemaBase(prim)
    {
    }

    /// Construct a UsdPhysXVehicleDriveStandardAPI on the prim held by \p schemaObj .
    /// Should be preferred over UsdPhysXVehicleDriveStandardAPI(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdPhysXVehicleDriveStandardAPI(const UsdSchemaBase& schemaObj)
        : UsdAPISchemaBase(schemaObj)
    {
    }

    /// Destructor.
    USDPHYSX_API
    virtual ~UsdPhysXVehicleDriveStandardAPI();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSX_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdPhysXVehicleDriveStandardAPI holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdPhysXVehicleDriveStandardAPI(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDPHYSX_API
    static UsdPhysXVehicleDriveStandardAPI
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
    /// This information is stored by adding "PhysxSchemaPhysxVehicleDriveStandardAPI" to the 
    /// token-valued, listOp metadata \em apiSchemas on the prim.
    /// 
    /// \return A valid UsdPhysXVehicleDriveStandardAPI object is returned upon success. 
    /// An invalid (or empty) UsdPhysXVehicleDriveStandardAPI object is returned upon 
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
    static UsdPhysXVehicleDriveStandardAPI 
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
    // AUTOGEARBOX 
    // --------------------------------------------------------------------- //
    /// A relationship to a PhysxVehicleAutoGearBoxAPI prim that describes the automatic gear shift box. 
    /// 
    /// This relationship is optional and should be omitted if no automatic gear shift is desired. It is also possible to apply PhysxVehicleAutoGearBoxAPI to the prim directly. In that case the relationship must not be defined.
    /// 
    ///
    USDPHYSX_API
    UsdRelationship GetAutoGearBoxRel() const;

    /// See GetAutoGearBoxRel(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create
    USDPHYSX_API
    UsdRelationship CreateAutoGearBoxRel() const;

public:
    // --------------------------------------------------------------------- //
    // CLUTCH 
    // --------------------------------------------------------------------- //
    /// A relationship to a PhysxVehicleClutchAPI prim that describes the clutch. 
    /// 
    /// Note: either this relationship has to be specified or the prim must have PhysxVehicleClutchAPI applied (none or both of the two is invalid).
    ///
    USDPHYSX_API
    UsdRelationship GetClutchRel() const;

    /// See GetClutchRel(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create
    USDPHYSX_API
    UsdRelationship CreateClutchRel() const;

public:
    // --------------------------------------------------------------------- //
    // ENGINE 
    // --------------------------------------------------------------------- //
    /// A relationship to a PhysxVehicleEngineAPI prim that describes the engine. 
    /// 
    /// Note: either this relationship has to be specified or the prim must have PhysxVehicleEngineAPI applied (none or both of the two is invalid).
    ///
    USDPHYSX_API
    UsdRelationship GetEngineRel() const;

    /// See GetEngineRel(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create
    USDPHYSX_API
    UsdRelationship CreateEngineRel() const;

public:
    // --------------------------------------------------------------------- //
    // GEARS 
    // --------------------------------------------------------------------- //
    /// A relationship to a PhysxVehicleGearsAPI prim that describes the gears. 
    /// 
    /// Note: either this relationship has to be specified or the prim must have PhysxVehicleGearsAPI applied (none or both of the two is invalid).
    ///
    USDPHYSX_API
    UsdRelationship GetGearsRel() const;

    /// See GetGearsRel(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create
    USDPHYSX_API
    UsdRelationship CreateGearsRel() const;

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

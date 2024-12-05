//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_GENERATED_VEHICLETANKDIFFERENTIALAPI_H
#define USDPHYSX_GENERATED_VEHICLETANKDIFFERENTIALAPI_H

/// \file usdPhysX/vehicleTankDifferentialAPI.h

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
// PHYSXSCHEMAPHYSXVEHICLETANKDIFFERENTIALAPI                                 //
// -------------------------------------------------------------------------- //

/// \class UsdPhysXVehicleTankDifferentialAPI
///
/// 
/// Differential to set up a wheeled tank vehicle.
/// 
/// Describes which wheels of a vehicle are part of the tank tracks. 
/// The wheels in each tank track have a constraint applied to them to enforce the rule that they all have the same longitudinal speed at the contact point between the wheel and the tank track. 
/// Driven wheels that are not part of a tank track receive the torque split specified in physxVehicleMultiWheelDifferential:torqueRatios. 
/// Has to be applied to a prim with PhysxVehicleAPI applied. Can only be used for vehicles that have a standard drive (see PhysxVehicleDriveStandardAPI).
/// 
///
class UsdPhysXVehicleTankDifferentialAPI : public UsdAPISchemaBase
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::SingleApplyAPI;

    /// Construct a UsdPhysXVehicleTankDifferentialAPI on UsdPrim \p prim .
    /// Equivalent to UsdPhysXVehicleTankDifferentialAPI::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysXVehicleTankDifferentialAPI(const UsdPrim& prim=UsdPrim())
        : UsdAPISchemaBase(prim)
    {
    }

    /// Construct a UsdPhysXVehicleTankDifferentialAPI on the prim held by \p schemaObj .
    /// Should be preferred over UsdPhysXVehicleTankDifferentialAPI(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdPhysXVehicleTankDifferentialAPI(const UsdSchemaBase& schemaObj)
        : UsdAPISchemaBase(schemaObj)
    {
    }

    /// Destructor.
    USDPHYSX_API
    virtual ~UsdPhysXVehicleTankDifferentialAPI();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSX_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdPhysXVehicleTankDifferentialAPI holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdPhysXVehicleTankDifferentialAPI(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDPHYSX_API
    static UsdPhysXVehicleTankDifferentialAPI
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
    /// This information is stored by adding "PhysxSchemaPhysxVehicleTankDifferentialAPI" to the 
    /// token-valued, listOp metadata \em apiSchemas on the prim.
    /// 
    /// \return A valid UsdPhysXVehicleTankDifferentialAPI object is returned upon success. 
    /// An invalid (or empty) UsdPhysXVehicleTankDifferentialAPI object is returned upon 
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
    static UsdPhysXVehicleTankDifferentialAPI 
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
    // NUMBEROFWHEELSPERTRACK 
    // --------------------------------------------------------------------- //
    /// For each track, this array holds the number of wheels assigned to that track.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int[] physxVehicleTankDifferential:numberOfWheelsPerTrack` |
    /// | C++ Type | VtArray<int> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->IntArray |
    USDPHYSX_API
    UsdAttribute GetNumberOfWheelsPerTrackAttr() const;

    /// See GetNumberOfWheelsPerTrackAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateNumberOfWheelsPerTrackAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // THRUSTINDEXPERTRACK 
    // --------------------------------------------------------------------- //
    /// 
    /// For each track, this array holds the index of the thrust control (0 or 1, see PhysxVehicleTankControllerAPI) that drives the track.
    /// 
    /// The length of the array needs to match the length of the "numberOfWheelsPerTrack" array.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int[] physxVehicleTankDifferential:thrustIndexPerTrack` |
    /// | C++ Type | VtArray<int> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->IntArray |
    USDPHYSX_API
    UsdAttribute GetThrustIndexPerTrackAttr() const;

    /// See GetThrustIndexPerTrackAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateThrustIndexPerTrackAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // TRACKTOWHEELINDICES 
    // --------------------------------------------------------------------- //
    /// 
    /// For each track, this array holds the start index of the list describing the wheels that are assigned to that track (e.g., the list of wheel indices assigned to the track with index 2 starts at: wheelIndicesInTrackOrder[trackToWheelIndices[2]]).
    /// 
    /// The length of the array needs to match the length of the "numberOfWheelsPerTrack" array.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int[] physxVehicleTankDifferential:trackToWheelIndices` |
    /// | C++ Type | VtArray<int> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->IntArray |
    USDPHYSX_API
    UsdAttribute GetTrackToWheelIndicesAttr() const;

    /// See GetTrackToWheelIndicesAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateTrackToWheelIndicesAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // WHEELINDICESINTRACKORDER 
    // --------------------------------------------------------------------- //
    /// 
    /// The wheels (identified by wheel attachment indices, see attribtue "index" of PhysxVehicleWheelAttachmentAPI) assigned to track 0, followed by the wheels assigned to track 1 and so on.
    /// 
    /// The length of the array is expected to be equal (or larger than) the number of wheels that are assigned to tracks.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int[] physxVehicleTankDifferential:wheelIndicesInTrackOrder` |
    /// | C++ Type | VtArray<int> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->IntArray |
    USDPHYSX_API
    UsdAttribute GetWheelIndicesInTrackOrderAttr() const;

    /// See GetWheelIndicesInTrackOrderAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateWheelIndicesInTrackOrderAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

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

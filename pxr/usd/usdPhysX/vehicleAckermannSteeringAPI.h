//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_GENERATED_VEHICLEACKERMANNSTEERINGAPI_H
#define USDPHYSX_GENERATED_VEHICLEACKERMANNSTEERINGAPI_H

/// \file usdPhysX/vehicleAckermannSteeringAPI.h

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
// PHYSXSCHEMAPHYSXVEHICLEACKERMANNSTEERINGAPI                                //
// -------------------------------------------------------------------------- //

/// \class UsdPhysXVehicleAckermannSteeringAPI
///
/// 
/// Describes a steering system with Ackermann correction for two wheels.
/// 
/// This system will result in asymmetric steer angles such that the line defined by the non-steered wheel axle and the lateral lines of the steered wheels meet at the same point. 
/// As a consequence, when following the path around a curve, the inner wheel will turn more than the outer one. 
/// This avoids that some wheels need to slip sideways to stay on the path. The specified wheels will be connected to the steer control (see PhysxVehicleControllerAPI). 
/// This API schema has to be applied to a prim with PhysxVehicleAPI applied. Can only be used for vehicles that have a drive (see PhysxVehicleDriveBasicAPI or PhysxVehicleDriveStandardAPI). 
/// This API schema can not be combined with PhysxVehicleSteeringAPI, only one or the other is allowed.
/// 
///
class UsdPhysXVehicleAckermannSteeringAPI : public UsdAPISchemaBase
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::SingleApplyAPI;

    /// Construct a UsdPhysXVehicleAckermannSteeringAPI on UsdPrim \p prim .
    /// Equivalent to UsdPhysXVehicleAckermannSteeringAPI::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysXVehicleAckermannSteeringAPI(const UsdPrim& prim=UsdPrim())
        : UsdAPISchemaBase(prim)
    {
    }

    /// Construct a UsdPhysXVehicleAckermannSteeringAPI on the prim held by \p schemaObj .
    /// Should be preferred over UsdPhysXVehicleAckermannSteeringAPI(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdPhysXVehicleAckermannSteeringAPI(const UsdSchemaBase& schemaObj)
        : UsdAPISchemaBase(schemaObj)
    {
    }

    /// Destructor.
    USDPHYSX_API
    virtual ~UsdPhysXVehicleAckermannSteeringAPI();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSX_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdPhysXVehicleAckermannSteeringAPI holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdPhysXVehicleAckermannSteeringAPI(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDPHYSX_API
    static UsdPhysXVehicleAckermannSteeringAPI
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
    /// This information is stored by adding "PhysxSchemaPhysxVehicleAckermannSteeringAPI" to the 
    /// token-valued, listOp metadata \em apiSchemas on the prim.
    /// 
    /// \return A valid UsdPhysXVehicleAckermannSteeringAPI object is returned upon success. 
    /// An invalid (or empty) UsdPhysXVehicleAckermannSteeringAPI object is returned upon 
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
    static UsdPhysXVehicleAckermannSteeringAPI 
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
    // MAXSTEERANGLE 
    // --------------------------------------------------------------------- //
    /// The maximum steer angle (in radians) that can be achieved by the wheels.
    /// Has to be in range [-pi, pi]. The steer angle of wheel0 will be defined by maxSteerAngle * ackermann_correction(0) * physxVehicleController:steer (see PhysxVehicleControllerAPI).
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physxVehicleAckermannSteering:maxSteerAngle = 0` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetMaxSteerAngleAttr() const;

    /// See GetMaxSteerAngleAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateMaxSteerAngleAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // STRENGTH 
    // --------------------------------------------------------------------- //
    /// The strength of the Ackermann correction with 0 denoting no correction and 1 denoting perfect correction.
    /// The value has to be in range [0, 1].
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physxVehicleAckermannSteering:strength = 1` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetStrengthAttr() const;

    /// See GetStrengthAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateStrengthAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // TRACKWIDTH 
    // --------------------------------------------------------------------- //
    /// The width of the axle defined by wheel0 and wheel1 (units: distance).
    /// 
    /// The value has to be greater than zero.
    /// 
    /// Note: this attribute has to be specified (there is no default).
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physxVehicleAckermannSteering:trackWidth` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetTrackWidthAttr() const;

    /// See GetTrackWidthAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateTrackWidthAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // WHEEL0 
    // --------------------------------------------------------------------- //
    /// The index of the wheel that is negative along the lateral axis and should get connected to the steering system.
    /// 
    /// The index refers to the attribute "index" of PhysxVehicleWheelAttachmentAPI.
    /// 
    /// Note: this attribute has to be specified (there is no default).
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int physxVehicleAckermannSteering:wheel0` |
    /// | C++ Type | int |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Int |
    USDPHYSX_API
    UsdAttribute GetWheel0Attr() const;

    /// See GetWheel0Attr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateWheel0Attr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // WHEEL1 
    // --------------------------------------------------------------------- //
    /// The index of the wheel that is positive along the lateral axis and should get connected to the steering system.
    /// 
    /// The index refers to the attribute "index" of PhysxVehicleWheelAttachmentAPI.
    /// 
    /// Note: this attribute has to be specified (there is no default).
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int physxVehicleAckermannSteering:wheel1` |
    /// | C++ Type | int |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Int |
    USDPHYSX_API
    UsdAttribute GetWheel1Attr() const;

    /// See GetWheel1Attr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateWheel1Attr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // WHEELBASE 
    // --------------------------------------------------------------------- //
    /// The longitudinal distance between the axle that is affected by Ackermann correction and a reference axle (units: distance).
    /// 
    /// The value has to be greater than zero.
    /// 
    /// Note: this attribute has to be specified (there is no default).
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physxVehicleAckermannSteering:wheelBase` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetWheelBaseAttr() const;

    /// See GetWheelBaseAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateWheelBaseAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

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

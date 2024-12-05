//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_GENERATED_VEHICLEWHEELCONTROLLERAPI_H
#define USDPHYSX_GENERATED_VEHICLEWHEELCONTROLLERAPI_H

/// \file usdPhysX/vehicleWheelControllerAPI.h

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
// PHYSXSCHEMAPHYSXVEHICLEWHEELCONTROLLERAPI                                  //
// -------------------------------------------------------------------------- //

/// \class UsdPhysXVehicleWheelControllerAPI
///
/// 
/// PhysX wheel controller that samples user input and allows direct control of the wheel torques and steer angle to drive the vehicle.
/// 
/// Has to be applied to a prim with PhysxVehicleWheelAttachmentAPI applied and be a descendant of a prim with a PhysxVehicleAPI applied.
/// 
///
class UsdPhysXVehicleWheelControllerAPI : public UsdAPISchemaBase
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::SingleApplyAPI;

    /// Construct a UsdPhysXVehicleWheelControllerAPI on UsdPrim \p prim .
    /// Equivalent to UsdPhysXVehicleWheelControllerAPI::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysXVehicleWheelControllerAPI(const UsdPrim& prim=UsdPrim())
        : UsdAPISchemaBase(prim)
    {
    }

    /// Construct a UsdPhysXVehicleWheelControllerAPI on the prim held by \p schemaObj .
    /// Should be preferred over UsdPhysXVehicleWheelControllerAPI(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdPhysXVehicleWheelControllerAPI(const UsdSchemaBase& schemaObj)
        : UsdAPISchemaBase(schemaObj)
    {
    }

    /// Destructor.
    USDPHYSX_API
    virtual ~UsdPhysXVehicleWheelControllerAPI();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSX_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdPhysXVehicleWheelControllerAPI holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdPhysXVehicleWheelControllerAPI(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDPHYSX_API
    static UsdPhysXVehicleWheelControllerAPI
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
    /// This information is stored by adding "PhysxSchemaPhysxVehicleWheelControllerAPI" to the 
    /// token-valued, listOp metadata \em apiSchemas on the prim.
    /// 
    /// \return A valid UsdPhysXVehicleWheelControllerAPI object is returned upon success. 
    /// An invalid (or empty) UsdPhysXVehicleWheelControllerAPI object is returned upon 
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
    static UsdPhysXVehicleWheelControllerAPI 
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
    // BRAKETORQUE 
    // --------------------------------------------------------------------- //
    /// 
    /// Torque to decrease wheel angular rate and slow down (units: mass * distance * distance / seconds / seconds).
    /// 
    /// The value has to be greater or equal zero.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physxVehicleWheelController:brakeTorque = 0` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetBrakeTorqueAttr() const;

    /// See GetBrakeTorqueAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateBrakeTorqueAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // DRIVETORQUE 
    // --------------------------------------------------------------------- //
    /// 
    /// Torque to increase wheel angular rate and speed up (units: mass * distance * distance / seconds / seconds).
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physxVehicleWheelController:driveTorque = 0` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetDriveTorqueAttr() const;

    /// See GetDriveTorqueAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateDriveTorqueAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // STEERANGLE 
    // --------------------------------------------------------------------- //
    /// 
    /// Steer angle of the wheel in radians.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physxVehicleWheelController:steerAngle = 0` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetSteerAngleAttr() const;

    /// See GetSteerAngleAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateSteerAngleAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

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

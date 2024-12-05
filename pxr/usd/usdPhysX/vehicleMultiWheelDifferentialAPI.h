//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_GENERATED_VEHICLEMULTIWHEELDIFFERENTIALAPI_H
#define USDPHYSX_GENERATED_VEHICLEMULTIWHEELDIFFERENTIALAPI_H

/// \file usdPhysX/vehicleMultiWheelDifferentialAPI.h

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
// PHYSXSCHEMAPHYSXVEHICLEMULTIWHEELDIFFERENTIALAPI                           //
// -------------------------------------------------------------------------- //

/// \class UsdPhysXVehicleMultiWheelDifferentialAPI
///
/// 
/// Describes which wheels of a vehicle are driven as well as the distribution of the drive torque among those wheels.
/// 
/// Has to be applied to a prim with PhysxVehicleAPI applied. Can only be used for vehicles that have a drive (see PhysxVehicleDriveBasicAPI or PhysxVehicleDriveStandardAPI).
/// 
///
class UsdPhysXVehicleMultiWheelDifferentialAPI : public UsdAPISchemaBase
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::SingleApplyAPI;

    /// Construct a UsdPhysXVehicleMultiWheelDifferentialAPI on UsdPrim \p prim .
    /// Equivalent to UsdPhysXVehicleMultiWheelDifferentialAPI::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysXVehicleMultiWheelDifferentialAPI(const UsdPrim& prim=UsdPrim())
        : UsdAPISchemaBase(prim)
    {
    }

    /// Construct a UsdPhysXVehicleMultiWheelDifferentialAPI on the prim held by \p schemaObj .
    /// Should be preferred over UsdPhysXVehicleMultiWheelDifferentialAPI(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdPhysXVehicleMultiWheelDifferentialAPI(const UsdSchemaBase& schemaObj)
        : UsdAPISchemaBase(schemaObj)
    {
    }

    /// Destructor.
    USDPHYSX_API
    virtual ~UsdPhysXVehicleMultiWheelDifferentialAPI();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSX_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdPhysXVehicleMultiWheelDifferentialAPI holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdPhysXVehicleMultiWheelDifferentialAPI(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDPHYSX_API
    static UsdPhysXVehicleMultiWheelDifferentialAPI
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
    /// This information is stored by adding "PhysxSchemaPhysxVehicleMultiWheelDifferentialAPI" to the 
    /// token-valued, listOp metadata \em apiSchemas on the prim.
    /// 
    /// \return A valid UsdPhysXVehicleMultiWheelDifferentialAPI object is returned upon success. 
    /// An invalid (or empty) UsdPhysXVehicleMultiWheelDifferentialAPI object is returned upon 
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
    static UsdPhysXVehicleMultiWheelDifferentialAPI 
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
    // AVERAGEWHEELSPEEDRATIOS 
    // --------------------------------------------------------------------- //
    /// Defines how the speeds of the driven wheels get weighted when computing the average wheel speed at the clutch (for computing clutch slip).
    /// 
    /// The provided ratios must be in range [0, 1] and under normal circumstances sum up to 1. 
    /// If the attribute is defined, then the length of the array needs to match the length of the "wheels" array. 
    /// If the attribute is not defined, the wheel speeds of all driven wheels will get weighted equally.
    /// 
    /// Note: if a vehicle is using a PhysxVehicleDriveBasicAPI drive, then this attribute should not be used.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float[] physxVehicleMultiWheelDifferential:averageWheelSpeedRatios` |
    /// | C++ Type | VtArray<float> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->FloatArray |
    USDPHYSX_API
    UsdAttribute GetAverageWheelSpeedRatiosAttr() const;

    /// See GetAverageWheelSpeedRatiosAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateAverageWheelSpeedRatiosAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // TORQUERATIOS 
    // --------------------------------------------------------------------- //
    /// Defines how the drive torque should get distributed among the wheels specified in the "wheels" attribute.
    /// 
    /// The provided ratios must be in range [-1, 1] and under normal circumstances the absolute values should sum up to 1. 
    /// If the attribute is defined, then the length of the array needs to match the length of the "wheels" array. 
    /// If the attribute is not defined, the torque will get split equally among all driven wheels.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float[] physxVehicleMultiWheelDifferential:torqueRatios` |
    /// | C++ Type | VtArray<float> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->FloatArray |
    USDPHYSX_API
    UsdAttribute GetTorqueRatiosAttr() const;

    /// See GetTorqueRatiosAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateTorqueRatiosAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // WHEELS 
    // --------------------------------------------------------------------- //
    /// List of indices, referencing the wheels that are driven (receiving torque from the engine).
    /// 
    /// The indices refer to the attribute "index" of PhysxVehicleWheelAttachmentAPI.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int[] physxVehicleMultiWheelDifferential:wheels` |
    /// | C++ Type | VtArray<int> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->IntArray |
    USDPHYSX_API
    UsdAttribute GetWheelsAttr() const;

    /// See GetWheelsAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateWheelsAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

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

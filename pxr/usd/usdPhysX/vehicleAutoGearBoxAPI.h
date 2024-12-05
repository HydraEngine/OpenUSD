//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_GENERATED_VEHICLEAUTOGEARBOXAPI_H
#define USDPHYSX_GENERATED_VEHICLEAUTOGEARBOXAPI_H

/// \file usdPhysX/vehicleAutoGearBoxAPI.h

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
// PHYSXSCHEMAPHYSXVEHICLEAUTOGEARBOXAPI                                      //
// -------------------------------------------------------------------------- //

/// \class UsdPhysXVehicleAutoGearBoxAPI
///
/// 
/// Properties of the PhysX vehicle automatic gear shift box.
/// 
/// If the automatic gear shift box setup does not need to be shared among vehicle instances, it can be applied to the prim which has PhysxVehicleDriveStandardAPI applied. 
/// If the intent is to share the automatic gear shift box setup, PhysxVehicleAutoGearBoxAPI can be applied to a separate prim which can be linked to (see PhysxVehicleDriveStandardAPI).
/// 
///
class UsdPhysXVehicleAutoGearBoxAPI : public UsdAPISchemaBase
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::SingleApplyAPI;

    /// Construct a UsdPhysXVehicleAutoGearBoxAPI on UsdPrim \p prim .
    /// Equivalent to UsdPhysXVehicleAutoGearBoxAPI::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysXVehicleAutoGearBoxAPI(const UsdPrim& prim=UsdPrim())
        : UsdAPISchemaBase(prim)
    {
    }

    /// Construct a UsdPhysXVehicleAutoGearBoxAPI on the prim held by \p schemaObj .
    /// Should be preferred over UsdPhysXVehicleAutoGearBoxAPI(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdPhysXVehicleAutoGearBoxAPI(const UsdSchemaBase& schemaObj)
        : UsdAPISchemaBase(schemaObj)
    {
    }

    /// Destructor.
    USDPHYSX_API
    virtual ~UsdPhysXVehicleAutoGearBoxAPI();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSX_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdPhysXVehicleAutoGearBoxAPI holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdPhysXVehicleAutoGearBoxAPI(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDPHYSX_API
    static UsdPhysXVehicleAutoGearBoxAPI
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
    /// This information is stored by adding "PhysxSchemaPhysxVehicleAutoGearBoxAPI" to the 
    /// token-valued, listOp metadata \em apiSchemas on the prim.
    /// 
    /// \return A valid UsdPhysXVehicleAutoGearBoxAPI object is returned upon success. 
    /// An invalid (or empty) UsdPhysXVehicleAutoGearBoxAPI object is returned upon 
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
    static UsdPhysXVehicleAutoGearBoxAPI 
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
    // DOWNRATIOS 
    // --------------------------------------------------------------------- //
    /// Value of normalized engine speed (engineRotationSpeed / maxRotationSpeed) that is low enough to decrement gear.
    /// 
    /// The first entry is for second gear then up to the highest gear. When (engineRotationSpeed / maxRotationSpeed) < downRatios[currentGear] the autobox will begin a transition to currentGear-1 unless currentGear is first gear or neutral or reverse.
    /// 
    /// Note: if not defined, the following values will be used: [0.5, 0.5, 0.5, 0.5].
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float[] physxVehicleAutoGearBox:downRatios` |
    /// | C++ Type | VtArray<float> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->FloatArray |
    USDPHYSX_API
    UsdAttribute GetDownRatiosAttr() const;

    /// See GetDownRatiosAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateDownRatiosAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // LATENCY 
    // --------------------------------------------------------------------- //
    /// The latency time of the automatic gear shift box (units: seconds).
    /// 
    /// This is the minimum time that must pass between each gear change that is initiated by the automatic gear shift box.
    /// 
    /// Note: if not defined, the value 2.0 will be used.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physxVehicleAutoGearBox:latency` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetLatencyAttr() const;

    /// See GetLatencyAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateLatencyAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // UPRATIOS 
    // --------------------------------------------------------------------- //
    /// Value of normalized engine speed (engineRotationSpeed / maxRotationSpeed) that is high enough to increment gear.
    /// 
    /// The first entry is for first gear and then up to the second highest gear. When (engineRotationSpeed / maxRotationSpeed) > upRatios[currentGear] the autobox will begin a transition to currentGear+1 unless currentGear is the highest possible gear or neutral or reverse.
    /// 
    /// Note: if not defined, the following values will be used: [0.65, 0.65, 0.65, 0.65].
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float[] physxVehicleAutoGearBox:upRatios` |
    /// | C++ Type | VtArray<float> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->FloatArray |
    USDPHYSX_API
    UsdAttribute GetUpRatiosAttr() const;

    /// See GetUpRatiosAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateUpRatiosAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

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

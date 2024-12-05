//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_GENERATED_VEHICLETANKCONTROLLERAPI_H
#define USDPHYSX_GENERATED_VEHICLETANKCONTROLLERAPI_H

/// \file usdPhysX/vehicleTankControllerAPI.h

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
// PHYSXSCHEMAPHYSXVEHICLETANKCONTROLLERAPI                                   //
// -------------------------------------------------------------------------- //

/// \class UsdPhysXVehicleTankControllerAPI
///
/// 
/// PhysX vehicle tank controller to divert torque from the engine to the wheels of the tracks of a wheel based tank vehicle (see PhysxVehicleTankDifferentialAPI).
/// 
/// Note that the "accelerator" attribute of PhysxVehicleControllerAPI still drives the engine torque whereas the thrust controls introduced here define how that torque gets diverted to the wheels, 
/// so both controls need to be used to drive a wheel based tank vehicle usually. This API schema has to be applied to a prim with PhysxVehicleAPI applied. 
/// Can only be used for vehicles that have a standard drive and a tank differential defined (see PhysxVehicleDriveStandardAPI, PhysxVehicleTankDifferentialAPI).
/// 
///
class UsdPhysXVehicleTankControllerAPI : public UsdAPISchemaBase
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::SingleApplyAPI;

    /// Construct a UsdPhysXVehicleTankControllerAPI on UsdPrim \p prim .
    /// Equivalent to UsdPhysXVehicleTankControllerAPI::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysXVehicleTankControllerAPI(const UsdPrim& prim=UsdPrim())
        : UsdAPISchemaBase(prim)
    {
    }

    /// Construct a UsdPhysXVehicleTankControllerAPI on the prim held by \p schemaObj .
    /// Should be preferred over UsdPhysXVehicleTankControllerAPI(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdPhysXVehicleTankControllerAPI(const UsdSchemaBase& schemaObj)
        : UsdAPISchemaBase(schemaObj)
    {
    }

    /// Destructor.
    USDPHYSX_API
    virtual ~UsdPhysXVehicleTankControllerAPI();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSX_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdPhysXVehicleTankControllerAPI holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdPhysXVehicleTankControllerAPI(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDPHYSX_API
    static UsdPhysXVehicleTankControllerAPI
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
    /// This information is stored by adding "PhysxSchemaPhysxVehicleTankControllerAPI" to the 
    /// token-valued, listOp metadata \em apiSchemas on the prim.
    /// 
    /// \return A valid UsdPhysXVehicleTankControllerAPI object is returned upon success. 
    /// An invalid (or empty) UsdPhysXVehicleTankControllerAPI object is returned upon 
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
    static UsdPhysXVehicleTankControllerAPI 
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
    // THRUST0 
    // --------------------------------------------------------------------- //
    /// Magnitude of thrust to apply to the tracks that are assigned to thrust control 0.
    /// 
    /// Values have to be in [-1.0, 1.0] with the sign dictating whether the thrust will be applied positively or negatively with respect to the gearing ratio.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physxVehicleTankController:thrust0 = 0` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetThrust0Attr() const;

    /// See GetThrust0Attr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateThrust0Attr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // THRUST1 
    // --------------------------------------------------------------------- //
    /// Magnitude of thrust to apply to the tracks that are assigned to thrust control 1.
    /// 
    /// Values have to be in [-1.0, 1.0] with the sign dictating whether the thrust will be applied positively or negatively with respect to the gearing ratio.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float physxVehicleTankController:thrust1 = 0` |
    /// | C++ Type | float |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float |
    USDPHYSX_API
    UsdAttribute GetThrust1Attr() const;

    /// See GetThrust1Attr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateThrust1Attr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

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

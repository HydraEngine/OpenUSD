//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_GENERATED_VEHICLENONLINEARCOMMANDRESPONSEAPI_H
#define USDPHYSX_GENERATED_VEHICLENONLINEARCOMMANDRESPONSEAPI_H

/// \file usdPhysX/vehicleNonlinearCommandResponseAPI.h

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
// PHYSXSCHEMAPHYSXVEHICLENONLINEARCOMMANDRESPONSEAPI                         //
// -------------------------------------------------------------------------- //

/// \class UsdPhysXVehicleNonlinearCommandResponseAPI
///
/// 
/// Describes a system of graphs to define nonlinear responses to PhysxVehicleControllerAPI command values like accelerator, brake0, brake1 and steer.
/// 
/// The normalized response will be a function of the command value and the longitudinal vehicle speed. 
/// The response will be computed by interpolating between the points of the graph and then interpolating those results again between the closest graphs. 
/// One example usage of nonlinear command response is a brake pedal that has an almost flat response when tipped slightly but a very strong response from a certain point on. 
/// Another example is the steering wheel showing a strong response for a large input at low speed but only a weak response at high speed.
/// 
/// This multipleApply schema can be used to control the response to steering (use instance name TfToken "steer") and braking (use instance name TfTokens "brakes0" or "brakes1"). 
/// It can also control the response to the accelerator but only in combination with the basic drive (use instance name TfToken "drive"). 
/// Furthermore, this API has to be applied to the appropriate prims to take effect: "steer" has to be applied to a prim that has PhysxVehicleSteeringAPI or PhysxVehicleAckermannSteeringAPI applied. 
/// "brakes0"/"brakes1" have to be applied to a prim that has PhysxVehicleBrakesAPI:brakes0/brakes1 applied. 
/// "drive" has to be applied to a prim that has PhysxVehicleDriveBasicAPI applied.
/// 
///
class UsdPhysXVehicleNonlinearCommandResponseAPI : public UsdAPISchemaBase
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
    static const UsdSchemaKind schemaKind = UsdSchemaKind::SingleApplyAPI;

    /// Construct a UsdPhysXVehicleNonlinearCommandResponseAPI on UsdPrim \p prim .
    /// Equivalent to UsdPhysXVehicleNonlinearCommandResponseAPI::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdPhysXVehicleNonlinearCommandResponseAPI(const UsdPrim& prim=UsdPrim())
        : UsdAPISchemaBase(prim)
    {
    }

    /// Construct a UsdPhysXVehicleNonlinearCommandResponseAPI on the prim held by \p schemaObj .
    /// Should be preferred over UsdPhysXVehicleNonlinearCommandResponseAPI(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdPhysXVehicleNonlinearCommandResponseAPI(const UsdSchemaBase& schemaObj)
        : UsdAPISchemaBase(schemaObj)
    {
    }

    /// Destructor.
    USDPHYSX_API
    virtual ~UsdPhysXVehicleNonlinearCommandResponseAPI();

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDPHYSX_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

    /// Return a UsdPhysXVehicleNonlinearCommandResponseAPI holding the prim adhering to this
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
    /// UsdPhysXVehicleNonlinearCommandResponseAPI(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDPHYSX_API
    static UsdPhysXVehicleNonlinearCommandResponseAPI
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
    /// This information is stored by adding "PhysxSchemaPhysxVehicleNonlinearCommandResponseAPI" to the 
    /// token-valued, listOp metadata \em apiSchemas on the prim.
    /// 
    /// \return A valid UsdPhysXVehicleNonlinearCommandResponseAPI object is returned upon success. 
    /// An invalid (or empty) UsdPhysXVehicleNonlinearCommandResponseAPI object is returned upon 
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
    static UsdPhysXVehicleNonlinearCommandResponseAPI 
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
    // COMMANDVALUES 
    // --------------------------------------------------------------------- //
    /// The command values to define response graphs for.
    /// 
    /// Each listed command value (in range [0, 1], steer commands are treated symmetrically) has to point to a graph in speedResponses. 
    /// The command values refer to steer, brake0 etc. The values have to be strictly increasing. 
    /// The number of entries has to match the number of entries in speedResponsesPerCommandValue and is limited to 8. Every command value needs at least one entry in speedResponses.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float[] commandValues` |
    /// | C++ Type | VtArray<float> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->FloatArray |
    USDPHYSX_API
    UsdAttribute GetCommandValuesAttr() const;

    /// See GetCommandValuesAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateCommandValuesAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // SPEEDRESPONSES 
    // --------------------------------------------------------------------- //
    /// List of pairs that define points in graphs of longitudinal speed vs.
    /// 
    /// normalized response. The first value of the pair is the longitudinal speed, the second value is the expected response (in range [0, 1]). 
    /// The longitudinal speed values within a graph have to be strictly increasing. The maximum allowed number of entries is 64. 
    /// See speedResponsesPerCommandValue for how the different graphs are accessed.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `float2[] speedResponses` |
    /// | C++ Type | VtArray<GfVec2f> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->Float2Array |
    USDPHYSX_API
    UsdAttribute GetSpeedResponsesAttr() const;

    /// See GetSpeedResponsesAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateSpeedResponsesAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

public:
    // --------------------------------------------------------------------- //
    // SPEEDRESPONSESPERCOMMANDVALUE 
    // --------------------------------------------------------------------- //
    /// List of indices pointing to the start of a response graph for a certain command value.
    /// 
    /// The index values have to be strictly increasing. 
    /// The graph for command value commandValues[i] starts at entry speedResponses[speedResponsesPerCommandValue[i]] and stops at entry speedResponses[speedResponsesPerCommandValue[i+1] - 1]. 
    /// The number of entries has to match the number of entries in commandValues and has the same maximum limit.
    /// 
    ///
    /// | ||
    /// | -- | -- |
    /// | Declaration | `int[] speedResponsesPerCommandValue` |
    /// | C++ Type | VtArray<int> |
    /// | \ref Usd_Datatypes "Usd Type" | SdfValueTypeNames->IntArray |
    USDPHYSX_API
    UsdAttribute GetSpeedResponsesPerCommandValueAttr() const;

    /// See GetSpeedResponsesPerCommandValueAttr(), and also 
    /// \ref Usd_Create_Or_Get_Property for when to use Get vs Create.
    /// If specified, author \p defaultValue as the attribute's default,
    /// sparsely (when it makes sense to do so) if \p writeSparsely is \c true -
    /// the default for \p writeSparsely is \c false.
    USDPHYSX_API
    UsdAttribute CreateSpeedResponsesPerCommandValueAttr(VtValue const &defaultValue = VtValue(), bool writeSparsely=false) const;

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

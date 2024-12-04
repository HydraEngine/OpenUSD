//
// Copyright 2016 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_TOKENS_H
#define USDPHYSX_TOKENS_H

/// \file usdPhysX/tokens.h

// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// 
// This is an automatically generated file (by usdGenSchema.py).
// Do not hand-edit!
// 
// XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#include "pxr/pxr.h"
#include "pxr/usd/usdPhysX/api.h"
#include "pxr/base/tf/staticData.h"
#include "pxr/base/tf/token.h"
#include <vector>

PXR_NAMESPACE_OPEN_SCOPE


/// \class UsdPhysXTokensType
///
/// \link UsdPhysXTokens \endlink provides static, efficient
/// \link TfToken TfTokens\endlink for use in all public USD API.
///
/// These tokens are auto-generated from the module's schema, representing
/// property names, for when you need to fetch an attribute or relationship
/// directly by name, e.g. UsdPrim::GetAttribute(), in the most efficient
/// manner, and allow the compiler to verify that you spelled the name
/// correctly.
///
/// UsdPhysXTokens also contains all of the \em allowedTokens values
/// declared for schema builtin attributes of 'token' scene description type.
/// Use UsdPhysXTokens like so:
///
/// \code
///     gprim.GetMyTokenValuedAttr().Set(UsdPhysXTokens->jointState);
/// \endcode
struct UsdPhysXTokensType {
    USDPHYSX_API UsdPhysXTokensType();
    /// \brief "jointState"
    /// 
    /// Property namespace prefix for the UsdPhysXJointStateAPI schema.
    const TfToken jointState;
    /// \brief "jointState:__INSTANCE_NAME__:physics:position"
    /// 
    /// UsdPhysXJointStateAPI
    const TfToken jointState_MultipleApplyTemplate_PhysicsPosition;
    /// \brief "jointState:__INSTANCE_NAME__:physics:velocity"
    /// 
    /// UsdPhysXJointStateAPI
    const TfToken jointState_MultipleApplyTemplate_PhysicsVelocity;
    /// \brief "PhysxSchemaJointStateAPI"
    /// 
    /// Schema identifer and family for UsdPhysXJointStateAPI
    const TfToken PhysxSchemaJointStateAPI;
    /// A vector of all of the tokens listed above.
    const std::vector<TfToken> allTokens;
};

/// \var UsdPhysXTokens
///
/// A global variable with static, efficient \link TfToken TfTokens\endlink
/// for use in all public USD API.  \sa UsdPhysXTokensType
extern USDPHYSX_API TfStaticData<UsdPhysXTokensType> UsdPhysXTokens;

PXR_NAMESPACE_CLOSE_SCOPE

#endif

//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/usdImaging/usdPhysicsImaging/fixedJointSchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"
#include "pxr/usd/usdPhysics/tokens.h"
#include "pxr/usd/usdPhysics/tokens.h"

PXR_NAMESPACE_OPEN_SCOPE

/*static*/
HdFixedJointSchema HdFixedJointSchema::GetFromParent(const HdContainerDataSourceHandle &fromParentContainer) {
    return HdFixedJointSchema(fromParentContainer ? HdContainerDataSource::Cast(fromParentContainer->Get(
                                                              UsdPhysicsTokens->PhysicsFixedJoint))
                                                     : nullptr);
}

/*static*/
const TfToken &HdFixedJointSchema::GetSchemaToken() { return UsdPhysicsTokens->PhysicsFixedJoint; }

/*static*/
const HdDataSourceLocator &HdFixedJointSchema::GetDefaultLocator() {
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}


PXR_NAMESPACE_CLOSE_SCOPE
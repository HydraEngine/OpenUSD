//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include "pxr/imaging/hd/physicsSchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdPhysicsSchemaTokens,
    HD_PHYSICS_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--

/*static*/
HdPhysicsSchema
HdPhysicsSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer)
{
    return HdPhysicsSchema(
        fromParentContainer
        ? HdContainerDataSource::Cast(fromParentContainer->Get(
                HdPhysicsSchemaTokens->physics))
        : nullptr);
}

/*static*/
const TfToken &
HdPhysicsSchema::GetSchemaToken()
{
    return HdPhysicsSchemaTokens->physics;
}

/*static*/
const HdDataSourceLocator &
HdPhysicsSchema::GetDefaultLocator()
{
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

PXR_NAMESPACE_CLOSE_SCOPE
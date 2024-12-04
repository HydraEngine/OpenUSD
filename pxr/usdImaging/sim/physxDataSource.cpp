//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include <pxr/imaging/hd/xformSchema.h>

#include "physxDataSource.h"
#include "pxr/imaging/hd/retainedDataSource.h"
#include "pxr/base/gf/rotation.h"
#include "physxEngine.h"
#include "utils.h"

#include <iostream>
#include <utility>

PXR_NAMESPACE_OPEN_SCOPE

HdPhysXDataSource::HdPhysXDataSource(HdSceneIndexBaseRefPtr sceneIndex,
                                     SdfPath primPath,
                                     HdContainerDataSourceHandle wrappedDataSource)
    : _sceneIndex(sceneIndex), _primPath(std::move(primPath)), _wrappedDataSource(std::move(wrappedDataSource)) {}

void HdPhysXDataSource::UpdateWrappedDataSource(HdContainerDataSourceHandle wrappedDataSource) {
    _wrappedDataSource = std::move(wrappedDataSource);
}

TfTokenVector HdPhysXDataSource::GetNames() {
    return (_wrappedDataSource == nullptr) ? TfTokenVector() : _wrappedDataSource->GetNames();
}

HdDataSourceBaseHandle HdPhysXDataSource::Get(const TfToken& name) {
    if (name == HdXformSchemaTokens->xform) {
        auto engine = sim::PhysxEngine::GetIfExists();
        SdfPath dynamicActorPath;
        physx::PxRigidDynamic* actor;
        for (const auto& ancestors : _primPath.GetAncestorsRange()) {
            actor = engine->FindDynamicsActor(ancestors);
            if (actor) {
                dynamicActorPath = ancestors;
            }
        }

        if (!actor) {
            return _wrappedDataSource->Get(name);
        }

        auto actorPrim = _sceneIndex->GetPrim(dynamicActorPath);
        HdXformSchema xformSchema = HdXformSchema::GetFromParent(actorPrim.dataSource);
        auto actorMatrix = xformSchema.GetMatrix()->GetTypedValue(0);

        auto prim = _sceneIndex->GetPrim(_primPath);
        xformSchema = HdXformSchema::GetFromParent(actorPrim.dataSource);
        auto shapeMatrix = xformSchema.GetMatrix()->GetTypedValue(0);
        shapeMatrix = shapeMatrix / actorMatrix;

        auto globalPose = convert(actor->getGlobalPose());
        shapeMatrix = shapeMatrix * globalPose;

        return HdXformSchema::Builder()
                .SetMatrix(HdRetainedTypedSampledDataSource<GfMatrix4d>::New(shapeMatrix))
                .Build();
    }

    // all other token values should be defer to the wrapped data source (if any)
    if (_wrappedDataSource != nullptr) {
        return _wrappedDataSource->Get(name);
    }

    return nullptr;
}

PXR_NAMESPACE_CLOSE_SCOPE
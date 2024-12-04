//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#include <pxr/imaging/hd/xformSchema.h>

#include "physxDataSource.h"

#include <iostream>
#include <utility>

PXR_NAMESPACE_OPEN_SCOPE

HdPhysXDataSource::HdPhysXDataSource(SdfPath  primPath,
                                     HdContainerDataSourceHandle wrappedDataSource)
    : _primPath(std::move(primPath)), _wrappedDataSource(std::move(wrappedDataSource)) {}

void HdPhysXDataSource::UpdateWrappedDataSource(HdContainerDataSourceHandle wrappedDataSource) {
    _wrappedDataSource = std::move(wrappedDataSource);
}

TfTokenVector HdPhysXDataSource::GetNames() {
    return (_wrappedDataSource == nullptr) ? TfTokenVector() : _wrappedDataSource->GetNames();
}

HdDataSourceBaseHandle HdPhysXDataSource::Get(const TfToken& name) {
    if (name == HdXformSchemaTokens->xform) {
        // this is an intercept of the flattened transform matrix
        // we need to dynamically compute a geospatial one
        std::cout << "lalala: " << _primPath << std::endl;
        return _wrappedDataSource->Get(name);
    }

    // all other token values should be defer to the wrapped data source (if any)
    if (_wrappedDataSource != nullptr) {
        return _wrappedDataSource->Get(name);
    }

    return nullptr;
}

PXR_NAMESPACE_CLOSE_SCOPE
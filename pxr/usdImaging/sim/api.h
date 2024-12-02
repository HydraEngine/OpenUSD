//  Copyright (c) 2024 Feng Yang
//
//  I am making my contributions/submissions to this project solely in my
//  personal capacity and am not conveying any rights to any intellectual
//  property of any third parties.

#pragma once

#include "pxr/base/arch/export.h"

#if defined(PXR_STATIC)
#define USDSIM_API
#define USDSIM_API_TEMPLATE_CLASS(...)
#define USDSIM_API_TEMPLATE_STRUCT(...)
#define USDSIM_LOCAL
#else
#if defined(USDSIM_EXPORTS)
#define USDSIM_API ARCH_EXPORT
#define USDSIM_API_TEMPLATE_CLASS(...) ARCH_EXPORT_TEMPLATE(class, __VA_ARGS__)
#define USDSIM_API_TEMPLATE_STRUCT(...) ARCH_EXPORT_TEMPLATE(struct, __VA_ARGS__)
#else
#define USDSIM_API ARCH_IMPORT
#define USDSIM_API_TEMPLATE_CLASS(...) ARCH_IMPORT_TEMPLATE(class, __VA_ARGS__)
#define USDSIM_API_TEMPLATE_STRUCT(...) ARCH_IMPORT_TEMPLATE(struct, __VA_ARGS__)
#endif
#define USDSIM_LOCAL ARCH_HIDDEN
#endif

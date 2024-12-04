//
// Copyright 2017 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef USDPHYSX_API_H
#define USDPHYSX_API_H

#include "pxr/base/arch/export.h"

#if defined(PXR_STATIC)
#   define USDPHYSX_API
#   define USDPHYSX_API_TEMPLATE_CLASS(...)
#   define USDPHYSX_API_TEMPLATE_STRUCT(...)
#   define USDPHYSX_LOCAL
#else
#   if defined(USDPHYSX_EXPORTS)
#       define USDPHYSX_API ARCH_EXPORT
#       define USDPHYSX_API_TEMPLATE_CLASS(...) ARCH_EXPORT_TEMPLATE(class, __VA_ARGS__)
#       define USDPHYSX_API_TEMPLATE_STRUCT(...) ARCH_EXPORT_TEMPLATE(struct, __VA_ARGS__)
#   else
#       define USDPHYSX_API ARCH_IMPORT
#       define USDPHYSX_API_TEMPLATE_CLASS(...) ARCH_IMPORT_TEMPLATE(class, __VA_ARGS__)
#       define USDPHYSX_API_TEMPLATE_STRUCT(...) ARCH_IMPORT_TEMPLATE(struct, __VA_ARGS__)
#   endif
#   define USDPHYSX_LOCAL ARCH_HIDDEN
#endif

#endif

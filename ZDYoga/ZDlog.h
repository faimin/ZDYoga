/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#if __has_include(<ZDYoga/ZDYGEnums.h>)
#include <ZDYoga/ZDYGEnums.h>
#else
#include "ZDYGEnums.h"
#endif

struct YGNode;
struct YGConfig;

namespace facebook::yoga::detail {

struct Log {
  static void log(
      YGNode* node,
      YGLogLevel level,
      void*,
      const char* message,
      ...) noexcept;

  static void log(
      YGConfig* config,
      YGLogLevel level,
      void*,
      const char* format,
      ...) noexcept;
};

} // namespace facebook::yoga::detail

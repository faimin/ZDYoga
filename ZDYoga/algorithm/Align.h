/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <ZDYoga/Yoga.h>

#include <ZDYoga/algorithm/FlexDirection.h>
#include <ZDYoga/node/Node.h>

namespace facebook::yoga {

inline Align resolveChildAlignment(
    const yoga::Node* node,
    const yoga::Node* child) {
  const Align align = child->style().alignSelf() == Align::Auto
      ? node->style().alignItems()
      : child->style().alignSelf();
  if (align == Align::Baseline && isColumn(node->style().flexDirection())) {
    return Align::FlexStart;
  }
  return align;
}

} // namespace facebook::yoga

/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <ZDYoga/algorithm/FlexDirection.h>
#include <ZDYoga/enums/Dimension.h>
#include <ZDYoga/enums/FlexDirection.h>
#include <ZDYoga/node/Node.h>
#include <ZDYoga/numeric/Comparison.h>
#include <ZDYoga/numeric/FloatOptional.h>

namespace facebook::yoga {

inline float paddingAndBorderForAxis(
    const yoga::Node* const node,
    const FlexDirection axis,
    const Direction direction,
    const float widthSize) {
  return node->style().computeInlineStartPaddingAndBorder(
             axis, direction, widthSize) +
      node->style().computeInlineEndPaddingAndBorder(
          axis, direction, widthSize);
}

inline FloatOptional boundAxisWithinMinAndMax(
    const yoga::Node* const node,
    const FlexDirection axis,
    const FloatOptional value,
    const float axisSize) {
  FloatOptional min;
  FloatOptional max;

  if (isColumn(axis)) {
    min = node->style().minDimension(Dimension::Height).resolve(axisSize);
    max = node->style().maxDimension(Dimension::Height).resolve(axisSize);
  } else if (isRow(axis)) {
    min = node->style().minDimension(Dimension::Width).resolve(axisSize);
    max = node->style().maxDimension(Dimension::Width).resolve(axisSize);
  }

  if (max >= FloatOptional{0} && value > max) {
    return max;
  }

  if (min >= FloatOptional{0} && value < min) {
    return min;
  }

  return value;
}

// Like boundAxisWithinMinAndMax but also ensures that the value doesn't
// go below the padding and border amount.
inline float boundAxis(
    const yoga::Node* const node,
    const FlexDirection axis,
    const Direction direction,
    const float value,
    const float axisSize,
    const float widthSize) {
  return yoga::maxOrDefined(
      boundAxisWithinMinAndMax(node, axis, FloatOptional{value}, axisSize)
          .unwrap(),
      paddingAndBorderForAxis(node, axis, direction, widthSize));
}

} // namespace facebook::yoga

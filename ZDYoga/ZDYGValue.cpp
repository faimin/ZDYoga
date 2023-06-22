/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#if __has_include(<ZDYoga/ZDYGValue.h>)
#include <ZDYoga/ZDYGValue.h>
#else
#include "ZDYGValue.h"
#endif

const YGValue YGValueZero = {0, YGUnitPoint};
const YGValue YGValueUndefined = {YGUndefined, YGUnitUndefined};
const YGValue YGValueAuto = {YGUndefined, YGUnitAuto};

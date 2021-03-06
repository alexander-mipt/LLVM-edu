//===-- sanitizer_hash_test.cpp -------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file is a part of Sanitizers.
//
//===----------------------------------------------------------------------===//
#include "sanitizer_common/sanitizer_hash.h"

#include "gtest/gtest.h"

namespace __sanitizer {

// Tests matche a few hashes generated by https://github.com/aappleby/smhasher.

TEST(SanitizerCommon, Hash32Seed) {
  EXPECT_EQ(MurMur2HashBuilder(0).get(), 275646681u);
  EXPECT_EQ(MurMur2HashBuilder(1).get(), 3030210376u);
  EXPECT_EQ(MurMur2HashBuilder(3).get(), 1816185114u);
}

TEST(SanitizerCommon, Hash32Add) {
  MurMur2HashBuilder h(123 * sizeof(u32));
  for (u32 i = 0; i < 123; ++i) h.add(i);
  EXPECT_EQ(h.get(), 351963665u);
  for (u32 i = 0; i < 123; ++i) h.add(-i);
  EXPECT_EQ(h.get(), 2640061027u);
}

TEST(SanitizerCommon, Hash64Seed) {
  EXPECT_EQ(MurMur2Hash64Builder(0).get(), 4469829599815726255ull);
  EXPECT_EQ(MurMur2Hash64Builder(1).get(), 14121968454562043709ull);
  EXPECT_EQ(MurMur2Hash64Builder(3).get(), 8040757559320203998ull);
}

TEST(SanitizerCommon, Hash64Add) {
  MurMur2Hash64Builder h(123 * sizeof(u64));
  for (u32 i = 0; i < 123; ++i) h.add(i);
  EXPECT_EQ(h.get(), 11366430808886012537ull);
  for (u32 i = 0; i < 123; ++i) h.add(-i);
  EXPECT_EQ(h.get(), 10843188204560467446ull);
}

}  // namespace __sanitizer

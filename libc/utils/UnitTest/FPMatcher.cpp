//===-- TestMatchers.cpp ----------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "FPMatcher.h"

#include "src/__support/FPUtil/FPBits.h"

#include <string>

namespace __llvm_libc {
namespace fputil {
namespace testing {

// Return the first N hex digits of an integer as a string in upper case.
template <typename T>
cpp::EnableIfType<cpp::IsIntegral<T>::Value, std::string>
uintToHex(T X, size_t Length = sizeof(T) * 2) {
  std::string s(Length, '0');

  for (auto it = s.rbegin(), end = s.rend(); it != end; ++it, X >>= 4) {
    unsigned char Mod = static_cast<unsigned char>(X) & 15;
    *it = (Mod < 10 ? '0' + Mod : 'a' + Mod - 10);
  }

  return s;
}

template <typename ValType>
cpp::EnableIfType<cpp::IsFloatingPointType<ValType>::Value, void>
describeValue(const char *label, ValType value,
              testutils::StreamWrapper &stream) {
  stream << label;

  FPBits<ValType> bits(value);
  if (bits.isNaN()) {
    stream << "(NaN)";
  } else if (bits.isInf()) {
    if (bits.getSign())
      stream << "(-Infinity)";
    else
      stream << "(+Infinity)";
  } else {
    constexpr int exponentWidthInHex =
        (fputil::ExponentWidth<ValType>::value - 1) / 4 + 1;
    constexpr int mantissaWidthInHex =
        (fputil::MantissaWidth<ValType>::value - 1) / 4 + 1;

    stream << "Sign: " << (bits.getSign() ? '1' : '0') << ", "
           << "Exponent: 0x"
           << uintToHex<uint16_t>(bits.getUnbiasedExponent(),
                                  exponentWidthInHex)
           << ", "
           << "Mantissa: 0x"
           << uintToHex<typename fputil::FPBits<ValType>::UIntType>(
                  bits.getMantissa(), mantissaWidthInHex);
  }

  stream << '\n';
}

template void describeValue<float>(const char *, float,
                                   testutils::StreamWrapper &);
template void describeValue<double>(const char *, double,
                                    testutils::StreamWrapper &);
template void describeValue<long double>(const char *, long double,
                                         testutils::StreamWrapper &);

} // namespace testing
} // namespace fputil
} // namespace __llvm_libc

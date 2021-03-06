//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <ostream>

// template <class Stream, class T>
// Stream&& operator<<(Stream&& os, const T& x);

#include <ostream>
#include <cassert>

#include "test_macros.h"


template <class CharT>
class testbuf
    : public std::basic_streambuf<CharT>
{
    typedef std::basic_streambuf<CharT> base;
    std::basic_string<CharT> str_;
public:
    testbuf()
    {
    }

    std::basic_string<CharT> str() const
        {return std::basic_string<CharT>(base::pbase(), base::pptr());}

protected:

    virtual typename base::int_type
        overflow(typename base::int_type ch = base::traits_type::eof())
        {
            if (ch != base::traits_type::eof())
            {
                int n = static_cast<int>(str_.size());
                str_.push_back(static_cast<CharT>(ch));
                str_.resize(str_.capacity());
                base::setp(const_cast<CharT*>(str_.data()),
                           const_cast<CharT*>(str_.data() + str_.size()));
                base::pbump(n+1);
            }
            return ch;
        }
};

struct Int {
    int value;
    template <class CharT>
    friend void operator<<(std::basic_ostream<CharT>& os, Int const& self) {
        os << self.value;
    }
};

int main(int, char**)
{
    {
        testbuf<char> sb;
        std::ostream os(&sb);
        Int const i = {123};
        std::ostream&& result = (std::move(os) << i);
        assert(&result == &os);
        assert(sb.str() == "123");
    }
#ifndef TEST_HAS_NO_WIDE_CHARACTERS
    {
        testbuf<wchar_t> sb;
        std::wostream os(&sb);
        Int const i = {123};
        std::wostream&& result = (std::move(os) << i);
        assert(&result == &os);
        assert(sb.str() == L"123");
    }
#endif

    return 0;
}

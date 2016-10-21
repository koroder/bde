// bdlt_datetimeinterval.cpp                                          -*-C++-*-
#include <bdlt_datetimeinterval.h>

#include <bsls_ident.h>
BSLS_IDENT_RCSID(bdlt_datetimeinterval_cpp,"$Id$ $CSID$")

#include <bdlb_bitutil.h>

#include <bslim_printer.h>

#include <bslmf_assert.h>

#include <bsl_cstdio.h>    // 'sprintf'
#include <bsl_ostream.h>

namespace BloombergLP {

// Assert fundamental assumptions made in the implementation.

BSLMF_ASSERT(-3 / 2 == -1);
BSLMF_ASSERT(-5 % 4 == -1);

namespace bdlt {

                          // ----------------------
                          // class DatetimeInterval
                          // ----------------------

// CLASS DATA
bsls::AtomicInt64 DatetimeInterval::s_maxSentinelCount(0);
bsls::AtomicInt64 DatetimeInterval::s_minSentinelCount(0);
bsls::AtomicInt64 DatetimeInterval::s_otherProposedRangeViolationCount(0);

// PRIVATE MANIPULATORS
void DatetimeInterval::logProposedRangeViolation()
{
    if (k_MILLISECONDS_MIN == d_milliseconds) {
        bdlb::BitUtil::uint64_t count =
                    static_cast<bdlb::BitUtil::uint64_t>(++s_minSentinelCount);
        if (count == bdlb::BitUtil::roundUpToBinaryPower(count)) {
            BSLS_LOG_SIMPLE(bsls::LogSeverity::e_ERROR,
                      "detected 'bdlt::DatetimeInterval::k_MILLISECONDS_MIN'");
        }
    }
    else if (k_MILLISECONDS_MAX == d_milliseconds) {
        bdlb::BitUtil::uint64_t count =
                    static_cast<bdlb::BitUtil::uint64_t>(++s_maxSentinelCount);
        if (count == bdlb::BitUtil::roundUpToBinaryPower(count)) {
            BSLS_LOG_SIMPLE(bsls::LogSeverity::e_ERROR,
                      "detected 'bdlt::DatetimeInterval::k_MILLISECONDS_MAX'");
        }
    }
    else {
        bdlb::BitUtil::uint64_t count = static_cast<bdlb::BitUtil::uint64_t>(
                                         ++s_otherProposedRangeViolationCount);
        if (count == bdlb::BitUtil::roundUpToBinaryPower(count)) {
            BSLS_LOG_ERROR("detected 'bdlt::DatetimeInterval' "
                                          "proposed range violation (%lld ms)",
                     d_milliseconds);
        }
    }
}

// ACCESSORS

                                  // Aspects

bsl::ostream& DatetimeInterval::print(bsl::ostream& stream,
                                      int           level,
                                      int           spacesPerLevel) const
{
    // space usage:    s dd...d _  hh: mm: ss: mmm null
    const int k_SIZE = 1 + 10 + 1 + 3 + 3 + 3 + 3 + 1;
    char      buf[k_SIZE];

    const int d  = days();
    const int h  = hours();
    const int m  = minutes();
    const int s  = seconds();
    const int ms = milliseconds();

    if (totalMilliseconds() < 0) {
        char *p = buf;

        if (0 == d) {
            *p++ = '-';  // '-' comes from 'd' only if 'd < 0'.
        }

        bsl::sprintf(p,    "%d_%02d:%02d:%02d.%03d", d, -h, -m, -s, -ms);
    }
    else {
        bsl::sprintf(buf, "+%d_%02d:%02d:%02d.%03d", d, h, m, s, ms);
    }

    bslim::Printer printer(&stream, level, spacesPerLevel);
    printer.start(true);  // 'true' -> suppress '['
    stream << buf;
    printer.end(true);    // 'true' -> suppress ']'

    return stream;
}


}  // close package namespace
}  // close enterprise namespace

// ----------------------------------------------------------------------------
// Copyright 2016 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------

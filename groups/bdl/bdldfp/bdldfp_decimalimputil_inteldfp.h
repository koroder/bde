// bdldfp_decimalimputil_inteldfp.h                                           -*-C++-*-
#ifndef INCLUDED_BDLDFP_DECIMALIMPUTIL_INTELDFP
#define INCLUDED_BDLDFP_DECIMALIMPUTIL_INTELDFP

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id$")

//@PURPOSE: Provide utility to implement decimal 'float's on the Intel library.
//
//@CLASSES:
//  bdldfp::DecimalImpUtil_IntelDFP: Namespace for Intel decimal FP functions
//
//@SEE_ALSO: bdldfp_decimal, bdldfp_decimalplatform
//
//@DESCRIPTION:
// This component is for internal use only by the 'bdldfp_decimal*' components.
// Direct use of any names declared in this component by any other code invokes
// undefined behavior.  In other words: this code may change, disappear, break,
// move without notice, and no support whatsoever will ever be provided for it.
//
///Usage
///-----
// This section shows the intended use of this component.
//
///Example 1: 
///- - - - - - - - - - - - - - - - - - - - - - - - -

#ifndef INCLUDED_BDLSCM_VERSION
#include <bdlscm_version.h>
#endif

#ifndef INCLUDED_BDLDFP_DECIMALPLATFORM
#include <bdldfp_decimalplatform.h>
#endif

#if BDLDFP_DECIMALPLATFORM_INTELDFP


#ifndef INCLUDED_BID_FUNCTIONS

// Controlling macros for the intel library configuration

#  define DECIMAL_CALL_BY_REFERENCE      0
#  define DECIMAL_GLOBAL_ROUNDING        1
#  define DECIMAL_GLOBAL_EXCEPTION_FLAGS 1

// in C++, there's always a 'wchar_t' type, so we need to tell Intel's library
// about this.

#  define _WCHAR_T_DEFINED

   extern "C" {
#   include <bid_conf.h>
#   include <bid_functions.h>
   }
#  define INCLUDED_BID_FUNCTIONS
#endif



namespace BloombergLP {
namespace bdldfp {

                          // ==============================
                          // class DecimalImplUtil_IntelDFP
                          // ==============================

struct DecimalImpUtil_IntelDFP {
    // This 'struct' provides a namespace for implementation functions that
    // work in terms of the underlying C-style decimal floating point
    // implementation, Intel's DFP library.

    // TYPES
    struct ValueType32  { BID_UINT32  d_raw; };
    struct ValueType64  { BID_UINT64  d_raw; };
    struct ValueType128 { BID_UINT128 d_raw; };

    struct DecimalTriple {
        bool               sign;  // 'true' if negative, 'false' if positive.
        unsigned long long mantissa;
        int                exponent;
    };

    // CLASS METHODS

                        // compose and decompose

    static ValueType32  composeDecimal32 (DecimalTriple triple);
    static ValueType64  composeDecimal64 (DecimalTriple triple);
    static ValueType128 composeDecimal128(DecimalTriple triple);
        // Return a 'ValueTypeXX' number having the value as specified by the
        // salient attributes of the specified 'triple'.  The behavior is
        // undefined if the 'mantissa' has too many decimal digits for
        // 'ValueType', or the 'exponent' is too large for 'ValueType'

    static DecimalTriple decomposeDecimal(ValueType32  value);
    static DecimalTriple decomposeDecimal(ValueType64  value);
    static DecimalTriple decomposeDecimal(ValueType128 value);
        // Return a 'DecimalTriple' object representing the salient attributes
        // of the specified 'value'.  The behavior is undefined, unless 'value'
        // is neither 'NaN' nor 'Inf'.

                        // Integer construction

    static ValueType32  int32ToDecimal32 (int value);
    static ValueType64  int32ToDecimal64 (int value);
    static ValueType128 int32ToDecimal128(int value);

    static ValueType32  uint32ToDecimal32 (unsigned int value);
    static ValueType64  uint32ToDecimal64 (unsigned int value);
    static ValueType128 uint32ToDecimal128(unsigned int value);

    static ValueType32  int64ToDecimal32 (long long int value);
    static ValueType64  int64ToDecimal64 (long long int value);
    static ValueType128 int64ToDecimal128(long long int value);

    static ValueType32  uint64ToDecimal32 (unsigned long long int value);
    static ValueType64  uint64ToDecimal64 (unsigned long long int value);
    static ValueType128 uint64ToDecimal128(unsigned long long int value);

                        // Arithmetic

    static ValueType64  add(ValueType64  lhs,  ValueType64  rhs);
    static ValueType128 add(ValueType128 lhs,  ValueType128 rhs);

    static ValueType64  sub(ValueType64  lhs,  ValueType64  rhs);
    static ValueType128 sub(ValueType128 lhs,  ValueType128 rhs);

    static ValueType64  mul(ValueType64  lhs,  ValueType64  rhs);
    static ValueType128 mul(ValueType128 lhs,  ValueType128 rhs);

    static ValueType64  div(ValueType64  lhs,  ValueType64  rhs);
    static ValueType128 div(ValueType128 lhs,  ValueType128 rhs);

    static ValueType32  neg(ValueType32  value);
    static ValueType64  neg(ValueType64  value);
    static ValueType128 neg(ValueType128 value);

                        // Comparison

    static bool less(ValueType32  lhs, ValueType32  rhs);
    static bool less(ValueType64  lhs, ValueType64  rhs);
    static bool less(ValueType128 lhs, ValueType128 rhs);

    static bool greater(ValueType32  lhs, ValueType32  rhs);
    static bool greater(ValueType64  lhs, ValueType64  rhs);
    static bool greater(ValueType128 lhs, ValueType128 rhs);

    static bool lessEqual(ValueType32  lhs, ValueType32  rhs);
    static bool lessEqual(ValueType64  lhs, ValueType64  rhs);
    static bool lessEqual(ValueType128 lhs, ValueType128 rhs);

    static bool greaterEqual(ValueType32  lhs, ValueType32  rhs);
    static bool greaterEqual(ValueType64  lhs, ValueType64  rhs);
    static bool greaterEqual(ValueType128 lhs, ValueType128 rhs);

    static bool equal(ValueType32  lhs, ValueType32  rhs);
    static bool equal(ValueType64  lhs, ValueType64  rhs);
    static bool equal(ValueType128 lhs, ValueType128 rhs);
        // Return 'true' if the specified 'lhs' and 'rhs' have the same value,
        // and 'false' otherwise.  Two decimal objects have the same value if
        // the 'compareQuietEqual' operation (IEEE-754 defined, non-total
        // ordering comparison) considers the underlying IEEE representations
        // equal.  In other words, two decimal objects have the same value if:
        //
        //: o both have a zero value (positive or negative), or
        //:
        //: o both have the same infinity value (both positive or negative), or
        //:
        //: o both have the value of a real number that are equal, even if they
        //:   are represented differently (cohorts have the same value)
        //
        // This operation raises the "invalid" floating-point exception if
        // either or both operands are NaN.

    static bool notEqual(ValueType32  lhs, ValueType32  rhs);
    static bool notEqual(ValueType64  lhs, ValueType64  rhs);
    static bool notEqual(ValueType128 lhs, ValueType128 rhs);
        // Return 'false' if the specified 'lhs' and 'rhs' have the same value,
        // and 'true' otherwise.  Two decimal objects have the same value if
        // the 'compareQuietEqual' operation (IEEE-754 defined, non-total
        // ordering comparison) considers the underlying IEEE representations
        // equal.  In other words, two decimal objects have the same value if:
        //
        //: o both have a zero value (positive or negative), or
        //:
        //: o both have the same infinity value (both positive or negative), or
        //:
        //: o both have the value of a real number that are equal, even if they
        //:   are represented differently (cohorts have the same value)
        //
        // This operation raises the "invalid" floating-point exception if
        // either or both operands are NaN.

    static ValueType32  convertToDecimal32 (const ValueType64&  input);
    static ValueType64  convertToDecimal64 (const ValueType32&  input);
    static ValueType64  convertToDecimal64 (const ValueType128& input);
    static ValueType128 convertToDecimal128(const ValueType32&  input);
    static ValueType128 convertToDecimal128(const ValueType64&  input);
        // Convert the specified 'input' to the indicated result type.  Note
        // that a conversion from 'ValueType128' to 'ValueType32' is not
        // provided (because such a conversion is not provided by the
        // 'decNumber' library).  A conversion from 128-bit to 32-bit
        // representations is *not* identical to the composing the conversions
        // from 128-bit to 64-bit, and 64-bit to 32-bit representations,
        // because rounding should only be performed once.

    static ValueType32  binaryToDecimal32(      float input);
    static ValueType32  binaryToDecimal32(     double input);
    static ValueType32  binaryToDecimal32(long double input);

    static ValueType64  binaryToDecimal64(      float input);
    static ValueType64  binaryToDecimal64(     double input);
    static ValueType64  binaryToDecimal64(long double input);

    static ValueType128 binaryToDecimal128(      float input);
    static ValueType128 binaryToDecimal128(     double input);
    static ValueType128 binaryToDecimal128(long double input);

    static ValueType32  makeDecimalRaw32(int mantissa, int exponent);
        // Create a 'ValueType32' object representing a decimal floating point
        // number consisting of the specified 'mantissa' and 'exponent', with
        // the sign given by 'mantissa'.  The behavior is undefined unless
        // 'abs(mantissa) <= 9,999,999' and '-101 <= exponent <= 90'.

    static ValueType64 makeDecimalRaw64(unsigned long long mantissa,
                                        int                exponent);
    static ValueType64 makeDecimalRaw64(long long          mantissa,
                                        int                exponent);
    static ValueType64 makeDecimalRaw64(unsigned int       mantissa,
                                        int                exponent);
    static ValueType64 makeDecimalRaw64(int                mantissa,
                                        int                exponent);
        // Create a 'ValueType64' object representing a decimal floating point
        // number consisting of the specified 'mantissa' and 'exponent', with
        // the sign given by 'mantissa'.  The behavior is undefined unless
        // 'abs(mantissa) <= 9,999,999,999,999,999' and
        // '-398 <= exponent <= 369'.

    static ValueType128 makeDecimalRaw128(unsigned long long mantissa,
                                          int                exponent);
    static ValueType128 makeDecimalRaw128(long long          mantissa,
                                          int                exponent);
    static ValueType128 makeDecimalRaw128(unsigned int       mantissa,
                                          int                exponent);
    static ValueType128 makeDecimalRaw128(int                mantissa,
                                          int                exponent);
        // Create a 'ValueType128' object representing a decimal floating point
        // number consisting of the specified 'mantissa' and 'exponent', with
        // the sign given by 'mantissa'.  The behavior is undefined unless
        // '-6176 <= exponent <= 6111'.

    static ValueType32 scaleB(ValueType32 value, int power);
    static ValueType64 scaleB(ValueType64 value, int power);
    static ValueType128 scaleB(ValueType128 value, int power);


    static ValueType32  parse32 (const char *string);
    static ValueType64  parse64 (const char *string);
    static ValueType128 parse128(const char *string);
};

typedef DecimalImpUtil_IntelDFP DecimalImpUtil_Platform;


    // Inline functions

                        // Integer construction

inline
DecimalImpUtil_Platform::ValueType32 DecimalImpUtil_Platform::int32ToDecimal32(int value)
{
    DecimalImpUtil_Platform::ValueType32 retval;
    retval.d_raw = __bid32_from_int32(value);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType64 DecimalImpUtil_Platform::int32ToDecimal64(int value)
{
    DecimalImpUtil_Platform::ValueType64 retval;
    retval.d_raw = __bid64_from_int32(value);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType128 DecimalImpUtil_Platform::int32ToDecimal128(int value)
{
    DecimalImpUtil_Platform::ValueType128 retval;
    retval.d_raw = __bid128_from_int32(value);
    return retval;
}


inline
DecimalImpUtil_Platform::ValueType32 DecimalImpUtil_Platform::uint32ToDecimal32(
                                                            unsigned int value)
{
    DecimalImpUtil_Platform::ValueType32 retval;
    retval.d_raw = __bid32_from_uint32(value);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType64 DecimalImpUtil_Platform::uint32ToDecimal64(
                                                            unsigned int value)
{
    DecimalImpUtil_Platform::ValueType64 retval;
    retval.d_raw = __bid64_from_uint32(value);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType128 DecimalImpUtil_Platform::uint32ToDecimal128(
                                                            unsigned int value)
{
    DecimalImpUtil_Platform::ValueType128 retval;
    retval.d_raw = __bid128_from_uint32(value);
    return retval;
}


inline
DecimalImpUtil_Platform::ValueType32 DecimalImpUtil_Platform::int64ToDecimal32(
                                                           long long int value)
{
    DecimalImpUtil_Platform::ValueType32 retval;
    retval.d_raw = __bid32_from_int64(value);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType64 DecimalImpUtil_Platform::int64ToDecimal64(
                                                           long long int value)
{
    DecimalImpUtil_Platform::ValueType64 retval;
    retval.d_raw = __bid64_from_int64(value);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType128 DecimalImpUtil_Platform::int64ToDecimal128(
                                                           long long int value)
{
    DecimalImpUtil_Platform::ValueType128 retval;
    retval.d_raw = __bid128_from_int64(value);
    return retval;
}


inline
DecimalImpUtil_Platform::ValueType32 DecimalImpUtil_Platform::uint64ToDecimal32(
                                                  unsigned long long int value)
{
    DecimalImpUtil_Platform::ValueType32 retval;
    retval.d_raw = __bid32_from_uint64(value);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType64 DecimalImpUtil_Platform::uint64ToDecimal64(
                                                  unsigned long long int value)
{
    DecimalImpUtil_Platform::ValueType64 retval;
    retval.d_raw = __bid64_from_uint64(value);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType128 DecimalImpUtil_Platform::uint64ToDecimal128(
                                                   unsigned long long int value)
{
    DecimalImpUtil_Platform::ValueType128 retval;
    retval.d_raw = __bid128_from_uint64(value);
    return retval;
}

                        // Arithmetic

inline DecimalImpUtil_Platform::ValueType64  DecimalImpUtil_Platform::add(
                                               DecimalImpUtil_Platform::ValueType64 lhs,
                                               DecimalImpUtil_Platform::ValueType64 rhs)
{
    DecimalImpUtil_Platform::ValueType64 retval;
    retval.d_raw = __bid64_add(lhs.d_raw, rhs.d_raw);
    return retval;
}

inline DecimalImpUtil_Platform::ValueType128  DecimalImpUtil_Platform::add(
                                              DecimalImpUtil_Platform::ValueType128 lhs,
                                              DecimalImpUtil_Platform::ValueType128 rhs)
{
    DecimalImpUtil_Platform::ValueType128 retval;
    retval.d_raw = __bid128_add(lhs.d_raw, rhs.d_raw);
    return retval;
}



inline DecimalImpUtil_Platform::ValueType64  DecimalImpUtil_Platform::sub(
                                               DecimalImpUtil_Platform::ValueType64 lhs,
                                               DecimalImpUtil_Platform::ValueType64 rhs)
{
    DecimalImpUtil_Platform::ValueType64 retval;
    retval.d_raw = __bid64_sub(lhs.d_raw, rhs.d_raw);
    return retval;
}

inline DecimalImpUtil_Platform::ValueType128  DecimalImpUtil_Platform::sub(
                                              DecimalImpUtil_Platform::ValueType128 lhs,
                                              DecimalImpUtil_Platform::ValueType128 rhs)
{
    DecimalImpUtil_Platform::ValueType128 retval;
    retval.d_raw = __bid128_sub(lhs.d_raw, rhs.d_raw);
    return retval;
}



inline DecimalImpUtil_Platform::ValueType64  DecimalImpUtil_Platform::mul(
                                               DecimalImpUtil_Platform::ValueType64 lhs,
                                               DecimalImpUtil_Platform::ValueType64 rhs)
{
    DecimalImpUtil_Platform::ValueType64 retval;
    retval.d_raw = __bid64_mul(lhs.d_raw, rhs.d_raw);
    return retval;
}

inline DecimalImpUtil_Platform::ValueType128  DecimalImpUtil_Platform::mul(
                                              DecimalImpUtil_Platform::ValueType128 lhs,
                                              DecimalImpUtil_Platform::ValueType128 rhs)
{
    DecimalImpUtil_Platform::ValueType128 retval;
    retval.d_raw = __bid128_mul(lhs.d_raw, rhs.d_raw);
    return retval;
}



inline DecimalImpUtil_Platform::ValueType64  DecimalImpUtil_Platform::div(
                                               DecimalImpUtil_Platform::ValueType64 lhs,
                                               DecimalImpUtil_Platform::ValueType64 rhs)
{
    DecimalImpUtil_Platform::ValueType64 retval;
    retval.d_raw = __bid64_div(lhs.d_raw, rhs.d_raw);
    return retval;
}

inline DecimalImpUtil_Platform::ValueType128  DecimalImpUtil_Platform::div(
                                             DecimalImpUtil_Platform::ValueType128  lhs,
                                             DecimalImpUtil_Platform::ValueType128  rhs)
{
    DecimalImpUtil_Platform::ValueType128 retval;
    retval.d_raw = __bid128_div(lhs.d_raw, rhs.d_raw);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType32 DecimalImpUtil_Platform::neg(
                                    DecimalImpUtil_Platform::ValueType32 value)
{
    DecimalImpUtil_Platform::ValueType32 retval;
    retval.d_raw = __bid32_negate(value.d_raw);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType64 DecimalImpUtil_Platform::neg(
                                    DecimalImpUtil_Platform::ValueType64 value)
{
    DecimalImpUtil_Platform::ValueType64 retval;
    retval.d_raw = __bid64_negate(value.d_raw);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType128 DecimalImpUtil_Platform::neg(
                                   DecimalImpUtil_Platform::ValueType128 value)
{
    DecimalImpUtil_Platform::ValueType128 retval;
    retval.d_raw = __bid128_negate(value.d_raw);
    return retval;
}

inline
bool DecimalImpUtil_Platform::less(DecimalImpUtil_Platform::ValueType32 lhs,
                                   DecimalImpUtil_Platform::ValueType32 rhs)
{
    return __bid32_quiet_less(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::less(DecimalImpUtil_Platform::ValueType64 lhs,
                                   DecimalImpUtil_Platform::ValueType64 rhs)
{
    return __bid64_quiet_less(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::less(DecimalImpUtil_Platform::ValueType128 lhs,
                                   DecimalImpUtil_Platform::ValueType128 rhs)
{
    return __bid128_quiet_less(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::greater(DecimalImpUtil_Platform::ValueType32 lhs,
                                      DecimalImpUtil_Platform::ValueType32 rhs)
{
    return __bid32_quiet_greater(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::greater(DecimalImpUtil_Platform::ValueType64 lhs,
                                      DecimalImpUtil_Platform::ValueType64 rhs)
{
    return __bid64_quiet_greater(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::greater(
                                     DecimalImpUtil_Platform::ValueType128 lhs,
                                     DecimalImpUtil_Platform::ValueType128 rhs)
{
    return __bid128_quiet_greater(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::lessEqual(
                                      DecimalImpUtil_Platform::ValueType32 lhs,
                                      DecimalImpUtil_Platform::ValueType32 rhs)
{
    return __bid32_quiet_less_equal(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::lessEqual(
                                      DecimalImpUtil_Platform::ValueType64 lhs,
                                      DecimalImpUtil_Platform::ValueType64 rhs)
{
    return __bid64_quiet_less_equal(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::lessEqual(
                                     DecimalImpUtil_Platform::ValueType128 lhs,
                                     DecimalImpUtil_Platform::ValueType128 rhs)
{
    return __bid128_quiet_less_equal(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::greaterEqual(
                                      DecimalImpUtil_Platform::ValueType32 lhs,
                                      DecimalImpUtil_Platform::ValueType32 rhs)
{
    return __bid32_quiet_greater_equal(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::greaterEqual(
                                      DecimalImpUtil_Platform::ValueType64 lhs,
                                      DecimalImpUtil_Platform::ValueType64 rhs)
{
    return __bid64_quiet_greater_equal(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::greaterEqual(
                                     DecimalImpUtil_Platform::ValueType128 lhs,
                                     DecimalImpUtil_Platform::ValueType128 rhs)
{
    return __bid128_quiet_greater_equal(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::equal(DecimalImpUtil_Platform::ValueType32 lhs,
                                    DecimalImpUtil_Platform::ValueType32 rhs)
{
    return __bid32_quiet_equal(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::equal(DecimalImpUtil_Platform::ValueType64 lhs,
                                    DecimalImpUtil_Platform::ValueType64 rhs)
{
    return __bid64_quiet_equal(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::equal(DecimalImpUtil_Platform::ValueType128 lhs,
                                    DecimalImpUtil_Platform::ValueType128 rhs)
{
    return __bid128_quiet_equal(lhs.d_raw, rhs.d_raw);
}


inline
bool DecimalImpUtil_Platform::notEqual(
                                      DecimalImpUtil_Platform::ValueType32 lhs,
                                      DecimalImpUtil_Platform::ValueType32 rhs)
{
    return __bid32_quiet_not_equal(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::notEqual(
                                      DecimalImpUtil_Platform::ValueType64 lhs,
                                      DecimalImpUtil_Platform::ValueType64 rhs)
{
    return __bid64_quiet_not_equal(lhs.d_raw, rhs.d_raw);
}

inline
bool DecimalImpUtil_Platform::notEqual(
                                     DecimalImpUtil_Platform::ValueType128 lhs,
                                     DecimalImpUtil_Platform::ValueType128 rhs)
{
    return __bid128_quiet_not_equal(lhs.d_raw, rhs.d_raw);
}


inline
DecimalImpUtil_Platform::ValueType32 DecimalImpUtil_Platform::convertToDecimal32(
                                      const DecimalImpUtil_Platform::ValueType64& input)
{
    DecimalImpUtil_Platform::ValueType32 retval;
    retval.d_raw = __bid64_to_bid32(input.d_raw);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType64
DecimalImpUtil_Platform::convertToDecimal64(
                             const DecimalImpUtil_Platform::ValueType32& input)
{
    DecimalImpUtil_Platform::ValueType64 retval;
    retval.d_raw = __bid32_to_bid64(input.d_raw);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType64
DecimalImpUtil_Platform::convertToDecimal64(
                            const DecimalImpUtil_Platform::ValueType128& input)
{
    DecimalImpUtil_Platform::ValueType64 retval;
    retval.d_raw = __bid128_to_bid64(input.d_raw);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType128
DecimalImpUtil_Platform::convertToDecimal128(
                             const DecimalImpUtil_Platform::ValueType32& input)
{
    DecimalImpUtil_Platform::ValueType128 retval;
    retval.d_raw = __bid32_to_bid128(input.d_raw);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType128
DecimalImpUtil_Platform::convertToDecimal128(
                             const DecimalImpUtil_Platform::ValueType64& input)
{
    DecimalImpUtil_Platform::ValueType128 retval;
    retval.d_raw = __bid64_to_bid128(input.d_raw);
    return retval;
}

inline
DecimalImpUtil_Platform::ValueType32
DecimalImpUtil_Platform::binaryToDecimal32(float input)
{
    ValueType32 result;
    result.d_raw = __binary32_to_bid32(input);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType32
DecimalImpUtil_Platform::binaryToDecimal32(double input)
{
    ValueType32 result;
    result.d_raw = __binary64_to_bid32(input);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType32
DecimalImpUtil_Platform::binaryToDecimal32(long double input)
{
    ValueType32 result;
    result.d_raw = __binary80_to_bid32(input);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType64
DecimalImpUtil_Platform::binaryToDecimal64(float input)
{
    ValueType64 result;
    result.d_raw = __binary32_to_bid64(input);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType64
DecimalImpUtil_Platform::binaryToDecimal64(double input)
{
    ValueType64 result;
    result.d_raw = __binary64_to_bid64(input);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType64
DecimalImpUtil_Platform::binaryToDecimal64(long double input)
{
    ValueType64 result;
    result.d_raw = __binary80_to_bid64(input);
    return result;
}


inline
DecimalImpUtil_Platform::ValueType128
DecimalImpUtil_Platform::binaryToDecimal128(float input)
{
    ValueType128 result;
    result.d_raw = __binary32_to_bid128(input);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType128
DecimalImpUtil_Platform::binaryToDecimal128(double input)
{
    ValueType128 result;
    result.d_raw = __binary80_to_bid128(input);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType128
DecimalImpUtil_Platform::binaryToDecimal128(long double input)
{
    ValueType128 result;
    result.d_raw = __binary80_to_bid128(input);
    return result;
}


inline
DecimalImpUtil_Platform::ValueType32
DecimalImpUtil_Platform::makeDecimalRaw32(int mantissa,
                                          int exponent)
{
    DecimalImpUtil_Platform::ValueType32 result;
    result = DecimalImpUtil_Platform::int32ToDecimal32(mantissa);
    result = DecimalImpUtil_Platform::scaleB(result, exponent);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType64
DecimalImpUtil_Platform::makeDecimalRaw64(unsigned long long mantissa,
                                          int                exponent)
{
    DecimalImpUtil_Platform::ValueType64 result;
    result = DecimalImpUtil_Platform::uint64ToDecimal64(mantissa);
    result = DecimalImpUtil_Platform::scaleB(result, exponent);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType64
DecimalImpUtil_Platform::makeDecimalRaw64(long long mantissa,
                                          int       exponent)
{
    DecimalImpUtil_Platform::ValueType64 result;
    result = DecimalImpUtil_Platform::int64ToDecimal64(mantissa);
    result = DecimalImpUtil_Platform::scaleB(result, exponent);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType64
DecimalImpUtil_Platform::makeDecimalRaw64(unsigned int mantissa,
                                          int          exponent)
{
    DecimalImpUtil_Platform::ValueType64 result;
    result = DecimalImpUtil_Platform::uint32ToDecimal64(mantissa);
    result = DecimalImpUtil_Platform::scaleB(result, exponent);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType64 DecimalImpUtil_Platform::makeDecimalRaw64(
                                                                  int mantissa,
                                                                  int exponent)
{
    DecimalImpUtil_Platform::ValueType64 result;
    result = DecimalImpUtil_Platform::int32ToDecimal64(mantissa);
    result = DecimalImpUtil_Platform::scaleB(result, exponent);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType128
DecimalImpUtil_Platform::makeDecimalRaw128(unsigned long long mantissa,
                                           int                exponent)
{
    DecimalImpUtil_Platform::ValueType128 result;
    result = DecimalImpUtil_Platform::uint64ToDecimal128(mantissa);
    result = DecimalImpUtil_Platform::scaleB(result, exponent);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType128
DecimalImpUtil_Platform::makeDecimalRaw128(long long mantissa,
                                           int       exponent)
{
    DecimalImpUtil_Platform::ValueType128 result;
    result = DecimalImpUtil_Platform::int64ToDecimal128(mantissa);
    result = DecimalImpUtil_Platform::scaleB(result, exponent);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType128
DecimalImpUtil_Platform::makeDecimalRaw128(unsigned int mantissa,
                                           int          exponent)
{
    DecimalImpUtil_Platform::ValueType128 result;
    result = DecimalImpUtil_Platform::uint32ToDecimal128(mantissa);
    result = DecimalImpUtil_Platform::scaleB(result, exponent);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType128
DecimalImpUtil_Platform::makeDecimalRaw128(int mantissa,
                                           int exponent)
{
    DecimalImpUtil_Platform::ValueType128 result;
    result = DecimalImpUtil_Platform::uint32ToDecimal128(mantissa);
    result = DecimalImpUtil_Platform::scaleB(result, exponent);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType32 DecimalImpUtil_Platform::scaleB(
                                    DecimalImpUtil_Platform::ValueType32 value,
                                    int                                  power)
{
    DecimalImpUtil_Platform::ValueType32 result;
    result.d_raw = __bid32_scalbn(value.d_raw, power);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType64 DecimalImpUtil_Platform::scaleB(
                                    DecimalImpUtil_Platform::ValueType64 value,
                                    int                                  power)
{
    DecimalImpUtil_Platform::ValueType64 result;
    result.d_raw = __bid64_scalbn(value.d_raw, power);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType128 DecimalImpUtil_Platform::scaleB(
                                   DecimalImpUtil_Platform::ValueType128 value,
                                   int                                   power)
{
    DecimalImpUtil_Platform::ValueType128 result;
    result.d_raw = __bid128_scalbn(value.d_raw, power);
    return result;
}

inline
DecimalImpUtil_Platform::ValueType32 DecimalImpUtil_Platform::parse32(const char *str)
{
    DecimalImpUtil_Platform::ValueType32 result;
    // NOTE: It is probably safe to convert from a 'const char *' to a 'char *'
    // because the __bid* interfaces are C interfaces.
    result.d_raw = __bid32_from_string(const_cast<char *>(str));
    return result;
}

inline
DecimalImpUtil_Platform::ValueType64 DecimalImpUtil_Platform::parse64(const char *str)
{
    DecimalImpUtil_Platform::ValueType64 result;
    // NOTE: It is probably safe to convert from a 'const char *' to a 'char *'
    // because the __bid* interfaces are C interfaces.
    result.d_raw = __bid64_from_string(const_cast<char *>(str));
    return result;
}

inline
DecimalImpUtil_Platform::ValueType128 DecimalImpUtil_Platform::parse128(const char *str)
{
    DecimalImpUtil_Platform::ValueType128 result;
    // NOTE: It is probably safe to convert from a 'const char *' to a 'char *'
    // because the __bid* interfaces are C interfaces.
    result.d_raw = __bid128_from_string(const_cast<char *>(str));
    return result;
}


}  // close package namespace
}  // close enterprise namespace

#endif

#endif

// ----------------------------------------------------------------------------
// Copyright (C) 2014 Bloomberg L.P.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------- END-OF-FILE ----------------------------------

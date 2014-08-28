#!/bin/sh

echo "Linking library contents..."
./wrap.sh LIBRARY/src/bid64_acos.c             library_src_bid64_acos.c
./wrap.sh LIBRARY/src/bid64_acosh.c            library_src_bid64_acosh.c
./wrap.sh LIBRARY/src/bid64_asin.c             library_src_bid64_asin.c
./wrap.sh LIBRARY/src/bid64_asinh.c            library_src_bid64_asinh.c
./wrap.sh LIBRARY/src/bid64_atan.c             library_src_bid64_atan.c
./wrap.sh LIBRARY/src/bid64_atan2.c            library_src_bid64_atan2.c
./wrap.sh LIBRARY/src/bid64_atanh.c            library_src_bid64_atanh.c
./wrap.sh LIBRARY/src/bid64_cbrt.c             library_src_bid64_cbrt.c
./wrap.sh LIBRARY/src/bid64_cos.c              library_src_bid64_cos.c
./wrap.sh LIBRARY/src/bid64_cosh.c             library_src_bid64_cosh.c
./wrap.sh LIBRARY/src/bid64_erf.c              library_src_bid64_erf.c
./wrap.sh LIBRARY/src/bid64_erfc.c             library_src_bid64_erfc.c
./wrap.sh LIBRARY/src/bid64_exp.c              library_src_bid64_exp.c
./wrap.sh LIBRARY/src/bid64_exp10.c            library_src_bid64_exp10.c
./wrap.sh LIBRARY/src/bid64_exp2.c             library_src_bid64_exp2.c
./wrap.sh LIBRARY/src/bid64_expm1.c            library_src_bid64_expm1.c
./wrap.sh LIBRARY/src/bid64_hypot.c            library_src_bid64_hypot.c
./wrap.sh LIBRARY/src/bid64_lgamma.c           library_src_bid64_lgamma.c
./wrap.sh LIBRARY/src/bid64_log.c              library_src_bid64_log.c
./wrap.sh LIBRARY/src/bid64_log10.c            library_src_bid64_log10.c
./wrap.sh LIBRARY/src/bid64_log1p.c            library_src_bid64_log1p.c
./wrap.sh LIBRARY/src/bid64_log2.c             library_src_bid64_log2.c
./wrap.sh LIBRARY/src/bid64_pow.c              library_src_bid64_pow.c
./wrap.sh LIBRARY/src/bid64_sin.c              library_src_bid64_sin.c
./wrap.sh LIBRARY/src/bid64_sinh.c             library_src_bid64_sinh.c
./wrap.sh LIBRARY/src/bid64_tan.c              library_src_bid64_tan.c
./wrap.sh LIBRARY/src/bid64_tanh.c             library_src_bid64_tanh.c
./wrap.sh LIBRARY/src/bid64_tgamma.c           library_src_bid64_tgamma.c
./wrap.sh LIBRARY/src/bid128_acos.c            library_src_bid128_acos.c
./wrap.sh LIBRARY/src/bid128_acosh.c           library_src_bid128_acosh.c
./wrap.sh LIBRARY/src/bid128_asin.c            library_src_bid128_asin.c
./wrap.sh LIBRARY/src/bid128_asinh.c           library_src_bid128_asinh.c
./wrap.sh LIBRARY/src/bid128_atan.c            library_src_bid128_atan.c
./wrap.sh LIBRARY/src/bid128_atan2.c           library_src_bid128_atan2.c
./wrap.sh LIBRARY/src/bid128_atanh.c           library_src_bid128_atanh.c
./wrap.sh LIBRARY/src/bid128_cbrt.c            library_src_bid128_cbrt.c
./wrap.sh LIBRARY/src/bid128_cos.c             library_src_bid128_cos.c
./wrap.sh LIBRARY/src/bid128_cosh.c            library_src_bid128_cosh.c
./wrap.sh LIBRARY/src/bid128_erf.c             library_src_bid128_erf.c
./wrap.sh LIBRARY/src/bid128_erfc.c            library_src_bid128_erfc.c
./wrap.sh LIBRARY/src/bid128_exp.c             library_src_bid128_exp.c
./wrap.sh LIBRARY/src/bid128_exp10.c           library_src_bid128_exp10.c
./wrap.sh LIBRARY/src/bid128_exp2.c            library_src_bid128_exp2.c
./wrap.sh LIBRARY/src/bid128_expm1.c           library_src_bid128_expm1.c
./wrap.sh LIBRARY/src/bid128_hypot.c           library_src_bid128_hypot.c
./wrap.sh LIBRARY/src/bid128_lgamma.c          library_src_bid128_lgamma.c
./wrap.sh LIBRARY/src/bid128_log.c             library_src_bid128_log.c
./wrap.sh LIBRARY/src/bid128_log10.c           library_src_bid128_log10.c
./wrap.sh LIBRARY/src/bid128_log1p.c           library_src_bid128_log1p.c
./wrap.sh LIBRARY/src/bid128_log2.c            library_src_bid128_log2.c
./wrap.sh LIBRARY/src/bid128_pow.c             library_src_bid128_pow.c
./wrap.sh LIBRARY/src/bid128_sin.c             library_src_bid128_sin.c
./wrap.sh LIBRARY/src/bid128_sinh.c            library_src_bid128_sinh.c
./wrap.sh LIBRARY/src/bid128_tan.c             library_src_bid128_tan.c
./wrap.sh LIBRARY/src/bid128_tanh.c            library_src_bid128_tanh.c
./wrap.sh LIBRARY/src/bid128_tgamma.c          library_src_bid128_tgamma.c
./wrap.sh LIBRARY/src/bid32_add.c              library_src_bid32_add.c
./wrap.sh LIBRARY/src/bid32_compare.c          library_src_bid32_compare.c
./wrap.sh LIBRARY/src/bid32_div.c              library_src_bid32_div.c
./wrap.sh LIBRARY/src/bid32_fdimd.c            library_src_bid32_fdimd.c
./wrap.sh LIBRARY/src/bid32_fma.c              library_src_bid32_fma.c
./wrap.sh LIBRARY/src/bid32_fmod.c             library_src_bid32_fmod.c
./wrap.sh LIBRARY/src/bid32_frexp.c            library_src_bid32_frexp.c
./wrap.sh LIBRARY/src/bid32_ldexp.c            library_src_bid32_ldexp.c
./wrap.sh LIBRARY/src/bid32_llrintd.c          library_src_bid32_llrintd.c
./wrap.sh LIBRARY/src/bid32_logb.c             library_src_bid32_logb.c
./wrap.sh LIBRARY/src/bid32_logbd.c            library_src_bid32_logbd.c
./wrap.sh LIBRARY/src/bid32_lrintd.c           library_src_bid32_lrintd.c
./wrap.sh LIBRARY/src/bid32_lround.c           library_src_bid32_lround.c
./wrap.sh LIBRARY/src/bid32_minmax.c           library_src_bid32_minmax.c
./wrap.sh LIBRARY/src/bid32_modf.c             library_src_bid32_modf.c
./wrap.sh LIBRARY/src/bid32_mul.c              library_src_bid32_mul.c
./wrap.sh LIBRARY/src/bid32_nearbyintd.c       library_src_bid32_nearbyintd.c
./wrap.sh LIBRARY/src/bid32_next.c             library_src_bid32_next.c
./wrap.sh LIBRARY/src/bid32_nexttowardd.c      library_src_bid32_nexttowardd.c
./wrap.sh LIBRARY/src/bid32_noncomp.c          library_src_bid32_noncomp.c
./wrap.sh LIBRARY/src/bid32_quantexpd.c        library_src_bid32_quantexpd.c
./wrap.sh LIBRARY/src/bid32_quantize.c         library_src_bid32_quantize.c
./wrap.sh LIBRARY/src/bid32_rem.c              library_src_bid32_rem.c
./wrap.sh LIBRARY/src/bid32_round_integral.c   library_src_bid32_round_integral.c
./wrap.sh LIBRARY/src/bid32_scalb.c            library_src_bid32_scalb.c
./wrap.sh LIBRARY/src/bid32_scalbl.c           library_src_bid32_scalbl.c
./wrap.sh LIBRARY/src/bid32_sqrt.c             library_src_bid32_sqrt.c
./wrap.sh LIBRARY/src/bid32_string.c           library_src_bid32_string.c
./wrap.sh LIBRARY/src/bid32_to_int16.c         library_src_bid32_to_int16.c
./wrap.sh LIBRARY/src/bid32_to_int32.c         library_src_bid32_to_int32.c
./wrap.sh LIBRARY/src/bid32_to_int64.c         library_src_bid32_to_int64.c
./wrap.sh LIBRARY/src/bid32_to_int8.c          library_src_bid32_to_int8.c
./wrap.sh LIBRARY/src/bid32_to_uint16.c        library_src_bid32_to_uint16.c
./wrap.sh LIBRARY/src/bid32_to_uint32.c        library_src_bid32_to_uint32.c
./wrap.sh LIBRARY/src/bid32_to_uint64.c        library_src_bid32_to_uint64.c
./wrap.sh LIBRARY/src/bid32_to_uint8.c         library_src_bid32_to_uint8.c
./wrap.sh LIBRARY/src/bid64_add.c              library_src_bid64_add.c
./wrap.sh LIBRARY/src/bid64_compare.c          library_src_bid64_compare.c
./wrap.sh LIBRARY/src/bid64_div.c              library_src_bid64_div.c
./wrap.sh LIBRARY/src/bid64_fdimd.c            library_src_bid64_fdimd.c
./wrap.sh LIBRARY/src/bid64_fma.c              library_src_bid64_fma.c
./wrap.sh LIBRARY/src/bid64_fmod.c             library_src_bid64_fmod.c
./wrap.sh LIBRARY/src/bid64_frexp.c            library_src_bid64_frexp.c
./wrap.sh LIBRARY/src/bid64_ldexp.c            library_src_bid64_ldexp.c
./wrap.sh LIBRARY/src/bid64_llrintd.c          library_src_bid64_llrintd.c
./wrap.sh LIBRARY/src/bid64_logb.c             library_src_bid64_logb.c
./wrap.sh LIBRARY/src/bid64_logbd.c            library_src_bid64_logbd.c
./wrap.sh LIBRARY/src/bid64_lrintd.c           library_src_bid64_lrintd.c
./wrap.sh LIBRARY/src/bid64_lround.c           library_src_bid64_lround.c
./wrap.sh LIBRARY/src/bid64_minmax.c           library_src_bid64_minmax.c
./wrap.sh LIBRARY/src/bid64_modf.c             library_src_bid64_modf.c
./wrap.sh LIBRARY/src/bid64_mul.c              library_src_bid64_mul.c
./wrap.sh LIBRARY/src/bid64_nearbyintd.c       library_src_bid64_nearbyintd.c
./wrap.sh LIBRARY/src/bid64_next.c             library_src_bid64_next.c
./wrap.sh LIBRARY/src/bid64_nexttowardd.c      library_src_bid64_nexttowardd.c
./wrap.sh LIBRARY/src/bid64_noncomp.c          library_src_bid64_noncomp.c
./wrap.sh LIBRARY/src/bid64_quantexpd.c        library_src_bid64_quantexpd.c
./wrap.sh LIBRARY/src/bid64_quantize.c         library_src_bid64_quantize.c
./wrap.sh LIBRARY/src/bid64_rem.c              library_src_bid64_rem.c
./wrap.sh LIBRARY/src/bid64_round_integral.c   library_src_bid64_round_integral.c
./wrap.sh LIBRARY/src/bid64_scalb.c            library_src_bid64_scalb.c
./wrap.sh LIBRARY/src/bid64_scalbl.c           library_src_bid64_scalbl.c
./wrap.sh LIBRARY/src/bid64_sqrt.c             library_src_bid64_sqrt.c
./wrap.sh LIBRARY/src/bid64_string.c           library_src_bid64_string.c
./wrap.sh LIBRARY/src/bid64_to_int16.c         library_src_bid64_to_int16.c
./wrap.sh LIBRARY/src/bid64_to_int32.c         library_src_bid64_to_int32.c
./wrap.sh LIBRARY/src/bid64_to_int64.c         library_src_bid64_to_int64.c
./wrap.sh LIBRARY/src/bid64_to_int8.c          library_src_bid64_to_int8.c
./wrap.sh LIBRARY/src/bid64_to_uint16.c        library_src_bid64_to_uint16.c
./wrap.sh LIBRARY/src/bid64_to_uint32.c        library_src_bid64_to_uint32.c
./wrap.sh LIBRARY/src/bid64_to_uint64.c        library_src_bid64_to_uint64.c
./wrap.sh LIBRARY/src/bid64_to_uint8.c         library_src_bid64_to_uint8.c
./wrap.sh LIBRARY/src/bid128_add.c             library_src_bid128_add.c
./wrap.sh LIBRARY/src/bid128_compare.c         library_src_bid128_compare.c
./wrap.sh LIBRARY/src/bid128_div.c             library_src_bid128_div.c
./wrap.sh LIBRARY/src/bid128_fdimd.c           library_src_bid128_fdimd.c
./wrap.sh LIBRARY/src/bid128_fma.c             library_src_bid128_fma.c
./wrap.sh LIBRARY/src/bid128_fmod.c            library_src_bid128_fmod.c
./wrap.sh LIBRARY/src/bid128_frexp.c           library_src_bid128_frexp.c
./wrap.sh LIBRARY/src/bid128_ldexp.c           library_src_bid128_ldexp.c
./wrap.sh LIBRARY/src/bid128_llrintd.c         library_src_bid128_llrintd.c
./wrap.sh LIBRARY/src/bid128_logb.c            library_src_bid128_logb.c
./wrap.sh LIBRARY/src/bid128_logbd.c           library_src_bid128_logbd.c
./wrap.sh LIBRARY/src/bid128_lrintd.c          library_src_bid128_lrintd.c
./wrap.sh LIBRARY/src/bid128_lround.c          library_src_bid128_lround.c
./wrap.sh LIBRARY/src/bid128_minmax.c          library_src_bid128_minmax.c
./wrap.sh LIBRARY/src/bid128_modf.c            library_src_bid128_modf.c
./wrap.sh LIBRARY/src/bid128_mul.c             library_src_bid128_mul.c
./wrap.sh LIBRARY/src/bid128_nearbyintd.c      library_src_bid128_nearbyintd.c
./wrap.sh LIBRARY/src/bid128_next.c            library_src_bid128_next.c
./wrap.sh LIBRARY/src/bid128_nexttowardd.c     library_src_bid128_nexttowardd.c
./wrap.sh LIBRARY/src/bid128_noncomp.c         library_src_bid128_noncomp.c
./wrap.sh LIBRARY/src/bid128_quantexpd.c       library_src_bid128_quantexpd.c
./wrap.sh LIBRARY/src/bid128_quantize.c        library_src_bid128_quantize.c
./wrap.sh LIBRARY/src/bid128_rem.c             library_src_bid128_rem.c
./wrap.sh LIBRARY/src/bid128_round_integral.c  library_src_bid128_round_integral.c
./wrap.sh LIBRARY/src/bid128_scalb.c           library_src_bid128_scalb.c
./wrap.sh LIBRARY/src/bid128_scalbl.c          library_src_bid128_scalbl.c
./wrap.sh LIBRARY/src/bid128_sqrt.c            library_src_bid128_sqrt.c
./wrap.sh LIBRARY/src/bid128_string.c          library_src_bid128_string.c
./wrap.sh LIBRARY/src/bid128_to_int16.c        library_src_bid128_to_int16.c
./wrap.sh LIBRARY/src/bid128_to_int32.c        library_src_bid128_to_int32.c
./wrap.sh LIBRARY/src/bid128_to_int64.c        library_src_bid128_to_int64.c
./wrap.sh LIBRARY/src/bid128_to_int8.c         library_src_bid128_to_int8.c
./wrap.sh LIBRARY/src/bid128_to_uint16.c       library_src_bid128_to_uint16.c
./wrap.sh LIBRARY/src/bid128_to_uint32.c       library_src_bid128_to_uint32.c
./wrap.sh LIBRARY/src/bid128_to_uint64.c       library_src_bid128_to_uint64.c
./wrap.sh LIBRARY/src/bid128_to_uint8.c        library_src_bid128_to_uint8.c
./wrap.sh LIBRARY/src/strtod32.c               library_src_strtod32.c
./wrap.sh LIBRARY/src/strtod64.c               library_src_strtod64.c
./wrap.sh LIBRARY/src/strtod128.c              library_src_strtod128.c
./wrap.sh LIBRARY/src/wcstod32.c               library_src_wcstod32.c
./wrap.sh LIBRARY/src/wcstod64.c               library_src_wcstod64.c
./wrap.sh LIBRARY/src/wcstod128.c              library_src_wcstod128.c
./wrap.sh LIBRARY/src/bid32_acos.c             library_src_bid32_acos.c
./wrap.sh LIBRARY/src/bid32_acosh.c            library_src_bid32_acosh.c
./wrap.sh LIBRARY/src/bid32_asin.c             library_src_bid32_asin.c
./wrap.sh LIBRARY/src/bid32_asinh.c            library_src_bid32_asinh.c
./wrap.sh LIBRARY/src/bid32_atan.c             library_src_bid32_atan.c
./wrap.sh LIBRARY/src/bid32_atan2.c            library_src_bid32_atan2.c
./wrap.sh LIBRARY/src/bid32_atanh.c            library_src_bid32_atanh.c
./wrap.sh LIBRARY/src/bid32_cbrt.c             library_src_bid32_cbrt.c
./wrap.sh LIBRARY/src/bid32_cos.c              library_src_bid32_cos.c
./wrap.sh LIBRARY/src/bid32_cosh.c             library_src_bid32_cosh.c
./wrap.sh LIBRARY/src/bid32_erf.c              library_src_bid32_erf.c
./wrap.sh LIBRARY/src/bid32_erfc.c             library_src_bid32_erfc.c
./wrap.sh LIBRARY/src/bid32_exp.c              library_src_bid32_exp.c
./wrap.sh LIBRARY/src/bid32_exp10.c            library_src_bid32_exp10.c
./wrap.sh LIBRARY/src/bid32_exp2.c             library_src_bid32_exp2.c
./wrap.sh LIBRARY/src/bid32_expm1.c            library_src_bid32_expm1.c
./wrap.sh LIBRARY/src/bid32_hypot.c            library_src_bid32_hypot.c
./wrap.sh LIBRARY/src/bid32_lgamma.c           library_src_bid32_lgamma.c
./wrap.sh LIBRARY/src/bid32_log.c              library_src_bid32_log.c
./wrap.sh LIBRARY/src/bid32_log10.c            library_src_bid32_log10.c
./wrap.sh LIBRARY/src/bid32_log1p.c            library_src_bid32_log1p.c
./wrap.sh LIBRARY/src/bid32_log2.c             library_src_bid32_log2.c
./wrap.sh LIBRARY/src/bid32_pow.c              library_src_bid32_pow.c
./wrap.sh LIBRARY/src/bid32_sin.c              library_src_bid32_sin.c
./wrap.sh LIBRARY/src/bid32_sinh.c             library_src_bid32_sinh.c
./wrap.sh LIBRARY/src/bid32_tan.c              library_src_bid32_tan.c
./wrap.sh LIBRARY/src/bid32_tanh.c             library_src_bid32_tanh.c
./wrap.sh LIBRARY/src/bid32_tgamma.c           library_src_bid32_tgamma.c
./wrap.sh LIBRARY/src/bid32_sub.c              library_src_bid32_sub.c
./wrap.sh LIBRARY/src/bid32_to_bid128.c        library_src_bid32_to_bid128.c
./wrap.sh LIBRARY/src/bid32_to_bid64.c         library_src_bid32_to_bid64.c
./wrap.sh LIBRARY/src/bid64_to_bid128.c        library_src_bid64_to_bid128.c
./wrap.sh LIBRARY/src/bid128_2_str_tables.c    library_src_bid128_2_str_tables.c
./wrap.sh LIBRARY/src/bid_binarydecimal.c      library_src_bid_binarydecimal.c
./wrap.sh LIBRARY/src/bid_convert_data.c       library_src_bid_convert_data.c
./wrap.sh LIBRARY/src/bid_decimal_data.c       library_src_bid_decimal_data.c
./wrap.sh LIBRARY/src/bid_decimal_globals.c    library_src_bid_decimal_globals.c
./wrap.sh LIBRARY/src/bid_dpd.c                library_src_bid_dpd.c
./wrap.sh LIBRARY/src/bid_feclearexcept.c      library_src_bid_feclearexcept.c
./wrap.sh LIBRARY/src/bid_fegetexceptflag.c    library_src_bid_fegetexceptflag.c
./wrap.sh LIBRARY/src/bid_feraiseexcept.c      library_src_bid_feraiseexcept.c
./wrap.sh LIBRARY/src/bid_fesetexceptflag.c    library_src_bid_fesetexceptflag.c
./wrap.sh LIBRARY/src/bid_fetestexcept.c       library_src_bid_fetestexcept.c
./wrap.sh LIBRARY/src/bid_flag_operations.c    library_src_bid_flag_operations.c
./wrap.sh LIBRARY/src/bid_from_int.c           library_src_bid_from_int.c
./wrap.sh LIBRARY/src/bid_round.c              library_src_bid_round.c
./wrap.sh LIBRARY/src/bid128.c                 library_src_bid128.c

echo "Linking float128 contents..."
./wrap.sh LIBRARY/float128/dpml_ux_bid.c       library_float128_dpml_ux_bid.c
./wrap.sh LIBRARY/float128/dpml_ux_bessel.c    library_float128_dpml_ux_bessel.c
./wrap.sh LIBRARY/float128/dpml_ux_cbrt.c      library_float128_dpml_ux_cbrt.c
./wrap.sh LIBRARY/float128/dpml_ux_erf.c       library_float128_dpml_ux_erf.c
./wrap.sh LIBRARY/float128/dpml_ux_exp.c       library_float128_dpml_ux_exp.c
./wrap.sh LIBRARY/float128/dpml_ux_int.c       library_float128_dpml_ux_int.c
./wrap.sh LIBRARY/float128/dpml_ux_inv_hyper.c library_float128_dpml_ux_inv_hyper.c
./wrap.sh LIBRARY/float128/dpml_ux_inv_trig.c  library_float128_dpml_ux_inf_trig.c
./wrap.sh LIBRARY/float128/dpml_ux_lgamma.c    library_float128_dpml_ux_lgamma.c
./wrap.sh LIBRARY/float128/dpml_ux_log.c       library_float128_dpml_ux_log.c
./wrap.sh LIBRARY/float128/dpml_ux_mod.c       library_float128_dpml_ux_mod.c
./wrap.sh LIBRARY/float128/dpml_ux_powi.c      library_float128_dpml_ux_powi.c
./wrap.sh LIBRARY/float128/dpml_ux_pow.c       library_float128_dpml_ux_pow.c
./wrap.sh LIBRARY/float128/dpml_ux_sqrt.c      library_float128_dpml_ux_sqrt.c
./wrap.sh LIBRARY/float128/dpml_ux_trig.c      library_float128_dpml_ux_trig.c
./wrap.sh LIBRARY/float128/dpml_ux_ops.c       library_float128_dpml_ux_ops.c
./wrap.sh LIBRARY/float128/dpml_ux_ops_64.c    library_float128_dpml_ux_ops_64.c
./wrap.sh LIBRARY/float128/dpml_four_over_pi.c library_float128_dpml_four_over_pi.c
./wrap.sh LIBRARY/float128/dpml_exception.c    library_float128_dpml_exception.c
./wrap.sh LIBRARY/float128/sqrt_tab_t.c        library_float128_sqrt_tab_t.c

echo "Linking headers..."
cp LIBRARY/src/bid_functions.h                 bid_functions.h
cp LIBRARY/src/bid_conf.h                      bid_conf.h
cp LIBRARY/src/bid_internal.h                  bid_internal.h
cp LIBRARY/src/bid_wrap_names.h                bid_wrap_names.h
cp LIBRARY/src/bid_gcc_intrinsics.h            bid_gcc_intrinsics.h

#ifndef ___UTILITY__STANDARD__LIBRARY__CMATH___
#define ___UTILITY__STANDARD__LIBRARY__CMATH___

#include<utility/config/utility_config.hpp>
#include<math.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::signbit;
    using ::fpclassify;
    using ::isfinite;
    using ::isinf;
    using ::isnan;
    using ::isnormal;
    using ::isgreater;
    using ::isgreaterequal;
    using ::isless;
    using ::islessequal;
    using ::islessgreater;
    using ::isunordered;
    using ::isunordered;

    using ::float_t;
    using ::double_t;

#ifndef _AIX
    using ::abs;
#endif

    using ::acos;
    using ::acosf;
    using ::asin;
    using ::asinf;
    using ::atan;
    using ::atanf;
    using ::atan2;
    using ::atan2f;
    using ::ceil;
    using ::ceilf;
    using ::cos;
    using ::cosf;
    using ::cosh;
    using ::coshf;

    using ::exp;
    using ::expf;

    using ::fabs;
    using ::fabsf;
    using ::floor;
    using ::floorf;

    using ::fmod;
    using ::fmodf;

    using ::frexp;
    using ::frexpf;
    using ::ldexp;
    using ::ldexpf;

    using ::log;
    using ::logf;

    using ::log10;
    using ::log10f;
    using ::modf;
    using ::modff;

    using ::pow;
    using ::powf;

    using ::sin;
    using ::sinf;
    using ::sinh;
    using ::sinhf;

    using ::sqrt;
    using ::sqrtf;
    using ::tan;
    using ::tanf;

    using ::tanh;
    using ::tanhf;

    using ::acosh;
    using ::acoshf;
    using ::asinh;
    using ::asinhf;
    using ::atanh;
    using ::atanhf;
    using ::cbrt;
    using ::cbrtf;

    using ::copysign;
    using ::copysignf;

    using ::erf;
    using ::erff;
    using ::erfc;
    using ::erfcf;
    using ::exp2;
    using ::exp2f;
    using ::expm1;
    using ::expm1f;
    using ::fdim;
    using ::fdimf;
    using ::fmaf;
    using ::fma;
    using ::fmax;
    using ::fmaxf;
    using ::fmin;
    using ::fminf;
    using ::hypot;
    using ::hypotf;
    using ::ilogb;
    using ::ilogbf;
    using ::lgamma;
    using ::lgammaf;
    using ::llrint;
    using ::llrintf;
    using ::llround;
    using ::llroundf;
    using ::log1p;
    using ::log1pf;
    using ::log2;
    using ::log2f;
    using ::logb;
    using ::logbf;
    using ::lrint;
    using ::lrintf;
    using ::lround;
    using ::lroundf;

    using ::nan;
    using ::nanf;

    using ::nearbyint;
    using ::nearbyintf;
    using ::nextafter;
    using ::nextafterf;
    using ::nexttoward;
    using ::nexttowardf;
    using ::remainder;
    using ::remainderf;
    using ::remquo;
    using ::remquof;
    using ::rint;
    using ::rintf;
    using ::round;
    using ::roundf;
    using ::scalbln;
    using ::scalblnf;
    using ::scalbn;
    using ::scalbnf;
    using ::tgamma;
    using ::tgammaf;
    using ::trunc;
    using ::truncf;

    using ::acosl;
    using ::asinl;
    using ::atanl;
    using ::atan2l;
    using ::ceill;
    using ::cosl;
    using ::coshl;
    using ::expl;
    using ::fabsl;
    using ::floorl;
    using ::fmodl;
    using ::frexpl;
    using ::ldexpl;
    using ::logl;
    using ::log10l;
    using ::modfl;
    using ::powl;
    using ::sinl;
    using ::sinhl;
    using ::sqrtl;
    using ::tanl;

    using ::tanhl;
    using ::acoshl;
    using ::asinhl;
    using ::atanhl;
    using ::cbrtl;

    using ::copysignl;

    using ::erfl;
    using ::erfcl;
    using ::exp2l;
    using ::expm1l;
    using ::fdiml;
    using ::fmal;
    using ::fmaxl;
    using ::fminl;
    using ::hypotl;
    using ::ilogbl;
    using ::lgammal;
    using ::llrintl;
    using ::llroundl;
    using ::log1pl;
    using ::log2l;
    using ::logbl;
    using ::lrintl;
    using ::lroundl;
    using ::nanl;
    using ::nearbyintl;
    using ::nextafterl;
    using ::nexttowardl;
    using ::remainderl;
    using ::remquol;
    using ::rintl;
    using ::roundl;
    using ::scalblnl;
    using ::scalbnl;
    using ::tgammal;
    using ::truncl;

    inline float hypot(float _x, float _y, float _z)
    { return sqrt(_x*_x + _y*_y + _z*_z);}
    inline double hypot(double _x, double _y, double _z)
    { return sqrt(_x*_x + _y*_y + _z*_z);}
    inline long double hypot(long double _x, long double _y, long double _z)
    { return sqrt(_x*_x + _y*_y + _z*_z);}

    // TODO: arithmetic type math function
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CMATH___

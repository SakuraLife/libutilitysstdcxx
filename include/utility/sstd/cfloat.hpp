

#ifndef ___UTILITY__STANDARD__LIBRARY__CFLOAT___
#define ___UTILITY__STANDARD__LIBRARY__CFLOAT___

#include<utility/config/utility_config.hpp>
#include<float.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

#ifndef FLT_EVAL_METHOD
#define FLT_EVAL_METHOD __FLT_EVAL_METHOD__
#endif

#ifndef DECIMAL_DIG
#define DECIMAL_DIG __DECIMAL_DIG__
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::fenv_t;
    using ::fexcept_t;

    using ::feclearexcept;
    using ::fegetexceptflag;
    using ::feraiseexcept;
    using ::fesetexceptflag;
    using ::fetestexcept;
    using ::fegetround;
    using ::fesetround;
    using ::fegetenv;
    using ::feholdexcept;
    using ::fesetenv;
    using ::feupdateenv;
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CFLOAT___

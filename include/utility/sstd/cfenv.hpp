
#ifndef ___UTILITY__STANDARD__LIBRARY__CFENV___
#define ___UTILITY__STANDARD__LIBRARY__CFENV___

#include<utility/config/utility_config.hpp>
#include<fenv.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

#ifdef feclearexcept
#undef feclearexcept
#endif

#ifdef fegetexceptflag
#undef fegetexceptflag
#endif

#ifdef feraiseexcept
#undef feraiseexcept
#endif

#ifdef fesetexceptflag
#undef fesetexceptflag
#endif

#ifdef fetestexcept
#undef fetestexcept
#endif

#ifdef fegetround
#undef fegetround
#endif

#ifdef fesetround
#undef fesetround
#endif

#ifdef fegetenv
#undef fegetenv
#endif

#ifdef feholdexcept
#undef feholdexcept
#endif


#ifdef fesetenv
#undef fesetenv
#endif

#ifdef feupdateenv
#undef feupdateenv
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

#endif // ! ___UTILITY__STANDARD__LIBRARY__CFENV___

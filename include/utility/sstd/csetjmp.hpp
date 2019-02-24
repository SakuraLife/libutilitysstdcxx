
#ifndef ___UTILITY__STANDARD__LIBRARY__CSETJMP___
#define ___UTILITY__STANDARD__LIBRARY__CSETJMP___

#include<utility/config/utility_config.hpp>
#include<setjmp.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

#ifndef setjmp
#define setjmp(env) setjmp(env)
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using ::jmp_buf;
    using ::longjmp;
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CSETJMP___

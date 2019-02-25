
#ifndef __UTILITY_EXCEPTION_TERMINATE__
#define __UTILITY_EXCEPTION_TERMINATE__

#include<utility/config/utility_config.hpp>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

__utility_exceptspace_start(utility)
  typedef void (*terminate_handler)();

  __UTILITY_FUNC_VIS
  terminate_handler set_terminate(terminate_handler) noexcept;
  __UTILITY_FUNC_VIS
  terminate_handler get_terminate() noexcept;
  [[noreturn]] __UTILITY_FUNC_VIS
  void terminate() noexcept;

 __utility_exceptspace_end(utility)


#endif // ! __UTILITY_EXCEPTION_TERMINATE__


#ifndef ___UTILITY__EXCEPTION__EXCEPTION___
#define ___UTILITY__EXCEPTION__EXCEPTION___

#include<utility/config/utility_config.hpp>
#include<utility/config/builtin_function.hpp>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

__utility_exceptspace_start(utility)
  class exception
  {
    public:
      exception() noexcept;
      virtual ~exception() noexcept;

    public:
      virtual const char* what() const noexcept;
  };

  template<typename _Exception>
  [[noreturn]] inline void exception_throw(const char* _info)
  {
#if !defined(__UTILITY_NO_EXCEPTION__)
    throw _Exception{_info};
#else
    _builtin::_about(_info);
#endif // __UTILITY_NO_EXCEPTION__
  }

  template<typename _Exception>
  [[noreturn]] inline void exception_throw()
  {
#if !defined(__UTILITY_NO_EXCEPTION__)
    throw _Exception{};
#else
    _builtin::_about();
#endif // __UTILITY_NO_EXCEPTION__
  }
__utility_exceptspace_end(utility)

#endif // ! ___UTILITY__EXCEPTION__EXCEPTION___


#ifndef __UTILITY_EXCEPTION_BAD_ALLOC__
#define __UTILITY_EXCEPTION_BAD_ALLOC__

#include<utility/config/utility_config.hpp>
#include<utility/exception/exception.hpp>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

__utility_exceptspace_start(utility)
  class bad_alloc : public exception
  {
    public:
      bad_alloc() noexcept;
      virtual ~bad_alloc() noexcept;

    public:
      virtual const char* whar() const noexcept;
  };

__utility_exceptspace_end(utility)

#endif // ! __UTILITY_EXCEPTION_BAD_ALLOC__

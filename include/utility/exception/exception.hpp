
#ifndef ___UTILITY__EXCEPTION__EXCEPTION___
#define ___UTILITY__EXCEPTION__EXCEPTION___

#include<utility/config/utility_config.hpp>
#include<utility/config/builtin_function.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(exception)
    class exception
    {
      public:
        exception() noexcept;
        virtual ~exception() noexcept;

      public:
        virtual const char* what() const noexcept;
    };

    exception::exception() noexcept
    { }

    exception::~exception() noexcept
    { }

    const char* exception::what() const noexcept
    { return "exception::exception";}


    template<typename _Exception>
    [[noreturn]] inline void exception_throw(const char* _info)
    {
#if defined(__UTILITY_NO_EXCEPTION__)
      throw _Exception{_info};
#else
      ;
#endif // __UTILITY_NO_EXCEPTION__
    }
  __utility_interspace_end(exception)
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__EXCEPTION__EXCEPTION___

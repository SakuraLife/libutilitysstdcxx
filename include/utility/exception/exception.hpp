
#ifndef ___UTILITY__EXCEPTION__EXCEPTION___
#define ___UTILITY__EXCEPTION__EXCEPTION___

#include<utility/config/utility_config.hpp>
#include<utility/config/builtin_function.hpp>

namespace utility
{
  namespace exception
  {
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
    [[noreturn]] inline void exception_throw(_Exception _e)
    {
#if defined(__UTILITY_NO_EXCEPTION__)
      throw _e;
#else
      ;
#endif // __UTILITY_NO_EXCEPTION__
    }
  }
}

#endif // ! ___UTILITY__EXCEPTION__EXCEPTION___

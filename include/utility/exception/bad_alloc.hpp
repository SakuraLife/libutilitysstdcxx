
#ifndef __UTILITY_EXCEPTION_BAD_ALLOC__
#define __UTILITY_EXCEPTION_BAD_ALLOC__

#include<utility/config/utility_config.hpp>
#include<utility/info/exception/exception.hpp>

namespace utility
{
  namespace exception
  {
    class bad_alloc : public exception
    {
      public:
        bad_alloc() noexcept;
        { }
        virtual ~bad_alloc() noexcept;
        { }
        virtual const char* whar() const noexcept;
    };


    bad_alloc::bad_alloc() noexcept
    { }

    bad_alloc::~bad_alloc() noexcept
    { }

    const char* bad_alloc::what() const noexcept
    { return "exception::bad_alloc";}
  }
}

#endif // ! __UTILITY_EXCEPTION_BAD_ALLOC__


#ifndef ___UTILITY__STANDARD__LIBRARY__CERRNO___
#define ___UTILITY__STANDARD__LIBRARY__CERRNO___

#include<utility/config/utility_config.hpp>

extern "C++"
{

namespace utility
{
  namespace sstd
  {
    extern int* errno_ptr() noexcept;
  }
}

}

#endif // ! ___UTILITY__STANDARD__LIBRARY__CERRNO___

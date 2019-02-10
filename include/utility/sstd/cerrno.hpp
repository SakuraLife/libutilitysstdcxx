
#ifndef ___UTILITY__STANDARD__LIBRARY__CERRNO___
#define ___UTILITY__STANDARD__LIBRARY__CERRNO___

#include<utility/config/utility_config.hpp>

extern "C++"
{

__utility_globalspace_start(utility)
  namespace sstd
  {
    extern int* errno_ptr() noexcept;
  }
__utility_globalspace_end(utility)

}

#endif // ! ___UTILITY__STANDARD__LIBRARY__CERRNO___

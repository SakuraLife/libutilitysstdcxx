

#ifndef __UTILITY_TRAIT_OPT___NONE____
#define __UTILITY_TRAIT_OPT___NONE____

#include<utility/config/utility_config.hpp>

namespace utility
{
  namespace trait
  {
    namespace __opt__
    {
      struct __none__
      {
        __none__() = delete;
        __none__(const __none__&) = delete;
        __none__& operator=(const __none__&) = delete;
        ~__none__() = delete;
      };

    }
  }
}

#endif // ! __UTILITY_TRAIT_OPT___NONE____

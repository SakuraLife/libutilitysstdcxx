
#ifndef __UTILITY_TRAIT_OPT___RESULT___
#define __UTILITY_TRAIT_OPT___RESULT___

#include<utility/config/utility_config.hpp>

namespace utility
{
  namespace trait
  {
    namespace __opt__
    {
      struct __success__
      { };
      struct __failure__
      { };

      struct __cyc_success__
      { typedef __cyc_success__ type;};
      struct __cyc_failure__
      { typedef __cyc_failure__ type;};

      template<typename _T>
      struct __type_success__
      { typedef _T type;};
      template<typename _T>
      struct __type_failure__
      { };
    }
  }
}


#endif // ! __UTILITY_TRAIT_OPT___RESULT___

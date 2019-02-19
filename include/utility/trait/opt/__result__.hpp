
#ifndef __UTILITY_TRAIT_OPT___RESULT___
#define __UTILITY_TRAIT_OPT___RESULT___

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    namespace __opt__
    {
      struct __UTILITY_TYPE_VIS __success__
      { };
      struct __UTILITY_TYPE_VIS __failure__
      { };

      struct __UTILITY_TYPE_VIS __cyc_success__
      { typedef __cyc_success__ type;};
      struct __UTILITY_TYPE_VIS __cyc_failure__
      { typedef __cyc_failure__ type;};

      template<typename _T>
      struct __UTILITY_TEMPLATE_VIS __type_success__
      { typedef _T type;};
      template<typename _T>
      struct __UTILITY_TEMPLATE_VIS __type_failure__
      { };
    }
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)


#endif // ! __UTILITY_TRAIT_OPT___RESULT___

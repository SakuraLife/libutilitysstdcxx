
#ifndef __UTILITY_TRAIT_OPT___CONSTANT____
#define __UTILITY_TRAIT_OPT___CONSTANT____

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
    namespace __opt__
    {
      template<typename _Type, _Type _val>
      struct __constant__
      {
        constexpr static _Type value = _val;
        typedef _Type type;
      };

      template<bool _B>
      using __bool_constant__   = __constant__<bool, _B>;
      using __true_constant__   = __bool_constant__<true>;
      using __false_constant__  = __bool_constant__<false>;

      template<bool _B>
      using __bool__    = __constant__<bool, _B>;
      using __true__    = __bool_constant__<true>;
      using __false__   = __bool_constant__<false>;
    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_OPT___CONSTANT____

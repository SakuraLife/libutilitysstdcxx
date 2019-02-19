
#ifndef __UTILITY_TRAIT_TYPE_MISCELLANEOUS_CONDITIONAL__
#define __UTILITY_TRAIT_TYPE_MISCELLANEOUS_CONDITIONAL__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(miscellaneous)
        // conditional
        template<bool _B, typename _IF, typename _ELSE>
        struct __UTILITY_TEMPLATE_VIS conditional
        { typedef _IF type;};
        template<typename _IF, typename _ELSE>
        struct __UTILITY_TEMPLATE_VIS conditional<false, _IF, _ELSE>
        { typedef _ELSE type;};

        template<bool _B, typename _IF, typename _ELSE>
        using conditional_t = typename conditional<_B, _IF, _ELSE>::type;
      __utility_interspace_end(miscellaneous)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_MISCELLANEOUS_CONDITIONAL__

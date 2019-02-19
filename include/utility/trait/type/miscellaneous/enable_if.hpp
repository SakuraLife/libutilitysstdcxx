
#ifndef __UTILITY_TRAIT_TYPE_MISCELLANEOUS_ENABLE_IF__
#define __UTILITY_TRAIT_TYPE_MISCELLANEOUS_ENABLE_IF__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(miscellaneous)
        // enable_if
        template<bool _B, typename _T = void>
        struct __UTILITY_TEMPLATE_VIS enable_if
        { };
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS enable_if<true, _T>
        { typedef _T type;};

        template<bool _B, typename _T = void>
        using enable_if_t = typename enable_if<_B, _T>::type;
      __utility_interspace_end(miscellaneous)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_MISCELLANEOUS_ENABLE_IF__

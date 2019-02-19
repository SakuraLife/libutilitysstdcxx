
#ifndef __UTILITY_TRAIT_TYPE_MISCELLANEOUS_UNDERLYING_TYPE__
#define __UTILITY_TRAIT_TYPE_MISCELLANEOUS_UNDERLYING_TYPE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_underlying_type

#include<utility/trait/config/trait_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(miscellaneous)
        // underlying_type
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS underlying_type
        { typedef __utility_underlying_type(_T) type;};

        template<typename _T>
        using underlying_type_t = typename underlying_type<_T>::type;
      __utility_interspace_end(miscellaneous)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __utility_has_underlying_type

#include<utility/trait/config/trait_undef.hpp>

#endif // __UTILITY_TRAIT_TYPE_MISCELLANEOUS_UNDERLYING_TYPE__

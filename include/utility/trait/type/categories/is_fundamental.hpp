
#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_FUNDAMENTAL__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_FUNDAMENTAL__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/categories/is_void.hpp>
#include<utility/trait/type/categories/is_arithmetic.hpp>
#include<utility/trait/type/categories/is_null_pointer.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(categories)
        // is_fundamental
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_fundamental:
          public trait::integral_constant<bool,
            is_void<_T>::value       ||
            is_arithmetic<_T>::value ||
            is_null_pointer<_T>::value>
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_fundamental_v = is_fundamental<_T>::value;
#endif

      __utility_interspace_end(categories)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_CATEGORIES_IS_FUNDAMENTAL__

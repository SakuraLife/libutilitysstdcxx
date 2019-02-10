
#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_OBJECT__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_OBJECT__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/categories/is_scalar.hpp>
#include<utility/trait/type/categories/is_array.hpp>
#include<utility/trait/type/categories/is_union.hpp>
#include<utility/trait/type/categories/is_class.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(categories)
        // is_object
        template<typename _T>
        struct is_object:
          public integral_constant<bool,
            is_scalar<_T>::value ||
            is_array<_T>::value  ||
            is_union<_T>::value  ||
            is_class<_T>::value>
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_object_v = is_object<_T>::value;
#endif

      __utility_interspace_end(categories)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_CATEGORIES_IS_OBJECT__


#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_SCALAR__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_SCALAR__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/categories/is_arithmetic.hpp>
#include<utility/trait/type/categories/is_member_pointer.hpp>
#include<utility/trait/type/categories/is_pointer.hpp>
#include<utility/trait/type/categories/is_null_pointer.hpp>
#include<utility/trait/type/categories/is_enum.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(categories)
      {
        // is_scalar
        template<typename _T>
        struct is_scalar :
          public trait::integral_constant<bool,
            is_arithmetic<_T>::value     ||
            is_member_pointer<_T>::value ||
            is_pointer<_T>::value        ||
            is_null_pointer<_T>::value   ||
            is_enum<_T>::value>
        { };
        template<>
        struct is_scalar<nullptr_t>: public trait::true_type
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_scalar_v = is_scalar<_T>::value;
#endif

      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_CATEGORIES_IS_SCALAR__

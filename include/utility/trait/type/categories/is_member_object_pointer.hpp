
#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_MEMBER_OBJECT_POINTER__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_MEMBER_OBJECT_POINTER__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/categories/is_member_pointer.hpp>
#include<utility/trait/type/categories/is_member_function_pointer.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(categories)
        // is_member_object_pointer
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_member_object_pointer:
          public trait::integral_constant<bool,
            is_member_pointer<_T>::value           &&
            !is_member_function_pointer<_T>::value>
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_member_object_pointer_v =
                      is_member_object_pointer<_T>::value;
#endif

      __utility_interspace_end(categories)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_CATEGORIES_IS_MEMBER_OBJECT_POINTER__


#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_LVALUE_REFERENCE__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_LVALUE_REFERENCE__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(categories)
        // is_lvalue_reference
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_lvalue_reference: public false_type
        { };
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_lvalue_reference<_T&>: public true_type
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_lvalue_reference_v = is_lvalue_reference<_T>::value;
#endif

      __utility_interspace_end(categories)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_CATEGORIES_IS_LVALUE_REFERENCE__

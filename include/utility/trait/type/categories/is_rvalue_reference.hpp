
#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_RVALUE_REFERENCE__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_RVALUE_REFERENCE__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(categories)
      {
        // is_rvalue_reference
        template<typename _T>
        struct is_rvalue_reference : public trait::false_type
        { };
        template<typename _T>
        struct is_rvalue_reference<_T&&> : public trait::true_type
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_rvalue_reference_v = is_rvalue_reference<_T>::value;
#endif

      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_CATEGORIES_IS_RVALUE_REFERENCE__

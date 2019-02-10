
#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_MEMBER_POINTER__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_MEMBER_POINTER__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(categories)
      {
        // is_member_pointer
        namespace __impl
        {
          template<typename _T>
          struct __is_member_pointer_test: public false_type
          { };

          template<typename _T, class _Inn>
          struct __is_member_pointer_test<_T _Inn::*>: public true_type
          { };
        }
        template<typename _T>
        struct is_member_pointer :
          public __impl::__is_member_pointer_test<
            trait::type::transform::remove_cv_t<_T>>
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_member_pointer_v = is_member_pointer<_T>::value;
#endif

      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_CATEGORIES_IS_MEMBER_POINTER__

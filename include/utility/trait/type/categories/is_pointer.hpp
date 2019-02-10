
#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_POINTER__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_POINTER__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(categories)
      {
        // is_pointer
        namespace __impl
        {
          template<typename _T>
          struct __is_pointer_test: public false_type
          { };
          template<typename _T>
          struct __is_pointer_test<_T*>: public true_type
          { };
        }
        template<typename _T>
        struct is_pointer :
          public __impl::__is_pointer_test<
            trait::type::transform::remove_cv_t<_T>
          >
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_pointer_v = is_pointer<_T>::value;
#endif

      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_CATEGORIES_IS_POINTER__

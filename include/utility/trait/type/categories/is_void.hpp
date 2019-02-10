
#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_VOID__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_VOID__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(categories)
        // is_void
        namespace __impl
        {
          template<typename _T>
          struct __is_void_test: public false_type
          { };
          template<>
          struct __is_void_test<void>: public true_type
          { };
        }
        template<typename _T>
        struct is_void :
          public __impl::__is_void_test<
            trait::type::transform::remove_cv_t<_T>
          >
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_void_v = is_void<_T>::value;
#endif

      __utility_interspace_end(categories)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)


#endif // ! __UTILITY_TRAIT_TYPE_CATEGORIES_IS_VOID__

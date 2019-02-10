
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_CV_POINTER__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_CV_POINTER__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>
#include<utility/trait/type/transform/remove_pointer.hpp>
#include<utility/trait/type/transform/remove_all_pointer.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(transform)
        // remove_const_pointer
        template<typename _T>
        struct remove_const_pointer
        { typedef remove_const_t<remove_pointer_t<_T>> type;};

        // remove_volatile_pointer
        template<typename _T>
        struct remove_volatile_pointer
        { typedef remove_volatile_t<remove_const_t<_T>> type;};

        // remove_cv_pointer
        template<typename _T>
        struct remove_cv_pointer
        { typedef remove_cv_t<remove_pointer_t<_T>> type;};

        // remove_const_all_pointer
        template<typename _T>
        struct remove_const_all_pointer
        { typedef remove_const_t<remove_all_pointer_t<_T>> type;};

        // remove_volatile_all_pointer
        template<typename _T>
        struct remove_volatile_all_pointer
        { typedef remove_volatile_t<remove_all_pointer_t<_T>> type;};

        // remove_cv_all_pointer
        template<typename _T>
        struct remove_cv_all_pointer
        {
          typedef remove_cv_t<remove_all_pointer_t<_T>> type;
        };

        template<typename _T>
        using remove_cv_all_pointer_t = typename remove_cv_all_pointer<_T>::type;

      __utility_interspace_end(transform)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_CV_POINTER__

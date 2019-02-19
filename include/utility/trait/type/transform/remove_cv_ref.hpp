
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_CV_REF__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_CV_REF__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>
#include<utility/trait/type/transform/remove_reference.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(transform)
        // remove_const_reference
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_const_reference
        { typedef remove_const_t<remove_reference_t<_T>> type;};
        // remove_volatile_reference
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_volatile_reference
        { typedef remove_volatile_t<remove_reference_t<_T>> type;};
        // remove_cv_reference
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_cv_reference
        { typedef remove_cv_t<remove_reference_t<_T>> type;};

        template<typename _T>
        using remove_cv_ref = remove_cv_reference<_T>;
        template<typename _T>
        using remove_cv_ref_t = typename remove_cv_reference<_T>::type;
        template<typename _T>
        using remove_cv_reference_t = typename remove_cv_reference<_T>::type;
      __utility_interspace_end(transform)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_CV_REF__

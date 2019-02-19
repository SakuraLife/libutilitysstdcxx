
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_CV__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_CV__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(transform)
        // remove_const
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_const
        { typedef _T type;};
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_const<_T const>
        { typedef _T type;};

        // remove_volatile
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_volatile
        { typedef _T type;};
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_volatile<_T volatile>
        { typedef _T type;};

        // remove_cv
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_cv
        {
          typedef typename remove_volatile<
            typename remove_const<_T>::type
          >::type type;
        };

        template<typename _T>
        using remove_const_t = typename remove_const<_T>::type;
        template<typename _T>
        using remove_volatile_t = typename remove_volatile<_T>::type;
        template<typename _T>
        using remove_cv_t = typename remove_cv<_T>::type;
      __utility_interspace_end(transform)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_CV__

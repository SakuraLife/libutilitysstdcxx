
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_POINTER__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_POINTER__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(transform)
        // remove_pointer
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_pointer
        { typedef _T type;};
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_pointer<_T*>
        { typedef _T type;};
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_pointer<_T* const>
        { typedef _T type;};
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_pointer<_T* volatile>
        { typedef _T type;};
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS remove_pointer<_T* const volatile>
        { typedef _T type;};

        template<typename _T>
        using remove_pointer_t = typename remove_pointer<_T>::type;

      __utility_interspace_end(transform)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_POINTER__

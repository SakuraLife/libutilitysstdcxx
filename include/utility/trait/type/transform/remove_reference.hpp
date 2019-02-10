
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_REFERENCE__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_REFERENCE__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(transform)
        // remove_reference
        template<typename _T>
        struct remove_reference
        { typedef _T type;};
        template<typename _T>
        struct remove_reference<_T&>
        { typedef _T type;};
        template<typename _T>
        struct remove_reference<_T&&>
        { typedef _T type;};

        template<typename _T>
        using remove_reference_t = typename remove_reference<_T>::type;

      __utility_interspace_end(transform)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_REFERENCE__

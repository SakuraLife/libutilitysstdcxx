
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_EXTENT__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_EXTENT__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(transform)
      {
        // remove_extent
        template<typename _T>
        struct remove_extent
        { typedef _T type;};
        template<typename _T>
        struct remove_extent<_T[]>
        { typedef _T type;};
        template<typename _T, size_t _size>
        struct remove_extent<_T[_size]>
        { typedef _T type;};

        template<typename _T>
        using remove_extent_t = typename remove_extent<_T>::type;
      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_EXTENT__

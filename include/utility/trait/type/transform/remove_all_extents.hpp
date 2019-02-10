
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_ALL_EXTENT__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_ALL_EXTENT__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(transform)
      {
        // remove_all_extents
        template<typename _T>
        struct remove_all_extents
        { typedef _T type;};
        template<typename _T>
        struct remove_all_extents<_T[]>
        { typedef typename remove_all_extents<_T>::type type;};
        template<typename _T, size_t _size>
        struct remove_all_extents<_T[_size]>
        { typedef typename remove_all_extents<_T>::type type;};

        template<typename _T>
        using remove_all_extents_t = typename remove_all_extents<_T>::type;

      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_ALL_EXTENT__

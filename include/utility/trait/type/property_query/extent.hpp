
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_EXTENT__
#define __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_EXTENT__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(property_query)
      {
        // extent
        template<typename _T, unsigned int _I = 0>
        struct extent: public integral_constant<size_t, 0>
        { };
        template<typename _T, unsigned int _I>
        struct extent<_T[], _I>: public integral_constant<
            size_t, extent<_T, _I-1>::value
          >
        { };
        template<typename _T>
        struct extent<_T[], 0>: public integral_constant<size_t, 0>
        { };
        template<typename _T, size_t _size>
        struct extent<_T[_size], 0>: public integral_constant<size_t, _size>
        { };
        template<typename _T, size_t _size, unsigned int _I>
        struct extent<_T[_size], _I>: public integral_constant<
            size_t, extent<_T, _I-1>::value
          >
        { };

      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_EXTENT__

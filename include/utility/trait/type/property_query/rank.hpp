
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_RANK__
#define __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_RANK__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property_query)
        // rank
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS rank: public integral_constant<size_t, 0>
        { };
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS rank<_T[]>: public integral_constant<size_t, rank<_T>::value+1>
        { };
        template<typename _T, size_t _size>
        struct __UTILITY_TEMPLATE_VIS rank<_T[_size]>:
          public integral_constant<size_t, rank<_T>::value+1>
        { };

      __utility_interspace_end(property_query)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_RANK__

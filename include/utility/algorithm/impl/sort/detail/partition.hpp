
#ifndef __UTILITY_ALGORITHM_IMPL_SORT_PARTITION__
#define __UTILITY_ALGORITHM_IMPL_SORT_PARTITION__

#include<utility/algorithm/iter_swap.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    namespace impl
    {
      namespace sort_impl
      {
        template<typename _RandomAccessIterator, typename _Compare>
        _RandomAccessIterator __partition(
          _RandomAccessIterator __first, _RandomAccessIterator __last,
          _RandomAccessIterator __pivot, _Compare __compare
        )
        {
          for(;;)
          {
            for(;__compare(*__first, *__pivot);)
            { ++__first;}
            --__last;
            for(;__compare(*__pivot, *__last);)
            { --__last;}
            if(!(__first < __last))
            { return __first;}
            algorithm::iter_swap(__first, __last);
            ++__first;
          }
        }

      }
    }
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_IMPL_SORT_PARTITION__

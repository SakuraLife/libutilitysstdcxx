
#ifndef __UTILITY_ALGORITHM_SWAP_RANGES__
#define __UTILITY_ALGORITHM_SWAP_RANGES__

#include<utility/config/utility_config.hpp>
#include<utility/algorithm/iter_swap.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(algorithm)
  {
    /**
     * \brief exchanges elements between range
     * Exchanges elements between range [\a _first, \a _last)
     * and another range starting at \a _ffirst.
     *
     * \param _first,_last    the first range of elements to swap
     * \param _ffirst         beginning of the second range of elements to swap
     * \return iterator to the element past the last element exchanged
     *         in the range beginning with \a _ffirst.
     */
    template<class _ForwardIterator1, class _ForwardIterator2>
    _ForwardIterator2 swap_ranges(
      _ForwardIterator1 _first, _ForwardIterator1 _last,
      _ForwardIterator2 _ffirst
    )
    {
      for(; _first != _last;)
      { iter_swap(_first++, _ffirst++);}
      return _ffirst;
    }
  }
__utility_globalspace_end(utility)


#endif // ! __UTILITY_ALGORITHM_SWAP_RANGES__

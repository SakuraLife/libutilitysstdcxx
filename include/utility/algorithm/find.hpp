
#ifndef __UTILITY_ALGORITHM_FIND__
#define __UTILITY_ALGORITHM_FIND__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    /**
     * Finds value in range
     *
     * Returns the first element in the range [\a __first, \a __last)
     * that equal to \a __val
     *
     * \tparam _InputIterator the iterator type
     * \tparam _T             the value type
     * \param __first,__last the range of elements to examine
     * \param __val          value to compare the elements to
     * \return Iterator to the first element satisfying the condition
     *         or \a __last if no such element is found.
     */
    template<typename _InputIterator, typename _T>
    inline _InputIterator find(
      _InputIterator __first, _InputIterator __last,
      const _T& __val
    )
    {
      for(; __first != __last; ++__first)
      {
        if(*__first == __val)
        { return __first;}
      }
      return __last;
    }
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_FIND__

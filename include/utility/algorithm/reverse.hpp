
#ifndef __UTILITY_ALGORITHM_REVERSE__
#define __UTILITY_ALGORITHM_REVERSE__

#include<utility/config/utility_config.hpp>
#include<utility/algorithm/iter_swap.hpp>
#include<utility/iterator/iterator_traits.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    namespace __detail
    {
      template<
        typename _Iterator,
        bool = iterator::is_vaild_iterator_type<
          _Iterator, iterator::random_access_iterator_tag
        >::value
      >
      struct __reverse
      {
        template<typename _BidirectionalIterator>
        static inline void __aux(
          _BidirectionalIterator __first, _BidirectionalIterator __last
        )
        {
          for(;__first != __last;)
          {
            if(__first == --__last)
            { break;}
            iter_swap(__first, __last);
            ++__first;
          }
        }
      };
      template<typename _Iterator>
      struct __reverse<_Iterator, true>
      {
        template<typename _RandomAccessIterator>
        static inline void __aux(
          _RandomAccessIterator __first, _RandomAccessIterator __last
        )
        {
          if(__first != __last)
          {
            for(;__first < --__last; ++__first)
            { iter_swap(__first, __last);}
          }
        }
      };
    }
    /**
     * \brief Reverse range
     *
     * Reverses the order of the elements in the range [\a __first, \a __last)
     *
     * \param __first,__last the range of elements to reverse
     * \note Behaves as if applying \c iter_swap to every pair of iterators
     *       \a __first+i, (\a __last-i) - 1 for each
     *       non-negative i < (\a __last - \a __first)/2
     */
    template<typename _BidirectionalIterator>
    void reverse(_BidirectionalIterator __first, _BidirectionalIterator __last)
    {
      __detail::__reverse<_BidirectionalIterator>::__aux(
        __first, __last
      );
    }
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_REVERSE__

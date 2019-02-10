
#ifndef __UTILITY_ALGORITHM_SORTIMPL_INSERTION_SORT__
#define __UTILITY_ALGORITHM_SORTIMPL_INSERTION_SORT__

#include<utility/algorithm/swap.hpp>
#include<utility/iterator/iterator_traits.hpp>
#include<utility/iterator/next.hpp>
#include<utility/iterator/prev.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    namespace sort_tag
    {
      struct insertion_sort_tag { };
    }

    namespace impl
    {
      using algorithm::sort_tag::insertion_sort_tag;
      template<typename _BidirectionalIterator, typename _Compare>
      void __sort(
        _BidirectionalIterator __first, _BidirectionalIterator __last,
        _Compare __compare, insertion_sort_tag /*sort_tag*/
      )
      {
        using algorithm::swap;
        typedef typename
          iterator::iterator_traits<_BidirectionalIterator>::value_type
          __value_type;
        for(
          _BidirectionalIterator __i = iterator::next(__first);
          __i != __last; ++__i
        )
        {
#ifdef UTILITY_DEBUG
          static_assert(
            iterator::is_bidirectional_iterator<_BidirectionalIterator>::value,
            "insertion sort tag need at least bidirectional iterator."
          );
#endif // ! UTILITY_DEBUG
          __value_type __tmp = *__i;
          _BidirectionalIterator __fpos;
          for(
            __fpos = iterator::prev(__i);
            iterator::next(__fpos) != __first && __compare(__tmp, *__fpos);
            --__fpos
          )
          { swap(*__fpos, *iterator::next(__fpos));}
          *iterator::next(__fpos) = __tmp;
        }
      }

    }

  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_SORTIMPL_INSERTION_SORT__


#ifndef __UTILITY_ALGORITHM_SORTIMPL_GNOME_SORT__
#define __UTILITY_ALGORITHM_SORTIMPL_GNOME_SORT__

#include<utility/algorithm/swap.hpp>
#include<utility/iterator/prev.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    namespace sort_tag
    {
      struct gnome_sort_tag { };
    }

    namespace impl
    {
      using algorithm::sort_tag::gnome_sort_tag;
      template<typename _BidirectionalIterator, typename _Compare>
      void __sort(
        _BidirectionalIterator __first, _BidirectionalIterator __last,
        _Compare __compare, gnome_sort_tag /*sort_tag*/
      )
      {
        using algorithm::swap;
#ifdef UTILITY_DEBUG
        static_assert(
          iterator::is_bidirectional_iterator<_BidirectionalIterator>::value,
          "gnome sort need at least bidirectional iterator."
        );
#endif // ! UTILITY_DEBUG
        for(_BidirectionalIterator __pos = __first; __pos != __last;)
        {
          if(__pos == __first || !__compare(*__pos, *iterator::prev(__pos)))
          { ++__pos;}
          else
          {
            swap(*__pos, *iterator::prev(__pos));
            --__pos;
          }
        }
      }

    }

  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_SORTIMPL_GNOME_SORT__

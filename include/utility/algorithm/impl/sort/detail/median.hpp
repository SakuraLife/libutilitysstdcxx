
#ifndef __UTILITY_ALGORITHM_IMPL_SORT_MEDIAN__
#define __UTILITY_ALGORITHM_IMPL_SORT_MEDIAN__

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    namespace impl
    {
      namespace sort_impl
      {
        template<typename _RandomAccessIterator, typename _Compare>
        inline _RandomAccessIterator __median(
          _RandomAccessIterator __a, _RandomAccessIterator __b,
          _RandomAccessIterator __c, _Compare __compare
        )
        {
          if(__compare(*__a, *__b))
          {
            if(__compare(*__b, *__c))
            { return __b;}
            if(__compare(*__a, *__c))
            { return __c;}
            return __a;
          }
          if(__compare(*__a, *__c))
          { return __a;}
          if(__compare(*__b, *__c))
          { return __c;}
          return __b;
        }

      }
    }
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_IMPL_SORT_MEDIAN__


#ifndef __UTILITY_ALGORITHM_IMPL_HEAP_POP_HEAP__
#define __UTILITY_ALGORITHM_IMPL_HEAP_POP_HEAP__

#include<utility/config/utility_config.hpp>
#include<utility/trait/type/transform/add_reference.hpp>
#include<utility/algorithm/algorithm_auxiliary.hpp>
#include<utility/algorithm/swap.hpp>
#include<utility/algorithm/impl/heap/push_heap.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    namespace impl
    {
      template<typename _RandomAccessIterator, typename _Compare, typename _Difference>
      void __pop_heap_aux(_RandomAccessIterator __first, _Difference __len, _Compare __compare)
      {
        using algorithm::swap;
        _Difference __hole = 0;
        _Difference __child = 2*__hole+1;
        for(;__child < __len;)
        {
          if(
            __child+1 < __len &&
            __compare(*(__first+__child), *(__first+__child+1))
          )
          { ++__child;}
          if(__compare(*(__first+__child), *(__first+__hole)))
          { return;}
          else
          {
            swap(*(__first+__child), *(__first+__hole));
            __hole = __child;
            __child = 2*__child+1;
          }
        }
      }
    }

    template<typename _RandomAccessIterator, typename _Compare>
    inline void pop_heap(
      _RandomAccessIterator __first, _RandomAccessIterator __last,
      _Compare __compare
    )
    {
      typedef typename
        iterator::iterator_traits<_RandomAccessIterator>::difference_type
        __difference_type;
      typedef typename
        trait::type::transform::add_lvalue_reference<_Compare>::type
        __comp_ref;

      algorithm::swap(*(__last-1), *__first);
      impl::__pop_heap_aux<_RandomAccessIterator, __comp_ref, __difference_type>(
        __first, __difference_type(__last-__first-1), __compare
      );
    }
    template<typename _RandomAccessIterator>
    inline void pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
    {
      typedef typename
        iterator::iterator_traits<_RandomAccessIterator>::value_type
        __value_type;
      pop_heap(
        __first, __last,
        algorithm::less<__value_type>()
      );
    }
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)
#endif // ! __UTILITY_ALGORITHM_IMPL_HEAP_POP_HEAP__

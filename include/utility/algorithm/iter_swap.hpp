
#ifndef __UTILITY_ALGORITHM_ITER_SWAP__
#define __UTILITY_ALGORITHM_ITER_SWAP__

#include<utility/config/utility_config.hpp>
#include<utility/algorithm/swap.hpp>
#include<utility/trait/type/type_trait_special.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    /**
     * \brief Exchange values of objects pointed to by two iterators
     *
     * Swaps the values of the elements the given iterators are pointing to.
     *
     * \param __ita, __itb iterators to the elements to swap
     */
    template<typename _ForwardIterator1, typename _ForwardIterator2>
    inline void iter_swap(_ForwardIterator1 __ita, _ForwardIterator2 __itb)
      noexcept(noexcept(swap(
            *trait::type::special::declval<_ForwardIterator1>(),
            *trait::type::special::declval<_ForwardIterator2>()
      )))
    {
      using algorithm::swap;
      swap(*__ita, *__itb);
    }
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_ITER_SWAP__

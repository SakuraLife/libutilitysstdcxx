
#ifndef __UTILITY_ALGORITHM_MINMAX__
#define __UTILITY_ALGORITHM_MINMAX__

#include<utility/config/utility_config.hpp>

#include<utility/container/pair.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    template<typename _T>
    inline __UTILITY_CPP14_CONSTEXPR__
    container::pair<const _T&, const _T&>
    minmax(const _T& _x, const _T& _y)
    {
      using container::pair;
      if(_x < _y)
      { return pair<const _T&, const _T&>{_x, _y};}
      return pair<const _T&, const _T&>{_y, _x};
    }

    template<typename _T, typename _Compare>
    inline __UTILITY_CPP14_CONSTEXPR__
    container::pair<const _T&, const _T&>
    minmax(const _T& _x, const _T& _y, _Compare _comp)
    {
      using container::pair;
      if(_comp(_x, _y))
      { return pair<const _T&, const _T&>{_x, _y};}
      return pair<const _T&, const _T&>{_y, _x};
    }
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_MINMAX__

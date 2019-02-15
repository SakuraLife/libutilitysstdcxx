
#ifndef __UTILITY_ALGORITHM_MIN__
#define __UTILITY_ALGORITHM_MIN__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    template<typename _T>
    inline __UTILITY_CPP14_CONSTEXPR__
    const _T& min(const _T& _x, const _T& _y)
    {
      if(_x < _y)
      { return _x;}
      return _y;
    }

    template<typename _T, typename _Compare>
    inline __UTILITY_CPP14_CONSTEXPR__
    const _T& min(const _T& _x, const _T& _y, _Compare _comp)
    {
      if(_comp(_x, _y))
      { return _x;}
      return _y;
    }
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_MIN__



#ifndef __UTILITY_ALOGITHM_CLAMP__
#define __UTILITY_ALOGITHM_CLAMP__

#include<utility/config/utility_config.hpp>

#include<utility/algorithm/algorithm_auxiliary.hpp>


__utility_globalspace_start(utility)
__utility_interspace_start(algorithm)
  template<typename _T, typename _Compare>
  __UTILITY_CPP14_CONSTEXPR__
  inline const _T& clamp(
    const _T& _x, const _T& _y, const _T& _z, _Compare _comp
  )
  {
    // assert(!_comp(_z, _y)),
    return comp(_x, _y) ? _y : comp(_z, _x) ? _z : _x;
  }

  template<typename _T>
  __UTILITY_CPP14_CONSTEXPR__
  inline const _T& clamp(
    const _T& _x, const _T& _y, const _T& _z
  )
  {
    return clamp(_x, _y, _z, less<_T>{})
  }

__utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALOGITHM_CLAMP__

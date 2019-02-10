
#ifndef __UTILITY_ALGORITHM_MAX__
#define __UTILITY_ALGORITHM_MAX__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(algorithm)
  {
    template<typename _T>
    inline __UTILITY_CPP14_CONSTEXPR__
    const _T& max(const _T& __a, const _T& __b) noexcept
    {
      if(__a > __b )
      { return __a;}
      return __b;
    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_MAX__

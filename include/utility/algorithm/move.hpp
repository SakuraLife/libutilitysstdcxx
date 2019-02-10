
#ifndef __UTILITY_ALGORITHM_MOVE__
#define __UTILITY_ALGORITHM_MOVE__

#include<utility/config/utility_config.hpp>
#include<utility/trait/type/transform/remove_reference.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(algorithm)
  {
    template<typename _T>
    inline constexpr
    typename trait::type::transform::remove_reference<_T>::type&&
    move(_T&& _val) noexcept
    {
      typedef typename
        trait::type::transform::remove_reference<_T>::type _U;
      return static_cast<_U&&>(_val);
    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_MOVE__

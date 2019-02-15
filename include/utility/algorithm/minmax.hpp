
#ifndef __UTILITY_ALGORITHM_MINMAX__
#define __UTILITY_ALGORITHM_MINMAX__

#include<utility/config/utility_config.hpp>

#include<utility/algorithm/impl/minmax.hpp>
#include<utility/algorithm/minmax_element.hpp>

#include<utility/container/initializer_list.hpp>
#include<utility/container/pair.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    template<typename _T>
    inline __UTILITY_CPP14_CONSTEXPR__
    container::pair<_T, _T>
    minmax(container::initializer_list<_T> _init)
    {
      using container::pair;
      auto __tmp = minmax_element(_init.begin(), _init.end());
      return pair<_T, _T>{*__tmp.first, *__tmp.second};
    }

    template<typename _T, typename _Compare>
    inline __UTILITY_CPP14_CONSTEXPR__
    container::pair<_T, _T>
    minmax(container::initializer_list<_T> _init, _Compare _comp)
    {
      using container::pair;
      auto __tmp = minmax_element(_init.begin(), _init.end(), _comp);
      return pair<_T, _T>{*__tmp.first, *__tmp.second};
    }
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_MINMAX__

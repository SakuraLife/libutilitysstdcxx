
#ifndef __UTILITY_ALGORITHM_MIN__
#define __UTILITY_ALGORITHM_MIN__

#include<utility/config/utility_config.hpp>

#include<utility/algorithm/impl/min.hpp>
#include<utility/algorithm/min_element.hpp>

#include<utility/container/initializer_list.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    template<typename _T>
    inline __UTILITY_CPP14_CONSTEXPR__
    _T min(container::initializer_list<_T> _init)
    { return *min_element(_init.begin(), _init.end());}

    template<typename _T, typename _Compare>
    inline __UTILITY_CPP14_CONSTEXPR__
    _T min(container::initializer_list<_T> _init, _Compare _comp)
    { return *min_element(_init.begin(), _init.end(), _comp);}
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_MIN__


#ifndef __UTILITY_ALGORITHM_INCLUDES__
#define __UTILITY_ALGORITHM_INCLUDES__

#include<utility/config/utility_config.hpp>

#include<utility/algorithm/algorithm_auxiliary.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    template<
      typename _InputIterator1,
      typename _InputIterator2,
      typename _Compare
    >
    __UTILITY_CPP14_CONSTEXPR__
    bool includes(
      _InputIterator1 _first1, _InputIterator1 _last1,
      _InputIterator2 _first2, _InputIterator2 _last2,
      _Compare _comp
    )
    {
      for(; _first2 != _last2; ++_first1)
      {
        if(_first1 == _last1 || _comp(*_first2, *_first1))
        { return false;}
        if(!_comp(*_first1, *_first2))
        { ++_first2;}
      }

      return true;
    }

    template<typename _InputIterator1, typename _InputIterator2>
    __UTILITY_CPP14_CONSTEXPR__
    bool includes(
      _InputIterator1 _first1, _InputIterator1 _last1,
      _InputIterator2 _first2, _InputIterator2 _last2
    )
    { return includes(_first1, _last1, _first2, _last2, less<void>{});}

  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_INCLUDES__

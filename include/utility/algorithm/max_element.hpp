
#ifndef __UTILITY_ALGORITHM_MAX_ELEMENT__
#define __UTILITY_ALGORITHM_MAX_ELEMENT__

#include<utility/config/utility_config.hpp>

#include<utility/algorithm/algorithm_auxiliary.hpp>

__utility_globalspace_start(utility)
__utility_interspace_start(algorithm)
  template<typename _ForwardIterator, typename _Compare>
  __UTILITY_CPP14_CONSTEXPR__
  _ForwardIterator max_element(
    _ForwardIterator _first, _ForwardIterator _last, _Compare _comp
  )
  {
    if(_first == _last)
    { return _first;}

    _ForwardIterator __max = _first;
    ++_first;
    for(; _first != _last; ++_first)
    {
      if(_comp(*__max, *_first))
      { __max = _first;}
    }

    return __max;
  }

  template<typename _ForwardIterator>
  __UTILITY_CPP14_CONSTEXPR__
  _ForwardIterator max_element(_ForwardIterator _first, _ForwardIterator _last)
  { return max_element(_first, _last, less<void>{});}

__utility_interspace_end(algorithm)
__utility_globalspace_end(utility)



#endif // ! __UTILITY_ALGORITHM_MAX_ELEMENT__

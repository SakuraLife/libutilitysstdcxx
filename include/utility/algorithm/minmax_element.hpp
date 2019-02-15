
#ifndef __UTILITY_ALGORITHM_MINMAX_ELEMENT__
#define __UTILITY_ALGORITHM_MINMAX_ELEMENT__

#include<utility/config/utility_config.hpp>

#include<utility/algorithm/algorithm_auxiliary.hpp>

#include<utility/container/pair.hpp>

__utility_globalspace_start(utility)
__utility_interspace_start(algorithm)
  template<typename _ForwardIterator, typename _Compare>
  __UTILITY_CPP14_CONSTEXPR__
  container::pair<_ForwardIterator, _ForwardIterator>
  minmax_element(
    _ForwardIterator _first, _ForwardIterator _last, _Compare _comp
  )
  {
    using container::pair;
    pair<_ForwardIterator, _ForwardIterator> __minmax{_first, _first};

    if(_first == _last)
    { return __minmax;}

    if(_comp(*_first, *__minmax.first))
    { __minmax.first = _first;}
    else
    { __minmax.second = _first;}
    ++_first;

    for(; _first != _last; ++_first)
    {
      _ForwardIterator __tmp = _first;
      if(++_first == _last)
      {
        if(_comp(*__tmp, *__minmax.first))
        { __minmax.first = __tmp;}
        else if(_comp(*__minmax.second, *__tmp))
        { __minmax.second = __tmp;}
      }
      else
      {
        if(_comp(*_first, *__tmp))
        {
          if(_comp(*_first, *__minmax.first))
          { __minmax.first = _first;}
          if(_comp(*__minmax.second, *__tmp))
          { __minmax.second = __tmp;}
        }
        else
        {
          if(_comp(*__tmp, *__minmax.first))
          { __minmax.first = __tmp;}
          if(_comp(*__minmax.second, *_first))
          { __minmax.second = _first;}
        }
      }
    }

    return __minmax;
  }

  template<typename _ForwardIterator>
  __UTILITY_CPP14_CONSTEXPR__
  container::pair<_ForwardIterator, _ForwardIterator>
  minmax_element(_ForwardIterator _first, _ForwardIterator _last)
  { return minmax_element(_first, _last, less<void>{});}

__utility_interspace_end(algorithm)
__utility_globalspace_end(utility)


#endif // ! __UTILITY_ALGORITHM_MINMAX_ELEMENT__

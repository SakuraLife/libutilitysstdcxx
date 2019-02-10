
#ifndef __UTILITY_ITERATOR_NEXT__
#define __UTILITY_ITERATOR_NEXT__

#include<utility/config/utility_config.hpp>
#include<utility/iterator/iterator_tag.hpp>
#include<utility/iterator/iterator_traits.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(iterator)
  {
    namespace __detail
    {
      template<typename _Iterator,
        bool = is_vaild_iterator_type<_Iterator,random_access_iterator_tag>::value
      >
      struct __next
      {
        template<typename _Difference>
        __UTILITY_CPP17_CONSTEXPR__
        static inline _Iterator __aux(_Iterator _it, _Difference _len)
        {
          for(; _len; --_len)
          { ++_it;}
          return _it;
        }
      };
      template<typename _Iterator>
      struct __next<_Iterator, true>
      {
        template<typename _Difference>
        __UTILITY_CPP17_CONSTEXPR__
        static inline _Iterator __aux(_Iterator _it, _Difference _len)
        { return _it + _len;}
      };
    }
    template<typename _ForwardIterator>
    __UTILITY_CPP17_CONSTEXPR__
    inline
    _ForwardIterator next(_ForwardIterator _it,
      typename iterator_traits<_ForwardIterator>::difference_type _len = 1
    )
    { return __detail::__next<_ForwardIterator>::__aux(_it, _len);}
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ITERATOR_NEXT__

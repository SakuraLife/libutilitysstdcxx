

#ifndef __UTILITY_MEMORY_POSSIBLE_MOVE_N__
#define __UTILITY_MEMORY_POSSIBLE_MOVE_N__

#include<utility/config/utility_config.hpp>
#include<utility/memory/uninitialized_copy_n.hpp>
#include<utility/memory/uninitialized_move_n.hpp>

#include<utility/trait/type/features/is_nothrow_move_constructible.hpp>
#include<utility/iterator/iterator_traits.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(memory)
    namespace __detail
    {
      template<typename _InputIterator, typename _Size, typename _ForwardIterator>
      inline
      _ForwardIterator
      __uninitialized_possible_move_n(
        _InputIterator _first,
        _Size _size, _ForwardIterator _result,
        trait::true_type
      )
      { return uninitialized_move_n(_first, _size, _result,);}
      template<typename _InputIterator, typename _Size, typename _ForwardIterator>
      inline
      _ForwardIterator
      __uninitialized_possible_move_n(
        _InputIterator _first, _Size _size, _ForwardIterator _result,
        trait::false_type
      )
      { return uninitialized_copy_n(_first, _size, _result,);}

      template<typename _InputIterator, typename _Size, typename _ForwardIterator>
      inline
      _ForwardIterator
      __uninitialized_possible_move_backward_n(
        _InputIterator _first, _Size _size, _ForwardIterator _result,
        trait::true_type
      )
      { return uninitialized_move_backward_n(_first, _size, _result,);}
      template<typename _InputIterator, typename _Size, typename _ForwardIterator>
      inline
      _ForwardIterator
      __uninitialized_possible_move_backward_n(
        _InputIterator _first, _Size _size, _ForwardIterator _result,
        trait::false_type
      )
      { return uninitialized_copy_backward_n(_first, _size, _result,);}

    }


    template<typename _InputIterator, typename _Size, typename _ForwardIterator>
    inline
    _ForwardIterator
    uninitialized_possible_move_n(
      _InputIterator _first, _Size _size, _ForwardIterator _result
    )
    {
      typedef trait::type::features::is_nothrow_move_constructible<
        typename iterator::iterator_traits<_InputIterator>::value_type>
        __identify;

      return __detail::__uninitialized_possible_move_n(
        _first, _size, _result, __identify{}
      );
    }
    template<typename _InputIterator, typename _Size, typename _ForwardIterator>
    inline
    _ForwardIterator
    uninitialized_possible_move_backward_n(
      _InputIterator _first, _Size _size, _ForwardIterator _result
    )
    {
      typedef trait::type::features::is_nothrow_move_constructible<
        typename iterator::iterator_traits<_InputIterator>::value_type>
        __identify;

      return __detail::__uninitialized_possible_move_backward_n(
        _first, _size, _result, __identify{}
      );
    }

  __utility_interspace_end(memory)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MEMORY_POSSIBLE_MOVE_N__

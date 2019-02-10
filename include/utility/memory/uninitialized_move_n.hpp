
#ifndef __UTILITY_MEMORY_UNINITIALIZED_MOVE_N__
#define __UTILITY_MEMORY_UNINITIALIZED_MOVE_N__

#include<utility/config/utility_config.hpp>
#include<utility/algorithm/move.hpp>
#include<utility/memory/addressof.hpp>
#include<utility/iterator/iterator_traits.hpp>
#include<utility/sstd/new.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(memory)
  {
    /*!
    * \brief Move block of memory
    *
    * Constructs moves of the \a _size first elements of the array
    * pointed by \a _first into a range beginning at \a _result
    * and returns an iterator to the last element in the destination range.<br/>
    * \b uninitialized_copy constructs the objects in-place,
    * instead of just moving them. This allows to obtain fully constructed
    * moves of the elements into a range of uninitialized memory.
    *
    * \tparam _InputIterator,_ForwardIterator
    * \param _first  Forward iterator to the initial position in
    *         an uninitialized sequence of at least \a _size elements.
    * \param _size   Number of elements to move.
    * \param _result Output iterator to the initial position
    *         in the uninitialized destination sequence.
    *         This shall not point to any element in
    *         the range [\a _first, \a _first+\a _size).
    * \return
    * \attention If an exception is thrown during the initialization,
    *         the function has no effects. And the original source will be
    *         right but uncertain.
    * \see memory::uninitialized_move
    */
    template<typename _InputIterator, typename _Size, typename _ForwardIterator>
    _ForwardIterator
    uninitialized_move_n(_InputIterator _first, _Size _size, _ForwardIterator _result)
    {
      using memory::addressof;
      using algorithm::move;
      typedef typename
        iterator::iterator_traits<_ForwardIterator>::value_type
        __type;
      __UTILITY_TRY_DEFINE(_ForwardIterator, __epos, _result);
      __UTILITY_TRY_BEGIN
        for(; _size > 0; (void)++_first, ++_result, --_size)
        {
          ::new (static_cast<void*>(addressof(*_result)))
            __type(move(*_first));
        }
      __UTILITY_TRY_END
      __UTILITY_CATCH(...)
      __UTILITY_CATCH_UNWIND(
        for(; __epos != _result; ++__epos)
        { __epos->~__type();}
      )
      return _first;
    }
    template<typename _BidirIterator1, typename _Size, typename _BidirIterator2>
    _BidirIterator2
    uninitialized_move_backward_n(
      _BidirIterator1 _last, _Size _size, _BidirIterator2 _result
    )
    {
      using memory::addressof;
      using algorithm::move;
      typedef typename
        iterator::iterator_traits<_BidirIterator2>::value_type
        __type;
      _BidirIterator2 __epos = _result;
      __UTILITY_TRY_BEGIN
        for(; _size > 0; --_size)
        {
          ::new (static_cast<void*>(addressof(*--_result)))
            __type(move(*--_last));
        }
      __UTILITY_TRY_END
      __UTILITY_CATCH(...)
      __UTILITY_CATCH_UNWIND(
        for(; __epos != _result; )
        { (--__epos)->~__type();}
      )
      return __epos;
    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MEMORY_UNINITIALIZED_MOVE__

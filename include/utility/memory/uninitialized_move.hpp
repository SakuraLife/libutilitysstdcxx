
#ifndef __UTILITY_MEMORY_UNINITIALIZED_MOVE__
#define __UTILITY_MEMORY_UNINITIALIZED_MOVE__

#include<utility/config/utility_config.hpp>
#include<utility/algorithm/move.hpp>
#include<utility/memory/addressof.hpp>
#include<utility/iterator/iterator_traits.hpp>
#include<utility/sstd/new.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(memory)
    /*!
    * \brief Move block of memory
    *
    * Constructs moves of the elements in the range
    * [\a _first,\a _last) into a range beginning at result and
    * returns an iterator to the last element in the destination range.<br/>
    * \b uninitialized_move constructs the objects in-place,
    * instead of just moving them. This allows to obtain fully constructed
    * moves of the elements into a range of uninitialized memory
    *
    * \param _first,_last Input iterators to the initial and final positions
    *         in a sequence to be moved. The range used is [\a _first, \a last),
    *         which contains all the elements between \a _first and \a _last,
    *         including the element pointed by \a _first
    *         but not the element pointed by \a _last.
    * \param _result Output iterator to the initial position
    *         in the uninitialized destination sequence. This shall not
    *         point to any element in the range [\a__first, \a _last).
    * \return An iterator to the last element of the destination sequence
    *         where elements have been moved.
    * \attention If an exception is thrown during the initialization,
    *         the function has no effects. And the original source will be
    *         right but uncertain.
    * \see memory::uninitialized_move_n
    */
    template<typename _InputIterator, typename _ForwardIterator>
    _ForwardIterator
    uninitialized_move(
      _InputIterator _first, _InputIterator _last, _ForwardIterator _result
    )
    {
      using memory::addressof;
      using algorithm::move;
      typedef typename
        iterator::iterator_traits<_ForwardIterator>::value_type
        __type;
      __UTILITY_TRY_DEFINE(_ForwardIterator, __epos, _result);
      __UTILITY_TRY_BEGIN
        for(; _first != _last; (void)++_first, ++_result)
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
      return _result;
    }

    template<typename _BidirIterator1, typename _BidirIterator2>
    _BidirIterator2
    uninitialized_move_backward(
      _BidirIterator1 _first, _BidirIterator1 _last, _BidirIterator2 _result
    )
    {
      using memory::addressof;
      using algorithm::move;
      typedef typename
        iterator::iterator_traits<_BidirIterator2>::value_type
        __type;
      __UTILITY_TRY_DEFINE(_BidirIterator2, __epos, _result);
      __UTILITY_TRY_BEGIN
        for(; _first != _last;)
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
      return _result;
    }
  __utility_interspace_end(memory)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MEMORY_UNINITIALIZED_MOVE__

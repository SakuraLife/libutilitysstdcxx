
#ifndef __UTILITY_MEMORY_UNINITIALIZED_COPY__
#define __UTILITY_MEMORY_UNINITIALIZED_COPY__

#include<utility/config/utility_config.hpp>
#include<utility/memory/addressof.hpp>
#include<utility/trait/type/categories/is_arithmetic.hpp>
#include<utility/trait/type/categories/is_pointer.hpp>
#include<utility/trait/type/property/is_pod.hpp>
#include<utility/iterator/iterator_traits.hpp>
#include<utility/sstd/new.hpp>
#include<utility/sstd/cstring.hpp>

namespace utility
{
  namespace memory
  {
    namespace detail
    {
      template<typename _InputIterator, typename _ForwardIterator>
      _ForwardIterator
      __uninitialized_copy(_InputIterator _first,
        _InputIterator _last, _ForwardIterator _result,
        trait::false_type
      )
      {
        typedef typename
        iterator::iterator_traits<_ForwardIterator>::value_type
        __value_type;
        __UTILITY_TRY_DEFINE(_ForwardIterator, __epos, _result);
        __UTILITY_TRY_BEGIN
          for(; _first != _last; (void)++_first, ++_result)
          {
            ::new (static_cast<void*>(memory::addressof(*_result)))
            __value_type(*_first);
          }
        __UTILITY_TRY_END
        __UTILITY_CATCH(...)
        __UTILITY_CATCH_UNWIND(
          for(; __epos != _result; ++__epos)
          { __epos->~__value_type();}
        )
        return _result;
      }

      template<typename _InputIterator, typename _ForwardIterator>
      inline
      _ForwardIterator
      __uninitialized_copy(_InputIterator _first,
        _InputIterator _last, _ForwardIterator _result,
        trait::true_type
      )
      {
        typedef typename
          iterator::iterator_traits<_ForwardIterator>::value_type
          __value_type;
        sstd::memmove(
          _result, _first, (_last-_first)*sizeof(__value_type));
        return _result + (_last-_first);
      }

      template<typename _BidirIterator1, typename _BidirIterator2>
      _BidirIterator2
      __uninitialized_copy_backward(_BidirIterator1 _first,
        _BidirIterator1 _last, _BidirIterator2 _result,
        trait::false_type
      )
      {
        typedef typename
        iterator::iterator_traits<_BidirIterator2>::value_type
        __value_type;
        __UTILITY_TRY_DEFINE(_BidirIterator2, __epos, _result);
        __UTILITY_TRY_BEGIN
          for(; _first != _last;)
          {
            ::new (static_cast<void*>(memory::addressof(*--_result)))
            __value_type(*--_first);
          }
        __UTILITY_TRY_END
        __UTILITY_CATCH(...)
        __UTILITY_CATCH_UNWIND(
          for(; __epos != _result;)
          { (--__epos)->~__value_type();}
        )
        return _result;
      }

      template<typename _BidirIterator1, typename _BidirIterator2>
      inline
      _BidirIterator2
      __uninitialized_copy_backward(_BidirIterator1 _first,
        _BidirIterator1 _last, _BidirIterator2 _result,
        trait::true_type
      )
      {
        typedef typename
          iterator::iterator_traits<_BidirIterator2>::value_type
          __value_type;
        sstd::memmove(
          _result, _first, (_last-_first)*sizeof(__value_type)
        );
        return _result + (_last-_first);
      }
    }

    /*!
    * \brief Copy block of memory
    *
    * Constructs copies of the elements in the range
    * [\a _first,\a _last) into a range beginning at result and
    * returns an iterator to the last element in the destination range.<br/>
    * \b uninitialized_copy constructs the objects in-place,
    * instead of just copying them. This allows to obtain fully constructed
    * copies of the elements into a range of uninitialized memory
    *
    * \param _first,_last Input iterators to the initial and final positions
    *         in a sequence to be copied. The range used is [\a _first, \a last),
    *         which contains all the elements between \a _first and \a _last,
    *         including the element pointed by \a _first
    *         but not the element pointed by \a _last.
    * \param _result Output iterator to the initial position
    *         in the uninitialized destination sequence. This shall not
    *         point to any element in the range [\a__first, \a _last).
    * \return An iterator to the last element of the destination sequence
    *         where elements have been copied.
    * \attention If an exception is thrown during the initialization,
    *         the function has no effects.
    * \note   If the \a _ForwardIterator and \a _InputIterator are both pointer
    *         the memmove is used to speed up copying.
    * \see memory::uninitialized_copy_n
    */
    template<typename _InputIterator, typename _ForwardIterator>
    inline
    _ForwardIterator
    uninitialized_copy(_InputIterator _first,
      _InputIterator _last, _ForwardIterator _result)
    {
      typedef typename
      iterator::iterator_traits<_ForwardIterator>::value_type
      __value_type;
      typedef
        trait::integral_constant<bool,
          trait::type::categories::is_pointer<_InputIterator>::value &&
          trait::type::categories::is_pointer<_ForwardIterator>::value &&
          (trait::type::categories::is_arithmetic<__value_type>::value ||
           trait::type::categories::is_pointer<__value_type>::value ||
           trait::type::property::is_pod<__value_type>::value)>
        __identify;
      return detail::__uninitialized_copy(
        _first, _last, _result, __identify{}
      );
    }


    template<typename _BidirIterator1, typename _BidirIterator2>
    inline
    _BidirIterator2
    uninitialized_copy_backward(_BidirIterator1 _first,
      _BidirIterator1 _last, _BidirIterator2 _result)
    {
      typedef typename
      iterator::iterator_traits<_BidirIterator2>::value_type
      __value_type;
      typedef
        trait::integral_constant<bool,
          trait::type::categories::is_pointer<_BidirIterator1>::value &&
          trait::type::categories::is_pointer<_BidirIterator2>::value &&
          (trait::type::categories::is_arithmetic<__value_type>::value ||
           trait::type::categories::is_pointer<__value_type>::value ||
           trait::type::property::is_pod<__value_type>::value)>
        __identify;
      return detail::__uninitialized_copy_backward(
        _first, _last, _result, __identify{}
      );
    }
  }
}

#endif // ! __UTILITY_MEMORY_UNINITIALIZED_COPY__

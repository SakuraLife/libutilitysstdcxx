
#ifndef __UTILITY_MEMORY_UNINITIALIZED_COPY_N__
#define __UTILITY_MEMORY_UNINITIALIZED_COPY_N__

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
      template<typename _InputIterator, typename _Size, typename _ForwardIterator>
      _ForwardIterator
      __uninitialized_copy_n(
        _InputIterator _first, _Size _size, _ForwardIterator _result,
        trait::false_type
      )
      {
        using memory::addressof;
        typedef typename
          iterator::iterator_traits<_ForwardIterator>::value_type
          __type;
        __UTILITY_TRY_DEFINE(_ForwardIterator, __epos, _result);
        __UTILITY_TRY_BEGIN
          for(; _size > 0; (void)++_first, ++_result, --_size)
          {
            ::new (static_cast<void*>(addressof(*_result)))
            __type(*_first);
          }
        __UTILITY_TRY_END
        __UTILITY_CATCH(...)
        __UTILITY_CATCH_UNWIND(
          for(; __epos != _result; ++__epos)
          { __epos->~__type();}
        )
        return _result;
      }
      template<typename _InputIterator, typename _Size, typename _ForwardIterator>
      inline _ForwardIterator
      __uninitialized_copy_n(
        _InputIterator _first, _Size _size, _ForwardIterator _result,
        trait::true_type
      )
      {
        typedef typename
          iterator::iterator_traits<_ForwardIterator>::value_type
          __type;
        sstd::memmove(_result, _first, _size * sizeof(__type));
        return _result + _size;
      }

      template<typename _BidirIterator1, typename _Size, typename _BidirIterator2>
      _BidirIterator2
      __uninitialized_copy_backward_n(
        _BidirIterator1 _last, _Size _size, _BidirIterator2 _result,
        trait::false_type
      )
      {
        using memory::addressof;
        typedef typename iterator::iterator_traits<_BidirIterator2>::value_type
          __type;
        _BidirIterator2 __epos = _result;
        __UTILITY_TRY_BEGIN
          for(; _size > 0; --_size)
          {
            ::new (static_cast<void*>(addressof(*--_result))) __type(*--_last);
          }
        __UTILITY_TRY_END
        __UTILITY_CATCH(...)
        __UTILITY_CATCH_UNWIND(
          for(; __epos != _result;)
          { (--__epos)->~__type();}
        )
        return __epos;
      }
      template<typename _BidirIterator1, typename _Size, typename _BidirIterator2>
      _BidirIterator2
      __uninitialized_copy_backward_n(
        _BidirIterator1 _last, _Size _size, _BidirIterator2 _result,
        trait::true_type
      )
      {
        typedef typename
          iterator::iterator_traits<_ForwardIterator>::value_type
          __type;
        _Size __len = _size * sizeof(__type);
        sstd::memmove(_result-__len, _first-__len, __len);
        return _result;
      }

    }

    /*!
    * \brief Copy block of memory
    *
    * Constructs copies of the \a _size first elements of the array
    * pointed by \a _first into a range beginning at \a _result
    * and returns an iterator to the last element in the destination range.<br/>
    * \b uninitialized_copy constructs the objects in-place,
    * instead of just copying them. This allows to obtain fully constructed
    * copies of the elements into a range of uninitialized memory.
    *
    * \param _first  Forward iterator to the initial position in
    *         an uninitialized sequence of at least \a _size elements.
    * \param _size   Number of elements to copy.
    * \param _result Output iterator to the initial position
    *         in the uninitialized destination sequence.
    *         This shall not point to any element in
    *         the range [\a _first, \a _first+\a _size).
    * \return An iterator to the last element of the destination sequence
    *         where elements have been copied.
    * \attention If an exception is thrown during the initialization,
    *         the function has no effects.
    * \note   If the \a _ForwardIterator and \a _InputIterator are both pointer
    *         the memmove is used to speed up copying.
    * \see memory::uninitialized_copy
    */
    template<typename _InputIterator, typename _Size, typename _ForwardIterator>
    inline _ForwardIterator uninitialized_copy_n(
      _InputIterator _first, _Size _size, _ForwardIterator _result
    )
    {
      using trait::type::categories::is_pointer;
      using trait::type::categories::is_arithmetic;
      using trait::type::property::is_pod;
      typedef typename
        iterator::iterator_traits<_ForwardIterator>::value_type
        __type;
      typedef
        trait::integral_constant<bool,
          is_pointer<_InputIterator>::value &&
          is_pointer<_ForwardIterator>::value &&
          (is_arithmetic<__type>::value ||
           is_pointer<__type>::value ||
           is_pod<__type>::value)>
        __identify;
      return detail::__uninitialized_copy_n(
        _first, _size, _result, __identify{}
      );
    }

    template<typename _BidirIterator1, typename _Size, typename _BidirIterator2>
    inline _BidirIterator2 uninitialized_copy_backward_n(
      _BidirIterator1 _last, _Size _size, _BidirIterator1 _result
    )
    {
      using trait::type::categories::is_pointer;
      using trait::type::categories::is_arithmetic;
      using trait::type::property::is_pod;
      typedef typename
        iterator::iterator_traits<_BidirIterator2>::value_type
        __type;
      typedef
        trait::integral_constant<bool,
          is_pointer<_BidirIterator1>::value &&
          is_pointer<_BidirIterator2>::value &&
          (is_arithmetic<__type>::value ||
           is_pointer<__type>::value ||
           is_pod<__type>::value)>
        __identify;
      return detail::__uninitialized_copy_n(
        _last, _size, _result, __identify{}
      );
    }
  }
}

#endif // ! __UTILITY_MEMORY_UNINITIALIZED_COPY_N__

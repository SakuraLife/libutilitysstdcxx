
#ifndef __UTILITY_ALGORITHM_COPY__
#define __UTILITY_ALGORITHM_COPY__

#include<utility/config/utility_config.hpp>
#include<utility/trait/type/categories/is_pointer.hpp>
#include<utility/trait/type/property/is_pod.hpp>
#include<utility/iterator/iterator_traits.hpp>
#include<utility/sstd/cstring.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    namespace __detail
    {
      template<typename _InputIterator, typename _OutputIterator>
      _OutputIterator __copy(_InputIterator __first, _InputIterator __last,
        _OutputIterator __result, trait::false_type)
      {
        while(__first != __last)
        { *__result++ = *__first++;}
        return __result;
      }
      template<typename _InputIterator, typename _OutputIterator>
      _OutputIterator __copy(_InputIterator __first, _InputIterator __last,
        _OutputIterator __result, trait::true_type)
      {
        typedef typename
          iterator::iterator_traits<_OutputIterator>::value_type
          __value_type;
        sstd::memmove(
          __result, __first, (__last-__first)*sizeof(__value_type)
        );
        return __result + (__last-__first);
      }
    }
    /**
     * \brief Copy range of elements
     *
     * Copies the elements in the range, defined by [\a __first, \a __last),
     * to another range beginning at \a __result,
     *
     * \tparam _InputIterator   the input iterator type
     * \tparam _OutputIterator  the output iterator type
     * \param __first,__last  the range of elements to copy
     * \param __result        the beginning of the destination range.
     * \return Output iterator to the element in the destination range,
     *         one past the last element copied.
     * \warning The behavior is undefined if the source and the destination ranges overlap.
     */
    template<typename _InputIterator, typename _OutputIterator>
    inline _OutputIterator copy(
      _InputIterator __first, _InputIterator __last,
      _OutputIterator __result
    )
    {
      typedef typename
        iterator::iterator_traits<_OutputIterator>::value_type
        __value_type;
      typedef
        trait::integral_constant<bool,
          trait::type::categories::is_pointer<_InputIterator>::value &&
          trait::type::categories::is_pointer<_OutputIterator>::value &&
          (trait::type::property::is_pod<__value_type>::value)>
        __identify;
      return __detail::__copy(__first, __last, __result, __identify());
    }
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_COPY__

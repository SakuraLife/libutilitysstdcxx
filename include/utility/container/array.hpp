
#ifndef __UTILITY_CONTAINER_ARRAY__
#define __UTILITY_CONTAINER_ARRAY__

/**
 * \file array.hpp
 * \author Inochi Amaoto
 *
 */

#include<utility/config/utility_config.hpp>
#include<utility/container/container_helper.hpp>

#include<utility/algorithm/swap.hpp>
#include<utility/algorithm/possible_swap.hpp>
#include<utility/algorithm/equal.hpp>
#include<utility/algorithm/lexicographical_compare.hpp>

#include<utility/iterator/reverse_iterator.hpp>

#include<utility/trait/opt/__types__.hpp>
#include<utility/trait/opt/__types_op__.hpp>
#include<utility/trait/integer_sequence.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>
#include<utility/trait/type/transform/decay.hpp>
#include<utility/trait/type/features/is_nothrow_swappable.hpp>
#include<utility/trait/type/features/is_nothrow_possible_swappable.hpp>
#include<utility/trait/type/miscellaneous/common_type.hpp>
#include<utility/trait/operation/negation.hpp>
#include<utility/trait/operation/conjunction.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(container)
  {
    template<typename _T, size_t _N>
    class array
    {
      public:
        typedef _T                      value_type;
        typedef value_type&             reference;
        typedef const value_type&       const_reference;
        typedef value_type*             pointer;
        typedef const value_type*       const_pointer;

      public:
        typedef size_t       size_type;
        typedef ptrdiff_t    difference_type;

      public:
        typedef value_type*                       iterator;
        typedef const value_type*                 const_iterator;
        typedef helper::reverse_iterator<iterator>        reverse_iterator;
        typedef helper::reverse_iterator<const_iterator>  const_reverse_iterator;

      public:
        value_type __element[_N];

      public:

#ifdef __UTILITY_USE_EXCEPTION

        __UTILITY_CPP14_CONSTEXPR__
        reference at(size_type _pos)
        {
          if(_pos >= _N)
          { throw 1;}
          return __element[_pos];
        }
        __UTILITY_CPP14_CONSTEXPR__
        const_reference at(size_type _pos) const
        {
          if(_pos >= _N)
          { throw 1;}
          return __element[_pos];
        }

#endif // ! __UTILITY_USE_EXCEPTION

        __UTILITY_CPP14_CONSTEXPR__
        reference operator[](size_type _pos)
        { return __element[_pos];}
        __UTILITY_CPP14_CONSTEXPR__
        const_reference operator[](size_type _pos) const
        { return __element[_pos];}

      public:
        __UTILITY_CPP14_CONSTEXPR__
        iterator begin() noexcept
        { return __element;}
        __UTILITY_CPP14_CONSTEXPR__
        const_iterator begin() const noexcept
        { return __element;}
        __UTILITY_CPP14_CONSTEXPR__
        const_iterator cbegin() const noexcept
        { return __element;}
        __UTILITY_CPP14_CONSTEXPR__
        iterator end() noexcept
        { return __element+_N;}
        __UTILITY_CPP14_CONSTEXPR__
        const_iterator end() const noexcept
        { return __element+_N;}
        __UTILITY_CPP14_CONSTEXPR__
        const_iterator cend() const noexcept
        { return __element+_N;}

      public:
        __UTILITY_CPP14_CONSTEXPR__
        reverse_iterator rbegin() noexcept
        { return reverse_iterator{end()};}
        __UTILITY_CPP14_CONSTEXPR__
        const_reverse_iterator rbegin() const noexcept
        { return const_reverse_iterator{end()};}
        __UTILITY_CPP14_CONSTEXPR__
        const_reverse_iterator crbegin() const noexcept
        { return const_reverse_iterator{end()};}
        __UTILITY_CPP14_CONSTEXPR__
        reverse_iterator rend() noexcept
        { return reverse_iterator{begin()};}
        __UTILITY_CPP14_CONSTEXPR__
        const_reverse_iterator rend() const noexcept
        { return const_reverse_iterator{begin()};}
        __UTILITY_CPP14_CONSTEXPR__
        const_reverse_iterator crend() const noexcept
        { return const_reverse_iterator{begin()};}

      public:
        __UTILITY_CPP14_CONSTEXPR__
        reference front()
        { return *(__element);}
        __UTILITY_CPP14_CONSTEXPR__
        const_reference front() const
        { return *(__element);}
        __UTILITY_CPP14_CONSTEXPR__
        reference back()
        { return __element[_N-1];}
        __UTILITY_CPP14_CONSTEXPR__
        const_reference back() const
        { return __element[_N-1];}

      public:
        __UTILITY_CPP14_CONSTEXPR__
        value_type* data() noexcept
        { return __element;}
        __UTILITY_CPP14_CONSTEXPR__
        const value_type* data() const noexcept
        { return __element;}

      public:
        constexpr bool empty() const noexcept
        { return _N == 0U;}
        constexpr size_type size() const noexcept
        { return _N;}
        constexpr size_type max_size() const noexcept
        { return _N;}

      public:
        void fill(const value_type& _val)
        {
          pointer __fptr = __element;
          for(size_type __len = _N; __len; --__len)
          { *__element++ = _val;}
        }
        void swap(array& _other) noexcept(
          trait::type::features::is_nothrow_swappable<_T>::value
        )
        {
          using algorithm::swap;
          swap(__element, _other.__element);
        }
        void possible_swap(array& _other) noexcept(
          trait::type::features::is_nothrow_possible_swappable<_T>::value
        )
        {
          using algorithm::possible_swap;
          possible_swap(__element, _other.__element);
        }

    };

    template<typename _T, size_t _N>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator==(const array<_T, _N>& _x, const array<_T, _N>& _y)
    { return algorithm::equal(_x.begin(), _x.end(), _y.begin());}
    template<typename _T, size_t _N>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator!=(const array<_T, _N>& _x, const array<_T, _N>& _y)
    { return !(_x == _y);}
    template<typename _T, size_t _N>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator<(const array<_T, _N>& _x, const array<_T, _N>& _y)
    {
      return algorithm::lexicographical_compare(
        _x.begin(), _x.end(), _y.begin()
      );
    }
    template<typename _T, size_t _N>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator>(const array<_T, _N>& _x, const array<_T, _N>& _y)
    { return _y < _x;}
    template<typename _T, size_t _N>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator<=(const array<_T, _N>& _x, const array<_T, _N>& _y)
    { return !(_y < _x);}
    template<typename _T, size_t _N>
    __UTILITY_CPP14_CONSTEXPR__
    bool operator>=(const array<_T, _N>& _x, const array<_T, _N>& _y)
    { return !(_x < _y);}

    template<size_t _Idx, typename _T, size_t _N>
    __UTILITY_CPP14_CONSTEXPR__
    inline _T& get(array<_T, _N>& _array) noexcept
    {
      static_assert(_Idx < _N, "get<>(array&) index out of range.");
      return _array.__element[_Idx];
    }
    template<size_t _Idx, typename _T, size_t _N>
    __UTILITY_CPP14_CONSTEXPR__
    inline const _T& get(const array<_T, _N>& _array) noexcept
    {
      static_assert(_Idx < _N, "get<>(const array&) index out of range.");
      return _array.__element[_Idx];
    }
    template<size_t _Idx, typename _T, size_t _N>
    __UTILITY_CPP14_CONSTEXPR__
    inline _T&& get(array<_T, _N>&& _array) noexcept
    {
      using algorithm::move;
      static_assert(_Idx < _N, "get<>(array&&) index out of range.");
      return move(_array.__element[_Idx]);
    }
    template<size_t _Idx, typename _T, size_t _N>
    __UTILITY_CPP14_CONSTEXPR__
    inline const _T&& get(const array<_T, _N>&& _array) noexcept
    {
      using algorithm::move;
      static_assert(_Idx < _N, "get<>(const array&&) index out of range.");
      return move(_array.__element[_Idx]);
    }

    namespace __detail
    {
      using trait::make_index_sequence;
      using trait::index_sequence;
      using trait::operation::negation;
      using trait::operation::conjunction;
      using trait::type::transform::remove_cv_t;
      using trait::type::transform::decay_t;
      using trait::type::miscellaneous::common_type;
      using trait::__opt__::__is_reference_wrapper__;

      template<typename _T>
      using __not_ref_wrapper = negation<
        __is_reference_wrapper__<decay_t<_T>>
      >;

      template<typename _Target, typename...>
      struct __return_type
      { typedef _Target type;};
      template<typename... _Types>
      struct __return_type<void, _Types...>: common_type<_Types...>
      {
        static_assert(
          conjunction<__not_ref_wrapper<_Types>...>::value,
          "_Types can't contain reference_wrappers if _Target is void"
        );
      };

      template<typename _Target, typename... _Types>
      using __make_array_return_type = array<
        typename __return_type<_Target, _Types...>::type, sizeof...(_Types)
      >;

      template<typename _T, size_t _N, size_t... _Idx>
      __UTILITY_CPP14_CONSTEXPR__
      array<remove_cv_t<_T>, _N> __to_array(
        _T(&_array)[_N], index_sequence<_Idx...>
      )
      { return {{_array[_Idx]...}};}
    }

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++11-narrowing"
#endif // ! __clang__

    template<typename _Target = void, typename... _Args>
    __UTILITY_CPP14_CONSTEXPR__
    __detail::__make_array_return_type<_Target, _Args...>
    make_array(_Args&&... _args)
    {
      using algorithm::forward;
      return {{forward<_Args>(_args)...}};
    }

#ifdef __clang__
#pragma clang diagnostic pop
#endif // ! __clang__

    template<typename _T, size_t _N>
    __UTILITY_CPP14_CONSTEXPR__
    inline array<__detail::remove_cv_t<_T>, _N> to_array(_T(&_array)[_N])
    {
      return __detail::__to_array(
        _array, __detail::make_index_sequence<_N>{}
      );
    }

    template<typename _T>
    struct tuple_size;

    template<typename _T, size_t _N>
    struct tuple_size<array<_T, _N>>:
      public trait::integral_constant<size_t, _N>
    { };

    template<size_t _Idx, typename _T>
    struct tuple_element;

    template<size_t _Idx, typename _T, size_t _N>
    struct tuple_element<_Idx, array<_T, _N>>
    {
      private:
        static_assert(
          _Idx < _N,
          "index out of range for tuple_element<_Idx, array<_T, _N>>"
        );

      public:
        typedef _T type;
    };

  }

   __utility_interspace_start(trait)
  {
    namespace __opt__
    {
      template<typename _T, size_t _N>
      struct __checkout_type_feature__<container::array<_T, _N>>
      {
        typedef typename __type_tuple_get_array__<
          make_index_sequence<_N>, __type_array__<_T, _N>
        >::type type;
      };
      template<typename _T, size_t _N>
      struct  __type_tuple_size__<container::array<_T, _N>>
      { constexpr static size_t value = 1;};
    }
  }

   __utility_interspace_start(algorithm)
  {
    template<typename _T, size_t _N>
    void swap(
      container::array<_T, _N>& _x, container::array<_T, _N>& _y
    ) noexcept(noexcept(_x.swap(_y)))
    { _x.swap(_y);}
    template<typename _T, size_t _N>
    void possible_swap(
      container::array<_T, _N>& _x, container::array<_T, _N>& _y
    ) noexcept(noexcept(_x.possible_swap(_y)))
    { _x.possible_swap(_y);}
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CONTAINER_ARRAY__

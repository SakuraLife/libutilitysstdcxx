
#ifndef ___UTILITY__ALGORITHM__ALGORITHM__AUXILIARY___
#define ___UTILITY__ALGORITHM__ALGORITHM__AUXILIARY___

#include<utility/config/utility_config.hpp>

#include<utility/algorithm/forward.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS plus
    {
      __UTILITY_CPP14_CONSTEXPR__
      _T operator()(const _T& _x, const _T& _y) const
      { return _x + _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS minus
    {
      __UTILITY_CPP14_CONSTEXPR__
      _T operator()(const _T& _x, const _T& _y) const
      { return _x - _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS multiplies
    {
      __UTILITY_CPP14_CONSTEXPR__
      _T operator()(const _T& _x, const _T& _y) const
      { return _x * _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS divides
    {
      __UTILITY_CPP14_CONSTEXPR__
      _T operator()(const _T& _x, const _T& _y) const
      { return _x / _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS modulus
    {
      __UTILITY_CPP14_CONSTEXPR__
      _T operator()(const _T& _x, const _T& _y) const
      { return _x % _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS negate
    {
      __UTILITY_CPP14_CONSTEXPR__
      _T operator()(const _T& _x) const
      { return -_x;}
    };

    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS equal_to
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x, const _T& _y) const
      { return _x == _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS not_equal_to
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x, const _T& _y) const
      { return _x != _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS less
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x, const _T& _y) const
      { return _x < _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS less_equal
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x, const _T& _y) const
      { return _x <= _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS greater
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x, const _T& _y) const
      { return _x > _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS greater_equal
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x, const _T& _y) const
      { return _x >= _y;}
    };

    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS logical_and
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x, const _T& _y) const
      { return _x && _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS logical_or
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x, const _T& _y) const
      { return _x || _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS logical_not
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x) const
      { return !_x;}
    };

    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS bit_and
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x, const _T& _y) const
      { return _x & _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS bit_or
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x, const _T& _y) const
      { return _x | _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS bit_xor
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x, const _T& _y) const
      { return _x ^ _y;}
    };
    template<typename _T = void>
    struct __UTILITY_TEMPLATE_VIS bit_not
    {
      __UTILITY_CPP14_CONSTEXPR__
      bool operator()(const _T& _x) const
      { return ~_x;}
    };

    template<>
    struct __UTILITY_TYPE_VIS plus<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) + forward<_U>(_y))
      { return forward<_T>(_x) + forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS minus<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) - forward<_U>(_y))
      { return forward<_T>(_x) - forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS multiplies<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) * forward<_U>(_y))
      { return forward<_T>(_x) * forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS divides<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) / forward<_U>(_y))
      { return forward<_T>(_x) / forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS modulus<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) % forward<_U>(_y))
      { return forward<_T>(_x) % forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS negate<void>
    {
      template<typename _T>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x) const
        ->decltype(-forward<_T>(_x))
      { return -forward<_T>(_x);}
    };

    template<>
    struct __UTILITY_TYPE_VIS equal_to<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) == forward<_U>(_y))
      { return forward<_T>(_x) == forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS not_equal_to<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) != forward<_U>(_y))
      { return forward<_T>(_x) != forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS greater<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) > forward<_U>(_y))
      { return forward<_T>(_x) > forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS less<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) < forward<_U>(_y))
      { return forward<_T>(_x) < forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS greater_equal<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) >= forward<_U>(_y))
      { return forward<_T>(_x) >= forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS less_equal<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) <= forward<_U>(_y))
      { return forward<_T>(_x) <= forward<_U>(_y);}
    };

    template<>
    struct __UTILITY_TYPE_VIS logical_and<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) && forward<_U>(_y))
      { return forward<_T>(_x) && forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS logical_or<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) || forward<_U>(_y))
      { return forward<_T>(_x) || forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS logical_not<void>
    {
      template<typename _T>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x) const
        ->decltype(!forward<_T>(_x))
      { return !forward<_T>(_x);}
    };

    template<>
    struct __UTILITY_TYPE_VIS bit_and<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) & forward<_U>(_y))
      { return forward<_T>(_x) & forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS bit_or<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) | forward<_U>(_y))
      { return forward<_T>(_x) | forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS bit_xor<void>
    {
      template<typename _T, typename _U>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x, _U&& _y) const
        ->decltype(forward<_T>(_x) ^ forward<_U>(_y))
      { return forward<_T>(_x) ^ forward<_U>(_y);}
    };
    template<>
    struct __UTILITY_TYPE_VIS bit_not<void>
    {
      template<typename _T>
      __UTILITY_CPP14_CONSTEXPR__
      auto operator()(_T&& _x) const
        ->decltype(~forward<_T>(_x))
      { return ~forward<_T>(_x);}
    };
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__ALGORITHM__ALGORITHM__AUXILIARY___

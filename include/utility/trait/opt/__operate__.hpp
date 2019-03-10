
#ifndef __UTILITY_TRAIT_OPT___OPERATE___
#define __UTILITY_TRAIT_OPT___OPERATE___

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    namespace __opt__
    {
      template<typename _T, _T... _Vals>
      struct __UTILITY_TYPE_VIS __value_and__;
      template<typename _T, _T _Val>
      struct __UTILITY_TYPE_VIS __value_and__<_T, _Val>
      {
        typedef _T value_type;
        constexpr static value_type value = _Val;
      };
      template<typename _T, _T _Val, _T... _Vals>
      struct __UTILITY_TYPE_VIS __value_and__<_T, _Val, _Vals...>
      {
        typedef _T value_type;
        constexpr static value_type value =
          _Val & __value_and__<_T, _Vals...>::value;
      };

      template<typename _T, _T... _Vals>
      struct __UTILITY_TYPE_VIS __value_or__;
      template<typename _T, _T _Val>
      struct __UTILITY_TYPE_VIS __value_or__<_T, _Val>
      {
        typedef _T value_type;
        constexpr static value_type value = _Val;
      };
      template<typename _T, _T _Val, _T... _Vals>
      struct __UTILITY_TYPE_VIS __value_or__<_T, _Val, _Vals...>
      {
        typedef _T value_type;
        constexpr static value_type value =
          _Val | __value_or__<_T, _Vals...>::value;
      };
      template<typename _T, _T... _Vals>
      struct __UTILITY_TYPE_VIS __value_xor__;
      template<typename _T, _T _Val>
      struct __UTILITY_TYPE_VIS __value_xor__<_T, _Val>
      {
        typedef _T value_type;
        constexpr static value_type value = _Val;
      };
      template<typename _T, _T _Val, _T... _Vals>
      struct __UTILITY_TYPE_VIS __value_xor__<_T, _Val, _Vals...>
      {
        typedef _T value_type;
        constexpr static value_type value =
          _Val ^ __value_xor__<_T, _Vals...>::value;
      };
    }
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)



#endif // ! __UTILITY_TRAIT_OPT___OPERATE___

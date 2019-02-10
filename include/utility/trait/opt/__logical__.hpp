
#ifndef __UTILITY_TRAIT_OPT___LOGICAL___
#define __UTILITY_TRAIT_OPT___LOGICAL___

#include<utility/config/utility_config.hpp>
#include<utility/trait/opt/__constant__.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
    namespace __opt__
    {
      template<bool _B>
      struct __not__;
      template<>
      struct __not__<true>: public __false__
      { };
      template<>
      struct __not__<false>: public __true__
      { };

      template<bool... _LB>
      struct __and__;
      template<>
      struct __and__<>: public __true__
      { };
      template<bool... _LB>
      struct __and__<true, _LB...>: public __and__<_LB...>
      { };
      template<bool... _LB>
      struct __and__<false, _LB...>: public __false__
      { };
      template<>
      struct __and__<false>: public __false__
      { };
      template<>
      struct __and__<true>: public __true__
      { };

      template<bool... _LB>
      struct __or__;
      template<>
      struct __or__<>: public __false__
      { };
      template<bool... _LB>
      struct __or__<true, _LB...>: public __true__
      { };
      template<bool... _LB>
      struct __or__<false, _LB...>: public __or__<_LB...>
      { };
      template<>
      struct __or__<false>: public __false__
      { };
      template<>
      struct __or__<true>: public __true__
      { };

      template<bool... _LB>
      struct __xor__;
      template<>
      struct __xor__<>: public __true__
      { };
      template<>
      struct __xor__<true>: public __true__
      { };
      template<>
      struct __xor__<false>: public __false__
      { };
      template<bool _B1, bool _B2>
      struct __xor__<_B1, _B2>: public __true__
      { };
      template<>
      struct __xor__<true, true>: public __false__
      { };
      template<>
      struct __xor__<false, false>: public __false__
      { };
      template<bool _B, bool... _LB>
      struct __xor__<_B, _LB...>: public __xor__<_B, __xor__<_LB...>::value>
      { };

      template<typename _T>
      struct __type_not__: public __not__<bool(_T::value)>
      { };

      template<bool _B = true, typename... _Ts>
      struct __type_and_impl__;
      template<>
      struct __type_and_impl__<true>: public __true__
      { };
      template<>
      struct __type_and_impl__<false>: public __false__
      { };
      template<typename _T, typename... _Ts>
      struct __type_and_impl__<true, _T, _Ts...>:
        public __type_and_impl__<bool(_T::value), _Ts...>
      { };
      template<typename _T, typename... _Ts>
      struct __type_and_impl__<false, _T, _Ts...>: public __false__
      { };

      template<bool _B = false, typename... _Ts>
      struct __type_or_impl__;
      template<>
      struct __type_or_impl__<true>: public __true__
      { };
      template<>
      struct __type_or_impl__<false>: public __false__
      { };
      template<typename _T, typename... _Ts>
      struct __type_or_impl__<true, _T, _Ts...>: public __true__
      { };
      template<typename _T, typename... _Ts>
      struct __type_or_impl__<false, _T, _Ts...>:
        public __type_or_impl__<bool(_T::value), _Ts...>
      { };
      template<typename... _Ts>
      struct __type_and__;
      template<>
      struct __type_and__<>: public __true__
      { };
      template<typename _T, typename... _Ts>
      struct __type_and__<_T, _Ts...>: __type_and_impl__<true, _T, _Ts...>
      { };
      template<typename... _Ts>
      struct __type_or__;
      template<>
      struct __type_or__<>: public __true__
      { };
      template<typename _T, typename... _Ts>
      struct __type_or__<_T, _Ts...>: __type_or_impl__<false, _T, _Ts...>
      { };
    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_OPT___LOGICAL___

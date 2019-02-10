
#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_FUNCTION__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_FUNCTION__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(categories)
      {
        // is_function
        template<typename>
        struct is_function: public false_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args...)>: public true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args...) &>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args...) &&>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args..., ...)>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args..., ...) &>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args..., ...) &&>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args...) const>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args...) const &>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args...) const &&>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args..., ...) const>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args..., ...) const &>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args..., ...) const &&>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args...) volatile>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args...) volatile &>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args...) volatile &&>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args..., ...) volatile>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args..., ...) volatile &>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args..., ...) volatile &&>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args...) const volatile>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args...) const volatile &>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args...) const volatile &&>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args..., ...) const volatile>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args..., ...) const volatile &>:
          public trait::true_type
        { };
        template<typename _Fn, typename... _Args>
        struct is_function<_Fn(_Args..., ...) const volatile &&>:
          public trait::true_type
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_function_v = is_function<_T>::value;
#endif

      }
    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_TYPE_CATEGORIES_IS_FUNCTION__

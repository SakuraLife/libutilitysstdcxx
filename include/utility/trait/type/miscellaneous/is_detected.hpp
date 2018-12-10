
#ifndef __UTILITY_TRAIT_TYPE_MISCELLANEOUS_IS_DETECTED__
#define __UTILITY_TRAIT_TYPE_MISCELLANEOUS_IS_DETECTED__

#include<utility/trait/trait_helper.hpp>

#include<utility/trait/opt/__none__.hpp>
#include<utility/trait/type/releations/is_same.hpp>
#include<utility/trait/type/releations/is_convertible.hpp>

#define ___utility_cpp_lib_detect 201505L

#ifndef UTILITY_NEED_EXPERIMENTAL
# define __cpp_lib_experimental_detect 201505L
#endif // ! UTILITY_NEED_EXPERIMENTAL

namespace utility
{
  namespace trait
  {
    namespace type
    {
      namespace miscellaneous
      {
        namespace __detail
        {
          template<typename _Default, typename _Void, template<typename...> class _Op, typename... _Args>
          struct __detector
          {
            typedef false_type      value_t;
            typedef _Default        type;
          };
          template<typename _Default, template<typename...> class _Op, typename... _Args>
          struct __detector<_Default, void_t<_Op<_Args...>>, _Op, _Args...>
          {
            typedef true_type       value_t;
            typedef _Op<_Args...>   type;
          };
        }

        typedef __opt__::__none__ nonesuch;
        template<template<typename...> class _Op, typename... _Args>
        using is_detected = typename __detail::__detector<nonesuch, void, _Op, _Args...>::value_t;

        template<template<typename...> class _Op, typename... _Args>
        using detected_t = typename __detail::__detector<nonesuch, void, _Op, _Args...>::type;

        template<typename _Default, template<typename...> class _Op, typename... _Args>
        using detected_or = __detail::__detector<_Default, void, _Op, _Args...>;

        template<typename _Default, template<typename...> class _Op, typename... _Args>
        using detected_or_t = typename __detail::__detector<_Default, void, _Op, _Args...>::type;

        template<typename _Expected, template<typename...> class _Op, typename... _Args>
        using is_detected_exact = releations::is_same<detected_t<_Op, _Args...>, _Expected>;

        template<typename _Expected, template<typename...> class _Op, typename... _Args>
        using is_detected_expect = releations::is_same<detected_t<_Op, _Args...>, _Expected>;

        template<typename _To, template<typename...> class _Op, typename... _Args>
        using is_detected_convertible = releations::is_convertible<detected_t<_Op, _Args...>, _To>;

#ifndef __UTILITY_NO_CPP14__
        template<template<typename...> class _Op, typename... _Args>
        __UTILITY_CPP17_INLINE__
        constexpr bool is_detected_v = is_detected<_Op, _Args...>::value;
        template<typename _Expected, template<typename...> class _Op, typename... _Args>
        __UTILITY_CPP17_INLINE__
        constexpr bool is_detected_exact_v = is_detected_exact<_Expected, _Op, _Args...>::value;
        template<typename _Expected, template<typename...> class _Op, typename... _Args>
        __UTILITY_CPP17_INLINE__
        constexpr bool is_detected_expect_v = is_detected_exact<_Expected, _Op, _Args...>::value;
        template<typename _To, template<typename...> class _Op, typename... _Args>
        __UTILITY_CPP17_INLINE__
        constexpr bool is_detected_convertible_v = is_detected_convertible<_To, _Op, _Args...>::value;

#endif // ! __UTILITY_NO_CPP14__

      }
    }
  }
}

#endif // ! __UTILITY_TRAIT_TYPE_MISCELLANEOUS_IS_DETECTED__

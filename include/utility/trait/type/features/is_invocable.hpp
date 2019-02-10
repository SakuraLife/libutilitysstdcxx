
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_INVOCABLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_INVOCABLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/opt/__logical__.hpp>
#include<utility/trait/type/miscellaneous/invoke_result.hpp>
#include<utility/trait/type/releations/is_convertible.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(features)
      {
        namespace __invoke_related
        {
          using namespace trait::type::miscellaneous::__invoke_related;
          using trait::void_t;
          using trait::__opt__::__type_and__;
          using trait::type::releations::is_convertible;

          template<bool/*Select*/, typename _Res, typename _T, typename = void>
          struct __is_invocable_helper: public false_type
          { };
          template<typename _Res, typename _T>
          struct __is_invocable_helper<
            false, _Res, _T, void_t<typename _Res::type>
          >: public true_type
          { };
          template<typename _Res, typename _T>
          struct __is_invocable_helper<true, _Res, _T, void_t<typename _Res::type>>:
            public integral_constant<bool,
              is_convertible<typename _Res::type, _T>::value
            >
          { };

          template<typename _Tag, typename _Fn, typename... _Args>
          struct __is_noexcept_invoke_test
          { constexpr static bool value = false;};
          template<typename _Fn, typename _Arg, typename... _Args>
          struct __is_noexcept_invoke_test<__invoke_member_function_unpacked, _Fn, _Arg, _Args...>
          {
            private:
              typedef typename __wrapper__<_Arg, decay_t<_Arg>>::type _Ori;
            public:
              constexpr static bool value = noexcept(((declval<_Ori>()).*declval<_Fn>())(declval<_Args>()...));
          };
          template<typename _Fn, typename _Arg, typename... _Args>
          struct __is_noexcept_invoke_test<__invoke_member_function_packed, _Fn, _Arg, _Args...>
          {
            public:
              constexpr static bool value = noexcept(((*declval<_Arg>()).*declval<_Fn>())(declval<_Args>()...));
          };
          template<typename _Fn, typename _Arg, typename... _Args>
          struct __is_noexcept_invoke_test<__invoke_member_object_unpacked, _Fn, _Arg, _Args...>
          {
            private:
              typedef typename __wrapper__<_Arg, decay_t<_Arg>>::type _Ori;
            public:
              constexpr static bool value = noexcept(declval<_Ori>().*declval<_Fn>());
          };
          template<typename _Fn, typename _Arg, typename... _Args>
          struct __is_noexcept_invoke_test<__invoke_member_object_packed, _Fn, _Arg, _Args...>
          {
            public:
              constexpr static bool value = noexcept((*declval<_Arg>()).*declval<_Fn>());
          };
          template<typename _Fn, typename... _Args>
          struct __is_noexcept_invoke_test<__invoke_operators, _Fn, _Args...>
          {
            public:
              constexpr static bool value = noexcept(declval<_Fn>()(declval<_Args>()...));
          };

        }
        // is_invocable
        template<class _Fn, typename... _ArgTypes>
        struct is_invocable:
          public __invoke_related::__is_invocable_helper<
            false, typename __invoke_related::__invoke_result<_Fn, _ArgTypes...>::type,
            void>
        { };

        // is_invocable_r
        template<typename _R, class _Fn, typename... _ArgTypes>
        struct is_invocable_r:
          public __invoke_related::__is_invocable_helper<
            true, typename __invoke_related::__invoke_result<_Fn, _ArgTypes...>::type,
            _R>
        { };

        // is_nothrow_invocable
        template<class _Fn, typename... _ArgTypes>
        struct is_nothrow_invocable:
          public __invoke_related::__type_and__<is_invocable<_Fn, _ArgTypes...>,
            __invoke_related::__is_noexcept_invoke_test<
              typename __invoke_related::__invoke_result<_Fn, _ArgTypes...>::invoke_tag,
              _Fn, _ArgTypes...>
          >
        { };

        // is_nothrow_invocable_r
        template<typename _R, class _Fn, typename... _ArgTypes>
        struct is_nothrow_invocable_r:
          public __invoke_related::__type_and__<is_invocable_r<_R, _Fn, _ArgTypes...>,
            __invoke_related::__is_noexcept_invoke_test<
              typename __invoke_related::__invoke_result<_Fn, _ArgTypes...>::invoke_tag,
              _Fn, _ArgTypes...>
          >
        { };

      }
    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_TYPE_FEATURES_IS_INVOCABLE__

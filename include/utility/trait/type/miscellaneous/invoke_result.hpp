
#ifndef __UTILITY_TRAIT_TYPE_MISCELLANEOUS_INVOKE_RESULT__
#define __UTILITY_TRAIT_TYPE_MISCELLANEOUS_INVOKE_RESULT__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/opt/__empty__.hpp>
#include<utility/trait/opt/__result__.hpp>
#include<utility/trait/opt/__logical__.hpp>
#include<utility/trait/type/type_trait_special.hpp>
#include<utility/trait/type/categories/is_member_function_pointer.hpp>
#include<utility/trait/type/categories/is_member_object_pointer.hpp>
#include<utility/trait/type/transform/decay.hpp>
#include<utility/trait/type/transform/remove_cv_ref.hpp>
#include<utility/trait/type/releations/is_same.hpp>
#include<utility/trait/type/releations/is_base_of.hpp>
#include<utility/trait/type/miscellaneous/conditional.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(miscellaneous)
      {
        namespace __invoke_related
        {
          using trait::__opt__::__type_success__;
          using trait::__opt__::__wrapper__;
          using trait::__opt__::__empty__;
          using trait::__opt__::__type_or__;
          using trait::type::categories::is_member_function_pointer;
          using trait::type::categories::is_member_object_pointer;
          using trait::type::releations::is_same;
          using trait::type::releations::is_base_of;
          using trait::type::special::declval;
          using trait::type::transform::decay_t;
          using trait::type::transform::remove_cv_ref_t;

          // invoke tags
          struct __invoke_member_function_unpacked;
          struct __invoke_member_function_packed;
          struct __invoke_member_object_unpacked;
          struct __invoke_member_object_packed;
          struct __invoke_operators;
          struct __invoke_failed;

          struct __invoke_member_function_unpacked
          { };
          struct __invoke_member_function_packed
          { };
          struct __invoke_member_object_unpacked
          { };
          struct __invoke_member_object_packed
          { };
          struct __invoke_operators
          { };
          struct __invoke_failed
          { };

          template<typename _T, typename _Invoke_Tag>
          struct __invoke_process
          {
            typedef _T type;
            typedef _Invoke_Tag invoke_tag;
          };

          template<typename _Fn, typename _Arg, typename... _Args>
          struct __invoke_member_function_unpacked_helper
          {
            private:
              template<typename __Fn, typename __Arg, typename... __Args>
              static __invoke_process<__type_success__<decltype(((declval<__Arg>()).*declval<__Fn>())(declval<__Args>()...))>, __invoke_member_function_unpacked> __test(int);
              template<typename __Fn, typename __Arg, typename... __Args>
              static __invoke_process<__empty__, __invoke_failed> __test(...);

            public:
              typedef decltype(__test<_Fn, _Arg, _Args...>(0)) type;
          };
          template<typename _Fn, typename _Arg, typename... _Args>
          struct __invoke_member_function_packed_helper
          {
            private:
              template<typename __Fn, typename __Arg, typename... __Args>
              static __invoke_process<__type_success__<decltype(((*declval<__Arg>()).*declval<__Fn>())(declval<__Args>()...))>, __invoke_member_function_packed> __test(int);
              template<typename __Fn, typename __Arg, typename... __Args>
              static __invoke_process<__empty__, __invoke_failed> __test(...);

            public:
              typedef decltype(__test<_Fn, _Arg, _Args...>(0)) type;
          };
          template<typename _Fn, typename _Arg, typename... _Args>
          struct __invoke_member_function_helper
          { typedef __invoke_process<__empty__, __invoke_failed> type;};
          template<typename _Res, typename _Class, typename _Arg, typename... _Args>
          struct __invoke_member_function_helper<_Res _Class::*, _Arg, _Args...>
          {
            private:
              typedef remove_cv_ref_t<_Arg> _Argval;
              typedef _Res _Class::* _Fn;

            public:
              typedef typename conditional<
                __type_or__<
                  is_same<_Argval, _Class>,
                  is_base_of<_Class, _Argval>
                >::value,
                __invoke_member_function_unpacked_helper<_Fn, _Arg, _Args...>,
                __invoke_member_function_packed_helper<_Fn, _Arg, _Args...>
              >::type::type type;
          };

          template<typename _Fn, typename _Arg>
          struct __invoke_member_object_unpacked_helper
          {
            private:
              template<typename __Fn, typename __Arg>
              static __invoke_process<__type_success__<decltype(declval<__Arg>().*declval<__Fn>())>, __invoke_member_object_unpacked> __test(int);
              template<typename __Fn, typename __Arg>
              static __invoke_process<__empty__, __invoke_failed> __test(...);

            public:
              typedef decltype(__test<_Fn, _Arg>(0)) type;
          };
          template<typename _Fn, typename _Arg>
          struct __invoke_member_object_packed_helper
          {
            private:
              template<typename __Fn, typename __Arg>
              static __invoke_process<__type_success__<decltype((*declval<__Arg>()).*declval<__Fn>())>, __invoke_member_object_packed> __test(int);
              template<typename __Fn, typename __Arg>
              static __invoke_process<__empty__, __invoke_failed> __test(...);

            public:
              typedef decltype(__test<_Fn, _Arg>(0)) type;
          };
          template<typename _Fn, typename _Arg>
          struct __invoke_member_object_helper
          { typedef __invoke_process<__empty__, __invoke_failed> type;};
          template<typename _Res, typename _Class, typename _Arg>
          struct __invoke_member_object_helper<_Res _Class::*, _Arg>
          {
            private:
              typedef remove_cv_ref_t<_Arg> _Argval;
              typedef _Res _Class::* _Fn;

            public:
              typedef typename conditional<
                __type_or__<
                  is_same<_Argval, _Class>,is_base_of<_Class, _Argval>
                >::value,
                __invoke_member_object_unpacked_helper<_Fn, _Arg>,
                __invoke_member_object_packed_helper<_Fn, _Arg>
              >::type::type type;
          };

          template<typename _Fn, typename... _Args>
          struct __invoke_operators_helper
          {
            private:
              template<typename __Fn, typename... __Args>
              static __invoke_process<__type_success__<decltype(declval<__Fn>()(declval<__Args>()...))>, __invoke_operators> __test(int);
              template<typename __Fn, typename... __Args>
              static __invoke_process<__empty__, __invoke_failed> __test(...);

            public:
              typedef decltype(__test<_Fn, _Args...>(0)) type;
          };


          template<bool/*member_function*/, bool/*member_object*/,
            typename _Fn, typename... _Args>
          struct __invoke_result_helper:
            public __invoke_process<__empty__, __invoke_failed>
          { };

          template<typename _Fn, typename... _Args>
          struct __invoke_result_helper<true, false, _Fn, _Args...>:
            public __invoke_process<__empty__, __invoke_failed>
          { };
          template<typename _Fn, typename _Arg, typename... _Args>
          struct __invoke_result_helper<true, false, _Fn, _Arg, _Args...>:
            public __invoke_member_function_helper<
              decay_t<_Fn>,
              typename __wrapper__<_Arg, decay_t<_Arg>>::type,
              _Args...>::type
          { };

          template<typename _Fn, typename... _Args>
          struct __invoke_result_helper<false, true, _Fn, _Args...>:
            public __invoke_process<__empty__, __invoke_failed>
          { };
          template<typename _Fn, typename _Arg, typename... _Args>
          struct __invoke_result_helper<false, true, _Fn, _Arg, _Args...>:
            public __invoke_member_object_helper<
              decay_t<_Fn>,
              typename __wrapper__<_Arg, decay_t<_Arg>>::type
            >::type
          { };

          template<typename _Fn, typename... _Args>
          struct __invoke_result_helper<false, false, _Fn, _Args...>:
            public __invoke_operators_helper<_Fn, _Args...>::type
          { };

          template<typename _Fn, typename... _Args>
          struct __invoke_result: public __invoke_result_helper<
              is_member_function_pointer<_Fn>::value,
              is_member_object_pointer<_Fn>::value,
              _Fn, _Args...
            >
          { };

        }
        // result_of
        template<typename _T>
        struct result_of;
        template<typename _Fn, typename... _ArgTypes>
        struct result_of<_Fn(_ArgTypes...)>:
          public __invoke_related::__invoke_result<_Fn, _ArgTypes...>::type
        { };

        // invoke_result
        template<typename _Fn, typename... _ArgTypes>
        struct invoke_result:
          public __invoke_related::__invoke_result<_Fn, _ArgTypes...>::type
        { };

        template<typename _Fn, typename... _ArgTypes>
        using invoke_result_t = typename invoke_result<_Fn, _ArgTypes...>::type;
        template<typename _T>
        using result_of_t = typename result_of<_T>::type;
      }
    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_TYPE_MISCELLANEOUS_INVOKE_RESULT__

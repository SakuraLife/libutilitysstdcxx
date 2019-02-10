
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_IMPLICIT_CONSTRUCTIBLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_IMPLICIT_CONSTRUCTIBLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/opt/__twochar__.hpp>
#include<utility/trait/type/type_trait_special.hpp>
#include<utility/trait/type/features/is_constructible.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(features)
      {
        // is_implicit_constructible
        namespace __impl
        {
          using __two = trait::__opt__::__twochar__;
          using trait::type::special::declval;

          template<typename _T, typename... _Args>
          struct __is_implicit_constructible_test
          {
            private:
              template<typename __T>
              static void __help(const __T&);

              template<typename __T, typename... __Args>
              static char __test(const __T&,
                decltype(__help<const _T&>({ declval<__Args>()...}))* = 0
              );

              template<typename __T, typename... __Args>
              static __two __test(...);

            public:
              constexpr static bool value = sizeof(char) ==
                sizeof(decltype(__test<_T, _Args...>(declval<_T>()))
              );
          };
          template<bool, typename _T, typename... _Args>
          struct __is_implicit_constructible_helper;

          template<typename _T, typename... _Args>
          struct __is_implicit_constructible_helper<false, _T, _Args...>:
            public false_type
          { };
          template<typename _T, typename... _Args>
          struct __is_implicit_constructible_helper<true, _T, _Args...>:
            public integral_constant<bool,
              __is_implicit_constructible_test<_T, _Args...>::value
            >
          { };
        }
        template<typename _T, typename... _Args>
        struct is_implicit_constructible:
          public __impl::__is_implicit_constructible_helper<
            is_constructible<_T, _Args...>::value, _T, _Args...
          >
        { };

      }
    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_TYPE_FEATURES_IS_IMPLICIT_CONSTRUCTIBLE__

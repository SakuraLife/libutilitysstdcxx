
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_CONSTRUCTIBLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_CONSTRUCTIBLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_is_constructible

# include<utility/trait/config/trait_config.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(features)
      {
        // is_constructible
        template<class _T, typename... _Args>
        struct is_constructible:
          public integral_constant<bool,
            __utility_is_constructible(_T, _Args...)
          >
        { };
      }
    }
  }
__utility_globalspace_end(utility)

#else // __utility_has_is_constructible

# include<utility/trait/opt/__logical__.hpp>
# include<utility/trait/type/type_trait_special.hpp>
# include<utility/trait/type/categories/is_reference.hpp>
# include<utility/trait/type/categories/is_function.hpp>
# include<utility/trait/type/categories/is_void.hpp>
# include<utility/trait/type/transform/remove_cv_ref.hpp>
# include<utility/trait/type/transform/remove_all_extents.hpp>
# include<utility/trait/type/releations/is_same.hpp>
# include<utility/trait/type/releations/is_base_of.hpp>
# include<utility/trait/type/features/is_destructible.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(features)
      {
        namespace __impl
        {
          using trait::__opt__::__type_and__;
          using trait::__opt__::__type_or__;
          using trait::__opt__::__type_not__;
          using trait::type::categories::is_reference;
          using trait::type::categories::is_function;
          using trait::type::categories::is_void;
          using trait::type::releations::is_same;
          using trait::type::releations::is_base_of;
          using trait::type::features::is_destructible;
          using trait::type::transform::remove_cv_ref_t;
          using trait::type::transform::remove_all_extents;
          using trait::type::special::declval;

          template<typename _T, typename... _Args>
          struct __is_constructible_helper;

          template<typename _To, typename _From>
          struct __is_invaild_base_to_derived_cast
          {
            static_assert(is_reference<_To>::value,
              "Can not convert to a lvalue"
            );
            using __rawFrom = remove_cv_ref_t<_From>;
            using __rawTo = remove_cv_ref_t<_To>;
            constexpr static bool value = __type_and__<
              __type_not__<is_same<__rawFrom,__rawTo>>,
              is_base_of<__rawFrom,__rawTo>,
              __type_not__<__is_constructible_helper<__rawTo, _From>>
            >::value;
          };

          template<typename _To, typename _From>
          struct __is_invalid_lvalue_to_rvalue_cast : public
            trait::false_type
          { };

          template<typename _To_ref, typename _From_ref>
          struct __is_invalid_lvalue_to_rvalue_cast<_To_ref&&, _From_ref&>
          {
            using __rawFrom = remove_cv_ref_t<_From_ref>;
            using __rawTo = remove_cv_ref_t<_To_ref>;
            constexpr static bool value = __type_and__<
              __type_not__<is_function<__rawTo>>,
              __type_or__<
                is_same<__rawFrom, __rawTo>,
                is_base_of<__rawTo, __rawFrom>
              >
            >::value;
          };

          struct __is_constructible_test_helper
          {
            private:
              template<typename _T>
              static void __help(_T);

            public:
              template<typename _To, typename _From,
                typename = decltype(__help<_To>(declval<_From>()))>
              static true_type __test_cast(int);

              template<typename _To, typename _From,
                typename = decltype(static_cast<_To>(declval<_From>()))>
              static integral_constant<bool,
                !__is_invaild_base_to_derived_cast<_To, _From>::value &&
                !__is_invalid_lvalue_to_rvalue_cast<_To, _From>::value>
                __test_cast(long);
              template<typename, typename>
              static false_type __test_cast(...);

            public:
              template<typename _T, typename... _Args,
                typename = decltype(_T(declval<_Args>()...))>
              static true_type __test_nary(int);
              template<typename _T, typename...>
              static false_type __test_nary(...);

            public:
              template<typename _T, typename _U, typename =
                decltype(new _T(declval<_U>()))>
              static is_destructible<_T> __test_unary(int);
              template<typename, typename>
              static false_type __test_unary(...);
          };

          template<typename _T, bool = is_void<_T>::value>
          struct __is_default_constructible_test:
            public decltype(__is_constructible_test_helper::__test_nary<_T>(0))
          { };
          template<typename _T>
          struct __is_default_constructible_test<_T, true>: public
            false_type
          { };
          template<typename _T>
          struct __is_default_constructible_test<_T[], false>: public
            false_type
          { };
          template<typename _T, size_t _Size>
          struct __is_default_constructible_test<_T[_Size], false>: public
            __is_default_constructible_test<typename
              remove_all_extents<_T>::type>
          { };
          template<typename _T, typename... _Args>
          struct __is_constructible_helper
          {
            static_assert(sizeof...(_Args) > 1, "");
            typedef
              decltype(__is_constructible_test_helper::__test_nary<_T, _Args...>(0)) type;
          };
          template<typename _T>
          struct __is_constructible_helper<_T>: public __is_default_constructible_test<_T>
          { };
          template<typename _T, typename _Arg>
          struct __is_constructible_helper<_T, _Arg>: public
            decltype(__is_constructible_test_helper::__test_unary<_T, _Arg>(0))
          { };
          template<typename _T, typename _Arg>
          struct __is_constructible_helper<_T&, _Arg>: public
            decltype(__is_constructible_test_helper::__test_cast<_T&, _Arg>(0))
          { };
          template<typename _T, typename _Arg>
          struct __is_constructible_helper<_T&&, _Arg>: public
            decltype(__is_constructible_test_helper::__test_cast<_T&&, _Arg>(0))
          { };
        }
        template<class _T, class... _Args>
        struct is_constructible: public
          __impl::__is_constructible_helper<_T, _Args...>::type
        { };
      }
    }
  }
__utility_globalspace_end(utility)

#endif // __utility_has_is_constructible

#include<utility/trait/config/trait_undef.hpp>

#endif // ! __UTILITY_TRAIT_TYPE_FEATURES_IS_CONSTRUCTIBLE__

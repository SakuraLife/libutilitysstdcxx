
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_DESTRUCTIBLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_DESTRUCTIBLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/opt/__twochar__.hpp>
#include<utility/trait/type/type_trait_special.hpp>
#include<utility/trait/type/categories/is_function.hpp>
#include<utility/trait/type/categories/is_reference.hpp>
#include<utility/trait/type/transform/remove_all_extents.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_destructible
        namespace __impl
        {
          using __two = trait::__opt__::__twochar__;
          using trait::type::special::declval;
          using trait::type::transform::remove_all_extents_t;
          using trait::type::categories::is_reference;

          template<typename>
          struct __int_type__
          { typedef int type;};

          template<typename _T>
          struct __is_destructible_test_helper
          {
            private:
              template<typename __T>
              static char __test(typename __int_type__<
                decltype(declval<__T&>().~__T())
                >::type);
              template<typename __T>
              static __two __test(...);
            public:
              constexpr static bool value = sizeof(__test<_T>(0)) == sizeof(char);
          };

          template<typename _T, bool>
          struct __is_destructible_test;

          template<typename _T>
          struct __is_destructible_test<_T, false>: public
            integral_constant<bool,
              __is_destructible_test_helper<
                remove_all_extents_t<_T>
              >::value
            >
          { };
          template<typename _T>
          struct __is_destructible_test<_T, true>: public true_type
          { };

          template<typename _T, bool>
          struct __is_destructible_helper;

          template<typename _T>
          struct __is_destructible_helper<_T, false>:
            public __is_destructible_test<_T, is_reference<_T>::value>
          { };
          template<typename _T>
          struct __is_destructible_helper<_T, true>: public false_type
          { };
        }
        template<typename _T>
        struct is_destructible: public
          __impl::__is_destructible_helper<_T,
            trait::type::categories::is_function<_T>::value
          >
        { };
        template<typename _T>
        struct is_destructible<_T[]>: public false_type
        { };
        template<>
        struct is_destructible<void>: public false_type
        { };
      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_DESTRUCTIBLE__

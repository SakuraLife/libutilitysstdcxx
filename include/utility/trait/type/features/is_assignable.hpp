
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_ASSIGNABLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_ASSIGNABLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/opt/__twochar__.hpp>
#include<utility/trait/type/type_trait_special.hpp>
#include<utility/trait/type/categories/is_void.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(features)
      {
        // is_assignable
        namespace __impl
        {
          using __two = trait::__opt__::__twochar__;
          using trait::type::special::declval;
          using trait::type::categories::is_void;

          template<typename _T, typename _F>
          struct __is_assignable_test
          {
            private:
              template<typename _To, typename _From>
              static
              decltype((declval<_To>() = declval<_From>()),char('\0'))
              __test(int);
              template<typename, typename>
              static __two __test(...);

            public:
              constexpr static bool value = sizeof(__test<_T, _F>(0)) == sizeof(char);
          };

          template<
            typename _To, typename _From,
            bool = is_void<_To>::value || is_void<_From>::value
          >
          struct __is_assignable_helper: public trait::false_type
          { };

          template<typename _To, typename _From>
          struct __is_assignable_helper<_To, _From, false>:
            public integral_constant<bool,
              __is_assignable_test<_To, _From>::value
            >
          { };
        }
        template<typename _T, typename _U>
        struct is_assignable: public
          __impl::__is_assignable_helper<_T, _U>
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T, typename _U>
        constexpr bool is_assignable_v = is_assignable<_T, _U>::value;
#endif
      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_ASSIGNABLE__

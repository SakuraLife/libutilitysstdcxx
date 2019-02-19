
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_SWAPPABLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_SWAPPABLE__

#include<utility/trait/trait_helper.hpp>

#include<utility/algorithm/impl/swap/swap_single.hpp>

#include<utility/trait/opt/__twochar__.hpp>
#include<utility/trait/type/type_trait_special.hpp>
#include<utility/trait/type/categories/is_void.hpp>
#include<utility/trait/type/transform/is_referenceable.hpp>
#include<utility/trait/type/transform/add_reference.hpp>
#include<utility/trait/type/miscellaneous/conditional.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_swappable_with(C++17)
        // is_swappable(C++17)
        // is_nothrow_swappable_with(C++17)
        // is_nothrow_swappable(C++17)
        namespace __impl
        {
          using __two = trait::__opt__::__twochar__;
          using trait::type::categories::is_void;
          using trait::type::special::declval;

          template<typename _T, typename _U = _T,
            bool = !is_void<_T>::value && !is_void<_U>::value>
          struct __is_swappable_with_helper
          {
            private:
              template<typename __T, typename __U>
              static decltype(algorithm::swap(
                declval<__T>(), declval<__U>()
              ), char(0)) __test(int);
              template<typename, typename>
              static __two __test(...);

              typedef decltype((__test<_T, _U>(0))) __type1;
              typedef decltype((__test<_U, _T>(0))) __type2;

            public:
              constexpr static bool value =
                (sizeof(char) == sizeof(__type1)) &&
                (sizeof(char) == sizeof(__type2));
          };
          template<typename _T, typename _U>
          struct __is_swappable_with_helper<_T, _U, false>
          {
            public:
              constexpr static bool value = false;
          };

          template<typename _T, typename _U,
            bool = __is_swappable_with_helper<_T, _U>::value>
          struct __is_nothrow_swappable_with_helper
          {
            constexpr static bool value =
              noexcept(algorithm::swap(
                declval<_T>(), declval<_U>())
              ) &&
              noexcept(algorithm::swap(
                declval<_U>(), declval<_T>())
              );
          };
          template<typename _T, typename _U>
          struct __is_nothrow_swappable_with_helper<_T, _U, false>
          { constexpr static bool value = false;};
        }
        template<typename _T, typename _U>
        struct __UTILITY_TEMPLATE_VIS is_swappable_with: public
          integral_constant<bool,
            __impl::__is_swappable_with_helper<_T, _U>::value>
        { };
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_swappable: public
          trait::type::miscellaneous::conditional<
            trait::type::transform::is_referenceable<_T>::value,
            is_swappable_with<
              trait::type::transform::add_lvalue_reference_t<_T>,
              trait::type::transform::add_lvalue_reference_t<_T>
            >,
            false_type
          >::type
        { };

        template<typename _T, typename _U>
        struct __UTILITY_TEMPLATE_VIS is_nothrow_swappable_with: public
          integral_constant<bool,
            __impl::__is_nothrow_swappable_with_helper<_T, _U>::value
          >
        { };
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_nothrow_swappable: public
          trait::type::miscellaneous::conditional<
            trait::type::transform::is_referenceable<_T>::value,
            is_nothrow_swappable_with<
              trait::type::transform::add_lvalue_reference_t<_T>,
              trait::type::transform::add_lvalue_reference_t<_T>
            >,
            false_type
          >::type
        { };

      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_SWAPPABLE__

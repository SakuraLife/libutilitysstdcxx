
#ifndef __UTILITY_TYPE_TRAIT_OPERATOR_EQ__
#define __UTILITY_TYPE_TRAIT_OPERATOR_EQ__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/type_trait_special.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(op)
        // operatot == -> eq
        namespace __impl
        {
          using trait::type::special::declval;

          template<typename _T, typename _U>
          struct __eq_test
          {
            private:
              template<typename __T>
              static void __help(const __T&);

              template<typename __T, typename __U>
              static char __test(const __T&, decltype(declval<_T>() == declval<_U>())* = 0);
              template<typename __T, typename __U>
              static __two __test(...);

            public:
              constexpr static bool value = sizeof(char) ==
                sizeof(decltype(__test<_T, _U>(declval<_T>())));
          };
        }
        template<typename _T, typename _U = _T>
        struct __UTILITY_TEMPLATE_VIS eq : public integral_constant<bool,
            __impl::__eq_test<_T, _U>::value>
        { };

      __utility_interspace_end(op)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TYPE_TRAIT_OPERATOR_EQ__

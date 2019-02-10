
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_POLYMORPHIC__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_POLYMORPHIC__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_is_polymorphic

# include<utility/trait/config/trait_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_polymorphic
        template<typename _T>
        struct is_polymorphic :
          public integral_constant<bool, __utility_is_polymorphic(_T)>
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#else

# include<utility/trait/opt/__twochar__.hpp>
# include<utility/trait/type/miscellaneous/enable_if.hpp>
# include<utility/trait/type/type_trait_special.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_polymorphic
        namespace __impl
        {
          using trait::type::miscellaneous::enable_if;
          using trait::type::special::declval;
          using trait::__opt__::__twochar__;

          template<typename _T>
          char __is_polymorphic_test(
            typename enable_if<
              sizeof(reinterpret_cast<_T*>(
                  dynamic_cast<const volatile void*>(declval<_T>())
              )) != 0,
              int
            >::type
          );
          template<typename _T>
          __twochar__ __is_polymorphic_test(...);
        }
        template<typename _T>
        struct is_polymorphic: public integral_constant<bool,
            sizeof(__impl::__is_polymorphic_test<_T>(0)) == 1
          >
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif

#include<utility/trait/config/trait_undef.hpp>

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_POLYMORPHIC__

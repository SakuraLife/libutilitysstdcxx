
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_NOTHROW_DESTRUCTIBLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_NOTHROW_DESTRUCTIBLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/type_trait_special.hpp>
#include<utility/trait/type/features/is_destructible.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_nothrow_destructible
        namespace __impl
        {
          using trait::type::special::declval;

          template<bool, typename _T>
          struct __is_nothrow_destructible_helper;

          template<typename _T>
          struct __is_nothrow_destructible_helper<false, _T>: public
            false_type
          { };
          template<typename _T>
          struct __is_nothrow_destructible_helper<true, _T>: public
            integral_constant<bool, noexcept(declval<_T>().~_T())>
          { };
        }
        template<typename _T>
        struct is_nothrow_destructible: public
          __impl::__is_nothrow_destructible_helper<
            is_destructible<_T>::value,_T
          >
        { };
        template<typename _T>
        struct is_nothrow_destructible<_T&>: public true_type
        { };
        template<typename _T>
        struct is_nothrow_destructible<_T&&>: public true_type
        { };
        template<typename _T, size_t _Size>
        struct is_nothrow_destructible<_T[_Size]>:
          public is_nothrow_destructible<_T>
        { };
      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_NOTHROW_DESTRUCTIBLE__

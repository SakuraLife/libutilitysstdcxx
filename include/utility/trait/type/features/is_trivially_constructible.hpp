
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_TRIVIALLY_CONSTRUCTIBLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_TRIVIALLY_CONSTRUCTIBLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_is_trivially_constructible

#include<utility/trait/config/trait_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_trivially_constructible
        template<class _T, typename... _Args>
        struct __UTILITY_TEMPLATE_VIS is_trivially_constructible:
          public integral_constant<bool,
            __utility_is_trivially_constructible(_T, _Args...)>
        { };
      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#else // __utility_has_has_trivial_constructor

#include<utility/trait/type/categories/is_scalar.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_trivially_constructible
        template<class _T, typename... Args>
        struct __UTILITY_TEMPLATE_VIS is_trivially_constructible:
          public false_type
        { };
        template<class _T>
        struct __UTILITY_TEMPLATE_VIS is_trivially_constructible<_T>:
          public integral_constant<bool,
            trait::type::categories::is_scalar<_T>::value
          >
        { };
        template<class _T>
        struct __UTILITY_TEMPLATE_VIS is_trivially_constructible<_T, _T&>:
          public integral_constant<bool,
            trait::type::categories::is_scalar<_T>::value
          >
        { };
        template<class _T>
        struct __UTILITY_TEMPLATE_VIS is_trivially_constructible<_T, _T&&>:
          public integral_constant<bool,
            trait::type::categories::is_scalar<_T>::value
          >
        { };
        template<class _T>
        struct __UTILITY_TEMPLATE_VIS is_trivially_constructible<_T, const _T&>:
          public integral_constant<bool,
            trait::type::categories::is_scalar<_T>::value
          >
        { };
      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __utility_has_has_trivial_constructor

#include<utility/trait/config/trait_undef.hpp>

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_TRIVIALLY_CONSTRUCTIBLE__

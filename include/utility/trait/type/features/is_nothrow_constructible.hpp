
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_NOTHROW_CONSTRUCTIBLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_NOTHROW_CONSTRUCTIBLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/type_trait_special.hpp>
#include<utility/trait/type/categories/is_reference.hpp>
#include<utility/trait/type/features/is_constructible.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_nothrow_constructible
        namespace __impl
        {
          using trait::type::special::declval;

          template<class _T>
          void __is_nothrow_constructible_test(_T) noexcept
          { }

          template<bool /*is constructible*/, bool /*is reference*/,
          class _T, class... _Args>
          struct __is_nothrow_constructible_helper;

          template<class _T, class... _Args>
          struct __is_nothrow_constructible_helper<true, false, _T, _Args...>:
            public integral_constant<bool, noexcept(_T(declval<_Args>()...))>
          { };
          template<class _T, class... _Args>
          struct __is_nothrow_constructible_helper<true, true, _T, _Args...>:
            public integral_constant<bool,
              noexcept(__is_nothrow_constructible_test<_T>(declval<_Args>()...))
            >
          { };
          template<class _T, class... _Args>
          struct __is_nothrow_constructible_helper<false, true, _T, _Args...>:
            public false_type
          { };
          template<class _T, class... _Args>
          struct __is_nothrow_constructible_helper<false, false, _T, _Args...>:
            public false_type
          { };
        }
        template<class _T, class... _Args>
        struct is_nothrow_constructible: public
          __impl::__is_nothrow_constructible_helper<
            is_constructible<_T, _Args...>::value,
            trait::type::categories::is_reference<_T>::value,
            _T, _Args...
          >
        { };
        template<class _T, size_t __Size>
        struct is_nothrow_constructible<_T[__Size]>: public
          __impl::__is_nothrow_constructible_helper<
            is_constructible<_T>::value,
            trait::type::categories::is_reference<_T>::value,
            _T
          >
        { };

      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_NOTHROW_CONSTRUCTIBLE__

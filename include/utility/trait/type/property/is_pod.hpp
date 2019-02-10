
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_POD__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_POD__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_is_pod

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_pod
        template<typename _T>
        struct is_pod: public integral_constant<bool, __utility_is_pod(_T)>
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#else // __utility_has_is_pod

#include<utility/trait/type/features/is_trivially_default_constructible.hpp>
#include<utility/trait/type/features/is_trivially_copy_constructible.hpp>
#include<utility/trait/type/features/is_trivially_copy_assignable.hpp>
#include<utility/trait/type/features/is_trivially_destructible.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_pod
        template<typename _T>
        struct is_pod: public integral_constant<bool,
            trait::type::features::is_trivially_default_constructible<_T>::value &&
            trait::type::features::is_trivially_copy_constructible<_T>::value &&
            trait::type::features::is_trivially_copy_assignable<_T>::value &&
            trait::type::features::is_trivially_destructible<_T>::value
          >
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __utility_has_is_pod

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        template<typename _T>
        struct is_pod<_T*>: public true_type
        { };
        template<typename _T>
        struct is_pod<_T* const>: public true_type
        { };
        template<typename _T>
        struct is_pod<_T* volatile>: public true_type
        { };
        template<typename _T>
        struct is_pod<_T* const volatile>: public true_type
        { };

        template<>
        struct is_pod<char>: public true_type
        { };
        template<>
        struct is_pod<signed char>: public true_type
        { };
        template<>
        struct is_pod<unsigned char>: public true_type
        { };
        template<>
        struct is_pod<signed short>: public true_type
        { };
        template<>
        struct is_pod<unsigned short>: public true_type
        { };
        template<>
        struct is_pod<signed int>: public true_type
        { };
        template<>
        struct is_pod<unsigned int>: public true_type
        { };
        template<>
        struct is_pod<signed long>: public true_type
        { };
        template<>
        struct is_pod<unsigned long>: public true_type
        { };
        template<>
        struct is_pod<signed long long>: public true_type
        { };
        template<>
        struct is_pod<unsigned long long>: public true_type
        { };
        template<>
        struct is_pod<float>: public true_type
        { };
        template<>
        struct is_pod<double>: public true_type
        { };
        template<>
        struct is_pod<long double>: public true_type
        { };

        template<>
        struct is_pod<wchar_t>: public true_type
        { };
        template<>
        struct is_pod<char16_t>: public true_type
        { };
        template<>
        struct is_pod<char32_t>: public true_type
        { };
      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_POD__

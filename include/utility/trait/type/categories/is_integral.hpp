
#ifndef __UTILITY_TRAIT_TYPE_CATEGORIES_IS_INTEGRAL__
#define __UTILITY_TRAIT_TYPE_CATEGORIES_IS_INTEGRAL__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(categories)
        // the libinteger has some lager integer specifiic
        // is_integral
        // for some reason the __int128_t ans __uint128_t
        // will not support
        namespace __impl
        {
          template<typename _T>
          struct __is_integral_test: public false_type
          { };
          template<>
          struct __is_integral_test<bool>: public true_type
          { };
          template<>
          struct __is_integral_test<char>: public true_type
          { };
          template<>
          struct __is_integral_test<signed char>: public true_type
          { };
          template<>
          struct __is_integral_test<unsigned char>: public true_type
          { };
          template<>
          struct __is_integral_test<wchar_t>: public true_type
          { };
          template<>
          struct __is_integral_test<signed short>: public true_type
          { };
          template<>
          struct __is_integral_test<unsigned short>: public true_type
          { };
          template<>
          struct __is_integral_test<signed int>: public true_type
          { };
          template<>
          struct __is_integral_test<unsigned int>: public true_type
          { };
          template<>
          struct __is_integral_test<signed long int>: public true_type
          { };
          template<>
          struct __is_integral_test<unsigned long int>: public true_type
          { };
          template<>
          struct __is_integral_test<signed long long int>: public true_type
          { };
          template<>
          struct __is_integral_test<unsigned long long int>: public true_type
          { };
          template<>
          struct __is_integral_test<char16_t>: public true_type
          { };
          template<>
          struct __is_integral_test<char32_t>: public true_type
          { };

        }
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_integral: public __impl::__is_integral_test<
            trait::type::transform::remove_cv_t<_T>
          >
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _T>
        constexpr bool is_integral_v = is_integral<_T>::value;
#endif

      __utility_interspace_end(categories)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_TYPE_CATEGORIES_IS_INTEGRAL__

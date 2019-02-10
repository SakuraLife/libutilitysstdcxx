
#ifndef __UTILITY_TRAIT_TYPE_RELEATIONS_IS_CONVERTIBLE__
#define __UTILITY_TRAIT_TYPE_RELEATIONS_IS_CONVERTIBLE__

#include<utility/trait/trait_helper.hpp>

# include<utility/trait/type/type_trait_special.hpp>
# include<utility/trait/type/categories/is_void.hpp>
# include<utility/trait/type/categories/is_array.hpp>
# include<utility/trait/type/categories/is_function.hpp>
# include<utility/trait/type/categories/is_reference.hpp>
# include<utility/trait/type/transform/remove_cv.hpp>
# include<utility/trait/type/transform/remove_reference.hpp>
# include<utility/trait/type/property/is_const.hpp>
# include<utility/trait/type/property/is_volatile.hpp>
# include<utility/trait/type/releations/is_base_of.hpp>
# include<utility/trait/type/releations/is_same.hpp>
__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(releations)
        namespace __impl
        {
          using trait::type::special::declval;
          using trait::type::categories::is_array;
          using trait::type::categories::is_function;
          using trait::type::categories::is_void;
          using trait::type::categories::is_reference;
          using trait::type::transform::remove_cv_t;
          using trait::type::transform::remove_reference_t;
          using trait::type::property::is_const;
          using trait::type::property::is_volatile;
          using trait::type::releations::is_same;
          using trait::type::releations::is_base_of;

          template<typename _T>
          void __is_convertible_test_conv(_T);
          template<typename _F, typename _T, typename = void>
          struct __is_convertible_test :
            public false_type
          { };
          template<typename _F, typename _T>
          struct __is_convertible_test<_F, _T,
            decltype(__is_convertible_test_conv<_T>(declval<_F>()))
          >: public true_type
          { };

          template<
            typename _T,
            bool _is_array = is_array<_T>::value,
            bool _is_function = is_function<_T>::value,
            bool _is_void = is_void<_T>::value
          >
          struct __is_convertible_type_test
          { enum { value = 0};};
          template<typename _T>
          struct __is_convertible_type_test<_T, true, false, false>
          { enum { value = 1};};
          template<typename _T>
          struct __is_convertible_type_test<_T, false, true, false>
          { enum { value = 2};};
          template<typename _T>
          struct __is_convertible_type_test<_T, false, false, true>
          { enum { value = 3};};

          // @special
          template<typename _T, unsigned int =
            __is_convertible_type_test<remove_cv_t<_T>>::value
          >
          struct __is_convertible_check
          { constexpr static size_t __size = 0;};
          template<typename _T>
          struct __is_convertible_check<_T, 0>
          { constexpr static size_t __size = sizeof(_T);};

          template<
            typename _T1,
            typename _T2,
            unsigned int _T1_type_test =
              __is_convertible_type_test<_T1>::value,
            unsigned int _T2_type_test =
              __is_convertible_type_test<_T2>::value
          >
          struct __is_convertible_helper :
            public integral_constant<bool,
              __is_convertible_test<_T1, _T2>::value &&
              !(!is_function<_T1>::value  &&
                !is_reference<_T1>::value &&
                is_reference<_T2>::value &&
                (!is_const<remove_reference_t<_T2>>::value ||
                  is_volatile<remove_reference_t<_T2>>::value) &&
                (is_same<
                  remove_cv_t<_T1>,
                  remove_cv_t<remove_reference_t<_T2>>
                 >::value ||
                 is_base_of<remove_reference_t<_T2>, _T1>::value))
              >
          { };
          template<typename _T1, typename _T2>
          struct __is_convertible_helper<_T1, _T2, 0, 1> :
            public false_type
          { };
          template<typename _T1, typename _T2>
          struct __is_convertible_helper<_T1, _T2, 0, 2> :
            public false_type
          { };
          template<typename _T1, typename _T2>
          struct __is_convertible_helper<_T1, _T2, 0, 3> :
            public false_type
          { };
          template<typename _T1, typename _T2>
          struct __is_convertible_helper<_T1, _T2, 1, 1> :
            public false_type
          { };
          template<typename _T1, typename _T2>
          struct __is_convertible_helper<_T1, _T2, 1, 2> :
            public false_type
          { };
          template<typename _T1, typename _T2>
          struct __is_convertible_helper<_T1, _T2, 1, 3> :
            public false_type
          { };
          template<typename _T1, typename _T2>
          struct __is_convertible_helper<_T1, _T2, 2, 1> :
            public false_type
          { };
          template<typename _T1, typename _T2>
          struct __is_convertible_helper<_T1, _T2, 2, 2> :
            public false_type
          { };
          template<typename _T1, typename _T2>
          struct __is_convertible_helper<_T1, _T2, 2, 3> :
            public false_type
          { };
          template<typename _T1, typename _T2>
          struct __is_convertible_helper<_T1, _T2, 3, 1> :
            public false_type
          { };
          template<typename _T1, typename _T2>
          struct __is_convertible_helper<_T1, _T2, 3, 2> :
            public false_type
          { };
          template<typename _T1, typename _T2>
          struct __is_convertible_helper<_T1, _T2, 3, 3> :
            public true_type
          { };
        }
        template<typename _F, typename _T>
        struct is_convertible :
          public __impl::__is_convertible_helper<_F, _T>
        { };

#if !defined(__UTILITY_NO_CPP14__)
        template<typename _F, typename _T>
        constexpr bool is_convertible_v = is_convertible<_F, _T>::value;
#endif

      __utility_interspace_end(releations)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_RELEATIONS_IS_CONVERTIBLE__

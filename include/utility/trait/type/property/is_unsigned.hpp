
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_UNSIGNED__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_UNSIGNED__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_unsigned
        namespace __impl
        {
          using trait::type::categories::is_integral;
          using trait::type::categories::is_arithmetic;

          template<typename _T, bool = is_integral<_T>::value>
          struct __is_unsigned_intger_test:
            public bool_constant<(_T(-1) > _T(0))>
          { };
          template<typename _T>
          struct __is_unsigned_intger_test<_T, false>: public false_type
          { };
          template<typename _T, bool = is_arithmetic<_T>::value>
          struct __is_unsigned_test: public __is_unsigned_intger_test<_T>
          { };
          template<typename _T>
          struct __is_unsigned_test<_T, false>: public false_type
          { };
        }
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_unsigned: public __impl::__is_unsigned_test<_T>
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_UNSIGNED__

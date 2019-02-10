
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_ABSTRACT__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_ABSTRACT__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/opt/__twochar__.hpp>
#include<utility/trait/type/categories/is_class.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property)
        // is_abstract
        namespace __impl
        {
          using trait::__opt__::__twochar__;
          using trait::type::categories::is_class;

          template<typename _T>
          char __is_abstract_helper(_T(*)[1]);
          template<typename _T>
          __twochar__ __is_abstract_helper(...);

          template<typename _T, bool = is_class<_T>::value>
          struct __is_abstract_test:
            public trait::integral_constant<bool,
              sizeof(__impl::__is_abstract_helper<_T>(0)) != 1
            >
          { };
          template<typename _T>
          struct __is_abstract_test<_T, false>: public false_type
          { };
        }
        template<typename _T>
        struct is_abstract: public __impl::__is_abstract_test<_T>
        { };

      __utility_interspace_end(property)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_ABSTRACT__

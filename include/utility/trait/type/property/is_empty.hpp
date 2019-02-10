
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_IS_EMPTY__
#define __UTILITY_TRAIT_TYPE_PROPERTY_IS_EMPTY__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_is_empty

# include<utility/trait/config/trait_config.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(property)
      {
        // is_empty
        template<typename _T>
        struct is_empty :
          public integral_constant<bool, __utility_is_empty(_T)>
        { };

      }
    }
  }
__utility_globalspace_end(utility)

#else // __utility_has_is_empty

# include<utility/trait/type/categories/is_class.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(property)
      {
        // is_empty
        namespace __impl
        {
          using trait::type::categories::is_class;

          // avoid align
          template<typename _T>
          struct __is_empty_helper: public _T
          { long __nouse;};
          struct __is_empty_base_helper
          { long __nouse;};

          template<typename _T, bool = is_class<_T>::value>
          struct __is_empty_test:
            public integral_constant<bool,
              sizeof(__is_empty_helper<_T>) == sizeof(__is_empty_base_helper)
            >
          { };
          template<typename _T>
          struct __is_empty_test<_T, false>: public false_type
          { };
        }
        template<typename _T>
        struct is_empty: public __impl::__is_empty_test<_T>
        { };

      }
    }
  }
__utility_globalspace_end(utility)

#endif // ! __utility_has_is_empty

#include<utility/trait/config/trait_undef.hpp>

#endif // __UTILITY_TRAIT_TYPE_PROPERTY_IS_EMPTY__

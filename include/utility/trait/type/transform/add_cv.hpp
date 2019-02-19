
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_ADD_CV__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_ADD_CV__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/categories/is_function.hpp>
#include<utility/trait/type/categories/is_reference.hpp>
#include<utility/trait/type/property/is_const.hpp>
#include<utility/trait/type/property/is_volatile.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(transform)
        // add_const
        namespace __impl
        {
          using trait::type::property::is_const;
          using trait::type::categories::is_function;
          using trait::type::categories::is_reference;

          template<typename _T, bool =
            is_const<_T>::value || is_function<_T>::value ||
            is_reference<_T>::value
          >
          struct __add_const_helper
          { typedef _T type;};
          template<typename _T>
          struct __add_const_helper<_T, false>
          { typedef const _T type;};
        }
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS add_const
        { typedef typename
            __impl::__add_const_helper<_T>::type type;};

        // add_volatile
        namespace __impl
        {
          using trait::type::property::is_volatile;

          template<typename _T, bool =
            is_volatile<_T>::value || is_function<_T>::value ||
            is_reference<_T>::value
          >
          struct __add_volatile_helper
          { typedef _T type;};
          template<typename _T>
          struct __add_volatile_helper<_T, false>
          { typedef volatile _T type;};
        }
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS add_volatile
        { typedef typename __impl::__add_volatile_helper<_T>::type type;};

        // add_cv
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS add_cv
        {
          typedef typename add_const<
            typename add_volatile<_T>::type
          >::type type;
        };

        template<typename _T>
        using add_cv_t = typename add_cv<_T>::type;
        template<typename _T>
        using add_const_t = typename add_const<_T>::type;
        template<typename _T>
        using add_volatile_t = typename add_volatile<_T>::type;

      __utility_interspace_end(transform)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_ADD_CV__


#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_ADD_REFERENCE__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_ADD_REFERENCE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/transform/is_referenceable.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(transform)
        // add_lvalue_reference
        namespace __impl
        {
          using trait::type::transform::is_referenceable;
          template<typename _T, bool = is_referenceable<_T>::value>
          struct __add_lvalue_reference_helper
          { typedef _T type;};
          template<typename _T>
          struct __add_lvalue_reference_helper<_T, true>
          { typedef _T& type;};

        }
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS add_lvalue_reference
        {
          typedef typename
            __impl::__add_lvalue_reference_helper<_T>::type type;
        };

        // add_rvalue_reference
        namespace __impl
        {
          template<typename _T, bool = is_referenceable<_T>::value>
          struct __add_rvalue_reference_helper
          { typedef _T type;};
          template<typename _T>
          struct __add_rvalue_reference_helper<_T, true>
          { typedef _T&& type;};
        }
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS add_rvalue_reference
        {
          typedef typename
            __impl::__add_rvalue_reference_helper<_T>::type type;
        };

        template<typename _T>
        using add_lvalue_reference_t = typename add_lvalue_reference<_T>::type;
        template<typename _T>
        using add_rvalue_reference_t = typename add_rvalue_reference<_T>::type;

      __utility_interspace_end(transform)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_ADD_REFERENCE__

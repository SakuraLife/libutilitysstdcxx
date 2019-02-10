
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_ADD_POINTER__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_ADD_POINTER__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/transform/is_referenceable.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>
#include<utility/trait/type/transform/remove_reference.hpp>
#include<utility/trait/type/releations/is_same.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(transform)
      {
        // add_pointer
        namespace __impl
        {
          using trait::type::transform::is_referenceable;
          using trait::type::releations::is_same;
          using trait::type::transform::remove_cv_t;

          template<typename _T,
            bool = is_referenceable<_T>::value ||
                   is_same<remove_cv_t<_T>, void>::value
          >
          struct __add_pointer_helper
          { typedef typename remove_reference<_T>::type* type;};
          template<typename _T>
          struct __add_pointer_helper<_T, false>
          { typedef _T type;};
        }
        template<typename _T>
        struct add_pointer
        { typedef typename __impl::__add_pointer_helper<_T>::type type;};

        template<typename _T>
        using add_pointer_t = typename add_pointer<_T>::type;

      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_ADD_POINTER__

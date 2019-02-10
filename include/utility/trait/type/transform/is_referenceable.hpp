
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_IS_REFERENECABLE__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_IS_REFERENECABLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/opt/__twochar__.hpp>
#include<utility/trait/type/releations/is_same.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(transform)
      {
        namespace __impl
        {
          using trait::__opt__::__twochar__;
          template<typename _T>
          _T& __is_referenceable_test(int);
          template<typename _T>
          __twochar__ __is_referenceable_test(...);

        }
        template<typename _T>
        struct is_referenceable: public integral_constant<bool,
            !trait::type::releations::is_same<
              decltype(__impl::__is_referenceable_test<_T>(0)),
              trait::__opt__::__twochar__
            >::value
          >
        { };

      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_IS_REFERENECABLE__

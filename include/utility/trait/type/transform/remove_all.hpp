
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_ALL__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_ALL__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>
#include<utility/trait/type/transform/remove_reference.hpp>
#include<utility/trait/type/transform/remove_pointer.hpp>
#include<utility/trait/type/transform/remove_all_pointer.hpp>
#include<utility/trait/type/transform/remove_cv_ref.hpp>
#include<utility/trait/type/transform/remove_cv_pointer.hpp>
#include<utility/trait/type/transform/remove_all_pointer_reference.hpp>
#include<utility/trait/type/transform/remove_extent.hpp>
#include<utility/trait/type/transform/remove_all_extents.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(transform)
      {
        template<typename _T>
        struct remove_all
        {
          typedef remove_cv_t<
            remove_all_pointer_reference_t<remove_all_extents_t<_T>>
          > type;
        };

        template<typename _T>
        using remove_all_t = typename remove_all<_T>::type;
      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_ALL__

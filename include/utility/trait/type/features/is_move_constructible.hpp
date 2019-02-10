
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_MOVE_CONSTRUCTIBLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_MOVE_CONSTRUCTIBLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/transform/add_reference.hpp>
#include<utility/trait/type/features/is_constructible.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(features)
      {
        // is_move_constructible
        template<typename _T>
        struct is_move_constructible: public is_constructible<
            _T, trait::type::transform::add_rvalue_reference_t<_T>
          >
        { };


      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_MOVE_CONSTRUCTIBLE__

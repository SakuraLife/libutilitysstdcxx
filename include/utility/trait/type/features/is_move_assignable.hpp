
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_MOVE_ASSIGNABLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_MOVE_ASSIGNABLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/transform/add_reference.hpp>
#include<utility/trait/type/features/is_assignable.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_move_assignable
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_move_assignable: public is_assignable<
            trait::type::transform::add_lvalue_reference_t<_T>,
            trait::type::transform::add_rvalue_reference_t<_T>>
        { };

      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_MOVE_ASSIGNABLE__


#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_MOVEABLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_MOVEABLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/features/is_move_constructible.hpp>
#include<utility/trait/type/features/is_move_assignable.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_moveable
        template<typename _T>
        struct is_moveable: public integral_constant<bool,
            is_move_constructible<_T>::value &&
            is_move_assignable<_T>::value>
        { };
      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_TYPE_FEATURES_IS_MOVEABLE__

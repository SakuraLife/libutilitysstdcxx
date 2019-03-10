
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_TYPE_FEATURE_CHECK__
#define __UTILITY_TRAIT_TYPE_FEATURES_TYPE_FEATURE_CHECK__


#include<utility/trait/type/features/has_virtual_destructor.hpp>

#include<utility/trait/type/features/is_assignable.hpp>
#include<utility/trait/type/features/is_copy_assignable.hpp>
#include<utility/trait/type/features/is_move_assignable.hpp>
#include<utility/trait/type/features/is_nothrow_assignable.hpp>
#include<utility/trait/type/features/is_nothrow_copy_assignable.hpp>
#include<utility/trait/type/features/is_nothrow_move_assignable.hpp>
#include<utility/trait/type/features/is_trivially_assignable.hpp>
#include<utility/trait/type/features/is_trivially_copy_assignable.hpp>
#include<utility/trait/type/features/is_trivially_move_assignable.hpp>

#include<utility/trait/type/features/is_constructible.hpp>
#include<utility/trait/type/features/is_implicit_constructible.hpp>
#include<utility/trait/type/features/is_default_constructible.hpp>
#include<utility/trait/type/features/is_copy_constructible.hpp>
#include<utility/trait/type/features/is_move_constructible.hpp>
#include<utility/trait/type/features/is_trivially_constructible.hpp>
#include<utility/trait/type/features/is_trivially_default_constructible.hpp>
#include<utility/trait/type/features/is_trivially_copy_constructible.hpp>
#include<utility/trait/type/features/is_trivially_move_constructible.hpp>
#include<utility/trait/type/features/is_nothrow_constructible.hpp>
#include<utility/trait/type/features/is_nothrow_default_constructible.hpp>
#include<utility/trait/type/features/is_nothrow_copy_constructible.hpp>
#include<utility/trait/type/features/is_nothrow_move_constructible.hpp>

#include<utility/trait/type/features/is_destructible.hpp>
#include<utility/trait/type/features/is_nothrow_destructible.hpp>
#include<utility/trait/type/features/is_trivially_destructible.hpp>

#include<utility/trait/opt/__operate__.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        template<typename _T>
        struct type_feature_check
        {
          constexpr static _trait_state destructible =
            is_destructible<_T>::value ?
              (is_trivially_destructible<_T>::value ?
                _trait_state::trivial : _trait_state::support) :
              _trait_state::unsupport;

          constexpr static _trait_state default_constructible =
            is_default_constructible<_T>::value ?
              (is_trivially_default_constructible<_T>::value ?
                _trait_state::trivial : _trait_state::support) :
              _trait_state::unsupport;

          constexpr static _trait_state copy_constructible =
            is_copy_constructible<_T>::value ?
              (is_trivially_copy_constructible<_T>::value ?
                _trait_state::trivial : _trait_state::support) :
              _trait_state::unsupport;

          constexpr static _trait_state move_constructible =
            is_move_constructible<_T>::value ?
              (is_trivially_move_constructible<_T>::value ?
                _trait_state::trivial : _trait_state::support) :
              _trait_state::unsupport;

          constexpr static _trait_state copy_assignable =
            is_copy_assignable<_T>::value ?
              (is_trivially_copy_assignable<_T>::value ?
                _trait_state::trivial : _trait_state::support) :
              _trait_state::unsupport;

          constexpr static _trait_state move_assignable =
            is_move_assignable<_T>::value ?
              (is_trivially_move_assignable<_T>::value ?
                _trait_state::trivial : _trait_state::support) :
              _trait_state::unsupport;
        };

        template<typename... _Types>
        struct typepack_feature_check
        {
          constexpr static _trait_state destructible =
            trait::__opt__::__value_and__<
              _trait_state, _trait_state::trivial,
              type_feature_check<_Types>::destructible...
            >::value;

          constexpr static _trait_state default_constructible =
            trait::__opt__::__value_and__<
              _trait_state, _trait_state::trivial,
              type_feature_check<_Types>::default_constructible...
            >::value;

          constexpr static _trait_state copy_constructible =
            trait::__opt__::__value_and__<
              _trait_state, _trait_state::trivial,
              type_feature_check<_Types>::copy_constructible...
            >::value;

          constexpr static _trait_state move_constructible =
            trait::__opt__::__value_and__<
              _trait_state, _trait_state::trivial,
              type_feature_check<_Types>::move_constructible...
            >::value;

          constexpr static _trait_state copy_assignable =
            trait::__opt__::__value_and__<
              _trait_state, _trait_state::trivial,
              type_feature_check<_Types>::copy_assignable...
            >::value;

          constexpr static _trait_state move_assignable =
            trait::__opt__::__value_and__<
              _trait_state, _trait_state::trivial,
              type_feature_check<_Types>::move_assignable...
            >::value;
        };

      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_TYPE_FEATURES_TYPE_FEATURE_CHECK__


#ifndef __UTILITY_CONTAINER_HELPER_IN_PLACE_T__
#define __UTILITY_CONTAINER_HELPER_IN_PLACE_T__


/**
 * \file in_place_t.hpp
 * \author Inochi Amaoto
 *
 */

#include<utility/config/utility_config.hpp>
#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(container)
    __utility_interspace_start(_helper)
      struct __UTILITY_TYPE_VIS in_place_t
      { explicit in_place_t() = default;};

      template<typename _T>
      struct __UTILITY_TEMPLATE_VIS in_place_type_t
      { explicit in_place_type_t() = default;};

      template<size_t _I>
      struct __UTILITY_TEMPLATE_VIS in_place_index_t
      { explicit in_place_index_t() = default;};

      __UTILITY_CPP17_INLINE__
      constexpr in_place_t in_place{};

#ifndef __UTILITY_NO_CPP14__
      template<typename _T>
      __UTILITY_CPP17_INLINE__
      constexpr in_place_type_t<_T> in_place_type{};

      template<size_t _I>
      __UTILITY_CPP17_INLINE__
      constexpr in_place_index_t<_I> in_place_index{};
#endif // ! __UTILITY_NO_CPP14__

      template<typename _T>
      struct is_in_place_type: public trait::false_type
      { };

      template<typename _T>
      struct is_in_place_type<in_place_type_t<_T>>: public trait::true_type
      { };

    __utility_interspace_end(_helper)

    using _helper::in_place_t;
    using _helper::in_place_index_t;
    using _helper::in_place_type_t;

    using _helper::in_place;
#ifndef __UTILITY_NO_CPP14__
    using _helper::in_place_index;
    using _helper::in_place_type;
#endif // ! __UTILITY_NO_CPP14__

  __utility_interspace_end(container)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CONTAINER_HELPER_IN_PLACE_T__

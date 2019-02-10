
#ifndef __UTILITY_CONTAINER_HELPER_IGNORE_T__
#define __UTILITY_CONTAINER_HELPER_IGNORE_T__

/**
 * \file ignore_t.hpp
 * \author Inochi Amaoto
 *
 */

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(container)

    __utility_interspace_start(_helper)
      struct ignore_t
      {
        public:
          constexpr ignore_t() = default;

        public:
          template<typename _T>
          __UTILITY_CPP14_CONSTEXPR__
          const ignore_t& operator=(const _T&) const
          { return *this;}
      };

      __UTILITY_CPP17_INLINE__
      constexpr ignore_t ignore{};

    __utility_interspace_end(_helper)

    using _helper::ignore_t;
    using _helper::ignore;

  __utility_interspace_end(container)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CONTAINER_HELPER_IGNORE_T__

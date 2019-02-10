
#ifndef __UTILITY_CONTAINER_HELPER_NULLOPT_T__
#define __UTILITY_CONTAINER_HELPER_NULLOPT_T__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(container)
    __utility_interspace_start(_helper)
      struct nullopt_t
      {
        public:
          explicit constexpr nullopt_t() noexcept
          { }
#if defined(UTILITY_USE_NULL_NULLOPT)
          explicit constexpr nullopt_t(nullptr_t) noexcept
          { }
#endif
      };

      __UTILITY_CPP17_INLINE__ constexpr nullopt_t nullopt{};
    __utility_interspace_end(_helper)

    using _helper::nullopt_t;
    using _helper::nullopt;

  __utility_interspace_end(container)
__utility_globalspace_end(utility)


#endif // ! __UTILITY_CONTAINER_HELPER_NULLOPT_T__

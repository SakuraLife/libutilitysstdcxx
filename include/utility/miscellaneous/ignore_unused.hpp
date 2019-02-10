
#ifndef __UTILITY_MISCELLANEOUS_IGNORE_UNUSED__
#define __UTILITY_MISCELLANEOUS_IGNORE_UNUSED__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(miscellaneous)
  {
    template<typename... Ts>
    UTILITY_ALWAYS_INLINE __UTILITY_CPP14_CONSTEXPR__
    inline void ignore_unused()
    { }
    template<typename... Ts>
    UTILITY_ALWAYS_INLINE __UTILITY_CPP14_CONSTEXPR__
    inline void ignore_unused(const Ts& ...)
    { }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MISCELLANEOUS_IGNORE_UNUSED__

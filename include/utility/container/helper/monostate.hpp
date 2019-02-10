
#ifndef __UTILITY_CONTAINER_HELPER_MONOSTATE__
#define __UTILITY_CONTAINER_HELPER_MONOSTATE__

/**
 * \file monostate.hpp
 * \author Inochi Amaoto
 *
 */

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(container)
  {

     __utility_interspace_start(_helper)
    {
      struct monostate
      { };
      constexpr bool operator<(monostate, monostate) noexcept
      { return false;}
      constexpr bool operator>(monostate, monostate) noexcept
      { return false;}
      constexpr bool operator<=(monostate, monostate) noexcept
      { return true;}
      constexpr bool operator>=(monostate, monostate) noexcept
      { return true;}
      constexpr bool operator==(monostate, monostate) noexcept
      { return true;}
      constexpr bool operator!=(monostate, monostate) noexcept
      { return false;}

    } // _helper

    using _helper::monostate;

  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CONTAINER_HELPER_MONOSTATE__


#ifndef __UTILITY_CONTAINER_HELPER_MONOSTATE__
#define __UTILITY_CONTAINER_HELPER_MONOSTATE__

/**
 * \file monostate.hpp
 * \author Inochi Amaoto
 *
 */

#include<utility/config/utility_config.hpp>

namespace utility
{
  namespace container
  {

    namespace helper
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

    } // helper

    using helper::monostate;

  }
}

#endif // ! __UTILITY_CONTAINER_HELPER_MONOSTATE__


#ifndef ___UTILITY__STANDARD__LIBRARY__CSTDINT___
#define ___UTILITY__STANDARD__LIBRARY__CSTDINT___

#include<utility/config/utility_config.hpp>

#if defined(__cplusplus) && !defined(__STDC_LIMIT_MACROS)
#define __STDC_LIMIT_MACROS
#endif
#if defined(__cplusplus) && !defined(__STDC_CONSTANT_MACROS)
#define __STDC_CONSTANT_MACROS
#endif

#include<stdint.h>

#if !defined(__UTILITY_BUILD_LIB) || !defined(__UTILITY_NO_SYSHEADER)
#pragma GCC system_header
#endif

__utility_globalspace_start(utility)
  namespace sstd
  {
    using::int8_t;
    using::int16_t;
    using::int32_t;
    using::int64_t;

    using::uint8_t;
    using::uint16_t;
    using::uint32_t;
    using::uint64_t;

    using::int_least8_t;
    using::int_least16_t;
    using::int_least32_t;
    using::int_least64_t;

    using::uint_least8_t;
    using::uint_least16_t;
    using::uint_least32_t;
    using::uint_least64_t;

    using::int_fast8_t;
    using::int_fast16_t;
    using::int_fast32_t;
    using::int_fast64_t;

    using::uint_fast8_t;
    using::uint_fast16_t;
    using::uint_fast32_t;
    using::uint_fast64_t;

    using::intptr_t;
    using::uintptr_t;

    using::intmax_t;
    using::uintmax_t;
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CSTDINT___

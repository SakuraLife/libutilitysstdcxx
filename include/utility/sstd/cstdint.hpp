
#ifndef ___UTILITY__STANDARD__LIBRARY__CSTDINT___
#define ___UTILITY__STANDARD__LIBRARY__CSTDINT___

#include<utility/config/utility_config.hpp>
#include<utility/config/utility_preconfig.hpp>

#define INT8_MIN          ___UTILITY_INT8_MIN
#define INT16_MIN         ___UTILITY_INT16_MIN
#define INT32_MIN         ___UTILITY_INT32_MIN
#define INT64_MIN         ___UTILITY_INT64_MIN
#define INT8_MAX          ___UTILITY_INT8_MAX
#define INT16_MAX         ___UTILITY_INT16_MAX
#define INT32_MAX         ___UTILITY_INT32_MAX
#define INT64_MAX         ___UTILITY_INT64_MAX

#define UINT8_MIN         ___UTILITY_UINT8_MIN
#define UINT16_MIN        ___UTILITY_UINT16_MIN
#define UINT32_MIN        ___UTILITY_UINT32_MIN
#define UINT64_MIN        ___UTILITY_UINT64_MIN
#define UINT8_MAX         ___UTILITY_UINT8_MAX
#define UINT16_MAX        ___UTILITY_UINT16_MAX
#define UINT32_MAX        ___UTILITY_UINT32_MAX
#define UINT64_MAX        ___UTILITY_UINT64_MAX

#define INT_FAST8_MIN     ___UTILITY_INT_FAST8_MIN
#define INT_FAST16_MIN    ___UTILITY_INT_FAST16_MIN
#define INT_FAST32_MIN    ___UTILITY_INT_FAST32_MIN
#define INT_FAST64_MIN    ___UTILITY_INT_FAST64_MIN
#define INT_FAST8_MAX     ___UTILITY_INT_FAST8_MAX
#define INT_FAST16_MAX    ___UTILITY_INT_FAST16_MAX
#define INT_FAST32_MAX    ___UTILITY_INT_FAST32_MAX
#define INT_FAST64_MAX    ___UTILITY_INT_FAST64_MAX

#define UINT_FAST8_MIN    ___UTILITY_UINT_FAST8_MIN
#define UINT_FAST16_MIN   ___UTILITY_UINT_FAST16_MIN
#define UINT_FAST32_MIN   ___UTILITY_UINT_FAST32_MIN
#define UINT_FAST64_MIN   ___UTILITY_UINT_FAST64_MIN
#define UINT_FAST8_MAX    ___UTILITY_UINT_FAST8_MAX
#define UINT_FAST16_MAX   ___UTILITY_UINT_FAST16_MAX
#define UINT_FAST32_MAX   ___UTILITY_UINT_FAST32_MAX
#define UINT_FAST64_MAX   ___UTILITY_UINT_FAST64_MAX

#define INT_LEAST8_MIN    ___UTILITY_INT_LEAST8_MIN
#define INT_LEAST16_MIN   ___UTILITY_INT_LEAST16_MIN
#define INT_LEAST32_MIN   ___UTILITY_INT_LEAST32_MIN
#define INT_LEAST64_MIN   ___UTILITY_INT_LEAST64_MIN
#define INT_LEAST8_MAX    ___UTILITY_INT_LEAST8_MAX
#define INT_LEAST16_MAX   ___UTILITY_INT_LEAST16_MAX
#define INT_LEAST32_MAX   ___UTILITY_INT_LEAST32_MAX
#define INT_LEAST64_MAX   ___UTILITY_INT_LEAST64_MAX

#define UINT_LEAST8_MIN   ___UTILITY_UINT_LEAST8_MIN
#define UINT_LEAST16_MIN  ___UTILITY_UINT_LEAST16_MIN
#define UINT_LEAST32_MIN  ___UTILITY_UINT_LEAST32_MIN
#define UINT_LEAST64_MIN  ___UTILITY_UINT_LEAST64_MIN
#define UINT_LEAST8_MAX   ___UTILITY_UINT_LEAST8_MAX
#define UINT_LEAST16_MAX  ___UTILITY_UINT_LEAST16_MAX
#define UINT_LEAST32_MAX  ___UTILITY_UINT_LEAST32_MAX
#define UINT_LEAST64_MAX  ___UTILITY_UINT_LEAST64_MAX

#define INTMAX_MIN        ___UTILITY_INTMAX_MIN
#define INTMAX_MAX        ___UTILITY_INTMAX_MAX
#define UINTMAX_MIN       ___UTILITY_UINTMAX_MIN
#define UINTMAX_MAX       ___UTILITY_UINTMAX_MAX


__utility_globalspace_start(utility)
#if defined(___UTILITY_INT8_T)
  typedef ___UTILITY_INT8_T int8_t;
#endif

#if defined(___UTILITY_INT16_T)
  typedef ___UTILITY_INT16_T int16_t;
#endif

#if defined(___UTILITY_INT32_T)
  typedef ___UTILITY_INT32_T int32_t;
#endif

#if defined(___UTILITY_INT64_T)
  typedef ___UTILITY_INT64_T int64_t;
#endif

#if defined(___UTILITY_UINT8_T)
  typedef ___UTILITY_UINT8_T uint8_t;
#endif

#if defined(___UTILITY_UINT16_T)
  typedef ___UTILITY_UINT16_T uint16_t;
#endif

#if defined(___UTILITY_UINT32_T)
  typedef ___UTILITY_UINT32_T uint32_t;
#endif

#if defined(___UTILITY_UINT64_T)
  typedef ___UTILITY_UINT64_T uint64_t;
#endif

#if defined(___UTILITY_INT_FAST8_T)
  typedef ___UTILITY_INT_FAST8_T int_fast8_t;
#endif

#if defined(___UTILITY_INT_FAST16_T)
  typedef ___UTILITY_INT_FAST16_T int_fast16_t;
#endif

#if defined(___UTILITY_INT_FAST32_T)
  typedef ___UTILITY_INT_FAST32_T int_fast32_t;
#endif

#if defined(___UTILITY_INT_FAST64_T)
  typedef ___UTILITY_INT_FAST64_T int_fast64_t;
#endif

#if defined(___UTILITY_UINT_FAST8_T)
  typedef ___UTILITY_UINT_FAST8_T uint_fast8_t;
#endif

#if defined(___UTILITY_UINT_FAST16_T)
  typedef ___UTILITY_UINT_FAST16_T uint_fast16_t;
#endif

#if defined(___UTILITY_UINT_FAST32_T)
  typedef ___UTILITY_UINT_FAST32_T uint_fast32_t;
#endif

#if defined(___UTILITY_UINT_FAST64_T)
  typedef ___UTILITY_UINT_FAST64_T uint_fast64_t;
#endif

#if defined(___UTILITY_INT_LEAST8_T)
  typedef ___UTILITY_INT_LEAST8_T int_least8_t;
#endif

#if defined(___UTILITY_INT_LEAST16_T)
  typedef ___UTILITY_INT_LEAST16_T int_least16_t;
#endif

#if defined(___UTILITY_INT_LEAST32_T)
  typedef ___UTILITY_INT_LEAST32_T int_least32_t;
#endif

#if defined(___UTILITY_INT_LEAST64_T)
  typedef ___UTILITY_INT_LEAST64_T int_least64_t;
#endif

#if defined(___UTILITY_UINT_LEAST8_T)
  typedef ___UTILITY_UINT_LEAST8_T uint_least8_t;
#endif

#if defined(___UTILITY_UINT_LEAST16_T)
  typedef ___UTILITY_UINT_LEAST16_T uint_least16_t;
#endif

#if defined(___UTILITY_UINT_LEAST32_T)
  typedef ___UTILITY_UINT_LEAST32_T uint_least32_t;
#endif

#if defined(___UTILITY_UINT_LEAST64_T)
  typedef ___UTILITY_UINT_LEAST64_T uint_least64_t;
#endif

#if defined(___UTILITY_INTMAX_T)
  typedef ___UTILITY_INTMAX_T intmax_t;
#endif

#if defined(___UTILITY_UINTMAX_T)
  typedef ___UTILITY_UINTMAX_T uintmax_t;
#endif
  namespace sstd
  {
#if defined(___UTILITY_INT8_T)
    using utility::int8_t;
#endif

#if defined(___UTILITY_INT16_T)
    using utility::int16_t;
#endif

#if defined(___UTILITY_INT32_T)
    using utility::int32_t;
#endif

#if defined(___UTILITY_INT64_T)
    using utility::int64_t;
#endif

#if defined(___UTILITY_UINT8_T)
    using utility::uint8_t;
#endif

#if defined(___UTILITY_UINT16_T)
    using utility::uint16_t;
#endif

#if defined(___UTILITY_UINT32_T)
    using utility::uint32_t;
#endif

#if defined(___UTILITY_UINT64_T)
    using utility::uint64_t;
#endif

#if defined(___UTILITY_INT_FAST8_T)
    using utility::int_fast8_t;
#endif

#if defined(___UTILITY_INT_FAST16_T)
    using utility::int_fast16_t;
#endif

#if defined(___UTILITY_INT_FAST32_T)
    using utility::int_fast32_t;
#endif

#if defined(___UTILITY_INT_FAST64_T)
    using utility::int_fast64_t;
#endif

#if defined(___UTILITY_UINT_FAST8_T)
    using utility::uint_fast8_t;
#endif

#if defined(___UTILITY_UINT_FAST16_T)
    using utility::uint_fast16_t;
#endif

#if defined(___UTILITY_UINT_FAST32_T)
    using utility::uint_fast32_t;
#endif

#if defined(___UTILITY_UINT_FAST64_T)
    using utility::uint_fast64_t;
#endif

#if defined(___UTILITY_INT_LEAST8_T)
    using utility::int_least8_t;
#endif

#if defined(___UTILITY_INT_LEAST16_T)
    using utility::int_least16_t;
#endif

#if defined(___UTILITY_INT_LEAST32_T)
    using utility::int_least32_t;
#endif

#if defined(___UTILITY_INT_LEAST64_T)
    using utility::int_least64_t;
#endif

#if defined(___UTILITY_UINT_LEAST8_T)
    using utility::uint_least8_t;
#endif

#if defined(___UTILITY_UINT_LEAST16_T)
    using utility::uint_least16_t;
#endif

#if defined(___UTILITY_UINT_LEAST32_T)
    using utility::uint_least32_t;
#endif

#if defined(___UTILITY_UINT_LEAST64_T)
    using utility::uint_least64_t;
#endif

#if defined(___UTILITY_INTMAX_T)
    using utility::intmax_t;
#endif

#if defined(___UTILITY_UINTMAX_T)
    using utility::uintmax_t;
#endif
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CSTDINT___

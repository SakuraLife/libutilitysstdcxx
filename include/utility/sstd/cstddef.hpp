
#ifndef ___UTILITY__STANDARD__LIBRARY__CSTDDEF__
#define ___UTILITY__STANDARD__LIBRARY__CSTDDEF__

#include<utility/config/utility_config.hpp>
#include_next<stddef.h>

#include<utility/type/byte.hpp>

// TODO: unknow
__utility_globalspace_start(utility)
  namespace sstd
  {
    using utility::nullptr_t;
    using ::ptrdiff_t;
    using ::size_t;
    using type::byte;
    // TODO: max_align_t
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__STANDARD__LIBRARY__CSTDDEF__

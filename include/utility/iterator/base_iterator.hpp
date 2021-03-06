
#ifndef __UTILITY_ITERATOR_BASE_ITERATOR__
#define __UTILITY_ITERATOR_BASE_ITERATOR__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(iterator)
    template<
      typename __Category,
      typename __T,
      typename __Distant = ptrdiff_t,
      typename __Pointer = __T*,
      typename __Reference = __T&
    >
    class __UTILITY_TEMPLATE_VIS iterator
    {
      public:
        typedef __Category    iterator_category;
        typedef __T           value_type;
        typedef __Distant     difference_type;
        typedef __Pointer     pointer;
        typedef __Reference   reference;
    };
  __utility_interspace_end(iterator)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ITERATOR_BASE_ITERATOR__

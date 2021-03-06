
#ifndef __UTILITY_ITERATOR_ADVANCE__
#define __UTILITY_ITERATOR_ADVANCE__

#include<utility/config/utility_config.hpp>
#include<utility/iterator/next.hpp>
#include<utility/iterator/prev.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(iterator)
    template<typename _Iterator, typename _Distance>
    __UTILITY_CPP17_CONSTEXPR__
    inline void advance(_Iterator& __it, _Distance __dis)
    {
      __it = __dis > 0 ? iterator::next(__it, __dis) :
        iterator::prev(__it, -__dis);
    }
  __utility_interspace_end(iterator)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ITERATOR_ADVANCE__

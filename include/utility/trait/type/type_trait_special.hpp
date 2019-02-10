
#ifndef ___UTILITY__TRAIT__SPECIAL__
#define ___UTILITY__TRAIT__SPECIAL__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(special)
      {
        // declval
        namespace __impl
        {
          template<typename T>
          T&& __declval_helper(int);
          template<typename T>
          T   __declval_helper(long);
        }
        template<typename T>
        decltype(__impl::__declval_helper<T>(0))
          declval() noexcept;
      }
    }
  }
__utility_globalspace_end(utility)

#endif // ! ___UTILITY__TRAIT__SPECIAL__

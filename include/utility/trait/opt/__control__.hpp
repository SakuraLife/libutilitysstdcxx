
#ifndef __UTILITY_TRAIT_OPT___CONTROL____
#define __UTILITY_TRAIT_OPT___CONTROL____

#include<utility/config/utility_config.hpp>
#include<utility/trait/opt/__constant__.hpp>

namespace utility
{
  namespace trait
  {
    namespace __opt__
    {
      template<bool _B, typename _T>
      struct __if__
      { };
      template<typename _T>
      struct __if__<true, _T>
      { typedef _T type;};

      template<bool _B, typename _TI, typename _TE>
      struct __if_else__
      { typedef _TI type;};
      template<typename _TI, typename _TE>
      struct __if_else__<false, _TI, _TE>
      { typedef _TE type;};

      template<typename _T1, typename _T2>
      struct __eq__ : __false__
      { };
      template<typename _T>
      struct __eq__<_T, _T> : __true__
      { };

      template<typename _T1, typename _T2>
      struct __neq__ : __true__
      { };
      template<typename _T>
      struct __neq__<_T, _T> : __false__
      { };
    }
  }
}

#endif // ! __UTILITY_TRAIT_OPT___CONTROL____

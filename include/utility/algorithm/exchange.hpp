
#ifndef __UTILITY_ALGORITHM_EXCHANGE__
#define __UTILITY_ALGORITHM_EXCHANGE__

#include<utility/config/utility_config.hpp>

#include<utility/algorithm/move.hpp>
#include<utility/algorithm/forward.hpp>


__utility_globalspace_start(utility)
   __utility_interspace_start(algorithm)
  {
    /**
     * \brief Replaces the old value with new value and returns the old value.
     *
     * Replaces the old value \a _obj with new value \a _new and
     * returns the old value.
     *
     * \param _obj object whose value to replace
     * \param _new the value to assign to \a obj
     * \return the old value of _obj
     */
    template<typename _T, typename _U>
    __UTILITY_CPP17_CONSTEXPR__
    inline _T exchange(_T& _obj, _U&& _new)
    {
      using algorithm::move;
      using algorithm::forward;
      _T __old = move(_obj);
      _obj = forward<_U>(_new);
      return __old;
    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ALGORITHM_EXCHANGE__

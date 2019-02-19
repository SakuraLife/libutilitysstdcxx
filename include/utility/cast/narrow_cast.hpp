
#ifndef __UTILITY_CAST_NARROW_CAST__
#define __UTILITY_CAST_NARROW_CAST__

#include<utility/config/utility_config.hpp>

#include<utility/trait/type/categories/is_integral.hpp>
#include<utility/trait/type/categories/is_floating_point.hpp>
#include<utility/trait/opt/__control__.hpp>

// #include<utility/trait/type/releations/is_convertible.hpp>


__utility_globalspace_start(utility)
  __utility_interspace_start(cast)
    namespace __helper
    {
      using trait::__opt__::__if__;
      using trait::__opt__::__neq__;
      using trait::type::categories::is_integral;
      using trait::type::categories::is_floating_point;
    }

    inline namespace v1
    {
      template<
        typename _To, typename _From,
        typename __helper::__if__<
          __helper::is_integral<_From>::value &&
          __helper::is_integral<_To>::value &&
          __helper::__neq__<_From, _To>::value &&
          sizeof(_To) <= sizeof(_From),
          bool
        >::type = true
      >
      constexpr _To narrow_cast(const _From& _val) noexcept
      { return static_cast<_To>(_val);}

      template<
        typename _To, typename _From,
        typename __helper::__if__<
          __helper::is_floating_point<_From>::value &&
          __helper::is_floating_point<_To>::value &&
          sizeof(_To) < sizeof(_From),
          bool
        >::type = true
      >
      constexpr _To narrow_cast(const _From& _val) noexcept
      { return static_cast<_To>(_val);}

      template<
        typename _To, typename _From,
        typename __helper::__if__<
          __helper::is_integral<_From>::value &&
          __helper::is_floating_point<_To>::value,
          bool
        >::type = true
      >
      constexpr _To narrow_cast(const _From& _val) noexcept
      { return static_cast<_To>(_val);}

      template<
        typename _To, typename _From,
        typename __helper::__if__<
          __helper::is_integral<_From>::value &&
          __helper::is_floating_point<_To>::value,
          bool
        >::type = true
      >
      constexpr _To narrow_cast(const _From& _val) noexcept
      { return static_cast<_To>(_val);}
    }
  __utility_interspace_end(cast)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CAST_NARROW_CAST__


#ifndef __UTILITY_CONTAINER_UNEXPECTED__
#define __UTILITY_CONTAINER_UNEXPECTED__

#include<utility/config/utility_config.hpp>

#include<utility/container/container_helper.hpp>

#include<utility/algorithm/move.hpp>
#include<utility/algorithm/forward.hpp>

#include<utility/trait/type/releations/is_same.hpp>
#include<utility/trait/type/transform/decay.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(container)
    namespace __detail
    {
      using trait::type::releations::is_same;
      using trait::type::transform::decay_t;
    }
    struct __UTILITY_TYPE_VIS unexpect_t
    {
      explicit unexpect_t() = default;
    };

    __UTILITY_CPP17_INLINE__
    constexpr unexpect_t unexpect{};

    template<typename _E>
    class __UTILITY_TEMPLATE_VIS unexpected
    {
      public:
        typedef _E error_type;

      public:
        constexpr unexpected() = delete;
        constexpr unexpected(const error_type& _err): val{_err}
        { }
        constexpr unexpected(error_type&& _err): val{algorithm::move(_err)}
        { }

      public:
        __UTILITY_CPP14_CONSTEXPR__
        error_type& value() &
        { return val;}
        constexpr const error_type& value() const &
        { return val;}
        __UTILITY_CPP14_CONSTEXPR__
        error_type&& value() && noexcept
        {
          using algorithm::move;
          return move(val);
        }
        constexpr const error_type&& value() const && noexcept
        {
          using algorithm::move;
          return move(val);
        }

      private:
        error_type  val;
    };

    template <typename _E>
    constexpr bool operator==(
      const unexpected<_E>& _x, const unexpected<_E>& _y
    )
    { return _x.value() == _y.value();}
    template <typename _E>
    constexpr bool operator!=(
      const unexpected<_E>& _x, const unexpected<_E>& _y
    )
    { return _x.value() != _y.value();}
    template <typename _E>
    constexpr bool operator<(
      const unexpected<_E>& _x, const unexpected<_E>& _y
    )
    { return _x.value() < _y.value();}
    template <typename _E>
    constexpr bool operator>(
      const unexpected<_E>& _x, const unexpected<_E>& _y
    )
    { return _x.value() > _y.value();}
    template <typename _E>
    constexpr bool operator<=(
      const unexpected<_E>& _x, const unexpected<_E>& _y
    )
    { return _x.value() <= _y.value();}
    template <typename _E>
    constexpr bool operator>=(
      const unexpected<_E>& _x, const unexpected<_E>& _y
    )
    { return _x.value() >= _y.value();}

    template<typename _E>
    __UTILITY_CPP14_CONSTEXPR__
    inline unexpected<__detail::decay_t<_E>> make_unexpected(_E&& _e)
    {
      using algorithm::forward;
      return unexpected<__detail::decay_t<_E>>{forward<_E>(_e)};
    }

  __utility_interspace_end(container)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CONTAINER_UNEXPECTED__

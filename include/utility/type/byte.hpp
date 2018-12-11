
#ifndef __UTILITY_TYPE_BYTE__
#define __UTILITY_TYPE_BYTE__

#include<utility/config/utility_config.hpp>

namespace utility
{
  namespace type
  {
    namespace __impl
    {
      template<typename _T>
      struct __is_integer
      { };

      template<>
      struct __is_integer<bool>
      {
        typedef byte type;
        typedef bool integer_type;
      };
      template<>
      struct __is_integer<char>
      {
        typedef byte type;
        typedef char integer_type;
      };
      template<>
      struct __is_integer<signed char>
      {
        typedef byte type;
        typedef signed char integer_type;
      };
      template<>
      struct __is_integer<unsigned char>
      {
        typedef byte type;
        typedef unsigned char integer_type;
      };
      template<>
      struct __is_integer<int>
      {
        typedef byte type;
        typedef int integer_type;
      };
      template<>
      struct __is_integer<unsigned int>
      {
        typedef byte type;
        typedef unsigned int integer_type;
      };
      template<>
      struct __is_integer<long>
      {
        typedef byte type;
        typedef long integer_type;
      };
      template<>
      struct __is_integer<unsigned long>
      {
        typedef byte type;
        typedef unsigned long integer_type;
      };
      template<>
      struct __is_integer<long long>
      {
        typedef byte type;
        typedef long long integer_type;
      };
      template<>
      struct __is_integer<unsigned long long>
      {
        typedef byte type;
        typedef unsigned long long integer_type;
      };
      template<>
      struct __is_integer<wchar_t>
      {
        typedef byte type;
        typedef wchar_t integer_type;
      };
      template<>
      struct __is_integer<char16_t>
      {
        typedef byte type;
        typedef char16_t integer_type;
      };
      template<>
      struct __is_integer<char32_t>
      {
        typedef byte type;
        typedef char32_t integer_type;
      };

      template<typename _T>
      struct __is_integer<const _T>: __is_integer<_T>
      { };
      template<typename _T>
      struct __is_integer<volatile _T>: __is_integer<_T>
      { };
      template<typename _T>
      struct __is_integer<const volatile _T>: __is_integer<_T>
      { };

      class __bit_view
      {
        private:
          unsigned char&  __val;
          size_t          __offset;

        public:
          __bit_view() = delete;
          explicit __bit_view(unsigned char& _byte, size_t _offset) noexcept:
            __val{_byte}, __offset{_offset}
          { }
          __bit_view(const __bit_view&) = default;
          __bit_view(__bit_view&&) = default;

        public:
          __bit_view& operator=(const __bit_view&) = default;
          __bit_view& operator=(__bit_view&&) = default;

        public:
          __bit_view& operator=(bool _bit) noexcept
          {
            typedef unsigned char __base;
            __val |= __base{_bit} << __offset;
            return *this;
          }

        public:
          operator bool() const noexcept
          { return (__val >> __offset) & 1;}
      };
    }

    enum class byte: unsigned char
    { };

    template<typename _Integer>
    constexpr inline typename __impl::__is_integer<_Integer>::integer_type
    to_integer(byte _by) noexcept
    { return static_cast<_Integer>(static_cast<unsigned char>(_by));}


    class bit_field
    {
      private:
        unsigned char __byte;

      public:
        bit_field() = delete;
        bit_field(byte _by) noexcept:__byte{static_cast<unsigned char>(_by)}
        { }
        bit_field(const bit_field&) = default;
        bit_field(bit_field&&) = default;

      public:
        bit_field& operator=(const bit_field&) = default;
        bit_field& operator=(bit_field&&) = default;

      public:
        __impl::__bit_view operator[](size_t _pos) noexcept
        { return __impl::__bit_view{__byte, _pos};}
        bool operator[](size_t _pos) const noexcept
        { return (__byte >> _pos) & 1;}

      public:
        bool access(size_t _pos) const noexcept
        { return (__byte >> _pos) & 1;}
        void set(size_t _pos) noexcept
        { __byte |= 1U << _pos;}
        void unset(size_t _pos) noexcept
        { __byte &= ~(1U << _pos);}
        void flip(size_t _pos) noexcept
        { __byte ^= 1U << _pos;}
        void set() noexcept
        {
          typedef unsigned char __base;
          __byte = ~__base{0U};
        }
        void unset() noexcept
        { __byte = 0;}
        void flip() noexcept
        {
          typedef unsigned char __base;
          __byte ^= ~__base{0U};
        }

    };

    constexpr byte operator|(byte _x, byte _y) noexcept
    {
      return static_cast<byte>(
        static_cast<unsigned char>(_x) | static_cast<unsigned char>(_y)
      );
    }
    constexpr byte operator&(byte _x, byte _y) noexcept
    {
      return static_cast<byte>(
        static_cast<unsigned char>(_x) & static_cast<unsigned char>(_y)
      );
    }
    constexpr byte operator^(byte _x, byte _y) noexcept
    {
      return static_cast<byte>(
        static_cast<unsigned char>(_x) ^ static_cast<unsigned char>(_y)
      );
    }
    __UTILITY_CPP14_CONSTEXPR__
    inline byte& operator|=(byte& _x, byte _y) noexcept
    { return _x = (_x | _y);}
    __UTILITY_CPP14_CONSTEXPR__
    inline byte& operator&=(byte& _x, byte _y) noexcept
    { return _x = (_x & _y);}
    __UTILITY_CPP14_CONSTEXPR__
    inline byte& operator^=(byte& _x, byte _y) noexcept
    { return _x = (_x ^ _y);}

    constexpr inline byte operator~(byte _by) noexcept
    { return static_cast<byte>(~static_cast<unsigned char>(_by));}

    template<typename _Integer>
    constexpr inline typename type::__impl::__is_integer<_Integer>::type
    operator<<(byte _by, _Integer _shift) noexcept
    { return static_cast<byte>(static_cast<unsigned char>(_by) << _shift);}
    template<typename _Integer>
    constexpr inline typename type::__impl::__is_integer<_Integer>::type
    operator>>(byte _by, _Integer _shift) noexcept
    { return static_cast<byte>(static_cast<unsigned char>(_by) >> _shift);}
    template<typename _Integer>
    constexpr inline typename type::__impl::__is_integer<_Integer>::type
    operator<<=(byte& _by, _Integer _shift) noexcept
    { return _by = _by << _shift;}
    template<typename _Integer>
    constexpr inline typename type::__impl::__is_integer<_Integer>::type
    operator>>=(byte& _by, _Integer _shift) noexcept
    { return _by = _by >> _shift;}
  }

  using type::byte;

}

#endif // ! __UTILITY_TYPE_BYTE__

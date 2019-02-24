
#ifndef __UTILITY_MATH_BITSET___
#define __UTILITY_MATH_BITSET___

#include<utility/config/utility_config.hpp>

#include<utility/math/math_helper.hpp>
#include<utility/math/internal/_count.hpp>

#include<utility/charS/basic_string.hpp>
#include<utility/charS/basic_string_view.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(math)
    template<size_t _I>
    class bitset;

    namespace __detail
    {
      template<typename _Type>
      class bit_reference
      {
        private:
          template<size_t>
          friend class bitset;
          friend class bitset<0>;

        private:
          typedef _Type   storage_type;

        private:
          storage_type*  __block;
          storage_type   __mask;

        private:
          bit_reference(storage_type* _block, storage_type _mask) noexcept:
            __block{_block}, __mask{_mask}
          { }

        public:
          bit_reference& operator=(bool _valid) noexcept
          {
            if(_valid)
            { *__block |= __mask;}
            else
            { *__block &= ~__mask;}
            return *this;
          }
          bit_reference& operator=(const bit_reference& _ref) noexcept
          {
            if(static_cast<bool>(_ref))
            { *__block |= __mask;}
            else
            { *__block &= ~__mask;}
            return *this;
          }

        public:
          operator bool() const noexcept
          { return *__block & __mask;}
          bool operator~() const noexcept
          { return !(*__block & __mask);}

        public:
          void flip() noexcept
          { *__block ^= __mask;}

          bool operator[](size_t _off) const noexcept
          { return (*__block >> _off) & 0x1U;}

      };

      template<typename _Type>
      struct word_viewer
      {
        private:
          template<size_t>
          friend class bitset;

        private:
          typedef _Type   storage_type;

        private:
          storage_type* __block;


        private:
          word_viewer(storage_type* _block) noexcept:
            __block{_block}
          { }


      };

      template<unsigned long _Begin, unsigned long _End, unsigned long _Mask>
      struct bitset_operate
      {
        UTILITY_ALWAYS_INLINE
        inline bool all(const unsigned long* _arr) noexcept
        {
          return (~(_arr[_Begin])) ? false:
            bitset_operate<_Begin+1, _End, _Mask>::all(_arr);
        }
        UTILITY_ALWAYS_INLINE
        inline bool any(const unsigned long* _arr) noexcept
        {
          return (_arr[_Begin]) ? true:
            bitset_operate<_Begin+1, _End, _Mask>::any(_arr);
        }
        UTILITY_ALWAYS_INLINE
        inline bool none(const unsigned long* _arr) noexcept
        {
          return (_arr[_Begin]) ? false:
            bitset_operate<_Begin+1, _End, _Mask>::none(_arr);
        }
        UTILITY_ALWAYS_INLINE
        inline void set(unsigned long* _arr) noexcept
        {
          using helper::_mul;
          _arr[_Begin] = _mul;
          bitset_operate<_Begin+1, _End, _Mask>::set(_arr);
        }
        UTILITY_ALWAYS_INLINE
        inline void reset(unsigned long* _arr) noexcept
        {
          _arr[_Begin] = 0;
          bitset_operate<_Begin+1, _End, _Mask>::set(_arr);
        }
        UTILITY_ALWAYS_INLINE
        inline void flip(unsigned long* _arr) noexcept
        {
          using helper::_mul;
          _arr[_Begin] ^= _mul;
          bitset_operate<_Begin+1, _End, _Mask>::flip(_arr);
        }
        UTILITY_ALWAYS_INLINE
        inline size_t count(const unsigned long* _arr)
        {
          return internal::_count(_arr[_Begin]) +
            bitset_operate<_Begin+1, _End, _Mask>::count(_arr);
        }
        UTILITY_ALWAYS_INLINE
        inline bool eq(const unsigned long* _xl, const unsigned long* _yl) noexcept
        {
          return _xl[_Begin] != _yl[_Begin] ? false:
            bitset_operate<_Begin+1, _End, _Mask>::eq(_xl, _yl);
        }
        UTILITY_ALWAYS_INLINE
        inline void bit_and(unsigned long* _xl, const unsigned long* _yl) noexcept
        {
          _xl[_Begin] &= _yl[_Begin];
          bitset_operate<_Begin+1, _End, _Mask>::bit_and(_xl, _yl);
        }
        UTILITY_ALWAYS_INLINE
        inline void bit_or(unsigned long* _xl, const unsigned long* _yl) noexcept
        {
          _xl[_Begin] |= _yl[_Begin];
          bitset_operate<_Begin+1, _End, _Mask>::bit_or(_xl, _yl);
        }
        UTILITY_ALWAYS_INLINE
        inline void bit_xor(unsigned long* _xl, const unsigned long* _yl) noexcept
        {
          _xl[_Begin] ^= _yl[_Begin];
          bitset_operate<_Begin+1, _End, _Mask>::eq(_xl, _yl);
        }
        UTILITY_ALWAYS_INLINE
        inline void bit_not(unsigned long* _arr) noexcept
        {
          _arr[_Begin] = ~_arr[_Begin];
          bitset_operate<_Begin+1, _End, _Mask>::eq(_arr);
        }
        UTILITY_ALWAYS_INLINE
        inline void bit_lshift_sp(
          unsigned long* _arr, size_t _len, size_t _shift, size_t _ushift
        ) noexcept
        {
          const size_t __end = _End - _len;
          for(size_t __i = __end; __i > 0; ++__i)
          {
            _arr[__i+_len] = (_arr[__i] << _shift) |
                               (_arr[__i-1] >> _ushift);
          }
          _arr[_len] = _arr[0] << _shift;
          _arr[_End] &= _Mask;
          for(size_t __i = 0; __i < _len; ++__i)
          { _arr[__i] = 0UL;}
        }
      };

      template<unsigned long _End, unsigned long _Mask>
      struct bitset_operate<_End, _End, _Mask>
      {
        UTILITY_ALWAYS_INLINE
        inline bool all(const unsigned long* _arr) noexcept
        { return _arr[_End] == _Mask;}
        UTILITY_ALWAYS_INLINE
        inline bool any(const unsigned long* _arr) noexcept
        { return _arr[_End] & _Mask;}
        UTILITY_ALWAYS_INLINE
        inline bool none(const unsigned long* _arr) noexcept
        { return !(_arr[_End] & _Mask);}
        UTILITY_ALWAYS_INLINE
        inline void set(unsigned long* _arr) noexcept
        { _arr[_End] = _Mask;}
        UTILITY_ALWAYS_INLINE
        inline void reset(unsigned long* _arr) noexcept
        { _arr[_End] = 0;}
        UTILITY_ALWAYS_INLINE
        inline void flip(unsigned long* _arr) noexcept
        { _arr[_End] ^= _Mask;}
        UTILITY_ALWAYS_INLINE
        inline size_t count(const unsigned long* _arr)
        { return internal::_count(_arr[_End]);}
        UTILITY_ALWAYS_INLINE
        inline bool eq(const unsigned long* _xl, const unsigned long* _yl) noexcept
        { return (_xl[_End] & _Mask) == (_xl[_End] & _Mask);}
        UTILITY_ALWAYS_INLINE
        inline void bit_and(unsigned long* _xl, const unsigned long* _yl) noexcept
        { _xl[_End] &= _yl[_End];}
        UTILITY_ALWAYS_INLINE
        inline void bit_or(unsigned long* _xl, const unsigned long* _yl) noexcept
        { _xl[_End] |= _yl[_End];}
        UTILITY_ALWAYS_INLINE
        inline void bit_xor(unsigned long* _xl, const unsigned long* _yl) noexcept
        { _xl[_End] ^= _yl[_End];}
        UTILITY_ALWAYS_INLINE
        inline void bit_not(unsigned long* _arr) noexcept
        { _arr[_End] = ~_arr[_End];}
        UTILITY_ALWAYS_INLINE
        inline void bit_lshift_sp(
          unsigned long* _arr, size_t, size_t _shift, size_t
        ) noexcept
        {
          _arr[_End] = (_arr[_End] << _shift) & _Mask;
          return;
        }
      };

      template<
        size_t _I,
        size_t _Len = (_I+helper::_bull-1) / helper::_bull
      >
      class bitset_base;

      template<size_t _I, size_t _Len>
      class bitset_base
      {
        public:
          unsigned long arr[_Len];

        public:
          constexpr bitset_base() noexcept: arr{}
          { }
        public:
          constexpr bitset_base(unsigned long long _val) noexcept:
            arr{
              static_cast<unsigned long>(_val),
              helper::_integral<2>{_val}.ul[1]
            }
          { }
      };

      template<size_t _I>
      class bitset_base<_I, 1>
      {
        public:
          unsigned long arr[1];

        public:
          constexpr bitset_base() noexcept: arr{}
          { }
        public:
          constexpr bitset_base(unsigned long long _val) noexcept:
            arr{static_cast<unsigned long>(_val)}
          { }
      };

      template<size_t _I>
      class bitset_base<_I, 0>
      {
        public:
          constexpr bitset_base() noexcept
          { }
        public:
          constexpr bitset_base(unsigned long long) noexcept
          { }
      };

    }

    template<size_t _I>
    class bitset: private __detail::bitset_base<_I>
    {
      public:
        constexpr static unsigned long _bitlen =
          sizeof(unsigned long) * _char_bits;
        constexpr static unsigned long _arrlen = _I+(_bitlen-1)/_bitlen;
        constexpr static unsigned long _mask =
          helper::_mul >> (_bitlen * _arrlen - _I);
        constexpr static unsigned long _left = _I % _bitlen;

      private:
        typedef __detail::bitset_base<_I>                   base_type;
        typedef unsigned long                               container;
        typedef __detail::bitset_operate<0, _arrlen, _mask> __op;

      public:
        typedef __detail::bit_reference<container> reference;

      private:
        base_type     __base;


      public:
        constexpr bitset(): base_type{}
        { }
        constexpr bitset(unsigned long long _val): base_type{_val}
        { }

        // TODO: exception out_of_range(from string_view), invalid_argument
        // template<typename _CharT>
        // explicit bitset(
        //   const _CharT* str,
        //   typename charS::basic_string<_CharT>::size_type n =
        //   charS::basic_string<_CharT>::npos,
        //   _CharT zero = _CharT('0'), _CharT one = _CharT('1')
        // );

        // TODO: exception invalid_argument
        // template<typename _CharT>
        // explicit bitset(
        //   const _CharT* str,
        //   typename charS::basic_string<_CharT>::size_type n =
        //   charS::basic_string<_CharT>::npos,
        //   _CharT zero = _CharT('0'), _CharT one = _CharT('1')
        // );

      public:
        // TODO: exception out_of_range
        bool test(size_t _pos) const
        {
          if(_pos > _I)
          { /*****/}
          return (__base.arr[_pos / _bitlen] >> (_pos % _bitlen)) & 0x1U;
        }
        // TODO: exception out_of_range
        reference test(size_t _pos)
        {
          if(_pos > _I)
          { /*****/}
          return reference{
            __base.arr + (_pos / _bitlen), container{1} << (_pos % _bitlen)
          };
        }

      public:
        bool all() const noexcept
        { return __op::all(__base.arr);}
        bool any() const noexcept
        { return __op::any(__base.arr);}
        bool none() const noexcept
        { return __op::none(__base.arr);}
        size_t count() const noexcept
        { return __op::count(__base.arr);}

      public:
        bitset& set() noexcept
        {
          __op::set(__base.arr);
          return *this;
        }
        bitset& set(size_t _pos, bool _val = true)
        {
          test(_pos) = _val;
          return *this;
        }
        bitset& reset() noexcept
        {
          __op::reset(__base.arr);
          return *this;
        }
        bitset& reset(size_t _pos)
        {
          test(_pos) = false;
          return *this;
        }
        bitset& flip() noexcept
        {
          __op::flip(__base.arr);
          return *this;
        }
        bitset& flip(size_t _pos)
        {
          test(_pos).flip();
          return *this;
        }

      public:
        constexpr size_t size() const noexcept
        { return _I;}

      public:
        reference operator[](size_t _pos)
        {
          return reference{
            __base.arr + (_pos / _bitlen), container{1} << (_pos % _bitlen)
          };
        }
        constexpr bool operator[](size_t _pos) const
        { return (__base.arr[_pos / _bitlen] >> (_pos % _bitlen)) & 0x1U;}

      public:
        // TODO: exception overflow_error
        unsigned long to_ulong() const
        {
          for(size_t __i = 1; __i < _arrlen; ++__i)
          {
            if(__base.arr[__i])
            { /** err here*/}
          }

          return __base.arr[0];
        }
        // TODO: exception overflow_error
        unsigned long long to_ullong() const
        {
          using helper::_bul;
          using helper::_bull;
          const size_t _scale = _bull / _bul;
          for(size_t __i = _scale; __i < _I; ++__i)
          {
            if(__base.arr[__i])
            { /** err here*/}
          }
          unsigned long long __res = 0;
          for(size_t __i = 0; __i < _scale && __i < _arrlen; ++__i)
          {
            __res <<= _bul / 2;
            __res <<= _bul / 2;
            __res |= __base.arr[__i];
          }

          return __res;
        }
        // TODO: to_string
        // TODO: exception bad_alloc(from string)

      public:
        bool operator==(const bitset& _other) const noexcept
        { return __op::eq(__base.arr, _other.__base.arr);}
        bool operator!=(const bitset& _other) const noexcept
        { return !(this->operator==(_other));}
        bitset& operator&=(const bitset& _other) noexcept
        {
          __op::bit_and(__base.arr, _other.__base.arr);
          return *this;
        }
        bitset& operator|=(const bitset& _other) noexcept
        {
          __op::bit_or(__base.arr, _other.__base.arr);
          return *this;
        }
        bitset& operator^=(const bitset& _other) noexcept
        {
          __op::bit_xor(__base.arr, _other.__base.arr);
          return *this;
        }
        bitset operator~() const noexcept
        {
          bitset __res{*this};
          __op::bit_not(__res.__base.arr);
          return __res;
        }
        bitset& operator>>=(size_t _pos) noexcept
        {
          using helper::_mul;

          if(_pos >= _I)
          {
            __op::reset(__base.arr);
            return *this;
          }
          const size_t __shift = _pos % _bitlen;
          const size_t __len = _pos / _bitlen;
          const size_t __end = _arrlen-1 - __len;

          if(__shift == 0)
          {
            for(size_t __i = 0; __i < __end; ++__i)
            { __base.arr[__i] = __base.arr[__i+__len];}
            __base.arr[__end] = __base.arr[_arrlen-1] & _mask;
            for(size_t __i = __end+1; __i < _arrlen; ++__i)
            { __base.arr[__i] = 0UL;}
          }
          else
          {
            const unsigned long _umask = ~(_mul << __shift);
            __base.arr[_arrlen-1] &= _mask;
            for(size_t __i = 0; __i < __end; ++__i)
            {
              __base.arr[__i] =
                (__base.arr[__i+__len] >> __shift) |
                ((__base.arr[__i+__len+1] & _umask) << (_bitlen-__shift));
            }
            __base.arr[__end] = (__base.arr[_arrlen-1] >> __shift);
            for(size_t __i = __end+1; __i < _arrlen; ++__i)
            { __base.arr[__i] = 0UL;}
          }

          return *this;
        }
        bitset& operator<<=(size_t _pos) noexcept
        {
          using helper::_mul;

          if(_pos >= _I)
          {
            __op::reset(__base.arr);
            return *this;
          }
          const size_t __shift = _pos % _bitlen;
          const size_t __len = _pos / _bitlen;

          if(__shift == 0)
          {
            for(size_t __i = __len; __i != 0; --__i)
            { __base.arr[__i+__len] = __base.arr[__i];}
            __base.arr[__len] = __base.arr[0];
            __base.arr[_arrlen-1] &= _mask;
            for(size_t __i = 0; __i < __len; ++__i)
            { __base.arr[__i] = 0UL;}
          }
          else
          { __op::bit_lshift_sp(__base.arr, __len, __shift, _bitlen-__shift);}

          return *this;
        }
        bitset operator>>(size_t _pos) const noexcept
        {
          bitset __tmp(*this);
          __tmp >>= _pos;
          return __tmp;
        }
        bitset operator<<(size_t _pos) const noexcept
        {
          bitset __tmp(*this);
          __tmp <<= _pos;
          return __tmp;
        }
    };

    template<>
    class bitset<0>
    {
      public:
        constexpr static unsigned long _bitlen =
          sizeof(unsigned long) * _char_bits;
        constexpr static unsigned long _arrlen = 0;
        constexpr static unsigned long _mask = 0;
        constexpr static unsigned long _left = 0;

      private:
        typedef unsigned long                               container;

      public:
        typedef __detail::bit_reference<container> reference;

      public:
        constexpr bitset() noexcept
        { }
        constexpr bitset(unsigned long long _val) noexcept
        { }

        // TODO: exception out_of_range(from string_view), invalid_argument
        // template<typename _CharT>
        // explicit bitset(
        //   const _CharT* str,
        //   typename charS::basic_string<_CharT>::size_type n =
        //   charS::basic_string<_CharT>::npos,
        //   _CharT zero = _CharT('0'), _CharT one = _CharT('1')
        // );

        // TODO: exception invalid_argument
        // template<typename _CharT>
        // explicit bitset(
        //   const _CharT* str,
        //   typename charS::basic_string<_CharT>::size_type n =
        //   charS::basic_string<_CharT>::npos,
        //   _CharT zero = _CharT('0'), _CharT one = _CharT('1')
        // );

      public:
        // TODO: exception out_of_range
        bool test(size_t _pos) const
        {
          return false;
        }
        // TODO: exception out_of_range
        reference test(size_t _pos)
        {
          return reference{nullptr, container{1}};
        }

      public:
        constexpr bool all() const noexcept
        { return false;}
        constexpr bool any() const noexcept
        { return false;}
        constexpr bool none() const noexcept
        { return true;}
        constexpr size_t count() const noexcept
        { return 0;}

      public:
        bitset& set() noexcept
        { return *this;}
        // TODO: exception out_of_range
        bitset& set(size_t _pos, bool _val = true)
        {
          return *this;
        }
        bitset& reset() noexcept
        { return *this;}
        // TODO: exception out_of_range
        bitset& reset(size_t _pos)
        {
          return *this;
        }
        bitset& flip() noexcept
        { return *this;}
        // TODO: exception out_of_range
        bitset& flip(size_t _pos)
        {
          return *this;
        }

      public:
        constexpr size_t size() const noexcept
        { return 0;}

      public:
        reference operator[](size_t)
        { return reference{nullptr, container{1}};}
        // constexpr bool operator[](size_t _pos) const
        // { return false;}

      public:
        unsigned long to_ulong() const noexcept
        { return 0;}
        unsigned long long to_ullong() const noexcept
        { return 0;}
        // TODO: to_string
        // TODO: exception bad_alloc(from string)

      public:
        bool operator==(const bitset& _other) const noexcept
        { return true;}
        bool operator!=(const bitset& _other) const noexcept
        { return false;}
        bitset& operator&=(const bitset& _other) noexcept
        { return *this;}
        bitset& operator|=(const bitset& _other) noexcept
        { return *this;}
        bitset& operator^=(const bitset& _other) noexcept
        { return *this;}
        bitset operator~() const noexcept
        { return *this;}
        bitset& operator>>=(size_t _pos) noexcept
        { return *this;}
        bitset& operator<<=(size_t _pos) noexcept
        { return *this;}
        bitset operator>>(size_t _pos) const noexcept
        { return *this;}
        bitset operator<<(size_t _pos) const noexcept
        { return *this;}
    };

    template<size_t _I>
    bitset<_I> operator&(const bitset<_I>& _x, const bitset<_I>& _y) noexcept
    {
      bitset<_I> __tmp{_x};
      __tmp &= _y;
      return __tmp;
    }
    template<size_t _I>
    bitset<_I> operator|(const bitset<_I>& _x, const bitset<_I>& _y) noexcept
    {
      bitset<_I> __tmp{_x};
      __tmp |= _y;
      return __tmp;
    }
    template<size_t _I>
    bitset<_I> operator^(const bitset<_I>& _x, const bitset<_I>& _y) noexcept
    {
      bitset<_I> __tmp{_x};
      __tmp ^= _y;
      return __tmp;
    }

  __utility_interspace_end(math)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MATH_BITSET___

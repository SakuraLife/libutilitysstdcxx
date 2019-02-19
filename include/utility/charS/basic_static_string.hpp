
#ifndef __UTILITY_CHARS_BASIC_STATIC_STRING__
#define __UTILITY_CHARS_BASIC_STATIC_STRING__

#include<utility/config/utility_config.hpp>

#include<utility/charS/impl/string_find.hpp>

#include<utility/algorithm/swap.hpp>
#include<utility/algorithm/possible_swap.hpp>
#include<utility/algorithm/move.hpp>
#include<utility/algorithm/impl/min.hpp>

#include<utility/trait/type/releations/is_same.hpp>
#include<utility/trait/type/releations/is_convertible.hpp>
#include<utility/trait/type/property/is_standard_layout.hpp>
#include<utility/trait/type/property/is_trivial.hpp>
#include<utility/trait/type/features/is_nothrow_swappable.hpp>

#include<utility/charS/char_traits.hpp>
#include<utility/charS/basic_string_view.hpp>

#include<utility/memory/uninitialized_copy.hpp>
#include<utility/memory/uninitialized_possible_move.hpp>

#include<utility/iterator/iterator_traits.hpp>
#include<utility/iterator/reverse_iterator.hpp>
#include<utility/iterator/raw_pointer_iterator.hpp>
#include<utility/iterator/distance.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(charS)
    namespace __detail
    {
      using namespace iterator;
      using trait::type::categories::is_array;
      using trait::type::property::is_standard_layout;
      using trait::type::property::is_trivial;
      using trait::type::releations::is_same;
      using trait::type::releations::is_convertible;
      using trait::type::miscellaneous::enable_if;
    }

    template<
      typename _CharT,
      size_t    _Len,
      typename  _Traits = char_traits<_CharT>
    >
    class __UTILITY_TEMPLATE_VIS basic_static_string
    {
      public:
        typedef _CharT                value_type;
        typedef _CharT                char_type;
        typedef value_type&           reference;
        typedef const value_type      const_value_type;
        typedef const value_type&     const_reference;
        typedef _Traits               traits_type;
        typedef _CharT*               pointer;
        typedef const _CharT*         const_pointer;
        typedef size_t                size_type;
        typedef ptrdiff_t             difference_type;

      public:
        typedef basic_string_view<char_type, traits_type>   view_type;

      public:
        typedef __detail::raw_pointer_iterator<pointer>         iterator;
        typedef __detail::raw_pointer_iterator<const_pointer>   const_iterator;
        typedef __detail::reverse_iterator<iterator>        reverse_iterator;
        typedef __detail::reverse_iterator<const_iterator>  const_reverse_iterator;

      public:
        constexpr static size_type npos = /*static_cast<size_type>*/(-1);

      public:
        static_assert(
          !__detail::is_array<value_type>::value,
          "The char type of the basic_static_string can't be an array"
        );
        static_assert(
          _Len > 0,
          "basic_static_string's length need to be longer than 0"
        );
        static_assert(
          __detail::is_standard_layout<value_type>::value,
          "The char type of the basic_static_string must have standard layout"
        );
        static_assert(
          __detail::is_trivial<value_type>::value,
          "The char type of the basic_static_string must be trivial"
        );
        static_assert(
          __detail::is_same<typename traits_type::char_type, value_type>::value,
          "The traits_type::char_type must be the same as value_type(_CharT)"
        );

      private:
        constexpr static size_type _strlen = _Len - 1U;

      public:
        char_type       value[_Len];
        size_type       len;

      public:
        constexpr basic_static_string() noexcept: value{}, len{0U}
        { }
        __UTILITY_CPP14_CONSTEXPR__
        basic_static_string(const char_type* _str, size_type _count) noexcept:
          value{}, len{}
        {
          size_t __i = 0;
          // if(_count > _strlen)
          // {
          //   for(; __i != _strlen; ++__i)
          //   { value[__i] = _str[__i];}
          // }
          // else
          // {
            for(; __i != _count; ++__i)
            { value[__i] = _str[__i];}
          // }
          // value[__i] = char_type{};
          len = __i;
        }
        __UTILITY_CPP14_CONSTEXPR__
        basic_static_string(const char_type* _str) noexcept: value{}, len{}
        {
          size_t __i = 0;
          size_type __count = traits_type::length(_str);
          // if(__count > _strlen)
          // {
          //   for(; __i != _strlen; ++__i)
          //   { value[__i] = _str[__i];}
          // }
          // else
          // {
            for(; __i != __count; ++__i)
            { value[__i] = _str[__i];}
          // }
          value[__i] = char_type{};
          len = __i;
        }

        constexpr basic_static_string(
          const basic_static_string&
        ) noexcept = default;

      public:
        __UTILITY_CPP14_CONSTEXPR__
        basic_static_string& operator=(
          const basic_static_string&
        ) noexcept = default;

      public:
        basic_static_string& operator=(const char_type* _str)
        {
          size_t __i = 0;
          size_type __count = traits_type::length(_str);
          for(; __i != __count; ++__i)
          { value[__i] = _str[__i];}
          value[__i] = char_type{};
          len = __i;
          return *this;
        }

      public:
        __UTILITY_CPP14_CONSTEXPR__
        const_reference operator[](size_type _pos) const
        { return value[_pos];}
        reference operator[](size_type _pos)
        { return value[_pos];}
        __UTILITY_CPP14_CONSTEXPR__
        const_reference at(size_type _pos) const
        {
          if(_pos > len)
          { }
          return value[_pos];
        }

      public:
        __UTILITY_CPP14_CONSTEXPR__
        bool empty() const noexcept
        { return len == 0U;}
        __UTILITY_CPP14_CONSTEXPR__
        size_type size() const noexcept
        { return len;}
        __UTILITY_CPP14_CONSTEXPR__
        size_type length() const noexcept
        { return len;}
        constexpr size_type capacity() const noexcept
        { return _Len;}
        constexpr size_type valid_capacity() const noexcept
        { return _Len - 1;}
        __UTILITY_CPP14_CONSTEXPR__
        size_type max_size() const noexcept
        { return npos;}

      public:
        __UTILITY_CPP14_CONSTEXPR__
        reference front() noexcept
        { return *value;}
        __UTILITY_CPP14_CONSTEXPR__
        const_reference front() const noexcept
        { return *value;}
        __UTILITY_CPP14_CONSTEXPR__
        reference back() noexcept
        { return value[len-1];}
        __UTILITY_CPP14_CONSTEXPR__
        const_reference back() const noexcept
        { return value[len-1];}

      public:
        __UTILITY_CPP14_CONSTEXPR__
        inline pointer data() noexcept
        { return value;}
        __UTILITY_CPP14_CONSTEXPR__
        inline const_pointer data() const noexcept
        { return value;}
        __UTILITY_CPP14_CONSTEXPR__
        inline const_pointer c_str() const noexcept
        { return value;}

      private:
        __UTILITY_CPP14_CONSTEXPR__
        inline pointer data_end() noexcept
        { return value + len;}
        __UTILITY_CPP14_CONSTEXPR__
        inline const_pointer data_end() const noexcept
        { return value + len;}

      public:
        __UTILITY_CPP14_CONSTEXPR__
        iterator begin() noexcept
        { return iterator{value};}
        __UTILITY_CPP14_CONSTEXPR__
        const_iterator begin() const noexcept
        { return const_iterator{value};}
        __UTILITY_CPP14_CONSTEXPR__
        const_iterator cbegin() const noexcept
        { return const_iterator{value};}
        __UTILITY_CPP14_CONSTEXPR__
        iterator end() noexcept
        { return iterator{value + len};}
        __UTILITY_CPP14_CONSTEXPR__
        const_iterator end() const noexcept
        { return const_iterator{value + len};}
        __UTILITY_CPP14_CONSTEXPR__
        const_iterator cend() const noexcept
        { return const_iterator{value + len};}

      public:
        __UTILITY_CPP14_CONSTEXPR__
        reverse_iterator rbegin() noexcept
        { return reverse_iterator{end()};}
        __UTILITY_CPP14_CONSTEXPR__
        const_reverse_iterator rbegin() const noexcept
        { return const_reverse_iterator{end()};}
        __UTILITY_CPP14_CONSTEXPR__
        const_reverse_iterator crbegin() const noexcept
        { return const_reverse_iterator{end()};}
        __UTILITY_CPP14_CONSTEXPR__
        reverse_iterator rend() noexcept
        { return reverse_iterator{begin()};}
        __UTILITY_CPP14_CONSTEXPR__
        const_reverse_iterator rend() const noexcept
        { return const_reverse_iterator{begin()};}
        __UTILITY_CPP14_CONSTEXPR__
        const_reverse_iterator crend() const noexcept
        { return const_reverse_iterator{begin()};}

      public:
        operator basic_string_view<char_type, traits_type>() const noexcept
        { return basic_string_view<char_type, traits_type>{value, len};}

      public:
        void resize(size_type _count, char_type _ch = char_type{})
        {
          if(_count < len)
          { value[_count] = char_type{};}
          else
          {
            size_type __sfill = _count - len;
            *traits_type::assign(data_end(), __sfill, _ch) = char_type{};
          }
          len = _count;
          return;
        }
        void clear() noexcept
        {
          value[0] = char_type{};
          len = 0;
        }

      public:
        inline void push_back(char_type _ch)
        { append(1U, _ch);}

      public:
        basic_static_string& append(size_type _count, char_type _ch) noexcept
        {
          if(_count == 0)
          { return *this;}
          char_type* __pos = data_end();
          for(; _count; --_count)
          { *__pos++ = _ch;}
          *__pos = char_type{};
          len += _count;
          return *this;
        }
        template<
          typename _Iterator,
          typename __detail::enable_if<
            __detail::is_iterator<_Iterator>::value,
            bool
          >::type = true
        >
        basic_static_string& append(_Iterator _first, _Iterator _last)
        {
          using memory::uninitialized_copy;
          using __detail::distance;

          if(_first != _last)
          {
            char_type* __ptr =
              uninitialized_copy(_first, _last, data_end());
            *__ptr = char_type{};
            len += distance(_first, _last);
          }
          return *this;
        }
        inline basic_static_string& append(
          const basic_static_string& _str
        )
        { return append(_str.data(), _str.data_end());}
        inline basic_static_string& append(
          const basic_static_string& _str,
          size_type _pos, size_type _count = npos
        )
        {
          _str.check_pos(_pos);
          if(_pos+_count > _str.size())
          { _count = _str.size();}
          else
          { _count += _pos;}
          return append(_str.data() + _pos, _str.data()+_count);
        }
        inline basic_static_string& append(
          const char_type* _str, size_type _count
        )
        { return append(_str, _str+_count);}
        inline basic_static_string& append(const char_type* _str)
        {
          const char_type* __send = _str;
          for(; *__send; ++__send)
          { }
          return append(_str, __send);
        }
        inline basic_static_string& append(
          container::initializer_list<char_type> _init
        )
        { return append(_init.first(), _init.end());}
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        inline basic_static_string& append(const _T& _sv)
        {
          view_type __sv = _sv;
          return append(__sv.first(), __sv.end());
        }
        inline basic_static_string& append(char_type _ch)
        { return append(1, _ch);}

      private:
        iterator __insert(
          size_type _pos, size_type _count, char_type _ch
        )
        {
          using memory::uninitialized_possible_move_backward;

          check_pos(_pos);

          char_type* __ptr = value + _pos;
          uninitialized_possible_move_backward(
            __ptr, data_end() + 1,
            data_end() + 1 + _count
          );
          traits_type::assign(__ptr, _count, _ch);
          return iterator{__ptr};
        }
        template<
          typename _Iterator,
          typename __detail::enable_if<
            __detail::is_iterator<_Iterator>::value,
            bool
          >::type = true
        >
        iterator __insert(
          size_type _pos, _Iterator _first, _Iterator _last
        )
        {
          check_pos(_pos);

          size_type _count =
            static_cast<size_type>(__detail::distance(_first, _last));

          char_type* __ptr= value + _pos;

          uninitialized_possible_move_backward(
            __ptr, data_end() + 1,
            data_end() + 1 + _count
          );
          uninitialized_copy(_first, _last, __ptr);

          return iterator{__ptr};
        }

      public:
        inline basic_static_string& insert(
          size_type _pos, size_type _count, char_type _ch
        ) noexcept
        {
          __insert(_pos, _count, _ch);
          return *this;
        }
        inline basic_static_string& insert(
          size_type _pos, const char_type* _str
        ) noexcept
        {
          char_type* __send = _str;
          for(; *__send; ++__send)
          { }
          __insert(_pos, _str, __send);
          return *this;
        }
        inline basic_static_string& insert(
          size_type _pos, const char_type* _str, size_type _count
        )
        {
          __insert(_pos, _str, _str+_count);
          return *this;
        }
        inline basic_static_string& insert(size_type _pos, const basic_static_string& _str)
        {
          __insert(_pos, _str.data(), _str.data_end());
          return *this;
        }
        inline basic_static_string& insert(
          size_type _pos, const basic_static_string& _str,
          size_type _idx, size_type _count = npos
        )
        {
          container::pair<const char_type*, const char_type*> __sp =
            _str.substr_ptr(_idx, _count);
          __insert(_pos, __sp.first, __sp.second);
          return *this;
        }
        inline iterator insert(const_iterator _pos, char_type _ch)
        { return __insert(_pos - value, 1U, _ch);}
        inline iterator insert(
          const_iterator _pos, size_type _count, char_type _ch
        )
        { return __insert(_pos - value, _count, _ch);}
        template<
          typename _Iterator,
          typename __detail::enable_if<
            __detail::is_iterator<_Iterator>::value,
            bool
          >::type = true
        >
        inline iterator __insert(
          const_iterator _pos,
          _Iterator _first, _Iterator _last
        )
        { return __insert(_pos - value, _first, _last);}
        inline iterator insert(
          const_iterator _pos,
          container::initializer_list<char_type> _init
        )
        {
          return __insert(
            _pos - value, _init.first(), _init.end()
          );
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        inline basic_static_string& insert(size_type _pos, const _T& _sv)
        {
          view_type __sv = _sv;
          __insert(_pos, __sv.first(), __sv.end());
          return *this;
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        inline basic_static_string& insert(
          size_type _pos, const _T& _sv,
          size_type _idx, size_type _count = npos
        )
        {
          view_type __sv = _sv;
          __sv = __sv.substr(_idx, _count);
          __insert(_pos, __sv.first(), __sv.end());
          return *this;
        }

      public:
        basic_static_string& erase(
          size_type _idx = 0U, size_type _count = npos
        ) noexcept
        {
          using algorithm::min;
          using memory::uninitialized_possible_move;

          check_pos(_idx);

          _count = min(_count, size() - _idx);
          char_type* __ebegin = value + _idx;
          char_type* __eend = __ebegin + _count;
          *uninitialized_possible_move(
            __eend, data_end(), __ebegin
          ) = char_type{};
          len -= _count;
          return *this;
        }
        inline iterator erase(const_iterator _pos) noexcept
        {
          size_type __where = _pos - value;
          erase(__where, 1U);
          return iterator{value + __where};
        }
        inline iterator erase(
          const_iterator _first, const_iterator _last
        ) noexcept
        {
          size_type __where = _first - value;
          erase(__where, static_cast<size_type>(_last-_first));
          return iterator{value + __where};
        }

      public:
        basic_static_string& replace(
          size_type _pos, size_type _count,
          size_type _slen, char_type _ch
        )
        {
          using algorithm::min;

          check_pos(_pos);
          _count = min(len - _pos, _count);
          size_type __ns = len - _count + _slen;

          traits_type::move(
            value + _pos + _slen, value + _pos + _count,
            __ns - _pos - _count + 1
          );
          char_type* __ptr = value + _pos;
          for( ; _slen; --_slen)
          { *__ptr++ = _ch;}
          len = __ns;

          return *this;
        }
        template<
          typename _Iterator,
          typename __detail::enable_if<
            __detail::is_iterator<_Iterator>::value,
            bool
          >::type = true
        >
        basic_static_string& replace(
          size_type _pos, size_type _count,
          _Iterator _first, _Iterator _last
        )
        {
          using algorithm::min;

          check_pos(_pos);

          _count = min(len - _pos, _count);
          size_type __slen =
            static_cast<size_type>(__detail::distance(_first, _last));
          size_type __ns = len - _count + __slen;

          traits_type::move(
            value + _pos + __slen, value + _pos + _count,
            __ns - _pos - _count + 1
          );
          char_type* __ptr = value + _pos;

          for(; _first != _last;)
          { *__ptr++ = *_first++;}

          len = __ns;

          return *this;
        }
        basic_static_string& replace(
          const_iterator _first, const_iterator _last,
          size_type _slen, char_type _ch
        )
        {
          return replace(
            _first - value,
            static_cast<size_type>(_last-_first),
            _slen, _ch
          );
        }
        basic_static_string& replace(
          size_type _pos, size_type _count,
          const basic_static_string& _str
        )
        { return replace(_pos, _count, _str.data(), _str.data_end());}
        basic_static_string& replace(
          const_iterator _first, const_iterator _last,
          const basic_static_string& _str
        )
        {
          return replace(
            _first - value,
            static_cast<size_type>(_last-_first),
            _str.data(), _str.data_end()
          );
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        basic_static_string& replace(
          size_type _pos, size_type _count, const _T& _sv
        )
        {
          view_type __sv = _sv;
          return replace(_pos, _count, __sv.begin(), __sv.end());
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        basic_static_string& replace(
          size_type _pos, size_type _count, const _T& _sv,
          size_type _idx, size_type _clen
        )
        {
          view_type __sv = _sv;
          __sv = __sv.substr(_idx, _clen);
          return replace(_pos, _count, __sv.begin(), __sv.end());
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        basic_static_string& replace(
          const_iterator _first, const_iterator _last, const _T& _sv
        )
        {
          view_type __sv = _sv;
          return replace(
            _first - value,
            static_cast<size_type>(_last-_first),
            __sv.begin(), __sv.end()
          );
        }
        basic_static_string& replace(
          size_type _pos, size_type _count,
          const basic_static_string& _str,
          size_type _idx, size_type _slen = npos
        )
        {
          container::pair<const char_type*, const char_type*> __sp =
            _str.substr_ptr(_idx, _slen);
          return replace(_pos, _count, __sp.first, __sp.second);
        }
        template<
          typename _Iterator,
          typename __detail::enable_if<
            __detail::is_iterator<_Iterator>::value,
            bool
          >::type = true
        >
        basic_static_string& replace(
          const_iterator _first, const_iterator _last,
          _Iterator _sfirst, _Iterator _slast
        )
        {
          return replace(
            _first - value,
            static_cast<size_type>(_last-_first),
            _sfirst, _slast
          );
        }
        basic_static_string& replace(
          size_type _pos, size_type _count,
          const char_type* _str, size_type _slen
        )
        { return replace(_pos, _count, _str, _str+_slen);}
        basic_static_string& replace(
          const_iterator _first, const_iterator _last,
          const char_type* _str, size_type _slen
        )
        {
          return replace(
            _first - value,
            static_cast<size_type>(_last-_first),
            _str, _str+_slen
          );
        }
        basic_static_string& replace(
          size_type _pos, size_type _count,
          const char_type* _str
        )
        {
          const char_type* __send = _str;
          for(; *__send; ++__send)
          { }
          return replace(_pos, _count, _str, __send);
        }
        basic_static_string& replace(
          const_iterator _first, const_iterator _last,
          const char_type* _str
        )
        {
          const char_type* __send = _str;
          for(; *__send; ++__send)
          { }
          return replace(
            _first - value,
            static_cast<size_type>(_last-_first),
            _str, __send
          );
        }

      public:
        template<size_t _Nlen = _Len>
        __UTILITY_CPP14_CONSTEXPR__
        basic_static_string<char_type, _Nlen, traits_type>
        substr(size_type _offset, size_type _count = npos) const noexcept
        {
          typedef basic_static_string<char_type, _Nlen, traits_type> _res_type;

          ///< TODO: Exception
          if(_offset > len)
          { }

          if(_offset + _count > len || _count == npos)
          { _count = len-_offset;}
          return _res_type{value + _offset, _count};
        }

      public:
        int compare(
          size_type _pos, size_type _count,
          const char_type* _str, size_type _clen
        ) const noexcept
        {
          using algorithm::min;
          container::pair<const char_type*, const char_type*> __sp =
            substr_ptr(_pos, _count);
          _count = static_cast<size_type>(__sp.second - __sp.first);
          size_type __len = min(_count, _clen);
          int __res = traits_type::compare(__sp.first, _str, __len);
          if(__res)
          { return __res;}
          return _count == _clen ? 0 : (_count < _clen ? -1 : 1);
        }
        int compare(const basic_static_string& _str) const noexcept
        { return compare(0U, npos, _str.data(), _str.size());}
        int compare(
          size_type _pos, size_type _count,
          const basic_static_string& _str
        ) const noexcept
        { return compare(_pos, _count, _str.data(), _str.size());}
        int compare(
          size_type _pos, size_type _count,
          const basic_static_string& _str,
          size_type _idx, size_type _clen
        ) const noexcept
        {
          container::pair<const char_type*, const char_type*> __sp =
            _str.substr_ptr(_idx, _clen);
          return compare(
            _pos, _count, __sp.first,
            static_cast<size_type>(__sp.second-__sp.first)
          );
        }
        int compare(const char_type* _str) const noexcept
        {
          size_type __clen = 0U;
          for(; *_str; ++_str, ++__clen)
          { }
          return compare(0U, npos, _str-__clen, __clen);
        }
        int compare(
          size_type _pos, size_type _count,
          const char_type* _str
        ) const noexcept
        {
          size_type __clen = 0U;
          for(; *_str; ++_str, ++__clen)
          { }
          return compare(_pos, _count, _str-__clen, __clen);
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        int compare(const _T& _sv) const noexcept
        {
          view_type __sv = _sv;
          return compare(0U, npos, __sv.data(), __sv.size());
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        int compare(
          size_type _pos, size_type _count, const _T& _sv
        ) const noexcept
        {
          view_type __sv = _sv;
          return compare(_pos, _count, __sv.data(), __sv.size());
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        int compare(
          size_type _pos, size_type _count, const _T& _sv,
          size_type _idx, size_type _clen
        ) const noexcept
        {
          view_type __sv = _sv;
          __sv = __sv.substr(_idx, _clen);
          return compare(_pos, _count, __sv.data(), __sv.size());
        }

      public:
        size_type copy(
          char_type* _dest, size_type _count, size_type _pos = 0U
        ) const
        {
          container::pair<const char_type*, const char_type*> __sp =
            substr_ptr(_pos, _count);
          size_type __ns = static_cast<size_type>(__sp.second-__sp.first);
          traits_type::assign(_dest, __sp.first, __ns);
          return __ns;
        }


      public:
        size_type find(
          const basic_static_string& _str, size_type _pos = 0
        ) const noexcept
        {
          return impl::__find<char_type, traits_type, size_type, npos>(
            data(), size(), _str.data(), _str.size(), check_pos(_pos)
          );
        }
        size_type find(
          const char_type* _str, size_type _pos = 0
        ) const noexcept
        {
          return impl::__find<char_type, traits_type, size_type, npos>(
            data(), size(), _str, traits_type::length(_str), check_pos(_pos)
          );
        }
        size_type find(
          const char_type* _str, size_type _pos, size_type _count
        ) const noexcept
        {
          return impl::__find<char_type, traits_type, size_type, npos>(
            data(), size(), _str, _count, check_pos(_pos)
          );
        }
        size_type find(char_type _ch, size_type _pos = 0) const noexcept
        {
          return impl::__find<char_type, traits_type, size_type, npos>(
            data(), size(), _ch, check_pos(_pos)
          );
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        size_type find(const _T& _sv, size_type _pos = 0) const noexcept
        {
          view_type __sv = _sv;
          return impl::__find<char_type, traits_type, size_type, npos>(
            data(), size(), __sv.data(), __sv.size(), check_pos(_pos)
          );
        }
        size_type rfind(
          const basic_static_string& _str, size_type _pos = npos
        ) const noexcept
        {
          return impl::__rfind<char_type, traits_type, size_type, npos>(
            data(), size(), _str.data(), _str.size(), check_pos(_pos)
          );
        }
        size_type rfind(
          const char_type* _str, size_type _pos = npos
        ) const noexcept
        {
          return impl::__rfind<char_type, traits_type, size_type, npos>(
            data(), size(), _str, traits_type::length(_str), check_pos(_pos)
          );
        }
        size_type rfind(
          const char_type* _str, size_type _pos, size_type _count
        ) const noexcept
        {
          return impl::__rfind<char_type, traits_type, size_type, npos>(
            data(), size(), _str, _count, check_pos(_pos)
          );
        }
        size_type rfind(char_type _ch, size_type _pos = npos) const noexcept
        {
          return impl::__rfind<char_type, traits_type, size_type, npos>(
            data(), size(), _ch, check_pos(_pos)
          );
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        size_type rfind(const _T& _sv, size_type _pos = npos) const noexcept
        {
          view_type __sv = _sv;
          return impl::__rfind<char_type, traits_type, size_type, npos>(
            data(), size(), __sv.data(), __sv.size(), check_pos(_pos)
          );
        }

      public:
        size_type find_first_of(
          const basic_static_string& _str, size_type _pos = 0
        ) const noexcept
        {
          return impl::__find_first_of<char_type, traits_type, size_type, npos>(
            data(), size(), _str.data(), _str.size(), check_pos(_pos)
          );
        }
        size_type find_first_of(
          const char_type* _str, size_type _pos = 0
        ) const noexcept
        {
          return impl::__find_first_of<char_type, traits_type, size_type, npos>(
            data(), size(), _str, traits_type::length(_str), check_pos(_pos)
          );
        }
        size_type find_first_of(
          const char_type* _str, size_type _pos, size_type _count
        ) const noexcept
        {
          return impl::__find_first_of<char_type, traits_type, size_type, npos>(
            data(), size(), _str, _count, check_pos(_pos)
          );
        }
        size_type find_first_of(char_type _ch, size_type _pos = 0) const noexcept
        {
          return impl::__find_first_of<char_type, traits_type, size_type, npos>(
            data(), size(), _ch, check_pos(_pos)
          );
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        size_type find_first_of(const _T& _sv, size_type _pos = 0) const noexcept
        {
          view_type __sv = _sv;
          return impl::__find_first_of<char_type, traits_type, size_type, npos>(
            data(), size(), __sv.data(), __sv.size(), check_pos(_pos)
          );
        }
        size_type find_last_of(
          const basic_static_string& _str, size_type _pos = npos
        ) const noexcept
        {
          return impl::__find_last_of<char_type, traits_type, size_type, npos>(
            data(), size(), _str.data(), _str.size(), check_pos(_pos)
          );
        }
        size_type find_last_of(
          const char_type* _str, size_type _pos = npos
        ) const noexcept
        {
          return impl::__find_last_of<char_type, traits_type, size_type, npos>(
            data(), size(), _str, traits_type::length(_str), check_pos(_pos)
          );
        }
        size_type find_last_of(
          const char_type* _str, size_type _pos, size_type _count
        ) const noexcept
        {
          return impl::__find_last_of<char_type, traits_type, size_type, npos>(
            data(), size(), _str, _count, check_pos(_pos)
          );
        }
        size_type find_last_of(char_type _ch, size_type _pos = npos) const noexcept
        {
          return impl::__find_last_of<char_type, traits_type, size_type, npos>(
            data(), size(), _ch, check_pos(_pos)
          );
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        size_type find_last_of(const _T& _sv, size_type _pos = npos) const noexcept
        {
          view_type __sv = _sv;
          return impl::__find_last_of<char_type, traits_type, size_type, npos>(
            data(), size(), __sv.data(), __sv.size(), check_pos(_pos)
          );
        }
        size_type find_first_not_of(
          const basic_static_string& _str, size_type _pos = 0
        ) const noexcept
        {
          return impl::__find_first_not_of<char_type, traits_type, size_type, npos>(
            data(), size(), _str.data(), _str.size(), check_pos(_pos)
          );
        }
        size_type find_first_not_of(
          const char_type* _str, size_type _pos = 0
        ) const noexcept
        {
          return impl::__find_first_not_of<char_type, traits_type, size_type, npos>(
            data(), size(), _str, traits_type::length(_str), check_pos(_pos)
          );
        }
        size_type find_first_not_of(
          const char_type* _str, size_type _pos, size_type _count
        ) const noexcept
        {
          return impl::__find_first_not_of<char_type, traits_type, size_type, npos>(
            data(), size(), _str, _count, check_pos(_pos)
          );
        }
        size_type find_first_not_of(char_type _ch, size_type _pos = 0) const noexcept
        {
          return impl::__find_first_not_of<char_type, traits_type, size_type, npos>(
            data(), size(), _ch, check_pos(_pos)
          );
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        size_type find_first_not_of(const _T& _sv, size_type _pos = 0) const noexcept
        {
          view_type __sv = _sv;
          return impl::__find_first_not_of<char_type, traits_type, size_type, npos>(
            data(), size(), __sv.data(), __sv.size(), check_pos(_pos)
          );
        }
        size_type find_last_not_of(
          const basic_static_string& _str, size_type _pos = npos
        ) const noexcept
        {
          return impl::__find_last_not_of<char_type, traits_type, size_type, npos>(
            data(), size(), _str.data(), _str.size(), check_pos(_pos)
          );
        }
        size_type find_last_not_of(
          const char_type* _str, size_type _pos = npos
        ) const noexcept
        {
          return impl::__find_last_not_of<char_type, traits_type, size_type, npos>(
            data(), size(), _str, traits_type::length(_str), check_pos(_pos)
          );
        }
        size_type find_last_not_of(
          const char_type* _str, size_type _pos, size_type _count
        ) const noexcept
        {
          return impl::__find_last_not_of<char_type, traits_type, size_type, npos>(
            data(), size(), _str, _count, check_pos(_pos)
          );
        }
        size_type find_last_not_of(
          char_type _ch, size_type _pos = npos
        ) const noexcept
        {
          return impl::__find_last_not_of<char_type, traits_type, size_type, npos>(
            data(), size(), _ch, check_pos(_pos)
          );
        }
        template<
          typename _T,
          typename __detail::enable_if<
            __detail::is_convertible<const _T&, view_type>::value &&
            (!__detail::is_convertible<_T, const char_type*>::value),
            bool
          >::type = true
        >
        size_type find_last_not_of(
          const _T& _sv, size_type _pos = npos
        ) const noexcept
        {
          view_type __sv = _sv;
          return impl::__find_last_not_of<char_type, traits_type, size_type, npos>(
            data(), size(), __sv.data(), __sv.size(), check_pos(_pos)
          );
        }

      public:
        __UTILITY_CPP14_CONSTEXPR__
        void swap(basic_static_string& _other) noexcept
        {
          using algorithm::swap;
          swap(value,   _other.value);
          swap(len,     _other.len);
        }
        __UTILITY_CPP14_CONSTEXPR__
        void possible_swap(basic_static_string& _other) noexcept
        {
          using algorithm::swap;
          swap(value,   _other.value);
          swap(len,     _other.len);
        }

      public:
        inline basic_static_string operator+=(const basic_static_string& _str)
        { return append(_str);}
        inline basic_static_string operator+=(char_type _ch)
        { return append(_ch);}
        inline basic_static_string operator+=(const char_type* _str)
        { return append(_str);}
        template<typename _T>
        inline basic_static_string operator+=(const _T& _sv)
        { return append(_sv);}
        inline basic_static_string operator+=(container::initializer_list<char_type> _init)
        { return append(_init);}

      private:
        size_type check_pos(size_type& _pos) const
        {
          if(_pos > len)
#if defined(__UTILITY_USE_EXCEPTION)
          { ;}
#elif defined(UTILITY_BASIC_STRING_CORRECT_OUTRANGE_POS)
          { _pos = len;}
#else
          { } // about
#endif
          return _pos;
        }

      private:
        __UTILITY_CPP14_CONSTEXPR__
        container::pair<const char_type*, const char_type*>
        substr_ptr(size_type _idx, size_type _count = npos) const noexcept
        {
          typedef container::pair<const char_type*, const char_type*> __result;

          ///< TODO: throw exception
          if(_idx >= len)
          { }

          if(_idx+_count > len || _count == npos)
          { _count = len;}
          else
          { _count += _idx;}
          return __result{value+_idx, value+_count};
        }
    };

    template<typename _CharT, size_t _Len,typename _Alloc>
    constexpr typename basic_static_string<_CharT, _Len,_Alloc>::size_type
      basic_static_string<_CharT, _Len, _Alloc>::npos;


    template<typename _CharT, size_t _Len, typename _Traits>
    bool operator==(
      const basic_static_string<_CharT, _Len, _Traits>& _x,
      const basic_static_string<_CharT, _Len, _Traits>& _y
    ) noexcept
    { return _x.compare(_y) == 0;}
    template<typename _CharT, size_t _Len, typename _Traits>
    bool operator!=(
      const basic_static_string<_CharT, _Len, _Traits>& _x,
      const basic_static_string<_CharT, _Len, _Traits>& _y
    ) noexcept
    { return _x.compare(_y) != 0;}
    template<typename _CharT, size_t _Len, typename _Traits>
    bool operator<(
      const basic_static_string<_CharT, _Len, _Traits>& _x,
      const basic_static_string<_CharT, _Len, _Traits>& _y
    ) noexcept
    { return _x.compare(_y) < 0;}
    template<typename _CharT, size_t _Len, typename _Traits>
    bool operator>(
      const basic_static_string<_CharT, _Len, _Traits>& _x,
      const basic_static_string<_CharT, _Len, _Traits>& _y
    ) noexcept
    { return _x.compare(_y) > 0;}
    template<typename _CharT, size_t _Len, typename _Traits>
    bool operator<=(
      const basic_static_string<_CharT, _Len, _Traits>& _x,
      const basic_static_string<_CharT, _Len, _Traits>& _y
    ) noexcept
    { return _x.compare(_y) <= 0;}
    template<typename _CharT, size_t _Len, typename _Traits>
    bool operator>=(
      const basic_static_string<_CharT, _Len, _Traits>& _x,
      const basic_static_string<_CharT, _Len, _Traits>& _y
    ) noexcept
    { return _x.compare(_y) >= 0;}

    template<size_t _Len>
    using static_string =
      basic_static_string<char, _Len, char_traits<char>>;
    template<size_t _Len>
    using static_wstring =
      basic_static_string<wchar_t, _Len, char_traits<wchar_t>>;
    template<size_t _Len>
    using static_u16string =
      basic_static_string<char16_t, _Len, char_traits<char16_t>>;
    template<size_t _Len>
    using static_u32string =
      basic_static_string<char32_t, _Len, char_traits<char32_t>>;
  __utility_interspace_end(charS)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CHARS_BASIC_STATIC_STRING__

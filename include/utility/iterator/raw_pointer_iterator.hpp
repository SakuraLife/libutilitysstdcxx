
#ifndef __UTILITY_ITERATOR_RAW_POINTER_ITERATOR__
#define __UTILITY_ITERATOR_RAW_POINTER_ITERATOR__

#include<utility/config/utility_config.hpp>
#include<utility/iterator/iterator_tag.hpp>
#include<utility/trait/miscellaneous/pointer_traits.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(iterator)
  {
    template<typename _T>
    class raw_pointer_iterator
    {
      public:
        typedef contiguous_iterator_tag     iterator_category;
        typedef _T                          value_type;
        typedef value_type&                 reference;
        typedef typename
          trait::miscellaneous::pointer_traits<_T*>::pointer pointer;
        typedef typename
          trait::miscellaneous::pointer_traits<_T*>::difference_type difference_type;

      public:
        typedef raw_pointer_iterator<value_type> self;

      public:
        pointer __ptr;

      public:
        inline raw_pointer_iterator() noexcept:
          __ptr(nullptr)
        { }
        inline explicit raw_pointer_iterator(pointer _tptr) noexcept:
          __ptr(_tptr)
        { }

      public:
        inline raw_pointer_iterator& operator=(
          const raw_pointer_iterator& _other
        ) noexcept = default;

      public:
        reference operator*() const noexcept
        { return *__ptr;}
        pointer operator->() const noexcept
        { return __ptr;}

      public:
        raw_pointer_iterator& operator++() noexcept
        {
          ++__ptr;
          return *this;
        }
        raw_pointer_iterator operator++(int) noexcept
        {
          raw_pointer_iterator __it = *this;
          ++__ptr;
          return __it;
        }
        raw_pointer_iterator& operator--() noexcept
        {
          --__ptr;
          return *this;
        }
        raw_pointer_iterator operator--(int) noexcept
        {
          raw_pointer_iterator __it = *this;
          --__ptr;
          return __it;
        }

      public:
        raw_pointer_iterator& operator+=(difference_type _len) noexcept
        {
          __ptr += _len;
          return *this;
        }
        raw_pointer_iterator& operator-=(difference_type _len) noexcept
        {
          __ptr -= _len;
          return *this;
        }
        raw_pointer_iterator operator+(difference_type _len) const noexcept
        { return raw_pointer_iterator{__ptr + _len};}
        raw_pointer_iterator operator-(difference_type _len) const noexcept
        { return raw_pointer_iterator{__ptr - _len};}

    };
    template<typename _T>
    class raw_pointer_iterator<const _T>
    {
      public:
        typedef contiguous_iterator_tag     iterator_category;
        typedef const _T                    value_type;
        typedef _T                          non_const_value_type;
        typedef const value_type&           reference;
        typedef typename
          trait::miscellaneous::pointer_traits<value_type*>::pointer pointer;
        typedef typename
          trait::miscellaneous::pointer_traits<value_type*>::difference_type difference_type;

      public:
        typedef raw_pointer_iterator<value_type> self;

      public:
        pointer __ptr;

      public:
        inline raw_pointer_iterator() noexcept:
          __ptr(nullptr)
        { }
        inline explicit raw_pointer_iterator(pointer _tptr) noexcept:
          __ptr(_tptr)
        { }
        inline raw_pointer_iterator(
          const raw_pointer_iterator<non_const_value_type>& _other
        ) noexcept:
          __ptr(_other.__ptr)
        { }

      public:
        inline raw_pointer_iterator& operator=(
          const raw_pointer_iterator& _other
        ) noexcept = default;

        inline raw_pointer_iterator& operator=(
          const raw_pointer_iterator<non_const_value_type>& _other
        ) noexcept
        {
          __ptr = _other.__ptr;
          return *this;
        }

      public:
        reference operator*() const noexcept
        { return *__ptr;}
        pointer operator->() const noexcept
        { return __ptr;}

      public:
        raw_pointer_iterator& operator++() noexcept
        {
          ++__ptr;
          return *this;
        }
        raw_pointer_iterator operator++(int) noexcept
        {
          raw_pointer_iterator __it = *this;
          ++__ptr;
          return __it;
        }
        raw_pointer_iterator& operator--() noexcept
        {
          --__ptr;
          return *this;
        }
        raw_pointer_iterator operator--(int) noexcept
        {
          raw_pointer_iterator __it = *this;
          --__ptr;
          return __it;
        }

      public:
        raw_pointer_iterator& operator+=(difference_type _len) noexcept
        {
          __ptr += _len;
          return *this;
        }
        raw_pointer_iterator& operator-=(difference_type _len) noexcept
        {
          __ptr -= _len;
          return *this;
        }
        raw_pointer_iterator operator+(difference_type _len) const noexcept
        { return raw_pointer_iterator{__ptr + _len};}
        raw_pointer_iterator operator-(difference_type _len) const noexcept
        { return raw_pointer_iterator{__ptr - _len};}

    };

    template<typename _T>
    bool operator==(
      const raw_pointer_iterator<_T>& _x, const raw_pointer_iterator<_T>& _y
    ) noexcept
    { return _x.__ptr == _y.__ptr;}
    template<typename _T>
    bool operator!=(
      const raw_pointer_iterator<_T>& _x, const raw_pointer_iterator<_T>& _y
    ) noexcept
    { return _x.__ptr != _y.__ptr;}
    template<typename _T>
    bool operator<(
      const raw_pointer_iterator<_T>& _x, const raw_pointer_iterator<_T>& _y
    ) noexcept
    { return _x.__ptr < _y.__ptr;}
    template<typename _T>
    bool operator>(
      const raw_pointer_iterator<_T>& _x, const raw_pointer_iterator<_T>& _y
    ) noexcept
    { return _x.__ptr > _y.__ptr;}
    template<typename _T>
    bool operator<=(
      const raw_pointer_iterator<_T>& _x, const raw_pointer_iterator<_T>& _y
    ) noexcept
    { return _x.__ptr <= _y.__ptr;}
    template<typename _T>
    bool operator>=(
      const raw_pointer_iterator<_T>& _x, const raw_pointer_iterator<_T>& _y
    ) noexcept
    { return _x.__ptr >= _y.__ptr;}

    template<typename _T>
    typename raw_pointer_iterator<_T>::difference_type operator-(
      const raw_pointer_iterator<_T>& _x, const raw_pointer_iterator<_T>& _y
    ) noexcept
    { return _x.__ptr - _y.__ptr;}
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ITERATOR_RAW_POINTER_ITERATOR__

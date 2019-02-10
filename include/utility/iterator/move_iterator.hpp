
#ifndef __UTILITY_ITERATOR_MOVE_ITERATOR__
#define __UTILITY_ITERATOR_MOVE_ITERATOR__

#include<utility/config/utility_config.hpp>

#include<utility/memory/addressof.hpp>

#include<utility/iterator/iterator_traits.hpp>

#include<utility/trait/opt/__control__.hpp>
#include<utility/trait/type/categories/is_reference.hpp>
#include<utility/trait/type/releations/is_convertible.hpp>
#include<utility/trait/type/transform/remove_reference.hpp>

#include<utility/iterator/iterator_tag.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(iterator)
  {
    namespace __detail
    {
      using trait::__opt__::__if__;
      using trait::__opt__::__if_else__;
      using trait::type::categories::is_reference;
      using trait::type::releations::is_convertible;
      using trait::type::transform::remove_reference_t;
    }


    template<typename _Iterator>
    class move_iterator
    {
      private:
        typedef typename
          iterator_traits<_Iterator>::reference        original_reference;
      public:
        typedef typename
          iterator_traits<_Iterator>::iterator_category  iterator_category;
        typedef typename
          iterator_traits<_Iterator>::value_type        value_type;
        typedef typename
          iterator_traits<_Iterator>::difference_type   difference_type;
        typedef _Iterator                               pointer;
        typedef typename __detail::__if_else__<
          __detail::is_reference<original_reference>::value,
          __detail::remove_reference_t<original_reference>&&,
          original_reference
        >::type                                         reference;

      public:
        typedef _Iterator                               iterator_type;

      private:
        iterator_type current;

      public:
        __UTILITY_CPP14_CONSTEXPR__
        inline move_iterator(): current()
        { }
        __UTILITY_CPP14_CONSTEXPR__
        inline explicit move_iterator(iterator_type __iit):
          current(__iit)
        { }
        template<typename _T>
        __UTILITY_CPP14_CONSTEXPR__
        inline move_iterator(const move_iterator<_T>& __oit):
          current(__oit.base())
        { }

      public:
        template<typename _T>
        inline __UTILITY_CPP14_CONSTEXPR__
        move_iterator& operator= (const move_iterator<_T>& __oit)
        {
          current = __oit.base();
          return *this;
        }

      public:
        __UTILITY_CPP14_CONSTEXPR__
        inline reference operator*() const
        { return static_cast<reference>(*current);}
        __UTILITY_CPP14_CONSTEXPR__
        inline pointer operator->() const noexcept
        { return current;}

      public:
        template<
          typename _Tag = iterator_category,
          typename __detail::__if__<
            __detail::is_convertible<_Tag, forward_iterator_tag>::value,
            bool
          >::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        inline move_iterator& operator++()
        {
          ++(current);
          return *this;
        }
        template<
          typename _Tag = iterator_category,
          typename __detail::__if__<
            __detail::is_convertible<_Tag, forward_iterator_tag>::value,
            bool
          >::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        inline move_iterator operator++(int) const
        {
          move_iterator __nit(current);
          ++(current);
          return __nit;
        }
        template<
          typename _Tag = iterator_category,
          typename __detail::__if__<
            __detail::is_convertible<_Tag, bidirectional_iterator_tag>::value,
            bool
          >::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        inline move_iterator& operator--()
        {
          --(current);
          return *this;
        }
        template<
          typename _Tag = iterator_category,
          typename __detail::__if__<
            __detail::is_convertible<_Tag, bidirectional_iterator_tag>::value,
            bool
          >::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        inline move_iterator operator--(int) const
        {
          move_iterator __nit(current);
          --(current);
          return __nit;
        }
        template<
          typename _Tag = iterator_category,
          typename __detail::__if__<
            __detail::is_convertible<_Tag, random_access_iterator_tag>::value,
            bool
          >::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        inline move_iterator operator+(difference_type _len) const
        { return move_iterator{current + _len};}
        template<
          typename _Tag = iterator_category,
          typename __detail::__if__<
            __detail::is_convertible<_Tag, random_access_iterator_tag>::value,
            bool
          >::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        inline move_iterator operator-(difference_type _len) const
        { return move_iterator{current - _len};}
        template<
          typename _Tag = iterator_category,
          typename __detail::__if__<
            __detail::is_convertible<_Tag, random_access_iterator_tag>::value,
            bool
          >::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        inline move_iterator& operator+=(difference_type _len)
        {
          current += _len;
          return *this;
        }
        template<
          typename _Tag = iterator_category,
          typename __detail::__if__<
            __detail::is_convertible<_Tag, random_access_iterator_tag>::value,
            bool
          >::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        inline move_iterator& operator-=(difference_type _len)
        {
          current -= _len;
          return *this;
        }
        template<
          typename _Tag = iterator_category,
          typename __detail::__if__<
            __detail::is_convertible<_Tag, random_access_iterator_tag>::value,
            bool
          >::type = true
        >
        __UTILITY_CPP14_CONSTEXPR__
        inline reference operator[](difference_type _len) const noexcept
        { return *(current + _len);}

      public:
        iterator_type base() const
        { return current;}
    };

    template<typename _Iterator1, typename _Iterator2>
    __UTILITY_CPP14_CONSTEXPR__
    inline bool operator==(const move_iterator<_Iterator1>& _x,
      const move_iterator<_Iterator2>& _y)
    { return _x.base() == _y.base();}
    template<typename _Iterator1, typename _Iterator2>
    __UTILITY_CPP14_CONSTEXPR__
    inline bool operator!=(const move_iterator<_Iterator1>& _x,
      const move_iterator<_Iterator2>& _y)
    { return _x.base() != _y.base();}

    template<typename _Iterator1, typename _Iterator2>
    __UTILITY_CPP14_CONSTEXPR__
    inline bool operator<(const move_iterator<_Iterator1>& _x,
      const move_iterator<_Iterator2>& _y)
    { return _x.base() < _y.base();}
    template<typename _Iterator1, typename _Iterator2>
    __UTILITY_CPP14_CONSTEXPR__
    inline bool operator<=(const move_iterator<_Iterator1>& _x,
      const move_iterator<_Iterator2>& _y)
    { return _x.base() <= _y.base();}
    template<typename _Iterator1, typename _Iterator2>
    __UTILITY_CPP14_CONSTEXPR__
    inline bool operator>(const move_iterator<_Iterator1>& _x,
      const move_iterator<_Iterator2>& _y)
    { return _x.base() > _y.base();}
    template<typename _Iterator1, typename _Iterator2>
    __UTILITY_CPP14_CONSTEXPR__
    inline bool operator>=(const move_iterator<_Iterator1>& _x,
      const move_iterator<_Iterator2>& _y)
    { return _x.base() >= _y.base();}

    template<typename _Iterator>
    __UTILITY_CPP14_CONSTEXPR__
    inline move_iterator<_Iterator> operator+(
      typename move_iterator<_Iterator>::difference_type _len,
      const move_iterator<_Iterator>& __it)
    { return __it + _len;}

    template<typename _Iterator>
    __UTILITY_CPP14_CONSTEXPR__
    inline auto operator-(const move_iterator<_Iterator>& _x,
      const move_iterator<_Iterator>& _y)
      ->decltype(_x.base() - _y.base())
    { return _x.base() - _y.base();}

    template<typename _Iterator>
    __UTILITY_CPP17_CONSTEXPR__
    inline move_iterator<_Iterator> make_move_iterator(_Iterator __it)
    { return move_iterator<_Iterator>(__it);}
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ITERATOR_MOVE_ITERATOR__

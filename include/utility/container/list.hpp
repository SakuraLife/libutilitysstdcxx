
#ifndef __UTILITY_CONTAINER_LIST__
#define __UTILITY_CONTAINER_LIST__


/**
 * \file list.hpp
 * \author Inochi Amaoto
 *
 */

#include<utility/config/utility_config.hpp>
#include<utility/container/container_helper.hpp>

#include<utility/algorithm/algorithm_auxiliary.hpp>
#include<utility/algorithm/swap.hpp>
#include<utility/algorithm/possible_swap.hpp>
#include<utility/algorithm/move.hpp>
#include<utility/algorithm/equal.hpp>
#include<utility/algorithm/lexicographical_compare.hpp>

#include<utility/container/compressed_pair.hpp>
#include<utility/container/pair.hpp>
#include<utility/container/helper/node.hpp>
#include<utility/container/helper/node_pool.hpp>

#include<utility/memory/allocator.hpp>
#include<utility/memory/allocator_traits.hpp>
#include<utility/memory/unique_ptr.hpp>
#include<utility/memory/raw_delete.hpp>

#include<utility/trait/type/releations/is_same.hpp>
#include<utility/trait/type/transform/add_reference.hpp>
#include<utility/trait/type/features/is_nothrow_swappable.hpp>
#include<utility/trait/type/features/is_nothrow_possible_swappable.hpp>
#include<utility/trait/type/miscellaneous/enable_if.hpp>
#include<utility/trait/miscellaneous/pointer_traits.hpp>

#include<utility/iterator/iterator_tag.hpp>
#include<utility/iterator/reverse_iterator.hpp>
#include<utility/iterator/distance.hpp>
#include<utility/iterator/next.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(container)
    template<typename _T, typename _Alloc = memory::allocator<_T>>
    class list;

    namespace __detail
    {
      using _helper::__node;
      using _helper::__dnode;
      using _helper::__node_trait;
      using trait::miscellaneous::pointer_traits;
      using trait::type::transform::add_lvalue_reference_t;
      using trait::type::features::is_nothrow_swappable;
      using trait::type::features::is_nothrow_possible_swappable;
      using trait::type::miscellaneous::enable_if;

      template<typename _T>
      using __list_node = __node<_T, __dnode>;

      template<typename _T>
      class __list_const_iterator;

      template<typename _T>
      class __list_iterator
      {
        private:
          template<typename>
          friend class __list_const_iterator;
          template<typename, typename>
          friend class container::list;

        private:
          typedef __node_trait<__dnode>             node_trait;

        public:
          typedef helper::bidirectional_iterator_tag    iterator_category;
          typedef _T                                    value_type;
          typedef value_type&                           reference;
          typedef typename pointer_traits<_T*>::pointer pointer;
          typedef typename pointer_traits<_T*>::difference_type
            difference_type;

        private:
          typedef typename node_trait::__link_type    __link_type;
          typedef typename node_trait::__node_type    __node_type;
          typedef __list_node<_T>                     __node;

        private:
          __link_type __ptr;

        public:
          inline __list_iterator() noexcept:
            __ptr{nullptr}
          { }
          inline explicit __list_iterator(__link_type _link) noexcept:
            __ptr{_link}
          { }

        public:
          reference operator*() const noexcept
          { return node_trait::get<__node>(__ptr)->value;}
          pointer operator->() const noexcept
          { return &(node_trait::get<__node>(__ptr)->value);}

        public:
          __list_iterator& operator++() noexcept
          {
            __ptr = __ptr->next;
            return *this;
          }
          __list_iterator operator++(int) noexcept
          {
            __list_iterator __it = *this;
            __ptr = __ptr->next;
            return __it;
          }
          __list_iterator& operator--() noexcept
          {
            __ptr = __ptr->prev;
            return *this;
          }
          __list_iterator operator--(int) noexcept
          {
            __list_iterator __it = *this;
            __ptr = __ptr->prev;
            return __it;
          }

        public:
          bool operator==(const __list_iterator& _other) const noexcept
          { return __ptr == _other.__ptr;}
          bool operator!=(const __list_iterator& _other) const noexcept
          { return __ptr != _other.__ptr;}
      };

      template<typename _T>
      class __list_const_iterator
      {
        private:
          template<typename, typename>
          friend class container::list;

        private:
          typedef __node_trait<__dnode>             node_trait;

        public:
          typedef helper::bidirectional_iterator_tag    iterator_category;
          typedef const _T                              value_type;
          typedef const value_type&                     reference;
          typedef typename pointer_traits<const _T*>::pointer pointer;
          typedef typename pointer_traits<const _T*>::difference_type
            difference_type;

        private:
          typedef typename node_trait::__link_type    __link_type;
          typedef typename node_trait::__node_type    __node_type;
          typedef __list_node<_T>                     __node;

        private:
          __link_type __ptr;

        public:
          inline __list_const_iterator() noexcept:
            __ptr{nullptr}
          { }
          inline explicit __list_const_iterator(__link_type _link) noexcept:
            __ptr{_link}
          { }
          inline __list_const_iterator(
            const __list_iterator<_T>& _other
          ) noexcept: __ptr{_other.__ptr}
          { }

        public:
          reference operator*() const noexcept
          { return node_trait::get<__node>(__ptr)->value;}
          pointer operator->() const noexcept
          { return &(node_trait::get<__node>(__ptr)->value);}

        public:
          __list_const_iterator& operator++() noexcept
          {
            __ptr = __ptr->next;
            return *this;
          }
          __list_const_iterator operator++(int) noexcept
          {
            __list_const_iterator __it = *this;
            __ptr = __ptr->next;
            return __it;
          }
          __list_const_iterator& operator--() noexcept
          {
            __ptr = __ptr->prev;
            return *this;
          }
          __list_const_iterator operator--(int) noexcept
          {
            __list_const_iterator __it = *this;
            __ptr = __ptr->prev;
            return __it;
          }

        public:
          bool operator==(const __list_const_iterator& _other) const noexcept
          { return __ptr == _other.__ptr;}
          bool operator!=(const __list_const_iterator& _other) const noexcept
          { return __ptr != _other.__ptr;}
      };

    }

    template<typename _T, typename _Alloc>
    class list
    {
      public:
        typedef _T                                value_type;
        typedef _Alloc                            allocator_type;
        typedef size_t                            size_type;
        typedef ptrdiff_t                         difference_type;
        typedef value_type&                       reference;
        typedef const value_type&                 const_reference;
        typedef memory::allocator_traits<_Alloc>  allocator_traits_type;

      public:
        typedef typename allocator_traits_type::pointer pointer;
        typedef typename allocator_traits_type::const_pointer const_pointer;

      private:
        typedef _helper::__dnode                            __node_type;
        typedef __node_type*                                __link_type;
        typedef _helper::__node<value_type, __node_type>    node_type;
        typedef node_type*                                  link_type;
        typedef _helper::__node_trait<__node_type>          node_trait;
        typedef _helper::__node_pool<node_type>             node_pool;

      public:
        typedef __detail::__list_iterator<value_type>       iterator;
        typedef __detail::__list_const_iterator<value_type> const_iterator;
        typedef helper::reverse_iterator<iterator>
          reverse_iterator;
        typedef helper::reverse_iterator<const_iterator>
          const_reverse_iterator;

      private:
        typedef compressed_pair<__node_type, allocator_type> __base_type;

      public: // assert
        static_assert(trait::type::releations::is_same<
          value_type, typename allocator_type::value_type>::value,
          "the allocator's alloc type must be the same as value type");

      private:
        node_pool     __pool;
        __base_type   __base;
        size_type     __size;

      public:
        list(): list{allocator_type{}}
        { }
        explicit list(const allocator_type& _alloc):
          __pool{}, __base{__node_type{}, _alloc}, __size{0U}
        { _init();}

        explicit list(
          size_type _count, const value_type& _val,
          const allocator_type _alloc = allocator_type{}
        ): __pool{}, __base{node_type{}, _alloc}, __size{0U}
        {
          _init();
          insert(cend(), _count, _val);
        }
        explicit list(
          size_type _count, const allocator_type _alloc = allocator_type{}
        ): __pool{}, __base{node_type{}, _alloc}, __size{0U}
        {
          _init();
          for(; _count > 0; --_count)
          { emplace_back();}
        }
        template<
          typename _Inputiterator,
          typename __detail::enable_if<
            is_iterator<_Inputiterator>::value, bool
          >::type = true
        >
        explicit list(
          _Inputiterator _first, _Inputiterator _last,
          const allocator_type _alloc = allocator_type{}
        ): __pool{}, __base{node_type{}, _alloc}, __size{0U}
        {
          _init();
          insert(cend(), _first, _last);
        }

        list(const list& _other):
          __pool{}, __base{node_type{}, _other.__base.second()}, __size{0U}
        {
          _init();
          insert(cend(), _other.begin(), _other.end());
        }
        list(const list& _other, const allocator_type _alloc):
          __pool{}, __base{node_type{}, _alloc}, __size{0U}
        {
          _init();
          insert(cend(), _other.begin(), _other.end());
        }
        list(list&& _other):
          __pool{algorithm::move(_other.__pool)},
          __base{algorithm::move(_other.__base)},
          __size{_other.__size}
        {
          if(__size)
          {
            __link_type __hander = &(__base.first());
            __hander->next->prev = __hander;
            __hander->prev->next = __hander;
            _other._init();
          }
          else
          { _init();}
        }
        list(list&& _other, const allocator_type _alloc):
          __pool{algorithm::move(_other.__pool)},
          __base{_other.__base.first(), _alloc},
          __size{_other.__size}
        {
          if(__size)
          {
            __link_type __hander = &(__base.first());
            __hander->next->prev = __hander;
            __hander->prev->next = __hander;
            _other._init();
          }
          else
          { _init();}
        }

        list(
          initializer_list<value_type> __init,
          const allocator_type& _alloc = allocator_type{}
        ):__pool{}, __base{node_type{}, _alloc}, __size{0U}
        {
          _init();
          insert(cend(), __init.begin(), __init.end());
        }

        ~list()
        { force_clear();}

      public:
        list& operator=(const list& _other)
        {
          if(&_other != this)
          {
            clear();
            insert(cend(), _other.begin(), _other.end());
          }
          return *this;
        }
        list& operator=(list&& _other)
        {
          if(&_other != this)
          {
            clear();
            __size = _other.__size;
            if(__size)
            {
              __base.first() = _other.__base.first();
              __link_type __hander = &(__base.first());
              __hander->next->prev = __hander;
              __hander->prev->next = __hander;
              _other._init();
            }
          }
          return *this;
        }
        list& operator=(initializer_list<value_type> __init)
        {
          assign(__init.begin(), __init.end());
          return *this;
        }

      public:
        void assign(size_type _count, const value_type& _val)
        {
          iterator __begin = begin();
          iterator __end = end();
          for(; __begin != __end && _count; ++__begin, --_count)
          { *__begin = _val;}
          if(_count)
          { insert(__begin, _count, _val);}
          else
          { erase(__begin, __end);}
        }
        template<
          typename _Inputiterator,
          typename __detail::enable_if<
            is_iterator<_Inputiterator>::value, bool
          >::type = true
        >
        void assign(_Inputiterator _first, _Inputiterator _last)
        {
          iterator __begin = begin();
          iterator __end = end();
          for(; __begin != __end && _first != _last; ++__begin, ++_first)
          { *__begin = *_first;}
          if(__begin == __end)
          { insert(__begin, _first, _last);}
          else
          { erase(__begin, __end);}
        }
        inline void assign(initializer_list<value_type> __init)
        { assign(__init.begin(), __init.end());}

      public:
        allocator_type get_allocator() const
        { return __base.second();}

      public:
        inline reference front() noexcept
        { return node_trait::get<node_type>(__base.first().next)->value;}
        inline const_reference front() const noexcept
        { return node_trait::get<node_type>(__base.first().next)->value;}
        inline reference back() noexcept
        { return node_trait::get<node_type>(__base.first().prev)->value;}
        inline const_reference back() const noexcept
        { return node_trait::get<node_type>(__base.first().prev)->value;}

      public:
        iterator begin() noexcept
        { return iterator{__base.first().next};}
        const_iterator begin() const noexcept
        { return const_iterator{__base.first().next};}
        const_iterator cbegin() const noexcept
        { return const_iterator{__base.first().next};}
        iterator end() noexcept
        { return iterator{&(__base.first())};}
        const_iterator end() const noexcept
        { return const_iterator{const_cast<__link_type>(&(__base.first()))};}
        const_iterator cend() const noexcept
        { return const_iterator{const_cast<__link_type>(&(__base.first()))};}

      public:
        reverse_iterator rbegin() noexcept
        { return reverse_iterator{end()};}
        const_reverse_iterator rbegin() const noexcept
        { return const_reverse_iterator{end()};}
        const_reverse_iterator crbegin() const noexcept
        { return const_reverse_iterator{end()};}
        reverse_iterator rend() noexcept
        { return reverse_iterator{begin()};}
        const_reverse_iterator rend() const noexcept
        { return const_reverse_iterator{begin()};}
        const_reverse_iterator crend() const noexcept
        { return const_reverse_iterator{begin()};}

      public:
        bool empty() const noexcept
        { return __base.first().next == &(__base.first());}
        size_type size() const noexcept
        { return __size;}
        size_type max_size() const noexcept
        { return ~size_type{0U};}

      public:
        void push_front(const value_type& _val)
        {
          __node_insert(_allocate_node(_val), __base.first().next);
          ++__size;
        }
        void push_front(value_type&& _val)
        {
          using algorithm::move;
          __node_insert(_allocate_node(move(_val)), __base.first().next);
          ++__size;
        }
        void push_back(const value_type& _val)
        {
          __node_insert(_allocate_node(_val), &(__base.first()));
          ++__size;
        }
        void push_back(value_type&& _val)
        {
          using algorithm::move;
          __node_insert(_allocate_node(move(_val)), &(__base.first()));
          ++__size;
        }

      public:
        template<typename... _Args>
        iterator emplace(const_iterator _pos, _Args&&... _args)
        {
          using algorithm::forward;
          __node_insert(_allocate_node(forward<_Args>(_args)...), _pos.__ptr);
          ++__size;
          return iterator{_pos.__ptr};
        }
        template<typename... _Args>
        reference emplace_front(_Args&&... _args)
        {
          using algorithm::forward;
          __node_insert(
            _allocate_node(forward<_Args>(_args)...), __base.first().next
          );
          ++__size;
          return node_trait::get<node_type>(__base.first().next)->value;
        }
        template<typename... _Args>
        reference emplace_back(_Args&&... _args)
        {
          using algorithm::forward;
          __node_insert(
            _allocate_node(forward<_Args>(_args)...), &(__base.first())
          );
          ++__size;
          return node_trait::get<node_type>(__base.first().prev)->value;
        }

      public:
        void pop_front()
        {
          __link_type __dlink = __base.first().next;
          __node_connect(__dlink->prev, __dlink->next);
          _destroy_node(node_trait::get<node_type>(__dlink));
          --__size;
        }
        void pop_back()
        {
          __link_type __dlink = __base.first().prev;
          __node_connect(__dlink->prev, __dlink->next);
          _destroy_node(node_trait::get<node_type>(__dlink));
          --__size;
        }

      public:
        iterator insert(const_iterator _pos, const value_type& _val)
        {
          link_type __ins = _allocate_node(_val);
          __node_insert(__ins, _pos.__ptr);
          ++__size;
          return iterator{__ins};
        }
        iterator insert(const_iterator _pos, value_type&& _val)
        {
          using algorithm::move;
          link_type __ins = _allocate_node(move(_val));
          __node_insert(__ins, _pos.__ptr);
          ++__size;
          return iterator{__ins};
        }
        iterator insert(
          const_iterator _pos, size_type _count, const value_type& _val
        )
        {
          if(_count == 0)
          { return iterator{_pos.__ptr};}
          pair<link_type, link_type> __chain =
            _allocate_node_chain(_count, _val);
          __link_type __tpos = _pos.__ptr;
          __node_connect(__tpos->prev, __chain.first);
          __node_connect(__chain.second, __tpos);
          __size += _count;
          return iterator{__chain.first};
        }
        template<
          typename _Inputiterator,
          typename __detail::enable_if<
            is_iterator<_Inputiterator>::value, bool
          >::type = true
        >
        inline iterator insert(
          const_iterator _pos, _Inputiterator _first, _Inputiterator _last
        )
        {
          using helper::distance;
          if(_first == _last)
          { return iterator{_pos.__ptr};}
          pair<link_type, link_type> __chain =
            _allocate_node_chain(_first, _last);
          __link_type __tpos = _pos.__ptr;
          __node_connect(__tpos->prev, __chain.first);
          __node_connect(__chain.second, __tpos);
          __size += distance(_first, _last);
          return iterator{__chain.first};
        }
        inline iterator insert(
          const_iterator _pos, initializer_list<value_type> __init
        )
        { return insert(_pos, __init.begin(), __init.end());}

      public:
        iterator erase(const_iterator _pos)
        {
          __link_type __elink = _pos.__ptr;
          __link_type __res = __elink->next;
          __node_connect(__elink->prev, __elink->next);
          _destroy_node(node_trait::get<node_type>(__elink));
          --__size;
          return iterator{__res};
        }
        iterator erase(const_iterator _first, const_iterator _last)
        {
          __link_type __res = _last.__ptr;
          if(_first != _last)
          {
            __link_type __elink = _first.__ptr;
            __link_type __nlink = __elink->next;
            __node_connect(__elink->prev, __res);
            for(; __elink != __res;)
            {
              _destroy_node(node_trait::get<node_type>(__elink));
              __elink = __nlink;
              __nlink = __nlink->next;
              --__size;
            }
          }
          return iterator{__res};
        }

      public:
#ifdef __UTILITY_NO_CPP20__
        void remove(const value_type& _val)
        {
          if(__size)
          {
            __link_type __hander = &(__base.first());
            __link_type __elink = __hander->next;
            __link_type __nlink = __elink->next;
            for(; __elink != __hander;)
            {
              if(node_trait::get<node_type>(__elink)->value == _val)
              {
                __node_connect(__elink->prev, __elink->next);
                _destroy_node(node_trait::get<node_type>(__elink));
                --__size;
              }
              __elink = __nlink;
              __nlink = __nlink->next;
            }
          }
        }
        template<typename _UnaryPredicate>
        void remove_if(_UnaryPredicate _op)
        {
          if(__size)
          {
            __link_type __hander = &(__base.first());
            __link_type __elink = __hander->next;
            __link_type __nlink = __elink->next;
            for(; __elink != __hander;)
            {
              if(_op(node_trait::get<node_type>(__elink)->value))
              {
                __node_connect(__elink->prev, __elink->next);
                _destroy_node(node_trait::get<node_type>(__elink));
                --__size;
              }
              __elink = __nlink;
              __nlink = __nlink->next;
            }
          }
        }
#else
        size_type remove(const value_type& _val)
        {
          size_type __destroy = __size;
          if(__size)
          {
            __link_type __hander = &(__base.first());
            __link_type __elink = __hander->next;
            __link_type __nlink = __elink->next;
            for(; __elink != __hander;)
            {
              if(node_trait::get<node_type>(__elink)->value == _val)
              {
                __node_connect(__elink->prev, __elink->next);
                _destroy_node(node_trait::get<node_type>(__elink));
                --__size;
              }
              __elink = __nlink;
              __nlink = __nlink->next;
            }
          }
          __destroy -= __size;

          return __destroy;
        }
        template<typename _UnaryPredicate>
        size_type remove_if(_UnaryPredicate _op)
        {
          size_type __destroy = __size;
          if(__size)
          {
            __link_type __hander = &(__base.first());
            __link_type __elink = __hander->next;
            __link_type __nlink = __elink->next;
            for(; __elink != __hander;)
            {
              if(_op(node_trait::get<node_type>(__elink)->value))
              {
                __node_connect(__elink->prev, __elink->next);
                _destroy_node(node_trait::get<node_type>(__elink));
                --__size;
              }
              __elink = __nlink;
              __nlink = __nlink->next;
            }
          }
          __destroy -= __size;

          return __destroy;
        }
#endif // ! __UTILITY_NO_CPP20__


      public:
        void clear()
        {
          if(__size)
          {
            __link_type __hander = &(__base.first());
            __link_type __elink = __hander->next;
            __link_type __nlink = __elink->next;
            for(; __elink != __hander;)
            {
              _destroy_node(node_trait::get<node_type>(__elink));
              __elink = __nlink;
              __nlink = __nlink->next;
            }

            __size = 0U;
            __hander->next = __hander->prev = __hander;
          }
        }

      public:
        void resize(size_type _count)
        {
          if(_count > __size)
          {
            for(; _count != __size;)
            { emplace_back();}
            return;
          }
          for(; _count != __size;)
          { pop_back();}
        }
        void resize(size_type _count, const value_type& _val)
        {
          if(_count > __size)
          {
            for(; _count != __size;)
            { push_back(_val);}
            return;
          }
          for(; _count != __size;)
          { pop_back();}
        }

      public:
        void reverse() noexcept
        {
          __link_type __hander = &(__base.first());
          __link_type __tlink = __hander;
          __node_reverse(__tlink);
          __tlink = __tlink->prev;
          for(; __tlink != __hander;)
          {
            __node_reverse(__tlink);
            __tlink = __tlink->prev;
          }
        }

      public:
        void splice(const_iterator _pos, list& _other) noexcept
        {
          if(!_other.empty() && (&_other != this))
          {
            __link_type __plink = _pos.__ptr;
            __link_type __obase = &(_other.__base.first());
            __node_connect(__plink->prev, __obase->next);
            __node_connect(__obase->prev, __plink);
            __obase->prev = __obase->next = __obase;
            __size += _other.__size;
            _other.__size = 0U;
          }
        }
        void splice(
          const_iterator _pos, list& _other, const_iterator _ins
        ) noexcept
        {
          if(_pos != _ins && !_other.empty())
          {
            __link_type __plink = _pos.__ptr;
            __link_type __ins = _ins.__ptr;
            __node_connect(__ins->prev, __ins->next);
            __node_insert(__ins, __plink);
            ++__size;
            --_other.__size;
          }
        }
        void splice(
          const_iterator _pos, list& _other,
          const_iterator _first, const_iterator _last
        ) noexcept
        {
          using helper::distance;
          if(!_other.empty() && (_first != _last))
          {
            size_type __len = distance(_first, _last);
            __link_type __plink = _pos.__ptr;
            __link_type __tflink = _first.__ptr;
            __link_type __tllink = _last.__ptr->prev;
            __node_connect(__tflink->prev, __tllink->next);
            __node_connect(__plink->prev, __tflink);
            __node_connect(__tllink, __plink);
            __size += __len;
            _other.__size -= __len;
          }
        }
        void splice(const_iterator _pos, list&& _other) noexcept
        { splice(_pos, _other);}
        void splice(
          const_iterator _pos, list&& _other, const_iterator _it
        ) noexcept
        { splice(_pos, _other, _it);}
        void splice(
          const_iterator _pos, list&& _other,
          const_iterator _first, const_iterator _last
        ) noexcept
        { splice(_pos, _other, _first, _last);}

      public:
#ifdef __UTILITY_NO_CPP20__
        inline void unique()
        {
          using algorithm::equal_to;
          this->unique(equal_to<value_type>{});
        }
        template<typename _BinaryPredicate>
        void unique(_BinaryPredicate _op)
        {
          using helper::next;

          iterator __end = end();
          for(iterator __it = begin(); __it != __end;)
          {
            iterator __tit = next(__it);
            for(; __tit != __end && _op(*__it, *__tit); ++__tit)
            { }
            if(++__it != __tit)
            { __it = erase(__it, __tit);}
          }
        }
#else
        inline size_type unique()
        {
          using algorithm::equal_to;
          return this->unique(equal_to<value_type>{});
        }
        template<typename _BinaryPredicate>
        size_type unique(_BinaryPredicate _op)
        {
          using helper::next;

          size_type __destroy = __size;
          iterator __end = end();
          for(iterator __it = begin(); __it != __end;)
          {
            iterator __tit = next(__it);
            for(; __tit != __end && _op(*__it, *__tit); ++__tit)
            { }
            if(++__it != __tit)
            { __it = erase(__it, __tit);}
          }
          __destroy -= __size;

          return __destroy;
        }
#endif // ! __UTILITY_NO_CPP20__

      public:
        inline void merge(list& _other)
        {
          using algorithm::less;
          this->merge(_other, less<value_type>{});
        }
        inline void merge(list&& _other)
        {
          using algorithm::less;
          this-merge(_other, less<value_type>{});
        }
        template<typename _Compare>
        void merge(list& _other, _Compare _cmp)
        {
          if(&_other != this)
          {
            __link_type __hander = &(__base.first());
            iterator __end = _other.end();
            for(iterator __it = _other.begin(); __it != __end;)
            {
              __hander = __hander->next;
              if(__hander == &(__base.first()))
              {
                splice(end(), _other);
                return;
              }

              link_type __ins = node_trait::get<node_type>(__it.__ptr);
              if(_cmp(__ins->value, node_trait::get<node_type>(__hander)->value))
              {
                ++__it;
                __node_insert(__ins, __hander);
              }
            }
            __size += _other.__size;
            _other.__size = 0U;
          }
        }
        template<typename _Compare>
        void merge(list&& _other, _Compare _cmp)
        {
          typedef __detail::add_lvalue_reference_t<_Compare> __cmpref;
          this->merge<__cmpref>(_other, _cmp);
        }

      public:
        inline void sort()
        {
          using algorithm::less;
          __sort(
            node_trait::get<node_type>(__base.first().next),
            node_trait::get<node_type>(__base.first().prev),
            __size, less<value_type>{}
          );
        }
        template<typename _Compare>
        inline void sort(_Compare _cmp)
        {
          typedef __detail::add_lvalue_reference_t<_Compare> __cmpref;
          __sort<__cmpref>(
            node_trait::get<node_type>(__base.first().next),
            node_trait::get<node_type>(__base.first().prev),
            __size, _cmp
          );
        }

      public:
        void swap(list& _other) noexcept(
          __detail::is_nothrow_swappable<allocator_type>::value
        )
        {
          using algorithm::swap;
          swap(__base, _other.__base);
          swap(__size, _other.__size);
        }
        void possible_swap(list& _other) noexcept(
          __detail::is_nothrow_possible_swappable<allocator_type>::value
        )
        {
          using algorithm::possible_swap;
          possible_swap(__base, _other.__base);
          possible_swap(__size, _other.__size);
        }

      private:
        void _init() noexcept
        {
          __link_type __tmp = &__base.first();
          __tmp->next = __tmp->prev = __tmp;
        }

      public:
        void force_clear()
        {
          if(empty())
          {
            __link_type __hander = &(__base.first());
            __link_type __elink = __hander->next;
            __link_type __nlink = __elink->next;
            for(; __elink != __hander;)
            {
              _deallocate_node(node_trait::get<node_type>(__elink));
              __elink = __nlink;
              __nlink = __nlink->next;
            }
          }
        }

      private:
        template<typename... _Args>
        UTILITY_ALWAYS_INLINE
        inline link_type _allocate_node(_Args&&... _args)
        {
          using memory::unique_ptr;
          using memory::raw_delete;
          using memory::default_allocate;
          using algorithm::forward;

          typedef unique_ptr<node_type, raw_delete> __handler;

          link_type __require = __pool.pop();
          if(!__require)
          { __require = default_allocate<node_type>(1U);}
          __require->next = __require->prev = nullptr;
          __handler __holder{__require};
          allocator_traits_type::construct(
            __base.second(), &(__holder->value), forward<_Args>(_args)...
          );

          return __holder.release();
        }
        UTILITY_ALWAYS_INLINE
        inline void _deallocate_node(link_type _pos)
        {
          using memory::default_deallocate;

          allocator_traits_type::destroy(__base.second(), &(_pos->value));
          default_deallocate(_pos);
        }
        UTILITY_ALWAYS_INLINE
        inline void _destroy_node(link_type _pos)
        {
          using memory::default_deallocate;

          allocator_traits_type::destroy(__base.second(), &(_pos->value));
          __pool.push(_pos);
        }
        inline pair<link_type, link_type>
        _allocate_node_chain(size_type _count, const value_type& _val)
        {
          link_type __link = _allocate_node(_val);
          size_type __now = 1U;
          __link->next = __link->prev = nullptr;
          link_type __rec = __link;

          __UTILITY_TRY_BEGIN
            for(; __now != _count; ++__now)
            {
              __node_connect(__link, _allocate_node(_val));
              __link = node_trait::get<node_type>(__link->next);
              __link->next = nullptr;
            }
          __UTILITY_TRY_END
          __UTILITY_CATCH(...)
          __UTILITY_CATCH_UNWIND(
            for(; __rec != nullptr; )
            {
              __rec = node_trait::get<node_type>(__rec->next);
              _deallocate_node(__rec);
            }
          );
          return pair<link_type, link_type>{__rec, __link};
        }
        template<
          typename _Inputiterator,
          typename __detail::enable_if<
            is_iterator<_Inputiterator>::value, bool
          >::type = true
        >
        pair<link_type, link_type>
        _allocate_node_chain(_Inputiterator _first, _Inputiterator _last)
        {
          link_type __link = _allocate_node(*_first++);
          __link->next = __link->prev = nullptr;
          link_type __rec = __link;

          __UTILITY_TRY_BEGIN
            for(; _first != _last; ++_first)
            {
              __node_connect(__link, _allocate_node(*_first));
              __link = node_trait::get<node_type>(__link->next);
              __link->next = nullptr;
            }
          __UTILITY_TRY_END
          __UTILITY_CATCH(...)
          __UTILITY_CATCH_UNWIND(
            for(; __rec != nullptr; )
            {
              __rec = node_trait::get<node_type>(__rec->next);
              _deallocate_node(__rec);
            }
          );
          return pair<link_type, link_type>{__rec, __link};
        }


      private:
        UTILITY_ALWAYS_INLINE
        static inline void __node_insert(
          __link_type _ins, __link_type _pos
        ) noexcept
        {
          _ins->prev = _pos->prev;
          _ins->next = _pos;
          _pos->prev = _pos->prev->next = _ins;
        }
        UTILITY_ALWAYS_INLINE
        static inline void __node_connect(
          __link_type _bf, __link_type _af
        ) noexcept
        {
          _bf->next = _af;
          _af->prev = _bf;
        }
        UTILITY_ALWAYS_INLINE
        static inline __link_type __node_connect(
          __link_type _link, size_type _len
        ) noexcept
        {
          for(size_type __i = 0; __i < _len; ++__i)
          { _link = _link->next;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static inline void __node_reverse(__link_type _link) noexcept
        {
          __link_type __tmp = _link->next;
          _link->next = _link->prev;
          _link->prev = __tmp;
        }
        UTILITY_ALWAYS_INLINE
        static inline __link_type __node_next(
          __link_type _link, size_type _len
        ) noexcept
        {
          for(size_type __i = 0; __i < _len; ++__i)
          { _link = _link->next;}
          return _link;
        }

      private:
        template<typename _Compare>
        static link_type __sort(
          link_type _first, link_type _last,
          size_type _tsize, _Compare _cmp
        )
        {
          using algorithm::swap;
          if(_tsize < 2)
          { return _first;}
          if(_tsize == 2)
          {
            if(_cmp(_last->value, _first->value))
            {
              _first->prev->next = _last;
              _first->next = _last->next;
              _last->next->prev = _first;
              _last->prev = _first->prev;
              __node_connect(_last, _first);
              _first = _last;
            }
            return _first;
          }
          size_type __len = _tsize / 2;
          link_type _mid = node_trait::get<node_type>(
            __node_next(_first, __len)
          );
          _first = __sort<_Compare>(
            _first, node_trait::get<node_type>(_mid->prev), __len, _cmp
          );
          _mid = __sort<_Compare>(_mid, _last, _tsize - __len, _cmp);
          _last = node_trait::get<node_type>(
            __node_next(_mid, _tsize - __len - 1)
          );
          return __merge<_Compare>(_first, _mid, _last, _cmp);
        }
        template<typename _Compare>
        UTILITY_ALWAYS_INLINE
        static inline link_type __merge(
          link_type _first, link_type _mid, link_type _last,
          _Compare _cmp
        )
        {
          if(_cmp(node_trait::get<node_type>(_mid->prev)->value, _mid->value))
          { return _first;}
          __node_connect(_mid->prev, _last->next);
          __link_type __res = _first;
          __link_type __elink = _last->next;
          __link_type __tlink = _mid->next;
          for(; _first != __elink && _mid != __elink;)
          {
            if(!_cmp(_mid->value, _first->value))
            { _first = reinterpret_cast<link_type>(_first->next);}
            else
            {
              __node_connect(_first->prev, _mid);
              __node_connect(_mid, _first);
              _mid = reinterpret_cast<link_type>(__tlink);
              __tlink = __tlink->next;
              if(_first == __res)
              { __res = __res->prev;}
            }
          }
          if(_mid != __elink)
          {
            __node_connect(__elink->prev, _mid);
            __node_connect(_last, __elink);
          }
          return node_trait::get<node_type>(__res);
        }
    };

    template<typename _T, typename _Alloc>
    inline bool operator==(const list<_T, _Alloc>& _x, const list<_T, _Alloc>& _y)
    {
      return _x.size() == _y.size() &&
        algorithm::equal(_x.begin(), _x.end(), _y.begin());
    }
    template<typename _T, typename _Alloc>
    inline bool operator!=(const list<_T, _Alloc>& _x, const list<_T, _Alloc>& _y)
    { return !(_x == _y);}
    template<typename _T, typename _Alloc>
    inline bool operator<(const list<_T, _Alloc>& _x, const list<_T, _Alloc>& _y)
    {
      return algorithm::lexicographical_compare(
        _x.begin(), _x.end(), _y.begin(), _y.end()
      );
    }
    template<typename _T, typename _Alloc>
    inline bool operator>(const list<_T, _Alloc>& _x, const list<_T, _Alloc>& _y)
    { return _y < _x;}
    template<typename _T, typename _Alloc>
    inline bool operator<=(const list<_T, _Alloc>& _x, const list<_T, _Alloc>& _y)
    { return !(_y < _x);}
    template<typename _T, typename _Alloc>
    inline bool operator>=(const list<_T, _Alloc>& _x, const list<_T, _Alloc>& _y)
    { return !(_x < _y);}

  __utility_interspace_end(container)

  __utility_interspace_start(algorithm)
    template<typename _T, typename _Alloc>
    inline void swap(
      container::list<_T, _Alloc>& _x,
      container::list<_T, _Alloc>& _y
    ) noexcept(noexcept(_x.swap(_y)))
    { _x.swap(_y);}
    template<typename _T, typename _Alloc>
    inline void possible_swap(
      container::list<_T, _Alloc>& _x,
      container::list<_T, _Alloc>& _y
    ) noexcept(noexcept(_x.possible_swap(_y)))
    { _x.possible_swap(_y);}
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CONTAINER_LIST__

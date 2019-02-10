
#ifndef __UTILITY_CONTAINER_FORWARD_LIST__
#define __UTILITY_CONTAINER_FORWARD_LIST__

#include<utility/config/utility_config.hpp>
#include<utility/container/container_helper.hpp>

#include<utility/algorithm/algorithm_auxiliary.hpp>
#include<utility/algorithm/swap.hpp>
#include<utility/algorithm/possible_swap.hpp>
#include<utility/algorithm/move.hpp>
#include<utility/algorithm/equal.hpp>
#include<utility/algorithm/lexicographical_compare.hpp>

#include<utility/container/helper/node.hpp>
#include<utility/container/pair.hpp>
#include<utility/container/helper/node_pool.hpp>
#include<utility/container/compressed_pair.hpp>

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
#include<utility/iterator/distance.hpp>
#include<utility/iterator/next.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(container)
  {
    template<
      typename _T,
      typename _Alloc = memory::allocator<_T>
    >
    class forward_list;

    namespace __detail
    {
      using _helper::__node;
      using _helper::__snode;
      using _helper::__node_trait;
      using trait::miscellaneous::pointer_traits;
      using trait::type::transform::add_lvalue_reference_t;
      using trait::type::features::is_nothrow_swappable;
      using trait::type::features::is_nothrow_possible_swappable;
      using trait::type::miscellaneous::enable_if;

      template<typename _T>
      using __slist_node = __node<_T, __snode>;

      template<typename _T>
      class __slist_const_iterator;

      template<typename _T>
      class __slist_iterator
      {
        private:
          template<typename>
          friend class __slist_const_iterator;
          template<typename, typename>
          friend class container::forward_list;

        private:
          typedef __node_trait<__snode>           node_trait;

        public:
          typedef helper::forward_iterator_tag          iterator_category;
          typedef _T                                    value_type;
          typedef value_type&                           reference;
          typedef typename pointer_traits<_T*>::pointer pointer;
          typedef typename pointer_traits<_T*>::difference_type
            difference_type;

        private:
          typedef typename node_trait::__link_type    __link_type;
          typedef typename node_trait::__node_type    __node_type;
          typedef __slist_node<_T>                    __node;

        private:
          __link_type __ptr;

        public:
          inline __slist_iterator() noexcept:
            __ptr{nullptr}
          { }
          inline __slist_iterator(__link_type _link) noexcept:
            __ptr{_link}
          { }

        public:
          reference operator*() const noexcept
          { return node_trait::get<__node>(__ptr)->value;}
          pointer operator->() const noexcept
          { return &(node_trait::get<__node>(__ptr)->value);}

        public:
          __slist_iterator& operator++() noexcept
          {
            __ptr = __ptr->next;
            return *this;
          }
          __slist_iterator operator++(int) noexcept
          {
            __slist_iterator __it = *this;
            __ptr = __ptr->next;
            return __it;
          }

        public:
          bool operator==(const __slist_iterator& _other) const noexcept
          { return __ptr == _other.__ptr;}
          bool operator!=(const __slist_iterator& _other) const noexcept
          { return __ptr != _other.__ptr;}
      };

      template<typename _T>
      class __slist_const_iterator
      {
        private:
          template<typename, typename>
          friend class container::forward_list;

        private:
          typedef __node_trait<__snode>           node_trait;

        public:
          typedef helper::forward_iterator_tag          iterator_category;
          typedef const _T                              value_type;
          typedef const value_type&                     reference;
          typedef typename pointer_traits<const _T*>::pointer pointer;
          typedef typename pointer_traits<const _T*>::difference_type
            difference_type;

        private:
          typedef typename node_trait::__link_type    __link_type;
          typedef typename node_trait::__node_type    __node_type;
          typedef __slist_node<_T>                    __node;

        private:
          __link_type __ptr;

        public:
          inline __slist_const_iterator() noexcept:
            __ptr{nullptr}
          { }
          inline __slist_const_iterator(__link_type _link) noexcept:
            __ptr{_link}
          { }
          inline __slist_const_iterator(
            const __slist_iterator<_T>& _other
          ) noexcept: __ptr{_other.__ptr}
          { }

        public:
          reference operator*() const noexcept
          { return node_trait::get<__node>(__ptr)->value;}
          pointer operator->() const noexcept
          { return &(node_trait::get<__node>(__ptr)->value);}

        public:
          __slist_const_iterator& operator++() noexcept
          {
            __ptr = __ptr->next;
            return *this;
          }
          __slist_const_iterator operator++(int) noexcept
          {
            __slist_const_iterator __it = *this;
            __ptr = __ptr->next;
            return __it;
          }

        public:
          bool operator==(const __slist_const_iterator& _other) const noexcept
          { return __ptr == _other.__ptr;}
          bool operator!=(const __slist_const_iterator& _other) const noexcept
          { return __ptr != _other.__ptr;}
      };
    }

    template<typename _T, typename _Alloc>
    class forward_list
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
        typedef _helper::__snode                            __node_type;
        typedef __node_type*                                __link_type;
        typedef _helper::__node<value_type, __node_type>    node_type;
        typedef node_type*                                  link_type;
        typedef _helper::__node_trait<__node_type>          node_trait;
        typedef _helper::__node_pool<node_type>             node_pool;

      public:
        typedef __detail::__slist_iterator<value_type>       iterator;
        typedef __detail::__slist_const_iterator<value_type> const_iterator;

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
        forward_list(): forward_list{allocator_type{}}
        { }
        explicit forward_list(const allocator_type& _alloc):
          __pool{}, __base{__node_type{}, _alloc}, __size{0U}
        { }

        explicit forward_list(
          size_type _count, const value_type& _val,
          const allocator_type _alloc = allocator_type{}
        ): __pool{}, __base{node_type{}, _alloc}, __size{0U}
        { insert_after(cbefore_begin(), _count, _val);}
        explicit forward_list(
          size_type _count, const allocator_type _alloc = allocator_type{}
        ): __pool{}, __base{node_type{}, _alloc}, __size{0U}
        {
          for(; _count > 0; --_count)
          { emplace_front();}
        }
        template<
          typename _Inputiterator,
          typename __detail::enable_if<
            is_iterator<_Inputiterator>::value, bool
          >::type = true
        >
        explicit forward_list(
          _Inputiterator _first, _Inputiterator _last,
          const allocator_type _alloc = allocator_type{}
        ): __pool{}, __base{node_type{}, _alloc}, __size{0U}
        { insert_after(cbefore_begin(), _first, _last);}

        forward_list(const forward_list& _other):
          __pool{}, __base{node_type{}, _other.__base.second()}, __size{0U}
        { insert_after(cbefore_begin(), _other.begin(), _other.end());}
        forward_list(const forward_list& _other, const allocator_type _alloc):
          __pool{}, __base{node_type{}, _alloc}, __size{0U}
        { insert_after(cbefore_begin(), _other.begin(), _other.end());}
        forward_list(forward_list&& _other):
          __pool{algorithm::move(_other.__pool)},
          __base{algorithm::move(_other.__base)},
          __size{_other.__size}
        {
          if(__size)
          {
            _other.__base.first().next = nullptr;
            _other.__size = 0U;
          }
        }
        forward_list(forward_list&& _other, const allocator_type _alloc):
          __pool{algorithm::move(_other.__pool)},
          __base{_other.__base.first(), _alloc},
          __size{_other.__size}
        {
          if(__size)
          {
            _other.__base.first().next = nullptr;
            _other.__size = 0U;
          }
        }
        forward_list(
          initializer_list<value_type> __init,
          const allocator_type& _alloc = allocator_type{}
        ):__pool{}, __base{node_type{}, _alloc}, __size{0U}
        { insert_after(cbefore_begin(), __init.begin(), __init.end());}

        ~forward_list()
        { force_clear();}

      public:
        forward_list& operator=(const forward_list& _other)
        {
          if(&_other != this)
          {
            clear();
            insert_after(before_begin(), _other.begin(), _other.end());
          }
          return *this;
        }
        forward_list& operator=(forward_list&& _other)
        {
          if(&_other != this)
          {
            clear();
            __size = _other.__size;
            if(__size)
            {
              __base.first() = _other.__base.first();
              _other.__base.first().next = nullptr;
              _other.__size = 0U;
            }
          }
          return *this;
        }
        forward_list& operator=(initializer_list<value_type> __init)
        {
          assign(__init.begin(), __init.end());
          return *this;
        }

      public:
        void assign(size_type _count, const value_type& _val)
        {
          using helper::next;
          iterator __bbegin = before_begin();
          iterator __begin = begin();
          iterator __end = end();
          for(; __begin != __end && _count; ++__begin, ++__bbegin, --_count)
          { *__begin = _val;}
          if(_count)
          { insert_after(__bbegin, _count, _val);}
          else
          { erase_after(__bbegin, __end);}
        }
        template<
          typename _Inputiterator,
          typename __detail::enable_if<
            is_iterator<_Inputiterator>::value, bool
          >::type = true
        >
        void assign(_Inputiterator _first, _Inputiterator _last)
        {
          iterator __bbegin = before_begin();
          iterator __begin = begin();
          iterator __end = end();
          for(; __begin != __end && _first != _last; ++__begin, ++__bbegin, ++_first)
          { *__begin = *_first;}
          if(__begin == __end)
          { insert_after(__bbegin, _first, _last);}
          else
          { erase_after(__bbegin, __end);}
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

      public:
        iterator before_begin() noexcept
        { return iterator{&(__base.first())};}
        const_iterator before_begin() const noexcept
        { return const_iterator{const_cast<__link_type>(&(__base.first()))};}
        const_iterator cbefore_begin() const noexcept
        { return const_iterator{const_cast<__link_type>(&(__base.first()))};}
        iterator begin() noexcept
        { return iterator{__base.first().next};}
        const_iterator begin() const noexcept
        { return const_iterator{__base.first().next};}
        const_iterator cbegin() const noexcept
        { return const_iterator{__base.first().next};}
        iterator end() noexcept
        { return iterator{};}
        const_iterator end() const noexcept
        { return const_iterator{};}
        const_iterator cend() const noexcept
        { return const_iterator{};}

      public:
        bool empty() const noexcept
        { return __size == 0U;}
        size_type size() const noexcept
        { return __size;}
        size_type max_size() const noexcept
        { return ~size_type{0U};}

      public:
        void push_front(const value_type& _val)
        {
          __node_insert_after(_allocate_node(_val), &(__base.first()));
          ++__size;
        }
        void push_front(value_type&& _val)
        {
          using algorithm::move;
          __node_insert_after(_allocate_node(move(_val)), &(__base.first()));
          ++__size;
        }

      public:
        template<typename... _Args>
        iterator emplace_after(const_iterator _pos, _Args&&... _args)
        {
          using algorithm::forward;
          __node_insert_after(
            _allocate_node(forward<_Args>(_args)...), _pos.__ptr
          );
          ++__size;
          return iterator{_pos.__ptr};
        }
        template<typename... _Args>
        reference emplace_front(_Args&&... _args)
        {
          using algorithm::forward;
          __node_insert_after(
            _allocate_node(forward<_Args>(_args)...), &(__base.first())
          );
          ++__size;
          return node_trait::get<node_type>(__base.first().next)->value;
        }

      public:
        void pop_front()
        {
          __link_type __dlink = __base.first().next;
          __base.first().next = __dlink->next;
          _destroy_node(node_trait::get<node_type>(__dlink));
          --__size;
        }

      public:
        iterator insert_after(const_iterator _pos, const value_type& _val)
        {
          link_type __ins = _allocate_node(_val);
          __node_insert_after(__ins, _pos.__ptr);
          ++__size;
          return iterator{__ins};
        }
        iterator insert_after(const_iterator _pos, value_type&& _val)
        {
          using algorithm::move;
          link_type __ins = _allocate_node(move(_val));
          __node_insert_after(__ins, _pos.__ptr);
          ++__size;
          return iterator{__ins};
        }
        iterator insert_after(
          const_iterator _pos, size_type _count, const value_type& _val
        )
        {
          if(_count == 0)
          { return iterator{_pos.__ptr};}
          pair<link_type, link_type> __chain =
            _allocate_node_chain(_count, _val);
          __link_type __tpos = _pos.__ptr;
          __chain.second->next = __tpos->next;
          __tpos->next = __chain.first;
          __size += _count;
          return iterator{__chain.first};
        }
        template<
          typename _Inputiterator,
          typename __detail::enable_if<
            is_iterator<_Inputiterator>::value, bool
          >::type = true
        >
        iterator insert_after(
          const_iterator _pos, _Inputiterator _first, _Inputiterator _last
        )
        {
          using helper::distance;
          if(_first == _last)
          { return iterator{_pos.__ptr};}
          pair<link_type, link_type> __chain =
            _allocate_node_chain(_first, _last);
          __link_type __tpos = _pos.__ptr;
          __chain.second->next = __tpos->next;
          __tpos->next = __chain.first;
          __size += distance(_first, _last);
          return iterator{__chain.first};
        }
        inline iterator insert_after(
          const_iterator _pos, initializer_list<value_type> __init
        )
        { return insert_after(_pos, __init.begin(), __init.end());}

      public:
        iterator erase_after(const_iterator _pos)
        {
          __link_type __tlink = _pos.__ptr;
          __link_type __elink = __tlink->next;
          __link_type __res = __elink->next;
          __tlink->next = __res;
          _destroy_node(node_trait::get<node_type>(__elink));
          --__size;
          return iterator{__res};
        }
        iterator erase_after(const_iterator _first, const_iterator _last)
        {
          __link_type __res = _last.__ptr;
          if(_first != _last && _first.__ptr->next)
          {
            __link_type __tlink = _first.__ptr;
            __link_type __elink = __tlink->next;
            __link_type __nlink = __elink;
            __tlink->next = __res;
            for(; __elink != __res;)
            {
              __nlink = __nlink->next;
              _destroy_node(node_trait::get<node_type>(__elink));
              __elink = __nlink;
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
            __link_type __plink = &(__base.first());
            __link_type __elink = __plink->next;
            for(; __elink;)
            {
              if(node_trait::get<node_type>(__elink)->value == _val)
              {
                __plink->next = __elink->next;
                _destroy_node(node_trait::get<node_type>(__elink));
                --__size;
              }
              else
              { __plink = __plink->next;}
              __elink = __plink->next;
            }
          }
        }
        template<typename _UnaryPredicate>
        void remove_if(_UnaryPredicate _op)
        {
          if(__size)
          {
            __link_type __plink = &(__base.first());
            __link_type __elink = __plink->next;
            for(; __elink;)
            {
              if(_op(node_trait::get<node_type>(__elink)->value))
              {
                __plink->next = __elink->next;
                _destroy_node(node_trait::get<node_type>(__elink));
                --__size;
              }
              else
              { __plink = __plink->next;}
              __elink = __plink->next;
            }
          }
        }
#else
        size_type remove(const value_type& _val)
        {
          size_type __destroy = __size;
          if(__size)
          {
            __link_type __plink = &(__base.first());
            __link_type __elink = __plink->next;
            for(; __elink;)
            {
              if(node_trait::get<node_type>(__elink)->value == _val)
              {
                __plink->next = __elink->next;
                _destroy_node(node_trait::get<node_type>(__elink));
                --__size;
              }
              else
              { __plink = __plink->next;}
              __elink = __plink->next;
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
            __link_type __plink = &(__base.first());
            __link_type __elink = __plink->next;
            for(; __elink;)
            {
              if(_op(node_trait::get<node_type>(__elink)->value))
              {
                __plink->next = __elink->next;
                _destroy_node(node_trait::get<node_type>(__elink));
                --__size;
              }
              else
              { __plink = __plink->next;}
              __elink = __plink->next;
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
            __link_type __elink = __base.first().next;
            __link_type __nlink = __elink;
            for(; __elink;)
            {
              __nlink = __nlink->next;
              _destroy_node(node_trait::get<node_type>(__elink));
              __elink = __nlink;
            }

            __size = 0U;
            __base.first().next = nullptr;
          }
        }

      public:
        void resize(size_type _count)
        {
          using helper::next;

          if(_count > __size)
          {
            __link_type __llink = __node_next(&(__base.first()), __size);
            pair<link_type, link_type> __chain =
              _allocate_node_chain(_count - __size);
            __llink->next = __chain.first;
            __chain.second->next = nullptr;
            __size = _count;
          }
          else if(__size > _count)
          {
            const_iterator __eit = next(cbefore_begin(), _count);
            erase_after(__eit, end());
          }
        }
        void resize(size_type _count, const value_type& _val)
        {
          using helper::next;

          if(_count > __size)
          {
            __link_type __llink = __node_next(&(__base.first()), __size);
            pair<link_type, link_type> __chain =
              _allocate_node_chain(_count - __size, _val);
            __llink->next = __chain.first;
            __chain.second->next = nullptr;
            __size = _count;
          }
          else if(__size > _count)
          {
            const_iterator __eit = next(cbefore_begin(), _count);
            erase_after(__eit, end());
          }
        }

      public:
        void reverse() noexcept
        {
          __link_type __rlink = __base.first().next;
          __link_type __qlink = __rlink;
          __link_type __nlink = __rlink;
          __link_type __tmp = __rlink;
          for(; __qlink;)
          {
            __nlink = __nlink->next;
            __qlink->next = __rlink;
            __rlink = __qlink;
            __qlink = __nlink;
          }
          if(__size)
          { __tmp->next = nullptr;}
          __base.first().next = __rlink;
        }

      public:
        void splice_after(const_iterator _pos, forward_list& _other) noexcept
        {
          if(!_other.empty() && (&_other != this))
          {
            __link_type __plink = _pos.__ptr;
            __link_type __obase = &(_other.__base.first());
            __link_type __oend = __node_next(__obase, _other.__size);
            __oend->next = __plink->next;
            __plink->next = __obase->next;
            __obase->next = nullptr;
            __size += _other.__size;
            _other.__size = 0U;
          }
        }
        void splice_after(
          const_iterator _pos, forward_list& _other, const_iterator _ins
        ) noexcept
        {
          using helper::next;

          if(_pos != _ins && _pos != next(_ins) &&
            !_other.empty() && _ins.__ptr->next)
          {
            __link_type __plink = _pos.__ptr;
            __link_type __tlink = _ins.__ptr;
            __link_type __ins = __tlink->next;
            __tlink->next = __ins->next;
            __ins->next = __plink->next;
            __plink->next = __ins;
            ++__size;
            --_other.__size;
          }
        }
        void splice_after(
          const_iterator _pos, forward_list& _other,
          const_iterator _first, const_iterator _last
        ) noexcept
        {
          if(!_other.empty() && (_first != _last))
          {
            size_type __len = 0;
            __link_type __plink = _pos.__ptr;
            __link_type __tflink = _first.__ptr;
            __link_type __tllink = __tflink;
            for(; __tllink->next != _last.__ptr;)
            {
              __tllink = __tllink->next;
              ++__len;
            }
            __tllink->next = __plink->next;
            __plink->next = __tflink->next;
            __tflink->next = _last.__ptr;
            __size += __len;
            _other.__size -= __len;
          }
        }
        void splice_after(const_iterator _pos, forward_list&& _other) noexcept
        { splice_after(_pos, _other);}
        void splice_after(
          const_iterator _pos, forward_list&& _other, const_iterator _it
        ) noexcept
        { splice_after(_pos, _other, _it);}
        void splice_after(
          const_iterator _pos, forward_list&& _other,
          const_iterator _first, const_iterator _last
        ) noexcept
        { splice_after(_pos, _other, _first, _last);}

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
            if(__it.__ptr->next != __tit.__ptr)
            { erase_after(__it, __tit);}
            __it = __tit;
          }
        }
#else
        inline size_type unique()
        {
          using algorithm::equal_to;
          return this->unique(equal_to<value_type>{});
        }
        template<typename _BinaryPredicate>
        void size_type(_BinaryPredicate _op)
        {
          using helper::next;

          size_type __destroy = __size;
          iterator __end = end();
          for(iterator __it = begin(); __it != __end;)
          {
            iterator __tit = next(__it);
            for(; __tit != __end && _op(*__it, *__tit); ++__tit)
            { }
            if(__it.__ptr->next != __tit.__ptr)
            { erase_after(__it, __tit);}
            __it = __tit;
          }
          __destroy -= __size;

          return __destroy;
        }
#endif // ! __UTILITY_NO_CPP20__
      public:
        inline void merge(forward_list& _other)
        {
          using algorithm::less;
          this->merge(_other, less<value_type>{});
        }
        inline void merge(forward_list&& _other)
        {
          using algorithm::less;
          this-merge(_other, less<value_type>{});
        }
        template<typename _Compare>
        inline void merge(forward_list& _other, _Compare _cmp)
        {
          typedef __detail::add_lvalue_reference_t<_Compare> __cmpref;
          if(&_other != this)
          {
            __base.first().next = __merge<__cmpref>(
              node_trait::get<node_type>(__base.first().next),
              node_trait::get<node_type>(_other.__base.first().next),
              _cmp
            );
            _other.__base.first().next = nullptr;
            __size += _other.__size;
            _other.__size = 0U;
          }
        }
        template<typename _Compare>
        inline void merge(forward_list&& _other, _Compare _cmp)
        {
          typedef __detail::add_lvalue_reference_t<_Compare> __cmpref;
          if(&_other != this)
          {
            __base.first().next = __merge<__cmpref>(
              node_trait::get<node_type>(__base.first().next),
              node_trait::get<node_type>(_other.__base.first().next),
              _cmp
            );
            _other.__base.first().next = nullptr;
            __size += _other.__size;
            _other.__size = 0U;
          }
        }

      public:
        inline void sort()
        {
          using algorithm::less;
          __sort(
            node_trait::get<node_type>(__base.first().next),
            __size, less<value_type>{}
          );
        }
        template<typename _Compare>
        inline void sort(_Compare _cmp)
        {
          typedef __detail::add_lvalue_reference_t<_Compare> __cmpref;
          __sort<__cmpref>(
            node_trait::get<node_type>(__base.first().next),
            __size, _cmp
          );
        }

      private:
        void swap(forward_list& _other) noexcept(
          __detail::is_nothrow_possible_swappable<allocator_type>::value
        )
        {
          using algorithm::swap;
          swap(__base, _other.__base);
          swap(__size, _other.__size);
        }
        void possible_swap(forward_list& _other) noexcept(
          __detail::is_nothrow_possible_swappable<allocator_type>::value
        )
        {
          using algorithm::possible_swap;
          possible_swap(__base, _other.__base);
          possible_swap(__size, _other.__size);
        }

      private:
        void force_clear()
        {
          if(__size)
          {
            __link_type __elink = __base.first().next;
            __link_type __nlink = __elink;
            for(; __elink;)
            {
              __nlink = __nlink->next;
              _deallocate_node(node_trait::get<node_type>(__elink));
              __elink = __nlink;
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
          __require->next = nullptr;
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
        _allocate_node_chain(size_type _count)
        {
          link_type __link = _allocate_node();
          size_type __now = 1U;
          __link->next = nullptr;
          link_type __rec = __link;

          __UTILITY_TRY_BEGIN
            for(; __now != _count; ++__now)
            {
              __link->next = _allocate_node();
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
        inline pair<link_type, link_type>
        _allocate_node_chain(size_type _count, const value_type& _val)
        {
          link_type __link = _allocate_node(_val);
          size_type __now = 1U;
          __link->next = nullptr;
          link_type __rec = __link;

          __UTILITY_TRY_BEGIN
            for(; __now != _count; ++__now)
            {
              __link->next = _allocate_node(_val);
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
        inline pair<link_type, link_type>
        _allocate_node_chain(_Inputiterator _first, _Inputiterator _last)
        {
          link_type __link = _allocate_node(*_first++);
          __link->next = nullptr;
          link_type __rec = __link;

          __UTILITY_TRY_BEGIN
            for(; _first != _last; ++_first)
            {
              __link->next = _allocate_node(*_first);
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
        static inline void __node_insert_after(
          __link_type _ins, __link_type _pos
        ) noexcept
        {
          _ins->next = _pos->next;
          _pos->next = _ins;
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
        UTILITY_ALWAYS_INLINE
        static inline link_type __merge(
          link_type _link1, link_type _link2, _Compare _cmp
        )
        {
          if(_link1 == nullptr)
          { return _link2;}
          if(_link2 == nullptr)
          { return _link1;}

          link_type __flink;
          if(_cmp(_link2->value, _link1->value))
          {
            __link_type __tmp = _link2;
            for(; __tmp->next && _cmp(
                node_trait::get<node_type>(__tmp->next)->value, _link1->value
            );)
            { __tmp = __tmp->next;}
            __flink = _link2;
            _link2 = node_trait::get<node_type>(__tmp->next);
            __tmp->next = _link1;
          }
          else
          { __flink = _link1;}

          link_type __mlink = _link1;
          _link1 = node_trait::get<node_type>(_link1->next);

          for(; _link1 && _link2;)
          {
            if(_cmp(_link2->value, _link1->value))
            {
              __link_type __tmp = _link2;
              for(; __tmp->next && _cmp(
                node_trait::get<node_type>(__tmp->next)->value, _link1->value
              );)
              { __tmp = __tmp->next;}
              __mlink->next = _link2;
              _link2 = node_trait::get<node_type>(__tmp->next);
              __tmp->next = _link1;
            }
            __mlink = _link1;
            _link1 = node_trait::get<node_type>(_link1->next);
          }

          if(_link2)
          { __mlink->next = _link2;}

          return __flink;
        }

        template<typename _Compare>
        static inline link_type __sort(
          link_type _link, size_type _tsize, _Compare _cmp
        )
        {
          if(_tsize < 2)
          { return _link;}
          if(_tsize == 2)
          {
            if(_cmp(node_trait::get<node_type>(_link->next)->value, _link->value))
            {
              __link_type __tmp = _link->next;
              __tmp->next = _link;
              _link->next = nullptr;
              _link = node_trait::get<node_type>(__tmp);
            }
            return _link;
          }

          size_type __len = _tsize / 2;
          link_type __pmid = node_trait::get<node_type>(
            __node_next(_link, __len-1)
          );
          link_type __mid = node_trait::get<node_type>(__pmid->next);
          __pmid->next = nullptr;

          return __merge<_Compare>(
            __sort<_Compare>(_link, __len, _cmp),
            __sort<_Compare>(__mid, _tsize - __len, _cmp),
            _cmp
          );
        }
    };


    template<typename _T, typename _Alloc>
    inline bool operator==(
      const forward_list<_T, _Alloc>& _x, const forward_list<_T, _Alloc>& _y
    )
    {
      return _x.size() == _y.size() &&
        algorithm::equal(_x.begin(), _x.end(), _y.begin());
    }
    template<typename _T, typename _Alloc>
    inline bool operator!=(
      const forward_list<_T, _Alloc>& _x, const forward_list<_T, _Alloc>& _y
    )
    { return !(_x == _y);}
    template<typename _T, typename _Alloc>
    inline bool operator<(
      const forward_list<_T, _Alloc>& _x, const forward_list<_T, _Alloc>& _y
    )
    {
      return algorithm::lexicographical_compare(
        _x.begin(), _x.end(), _y.begin(), _y.end()
      );
    }
    template<typename _T, typename _Alloc>
    inline bool operator>(
      const forward_list<_T, _Alloc>& _x, const forward_list<_T, _Alloc>& _y
    )
    { return _y < _x;}
    template<typename _T, typename _Alloc>
    inline bool operator<=(
      const forward_list<_T, _Alloc>& _x, const forward_list<_T, _Alloc>& _y
    )
    { return !(_y < _x);}
    template<typename _T, typename _Alloc>
    inline bool operator>=(
      const forward_list<_T, _Alloc>& _x, const forward_list<_T, _Alloc>& _y
    )
    { return !(_x < _y);}
  }

   __utility_interspace_start(algorithm)
  {
    template<typename _T, typename _Alloc>
    inline void swap(
      container::forward_list<_T, _Alloc>& _x,
      container::forward_list<_T, _Alloc>& _y
    ) noexcept(noexcept(_x.swap(_y)))
    { _x.swap(_y);}
    template<typename _T, typename _Alloc>
    inline void possible_swap(
      container::forward_list<_T, _Alloc>& _x,
      container::forward_list<_T, _Alloc>& _y
    ) noexcept(noexcept(_x.possible_swap(_y)))
    { _x.possible_swap(_y);}
  }
__utility_globalspace_end(utility)


#endif // ! __UTILITY_CONTAINER_FORWARD_LIST__

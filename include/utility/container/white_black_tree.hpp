
#ifndef __UTILITY_CONTAINER_WHITE_BLACK_TREE__
#define __UTILITY_CONTAINER_WHITE_BLACK_TREE__

/**
 * \file white_black_tree.hpp
 * \author Inochi Amaoto
 *
 */

#include<utility/config/utility_config.hpp>
#include<utility/container/container_helper.hpp>

#include<utility/algorithm/swap.hpp>
#include<utility/algorithm/possible_swap.hpp>
#include<utility/algorithm/algorithm_auxiliary.hpp>
#include<utility/algorithm/move.hpp>
#include<utility/algorithm/forward.hpp>
#include<utility/algorithm/equal.hpp>
#include<utility/algorithm/lexicographical_compare.hpp>

#include<utility/container/helper/node.hpp>
#include<utility/container/helper/node_pool.hpp>
#include<utility/container/pair.hpp>
#include<utility/container/compressed_pair.hpp>

#include<utility/trait/type/releations/is_same.hpp>
#include<utility/trait/type/features/is_swappable.hpp>
#include<utility/trait/type/features/is_possible_swappable.hpp>
#include<utility/trait/type/features/is_nothrow_swappable.hpp>
#include<utility/trait/type/features/is_nothrow_possible_swappable.hpp>
#include<utility/trait/type/features/is_default_constructible.hpp>
#include<utility/trait/type/features/is_copy_constructible.hpp>
#include<utility/trait/type/miscellaneous/enable_if.hpp>

#include<utility/trait/miscellaneous/pointer_traits.hpp>

#include<utility/memory/allocator.hpp>
#include<utility/memory/allocator_traits.hpp>
#include<utility/memory/unique_ptr.hpp>
#include<utility/memory/raw_delete.hpp>

#include<utility/iterator/iterator_tag.hpp>
#include<utility/iterator/reverse_iterator.hpp>
#include<utility/iterator/distance.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(container)
    __utility_interspace_start(_helper)
      struct __UTILITY_TYPE_VIS __wbtree_node
      {
        public:
          typedef __tree_tag        __tag;
          typedef __wbtree_node*    __link_type;
          typedef bool              __color_type;

          __link_type         head;
          __link_type         left;
          __link_type         right;
          __color_type        color;
      };

      template<>
      struct __UTILITY_TYPE_VIS __node_trait<__wbtree_node, __tree_tag>
      {
        typedef __wbtree_node          __node_type;
        typedef __wbtree_node*         __link_type;
        typedef const __wbtree_node*   __const_link_type;

        template<typename _U>
        UTILITY_ALWAYS_INLINE
        static _U* get(__link_type _link) noexcept
        { return static_cast<_U*>(_link);}
        template<typename _U>
        UTILITY_ALWAYS_INLINE
        static const _U* get(__const_link_type _link) noexcept
        { return static_cast<const _U*>(_link);}

        UTILITY_ALWAYS_INLINE
        static __link_type minimum(__link_type _link) noexcept
        {
          for(; _link->left;)
          { _link = _link->left;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __link_type maximum(__link_type _link) noexcept
        {
          for(; _link->right;)
          { _link = _link->right;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __link_type next(__link_type _link) noexcept
        {
          if(_link->right)
          { return minimum(_link->right);}

          __link_type __tmp = _link->head;

          for(; _link == __tmp->right;)
          {
            _link = __tmp;
            __tmp = __tmp->head;
          }
          if(_link->right != __tmp)
          { _link= __tmp;}

          // for(; _link == _link->head->right;)
          // { _link = _link->head;}
          // if(_link->right != _link->head)
          // { _link = _link->head;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __link_type prev(__link_type _link) noexcept
        {
          if(!_link->color && _link->head->head == _link)
          { return _link->right;}
          if(_link->left)
          { return maximum(_link->left);}
          for(; _link == _link->head->left;)
          { _link = _link->head;}
          return _link->head;
        }
        UTILITY_ALWAYS_INLINE
        static __const_link_type minimum(__const_link_type _link) noexcept
        {
          for(; _link->left;)
          { _link = _link->left;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __const_link_type maximum(__const_link_type _link) noexcept
        {
          for(; _link->right;)
          { _link = _link->right;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __const_link_type next(__const_link_type _link) noexcept
        {
          if(_link->right)
          { return minimum(_link->right);}
          for(; _link == _link->head->right;)
          { _link = _link->head;}
          if(_link->right != _link->head)
          { _link = _link->head;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __const_link_type prev(__const_link_type _link) noexcept
        {
          if(!_link->color && _link->head->head == _link)
          { return _link->right;}
          if(_link->left)
          { return maximum(_link->left);}
          for(; _link == _link->head->left;)
          { _link = _link->head;}
          return _link->head;
        }
      };

    __utility_interspace_end(_helper)

    template<
      typename _Key,
      typename _Value,
      typename _Compare = algorithm::less<_Key>,
      typename _Container = container::pair<const _Key, _Value>,
      typename _Alloc = memory::allocator<_Container>
    >
    class white_black_tree;


    namespace __detail
    {
      using trait::miscellaneous::pointer_traits;
      using trait::type::miscellaneous::enable_if;

      template<typename _T>
      class __UTILITY_TEMPLATE_VIS __wbtree_const_iterator;

      template<typename _T>
      class __UTILITY_TEMPLATE_VIS __wbtree_iterator
      {
        private:
          template<typename, typename, typename, typename, typename>
          friend class container::white_black_tree;
          template<typename>
          friend class __wbtree_const_iterator;

        private:
          typedef _helper::__node_trait<_helper::__wbtree_node> node_trait;

        public:
          typedef helper::bidirectional_iterator_tag      iterator_category;
          typedef _T                                      value_type;
          typedef value_type&                             reference;
          typedef typename pointer_traits<_T*>::pointer   pointer;
          typedef typename pointer_traits<_T*>::difference_type
            difference_type;

        private:
          typedef typename node_trait::__link_type    __link_type;
          typedef typename node_trait::__node_type    __node_type;
          typedef _helper::__node<_T, __node_type>    __node;

        private:
          __link_type     __ptr;

        public:
          inline constexpr __wbtree_iterator() noexcept = default;
          inline constexpr
          explicit __wbtree_iterator(__link_type _link) noexcept:
            __ptr{_link}
          { }

        public:
          reference operator*() const noexcept
          { return node_trait::get<__node>(__ptr)->value;}
          pointer operator->() const noexcept
          { return &(node_trait::get<__node>(__ptr)->value);}

        public:
          inline __wbtree_iterator& operator++() noexcept
          {
            __ptr = node_trait::next(__ptr);
            return *this;
          }
          inline __wbtree_iterator operator++(int) noexcept
          {
            __wbtree_iterator __tmp{*this};
            __ptr = node_trait::next(__ptr);
            return __tmp;
          }
          inline __wbtree_iterator& operator--() noexcept
          {
            __ptr = node_trait::prev(__ptr);
            return *this;
          }
          inline __wbtree_iterator operator--(int) noexcept
          {
            __wbtree_iterator __tmp{*this};
            __ptr = node_trait::prev(__ptr);
            return __tmp;
          }

        public:
          inline bool operator==(const __wbtree_iterator& _other) const noexcept
          { return __ptr == _other.__ptr;}
          inline bool operator!=(const __wbtree_iterator& _other) const noexcept
          { return __ptr != _other.__ptr;}
      };

      template<typename _T>
      class __UTILITY_TEMPLATE_VIS __wbtree_const_iterator
      {
        private:
          template<typename, typename, typename, typename, typename>
          friend class container::white_black_tree;;

        private:
          typedef _helper::__node_trait<_helper::__wbtree_node> node_trait;

        public:
          typedef helper::bidirectional_iterator_tag      iterator_category;
          typedef _T                                      value_type;
          typedef const value_type&                       reference;
          typedef typename pointer_traits<const _T*>::pointer   pointer;
          typedef typename pointer_traits<const _T*>::difference_type
            difference_type;

        private:
          typedef typename node_trait::__link_type          __link_type;
          typedef typename node_trait::__node_type          __node_type;
          typedef const _helper::__node<_T, __node_type>    __node;

        private:
          __link_type     __ptr;

        public:
          inline constexpr __wbtree_const_iterator() noexcept = default;
          inline constexpr
          explicit __wbtree_const_iterator(__link_type _link) noexcept:
            __ptr{_link}
          { }
          inline constexpr __wbtree_const_iterator(
            const __wbtree_iterator<value_type>& _it
          ) noexcept: __ptr{_it.__ptr}
          { }

        public:
          reference operator*() const noexcept
          { return node_trait::get<__node>(__ptr)->value;}
          pointer operator->() const noexcept
          { return &(node_trait::get<__node>(__ptr)->value);}

        public:
          inline __wbtree_const_iterator& operator++() noexcept
          {
            __ptr = node_trait::next(__ptr);
            return *this;
          }
          inline __wbtree_const_iterator operator++(int) noexcept
          {
            __wbtree_const_iterator __tmp{*this};
            __ptr = node_trait::next(__ptr);
            return __tmp;
          }
          inline __wbtree_const_iterator& operator--() noexcept
          {
            __ptr = node_trait::prev(__ptr);
            return *this;
          }
          inline __wbtree_const_iterator operator--(int) noexcept
          {
            __wbtree_const_iterator __tmp{*this};
            __ptr = node_trait::prev(__ptr);
            return __tmp;
          }

        public:
          inline bool operator==(
            const __wbtree_const_iterator& _other
          ) const noexcept
          { return __ptr == _other.__ptr;}
          inline bool operator!=(
            const __wbtree_const_iterator& _other
          ) const noexcept
          { return __ptr != _other.__ptr;}
      };
    }

    template<
      typename _Key,
      typename _Value,
      typename _Compare,
      typename _Container,
      typename _Alloc
    >
    class __UTILITY_TEMPLATE_VIS white_black_tree
    {
      private:
        constexpr static bool __white = true;
        constexpr static bool __black = false;

      public:
        typedef _Key                              key_type;
        typedef _Value                            mapped_type;
        typedef _Container                        value_type;
        typedef _Compare                          key_compare;
        typedef size_t                            size_type;
        typedef ptrdiff_t                         difference_type;
        typedef value_type&                       reference;
        typedef const value_type&                 const_reference;
        typedef _Alloc                            allocator_type;
        typedef memory::allocator_traits<_Alloc>  allocator_traits_type;

      public:
        typedef typename allocator_traits_type::pointer pointer;
        typedef typename allocator_traits_type::const_pointer const_pointer;

      private:
        typedef _helper::__wbtree_node                      __node_type;
        typedef __node_type*                                __link_type;
        typedef _helper::__node<value_type, __node_type>    node_type;
        typedef node_type*                                  link_type;
        typedef _helper::__node_trait<__node_type>          node_trait;
        typedef _helper::__node_pool<node_type>             node_pool;

      public:
        typedef __detail::__wbtree_iterator<value_type>       iterator;
        typedef __detail::__wbtree_const_iterator<value_type> const_iterator;
        typedef helper::reverse_iterator<iterator>
          reverse_iterator;
        typedef helper::reverse_iterator<const_iterator>
          const_reverse_iterator;

      private:
        typedef compressed_pair<__node_type, allocator_type> __base_type;
        typedef compressed_pair<size_type, key_compare> __mis_type;


      private:
        node_pool     __pool;
        __base_type   __base;
        __mis_type    __mis;

      public: // assert:
        static_assert(trait::type::releations::is_same<
          value_type, typename allocator_type::value_type>::value,
          "the allocator's alloc type must be the same as value type");


      public:
        explicit white_black_tree():
          __pool{}, __base{}, __mis{}
        { _init();}

        explicit white_black_tree(
          const key_compare& _cmp,
          const allocator_type& _alloc = allocator_type{}
        ):__pool{}, __base{__node_type{}, _alloc}, __mis{0U, _cmp}
        { _init();}

        explicit white_black_tree(const allocator_type& _alloc):
          __pool{}, __base{__node_type{}, _alloc}, __mis{}
        { _init();}

        template<
          typename _InputIterator,
          typename __detail::enable_if<
            is_iterator<_InputIterator>::value,
          bool>::type = true
        >
        white_black_tree(
          _InputIterator _first, _InputIterator _last,
          const key_compare& _cmp = key_compare(),
          const allocator_type& _alloc = allocator_type()
        ):__pool{}, __base{__node_type{}, _alloc}, __mis{0U, _cmp}
        {
          _init();
          for(; _first != _last;)
          { this->insert_equal(*_first++);}
        }

        template<
          typename _InputIterator,
          typename __detail::enable_if<
            is_iterator<_InputIterator>::value,
          bool>::type = true
        >
        white_black_tree(
          _InputIterator _first, _InputIterator _last,
          const allocator_type& _alloc
        ):__pool{}, __base{__node_type{}, _alloc}, __mis{}
        {
          _init();
          for(; _first != _last;)
          { this->insert_equal(*_first++);}
        }

        white_black_tree(const white_black_tree& _other):
          __pool{}, __base{__node_type{}, _other.__base.second()},
          __mis{_other.__mis.first(), _other.__mis.second()}
        {
          _init();
          __link_type __head = &(__base.first());
          if(_other.size())
          {
            link_type __root = node_trait::get<node_type>(
              _other.__base.first().head
            );
            __head->head = _tree_copy(__root, __head);
            __head->left = node_trait::minimum(__head->head);
            __head->right = node_trait::maximum(__head->head);
          }
        }
        white_black_tree(
          const white_black_tree& _other,
          const allocator_type& _alloc
        ):
          __pool{}, __base{__node_type{}, _alloc},
          __mis{_other.__mis.first(), _other.__mis.second()}
        {
          _init();
          __link_type __head = &(__base.first());
          if(_other.size())
          {
            link_type __root = node_trait::get<node_type>(
              _other.__base.first().head
            );
            __head->head = _tree_copy(__root, __head);
            __head->left = node_trait::minimum(__head->head);
            __head->right = node_trait::maximum(__head->head);
          }
        }

        white_black_tree(white_black_tree&& _other):
          __pool{algorithm::move(_other.__pool)},
          __base{algorithm::move(_other.__base)},
          __mis{algorithm::move(_other.__mis)}
        {
          __link_type __now = &(__base.first());
          __now->head->head = __now;
          _other.__mis.first() = 0U;
        }
        white_black_tree(
          white_black_tree&& _other,
          const allocator_type& _alloc
        ):
          __pool{algorithm::move(_other.__pool)},
          __base{_other.__base.first(), _alloc},
          __mis{algorithm::move(_other.__mis)}
        {
          __link_type __now = &(__base.first());
          __now->head->head = __now;
          _other.__mis.first() = 0U;
        }

        white_black_tree(
          initializer_list<value_type> __init,
          const key_compare& _cmp = key_compare{},
          const allocator_type& _alloc = allocator_type{}
        ):__pool{}, __base{__node_type{}, _alloc},
          __mis{0U, _cmp}
        {
          typedef typename initializer_list<value_type>::iterator __iterator;
          _init();
          __iterator __end = __init.end();
          for(__iterator __it = __init.begin(); __it != __end; ++__it)
          { insert_equal(*__it);}
        }
        white_black_tree(
          initializer_list<value_type> __init,
          const allocator_type& _alloc
        ):__pool{}, __base{__node_type{}, _alloc}, __mis{}
        {
          typedef typename initializer_list<value_type>::iterator __iterator;
          _init();
          __iterator __end = __init.end();
          for(__iterator __it = __init.begin(); __it != __end; ++__it)
          { insert_equal(*__it);}
        }

        ~white_black_tree()
        { this->force_clear();}

      public:
        white_black_tree& operator=(const white_black_tree& _other)
        {
          if(this != &_other)
          {
            if(__mis.first())
            { clear();}
            else
            { _init();}
            __link_type __head = &(__base.first());
            __mis = _other.__mis;
            if(_other.size())
            {
              link_type __root = node_trait::get<node_type>(
                _other.__base.first().head
              );
              __head->head = _tree_copy(__root, __head);
              __head->left = node_trait::minimum(__head->head);
              __head->right = node_trait::maximum(__head->head);
            }
          }
          return *this;
        }
        white_black_tree& operator=(white_black_tree&& _other)
        {
          using algorithm::move;

          if(this != &_other)
          {
            if(__mis.first())
            { clear();}
            else
            { _init();}
            __pool.merge(_other.__pool);
            __base = move(_other.__base);
            __mis = move(_other.__mis);
            __link_type __now = &(__base.first());
            __now->head->head = __now;
            _other.__mis.first() = 0U;
          }

          return *this;
        }
        white_black_tree& operator=(initializer_list<value_type> __init)
        {
          typedef typename initializer_list<value_type>::iterator __iterator;
          if(__mis.first())
          { clear();}
          else
          { _init();}
          __iterator __end = __init.end();
          for(__iterator __it = __init.begin(); __it != __end; ++__it)
          { insert_equal(*__it);}

          return *this;
        }


      public:
        allocator_type get_allocator() const
        { return __base.second();}

      public:
        iterator begin() noexcept
        { return iterator{__base.first().left};}
        const_iterator begin() const noexcept
        { return const_iterator{__base.first().left};}
        const_iterator cbegin() const noexcept
        { return const_iterator{__base.first().left};}
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
        { return __base.first().head == nullptr;}
        size_type size() const noexcept
        { return __mis.first();}
        inline size_type max_size() const noexcept
        { return ~size_type{0U};}

      public:
        reference minimum() noexcept
        { return _get(__base.first().left);}
        const_reference minimum() const noexcept
        { return _get(__base.first().left);}
        reference maximum() noexcept
        { return _get(__base.first().right);}
        const_reference maximum() const noexcept
        { return _get(__base.first().right);}

      public:
        pair<iterator, bool> insert_unique(const value_type& _val)
        { return __insert_unique(_allocate_node(_val), this);}
        pair<iterator, bool> insert_unique(const value_type&& _val)
        {
          using algorithm::move;
          return __insert_unique(_allocate_node(move(_val)), this);
        }
        iterator insert_unique(const_iterator _hint, const value_type& _val)
        { return __insert_unique(_hint.__ptr, _allocate_node(_val), this);}
        iterator insert_unique(const_iterator _hint, value_type&& _val)
        {
          using algorithm::move;
          return __insert_unique(
            _hint.__ptr, _allocate_node(move(_val)), this
          );
        }
        iterator insert_equal(const value_type& _val)
        { return __insert_equal(_allocate_node(_val), this);}
        iterator insert_equal(value_type&& _val)
        {
          using algorithm::move;
          return __insert_equal(_allocate_node(move(_val)), this);
        }
        iterator insert_equal(const_iterator _hint, const value_type& _val)
        { return __insert_equal(_hint.__ptr, _allocate_node(_val), this);}
        iterator insert_equal(const_iterator _hint, value_type&& _val)
        {
          using algorithm::move;
          return __insert_equal(_hint.__ptr, _allocate_node(move(_val)), this);
        }

      public:
        template<typename... _Args>
        pair<iterator, bool> emplace_unique(_Args&&... _args)
        {
          using algorithm::forward;
          return __insert_unique(
            _allocate_node(forward<_Args>(_args)...), this
          );
        }
        template<typename... _Args>
        iterator emplace_equal(_Args&&... _args)
        {
          using algorithm::forward;
          return __insert_equal(
            _allocate_node(forward<_Args>(_args)...), this
          );
        }
        template<typename... _Args>
        iterator emplace_unique_hint(const_iterator _hint, _Args&&... _args)
        {
          using algorithm::forward;
          return __insert_unique(
            _hint.__ptr, _allocate_node(forward<_Args>(_args)...), this
          );
        }
        template<typename... _Args>
        iterator emplace_equal_hint(const_iterator _hint, _Args&&... _args)
        {
          using algorithm::forward;
          return __insert_equal(
            _hint.__ptr, _allocate_node(forward<_Args>(_args)...), this
          );
        }

      public:
        inline size_type count(const key_type& __key) const
        {
          using helper::distance;
          return distance(this->lower_bound(__key), this->upper_bound(__key));
        }

      public:
        inline iterator find(const key_type& __key)
        {
          iterator __res{__lower_bound(this, __key)};
          return __res == end() || __mis.second()(__key, _key(__res.__ptr)) ?
            end(): __res;
        }
        inline const_iterator find(const key_type& __key) const
        {
          const_iterator __res{
            const_cast<__link_type>(__lower_bound(this, __key))
          };
          return __res == end() || __mis.second()(__key, _key(__res.__ptr)) ?
            end(): __res;
        }

      public:
        inline iterator lower_bound(const key_type& __key)
        { return iterator{__lower_bound(this, __key)};}
        inline const_iterator lower_bound(const key_type& __key) const
        {
          return const_iterator{
            const_cast<__link_type>(__lower_bound(this, __key))
          };
        }
        inline iterator upper_bound(const key_type& __key)
        { return iterator{__upper_bound(this, __key)};}
        inline const_iterator upper_bound(const key_type& __key) const
        {
          return const_iterator{
            const_cast<__link_type>(__upper_bound(this, __key))
          };
        }
        inline pair<iterator, iterator> equal_range(const key_type& __key)
        {
          return pair<iterator, iterator>{
            this->lower_bound(__key), this->upper_bound(__key)
          };
        }
        inline pair<const_iterator, const_iterator>
        equal_range(const key_type& __key) const
        {
          return pair<const_iterator, const_iterator>{
            this->lower_bound(__key), this->upper_bound(__key)
          };
        }


      public:
        iterator erase(const_iterator _pos)
        {
          iterator __res{_pos.__ptr};
          ++__res;
          __link_type __head = &(__base.first());
          __link_type __del = __erase_rebalance(
            _pos.__ptr, __head->head, __head->left, __head->right
          );
          _destroy_node(node_trait::get<node_type>(__del));
          --(__mis.first());
          return __res;
        }
        iterator erase(const_iterator _first, const_iterator _last)
        {
          if(_first == begin() && _last == end())
          {
            clear();
            return end();
          }
          else
          {
            for(; _first != _last;)
            { erase(_first++);}
          }
          return iterator{_last.__ptr};
        }
        size_type erase(const key_type __key)
        {
          using helper::distance;
          pair<const_iterator, const_iterator> __tmp = equal_range(__key);
          size_type __res = distance(__tmp.first, __tmp.second);
          erase(__tmp.first, __tmp.second);
          return __res;
        }

      public:
        void clear()
        {
          if(__mis.first())
          {
            _tree_clear(node_trait::get<node_type>(__base.first().head));
            _init();
            __mis.first() = 0U;
          }
        }

      public:
        template<
          typename _Key_Compare = key_compare,
          typename trait::type::miscellaneous::enable_if<
            trait::type::features::is_swappable<_Key_Compare>::value,
          bool>::type = true
        >
        void swap(white_black_tree& __other) noexcept(
          trait::type::features::is_nothrow_swappable<key_compare>::value &&
          trait::type::features::is_nothrow_swappable<allocator_type>::value
        )
        {
          using algorithm::swap;
          swap(__base,    __other.__base);
          swap(__mis,     __other.__mis);
          return;
        }
        template<
          typename _Key_Compare = key_compare, typename __Alloc = allocator_type,
          typename trait::type::miscellaneous::enable_if<
            trait::type::features::is_possible_swappable<_Key_Compare>::value &&
            trait::type::features::is_possible_swappable<__Alloc>::value,
          bool>::type = true
        >
        void possible_swap(white_black_tree& __other) noexcept(
          trait::type::features::is_nothrow_possible_swappable<key_compare>::value
        )
        {
          using algorithm::possible_swap;
          possible_swap(__base,   __other.__base);
          possible_swap(__mis,    __other.__mis);
          return;
        }

      private:
        void _init() noexcept
        {
          __link_type __root = &(__base.first());
          __root->head = nullptr;
          __root->color = __white;
          __root->left = __root->right = __root;
        }
        void force_clear()
        {
          if(__mis.first())
          { _tree_destroy(node_trait::get<node_type>(__base.first().head));}
        }

      private:
        void _tree_clear(link_type _root)
        {
          for(; _root;)
          {
            _tree_clear(node_trait::get<node_type>(_root->right));
            link_type __left = node_trait::get<node_type>(_root->left);
            _destroy_node(_root);
            _root = __left;
          }
        }
        void _tree_destroy(link_type _root)
        {
          for(; _root;)
          {
            _tree_destroy(node_trait::get<node_type>(_root->right));
            link_type __left = node_trait::get<node_type>(_root->left);
            _deallocate_node(_root);
            _root = __left;
          }
        }
        link_type _tree_copy(link_type _src, __link_type _dest)
        {
          link_type __tmp = _allocate_node(_get(_src));
          __tmp->head = _dest;
          __UTILITY_TRY_BEGIN
            if(_src->right)
            {
              __tmp->right = _tree_copy(
                node_trait::get<node_type>(_src->right), __tmp
              );
            }
            _dest = __tmp;
            _src = node_trait::get<node_type>(_src->left);
            for(; _src;)
            {
              link_type __left = _allocate_node(_get(_src));
              _dest->left = __left;
              __left->head = _dest;
              if(_src->right)
              {
                __left->right = _tree_copy(
                  node_trait::get<node_type>(_src->right), __left
                );
              }
              _dest = __left;
              _src = node_trait::get<node_type>(_src->left);
            }
          __UTILITY_TRY_END
          __UTILITY_CATCH(...)
          __UTILITY_CATCH_UNWIND(_tree_destroy(__tmp););
          return __tmp;
        }

      private:
        template<typename... _Args>
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
          __require->left = __require->right = nullptr;
          __handler __holder{__require};
          allocator_traits_type::construct(
            __base.second(), &(__holder->value), forward<_Args>(_args)...
          );

          return __holder.release();
        }
        inline void _deallocate_node(link_type _pos)
        {
          using memory::default_deallocate;
          allocator_traits_type::destroy(
            __base.second(), &(_pos->value)
          );
          default_deallocate(_pos);
        }
        inline void _destroy_node(link_type _pos)
        {
          using memory::default_deallocate;
          allocator_traits_type::destroy(
            __base.second(), &(_pos->value)
          );
          __pool.push(_pos);
        }

      private:
        static inline __link_type __lower_bound(
          white_black_tree* _this, const key_type& __key
        )
        {
          __link_type __head = &(_this->__base.first());
          __link_type __pos = __head->head;

          for(; __pos;)
          {
            if(!(_this->__mis.second()(_key(__pos), __key)))
            {
              __head = __pos;
              __pos = __pos->left;
            }
            else
            { __pos = __pos->right;}
          }

          return __head;
        }
        static inline const __node_type* __lower_bound(
          const white_black_tree* _this, const key_type& __key
        )
        {
          const __node_type* __head = &(_this->__base.first());
          const __node_type* __pos = __head->head;

          for(; __pos;)
          {
            if(!(_this->__mis.second()(_key(__pos), __key)))
            {
              __head = __pos;
              __pos = __pos->left;
            }
            else
            { __pos = __pos->right;}
          }

          return __head;
        }
        static inline const __node_type* __upper_bound(
          const white_black_tree* _this, const key_type& __key
        )
        {
          const __node_type* __head = &(_this->__base.first());
          const __node_type* __pos = __head->head;

          for(; __pos;)
          {
            if(_this->__mis.second()(__key, _key(__pos)))
            {
              __head = __pos;
              __pos = __pos->left;
            }
            else
            { __pos = __pos->right;}
          }

          return __head;
        }
        static inline __link_type __upper_bound(
          white_black_tree* _this, const key_type& __key
        )
        {
          __link_type __head = &(_this->__base.first());
          __link_type __pos = __head->head;

          for(; __pos;)
          {
            if(_this->__mis.second()(__key, _key(__pos)))
            {
              __head = __pos;
              __pos = __pos->left;
            }
            else
            { __pos = __pos->right;}
          }

          return __head;
        }

      private:
        static inline pair<iterator, bool> __insert_unique(
          __link_type _ins, white_black_tree* _this
        )
        {
          __link_type __head = &(_this->__base.first());
          __link_type __pos = __head->head;
          bool __comp = true;

          for(; __pos;)
          {
            __head = __pos;
            __comp = _this->__mis.second()(_key(_ins), _key(__pos));
            __pos = __comp ? __pos->left : __pos->right;
          }

          iterator __tmp{__head};

          if(__comp)
          {
            if(__tmp == _this->begin())
            {
              return pair<iterator, bool>{
                __insert(__pos, __head, _ins, _this), true
              };
            }
            else
            { --__tmp;}
          }
          if(_this->__mis.second()(_key(__tmp.__ptr), _key(_ins)))
          {
            return pair<iterator, bool>{
              __insert(__pos, __head, _ins, _this), true
            };
          }
          _this->_destroy_node(node_trait::get<node_type>(_ins));
          return pair<iterator, bool>{__tmp, false};
        }
        static inline iterator __insert_unique(
          __link_type _hint, __link_type _ins,
          white_black_tree* _this
        )
        {
          __link_type __head = &(_this->__base.first());
          // The first node.
          if(_hint == __head->left)
          {
            if(_this->__mis.first() &&
               _this->__mis.second()(_key(_ins), _key(_hint))
            )
            { return __insert(_hint, _hint, _ins, _this);}
            return __insert_unique(_ins, _this).first;
          }

          // The last node.
          if(_hint == __head)
          {
            if(_this->__mis.second()(_key(__head->right), _key(_ins)))
            { return __insert(nullptr, __head->right, _ins, _this);}
            return __insert_unique(_ins, _this).first;
          }

          __link_type __before = node_trait::prev(_hint);
          if(_this->__mis.second()(_key(__before), _key(_ins)) &&
             _this->__mis.second()(_key(_ins), _key(_hint))
          )
          {
            if(__before->right)
            { return __insert(_hint, _hint, _ins, _this);}
            return __insert(nullptr, __before, _ins, _this);
          }
          return __insert_unique(_ins, _this).first;
        }

        static iterator __insert_equal(
          __link_type _ins, white_black_tree* _this
        )
        {
          __link_type __head = &(_this->__base.first());
          __link_type __pos = __head->head;
          for(; __pos;)
          {
            __head = __pos;
            __pos = _this->__mis.second()(_key(_ins), _key(__pos)) ?
              __pos->left: __pos->right;
          }

          return __insert(__pos, __head, _ins, _this);
        }
        static iterator __insert_equal(
          __link_type _hint, __link_type _ins,
          white_black_tree* _this
        )
        {
          __link_type __head = &(_this->__base.first());

          // The first node.
          if(_hint == __head->left)
          {
            if(_this->__mis.first() &&
               !(_this->__mis.second()(_key(_hint), _key(_ins)))
            )
            { return __insert(_hint, _hint, _ins, _this);}
            return __insert_equal(_ins, _this);
          }

          // The last node.
          if(_hint == __head)
          {
            if(!(_this->__mis.second()(_key(_ins), _key(__head->right))))
            { return __insert(nullptr, __head->right, _ins, _this);}
            return __insert_equal(_ins, _this);
          }

          __link_type __before = node_trait::prev(_hint);
          if(!(_this->__mis.second()(_key(_ins), _key(__before))) &&
             !(_this->__mis.second()(_key(_hint), _key(_ins)))
          )
          {
            if(__before->right)
            { return __insert(_hint, _hint, _ins, _this);}
            return __insert(nullptr, __before, _ins, _this);
          }

          return __insert_equal(_ins, _this);
        }

        static inline iterator __insert(
          __link_type _x, __link_type _y, __link_type _z,
          white_black_tree* _this
        )
        {
          __link_type __head = &(_this->__base.first());
          if(_y == __head || _x || _this->__mis.second()(_key(_z), _key(_y)))
          {
            _y->left = _z;
            if(_y == __head)
            {
              __head->head = _z;
              __head->right = _z;
            }
            else if(_y == __head->left)
            { __head->left = _z;}
          }
          else
          {
            _y->right = _z;
            if(_y == __head->right)
            { __head->right = _z;}
          }

          _z->head = _y;
          _z->right = _z->left = nullptr;
          __insert_rebalance(_z, __head->head);
          ++(_this->__mis.first());
          return iterator{_z};
        }

      private:
        static inline void __rotate_left(
          __link_type _x, __link_type& _root
        ) noexcept
        {
          // Get right node __y
          __link_type __y = _x->right;
          _x->right = __y->left;

          // set __y's left child parent
          if(__y->left)
          { __y->left->head = _x;}
          __y->head = _x->head;

          // set __y's position
          if(_x == _root)
          { _root = __y;}
          else if(_x == _x->head->left)
          { _x->head->left = __y;}
          else
          { _x->head->right = __y;}

          // link _x and __y
          __y->left = _x;
          _x->head = __y;
        }
        static inline void __rotate_right(
          __link_type _x, __link_type& _root
        )
        {
          __link_type __y = _x->left;
          _x->left = __y->right;

          if(__y->right)
          { __y->right->head = _x;}
          __y->head = _x->head;

          if(_x == _root)
          { _root = __y;}
          else if(_x == _x->head->right)
          { _x->head->right = __y;}
          else
          { _x->head->left = __y;}

          __y->right = _x;
          _x->head = __y;
        }
        static void __insert_rebalance(
          __link_type _x, __link_type& _root
        ) noexcept
        {
          _x->color = __white;
          for(;_x != _root && _x->head->color == __white;)
          {
            if(_x->head == _x->head->head->left)
            {
              __link_type __y = _x->head->head->right;
              if(__y != nullptr && __y->color == __white)
              {
                _x->head->color = __black;
                __y->color = __black;
                _x->head->head->color = __white;
                _x = _x->head->head;
              }
              else
              {
                if(_x == _x->head->right)
                {
                  _x = _x->head;
                  __rotate_left(_x, _root);
                }
                _x->head->color = __black;
                _x->head->head->color = __white;
                __rotate_right(_x->head->head, _root);
              }
            }
            else
            {
              __link_type __y = _x->head->head->left;
              if(__y != nullptr && __y->color == __white)
              {
                _x->head->color = __black;
                __y->color = __black;
                _x->head->head->color = __white;
                _x = _x->head->head;
              }
              else
              {
                if(_x == _x->head->left)
                {
                  _x = _x->head;
                  __rotate_right(_x, _root);
                }
                _x->head->color = __black;
                _x->head->head->color = __white;
                __rotate_left(_x->head->head, _root);
              }
            }
          }
          _root->color = __black;
        }
        static __link_type __erase_rebalance(
          __link_type _z,         __link_type& _root,
          __link_type& _leftmost, __link_type& _rightmost
        ) noexcept
        {
          using algorithm::swap;
          __link_type __y = _z;
          __link_type __x = nullptr;
          __link_type __x_par = nullptr;

          if(__y->left == nullptr)
          { __x = __y->right;}
          else
          {
            if(__y->right == nullptr)
            { __x = __y->left;}
            else
            {
              __y = __y->right;
              for(;__y->left != nullptr;)
              { __y = __y->left;}
              __x = __y->right;
            }
          }

          if(__y != _z)
          {
            _z->left->head = __y;
            __y->left = _z->left;
            if(__y != _z->right)
            {
              __x_par = __y->head;
              if(__x != nullptr)
              { __x->head = __y->head;}
              __y->head->left = __x;
              __y->right = _z->right;
              _z->right->head = __y;
            }
            else
            { __x_par = __y;}

            if(_root == _z)
            { _root = __y;}
            else if(_z->head->left == _z)
            { _z->head->left = __y;}
            else
            { _z->head->right = __y;}

            __y->head = _z->head;
            swap(__y->color, _z->color);
            __y = _z;
          }
          else
          {
            __x_par = __y->head;
            if(__x != nullptr)
            { __x->head= __y->head;}

            if(_root == _z)
            { _root = __x;}
            else if(_z->head->left == _z)
            { _z->head->left = __x;}
            else
            { _z->head->right = __x;}

            if(_leftmost == _z)
            {
              if(_z->right == nullptr)
              { _leftmost = _z->head;}
              else
              { _leftmost = node_trait::minimum(__x);}
            }
            if(_rightmost == _z)
            {
              if(_z->left == nullptr)
              { _rightmost = _z->head;}
              else
              { _rightmost = node_trait::minimum(__x);}
            }
          }

          if(__y->color != __white)
          {
            for(; __x != _root && (__x == nullptr || __x->color == __black);)
            {
              if(__x == __x_par->left)
              {
                __link_type __w = __x_par->right;
                if(__w->color == __white)
                {
                  __w->color = __black;
                  __x_par->color = __white;
                  __rotate_left(__x_par, _root);
                  __w = __x_par->right;
                }

                if((__w->left == nullptr ||
                    __w->left->color == __black) &&
                   (__w->right == nullptr ||
                    __w->right->color == __black)
                )
                {
                  __w->color = __white;
                  __x = __x_par;
                  __x_par = __x_par->head;
                }
                else
                {
                  if(__w->right == nullptr || __w->right->color == __black)
                  {
                    if(__w->left != nullptr)
                    { __w->left->color = __black;}
                    __w->color = __white;
                    __rotate_right(__w, _root);
                    __w = __x_par->right;
                  }
                  __w->color = __x_par->color;
                  __x_par->color = __black;
                  if(__w->right != nullptr)
                  { __w->right->color = __black;}
                  __rotate_left(__x_par, _root);
                  break;
                }
              }
              else
              {
                __link_type __w = __x_par->left;
                if(__w->color == __white)
                {
                  __w->color = __black;
                  __x_par->color = __white;
                  __rotate_right(__x_par, _root);
                  __w = __x_par->left;
                }

                if((__w->right == nullptr ||
                    __w->right->color == __black) &&
                   (__w->left == nullptr ||
                    __w->left->color == __black)
                )
                {
                  __w->color = __white;
                  __x = __x_par;
                  __x_par = __x_par->head;
                }
                else
                {
                  if(__w->left == nullptr ||
                     __w->left->color == __black
                  )
                  {
                    if(__w->right != nullptr)
                    { __w->right->color = __black;}
                    __w->color = __white;
                    __rotate_left(__w, _root);
                    __w = __x_par->left;
                  }
                  __w->color = __x_par->color;
                  __x_par->color = __black;
                  if(__w->left != nullptr)
                  { __w->left->color = __black;}
                  __rotate_right(__x_par, _root);
                  break;
                }
              }
            }
            if(__x != nullptr)
            { __x->color = __black;}
          }
          return __y;
        }

      private:
        UTILITY_ALWAYS_INLINE
        static inline value_type& _get(__link_type _link) noexcept
        { return node_trait::get<node_type>(_link)->value;}
        UTILITY_ALWAYS_INLINE
        static inline const value_type& _get(const __node_type* _link) noexcept
        { return node_trait::get<node_type>(_link)->value;}
        UTILITY_ALWAYS_INLINE
        static inline const key_type& _key(__link_type _link)
        {
          using container::get;
          return get<0>(_get(_link));
        }
        UTILITY_ALWAYS_INLINE
        static inline const key_type& _key(const __node_type* _link)
        {
          using container::get;
          return get<0>(_get(_link));
        }
        UTILITY_ALWAYS_INLINE
        static inline value_type& _value(__node_type* _link)
        {
          using container::get;
          return get<1>(_get(_link));
        }
        UTILITY_ALWAYS_INLINE
        static inline const value_type& _value(const __node_type* _link)
        {
          using container::get;
          return get<1>(_get(_link));
        }
    };

    template<
      typename _Key, typename _Value, typename _Compare,
      typename _Container, typename _Alloc
    >
    inline bool operator==(
      const white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _x,
      const white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _y
    )
    {
      return _x.size() == _y.size() &&
        algorithm::equal(_x.begin(), _x.end(), _y.begin());
    }
    template<
      typename _Key, typename _Value, typename _Compare,
      typename _Container, typename _Alloc
    >
    inline bool operator!=(
      const white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _x,
      const white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _y
    )
    { return !(_x == _y);}
    template<
      typename _Key, typename _Value, typename _Compare,
      typename _Container, typename _Alloc
    >
    inline bool operator<(
      const white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _x,
      const white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _y
    )
    {
      return algorithm::lexicographical_compare(
        _x.begin(), _x.end(), _y.begin(), _y.end()
      );
    }
    template<
      typename _Key, typename _Value, typename _Compare,
      typename _Container, typename _Alloc
    >
    inline bool operator>(
      const white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _x,
      const white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _y
    )
    { return _y < _x;}
    template<
      typename _Key, typename _Value, typename _Compare,
      typename _Container, typename _Alloc
    >
    inline bool operator<=(
      const white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _x,
      const white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _y
    )
    { return !(_y < _x);}
    template<
      typename _Key, typename _Value, typename _Compare,
      typename _Container, typename _Alloc
    >
    inline bool operator>=(
      const white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _x,
      const white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _y
    )
    { return !(_x < _y);}
  __utility_interspace_end(container)

  __utility_interspace_start(algorithm)
    template<
      typename _Key, typename _Value, typename _Compare,
      typename _Container, typename _Alloc,
      typename trait::type::miscellaneous::enable_if<
        trait::type::features::is_swappable<_Compare>::value,
      bool>::type = true
    >
    void swap(
      container::white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _X,
      container::white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _y
    ) noexcept(noexcept(_X.swap(_y)))
    {
      _X.swap(_y);
    }
    template<
      typename _Key, typename _Value, typename _Compare,
      typename _Container, typename _Alloc,
      typename trait::type::miscellaneous::enable_if<
        trait::type::features::is_possible_swappable<_Compare>::value &&
        trait::type::features::is_possible_swappable<_Alloc>::value,
      bool>::type = true
    >
    void possible_swap(
      container::white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _X,
      container::white_black_tree<_Key, _Value, _Compare, _Container, _Alloc>& _y
    ) noexcept(noexcept(_X.possible_swap(_y)))
    {
      _X.possible_swap(_y);
    }
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)


#endif // ! __UTILITY_CONTAINER_WHITE_BLACK_TREE__

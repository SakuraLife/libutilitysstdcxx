
#ifndef __UTILITY_CONTAINER_HELPER_NODE__
#define __UTILITY_CONTAINER_HELPER_NODE__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(container)
    __utility_interspace_start(_helper)
      struct __single_tag
      { };
      struct __double_tag
      { };
      struct __tree_tag
      { };

      struct __dnode
      {
        typedef __double_tag    __tag;
        typedef __dnode*        __link_type;

        __link_type             prev;
        __link_type             next;
      };

      struct __snode
      {
        typedef __single_tag    __tag;
        typedef __snode*        __link_type;

        __link_type             next;
      };

      struct __tree_node
      {
        typedef __tree_tag      __tag;
        typedef __tree_node*    __link_type;

        __link_type         head;
        __link_type         left;
        __link_type         right;
      };


      template<typename _T, typename _Base>
      struct __node: public _Base
      {
        typedef _T          __value_type;

        __value_type        value;
      };

      template<typename _T, typename = typename _T::__tag>
      struct __node_trait;

      template<typename _T>
      struct __node_trait<_T, __single_tag>
      {
        typedef _T          __node_type;
        typedef _T*         __link_type;
        typedef const _T*   __const_link_type;

        template<typename _U>
        UTILITY_ALWAYS_INLINE
        static _U* get(__link_type _link) noexcept
        { return reinterpret_cast<_U*>(_link);}

        UTILITY_ALWAYS_INLINE
        static __link_type minimum(__link_type _link) noexcept
        { return _link;}
        UTILITY_ALWAYS_INLINE
        static __link_type maximum(__link_type _link) noexcept
        {
          for(; _link->next;)
          { _link = _link->next;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __link_type next(__link_type _link) noexcept
        { return _link->next;}
        UTILITY_ALWAYS_INLINE
        static __link_type prev(__link_type _link) noexcept
        { return nullptr;}
        UTILITY_ALWAYS_INLINE
        static __const_link_type minimum(__const_link_type _link) noexcept
        { return _link;}
        UTILITY_ALWAYS_INLINE
        static __const_link_type maximum(__const_link_type _link) noexcept
        {
          for(; _link->next;)
          { _link = _link->next;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __const_link_type next(__const_link_type _link) noexcept
        { return _link->next;}
        UTILITY_ALWAYS_INLINE
        static __const_link_type prev(__const_link_type _link) noexcept
        { return nullptr;}
      };

      template<typename _T>
      struct __node_trait<_T, __double_tag>
      {
        typedef _T          __node_type;
        typedef _T*         __link_type;
        typedef const _T*   __const_link_type;

        template<typename _U>
        UTILITY_ALWAYS_INLINE
        static _U* get(__link_type _link) noexcept
        { return reinterpret_cast<_U*>(_link);}

        UTILITY_ALWAYS_INLINE
        static __link_type minimum(__link_type _link) noexcept
        {
          for(; _link->prev;)
          { _link = _link->prev;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __link_type maximum(__link_type _link) noexcept
        {
          for(; _link->next;)
          { _link = _link->next;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __link_type next(__link_type _link) noexcept
        { return _link->next;}
        UTILITY_ALWAYS_INLINE
        static __link_type prev(__link_type _link) noexcept
        { return _link->prev;}
        UTILITY_ALWAYS_INLINE
        static __const_link_type minimum(__const_link_type _link) noexcept
        {
          for(; _link->prev;)
          { _link = _link->prev;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __const_link_type maximum(__const_link_type _link) noexcept
        {
          for(; _link->next;)
          { _link = _link->next;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __const_link_type next(__const_link_type _link) noexcept
        { return _link->next;}
        UTILITY_ALWAYS_INLINE
        static __const_link_type prev(__const_link_type _link) noexcept
        { return _link->prev;}
      };

      template<typename _T>
      struct __node_trait<_T, __tree_tag>
      {
        typedef _T          __node_type;
        typedef _T*         __link_type;
        typedef const _T*   __const_link_type;

        template<typename _U>
        UTILITY_ALWAYS_INLINE
        static _U* get(__link_type _link) noexcept
        { return reinterpret_cast<_U*>(_link);}

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
          for(; _link == _link->head->right;)
          { _link = _link->head;}
          if(_link->right != _link->head)
          { _link = _link->head;}
          return _link;
        }
        UTILITY_ALWAYS_INLINE
        static __link_type prev(__link_type _link) noexcept
        {
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
          if(_link->left)
          { return maximum(_link->left);}
          for(; _link == _link->head->left;)
          { _link = _link->head;}
          return _link->head;
        }
      };
    __utility_interspace_end(_helper)
  __utility_interspace_end(container)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CONTAINER_HELPER_NODE__

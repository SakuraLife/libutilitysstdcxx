
#ifndef __UTILITY_CONTAINER_HELPER_NODE_POOL__
#define __UTILITY_CONTAINER_HELPER_NODE_POOL__

#include<utility/config/utility_config.hpp>

#include<utility/container/helper/node.hpp>
#include<utility/container/compressed_pair.hpp>

#include<utility/memory/allocator_traits.hpp>
#include<utility/memory/allocator.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(container)
  {
     __utility_interspace_start(_helper)
    {
      template<typename _Node>
      class __node_pool
      {
        private:
          union __link
          {
            __link* next;
            char _no_name[sizeof(_Node)];
          };

        public:
          typedef _Node*                      return_type;
          typedef __link*                     link_type;
          typedef __link                      node_type;
          typedef size_t                      size_type;

        __utility_extra:
          __link*       base;

        public:
          __node_pool() noexcept: base{}
          { }
          __node_pool(const __node_pool&) noexcept: base{}
          { }
          __node_pool(__node_pool&& _other) noexcept:
            base{_other.base}
          { _other.base = nullptr;}

          ~__node_pool()
          {
            give_up();
          }

        public:
          inline return_type pop() noexcept
          {
            if(base)
            {
              link_type __tmp = base;
              base = base->next;
              return reinterpret_cast<return_type>(__tmp);
            }
            return nullptr;
          }
          void push(return_type _link) noexcept
          {
            link_type __tmp = reinterpret_cast<link_type>(_link);
            __tmp->next = base;
            base = __tmp;
          }
          void merge(__node_pool& _other) noexcept
          {
            for(; _other.base;)
            {
              link_type __extract = _other.base;
              _other.base = _other.base->next;
              __extract->next = base;
              base = __extract;
            }

            return;
          }
          void give_up() noexcept
          {
            using memory::default_deallocate;
            if(base != nullptr)
            {
              for(link_type __next = base->next; base; base = __next)
              {
                __next = base->next;
                default_deallocate(reinterpret_cast<return_type>(base));
              }
            }
          }
      };

    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CONTAINER_HELPER_NODE_POOL__

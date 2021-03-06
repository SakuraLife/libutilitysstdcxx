
#ifndef __UTILITY_MEMORY_DESTROY_N__
#define __UTILITY_MEMORY_DESTROY_N__

#include<utility/config/utility_config.hpp>
#include<utility/memory/addressof.hpp>
#include<utility/memory/destroy_at.hpp>
#include<utility/trait/type/features/is_trivially_destructible.hpp>
#include<utility/trait/type/type_trait_special.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(memory)
    namespace __detail
    {
      using trait::type::features::is_trivially_destructible;
      using trait::type::special::declval;

      template<
        typename _ForwardIterator,
        bool = is_trivially_destructible<
          decltype(*declval<_ForwardIterator>())
        >::value
      >
      struct __destroy_n
      {
        template<typename _Size>
        static inline void __aux(_ForwardIterator __first, _Size __length)
        {
          for(; __length > 0; --__length, ++__first)
          {
            memory::destroy_at(
              memory::addressof(*__first)
            );
          }
        }
      };
      template<typename _ForwardIterator>
      struct __destroy_n<_ForwardIterator, true>
      {
        template<typename _Size>
        static inline void __aux(_ForwardIterator __first, _Size __length)
        { }
      };
    }
    template<typename _ForwardIterator, typename _Size>
    void destroy_n(_ForwardIterator __first, _Size __length)
    { __detail::__destroy_n<_ForwardIterator>::__aux(__first, __length);}
  __utility_interspace_end(memory)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MEMORY_DESTROY_N__

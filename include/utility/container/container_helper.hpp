
#ifndef __UTILITY_CONTAINER_CONTAINER_HELPER__
#define __UTILITY_CONTAINER_CONTAINER_HELPER__

/**
 * \file container_helper.hpp
 * \author Inochi Amaoto
 *
 */

#include<utility/config/utility_config.hpp>

#include<utility/container/initializer_list.hpp>

#include<utility/memory/allocator_helper.hpp>

#include<utility/iterator/iterator_traits.hpp>
#include<utility/iterator/reverse_iterator.hpp>
#include<utility/iterator/move_iterator.hpp>
#include<utility/iterator/iterator_tag.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(container)
    namespace helper
    {
      struct __UTILITY_TYPE_VIS __success
      { };
      struct __UTILITY_TYPE_VIS __failure
      { };
      using namespace iterator;
    }
    using iterator::is_iterator;
    using iterator::is_vaild_iterator;
    using memory::allocator_arg_t;
    using memory::allocator_arg;

  __utility_interspace_end(container)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_CONTAINER_CONTAINER_HELPER__

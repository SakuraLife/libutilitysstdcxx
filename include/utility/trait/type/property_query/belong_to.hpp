
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_BELONG_TO__
#define __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_BELONG_TO__

#include<utility/trait/trait_helper.hpp>
#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(property_query)
        // belong_to
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS belong_to
        { };
        template<typename _T, class _Inn>
        struct __UTILITY_TEMPLATE_VIS belong_to<_T _Inn::*>
        { typedef _Inn type;};

      __utility_interspace_end(property_query)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)


#endif // __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_BELONG_TO__

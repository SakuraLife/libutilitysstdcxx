
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_ALIGNMENT_OF__
#define __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_ALIGNMENT_OF__

#include<utility/trait/trait_helper.hpp>
#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(property_query)
      {
        // alignment_of
        template<typename _T>
        struct alignment_of :
          public integral_constant<size_t, __utility_alignof(_T)>
        { };

      }
    }
  }
__utility_globalspace_end(utility)


#endif // __UTILITY_TRAIT_TYPE_PROPERTY_QUERY_ALIGNMENT_OF__

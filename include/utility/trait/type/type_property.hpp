
#ifndef __UTILITY_TRAIT_TYPE_PROPERTY__
#define __UTILITY_TRAIT_TYPE_PROPERTY__

#include<utility/trait/type/property/is_abstract.hpp>
#include<utility/trait/type/property/is_const.hpp>
#include<utility/trait/type/property/is_cv.hpp>
#include<utility/trait/type/property/is_empty.hpp>
#include<utility/trait/type/property/is_final.hpp>
#include<utility/trait/type/property/is_literal_type.hpp>
#include<utility/trait/type/property/is_pod.hpp>
#include<utility/trait/type/property/is_polymorphic.hpp>
#include<utility/trait/type/property/is_signed.hpp>
#include<utility/trait/type/property/is_standard_layout.hpp>
#include<utility/trait/type/property/is_trivial.hpp>
#include<utility/trait/type/property/is_trivially_copyable.hpp>
#include<utility/trait/type/property/is_unsigned.hpp>
#include<utility/trait/type/property/is_volatile.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(property)
      {

        // has_unique_object_representations(C++17)
        template<typename _T>
        struct has_unique_object_representations;

        // is_aggregate(C++17)
        template<typename _T>
        struct is_aggregate;

      }
    }
  }
__utility_globalspace_end(utility)

#endif // ! __UTILITY_TRAIT_TYPE_PROPERTY__


#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_DECAY__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_DECAY__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/categories/is_array.hpp>
#include<utility/trait/type/categories/is_function.hpp>
#include<utility/trait/type/transform/remove_reference.hpp>
#include<utility/trait/type/transform/remove_extent.hpp>
#include<utility/trait/type/transform/remove_cv.hpp>
#include<utility/trait/type/transform/add_pointer.hpp>
#include<utility/trait/type/miscellaneous/conditional.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(transform)
        // decay
        template<typename _T>
        struct decay
        {
          private:
            typedef typename
              trait::type::transform::remove_reference
              < _T>::type _type;

          public:
            typedef typename trait::type::miscellaneous::conditional<
              trait::type::categories::is_array<_type>::value,
              remove_extent_t<_type>*,
              typename
              trait::type::miscellaneous::conditional<
                trait::type::categories::is_function<_type>::value,
                add_pointer_t<_type>,
                remove_cv_t<_type>
              >::type
            >::type type;
        };

        template<typename _T>
        using decay_t = typename decay<_T>::type;

      __utility_interspace_end(transform)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_DECAY__


#ifndef __UTILITY_TRAIT_TYPE_FEATURES_IS_NOTHROW_COPY_CONSTRUCTIBLE__
#define __UTILITY_TRAIT_TYPE_FEATURES_IS_NOTHROW_COPY_CONSTRUCTIBLE__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/type/transform/add_reference.hpp>
#include<utility/trait/type/transform/add_cv.hpp>
#include<utility/trait/type/features/is_nothrow_constructible.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // is_nothrow_copy_constructible
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS is_nothrow_copy_constructible: public is_nothrow_constructible<
            _T,
            trait::type::transform::add_lvalue_reference_t<
              trait::type::transform::add_const_t<_T>
            >
          >
        { };

      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_FEATURES_IS_NOTHROW_COPY_CONSTRUCTIBLE__

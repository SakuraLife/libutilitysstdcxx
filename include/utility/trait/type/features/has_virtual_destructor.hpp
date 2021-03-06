
#ifndef __UTILITY_TRAIT_TYPE_FEATURES_HAS_VIRTUAL_DESTRUCTOR__
#define __UTILITY_TRAIT_TYPE_FEATURES_HAS_VIRTUAL_DESTRUCTOR__

#include<utility/trait/trait_helper.hpp>
#include<utility/trait/config/trait_config.hpp>

#if __utility_has_has_virtual_destructor

# include<utility/trait/config/trait_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // has_virtual_destructor
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS has_virtual_destructor :
          public integral_constant<bool,
            __utility_has_virtual_destructor(_T)>
        { };

      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#else // __utility_has_has_virtual_destructor

__utility_globalspace_start(utility)
  __utility_interspace_start(trait)
    __utility_interspace_start(type)
      __utility_interspace_start(features)
        // has_virtual_destructor
        /*!
        * \todo
        */
        template<typename _T>
        struct __UTILITY_TEMPLATE_VIS has_virtual_destructor: public unsupport_trait<false>
        { };

      __utility_interspace_end(features)
    __utility_interspace_end(type)
  __utility_interspace_end(trait)
__utility_globalspace_end(utility)

#endif // ! __utility_has_has_virtual_destructor

#include<utility/trait/config/trait_undef.hpp>

#endif // __UTILITY_TRAIT_TYPE_FEATURES_HAS_VIRTUAL_DESTRUCTOR__


#ifndef __UTILITY_ITERATOR_ITERATOR_TAG__
#define __UTILITY_ITERATOR_ITERATOR_TAG__

#include<utility/config/utility_config.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(iterator)
    struct __UTILITY_TYPE_VIS input_iterator_tag
    { };
    struct __UTILITY_TYPE_VIS output_iterator_tag
    { };
    struct __UTILITY_TYPE_VIS forward_iterator_tag : public input_iterator_tag
    { };
    struct __UTILITY_TYPE_VIS bidirectional_iterator_tag : public forward_iterator_tag
    { };
    struct __UTILITY_TYPE_VIS random_access_iterator_tag : public bidirectional_iterator_tag
    { };
    struct __UTILITY_TYPE_VIS contiguous_iterator_tag : public random_access_iterator_tag
    { };

  __utility_interspace_end(iterator)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_ITERATOR_ITERATOR_TAG__

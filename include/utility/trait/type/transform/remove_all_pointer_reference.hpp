
#ifndef __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_ALL_POINTER_REFERENCE__
#define __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_ALL_POINTER_REFERENCE__

#include<utility/trait/trait_helper.hpp>

__utility_globalspace_start(utility)
   __utility_interspace_start(trait)
  {
     __utility_interspace_start(type)
    {
       __utility_interspace_start(transform)
      {
        // remove_all_pointer_reference
        template<typename _T>
        struct remove_all_pointer_reference
        { typedef _T type;};
        template<typename _T>
        struct remove_all_pointer_reference<_T&>
        { typedef typename remove_all_pointer_reference<_T>::type type;};
        template<typename _T>
        struct remove_all_pointer_reference<_T&&>
        { typedef typename remove_all_pointer_reference<_T>::type type;};
        template<typename _T>
        struct remove_all_pointer_reference<_T*>
        { typedef typename remove_all_pointer_reference<_T>::type type;};
        template<typename _T>
        struct remove_all_pointer_reference<_T* const>
        { typedef typename remove_all_pointer_reference<_T>::type type;};
        template<typename _T>
        struct remove_all_pointer_reference<_T* volatile>
        { typedef typename remove_all_pointer_reference<_T>::type type;};
        template<typename _T>
        struct remove_all_pointer_reference<_T* const volatile>
        { typedef typename remove_all_pointer_reference<_T>::type type;};

        template<typename _T>
        using remove_all_ptr_ref = remove_all_pointer_reference<_T>;
        template<typename _T>
        using remove_all_ptr_ref_t =
          typename remove_all_pointer_reference<_T>::type;
        template<typename _T>
        using remove_all_pointer_reference_t =
          typename remove_all_pointer_reference<_T>::type;

      }
    }
  }
__utility_globalspace_end(utility)

#endif // __UTILITY_TRAIT_TYPE_TRANSFORM_REMOVE_ALL_POINTER_REFERENCE__

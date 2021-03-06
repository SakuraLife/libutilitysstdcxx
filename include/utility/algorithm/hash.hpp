
#ifndef __UTILITY_ALGORITHM_HASH__
#define __UTILITY_ALGORITHM_HASH__

#include<utility/config/utility_config.hpp>
#include<utility/trait/type/categories/is_enum.hpp>
#include<utility/trait/type/miscellaneous/underlying_type.hpp>
#include<utility/trait/config/trait_config.hpp>

#include<utility/algorithm/hash_detail/fnv_hash_1.hpp>
#include<utility/algorithm/hash_detail/fnv_hash_1a.hpp>
#include<utility/algorithm/hash_detail/murmur_hash_2.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(algorithm)

    template<typename _T>
    struct __UTILITY_TEMPLATE_VIS hash;

    namespace hash_detail
    {
      template<typename _T,
        bool = trait::type::categories::is_enum<_T>::value && __utility_has_underlying_type>
      struct enum_hash
      {
        // static_assert(false, "enum_hash does not support.");
      };
      template<typename _T>
      struct enum_hash<_T, true>
      {
        inline size_t operator()(_T __v) const noexcept
        {
          typedef typename
            trait::type::miscellaneous::underlying_type<_T>::type
            __under;
          return algorithm::hash<__under>{}(static_cast<__under>(__v));
        }
      };

    }

    template<>
    struct __UTILITY_TYPE_VIS hash<bool>
    {
      inline size_t operator()(bool __v)const noexcept
      { return static_cast<size_t>(__v);}
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<char>
    {
      inline size_t operator()(char __v) const noexcept
      { return static_cast<size_t>(__v);}
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<signed char>
    {
      inline size_t operator()(signed char __v) const noexcept
      { return static_cast<size_t>(__v);}
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<unsigned char>
    {
      inline size_t operator()(unsigned char __v) const noexcept
      { return static_cast<size_t>(__v);}
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<signed short>
    {
      inline size_t operator()(signed short __v) const noexcept
      { return static_cast<size_t>(__v);}
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<unsigned short>
    {
      inline size_t operator()(unsigned short __v) const noexcept
      { return static_cast<size_t>(__v);}
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<signed int>
    {
      inline size_t operator()(signed int __v) const noexcept
      { return static_cast<size_t>(__v);}
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<unsigned int>
    {
      inline size_t operator()(unsigned int __v) const noexcept
      { return static_cast<size_t>(__v);}
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<signed long>
    {
      inline size_t operator()(signed long __v) const noexcept
      { return static_cast<size_t>(__v);}
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<unsigned long>
    {
      inline size_t operator()(unsigned long __v) const noexcept
      { return static_cast<size_t>(__v);}
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<signed long long>
    {
      inline size_t operator()(signed long long __v) const noexcept
      { return static_cast<size_t>(__v);}
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<unsigned long long>
    {
      inline size_t operator()(unsigned long long __v) const noexcept
      { return static_cast<size_t>(__v);}
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<float>
    {
      inline size_t operator()(float __v) const noexcept
      {
         return __v == 0.0f ? 0 :
          algorithm::hash_detail::fnv_hash_1a<>::__aux(
            &__v, sizeof(__v)
          );
      }
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<double>
    {
      inline size_t operator()(double __v) const noexcept
      {
        return __v == 0.0f ? 0 :
          algorithm::hash_detail::fnv_hash_1a<>::__aux(
            &__v, sizeof(__v)
          );
      }
    };
    template<>
    struct __UTILITY_TYPE_VIS hash<long double>
    {
      inline size_t operator()(long double __v) const noexcept
      {
        return __v == 0.0f ? 0 :
          algorithm::hash_detail::fnv_hash_1a<>::__aux(
            &__v, sizeof(__v)
          );
      }
    };
    template<typename _T>
    struct __UTILITY_TEMPLATE_VIS hash<_T*>
    {
      inline size_t operator()(_T* __v) const noexcept
      { return reinterpret_cast<size_t>(__v);}
    };
  __utility_interspace_end(algorithm)
__utility_globalspace_end(utility)

#include<utility/trait/config/trait_undef.hpp>

#endif // ! __UTILITY_ALGORITHM_HASH__

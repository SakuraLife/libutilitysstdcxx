
#ifndef __UTILITY_MATH_INTERNAL__COUNT__
#define __UTILITY_MATH_INTERNAL__COUNT__

#include<utility/config/utility_config.hpp>
#include<utility/math/math_helper.hpp>

__utility_globalspace_start(utility)
  __utility_interspace_start(math)
    namespace internal
    {
      struct ___func_count;

      template<>
      struct storage<___func_count>
      {
        constexpr static unsigned int counts[256] =
        {
          0,  1,  1,  2,  1,  2,  2,  3,  1,  2,  2,  3,  2,  3,  3,  4,
          1,  2,  2,  3,  2,  3,  3,  4,  2,  3,  3,  4,  3,  4,  4,  5,
          1,  2,  2,  3,  2,  3,  3,  4,  2,  3,  3,  4,  3,  4,  4,  5,
          2,  3,  3,  4,  3,  4,  4,  5,  3,  4,  4,  5,  4,  5,  5,  6,
          1,  2,  2,  3,  2,  3,  3,  4,  2,  3,  3,  4,  3,  4,  4,  5,
          2,  3,  3,  4,  3,  4,  4,  5,  3,  4,  4,  5,  4,  5,  5,  6,
          2,  3,  3,  4,  3,  4,  4,  5,  3,  4,  4,  5,  4,  5,  5,  6,
          3,  4,  4,  5,  4,  5,  5,  6,  4,  5,  5,  6,  5,  6,  6,  7,
          1,  2,  2,  3,  2,  3,  3,  4,  2,  3,  3,  4,  3,  4,  4,  5,
          2,  3,  3,  4,  3,  4,  4,  5,  3,  4,  4,  5,  4,  5,  5,  6,
          2,  3,  3,  4,  3,  4,  4,  5,  3,  4,  4,  5,  4,  5,  5,  6,
          3,  4,  4,  5,  4,  5,  5,  6,  4,  5,  5,  6,  5,  6,  6,  7,
          2,  3,  3,  4,  3,  4,  4,  5,  3,  4,  4,  5,  4,  5,  5,  6,
          3,  4,  4,  5,  4,  5,  5,  6,  4,  5,  5,  6,  5,  6,  6,  7,
          3,  4,  4,  5,  4,  5,  5,  6,  4,  5,  5,  6,  5,  6,  6,  7,
          4,  5,  5,  6,  5,  6,  6,  7,  5,  6,  6,  7,  6,  7,  7,  8
        };
      };

      template<unsigned long _Len>
      struct ___count;

      template<>
      struct ___count<8>
      {
        template<typename _T>
        UTILITY_ALWAYS_INLINE
        static inline unsigned int aux(_T _val) noexcept
        { return storage<___func_count>::counts[_val];}
      };

#define ___ut_count_shift(_type, _name, _len) \
  storage<___func_count>::counts[static_cast<_type>(_name >> _len) & 0xffU]
#define ___ut_count(_name) \
  storage<___func_count>::counts[_name & 0xffU]

      template<>
      struct ___count<16>
      {
        template<typename _T>
        UTILITY_ALWAYS_INLINE
        static inline unsigned int aux(_T _val) noexcept
        {
          return ___ut_count_shift(_T, _val, 8U) +
                 ___ut_count(_val);
        }
      };

      template<>
      struct ___count<32>
      {
        template<typename _T>
        UTILITY_ALWAYS_INLINE
        static inline unsigned int aux(_T _val) noexcept
        {
          return ___ut_count_shift(_T, _val, 24U) +
                 ___ut_count_shift(_T, _val, 16U) +
                 ___ut_count_shift(_T, _val, 8U) +
                 ___ut_count(_val);
        }
      };

      template<>
      struct ___count<64>
      {
        template<typename _T>
        UTILITY_ALWAYS_INLINE
        static inline unsigned int aux(_T _val) noexcept
        {
          return ___ut_count_shift(_T, _val, 56U) +
                 ___ut_count_shift(_T, _val, 48U) +
                 ___ut_count_shift(_T, _val, 40U) +
                 ___ut_count_shift(_T, _val, 32U) +
                 ___ut_count_shift(_T, _val, 24U) +
                 ___ut_count_shift(_T, _val, 16U) +
                 ___ut_count_shift(_T, _val, 8U) +
                 ___ut_count(_val);
        }
      };

      template<>
      struct ___count<128>
      {
        template<typename _T>
        UTILITY_ALWAYS_INLINE
        static inline unsigned int aux(_T _val) noexcept
        {
          return ___ut_count_shift(_T, _val, 120U) +
                 ___ut_count_shift(_T, _val, 112U) +
                 ___ut_count_shift(_T, _val, 104U) +
                 ___ut_count_shift(_T, _val, 96U) +
                 ___ut_count_shift(_T, _val, 88U) +
                 ___ut_count_shift(_T, _val, 80U) +
                 ___ut_count_shift(_T, _val, 72U) +
                 ___ut_count_shift(_T, _val, 64U) +
                 ___ut_count_shift(_T, _val, 56U) +
                 ___ut_count_shift(_T, _val, 48U) +
                 ___ut_count_shift(_T, _val, 40U) +
                 ___ut_count_shift(_T, _val, 32U) +
                 ___ut_count_shift(_T, _val, 24U) +
                 ___ut_count_shift(_T, _val, 16U) +
                 ___ut_count_shift(_T, _val, 8U) +
                 ___ut_count(_val);
        }
      };

      UTILITY_ALWAYS_INLINE
      inline unsigned int _count(unsigned char _val) noexcept
      { return ___count<_buc>::aux(_val);}
      UTILITY_ALWAYS_INLINE
      inline unsigned int _count(unsigned short _val) noexcept
      { return ___count<_bus>::aux(_val);}
      UTILITY_ALWAYS_INLINE
      inline unsigned int _count(unsigned int _val) noexcept
      { return ___count<_bui>::aux(_val);}
      UTILITY_ALWAYS_INLINE
      inline unsigned int _count(unsigned long _val) noexcept
      { return ___count<_bul>::aux(_val);}
      UTILITY_ALWAYS_INLINE
      inline unsigned int _count(unsigned long long _val) noexcept
      { return ___count<_bull>::aux(_val);}
    }
  __utility_interspace_end(math)
__utility_globalspace_end(utility)

#endif // ! __UTILITY_MATH_INTERNAL__COUNT__

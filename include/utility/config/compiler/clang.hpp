
#ifndef __UTILITY_CLANG_CONFIG__
#define __UTILITY_CLANG_CONFIG__

# define UTILITY_ALWAYS_INLINE __attribute__((always_inline))
# define __utility_alignof(type) __alignof__(type)

# define UTILITY_VISBLITY_HIDDEN __attribute__ ((__visibility__("hidden")))
# define UTILITY_VISBLITY __attribute__ ((__visibility__("default")))
# define UTILITY_TEMPLATE_VISBLITY __attribute__ ((__visibility__("default")))

#endif // ! __UTILITY_CLANG_CONFIG__

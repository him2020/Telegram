//
// Created by jinhui on 2022/6/16.
//

#pragma once

#include <type_traits>

namespace base {
    namespace assertion {
        void log(const char *message, const char *file, int line);
// Release build assertions.
        inline constexpr void noop() {
        }

        inline void fail(
                const char *message,
                const char *file,
                int line) {
            log(message, file, line);
//            // Crash with access violation and generate crash report.
//            volatile auto nullptr_value = (int*)nullptr;
//            *nullptr_value = 0;
//
//            // Silent the possible failure to comply noreturn warning.
//            std::abort();
        }

        constexpr const char* extract_basename(const char* path, size_t size) {
            while (size != 0 && path[size - 1] != '/' && path[size - 1] != '\\') {
                --size;
            }
            return path + size;
        }

    } // namespace assertion
} // namespace base

#if defined(__clang__) || defined(__GNUC__)
#define AssertUnlikelyHelper(x) __builtin_expect(!!(x), 0)
#else
#define AssertUnlikelyHelper(x) (!!(x))
#endif

#define AssertValidationCondition(condition, message, file, line)\
	((AssertUnlikelyHelper(!(condition)))\
		? ::base::assertion::fail(message, file, line)\
		: ::base::assertion::noop())

#define SOURCE_FILE_BASENAME (::base::assertion::extract_basename(\
	__FILE__,\
	sizeof(__FILE__)))

// Define our own versions of Expects() and Ensures().
// Let them crash with reports and logging.
#ifdef Expects
#undef Expects
#endif // Expects
#define Expects(condition) (AssertValidationCondition(\
	condition,\
	"\"" #condition "\"",\
	SOURCE_FILE_BASENAME,\
	__LINE__))

namespace std {
#ifdef __clang__
    template<class _Ty1, class _Ty2>
    inline constexpr bool is_same_v = __is_same(_Ty1, _Ty2);
#else // ^^^ Clang / not Clang vvv
    template <class, class>
    inline constexpr bool is_same_v = false; // determine whether arguments are the same type
    template <class _Ty>
    inline constexpr bool is_same_v<_Ty, _Ty> = true;
#endif // __clang__
} // namespace std

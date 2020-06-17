#ifndef _LIBS_UTILS_THREAD_DEFS_H
#define _LIBS_UTILS_THREAD_DEFS_H

#include <stdint.h>
#include <sys/types.h>

// ---------------------------------------------------------------------------
// C API

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
	typedef uint32_t android_thread_id_t;
#else
	typedef void* android_thread_id_t;
#endif

	typedef int (*android_thread_func_t)(void*);

#ifdef __cplusplus
} // extern "C"
#endif

// ---------------------------------------------------------------------------
// C++ API
#ifdef __cplusplus
namespace android {
	// ---------------------------------------------------------------------------

	typedef android_thread_id_t thread_id_t;
	typedef android_thread_func_t thread_func_t;

#if defined(__cplusplus)
	extern "C" {
#endif

		enum {
			ANDROID_PRIORITY_LOWEST         =  19,
			ANDROID_PRIORITY_BACKGROUND     =  10,
			ANDROID_PRIORITY_NORMAL         =   0,
			ANDROID_PRIORITY_FOREGROUND     =  -2,
			ANDROID_PRIORITY_DISPLAY        =  -4,
			ANDROID_PRIORITY_URGENT_DISPLAY =  -8,
			ANDROID_PRIORITY_VIDEO          = -10,
			ANDROID_PRIORITY_AUDIO          = -16,
			ANDROID_PRIORITY_URGENT_AUDIO   = -19,
			ANDROID_PRIORITY_HIGHEST        = -20,
			ANDROID_PRIORITY_DEFAULT        = ANDROID_PRIORITY_NORMAL,
			ANDROID_PRIORITY_MORE_FAVORABLE = -1,
			ANDROID_PRIORITY_LESS_FAVORABLE = +1,
		};
	}

	enum {
		PRIORITY_LOWEST         = ANDROID_PRIORITY_LOWEST,
		PRIORITY_BACKGROUND     = ANDROID_PRIORITY_BACKGROUND,
		PRIORITY_NORMAL         = ANDROID_PRIORITY_NORMAL,
		PRIORITY_FOREGROUND     = ANDROID_PRIORITY_FOREGROUND,
		PRIORITY_DISPLAY        = ANDROID_PRIORITY_DISPLAY,
		PRIORITY_URGENT_DISPLAY = ANDROID_PRIORITY_URGENT_DISPLAY,
		PRIORITY_AUDIO          = ANDROID_PRIORITY_AUDIO,
		PRIORITY_URGENT_AUDIO   = ANDROID_PRIORITY_URGENT_AUDIO,
		PRIORITY_HIGHEST        = ANDROID_PRIORITY_HIGHEST,
		PRIORITY_DEFAULT        = ANDROID_PRIORITY_DEFAULT,
		PRIORITY_MORE_FAVORABLE = ANDROID_PRIORITY_MORE_FAVORABLE,
		PRIORITY_LESS_FAVORABLE = ANDROID_PRIORITY_LESS_FAVORABLE,
	};

	// ---------------------------------------------------------------------------
}  // namespace android
#endif  // __cplusplus
// ---------------------------------------------------------------------------

#endif // _LIBS_UTILS_THREAD_DEFS_H

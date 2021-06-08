#ifndef			_XANADU_RUNTIME_THREAD_H_
#define			_XANADU_RUNTIME_THREAD_H_

#include <XanaduRuntime/Header.h>

#if defined(XANADU_SYSTEM_WINDOWS)
typedef			unsigned long						pthread_t;
#endif

namespace Xanadu
{
	// <summary>
	// 此函数返回线程标识符，该标识符用作调用线程的句柄。
	// </summary>
	// <returns>返回调用线程的线程标识符。</returns>
	XANADU_RUNTIME_EXPORT unsigned long XANADUAPI GetCurrentThreadId() noexcept;

	// <summary>
	// 此函数返回线程标识符，该标识符用作调用线程的句柄。
	// </summary>
	// <returns>返回调用线程的线程标识符。</returns>
	XANADU_RUNTIME_EXPORT pthread_t XANADUAPI gettid() noexcept;
};

#endif

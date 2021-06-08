#include <XanaduRuntime/Thread.h>


// 此函数返回线程标识符，该标识符用作调用线程的句柄。
XANADU_RUNTIME_EXPORT unsigned long XANADUAPI Xanadu::GetCurrentThreadId() noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return ::GetCurrentThreadId();
#else
	return (unsigned long)(Xanadu::gettid());
#endif
}

// 此函数返回线程标识符，该标识符用作调用线程的句柄。
XANADU_RUNTIME_EXPORT pthread_t XANADUAPI Xanadu::gettid() noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return (pthread_t)(Xanadu::GetCurrentThreadId());
#else
	return ::pthread_self();
#endif
}

#ifndef			_XANADU_CORE_THREAD_H_
#define			_XANADU_CORE_THREAD_H_

#include <XanaduCore/XanaduCoreHeader.h>

/// 线程声明
typedef void(XANADUAPI* _Thread_StartAddress)(void* _Param);

/// Thread
class XANADU_CORE_EXPORT XThread
{
public:
	XThread() noexcept;

	virtual ~XThread() noexcept;

public:
	/// 创建
	static HANDLE create(_Thread_StartAddress _Thread, void* _Param) noexcept;

	/// 等待
	static void wait(HANDLE _Handle) noexcept;

	/// 结束
	static void terminate(HANDLE _Handle) noexcept;
};

#endif /// _XANADU_CORE_THREAD_H_

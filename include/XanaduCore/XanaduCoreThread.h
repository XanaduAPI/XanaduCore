#ifndef			_XANADU_CORE_THREAD_H_
#define			_XANADU_CORE_THREAD_H_

#include <XanaduCore/XanaduCoreHeader.h>

/// 线程声明
typedef void(XANADUAPI* _Thread_StartAddress)(void* _Param);

/// Thread
class XANADU_CORE_EXPORT XThread
{
public:
	XThread() XANADU_NOTHROW;

	virtual ~XThread() XANADU_NOTHROW;

public:
	/// 创建
	static HANDLE Create(_Thread_StartAddress _Thread, void* _Param) XANADU_NOTHROW;

	/// 等待
	static void Wait(HANDLE _Handle) XANADU_NOTHROW;

	/// 结束
	static void Terminate(HANDLE _Handle) XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_THREAD_H_

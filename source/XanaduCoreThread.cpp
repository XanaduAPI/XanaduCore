#include <XanaduCore/XanaduCoreThread.h>
#include <XanaduCore/XanaduCoreMutex.h>

/// 线程结构
typedef struct _PlatformThreadRunning
{
	//线程地址
	_Thread_StartAddress		_Address;

	//线程数据
	void*				_Data;
}PlatformThreadRunning;

/// 线程函数(WINDOWS)
void Thread_Function_Windows(void* _Param)
{
	XANADU_CHECK_RETURN(_Param);

	auto		vRunning = (PlatformThreadRunning*)_Param;
	vRunning->_Address(vRunning->_Data);
	XANADU_DELETE_PTR(vRunning);
}

/// 线程函数(LINUX)
void* Thread_Function_Linux(void* _Param)
{
	Thread_Function_Windows(_Param);
	return _Param;
}

/// 线程函数(MACOS)
void* Thread_Function_Macos(void* _Param)
{
	Thread_Function_Windows(_Param);
	return _Param;
}

XThread::XThread() noexcept
{
}

XThread::~XThread() noexcept
{
}

/// 创建
HANDLE XThread::create(_Thread_StartAddress _Thread, void* _Param) noexcept
{
	XANADU_CHECK_RETURN(_Thread, nullptr);
	auto		vRunning = XANADU_NEW PlatformThreadRunning();
	XANADU_CHECK_RETURN(vRunning, nullptr);
	vRunning->_Address = _Thread;
	vRunning->_Data = _Param;

#ifdef XANADU_SYSTEM_WINDOWS
	auto		vHandle = (HANDLE)::_beginthread(Thread_Function_Windows, NULL, vRunning);
#endif /// XANADU_SYSTEM_WINDOWS
#ifdef XANADU_SYSTEM_LINUX
	pthread_t	vThreadID = NULL;
	if(::pthread_create(&vThreadID, nullptr, Thread_Function_Linux, vRunning) != 0)
	{
		XANADU_DELETE_PTR(vRunning);
		return nullptr;
	}
	auto		vHandle = (HANDLE)vThreadID;
#endif /// XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
	pthread_t	vThreadID = NULL;
	if(::pthread_create(&vThreadID, nullptr, Thread_Function_Macos, vRunning) != 0)
	{
		XANADU_DELETE_PTR(vRunning);
		return nullptr;
	}
	auto		vHandle = (HANDLE)vThreadID;
#endif /// XANADU_SYSTEM_MACOS
	return vHandle;
}

/// 等待
void XThread::wait(HANDLE _Handle) noexcept
{
#ifdef XANADU_SYSTEM_WINDOWS
	::WaitForSingleObject(_Handle, INFINITE);
#else
	void* vExitValue = nullptr;
	::pthread_join((pthread_t)_Handle, &vExitValue);
#endif /// XANADU_SYSTEM_WINDOWS
}

/// 结束
void XThread::terminate(HANDLE _Handle) noexcept
{
#ifdef XANADU_SYSTEM_WINDOWS
	::TerminateThread(_Handle, 4);
#else
	::pthread_cancel((pthread_t)_Handle);
#endif /// XANADU_SYSTEM_WINDOWS
}

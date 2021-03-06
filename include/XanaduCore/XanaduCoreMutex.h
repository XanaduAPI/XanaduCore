#ifndef			_XANADU_CORE_MUTEX_H_
#define			_XANADU_CORE_MUTEX_H_

#include <XanaduCore/XanaduCoreHeader.h>

// Xanadu Class Mutex
class XANADU_CORE_EXPORT XMutex
{
private:
	HANDLE				_data_mutex;

public:
	enum RecursionMode
	{
		Recursive,
		NonRecursive,
	};

public:
	explicit XMutex(RecursionMode _Mode = Recursive) noexcept;

	virtual ~XMutex() noexcept;

public:
	virtual void lock() noexcept;

	virtual void unlock() noexcept;
};



class XANADU_CORE_EXPORT XMutexAuto
{
private:
	XMutex&				_data_mutex;

public:
	explicit XMutexAuto(XMutex& _Mutex) noexcept;

	virtual ~XMutexAuto() noexcept;
};

#define				XANADU_MUTEX_AUTO(_Mutex)				XMutexAuto	_XanaduMutexAuto(_Mutex)

#endif // _XANADU_CORE_MUTEX_H_

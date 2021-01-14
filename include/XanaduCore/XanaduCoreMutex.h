//
// Created by Administrator on 2021/1/14.
//

#ifndef			_XANADU_CORE_MUTEX_H_
#define			_XANADU_CORE_MUTEX_H_

#include <XanaduCore/XanaduCoreHeader.h>

//Xanadu Class Mutex
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
	explicit XMutex(RecursionMode _Mode = Recursive) XANADU_NOTHROW;

	virtual ~XMutex() XANADU_NOTHROW;

public:
	virtual void Lock() XANADU_NOTHROW;

	virtual void Unlock() XANADU_NOTHROW;
};



class XANADU_CORE_EXPORT XMutexAuto
{
private:
	XMutex&				_data_mutex;

public:
	explicit XMutexAuto(XMutex& _Mutex) XANADU_NOTHROW;

	virtual ~XMutexAuto() XANADU_NOTHROW;
};

#define				XANADU_MUTEX_AUTO(_Mutex)				XMutexAuto	_XanaduMutexAuto(_Mutex)

#endif /// _XANADU_CORE_MUTEX_H_

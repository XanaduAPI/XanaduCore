﻿#ifndef			_XANADU_CORE_MUTEX_H_
#define			_XANADU_CORE_MUTEX_H_

#include <XanaduCore/XHeader.h>

///  <summary>
///  Implementation of cross platform XMutex
///  </summary>
class XANADU_CORE_EXPORT XMutex
{
public:
	// Types of XMutex
	enum RecursionMode
	{
		Recursive,
		NonRecursive,
	};

private:
	// Private data of XMutex
	HANDLE				_mutex_data;

	// Types of locks
	RecursionMode			_mutex_mode;

public:
	// constructor
	explicit XMutex(RecursionMode _Mode = Recursive) noexcept;

	// destructor
	virtual ~XMutex() noexcept;

public:
	// Gets the type of the lock
	virtual RecursionMode type() const noexcept;

public:
	// Lock
	virtual void lock() noexcept;

	// Unlock
	virtual void unlock() noexcept;
};

///  <summary>
///  A class that can release XMutex automatically
///  </summary>
class XANADU_CORE_EXPORT XMutexAuto
{
private:
	XMutex&				_data_mutex;

public:
	// constructor
	explicit XMutexAuto(XMutex& _Mutex) noexcept;

	// destructor
	virtual ~XMutexAuto() noexcept;
};

// Macro used to call auto destruct lock conveniently
#define				XANADU_MUTEX_AUTO(_Mutex)				XMutexAuto		_XanaduMutexAuto(_Mutex)

#endif

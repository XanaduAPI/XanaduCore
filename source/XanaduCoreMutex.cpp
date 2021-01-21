﻿//
// Created by Administrator on 2021/1/14.
//

#include <XanaduCore/XanaduCoreMutex.h>


XMutex::XMutex(RecursionMode _Mode) XANADU_NOTHROW
{
	XANADU_UNPARAMETER(_Mode);
#ifdef XANADU_SYSTEM_WINDOWS
	_data_mutex = XANADU_NEW CRITICAL_SECTION;
	XANADU_CHECK_RETURN(_data_mutex);
	InitializeCriticalSection(static_cast<CRITICAL_SECTION*>(_data_mutex));
#else
	_data_mutex = XANADU_NEW pthread_mutex_t;
	XANADU_CHECK_RETURN(_data_mutex);

	switch(_Mode)
	{
		case XMutex::Recursive:
			{
				pthread_mutexattr_t	vAttr;
				pthread_mutexattr_init(&vAttr);
				pthread_mutexattr_settype(&vAttr, PTHREAD_MUTEX_RECURSIVE);
				pthread_mutex_init(static_cast<pthread_mutex_t*>(_data_mutex), &vAttr);
			}
			break;
		case XMutex::NonRecursive:
			{
				pthread_mutex_init(static_cast<pthread_mutex_t*>(_data_mutex), nullptr);
			}
			break;
		default:
			break;
	}
#endif//XANADU_SYSTEM_WINDOWS
}

XMutex::~XMutex() XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_data_mutex);
#ifdef XANADU_SYSTEM_WINDOWS
	auto		vMutex = static_cast<CRITICAL_SECTION*>(_data_mutex);
	DeleteCriticalSection(vMutex);
	XANADU_DELETE_PTR(vMutex);
#else
	auto		vMutex = static_cast<pthread_mutex_t*>(_data_mutex);
	pthread_mutex_destroy(vMutex);
	XANADU_DELETE_PTR(vMutex);
#endif//XANADU_SYSTEM_WINDOWS
	_data_mutex = nullptr;
}

void XMutex::Lock() XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_data_mutex);
#ifdef XANADU_SYSTEM_WINDOWS
	EnterCriticalSection(static_cast<CRITICAL_SECTION*>(_data_mutex));
#else
	pthread_mutex_lock(static_cast<pthread_mutex_t*>(_data_mutex));
#endif//XANADU_SYSTEM_WINDOWS
}

void XMutex::Unlock() XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_data_mutex);
#ifdef XANADU_SYSTEM_WINDOWS
	LeaveCriticalSection(static_cast<CRITICAL_SECTION*>(_data_mutex));
#else
	pthread_mutex_unlock(static_cast<pthread_mutex_t*>(_data_mutex));
#endif//XANADU_SYSTEM_WINDOWS
}




XMutexAuto::XMutexAuto(XMutex& _Mutex) XANADU_NOTHROW : _data_mutex(_Mutex)
{
	_data_mutex.Lock();
}

XMutexAuto::~XMutexAuto() XANADU_NOTHROW
{
	_data_mutex.Unlock();
}
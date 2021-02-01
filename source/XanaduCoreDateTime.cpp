//
// Created by Administrator on 2021/1/14.
//

#include <XanaduCore/XanaduCoreDateTime.h>
#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>

typedef struct _XANADU_TIME_HIGH_PRECISION
{
#ifdef XANADU_SYSTEM_WINDOWS
	/// 开始时间
	LARGE_INTEGER		vBeginTime;

	/// 结束时间
	LARGE_INTEGER		vEndTime;

	/// CPU时间
	LARGE_INTEGER		vCpuTime;
#else
	/// 开始时间
	timeval			vBeginTime;

	/// 结束时间
	timeval			vEndTime;
#endif//XANADU_SYSTEM_WINDOWS
}XANADU_TIME_HIGH_PRECISION;



XDateTime::XDateTime() XANADU_NOTHROW
{
	_time_millisecond = XDateTime::CurrentMillisecond();
}

XDateTime::~XDateTime() XANADU_NOTHROW
{
}

/// UTC Second
int64U XDateTime::CurrentSecond() XANADU_NOTHROW
{
	return static_cast<int64U>(time(nullptr));
}

/// UTC Millisecond
int64U XDateTime::CurrentMillisecond() XANADU_NOTHROW
{
	struct timeb		vRawtime;
	ftime(&vRawtime);
	return vRawtime.time * 1000ULL + vRawtime.millitm;
}

/// Second To String (1970-01-01 08:00:00)
XString XDateTime::SecondToString(int64U _Second) XANADU_NOTHROW
{
	auto		vValueSecond = static_cast<time_t>(_Second);
	auto		vTM = Xanadu::localtime(&vValueSecond);
	return XString::Format(L"%04d-%02d-%02d %02d:%02d:%02d", vTM->tm_year + 1900, vTM->tm_mon + 1, vTM->tm_mday, vTM->tm_hour, vTM->tm_min, vTM->tm_sec);
}

/// Millisecond To String (1970-01-01 08:00:00.000)
XString XDateTime::MillisecondToString(int64U _Millisecond) XANADU_NOTHROW
{
	return SecondToString(_Millisecond / 1000) + L"." + XString::number(_Millisecond % 1000);
}

/// Current To String (1970-01-01 08:00:00.000)
XString XDateTime::CurrentToString() XANADU_NOTHROW
{
	wchar_t		vBuffer[XANADU_PATH] = { 0 };
#ifdef XANADU_SYSTEM_WINDOWS
	SYSTEMTIME		vSystemTime;
	GetSystemTime(&vSystemTime);
	swprintf(vBuffer, XANADU_PATH, L"%04d-%02d-%02dT%02d:%02d:%02d.%03dZ", vSystemTime.wYear, vSystemTime.wMonth, vSystemTime.wDay, vSystemTime.wHour, vSystemTime.wMinute, vSystemTime.wSecond, vSystemTime.wMilliseconds);
#else
	struct timespec		vTime;
	clock_gettime(CLOCK_REALTIME, &vTime);
	struct tm		vNowTime;
	localtime_r(&vTime.tv_sec, &vNowTime);
	swprintf(vBuffer, XANADU_PATH, L"%04d-%02d-%02dT%02d:%02d:%02d.%06dZ", vNowTime.tm_year + 1900, vNowTime.tm_mon + 1, vNowTime.tm_mday, vNowTime.tm_hour, vNowTime.tm_min, vNowTime.tm_sec, vTime.tv_nsec / 1000);
#endif//XANADU_SYSTEM_WINDOWS
	return vBuffer;
}

/// format
XDateTime XDateTime::FormSecond(int64U _Second) XANADU_NOTHROW
{
	return XDateTime::FormMillisecond(_Second * 1000);
}

/// format
XDateTime XDateTime::FormMillisecond(int64U _Millisecond) XANADU_NOTHROW
{
	auto		vTime = XDateTime();
	vTime._time_millisecond = _Millisecond;
	return vTime;
}


/// 高精度计时开始
HANDLE XDateTime::HighPrecisionStart() XANADU_NOTHROW
{
	auto		vHandle = XANADU_NEW XANADU_TIME_HIGH_PRECISION();
	if (vHandle)
	{
		Xanadu::memset(vHandle, 0, sizeof(XANADU_TIME_HIGH_PRECISION));
#ifdef XANADU_SYSTEM_WINDOWS
		QueryPerformanceFrequency(&vHandle->vCpuTime);
		QueryPerformanceCounter(&vHandle->vBeginTime);
#else
		gettimeofday(&vHandle->vBeginTime, NULL);
#endif//XANADU_SYSTEM_WINDOWS
	}
	return vHandle;
}

/// 高精度计时结束
int64U XDateTime::HighPrecisionStop(HANDLE _Handle) XANADU_NOTHROW
{
	auto		vDifference = static_cast<int64U>(0);
	auto		vHandle = static_cast<XANADU_TIME_HIGH_PRECISION*>(_Handle);
	if (vHandle)
	{
#ifdef XANADU_SYSTEM_WINDOWS
		QueryPerformanceCounter(&vHandle->vEndTime);

		double		dbCpuTime = (double)vHandle->vCpuTime.QuadPart;
		int64S		nTemp = vHandle->vEndTime.QuadPart - vHandle->vBeginTime.QuadPart;

		double		dbDifference = (double)nTemp;
		dbDifference *= 1000.0f;
		double		dbMillisecond = dbDifference / dbCpuTime;

		vDifference = (int64S)dbMillisecond;
#else
		gettimeofday(&vHandle->vEndTime, NULL);
		int64S		nDelayedSecond = vHandle->vEndTime.tv_sec - vHandle->vBeginTime.tv_sec;
		nDelayedSecond *= 1000000;
		int64S		nDelayedMillisecond = vHandle->vEndTime.tv_usec - vHandle->vBeginTime.tv_usec;
		vDifference += nDelayedSecond + nDelayedMillisecond;
#endif//XANADU_SYSTEM_WINDOWS
		XANADU_DELETE_PTR(vHandle);
	}
	return vDifference;
}

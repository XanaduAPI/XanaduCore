#include <XanaduCore/XTime.h>
#include <XanaduCore/XRuntime.h>


typedef struct _XANADU_TIME_HIGH_PRECISION
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	// 开始时间
	LARGE_INTEGER		vBeginTime;

	// 结束时间
	LARGE_INTEGER		vEndTime;

	// CPU时间
	LARGE_INTEGER		vCpuTime;
#else
	// 开始时间
	timeval			vBeginTime;

	// 结束时间
	timeval			vEndTime;
#endif
}XANADU_TIME_HIGH_PRECISION;


int64U currentMillisecondUTC()
{
	struct timeb		vRawtime;
	ftime(&vRawtime);
	return vRawtime.time * 1000ULL + vRawtime.millitm;
};


XTime::XTime() noexcept
{
	this->_time_millisecond = currentMillisecondUTC();
}

XTime::XTime(int32U _Hour, int32U _Minute, int32U _Second, int32U _Millisecond) noexcept
{
	this->_time_millisecond = _Hour * 3600ULL * 1000ULL;
	this->_time_millisecond += _Minute * 60ULL * 1000ULL;
	this->_time_millisecond += _Second * 1000ULL;
	this->_time_millisecond += _Millisecond;
}

XTime::XTime(const XTime& _Info) noexcept
{
	this->_time_millisecond = _Info._time_millisecond;
}

XTime::~XTime() noexcept
{
	this->_time_millisecond = 0ULL;
}





XTime& XTime::operator = (const XTime& _Other)
{
	this->_time_millisecond = _Other._time_millisecond;
	return *this;
}





// Gets the total number of seconds
int64U XTime::second() const noexcept
{
	return this->millisecond() / 1000ULL;
}

// Gets the total number of millisecond
int64U XTime::millisecond() const noexcept
{
	return this->_time_millisecond;
}





// Get the current time
XTime XTime::currentTime() noexcept
{
	return XTime::fromMillisecond(currentMillisecondUTC());
}

// Sets the time to the specified number of milliseconds
XTime XTime::fromMillisecond(int64U _Millisecond) noexcept
{
	auto		vTime = XTime();
	vTime._time_millisecond = _Millisecond;
	return vTime;
}





// 高精度计时开始
HANDLE XTime::HighPrecisionStart() noexcept
{
	auto		vHandle = XANADU_NEW XANADU_TIME_HIGH_PRECISION();
	if (vHandle)
	{
		Xanadu::memset(vHandle, 0, sizeof(XANADU_TIME_HIGH_PRECISION));
#if defined(_XANADU_SYSTEM_WINDOWS)
		QueryPerformanceFrequency(&vHandle->vCpuTime);
		QueryPerformanceCounter(&vHandle->vBeginTime);
#else
		gettimeofday(&vHandle->vBeginTime, NULL);
#endif
	}
	return vHandle;
}

// 高精度计时结束
int64U XTime::HighPrecisionStop(HANDLE _Handle) noexcept
{
	auto		vDifference = static_cast<int64U>(0);
	auto		vHandle = static_cast<XANADU_TIME_HIGH_PRECISION*>(_Handle);
	if (vHandle)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
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
#endif
		XANADU_DELETE_PTR(vHandle);
	}
	return vDifference;
}


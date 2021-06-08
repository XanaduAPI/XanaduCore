#ifndef			_XANADU_CORE_TIME_H_
#define			_XANADU_CORE_TIME_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XString.h>
#include <XanaduCore/XTimeZone.h>

#define				XANADU_TIME_MINUTE				(60)				// 一分的秒数
#define				XANADU_TIME_HOUR				(XANADU_TIME_MINUTE * 60)	// 一小时的秒数
#define				XANADU_TIME_DAY					(XANADU_TIME_HOUR * 24)		// 一天的秒数
#define				XANADU_TIME_YEAR				(XANADU_TIME_DAY * 365)		// 一年的秒数

// 时间操作
class XANADU_CORE_EXPORT XTime
{
private:
	// time : init is current
	int64U					_time_millisecond;

public:
	XTime() noexcept;

	XTime(int32U _Hour, int32U _Minute, int32U _Second = 0U, int32U _Millisecond = 0U) noexcept;

	XTime(const XTime& _Info) noexcept;

	virtual ~XTime() noexcept;

public:
	virtual XTime& operator = (const XTime& _Other);

public:
	// Gets the total number of seconds
	virtual int64U second() const noexcept;

	// Gets the total number of millisecond
	virtual int64U millisecond() const noexcept;

public:
	// Get the current time
	static XTime currentTime() noexcept;

	// Sets the time to the specified number of milliseconds
	static XTime fromMillisecond(int64U _Millisecond) noexcept;

public:
	// 高精度计时开始
	static HANDLE HighPrecisionStart() noexcept;

	// 高精度计时结束
	static int64U HighPrecisionStop(HANDLE _Handle) noexcept;
};

#endif // _XANADU_CORE_TIME_H_

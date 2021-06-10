#ifndef			_XANADU_CORE_DATETIME_H_
#define			_XANADU_CORE_DATETIME_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XTime.h>
#include <XanaduCore/XTimeZone.h>

// 日期时间操作
class XANADU_CORE_EXPORT XDateTime
{
private:
	XTime						_info_datetime;

public:
	XDateTime() noexcept;

	XDateTime(const XDateTime& _Info) noexcept;

	virtual ~XDateTime() noexcept;

public:
	virtual XDateTime& operator = (const XDateTime& _Other);

public:
	static XDateTime currentDateTime(const XTimeZone& _TimeZone = XTimeZone::UTC) noexcept;

	static int64U currentMillisecond(const XTimeZone& _TimeZone = XTimeZone::UTC) noexcept;

	static int64U currentSecond(const XTimeZone& _TimeZone = XTimeZone::UTC) noexcept;

	static XDateTime fromMillisecond(int64U _Millisecond, const XTimeZone& _TimeZone = XTimeZone::UTC) noexcept;

	static XDateTime fromSecond(int64U _Second, const XTimeZone& _TimeZone = XTimeZone::UTC) noexcept;

public:
	static XDateTime currentDateTimeUtc() noexcept;

	static int64U currentMillisecondSinceUtc() noexcept;

	static int64U currentSecondSinceUtc() noexcept;

	static XDateTime fromMillisecondSinceUtc(int64U _Millisecond) noexcept;

	static XDateTime fromSecondSinceUtc(int64U _Second) noexcept;

public:
	// Second To String (1970-01-01 08:00:00)
	static XString secondToString(int64U _Second) noexcept;

	// Millisecond To String (1970-01-01 08:00:00.000)
	static XString millisecondToString(int64U _Millisecond) noexcept;

	// Current To String (1970-01-01 08:00:00.000)
	static XString currentMillisecondToString() noexcept;
};

#endif

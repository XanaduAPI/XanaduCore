﻿#ifndef			_XANADU_CORE_DATETIME_H_
#define			_XANADU_CORE_DATETIME_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>

#define				XANADU_TIME_MINUTE				(60)				/// 一分的秒数
#define				XANADU_TIME_HOUR				(XANADU_TIME_MINUTE * 60)	/// 一小时的秒数
#define				XANADU_TIME_DAY					(XANADU_TIME_HOUR * 24)		/// 一天的秒数
#define				XANADU_TIME_YEAR				(XANADU_TIME_DAY * 365)		/// 一年的秒数

/// 时间操作
class XANADU_CORE_EXPORT XDateTime
{
private:
	/// time : init is current
	int64U					_time_millisecond;

public:
	XDateTime() XANADU_NOTHROW;

	virtual ~XDateTime() XANADU_NOTHROW;

public:
	/// UTC Second
	static int64U CurrentSecond() XANADU_NOTHROW;

	/// UTC Millisecond
	static int64U CurrentMillisecond() XANADU_NOTHROW;

public:
	/// Second To String (1970-01-01 08:00:00)
	static XString SecondToString(int64U _Second) XANADU_NOTHROW;

	/// Millisecond To String (1970-01-01 08:00:00.000)
	static XString MillisecondToString(int64U _Millisecond) XANADU_NOTHROW;

	/// Current To String (1970-01-01 08:00:00.000)
	static XString CurrentToString() XANADU_NOTHROW;

public:
	/// format
	static XDateTime FormSecond(int64U _Second) XANADU_NOTHROW;

	/// format
	static XDateTime FormMillisecond(int64U _Millisecond) XANADU_NOTHROW;

public:
	/// 高精度计时开始
	static HANDLE HighPrecisionStart() XANADU_NOTHROW;

	/// 高精度计时结束
	static int64U HighPrecisionStop(HANDLE _Handle) XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_DATETIME_H_

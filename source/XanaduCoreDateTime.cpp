//
// Created by Administrator on 2021/1/14.
//

#include <XanaduCore/XanaduCoreDateTime.h>
#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>

XDateTime::XDateTime() noexcept
{
	this->_info_datetime = XTime::currentTime();
}

XDateTime::XDateTime(const XDateTime& _Info) noexcept
{
	this->_info_datetime = _Info._info_datetime;
}

XDateTime::~XDateTime() noexcept
{
}





XDateTime& XDateTime::operator = (const XDateTime& _Other)
{
	this->_info_datetime = _Other._info_datetime;
	return *this;
}






XDateTime XDateTime::currentDateTimeUtc() noexcept
{
	auto		vDateTime = XDateTime();
	vDateTime._info_datetime = XTime::currentTime();
	return vDateTime;
}

int64U XDateTime::currentMillisecondSinceUtc() noexcept
{
	return XTime::currentTime().millisecond();
}

int64U XDateTime::currentSecondSinceUtc() noexcept
{
	return XTime::currentTime().second();
}

XDateTime XDateTime::fromMillisecondSinceUtc(int64U _Millisecond) noexcept
{
	auto		vDateTime = XDateTime();
	vDateTime._info_datetime = XTime::fromMillisecond(_Millisecond);
	return vDateTime;
}

XDateTime XDateTime::fromSecondSinceUtc(int64U _Second) noexcept
{
	auto		vDateTime = XDateTime();
	vDateTime._info_datetime = XTime::fromMillisecond(_Second * 1000);
	return vDateTime;
}







// Second To String (1970-01-01 08:00:00)
XString XDateTime::secondToString(int64U _Second) noexcept
{
	auto		vValueSecond = static_cast<time_t>(_Second);
	auto		vTM = Xanadu::localtime(&vValueSecond);
	return XString::format(L"%04d-%02d-%02d %02d:%02d:%02d", vTM->tm_year + 1900, vTM->tm_mon + 1, vTM->tm_mday, vTM->tm_hour, vTM->tm_min, vTM->tm_sec);
}

// Millisecond To String (1970-01-01 08:00:00.000)
XString XDateTime::millisecondToString(int64U _Millisecond) noexcept
{
	return secondToString(_Millisecond / 1000) + L"." + XString::number(_Millisecond % 1000);
}

// Current To String (1970-01-01 08:00:00.000)
XString XDateTime::currentMillisecondToString() noexcept
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
#endif // XANADU_SYSTEM_WINDOWS
	return vBuffer;
}

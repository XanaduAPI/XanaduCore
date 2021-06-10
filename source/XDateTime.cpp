#include <XanaduCore/XDateTime.h>
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





XDateTime XDateTime::currentDateTime(const XTimeZone& _TimeZone) noexcept
{
	XANADU_UNPARAMETER(_TimeZone);

	auto		vDateTime = XDateTime();
	vDateTime._info_datetime = XTime::currentTime();
	return vDateTime;
}

int64U XDateTime::currentMillisecond(const XTimeZone& _TimeZone) noexcept
{
	XANADU_UNPARAMETER(_TimeZone);

	return XTime::currentTime().millisecond();
}

int64U XDateTime::currentSecond(const XTimeZone& _TimeZone) noexcept
{
	XANADU_UNPARAMETER(_TimeZone);

	return XTime::currentTime().second();
}

XDateTime XDateTime::fromMillisecond(int64U _Millisecond, const XTimeZone& _TimeZone) noexcept
{
	XANADU_UNPARAMETER(_TimeZone);

	auto		vDateTime = XDateTime();
	vDateTime._info_datetime = XTime::fromMillisecond(_Millisecond);
	return vDateTime;
}

XDateTime XDateTime::fromSecond(int64U _Second, const XTimeZone& _TimeZone) noexcept
{
	return XDateTime::fromMillisecond(_Second * 1000, _TimeZone);
}






XDateTime XDateTime::currentDateTimeUtc() noexcept
{
	return XDateTime::currentDateTime(XTimeZone::UTC);
}

int64U XDateTime::currentMillisecondSinceUtc() noexcept
{
	return XDateTime::currentMillisecond(XTimeZone::UTC);
}

int64U XDateTime::currentSecondSinceUtc() noexcept
{
	return XDateTime::currentSecond(XTimeZone::UTC);
}

XDateTime XDateTime::fromMillisecondSinceUtc(int64U _Millisecond) noexcept
{
	return XDateTime::fromMillisecond(_Millisecond, XTimeZone::UTC);
}

XDateTime XDateTime::fromSecondSinceUtc(int64U _Second) noexcept
{
	return XDateTime::fromSecond(_Second, XTimeZone::UTC);;
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
	return XDateTime::secondToString(_Millisecond / 1000) + L"." + XString::number(_Millisecond % 1000);
}

// Current To String (1970-01-01 08:00:00.000)
XString XDateTime::currentMillisecondToString() noexcept
{
	wchar_t		vBuffer[XANADU_PATH] = { 0 };
#if defined(_XANADU_SYSTEM_WINDOWS)
	SYSTEMTIME		vSystemTime;
	GetSystemTime(&vSystemTime);
	swprintf(vBuffer, XANADU_PATH, L"%04d-%02d-%02dT%02d:%02d:%02d.%03dZ", vSystemTime.wYear, vSystemTime.wMonth, vSystemTime.wDay, vSystemTime.wHour, vSystemTime.wMinute, vSystemTime.wSecond, vSystemTime.wMilliseconds);
#else
	struct timespec		vTime;
	clock_gettime(CLOCK_REALTIME, &vTime);
	struct tm		vNowTime;
	localtime_r(&vTime.tv_sec, &vNowTime);
	swprintf(vBuffer, XANADU_PATH, L"%04d-%02d-%02dT%02d:%02d:%02d.%06dZ", vNowTime.tm_year + 1900, vNowTime.tm_mon + 1, vNowTime.tm_mday, vNowTime.tm_hour, vNowTime.tm_min, vNowTime.tm_sec, vTime.tv_nsec / 1000);
#endif
	return vBuffer;
}

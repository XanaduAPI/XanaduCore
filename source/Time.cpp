#include <XanaduRuntime/Time.h>

XANADU_RUNTIME_EXPORT struct tm* XANADUAPI Xanadu::localtime(const time_t* _Time) noexcept
{
	XANADU_CHECK_RETURN(_Time, nullptr);

	return ::localtime(_Time);
}

XANADU_RUNTIME_EXPORT time_t XANADUAPI Xanadu::mktime(struct tm* _Tm) noexcept
{
	XANADU_CHECK_RETURN(_Tm, 0);

	return ::mktime(_Tm);
}

XANADU_RUNTIME_EXPORT time_t XANADUAPI Xanadu::time(time_t* _Time) noexcept
{
	XANADU_CHECK_RETURN(_Time, 0);

	return ::time(_Time);
}

XANADU_RUNTIME_EXPORT struct tm* XANADUAPI Xanadu::gmtime(const time_t* _Time) noexcept
{
	XANADU_CHECK_RETURN(_Time, nullptr);

	return ::gmtime(_Time);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::ctime(const time_t* _Time) noexcept
{
	XANADU_CHECK_RETURN(_Time, nullptr);

	return ::ctime(_Time);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::asctime(const struct tm* _Tm) noexcept
{
	XANADU_CHECK_RETURN(_Tm, nullptr);

	return ::asctime(_Tm);
}

XANADU_RUNTIME_EXPORT void XANADUAPI Xanadu::srand(unsigned int _Seed) noexcept
{
	::srand(_Seed);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::rand() noexcept
{
	return ::rand();
}

// 秒级延时
XANADU_RUNTIME_EXPORT unsigned int XANADUAPI Xanadu::sleep(unsigned int _Seconds) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return Xanadu::msleep(_Seconds * 1000);
#else
	return ::sleep(_Seconds);
#endif
}

// 毫秒级延时
XANADU_RUNTIME_EXPORT unsigned int XANADUAPI Xanadu::msleep(unsigned int _Milliseconds) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	//std::this_thread::sleep_for(std::chrono::milliseconds(_Milliseconds));
	::Sleep(_Milliseconds);
	return 0;
#else
	return ::usleep(_Milliseconds * 1000) / 1000;
#endif
}

// 微秒级延时
XANADU_RUNTIME_EXPORT unsigned int XANADUAPI Xanadu::usleep(unsigned int _Microseconds) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	LARGE_INTEGER	vInterval;
	vInterval.QuadPart = -(10 * static_cast<int64S>(_Microseconds));

	auto 		vTimer = CreateWaitableTimerA(nullptr, TRUE, nullptr);
	SetWaitableTimer(vTimer, &vInterval, 0, nullptr, nullptr, 0);
	WaitForSingleObject(vTimer, INFINITE);
	CloseHandle(vTimer);
	return 0;
#else
	return ::usleep(_Microseconds);
#endif
}

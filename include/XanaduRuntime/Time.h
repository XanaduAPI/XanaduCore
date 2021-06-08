#ifndef			_XANADU_RUNTIME_TIME_H_
#define			_XANADU_RUNTIME_TIME_H_

#include <XanaduRuntime/Header.h>

namespace Xanadu
{
	XANADU_RUNTIME_EXPORT struct tm* XANADUAPI localtime(const time_t* _Time) noexcept;

	XANADU_RUNTIME_EXPORT time_t XANADUAPI mktime(struct tm* _Tm) noexcept;

	XANADU_RUNTIME_EXPORT time_t XANADUAPI time(time_t* _Time) noexcept;

	XANADU_RUNTIME_EXPORT struct tm* XANADUAPI gmtime(const time_t* _Time) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI ctime(const time_t* _Time) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI asctime(const struct tm* _Tm) noexcept;

	XANADU_RUNTIME_EXPORT void XANADUAPI srand(unsigned int _Seed) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI rand() noexcept;

	// <summary>
	// 秒级延时
	// </summary>
	// <param name="_Seconds">以秒为单位的时间</param>
	// <returns>如果函数返回是因为请求的时间已过，则返回的值将为零。如果函数由于信号的传递而返回，则返回的值将是以秒为单位的值（请求的时间减去实际睡眠的时间）。</returns>
	XANADU_RUNTIME_EXPORT unsigned int XANADUAPI sleep(unsigned int _Seconds) noexcept;

	// <summary>
	// 毫秒级延时
	// </summary>
	// <param name="_Milliseconds">以毫秒为单位的时间</param>
	// <returns>如果函数返回是因为请求的时间已过，则返回的值将为零。如果函数由于信号的传递而返回，则返回的值将是以毫秒为单位的值（请求的时间减去实际睡眠的时间）。</returns>
	XANADU_RUNTIME_EXPORT unsigned int XANADUAPI msleep(unsigned int _Milliseconds) noexcept;

	// <summary>
	// 微秒级延时
	// </summary>
	// <param name="_Microseconds">以微秒为单位的时间</param>
	// <returns>如果函数返回是因为请求的时间已过，则返回的值将为零。如果函数由于信号的传递而返回，则返回的值将是以微秒为单位的值（请求的时间减去实际睡眠的时间）。</returns>
	XANADU_RUNTIME_EXPORT unsigned int XANADUAPI usleep(unsigned int _Microseconds) noexcept;
};

#endif

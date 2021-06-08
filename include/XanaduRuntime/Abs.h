#ifndef			_XANADU_RUNTIME_ABS_H_
#define			_XANADU_RUNTIME_ABS_H_

#include <XanaduRuntime/Header.h>

namespace Xanadu
{
	// <summary>
	// 计算绝对值
	// </summary>
	// <param name="_X">有符号的8位整型</param>
	// <returns>返回参数的绝对值</returns>
	XANADU_RUNTIME_EXPORT char XANADUAPI abs(char _X) noexcept;

	// <summary>
	// 计算绝对值
	// </summary>
	// <param name="_X">有符号的16位整型</param>
	// <returns>返回参数的绝对值</returns>
	XANADU_RUNTIME_EXPORT short XANADUAPI abs(short _X) noexcept;

	// <summary>
	// 计算绝对值
	// </summary>
	// <param name="_X">有符号的32位整型</param>
	// <returns>返回参数的绝对值</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI abs(int _X) noexcept;

	// <summary>
	// 计算绝对值
	// </summary>
	// <param name="_X">有符号的32 <= X <=64位整型</param>
	// <returns>返回参数的绝对值</returns>
	XANADU_RUNTIME_EXPORT long XANADUAPI abs(long _X) noexcept;

	// <summary>
	// 计算绝对值
	// </summary>
	// <param name="_X">有符号的64位整型</param>
	// <returns>返回参数的绝对值</returns>
	XANADU_RUNTIME_EXPORT long long XANADUAPI abs(long long _X) noexcept;

	// <summary>
	// 计算绝对值
	// </summary>
	// <param name="_X">有符号的单精度浮点数</param>
	// <returns>返回参数的绝对值</returns>
	XANADU_RUNTIME_EXPORT float XANADUAPI abs(float _X) noexcept;

	// <summary>
	// 计算绝对值
	// </summary>
	// <param name="_X">有符号的双精度浮点数</param>
	// <returns>返回参数的绝对值</returns>
	XANADU_RUNTIME_EXPORT double XANADUAPI abs(double _X) noexcept;

	// <summary>
	// 计算绝对值
	// </summary>
	// <param name="_X">有符号的多精度浮点数</param>
	// <returns>返回参数的绝对值</returns>
	XANADU_RUNTIME_EXPORT long double XANADUAPI abs(long double _X) noexcept;
};

#endif

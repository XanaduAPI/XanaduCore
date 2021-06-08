#include <XanaduRuntime/Abs.h>

// 计算绝对值
XANADU_RUNTIME_EXPORT char XANADUAPI Xanadu::abs(char _X) noexcept
{
	return static_cast<char>(::abs(_X));
}

// 计算绝对值
XANADU_RUNTIME_EXPORT short XANADUAPI Xanadu::abs(short _X) noexcept
{
	return static_cast<short>(::abs(_X));
}

// 计算绝对值
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::abs(int _X) noexcept
{
	return ::abs(_X);
}

// 计算绝对值
XANADU_RUNTIME_EXPORT long XANADUAPI Xanadu::abs(long _X) noexcept
{
	return ::abs(_X);
}

// 计算绝对值
XANADU_RUNTIME_EXPORT long long XANADUAPI Xanadu::abs(long long _X) noexcept
{
	return ::abs(_X);
}

// 计算绝对值
XANADU_RUNTIME_EXPORT float XANADUAPI Xanadu::abs(float _X) noexcept
{
	return ::fabsf(_X);
}

// 计算绝对值
XANADU_RUNTIME_EXPORT double XANADUAPI Xanadu::abs(double _X) noexcept
{
	return ::fabs(_X);
}

// 计算绝对值
XANADU_RUNTIME_EXPORT long double XANADUAPI Xanadu::abs(long double _X) noexcept
{
	return ::fabsl(_X);
}

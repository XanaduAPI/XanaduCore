#include <XanaduRuntime/Convert.h>
#include <XanaduRuntime/Memory.h>
#include <XanaduRuntime/String.h>

// 将字符串的初始部分转换为 double 表示形式
XANADU_RUNTIME_EXPORT double XANADUAPI Xanadu::atof(const char* _Str) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0.0f);

	return ::atof(_Str);
}

// 将字符串的初始部分转换为 double 表示形式
XANADU_RUNTIME_EXPORT double XANADUAPI Xanadu::atof_l(const char* _Str, XLocale _Locale) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0.0f);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_atof_l(_Str, _Locale);
#endif
#ifdef XANADU_SYSTEM_LINUX
	XANADU_UNPARAMETER(_Locale);
	return ::atof(_Str);
#endif // XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
	return ::atof_l(_Str, _Locale);
#endif // XANADU_SYSTEM_MACOS
}

// 将字符串的初始部分转换为 double 表示形式
XANADU_RUNTIME_EXPORT double XANADUAPI Xanadu::wtof(const wchar_t* _Str) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0.0f);

	auto 		vNString = Xanadu::strwton(_Str);
	auto 		vResult = Xanadu::atof(vNString);
	Xanadu::strfree(vNString);
	return vResult;
}

// 将字符串的初始部分转换为 double 表示形式
XANADU_RUNTIME_EXPORT double XANADUAPI Xanadu::wtof_l(const wchar_t* _Str, XLocale _Locale) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0.0f);

	auto 		vNString = Xanadu::strwton(_Str);
	auto 		vResult = Xanadu::atof_l(vNString, _Locale);
	Xanadu::strfree(vNString);
	return vResult;
}

// 将字符串的初始部分转换为 int 表示形式
XANADU_RUNTIME_EXPORT int32S XANADUAPI Xanadu::atoi(const char* _Str) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0);

	return ::atoi(_Str);
}

// 将字符串的初始部分转换为 int 表示形式
XANADU_RUNTIME_EXPORT int32S XANADUAPI Xanadu::atoi_l(const char* _Str, XLocale _Locale) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_atoi_l(_Str, _Locale);
#endif
#ifdef XANADU_SYSTEM_LINUX
	XANADU_UNPARAMETER(_Locale);
	return ::atoi(_Str);
#endif // XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
	return ::atoi_l(_Str, _Locale);
#endif // XANADU_SYSTEM_MACOS
}

// 将字符串的初始部分转换为 int 表示形式
XANADU_RUNTIME_EXPORT int32S XANADUAPI Xanadu::wtoi(const wchar_t* _Str) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0);

	auto 		vNString = Xanadu::strwton(_Str);
	auto 		vResult = Xanadu::atoi(vNString);
	Xanadu::strfree(vNString);
	return vResult;
}

// 将字符串的初始部分转换为 int 表示形式
XANADU_RUNTIME_EXPORT int32S XANADUAPI Xanadu::wtoi_l(const wchar_t* _Str, XLocale _Locale) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0);

	auto 		vNString = Xanadu::strwton(_Str);
	auto 		vResult = Xanadu::atoi_l(vNString, _Locale);
	Xanadu::strfree(vNString);
	return vResult;
}

// 将字符串的初始部分转换为 long 表示形式
XANADU_RUNTIME_EXPORT long XANADUAPI Xanadu::atol(const char* _Str) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0);

	return ::atol(_Str);
}

// 将字符串的初始部分转换为 long 表示形式
XANADU_RUNTIME_EXPORT long XANADUAPI Xanadu::atol_l(const char* _Str, XLocale _Locale) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_atol_l(_Str, _Locale);
#endif
#ifdef XANADU_SYSTEM_LINUX
	XANADU_UNPARAMETER(_Locale);
	return ::atol(_Str);
#endif // XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
	return ::atol_l(_Str, _Locale);
#endif // XANADU_SYSTEM_MACOS
}

// 将字符串的初始部分转换为 long 表示形式
XANADU_RUNTIME_EXPORT long XANADUAPI Xanadu::wtol(const wchar_t* _Str) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0);

	auto 		vNString = Xanadu::strwton(_Str);
	auto 		vResult = Xanadu::atol(vNString);
	Xanadu::strfree(vNString);
	return vResult;
}

// 将字符串的初始部分转换为 long 表示形式
XANADU_RUNTIME_EXPORT long XANADUAPI Xanadu::wtol_l(const wchar_t* _Str, XLocale _Locale) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0);

	auto 		vNString = Xanadu::strwton(_Str);
	auto 		vResult = Xanadu::atol_l(vNString, _Locale);
	Xanadu::strfree(vNString);
	return vResult;
}

// 将字符串的初始部分转换为 long long 表示形式
XANADU_RUNTIME_EXPORT int64S XANADUAPI Xanadu::atoll(const char* _Str) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0);

	return ::atoll(_Str);
}

// 将字符串的初始部分转换为 long long 表示形式
XANADU_RUNTIME_EXPORT int64S XANADUAPI Xanadu::atoll_l(const char* _Str, XLocale _Locale) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_atoll_l(_Str, _Locale);
#endif
#ifdef XANADU_SYSTEM_LINUX
	XANADU_UNPARAMETER(_Locale);
	return ::atoll(_Str);
#endif // XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
	return ::atoll_l(_Str, _Locale);
#endif // XANADU_SYSTEM_MACOS
}

// 将字符串的初始部分转换为 long long 表示形式
XANADU_RUNTIME_EXPORT int64S XANADUAPI Xanadu::wtoll(const wchar_t* _Str) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0);

	auto 		vNString = Xanadu::strwton(_Str);
	auto 		vResult = Xanadu::atoll(vNString);
	Xanadu::strfree(vNString);
	return vResult;
}

// 将字符串的初始部分转换为 long long 表示形式
XANADU_RUNTIME_EXPORT int64S XANADUAPI Xanadu::wtoll_l(const wchar_t* _Str, XLocale _Locale) noexcept
{
	XANADU_CHECK_RETURN(_Str, 0);

	auto 		vNString = Xanadu::strwton(_Str);
	auto 		vResult = Xanadu::atoll_l(vNString, _Locale);
	Xanadu::strfree(vNString);
	return vResult;
}

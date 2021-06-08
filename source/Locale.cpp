#include <XanaduRuntime/Locale.h>

// 设置或检索运行时区域设置
XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::setlocale(int _Category, const char* _Locale) noexcept
{
	return ::setlocale(_Category, _Locale);
}

// 将宽字符序列分成多字节字符一个对应的序列
XANADU_RUNTIME_EXPORT size_t XANADUAPI Xanadu::wcstombs(char* _MBS, const wchar_t* _WCS, size_t _MaxCount) noexcept
{
	XANADU_CHECK_RETURN(_WCS, -1);

	return ::wcstombs(_MBS, _WCS, _MaxCount);
}

// 将宽字符序列分成多字节字符一个对应的序列
XANADU_RUNTIME_EXPORT size_t XANADUAPI Xanadu::wcstombs_l(char* _MBS, const wchar_t* _WCS, size_t _MaxCount, XLocale _Locale) noexcept
{
	XANADU_CHECK_RETURN(_WCS, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_wcstombs_l(_MBS, _WCS, _MaxCount, _Locale);
#endif
#ifdef XANADU_SYSTEM_LINUX
	XANADU_UNPARAMETER(_Locale);
	return ::wcstombs(_MBS, _WCS, _MaxCount);
#endif // XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
	return ::wcstombs_l(_MBS, _WCS, _MaxCount, _Locale);
#endif // XANADU_SYSTEM_MACOS
}

// 把多字符转换成宽字符
XANADU_RUNTIME_EXPORT size_t XANADUAPI Xanadu::mbstowcs(wchar_t* _WCS, const char* _MBS, size_t _MaxCount) noexcept
{
	XANADU_CHECK_RETURN(_MBS, -1);

	return ::mbstowcs(_WCS, _MBS, _MaxCount);
}

// 把多字符转换成宽字符
XANADU_RUNTIME_EXPORT size_t XANADUAPI Xanadu::mbstowcs_l(wchar_t* _WCS, const char* _MBS, size_t _MaxCount, XLocale _Locale) noexcept
{
	XANADU_CHECK_RETURN(_MBS, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_mbstowcs_l(_WCS, _MBS, _MaxCount, _Locale);
#endif
#ifdef XANADU_SYSTEM_LINUX
	XANADU_UNPARAMETER(_Locale);
	return ::mbstowcs(_WCS, _MBS, _MaxCount);
#endif // XANADU_SYSTEM_LINUX
#ifdef XANADU_SYSTEM_MACOS
	return ::mbstowcs_l(_WCS, _MBS, _MaxCount, _Locale);
#endif // XANADU_SYSTEM_MACOS
}

#ifndef			_XANADU_RUNTIME_LOCALE_H_
#define			_XANADU_RUNTIME_LOCALE_H_

#include <XanaduRuntime/Header.h>

#if defined(XANADU_SYSTEM_WINDOWS)
typedef			_locale_t 						XLocale;
#else
typedef			locale_t 						XLocale;
#endif

namespace Xanadu
{
	// <summary>
	// 设置或检索运行时区域设置
	// </summary>
	// <param name="_Category">区域设置的影响的类别</param>
	// <param name="_Locale">区域设置说明符</param>
	// <returns>如果为有效的 _Locale 和 _Category，返回指向该字符串与指定的 _Locale 和 _Category。如果 _Locale 或 _Category 无效，则返回 null 指针，并且不更改程序的当前区域设置</returns>
	// <examples>setlocale( LC_ALL, "en-US" );</examples>
	XANADU_RUNTIME_EXPORT char* XANADUAPI setlocale(int _Category, const char* _Locale) noexcept;

	// <summary>
	// 将宽字符序列分成多字节字符一个对应的序列
	// 如 _MBS 非 NULL，则 wcstombs() 函数把多字符 _WCS 转换成宽字符 _MBS，最多转换到 _MaxCount 个多字节字符。
	// 如 _MBS 为 NULL，则忽略参数 _MaxCount，转换仍然继续，只是不写到 _WCS，最终返回转换成功的多字节字符个数(不包括终止符'\0')。
	// </summary>
	// <param name="_MBS">多字节字符序列的地址</param>
	// <param name="_WCS">宽字符序列的地址</param>
	// <param name="_MaxCount">在多字节输出字符串中存储的最大字节数</param>
	// <returns>如果 wcstombs() 遇到无效的宽字节字符，则返回-1。如果返回值为 _MaxCount，则宽字符串不以 null 结尾</returns>
	XANADU_RUNTIME_EXPORT size_t XANADUAPI wcstombs(char* _MBS, const wchar_t* _WCS, size_t _MaxCount) noexcept;

	// <summary>
	// 将宽字符序列分成多字节字符一个对应的序列
	// 如 _MBS 非 NULL，则 wcstombs() 函数把多字符 _WCS 转换成宽字符 _MBS，最多转换到 _MaxCount 个多字节字符。
	// 如 _MBS 为 NULL，则忽略参数 _MaxCount，转换仍然继续，只是不写到 _WCS，最终返回转换成功的多字节字符个数(不包括终止符'\0')。
	// </summary>
	// <param name="_MBS">多字节字符序列的地址</param>
	// <param name="_WCS">宽字符序列的地址</param>
	// <param name="_MaxCount">在多字节输出字符串中存储的最大字节数</param>
	// <param name="_Locale">要使用的区域设置</param>
	// <returns>如果 wcstombs() 遇到无效的宽字节字符，则返回-1。如果返回值为 _MaxCount，则宽字符串不以 null 结尾</returns>
	XANADU_RUNTIME_EXPORT size_t XANADUAPI wcstombs_l(char* _MBS, const wchar_t* _WCS, size_t _MaxCount, XLocale _Locale) noexcept;

	// <summary>
	// 把多字符转换成宽字符
	// 如 _WCS 非 NULL，则 mbstowcs() 函数把多字符 _MBS 转换成宽字符 _WCS，最多转换到 _MaxCount 个宽字符（即wchar_t）。
	// 如 _WCS 为 NULL，则忽略参数 _MaxCount，转换仍然继续，只是不写到 _WCS，最终返回转换成功的宽字符个数(不包括终止符'\0')。
	// </summary>
	// <param name="_WCS">用来存放宽字符的缓冲区</param>
	// <param name="_MBS">以空结尾的多字节字符序列的地址</param>
	// <param name="_MaxCount">要转换的最大多字节字符数</param>
	// <returns>如果 mbstowcs() 遇到无效的多字节字符，则返回-1。如果返回值为 _MaxCount，则宽字符串不以 null 结尾</returns>
	XANADU_RUNTIME_EXPORT size_t XANADUAPI mbstowcs(wchar_t* _WCS, const char* _MBS, size_t _MaxCount) noexcept;

	// <summary>
	// 把多字符转换成宽字符
	// 如 _WCS 非 NULL，则 mbstowcs() 函数把多字符 _MBS 转换成宽字符 _WCS，最多转换到 _MaxCount 个宽字符（即wchar_t）。
	// 如 _WCS 为 NULL，则忽略参数 _MaxCount，转换仍然继续，只是不写到 _WCS，最终返回转换成功的宽字符个数(不包括终止符'\0')。
	// </summary>
	// <param name="_WCS">用来存放宽字符的缓冲区</param>
	// <param name="_MBS">以空结尾的多字节字符序列的地址</param>
	// <param name="_MaxCount">要转换的最大多字节字符数</param>
	// <param name="_Locale">要使用的区域设置</param>
	// <returns>如果 mbstowcs() 遇到无效的多字节字符，则返回-1。如果返回值为 _MaxCount，则宽字符串不以 null 结尾</returns>
	XANADU_RUNTIME_EXPORT size_t XANADUAPI mbstowcs_l(wchar_t* _WCS, const char* _MBS, size_t _MaxCount, XLocale _Locale) noexcept;
};

#endif

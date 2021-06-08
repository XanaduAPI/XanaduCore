#ifndef			_XANADU_RUNTIME_CONVERT_H_
#define			_XANADU_RUNTIME_CONVERT_H_

#include <XanaduRuntime/Header.h>
#include <XanaduRuntime/Locale.h>

namespace Xanadu
{
	// <summary>
	// 将字符串的初始部分转换为 double 表示形式
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <returns>函数返回解释生成的 double 值类型。如果输入无法转换为该类型的值返回值为 0.0</returns>
	XANADU_RUNTIME_EXPORT double XANADUAPI atof(const char* _Str) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 double 表示形式
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <param name="_Locale">区域设置说明符</param>
	// <returns>函数返回解释生成的 double 值类型。如果输入无法转换为该类型的值返回值为 0.0</returns>
	XANADU_RUNTIME_EXPORT double XANADUAPI atof_l(const char* _Str, XLocale _Locale) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 double 表示形式
	// atof() 的宽字节版本
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <returns>函数返回解释生成的 double 值类型。如果输入无法转换为该类型的值返回值为 0.0</returns>
	XANADU_RUNTIME_EXPORT double XANADUAPI wtof(const wchar_t* _Str) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 double 表示形式
	// atof_l() 的宽字节版本
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <param name="_Locale">区域设置说明符</param>
	// <returns>函数返回解释生成的 double 值类型。如果输入无法转换为该类型的值返回值为 0.0</returns>
	XANADU_RUNTIME_EXPORT double XANADUAPI wtof_l(const wchar_t* _Str, XLocale _Locale) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 int 表示形式
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <returns>函数返回解释生成的 int 值类型。如果输入无法转换为该类型的值返回值为 0</returns>
	XANADU_RUNTIME_EXPORT int32S XANADUAPI atoi(const char* _Str) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 int 表示形式
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <param name="_Locale">区域设置说明符</param>
	// <returns>函数返回解释生成的 int 值类型。如果输入无法转换为该类型的值返回值为 0</returns>
	XANADU_RUNTIME_EXPORT int32S XANADUAPI atoi_l(const char* _Str, XLocale _Locale) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 int 表示形式
	// atoi() 的宽字节版本
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <returns>函数返回解释生成的 int 值类型。如果输入无法转换为该类型的值返回值为 0</returns>
	XANADU_RUNTIME_EXPORT int32S XANADUAPI wtoi(const wchar_t* _Str) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 int 表示形式
	// atoi_l() 的宽字节版本
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <param name="_Locale">区域设置说明符</param>
	// <returns>函数返回解释生成的 int 值类型。如果输入无法转换为该类型的值返回值为 0</returns>
	XANADU_RUNTIME_EXPORT int32S XANADUAPI wtoi_l(const wchar_t* _Str, XLocale _Locale) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 long 表示形式
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <returns>函数返回解释生成的 long 值类型。如果输入无法转换为该类型的值返回值为 0</returns>
	XANADU_RUNTIME_EXPORT long XANADUAPI atol(const char* _Str) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 long 表示形式
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <param name="_Locale">区域设置说明符</param>
	// <returns>函数返回解释生成的 long 值类型。如果输入无法转换为该类型的值返回值为 0</returns>
	XANADU_RUNTIME_EXPORT long XANADUAPI atol_l(const char* _Str, XLocale _Locale) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 long 表示形式
	// atol() 的宽字节版本
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <returns>函数返回解释生成的 long 值类型。如果输入无法转换为该类型的值返回值为 0</returns>
	XANADU_RUNTIME_EXPORT long XANADUAPI wtol(const wchar_t* _Str) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 long 表示形式
	// atol_l() 的宽字节版本
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <param name="_Locale">区域设置说明符</param>
	// <returns>函数返回解释生成的 long 值类型。如果输入无法转换为该类型的值返回值为 0</returns>
	XANADU_RUNTIME_EXPORT long XANADUAPI wtol_l(const wchar_t* _Str, XLocale _Locale) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 long long 表示形式
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <returns>函数返回解释生成的 long long 值类型。如果输入无法转换为该类型的值返回值为 0</returns>
	XANADU_RUNTIME_EXPORT int64S XANADUAPI atoll(const char* _Str) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 long long 表示形式
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <param name="_Locale">区域设置说明符</param>
	// <returns>函数返回解释生成的 long long 值类型。如果输入无法转换为该类型的值返回值为 0</returns>
	XANADU_RUNTIME_EXPORT int64S XANADUAPI atoll_l(const char* _Str, XLocale _Locale) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 long long 表示形式
	// atoll() 的宽字节版本
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <returns>函数返回解释生成的 long long 值类型。如果输入无法转换为该类型的值返回值为 0</returns>
	XANADU_RUNTIME_EXPORT int64S XANADUAPI wtoll(const wchar_t* _Str) noexcept;

	// <summary>
	// 将字符串的初始部分转换为 long long 表示形式
	// atoll_l() 的宽字节版本
	// </summary>
	// <param name="_Str">要转换的字符串</param>
	// <param name="_Locale">区域设置说明符</param>
	// <returns>函数返回解释生成的 long long 值类型。如果输入无法转换为该类型的值返回值为 0</returns>
	XANADU_RUNTIME_EXPORT int64S XANADUAPI wtoll_l(const wchar_t* _Str, XLocale _Locale) noexcept;
};

#endif

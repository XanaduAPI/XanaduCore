#ifndef			_XANADU_RUNTIME_STRING_H_
#define			_XANADU_RUNTIME_STRING_H_

#include <XanaduRuntime/Header.h>

namespace Xanadu
{
	XANADU_RUNTIME_EXPORT size_t XANADUAPI strlen(const char* _String) noexcept;

	XANADU_RUNTIME_EXPORT size_t XANADUAPI wcslen(const wchar_t* _String) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strchr(char* _Str, int _Val) noexcept;

	XANADU_RUNTIME_EXPORT const char* XANADUAPI strchr(const char* _Str, int _Val) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strrchr(char* _Str, int _Ch) noexcept;

	XANADU_RUNTIME_EXPORT const char* XANADUAPI strrchr(const char* _Str, int _Ch) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcschr(wchar_t* _Str, wchar_t _Val) noexcept;

	XANADU_RUNTIME_EXPORT const wchar_t* XANADUAPI wcschr(const wchar_t* _Str, wchar_t _Val) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcsrchr(wchar_t* _Str, wchar_t _Ch) noexcept;

	XANADU_RUNTIME_EXPORT const wchar_t* XANADUAPI wcsrchr(const wchar_t* _Str, wchar_t _Ch) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strstr(char* _String, const char* _SubStr) noexcept;

	XANADU_RUNTIME_EXPORT const char* XANADUAPI strstr(const char* _String, const char* _SubStr) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcsstr(wchar_t* _String, const wchar_t* _SubStr) noexcept;

	XANADU_RUNTIME_EXPORT const wchar_t* XANADUAPI wcsstr(const wchar_t* _String, const wchar_t* _SubStr) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strcpy(char* _Dest, const char* _Source) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strcpy(char* _Dest, size_t _Length, const char* _Source) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcscpy(wchar_t* _Dest, const wchar_t* _Source) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcscpy(wchar_t* _Dest, size_t _Length, const wchar_t* _Source) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strncpy(char* _Dest, const char* _Source, size_t _MaxCount) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strncpy(char* _Dest, size_t _Length, const char* _Source, size_t _MaxCount) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcsncpy(wchar_t* _Dest, const wchar_t* _Source, size_t _MaxCount) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcsncpy(wchar_t* _Dest, size_t _Length, const wchar_t* _Source, size_t _MaxCount) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strcat(char* _Dest, const char* _Source) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strcat(char* _Dest, size_t _Length, const char* _Source) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcscat(wchar_t* _Dest, const wchar_t* _Source) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcscat(wchar_t* _Dest, size_t _Length, const wchar_t* _Source) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI strcmp(const char* _Str1, const char* _Str2) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI wcscmp(const wchar_t* _Str1, const wchar_t* _Str2) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI strncmp(const char* _Str1, const char* _Str2, size_t _MaxCount) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI wcsncmp(const wchar_t* _Str1, const wchar_t* _Str2, size_t _MaxCount) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI strcasecmp(const char* _String1, const char* _String2) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI wcscasecmp(const wchar_t* _String1, const wchar_t* _String2) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strdup(const char* _String) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcsdup(const wchar_t* _String) noexcept;

	XANADU_RUNTIME_EXPORT void XANADUAPI strfree(char* _String) noexcept;

	XANADU_RUNTIME_EXPORT void XANADUAPI wcsfree(wchar_t* _String) noexcept;


	XANADU_RUNTIME_EXPORT int XANADUAPI tolower(int _C) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI toupper(int _C) noexcept;

	XANADU_RUNTIME_EXPORT wint_t XANADUAPI towlower(wint_t _C) noexcept;

	XANADU_RUNTIME_EXPORT wint_t XANADUAPI towupper(wint_t _C) noexcept;


	XANADU_RUNTIME_EXPORT char* XANADUAPI strlower(char* _String) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strlower(char* _String, size_t _MaxCount) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strupper(char* _String) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI strupper(char* _String, size_t _MaxCount) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcslower(wchar_t* _String) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcslower(wchar_t* _String, size_t _MaxCount) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcsupper(wchar_t* _String) noexcept;

	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcsupper(wchar_t* _String, size_t _MaxCount) noexcept;

	// <summary>
	// UNICODE 转换为 ASCII，需要使用 Xanadu::strfree() 释放
	// </summary>
	// <param name="_String"> 一个 UNICODE 的字符串 </param>
	// <returns> 成功时返回一个 ASCII 字符串，失败返回nullptr </returns>
	XANADU_RUNTIME_EXPORT char* XANADUAPI strwtoa(const wchar_t* _String) noexcept;

	// <summary>
	// UNICODE 转换为 UTF-8，需要使用 Xanadu::strfree() 释放
	// </summary>
	// <param name="_String">一个 UNICODE 的字符串</param>
	// <returns>成功时返回一个 UTF-8 字符串，失败返回nullptr</returns>
	XANADU_RUNTIME_EXPORT char* XANADUAPI strwtou(const wchar_t* _String) noexcept;

	// <summary>
	// UNICODE 转换为 Native String(Windows:ASCII/Other:UTF-8)，需要使用 Xanadu::strfree() 释放
	// </summary>
	// <param name="_String"> 一个 UNICODE 的字符串 </param>
	// <returns> 成功时返回一个 Native String(Windows:ASCII/Other:UTF-8) 字符串，失败返回nullptr </returns>
	XANADU_RUNTIME_EXPORT char* XANADUAPI strwton(const wchar_t* _String) noexcept;

	// <summary>
	// ASCII 转换为 UNICODE，需要使用 Xanadu::wcsfree() 释放
	// </summary>
	// <param name="_String"> 一个 ASCII 的字符串 </param>
	// <returns> 成功时返回一个 UNICODE 字符串，失败返回nullptr </returns>
	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI stratow(const char* _String) noexcept;

	// <summary>
	// UTF-8 转换为 UNICODE，需要使用 Xanadu::wcsfree() 释放
	// </summary>
	// <param name="_String"> 一个 UTF-8 的字符串 </param>
	// <returns> 成功时返回一个 UNICODE 字符串，失败返回nullptr </returns>
	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI strutow(const char* _String) noexcept;

	// <summary>
	// Native String(Windows:ASCII/Other:UTF-8) 转换为 UNICODE，需要使用 Xanadu::wcsfree() 释放
	// </summary>
	// <param name="_String"> 一个 Native String(Windows:ASCII/Other:UTF-8) 的字符串 </param>
	// <returns> 成功时返回一个 UNICODE 字符串，失败返回nullptr </returns>
	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI strntow(const char* _String) noexcept;
};

#endif

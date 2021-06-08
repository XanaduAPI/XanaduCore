#include <XanaduRuntime/String.h>
#include <XanaduRuntime/Locale.h>
#include <XanaduRuntime/Memory.h>
#include <cstring>
#include <codecvt>
#include <locale>

XANADU_RUNTIME_EXPORT size_t XANADUAPI Xanadu::strlen(const char* _String) noexcept
{
	XANADU_CHECK_RETURN(_String, 0LL);

	return ::strlen(_String);
}

XANADU_RUNTIME_EXPORT size_t XANADUAPI Xanadu::wcslen(const wchar_t* _String) noexcept
{
	XANADU_CHECK_RETURN(_String, 0LL);

	return ::wcslen(_String);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strchr(char* _Str, int _Val) noexcept
{
	XANADU_CHECK_RETURN(_Str, nullptr);

	return ::strchr(_Str, _Val);
}

XANADU_RUNTIME_EXPORT const char* XANADUAPI Xanadu::strchr(const char* _Str, int _Val) noexcept
{
	XANADU_CHECK_RETURN(_Str, nullptr);

	return ::strchr(_Str, _Val);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strrchr(char* _Str, int _Ch) noexcept
{
	XANADU_CHECK_RETURN(_Str, nullptr);

	return ::strrchr(_Str, _Ch);
}

XANADU_RUNTIME_EXPORT const char* XANADUAPI Xanadu::strrchr(const char* _Str, int _Ch) noexcept
{
	XANADU_CHECK_RETURN(_Str, nullptr);

	return ::strrchr(_Str, _Ch);
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcschr(wchar_t* _Str, wchar_t _Val) noexcept
{
	XANADU_CHECK_RETURN(_Str, nullptr);

	return ::wcschr(_Str, _Val);
}

XANADU_RUNTIME_EXPORT const wchar_t* XANADUAPI Xanadu::wcschr(const wchar_t* _Str, wchar_t _Val) noexcept
{
	XANADU_CHECK_RETURN(_Str, nullptr);

	return ::wcschr(_Str, _Val);
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcsrchr(wchar_t* _Str, wchar_t _Ch) noexcept
{
	XANADU_CHECK_RETURN(_Str, nullptr);

	return ::wcsrchr(_Str, _Ch);
}

XANADU_RUNTIME_EXPORT const wchar_t* XANADUAPI Xanadu::wcsrchr(const wchar_t* _Str, wchar_t _Ch) noexcept
{
	XANADU_CHECK_RETURN(_Str, nullptr);

	return ::wcsrchr(_Str, _Ch);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strstr(char* _String, const char* _SubStr) noexcept
{
	XANADU_CHECK_RETURN(_String, nullptr);
	XANADU_CHECK_RETURN(_SubStr, nullptr);

	return ::strstr(_String, _SubStr);
}

XANADU_RUNTIME_EXPORT const char* XANADUAPI Xanadu::strstr(const char* _String, const char* _SubStr) noexcept
{
	XANADU_CHECK_RETURN(_String, nullptr);
	XANADU_CHECK_RETURN(_SubStr, nullptr);

	return ::strstr(_String, _SubStr);
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcsstr(wchar_t* _String, const wchar_t* _SubStr) noexcept
{
	XANADU_CHECK_RETURN(_String, nullptr);
	XANADU_CHECK_RETURN(_SubStr, nullptr);

	return ::wcsstr(_String, _SubStr);
}

XANADU_RUNTIME_EXPORT const wchar_t* XANADUAPI Xanadu::wcsstr(const wchar_t* _String, const wchar_t* _SubStr) noexcept
{
	XANADU_CHECK_RETURN(_String, nullptr);
	XANADU_CHECK_RETURN(_SubStr, nullptr);

	return ::wcsstr(_String, _SubStr);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strcpy(char* _Dest, const char* _Source) noexcept
{
	XANADU_CHECK_RETURN(_Dest, nullptr);
	XANADU_CHECK_RETURN(_Source, nullptr);

	return ::strcpy(_Dest, _Source);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strcpy(char* _Dest, size_t _Length, const char* _Source) noexcept
{
	XANADU_CHECK_RETURN(_Dest, nullptr);
	XANADU_CHECK_RETURN(_Source, nullptr);
	XANADU_UNPARAMETER(_Length);

	return Xanadu::strcpy(_Dest, _Source);
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcscpy(wchar_t* _Dest, const wchar_t* _Source) noexcept
{
	XANADU_CHECK_RETURN(_Dest, nullptr);
	XANADU_CHECK_RETURN(_Source, nullptr);

	return ::wcscpy(_Dest, _Source);
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcscpy(wchar_t* _Dest, size_t _Length, const wchar_t* _Source) noexcept
{
	XANADU_CHECK_RETURN(_Dest, nullptr);
	XANADU_CHECK_RETURN(_Source, nullptr);
	XANADU_UNPARAMETER(_Length);

	return Xanadu::wcscpy(_Dest, _Source);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strncpy(char* _Dest, const char* _Source, size_t _MaxCount) noexcept
{
	XANADU_CHECK_RETURN(_Dest, nullptr);
	XANADU_CHECK_RETURN(_Source, nullptr);

	return ::strncpy(_Dest, _Source, _MaxCount);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strncpy(char* _Dest, size_t _Length, const char* _Source, size_t _MaxCount) noexcept
{
	XANADU_CHECK_RETURN(_Dest, nullptr);
	XANADU_CHECK_RETURN(_Source, nullptr);
	XANADU_UNPARAMETER(_Length);

	return Xanadu::strncpy(_Dest, _Source, _MaxCount);
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcsncpy(wchar_t* _Dest, const wchar_t* _Source, size_t _MaxCount) noexcept
{
	XANADU_CHECK_RETURN(_Dest, nullptr);
	XANADU_CHECK_RETURN(_Source, nullptr);

	return ::wcsncpy(_Dest, _Source, _MaxCount);
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcsncpy(wchar_t* _Dest, size_t _Length, const wchar_t* _Source, size_t _MaxCount) noexcept
{
	XANADU_CHECK_RETURN(_Dest, nullptr);
	XANADU_CHECK_RETURN(_Source, nullptr);
	XANADU_UNPARAMETER(_Length);

	return Xanadu::wcsncpy(_Dest, _Source, _MaxCount);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strcat(char* _Dest, const char* _Source) noexcept
{
	XANADU_CHECK_RETURN(_Dest, nullptr);
	XANADU_CHECK_RETURN(_Source, _Dest);

	return ::strcat(_Dest, _Source);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strcat(char* _Dest, size_t _Length, const char* _Source) noexcept
{
	XANADU_CHECK_RETURN(_Dest, nullptr);
	XANADU_CHECK_RETURN(_Source, _Dest);
	XANADU_UNPARAMETER(_Length);

	return Xanadu::strcat(_Dest, _Source);
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcscat(wchar_t* _Dest, const wchar_t* _Source) noexcept
{
	XANADU_CHECK_RETURN(_Dest, nullptr);
	XANADU_CHECK_RETURN(_Source, nullptr);

	return ::wcscat(_Dest, _Source);
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcscat(wchar_t* _Dest, size_t _Length, const wchar_t* _Source) noexcept
{
	XANADU_CHECK_RETURN(_Dest, nullptr);
	XANADU_CHECK_RETURN(_Source, nullptr);
	XANADU_UNPARAMETER(_Length);

	return Xanadu::wcscat(_Dest, _Source);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::strcmp(const char* _Str1, const char* _Str2) noexcept
{
	if (_Str1 == _Str2)
	{
		return 0;
	}
	if (_Str1 && _Str2)
	{
		return ::strcmp(_Str1, _Str2);
	}
	else if(_Str1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wcscmp(const wchar_t* _Str1, const wchar_t* _Str2) noexcept
{
	if(_Str1 == _Str2)
	{
		return 0;
	}
	if(_Str1 && _Str2)
	{
		return ::wcscmp(_Str1, _Str2);
	}
	else if(_Str1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::strncmp(const char* _Str1, const char* _Str2, size_t _MaxCount) noexcept
{
	if(_Str1 == _Str2)
	{
		return 0;
	}
	if(_Str1 && _Str2)
	{
		return ::strncmp(_Str1, _Str2, _MaxCount);
	}
	else if(_Str1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wcsncmp(const wchar_t* _Str1, const wchar_t* _Str2, size_t _MaxCount) noexcept
{
	if(_Str1 == _Str2)
	{
		return 0;
	}
	if(_Str1 && _Str2)
	{
		return ::wcsncmp(_Str1, _Str2, _MaxCount);
	}
	else if(_Str1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::strcasecmp(const char* _String1, const char* _String2) noexcept
{
	if(_String1 == _String2)
	{
		return 0;
	}
	if(!_String1)
	{
		return (_String1 == _String2) ? 0 : -1;
	}
	if(!_String2)
	{
		return 1;
	}
	for(; ::tolower(*_String1) == ::tolower(*_String2); ++_String1, ++_String2)
	{
		if(*_String1 == 0)
		{
			return 0;
		}
	}
	return ::tolower(*(const char*)_String1) - ::tolower(*(const char*)_String2);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wcscasecmp(const wchar_t* _String1, const wchar_t* _String2) noexcept
{
	if(_String1 == _String2)
	{
		return 0;
	}
	if(!_String1)
	{
		return (_String1 == _String2) ? 0 : -1;
	}
	if(!_String2)
	{
		return 1;
	}
	for(; ::towlower(*_String1) == ::towlower(*_String2); ++_String1, ++_String2)
	{
		if(*_String1 == 0)
		{
			return 0;
		}
	}
	return ::towlower(*(const wchar_t*)_String1) - ::towlower(*(const wchar_t*)_String2);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strdup(const char* _String) noexcept
{
	XANADU_CHECK_RETURN(_String, nullptr);

	auto		vLength = Xanadu::strlen(_String) + 1;
	auto		vMemory = (char*)Xanadu::malloc(vLength);
	if(vMemory)
	{
		Xanadu::memcpy(vMemory, _String, vLength);
		vMemory[vLength - 1] = '\0';
		return vMemory;
	}
	return nullptr;
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcsdup(const wchar_t* _String) noexcept
{
	XANADU_CHECK_RETURN(_String, nullptr);

	auto		vLength = Xanadu::wcslen(_String) + 1;
	auto		vMemory = (wchar_t*)Xanadu::malloc(vLength * sizeof(wchar_t));
	if(vMemory)
	{
		Xanadu::wmemcpy(vMemory, _String, vLength);
		vMemory[vLength - 1] = L'\0';
		return vMemory;
	}
	return nullptr;
}

XANADU_RUNTIME_EXPORT void XANADUAPI Xanadu::strfree(char* _String) noexcept
{
	XANADU_CHECK_RETURN(_String);

	Xanadu::free(_String);
}

XANADU_RUNTIME_EXPORT void XANADUAPI Xanadu::wcsfree(wchar_t* _String) noexcept
{
	XANADU_CHECK_RETURN(_String);

	Xanadu::free(_String);
}


XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::tolower(int _C) noexcept
{
	return ::tolower(_C);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::toupper(int _C) noexcept
{
	return ::toupper(_C);
}

XANADU_RUNTIME_EXPORT wint_t XANADUAPI Xanadu::towlower(wint_t _C) noexcept
{
	return ::towlower(_C);
}

XANADU_RUNTIME_EXPORT wint_t XANADUAPI Xanadu::towupper(wint_t _C) noexcept
{
	return ::towupper(_C);
}


XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strlower(char* _String) noexcept
{
	return Xanadu::strlower(_String, Xanadu::strlen(_String));
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strlower(char* _String, size_t _MaxCount) noexcept
{
	if (_String && _MaxCount)
	{
		for (auto vIndex = 0U; vIndex < _MaxCount; ++vIndex)
		{
			_String[vIndex] = (char)Xanadu::tolower(_String[vIndex]);
		}
	}
	return _String;
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strupper(char* _String) noexcept
{
	return Xanadu::strupper(_String, Xanadu::strlen(_String));
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strupper(char* _String, size_t _MaxCount) noexcept
{
	if(_String && _MaxCount)
	{
		for(auto vIndex = 0U; vIndex < _MaxCount; ++vIndex)
		{
			_String[vIndex] = (char)Xanadu::toupper(_String[vIndex]);
		}
	}
	return _String;
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcslower(wchar_t* _String) noexcept
{
	return Xanadu::wcslower(_String, Xanadu::wcslen(_String));
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcslower(wchar_t* _String, size_t _MaxCount) noexcept
{
	if(_String && _MaxCount)
	{
		for(auto vIndex = 0U; vIndex < _MaxCount; ++vIndex)
		{
			_String[vIndex] = Xanadu::towlower(_String[vIndex]);
		}
	}
	return _String;
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcsupper(wchar_t* _String) noexcept
{
	return Xanadu::wcsupper(_String, Xanadu::wcslen(_String));
}

XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wcsupper(wchar_t* _String, size_t _MaxCount) noexcept
{
	if(_String && _MaxCount)
	{
		for(auto vIndex = 0U; vIndex < _MaxCount; ++vIndex)
		{
			_String[vIndex] = Xanadu::towupper(_String[vIndex]);
		}
	}
	return _String;
}

// UNICODE 转换为 ASCII，需要使用 Xanadu::strfree() 释放
XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strwtoa(const wchar_t* _String) noexcept
{
	XANADU_CHECK_RETURN(_String, nullptr);

	auto		vAString = std::string("");
	auto		_DestSize = static_cast<unsigned int>(4 * Xanadu::wcslen(_String) + 1);
	auto		_Dest = (char*)XANADU_MALLOC(_DestSize);
	Xanadu::memset(_Dest, 0, _DestSize);
	Xanadu::wcstombs(_Dest, _String, _DestSize);
	vAString = _Dest;
	XANADU_FREE(_Dest);
	return Xanadu::strdup(vAString.data());
}

// UNICODE 转换为 UTF-8，需要使用 Xanadu::strfree() 释放
XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strwtou(const wchar_t* _String) noexcept
{
	XANADU_CHECK_RETURN(_String, nullptr);

	auto		vUString = std::string("");
	try
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> vConvert;
		vUString = vConvert.to_bytes(_String);
	}
	catch(const std::exception& _Except)
	{
		XANADU_UNPARAMETER(_Except);
#ifdef _XANADU_EXCEPTION_OUTPUT
		fprintf(stderr, "[%s : %d] exception : %ls", __XFUNCSIG__, __XLINE__, _String);
#endif
	}
	return Xanadu::strdup(vUString.data());
}

// UNICODE 转换为 Native String(Windows:ASCII/Other:UTF-8)，需要使用 Xanadu::strfree() 释放
XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::strwton(const wchar_t* _String) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return Xanadu::strwtoa(_String);
#else
	return Xanadu::strwtou(_String);
#endif
}

// ASCII 转换为 UNICODE，需要使用 Xanadu::wcsfree() 释放
XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::stratow(const char* _String) noexcept
{
	XANADU_CHECK_RETURN(_String, nullptr);

	auto		vXString = std::wstring(L"");
	auto	_Dsize = static_cast<unsigned int>(Xanadu::strlen(_String) + 1);
	auto	_Dest = (wchar_t*)XANADU_MALLOC(sizeof(wchar_t) * _Dsize);
	Xanadu::wmemset(_Dest, 0, _Dsize);
	Xanadu::mbstowcs(_Dest, _String, _Dsize);
	vXString = _Dest;
	XANADU_FREE(_Dest);
	return Xanadu::wcsdup(vXString.data());
}

// UTF-8 转换为 UNICODE，需要使用 Xanadu::wcsfree() 释放
XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::strutow(const char* _String) noexcept
{
	XANADU_CHECK_RETURN(_String, nullptr);

	auto		vReturn = std::wstring(L"");
	try
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> vConvert;
		vReturn = vConvert.from_bytes(_String);
	}
	catch(const std::exception& _Except)
	{
		XANADU_UNPARAMETER(_Except);
#ifdef _XANADU_EXCEPTION_OUTPUT
		fprintf(stderr, "[%s : %d] exception : %s", __XFUNCSIG__, __XLINE__, _String);
#endif
	}
	return Xanadu::wcsdup(vReturn.data());
}

// Native String(Windows:ASCII/Other:UTF-8) 转换为 UNICODE，需要使用 Xanadu::wcsfree() 释放
XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::strntow(const char* _String) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return Xanadu::stratow(_String);
#else
	return Xanadu::strutow(_String);
#endif
}

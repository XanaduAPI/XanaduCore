#include <XanaduCore/XRuntime.h>


// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// C memory management library
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// Allocates size bytes of uninitialized storage.
XANADU_CORE_EXPORT void* XANADUAPI Xanadu::malloc(std::size_t _Size) noexcept
{
	return std::malloc(_Size);
}

// Allocates memory for an array of num objects of size size and initializes it to all bits zero.
XANADU_CORE_EXPORT void* XANADUAPI Xanadu::calloc(std::size_t _Number, std::size_t _Size) noexcept
{
	return std::calloc(_Number, _Size);
}

// Reallocates the given area of memory.
XANADU_CORE_EXPORT void* XANADUAPI Xanadu::realloc(void* _Block, size_t _Size) noexcept
{
	if(_Block)
	{
		return std::realloc(_Block, _Size);
	}
	else
	{
		return std::malloc(_Size);
	}
}

// Deallocates the space previously allocated by malloc, calloc, or realloc.
XANADU_CORE_EXPORT void XANADUAPI Xanadu::free(void* _Memory) noexcept
{
	if(_Memory)
	{
		std::free(_Memory);
	}
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Character array manipulation
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// searches an array for the first occurrence of a character
XANADU_CORE_EXPORT const void* XANADUAPI Xanadu::memchr(const void* _Buf, int _Val, std::size_t _Count) noexcept
{
	if(_Buf)
	{
		return std::memchr(_Buf, _Val, _Count);
	}
	return nullptr;
}

// searches an array for the first occurrence of a character
XANADU_CORE_EXPORT const wchar_t* XANADUAPI Xanadu::wmemchr(const wchar_t* _Buf, wchar_t _Val, std::size_t _Count) noexcept
{
	if(_Buf)
	{
		return std::wmemchr(_Buf, _Val, _Count);
	}
	return nullptr;
}

// searches an array for the first occurrence of a character
XANADU_CORE_EXPORT void* XANADUAPI Xanadu::memchr(void* _Buf, int _Val, std::size_t _Count) noexcept
{
	if(_Buf)
	{
		return std::memchr(_Buf, _Val, _Count);
	}
	return nullptr;
}

// searches an array for the first occurrence of a character
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wmemchr(wchar_t* _Buf, wchar_t _Val, std::size_t _Count) noexcept
{
	if(_Buf)
	{
		return std::wmemchr(_Buf, _Val, _Count);
	}
	return nullptr;
}

// compare the values of _Buf1 and _Buf2 by byte, up to _Size bytes.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::memcmp(const void* _Buf1, const void* _Buf2, std::size_t _Size) noexcept
{
	if (_Buf1 == _Buf2)
	{
		return 0;
	}
	if (_Buf1 && _Buf2)
	{
		return std::memcmp(_Buf1, _Buf2, _Size);
	}
	else if(_Buf1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

// compare the values of _Buf1 and _Buf2 by byte, up to _Size bytes.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wmemcmp(const wchar_t* _Buf1, const wchar_t* _Buf2, std::size_t _Size) noexcept
{
	if (_Buf1 == _Buf2)
	{
		return 0;
	}
	if (_Buf1 && _Buf2)
	{
		return std::wmemcmp(_Buf1, _Buf2, _Size);
	}
	else if(_Buf1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

// Sets the first num bytes of the block of memory pointed by ptr to the specified value.
XANADU_CORE_EXPORT void* XANADUAPI Xanadu::memset(void* _Buffer, int _Value, std::size_t _Size) noexcept
{
	if(_Buffer)
	{
		return std::memset(_Buffer, _Value, _Size);
	}
	return nullptr;
}

// Sets the first num bytes of the block of memory pointed by ptr to the specified value.
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wmemset(wchar_t* _Buffer, wchar_t _Value, std::size_t _Size) noexcept
{
	if(_Buffer)
	{
		return std::wmemset(_Buffer, _Value, _Size);
	}
	return nullptr;
}

// Copies size bytes from the object pointed to by src to the object pointed to by dest.
XANADU_CORE_EXPORT void* XANADUAPI Xanadu::memcpy(void* _Dest, const void* _Src, std::size_t _Size) noexcept
{
	if(_Dest && _Src)
	{
		return std::memcpy(_Dest, _Src, _Size);
	}
	return nullptr;
}

// Copies size bytes from the object pointed to by src to the object pointed to by dest.
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wmemcpy(wchar_t* _Dest, const wchar_t* _Src, std::size_t _Size) noexcept
{
	if(_Dest && _Src)
	{
		return std::wmemcpy(_Dest, _Src, _Size);
	}
	return nullptr;
}

// Copies size bytes from the object pointed to by src to the object pointed to by dest.
XANADU_CORE_EXPORT void* XANADUAPI Xanadu::memcpy(void* _Dest, std::size_t _Length, const void* _Src, std::size_t _Size) noexcept
{
	if(_Dest && _Src)
	{
		return std::memcpy(_Dest, _Src, _Length < _Size ? _Length : _Size);
	}
	return nullptr;
}

// Copies size bytes from the object pointed to by src to the object pointed to by dest.
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wmemcpy(wchar_t* _Dest, std::size_t _Length, const wchar_t* _Src, std::size_t _Size) noexcept
{
	if(_Dest && _Src)
	{
		return std::wmemcpy(_Dest, _Src, _Length < _Size ? _Length : _Size);
	}
	return nullptr;
}

// Copies count characters from the object pointed to by src to the object pointed to by dest.
XANADU_CORE_EXPORT void* XANADUAPI Xanadu::memmove(void* _Dest, const void* _Src, std::size_t _Size) noexcept
{
	if(_Dest && _Src)
	{
		return std::memmove(_Dest, _Src, _Size);
	}
	return nullptr;
}

// Copies count characters from the object pointed to by src to the object pointed to by dest.
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wmemmove(wchar_t* _Dest, const wchar_t* _Src, std::size_t _Size) noexcept
{
	if(_Dest && _Src)
	{
		return std::wmemmove(_Dest, _Src, _Size);
	}
	return nullptr;
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Character classification
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// checks if a character is alphanumeric.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::isalnum(int _Char) noexcept
{
	return std::isalnum(_Char);
}

// checks if a wide character is alphanumeric.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswalnum(std::wint_t _Char) noexcept
{
	return std::iswalnum(_Char);
}

// checks if a character is alphabetic.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::isalpha(int _Char) noexcept
{
	return std::isalpha(_Char);
}

// checks if a wide character is alphabetic.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswalpha(std::wint_t _Char) noexcept
{
	return std::iswalpha(_Char);
}

// checks if a character is lowercase.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::islower(int _Char) noexcept
{
	return std::islower(_Char);
}

// checks if a wide character is lowercase.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswlower(std::wint_t _Char) noexcept
{
	return std::iswlower(_Char);
}

// checks if a character is an uppercase character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::isupper(int _Char) noexcept
{
	return std::isupper(_Char);
}

// checks if a wide character is an uppercase character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswupper(std::wint_t _Char) noexcept
{
	return std::iswupper(_Char);
}

// checks if a character is a digit.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::isdigit(int _Char) noexcept
{
	return std::isdigit(_Char);
}

// checks if a wide character is a digit.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswdigit(std::wint_t _Char) noexcept
{
	return std::iswdigit(_Char);
}

// checks if a character is a hexadecimal character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::isxdigit(int _Char) noexcept
{
	return std::isxdigit(_Char);
}

// checks if a wide character is a hexadecimal character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswxdigit(std::wint_t _Char) noexcept
{
	return std::iswxdigit(_Char);
}

// checks if a character is a control character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iscntrl(int _Char) noexcept
{
	return std::iscntrl(_Char);
}

// checks if a wide character is a control character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswcntrl(std::wint_t _Char) noexcept
{
	return std::iswcntrl(_Char);
}

// checks if a character is a graphical character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::isgraph(int _Char) noexcept
{
	return std::isgraph(_Char);
}

// checks if a wide character is a graphical character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswgraph(std::wint_t _Char) noexcept
{
	return std::iswgraph(_Char);
}

// checks if a character is a space character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::isspace(int _Char) noexcept
{
	return std::isspace(_Char);
}

// checks if a wide character is a space character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswspace(std::wint_t _Char) noexcept
{
	return std::iswspace(_Char);
}

// checks if a character is a blank character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::isblank(int _Char) noexcept
{
	return std::isblank(_Char);
}

// checks if a wide character is a blank character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswblank(std::wint_t _Char) noexcept
{
	return std::iswblank(_Char);
}

// checks if a character is a printing character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::isprint(int _Char) noexcept
{
	return std::isprint(_Char);
}

// checks if a wide character is a printing character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswprint(std::wint_t _Char) noexcept
{
	return std::iswprint(_Char);
}

// checks if a character is a punctuation character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::ispunct(int _Char) noexcept
{
	return std::ispunct(_Char);
}

// checks if a wide character is a punctuation character.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswpunct(std::wint_t _Char) noexcept
{
	return std::iswpunct(_Char);
}

// classifies a wide character according to the specified LC_CTYPE category
XANADU_CORE_EXPORT int XANADUAPI Xanadu::iswctype(std::wint_t _Char, std::wctype_t _Desc) noexcept
{
	return std::iswctype(_Char, _Desc);
}

// looks up a character classification category in the current C locale
XANADU_CORE_EXPORT std::wctype_t XANADUAPI Xanadu::wctype(const char* _String) noexcept
{
	return std::wctype(_String);
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Character manipulation
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// converts a character to lowercase
XANADU_CORE_EXPORT int XANADUAPI Xanadu::tolower(int _Char) noexcept
{
	return std::tolower(_Char);
}

// Converts the given wide character to lowercase
XANADU_CORE_EXPORT std::wint_t XANADUAPI Xanadu::towlower(std::wint_t _Char) noexcept
{
	return std::towlower(_Char);
}

// converts a character to uppercase
XANADU_CORE_EXPORT int XANADUAPI Xanadu::toupper(int _Char) noexcept
{
	return std::toupper(_Char);
}

// Converts the given wide character to uppercase
XANADU_CORE_EXPORT std::wint_t XANADUAPI Xanadu::towupper(std::wint_t _Char) noexcept
{
	return std::towupper(_Char);
}

// performs character mapping according to the specified LC_CTYPE mapping category
XANADU_CORE_EXPORT std::wint_t XANADUAPI Xanadu::towctrans(std::wint_t _WChar, std::wctrans_t _Desc) noexcept
{
	return std::towctrans(_WChar, _Desc);
}

// looks up a character mapping category in the current C locale
XANADU_CORE_EXPORT std::wctrans_t XANADUAPI Xanadu::wctrans(const char* _String) noexcept
{
	return std::wctrans(_String);
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Conversions to numeric formats
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// converts a byte string to a floating point value.
XANADU_CORE_EXPORT double XANADUAPI Xanadu::atof(const char* _String) noexcept
{
	if(_String)
	{
		return std::atof(_String);
	}
	return 0.0f;
}

// converts a byte string to a floating point value.
XANADU_CORE_EXPORT double XANADUAPI Xanadu::wtof(const wchar_t* _String) noexcept
{
	if(_String)
	{
		auto 		vNString = Xanadu::strwton(_String);
		auto 		vResult = Xanadu::atof(vNString);
		Xanadu::strfree(vNString);
		return vResult;
	}
	return 0.0f;
}

// converts a byte string to an integer value.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::atoi(const char* _String) noexcept
{
	if(_String)
	{
		return std::atoi(_String);
	}
	return 0;
}

// converts a byte string to an integer value.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wtoi(const wchar_t* _String) noexcept
{
	if(_String)
	{
		auto 		vNString = Xanadu::strwton(_String);
		auto 		vResult = Xanadu::atoi(vNString);
		Xanadu::strfree(vNString);
		return vResult;
	}
	return 0;
}

// converts a byte string to an integer value.
XANADU_CORE_EXPORT long XANADUAPI Xanadu::atol(const char* _String) noexcept
{
	if(_String)
	{
		return std::atol(_String);
	}
	return 0;
}

// converts a byte string to an integer value.
XANADU_CORE_EXPORT long XANADUAPI Xanadu::wtol(const wchar_t* _String) noexcept
{
	if(_String)
	{
		auto 		vNString = Xanadu::strwton(_String);
		auto 		vResult = Xanadu::atol(vNString);
		Xanadu::strfree(vNString);
		return vResult;
	}
	return 0;
}

// converts a byte string to an integer value.
XANADU_CORE_EXPORT long long XANADUAPI Xanadu::atoll(const char* _String) noexcept
{
	if(_String)
	{
		return std::atoll(_String);
	}
	return 0;
}

// converts a byte string to an integer value.
XANADU_CORE_EXPORT long long XANADUAPI Xanadu::wtoll(const wchar_t* _String) noexcept
{
	if(_String)
	{
		auto 		vNString = Xanadu::strwton(_String);
		auto 		vResult = Xanadu::atoll(vNString);
		Xanadu::strfree(vNString);
		return vResult;
	}
	return 0;
}

// converts a byte string to an integer value.
XANADU_CORE_EXPORT long XANADUAPI Xanadu::strtol(const char* _String, char** _StrEnd, int _Base) noexcept
{
	if(_String)
	{
		return std::strtol(_String, _StrEnd, _Base);
	}
	return 0;
}

// converts a wide string to an integer value.
XANADU_CORE_EXPORT long XANADUAPI Xanadu::wcstol(const wchar_t* _String, wchar_t** _StrEnd, int _Base) noexcept
{
	if(_String)
	{
		return std::wcstol(_String, _StrEnd, _Base);
	}
	return 0;
}

// converts a byte string to an integer value.
XANADU_CORE_EXPORT long long XANADUAPI Xanadu::strtoll(const char* _String, char** _StrEnd, int _Base) noexcept
{
	if(_String)
	{
		return std::strtoll(_String, _StrEnd, _Base);
	}
	return 0;
}

// converts a wide string to an integer value.
XANADU_CORE_EXPORT long long XANADUAPI Xanadu::wcstoll(const wchar_t* _String, wchar_t** _StrEnd, int _Base) noexcept
{
	if(_String)
	{
		return std::wcstoll(_String, _StrEnd, _Base);
	}
	return 0;
}

// converts a byte string to an unsigned integer value.
XANADU_CORE_EXPORT unsigned long XANADUAPI Xanadu::strtoul(const char* _String, char** _StrEnd, int _Base) noexcept
{
	if(_String)
	{
		return std::strtoul(_String, _StrEnd, _Base);
	}
	return 0;
}

// converts a wide string to an unsigned integer value.
XANADU_CORE_EXPORT unsigned long XANADUAPI Xanadu::wcstoul(const wchar_t* _String, wchar_t** _StrEnd, int _Base) noexcept
{
	if(_String)
	{
		return std::wcstoul(_String, _StrEnd, _Base);
	}
	return 0;
}

// converts a byte string to an unsigned integer value.
XANADU_CORE_EXPORT unsigned long long XANADUAPI Xanadu::strtoull(const char* _String, char** _StrEnd, int _Base) noexcept
{
	if(_String)
	{
		return std::strtoull(_String, _StrEnd, _Base);
	}
	return 0;
}

// converts a wide string to an unsigned integer value.
XANADU_CORE_EXPORT unsigned long long XANADUAPI Xanadu::wcstoull(const wchar_t* _String, wchar_t** _StrEnd, int _Base) noexcept
{
	if(_String)
	{
		return std::wcstoull(_String, _StrEnd, _Base);
	}
	return 0;
}

// converts a byte string to a floating point value.
XANADU_CORE_EXPORT float XANADUAPI Xanadu::strtof(const char* _String, char** _StrEnd) noexcept
{
	if(_String)
	{
		return std::strtof(_String, _StrEnd);
	}
	return 0.0f;
}

// converts a wide string to a floating point value.
XANADU_CORE_EXPORT float XANADUAPI Xanadu::wcstof(const wchar_t* _String, wchar_t** _StrEnd) noexcept
{
	if(_String)
	{
		return std::wcstof(_String, _StrEnd);
	}
	return 0.0f;
}

// converts a byte string to a floating point value.
XANADU_CORE_EXPORT double XANADUAPI Xanadu::strtod(const char* _String, char** _StrEnd) noexcept
{
	if(_String)
	{
		return std::strtod(_String, _StrEnd);
	}
	return 0.0f;
}

// converts a wide string to a floating point value.
XANADU_CORE_EXPORT double XANADUAPI Xanadu::wcstod(const wchar_t* _String, wchar_t** _StrEnd) noexcept
{
	if(_String)
	{
		return std::wcstod(_String, _StrEnd);
	}
	return 0.0f;
}

// converts a byte string to a floating point value.
XANADU_CORE_EXPORT long double XANADUAPI Xanadu::strtold(const char* _String, char** _StrEnd) noexcept
{
	if(_String)
	{
		return std::strtold(_String, _StrEnd);
	}
	return 0.0f;
}

// converts a wide string to a floating point value.
XANADU_CORE_EXPORT long double XANADUAPI Xanadu::wcstold(const wchar_t* _String, wchar_t** _StrEnd) noexcept
{
	if(_String)
	{
		return std::wcstold(_String, _StrEnd);
	}
	return 0.0f;
}

// converts a byte string to std::intmax_t.
XANADU_CORE_EXPORT std::intmax_t XANADUAPI Xanadu::strtoimax(const char* _String, char** _StrEnd, int _Base) noexcept
{
	if(_String)
	{
		return std::strtoimax(_String, _StrEnd, _Base);
	}
	return 0;
}

// converts a wide string to std::intmax_t.
XANADU_CORE_EXPORT std::intmax_t XANADUAPI Xanadu::wcstoimax(const wchar_t* _String, wchar_t** _StrEnd, int _Base) noexcept
{
	if(_String)
	{
		return std::wcstoimax(_String, _StrEnd, _Base);
	}
	return 0;
}

// converts a byte string to std::uintmax_t.
XANADU_CORE_EXPORT std::uintmax_t XANADUAPI Xanadu::strtoumax(const char* _String, char** _StrEnd, int _Base) noexcept
{
	if(_String)
	{
		return std::strtoumax(_String, _StrEnd, _Base);
	}
	return 0;
}

// converts a wide string to std::uintmax_t.
XANADU_CORE_EXPORT std::uintmax_t XANADUAPI Xanadu::wcstoumax(const wchar_t* _String, wchar_t** _StrEnd, int _Base) noexcept
{
	if(_String)
	{
		return std::wcstoumax(_String, _StrEnd, _Base);
	}
	return 0;
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// String manipulation
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// copies one string to another
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strcpy(char* _Dest, const char* _Src) noexcept
{
	if(_Dest && _Src)
	{
		return std::strcpy(_Dest, _Src);
	}
	return _Dest;
}

// copies one string to another
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strcpy(char* _Dest, std::size_t _Length, const char* _Src) noexcept
{
	if(_Dest && _Src)
	{
		if(Xanadu::strlen(_Src) > _Length)
		{
			return std::strncpy(_Dest, _Src, _Length);
		}
		else
		{
			return std::strcpy(_Dest, _Src);
		}
	}
	return _Dest;
}

// copies one wide string to another
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcscpy(wchar_t* _Dest, const wchar_t* _Src) noexcept
{
	if(_Dest && _Src)
	{
		return std::wcscpy(_Dest, _Src);
	}
	return _Dest;
}

// copies one wide string to another
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcscpy(wchar_t* _Dest, std::size_t _Length, const wchar_t* _Src) noexcept
{
	if(_Dest && _Src)
	{
		if(Xanadu::wcslen(_Src) > _Length)
		{
			return std::wcsncpy(_Dest, _Src, _Length);
		}
		else
		{
			return std::wcscpy(_Dest, _Src);
		}
	}
	return _Dest;
}

// copies a certain amount of characters from one string to another
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strncpy(char* _Dest, const char* _Src, std::size_t _Count) noexcept
{
	if(_Dest && _Src)
	{
		return std::strncpy(_Dest, _Src, _Count);
	}
	return _Dest;
}

// copies a certain amount of characters from one string to another
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strncpy(char* _Dest, std::size_t _Length, const char* _Src, std::size_t _Count) noexcept
{
	if(_Dest && _Src)
	{
		if(_Count > _Length)
		{
			return std::strncpy(_Dest, _Src, _Length);
		}
		else
		{
			return std::strncpy(_Dest, _Src, _Count);
		}
	}
	return _Dest;
}

// copies a certain amount of wide characters from one string to another
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcsncpy(wchar_t* _Dest, const wchar_t* _Src, std::size_t _Count) noexcept
{
	if(_Dest && _Src)
	{
		return std::wcsncpy(_Dest, _Src, _Count);
	}
	return _Dest;
}

// copies a certain amount of wide characters from one string to another
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcsncpy(wchar_t* _Dest, std::size_t _Length, const wchar_t* _Src, std::size_t _Count) noexcept
{
	if(_Dest && _Src)
	{
		if(_Count > _Length)
		{
			return std::wcsncpy(_Dest, _Src, _Length);
		}
		else
		{
			return std::wcsncpy(_Dest, _Src, _Count);
		}
	}
	return _Dest;
}

// concatenates two strings
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strcat(char* _Dest, const char* _Src) noexcept
{
	if(_Dest && _Src)
	{
		return std::strcat(_Dest, _Src);
	}
	return _Dest;
}

// concatenates two strings
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strcat(char* _Dest, std::size_t _Length, const char* _Src) noexcept
{
	if(_Dest && _Src)
	{
		if(Xanadu::strlen(_Src) > _Length)
		{
			return std::strncat(_Dest, _Src, _Length);
		}
		else
		{
			return std::strcat(_Dest, _Src);
		}
	}
	return _Dest;
}

// appends a copy of one wide string to another
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcscat(wchar_t* _Dest, const wchar_t* _Src) noexcept
{
	if(_Dest && _Src)
	{
		return std::wcscat(_Dest, _Src);
	}
	return _Dest;
}

// appends a copy of one wide string to another
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcscat(wchar_t* _Dest, std::size_t _Length, const wchar_t* _Src) noexcept
{
	if(_Dest && _Src)
	{
		if(Xanadu::wcslen(_Src) > _Length)
		{
			return std::wcsncat(_Dest, _Src, _Length);
		}
		else
		{
			return std::wcscat(_Dest, _Src);
		}
	}
	return _Dest;
}

// concatenates a certain amount of characters of two strings
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strncat(char* _Dest, const char* _Src, std::size_t _Count) noexcept
{
	if(_Dest && _Src)
	{
		return std::strncat(_Dest, _Src, _Count);
	}
	return _Dest;
}

// concatenates a certain amount of characters of two strings
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strncat(char* _Dest, std::size_t _Length, const char* _Src, std::size_t _Count) noexcept
{
	if(_Dest && _Src)
	{
		if(_Count > _Length)
		{
			return std::strncat(_Dest, _Src, _Length);
		}
		else
		{
			return std::strncat(_Dest, _Src, _Count);
		}
	}
	return _Dest;
}

// appends a certain amount of wide characters from one wide string to another
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcsncat(wchar_t* _Dest, const wchar_t* _Src, std::size_t _Count) noexcept
{
	if(_Dest && _Src)
	{
		return std::wcsncat(_Dest, _Src, _Count);
	}
	return _Dest;
}

// appends a certain amount of wide characters from one wide string to another
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcsncat(wchar_t* _Dest, std::size_t _Length, const wchar_t* _Src, std::size_t _Count) noexcept
{
	if(_Dest && _Src)
	{
		if(_Count > _Length)
		{
			return std::wcsncat(_Dest, _Src, _Length);
		}
		else
		{
			return std::wcsncat(_Dest, _Src, _Count);
		}
	}
	return _Dest;
}

// transform a string so that strcmp would produce the same result as strcoll
XANADU_CORE_EXPORT std::size_t XANADUAPI Xanadu::strxfrm(char* _Dest, const char* _Src, std::size_t _Count) noexcept
{
	if (_Dest == _Src)
	{
		return 0;
	}
	if (_Dest && _Src)
	{
		return std::strxfrm(_Dest, _Src, _Count);
	}
	else if(_Dest)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

// transform a wide string so that wcscmp would produce the same result as wcscoll
XANADU_CORE_EXPORT std::size_t XANADUAPI Xanadu::wcsxfrm(wchar_t* _Dest, const wchar_t* _Src, std::size_t _Count) noexcept
{
	if (_Dest == _Src)
	{
		return 0;
	}
	if (_Dest && _Src)
	{
		return std::wcsxfrm(_Dest, _Src, _Count);
	}
	else if(_Dest)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// String examination
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// returns the length of a given string
XANADU_CORE_EXPORT std::size_t XANADUAPI Xanadu::strlen(const char* _String) noexcept
{
	if(_String)
	{
		return std::strlen(_String);
	}
	return 0;
}

// returns the length of a wide string
XANADU_CORE_EXPORT std::size_t XANADUAPI Xanadu::wcslen(const wchar_t* _String) noexcept
{
	if(_String)
	{
		return std::wcslen(_String);
	}
	return 0;
}

// compares two strings
XANADU_CORE_EXPORT int XANADUAPI Xanadu::strcmp(const char* lhs, const char* rhs) noexcept
{
	if (lhs == rhs)
	{
		return 0;
	}
	if (lhs && rhs)
	{
		return std::strcmp(lhs, rhs);
	}
	else if(lhs)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

// compares two wide strings
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wcscmp(const wchar_t* lhs, const wchar_t* rhs) noexcept
{
	if (lhs == rhs)
	{
		return 0;
	}
	if (lhs && rhs)
	{
		return std::wcscmp(lhs, rhs);
	}
	else if(lhs)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

// compares a certain number of characters from two strings
XANADU_CORE_EXPORT int XANADUAPI Xanadu::strncmp(const char* lhs, const char* rhs, std::size_t _Count) noexcept
{
	if(lhs == rhs)
	{
		return 0;
	}
	if(lhs && rhs)
	{
		return std::strncmp(lhs, rhs, _Count);
	}
	else if(lhs)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

// compares a certain amount of characters from two wide strings
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wcsncmp(const wchar_t* lhs, const wchar_t* rhs, std::size_t _Count) noexcept
{
	if(lhs == rhs)
	{
		return 0;
	}
	if(lhs && rhs)
	{
		return std::wcsncmp(lhs, rhs, _Count);
	}
	else if(lhs)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

// compares two strings in accordance to the current locale
XANADU_CORE_EXPORT int XANADUAPI Xanadu::strcoll(const char* lhs, const char* rhs) noexcept
{
	if(lhs == rhs)
	{
		return 0;
	}
	if(lhs && rhs)
	{
		return std::strcoll(lhs, rhs);
	}
	else if(lhs)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

// compares two wide strings in accordance to the current locale
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wcscoll(const wchar_t* lhs, const wchar_t* rhs) noexcept
{
	if(lhs == rhs)
	{
		return 0;
	}
	if(lhs && rhs)
	{
		return std::wcscoll(lhs, rhs);
	}
	else if(lhs)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

// finds the first occurrence of a character
XANADU_CORE_EXPORT const char* XANADUAPI Xanadu::strchr(const char* _String, int _Char) noexcept
{
	if(_String)
	{
		return std::strchr(_String, _Char);
	}
	return nullptr;
}

// finds the first occurrence of a wide character in a wide string
XANADU_CORE_EXPORT const wchar_t* XANADUAPI Xanadu::wcschr(const wchar_t* _String, wchar_t _Char) noexcept
{
	if(_String)
	{
		return std::wcschr(_String, _Char);
	}
	return nullptr;
}

// finds the first occurrence of a character
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strchr(char* _String, int _Char) noexcept
{
	if(_String)
	{
		return std::strchr(_String, _Char);
	}
	return nullptr;
}

// finds the first occurrence of a wide character in a wide string
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcschr(wchar_t* _String, wchar_t _Char) noexcept
{
	if(_String)
	{
		return std::wcschr(_String, _Char);
	}
	return nullptr;
}

// finds the last occurrence of a character
XANADU_CORE_EXPORT const char* XANADUAPI Xanadu::strrchr(const char* _String, int _Char) noexcept
{
	if(_String)
	{
		return std::strrchr(_String, _Char);
	}
	return nullptr;
}

// finds the first occurrence of a wide character in a wide string
XANADU_CORE_EXPORT const wchar_t* XANADUAPI Xanadu::wcsrchr(const wchar_t* _String, wchar_t _Char) noexcept
{
	if(_String)
	{
		return std::wcsrchr(_String, _Char);
	}
	return nullptr;
}

// finds the last occurrence of a character
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strrchr(char* _String, int _Char) noexcept
{
	if(_String)
	{
		return std::strrchr(_String, _Char);
	}
	return nullptr;
}

// finds the first occurrence of a wide character in a wide string
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcsrchr(wchar_t* _String, wchar_t _Char) noexcept
{
	if(_String)
	{
		return std::wcsrchr(_String, _Char);
	}
	return nullptr;
}

// returns the length of the maximum initial segment that consists of only the characters found in another byte string
XANADU_CORE_EXPORT size_t XANADUAPI Xanadu::strspn(const char* _Dest, const char* _String) noexcept
{
	return std::strspn(_Dest, _String);
}

// returns the length of the maximum initial segment that consists of only the wide characters found in another wide string
XANADU_CORE_EXPORT size_t XANADUAPI Xanadu::wcsspn(const wchar_t* _Dest, const wchar_t* _String) noexcept
{
	return std::wcsspn(_Dest, _String);
}

// returns the length of the maximum initial segment that consists of only the characters not found in another byte string
XANADU_CORE_EXPORT size_t XANADUAPI Xanadu::strcspn(const char* _Dest, const char* _String) noexcept
{
	return std::strcspn(_Dest, _String);
}

// returns the length of the maximum initial segment that consists of only the wide not found in another wide string
XANADU_CORE_EXPORT std::size_t XANADUAPI Xanadu::wcscspn(const wchar_t* _Dest, const wchar_t* _String) noexcept
{
	return std::wcscspn(_Dest, _String);
}

// finds the first location of any character from a set of separators
XANADU_CORE_EXPORT const char* XANADUAPI Xanadu::strpbrk(const char* _Dest, const char* _BreakSet) noexcept
{
	return std::strpbrk(_Dest, _BreakSet);
}

// finds the first location of any wide character in one wide string, in another wide string
XANADU_CORE_EXPORT const wchar_t* XANADUAPI Xanadu::wcspbrk(const wchar_t* _Dest, const wchar_t* _BreakSet) noexcept
{
	return std::wcspbrk(_Dest, _BreakSet);
}

// finds the first location of any character from a set of separators
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strpbrk(char* _Dest, const char* _BreakSet) noexcept
{
	return std::strpbrk(_Dest, _BreakSet);
}

// finds the first location of any wide character in one wide string, in another wide string
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcspbrk(wchar_t* _Dest, const wchar_t* _BreakSet) noexcept
{
	return std::wcspbrk(_Dest, _BreakSet);
}

// finds the first occurrence of a substring of characters
XANADU_CORE_EXPORT const char* XANADUAPI Xanadu::strstr(const char* _String, const char* _SubStr) noexcept
{
	if(_String && _SubStr)
	{
		return std::strstr(_String, _SubStr);
	}
	return nullptr;
}

// finds the first occurrence of a wide string within another wide string
XANADU_CORE_EXPORT const wchar_t* XANADUAPI Xanadu::wcsstr(const wchar_t* _String, const wchar_t* _SubStr) noexcept
{
	if(_String && _SubStr)
	{
		return std::wcsstr(_String, _SubStr);
	}
	return nullptr;
}

// finds the first occurrence of a substring of characters
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strstr(char* _String, const char* _SubStr) noexcept
{
	if(_String && _SubStr)
	{
		return std::strstr(_String, _SubStr);
	}
	return nullptr;
}

// finds the first occurrence of a wide string within another wide string
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcsstr(wchar_t* _String, const wchar_t* _SubStr) noexcept
{
	if(_String && _SubStr)
	{
		return std::wcsstr(_String, _SubStr);
	}
	return nullptr;
}

// finds the next token in a byte string
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strtok(char* _String, const char* _Delim) noexcept
{
	return std::strtok(_String, _Delim);
}

// finds the next token in a wide string
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcstok(wchar_t* _String, const wchar_t* _Delim, wchar_t** _Ptr) noexcept
{
	return std::wcstok(_String, _Delim, _Ptr);
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Xanadu: String extend
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// Ignore case comparison strings
XANADU_CORE_EXPORT int XANADUAPI Xanadu::strcasecmp(const char* _String1, const char* _String2) noexcept
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

// Ignore case comparison strings
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wcscasecmp(const wchar_t* _String1, const wchar_t* _String2) noexcept
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

// Copy a string
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strdup(const char* _String) noexcept
{
	if(_String)
	{
		auto		vLength = Xanadu::strlen(_String) + 1;
		auto		vMemory = (char*)Xanadu::malloc(vLength);
		if(vMemory)
		{
			Xanadu::memcpy(vMemory, _String, vLength);
			vMemory[vLength - 1] = '\0';
			return vMemory;
		}
	}
	return nullptr;
}

// Copy a string
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcsdup(const wchar_t* _String) noexcept
{
	if(_String)
	{
		auto		vLength = Xanadu::wcslen(_String) + 1;
		auto		vMemory = (wchar_t*)Xanadu::malloc(vLength * sizeof(wchar_t));
		if(vMemory)
		{
			Xanadu::wmemcpy(vMemory, _String, vLength);
			vMemory[vLength - 1] = L'\0';
			return vMemory;
		}
	}
	return nullptr;
}

// Releases a string created by strdup
XANADU_CORE_EXPORT void XANADUAPI Xanadu::strfree(char* _String) noexcept
{
	if(_String)
	{
		Xanadu::free(_String);
	}
}

// Releases a string created by wcsdup
XANADU_CORE_EXPORT void XANADUAPI Xanadu::wcsfree(wchar_t* _String) noexcept
{
	if(_String)
	{
		Xanadu::free(_String);
	}
}

// Convert string to lowercase
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strlower(char* _String) noexcept
{
	return Xanadu::strlower(_String, Xanadu::strlen(_String));
}

// Convert string to lowercase
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strlower(char* _String, size_t _Count) noexcept
{
	if (_String && _Count)
	{
		for (auto vIndex = 0U; vIndex < _Count; ++vIndex)
		{
			_String[vIndex] = (char)Xanadu::tolower(_String[vIndex]);
		}
	}
	return _String;
}

// Convert string to uppercase
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strupper(char* _String) noexcept
{
	return Xanadu::strupper(_String, Xanadu::strlen(_String));
}

// Convert string to uppercase
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strupper(char* _String, size_t _Count) noexcept
{
	if(_String && _Count)
	{
		for(auto vIndex = 0U; vIndex < _Count; ++vIndex)
		{
			_String[vIndex] = (char)Xanadu::toupper(_String[vIndex]);
		}
	}
	return _String;
}

// Convert string to lowercase
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcslower(wchar_t* _String) noexcept
{
	return Xanadu::wcslower(_String, Xanadu::wcslen(_String));
}

// Convert string to lowercase
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcslower(wchar_t* _String, size_t _Count) noexcept
{
	if(_String && _Count)
	{
		for(auto vIndex = 0U; vIndex < _Count; ++vIndex)
		{
			_String[vIndex] = Xanadu::towlower(_String[vIndex]);
		}
	}
	return _String;
}

// Convert string to uppercase
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcsupper(wchar_t* _String) noexcept
{
	return Xanadu::wcsupper(_String, Xanadu::wcslen(_String));
}

// Convert string to uppercase
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcsupper(wchar_t* _String, size_t _Count) noexcept
{
	if(_String && _Count)
	{
		for(auto vIndex = 0U; vIndex < _Count; ++vIndex)
		{
			_String[vIndex] = Xanadu::towupper(_String[vIndex]);
		}
	}
	return _String;
}

// Convert UNICODE string to ASCII
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strwtoa(const wchar_t* _String) noexcept
{
	if(_String)
	{
		auto		_DestSize = static_cast<unsigned int>(4 * Xanadu::wcslen(_String) + 1);
		auto		_Dest = (char*)Xanadu::malloc(_DestSize);
		if(_Dest)
		{
			Xanadu::memset(_Dest, 0, _DestSize);
			Xanadu::wcstombs(_Dest, _String, _DestSize);
			return _Dest;
		}
	}
	return nullptr;
}

// Convert UNICODE string to UTF-8
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strwtou(const wchar_t* _String) noexcept
{
	if(_String)
	{
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
	return nullptr;
}

// Convert UNICODE string to Native String(Windows:ASCII/Other:UTF-8)
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strwton(const wchar_t* _String) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return Xanadu::strwtoa(_String);
#else
	return Xanadu::strwtou(_String);
#endif
}

// Convert ASCII string to UNICODE
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::stratow(const char* _String) noexcept
{
	if(_String)
	{
		auto		_Dsize = static_cast<unsigned int>(Xanadu::strlen(_String) + 1);
		auto		_Dest = (wchar_t*)Xanadu::malloc(sizeof(wchar_t) * _Dsize);
		if(_Dest)
		{
			Xanadu::wmemset(_Dest, 0, _Dsize);
			Xanadu::mbstowcs(_Dest, _String, _Dsize);
			return _Dest;
		}
	}
	return nullptr;
}

// Convert UTF-8 string to UNICODE
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::strutow(const char* _String) noexcept
{
	if(_String)
	{
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
	return nullptr;
}

// Convert Native String(Windows:ASCII/Other:UTF-8) string to UNICODE
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::strntow(const char* _String) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return Xanadu::stratow(_String);
#else
	return Xanadu::strutow(_String);
#endif
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Compute absolute value
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// Returns the absolute value of the specified value.
XANADU_CORE_EXPORT char XANADUAPI Xanadu::abs(char _X) noexcept
{
	return static_cast<char>(std::abs(_X));
}

// Returns the absolute value of the specified value.
XANADU_CORE_EXPORT short XANADUAPI Xanadu::abs(short _X) noexcept
{
	return static_cast<short>(std::abs(_X));
}

// Returns the absolute value of the specified value.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::abs(int _X) noexcept
{
	return std::abs(_X);
}

// Returns the absolute value of the specified value.
XANADU_CORE_EXPORT long XANADUAPI Xanadu::abs(long _X) noexcept
{
	return std::labs(_X);
}

// Returns the absolute value of the specified value.
XANADU_CORE_EXPORT long long XANADUAPI Xanadu::abs(long long _X) noexcept
{
	return std::llabs(_X);
}

// Returns the absolute value of the specified value.
XANADU_CORE_EXPORT float XANADUAPI Xanadu::abs(float _X) noexcept
{
	return std::fabsf(_X);
}

// Returns the absolute value of the specified value.
XANADU_CORE_EXPORT double XANADUAPI Xanadu::abs(double _X) noexcept
{
	return std::fabs(_X);
}

// Returns the absolute value of the specified value.
XANADU_CORE_EXPORT long double XANADUAPI Xanadu::abs(long double _X) noexcept
{
	return std::fabsl(_X);
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Dynamic library operation
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// Loading dynamic library
XANADU_CORE_EXPORT HANDLE XANADUAPI Xanadu::LoadLibraryA(const char* _LibraryFile) noexcept
{
	if(_LibraryFile)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return (HANDLE)::LoadLibraryA(_LibraryFile);
#else
		return Xanadu::dlopen(_LibraryFile, RTLD_NOW);
#endif
	}
	return nullptr;
}

// Loading dynamic library
XANADU_CORE_EXPORT HANDLE XANADUAPI Xanadu::LoadLibraryW(const wchar_t* _LibraryFile) noexcept
{
	if(_LibraryFile)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return (HANDLE)::LoadLibraryW(_LibraryFile);
#else
		auto 		vNLibraryFile = Xanadu::strwton(_LibraryFile);
		if(vNLibraryFile)
		{
			auto 		vResult = Xanadu::dlopen(vNLibraryFile, RTLD_NOW);
			Xanadu::strfree(vNLibraryFile);
			return vResult;
		}
#endif
	}
	return nullptr;
}

// Finding function address from dynamic library
XANADU_CORE_EXPORT void* XANADUAPI Xanadu::GetProcAddress(HANDLE _Handle, const char* _ProcName) noexcept
{
	if(_Handle && _ProcName)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return (void*)::GetProcAddress((HMODULE)_Handle, _ProcName);
#else
		return (void*)::dlsym(_Handle, _ProcName);
#endif
	}
	return nullptr;
}

// Close dynamic library
XANADU_CORE_EXPORT bool XANADUAPI Xanadu::FreeLibrary(HANDLE _Handle) noexcept
{
	if(_Handle)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return ::FreeLibrary((HMODULE)_Handle);
#else
		return ::dlclose(_Handle) == 0;
#endif
	}
	return false;
}

// Loading dynamic library
XANADU_CORE_EXPORT HANDLE XANADUAPI Xanadu::dlopen(const char* _LibraryFile, int _Mode) noexcept
{
	if(_LibraryFile)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return Xanadu::LoadLibraryA(_LibraryFile);
#else
		return (HANDLE)::dlopen(_LibraryFile, _Mode);
#endif
	}
	return nullptr;
}

// Finding function address from dynamic library
XANADU_CORE_EXPORT void* XANADUAPI Xanadu::dlsym(HANDLE _Handle, const char* _ProcName) noexcept
{
	if(_Handle && _ProcName)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return (void*)::GetProcAddress((HMODULE)_Handle, _ProcName);
#else
		return (void*)::dlsym(_Handle, _ProcName);
#endif
	}
	return nullptr;
}

// Close dynamic library
XANADU_CORE_EXPORT int XANADUAPI Xanadu::dlclose(HANDLE _Handle) noexcept
{
	if(_Handle)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return ::FreeLibrary((HMODULE)_Handle);
#else
		return ::dlclose(_Handle) == 0;
#endif
	}
	return false;
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// C library locales
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// gets and sets the current C locale
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::setlocale(int _Category, const char* _Locale) noexcept
{
	return std::setlocale(_Category, _Locale);
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Multibyte/wide character conversions
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// converts a wide string to narrow multibyte character string
// https://en.cppreference.com/w/cpp/string/multibyte/wcstombs
XANADU_CORE_EXPORT std::size_t XANADUAPI Xanadu::wcstombs(char* _MBS, const wchar_t* _WCS, std::size_t _Length) noexcept
{
	if(_WCS)
	{
		return std::wcstombs(_MBS, _WCS, _Length);
	}
	return 0;
}

// converts a narrow multibyte character string to wide string
// https://en.cppreference.com/w/cpp/string/multibyte/mbstowcs
XANADU_CORE_EXPORT std::size_t XANADUAPI Xanadu::mbstowcs(wchar_t* _WCS, const char* _MBS, std::size_t _Length) noexcept
{
	if(_WCS)
	{
		return std::mbstowcs(_WCS, _MBS, _Length);
	}
	return 0;
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// C random library
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// seeds pseudo-random number generator
XANADU_CORE_EXPORT void XANADUAPI Xanadu::srand(unsigned int _Seed) noexcept
{
	return std::srand(_Seed);
}

// generates a pseudo-random number
XANADU_CORE_EXPORT int XANADUAPI Xanadu::rand() noexcept
{
	return std::rand();
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// C sleep library
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// Sleep by the specified number of seconds
XANADU_CORE_EXPORT unsigned int XANADUAPI Xanadu::sleep(unsigned int _Seconds) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return Xanadu::msleep(_Seconds * 1000);
#else
	return ::sleep(_Seconds);
#endif
}

// Sleep by the specified number of milliseconds
XANADU_CORE_EXPORT unsigned int XANADUAPI Xanadu::msleep(unsigned int _Milliseconds) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	//std::this_thread::sleep_for(std::chrono::milliseconds(_Milliseconds));
	::Sleep(_Milliseconds);
	return 0;
#else
	return ::usleep(_Milliseconds * 1000) / 1000;
#endif
}

// Sleep by the specified number of microseconds
XANADU_CORE_EXPORT unsigned int XANADUAPI Xanadu::usleep(unsigned int _Microseconds) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
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





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Time manipulation
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// computes the difference between times
XANADU_CORE_EXPORT double XANADUAPI Xanadu::difftime(std::time_t _TimeEnd, std::time_t _TimeBegin) noexcept
{
	return std::difftime(_TimeEnd, _TimeBegin);
}

// returns the current time of the system as time since epoch
XANADU_CORE_EXPORT std::time_t XANADUAPI Xanadu::time(std::time_t* _Arg) noexcept
{
	return std::time(_Arg);
}

// returns raw processor clock time since the program is started
XANADU_CORE_EXPORT std::clock_t XANADUAPI Xanadu::clock() noexcept
{
	return std::clock();
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Format conversions
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// converts a tm object to a textual representation
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::asctime(const std::tm* _Time) noexcept
{
	return std::asctime(_Time);
}

// converts a time_t object to a textual representation
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::ctime(const std::time_t* _Time) noexcept
{
	return std::ctime(_Time);
}

// converts a tm object to custom textual representation
XANADU_CORE_EXPORT std::size_t XANADUAPI Xanadu::strftime(char* _String, std::size_t _Count, const char* _Format, const std::tm* _Time) noexcept
{
	return std::strftime(_String, _Count, _Format, _Time);
}

// converts a tm object to custom wide string textual representation
XANADU_CORE_EXPORT std::size_t XANADUAPI Xanadu::wcsftime(wchar_t* _String, std::size_t _Count, const wchar_t* _Format, const std::tm* _Time) noexcept
{
	return std::wcsftime(_String, _Count, _Format, _Time);
}

// converts time since epoch to calendar time expressed as Universal Coordinated Time
XANADU_CORE_EXPORT std::tm* XANADUAPI Xanadu::gmtime(const std::time_t* _Time) noexcept
{
	return std::gmtime(_Time);
}

// converts time since epoch to calendar time expressed as local time
XANADU_CORE_EXPORT std::tm* XANADUAPI Xanadu::localtime(const std::time_t* _Time) noexcept
{
	return std::localtime(_Time);
}

// converts calendar time to time since epoch
XANADU_CORE_EXPORT std::time_t XANADUAPI Xanadu::mktime(std::tm* _Time) noexcept
{
	return std::mktime(_Time);
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Process operation
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// Analytic parameters
static std::list<std::string> XanaduParseCombinedArgString(const std::string& _Program)
{
	auto		vArgs = std::list<std::string>();
	auto 		vTemp = std::string();
	auto		vQuoteCount = 0;
	auto		vInQuote = false;

	// handle quoting. tokens can be surrounded by double quotes
	// "hello world". three consecutive double quotes represent
	// the quote character itself.
	for (char vIndex : _Program)
	{
		if (vIndex == '\"')
		{
			++vQuoteCount;
			if (vQuoteCount == 3)
			{
				// third consecutive quote
				vQuoteCount = 0;
				vTemp += vIndex;
			}
			continue;
		}
		if (vQuoteCount)
		{
			if (vQuoteCount == 1)
			{
				vInQuote = !vInQuote;
			}
			vQuoteCount = 0;
		}
		if (!vInQuote && vIndex == ' ')
		{
			if (!vTemp.empty())
			{
				vArgs.push_back(vTemp);
				vTemp.clear();
			}
		}
		else
		{
			vTemp += vIndex;
		}
	}
	if (!vTemp.empty())
	{
		vArgs.push_back(vTemp);
	}
	return vArgs;
}

// Creates a pipe and executes a command.
XANADU_CORE_EXPORT FILE* XANADUAPI Xanadu::popen(const char* _Command, const char* _Mode) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_popen(_Command, _Mode);
#else
	return ::popen(_Command, _Mode);
#endif
}

// Waits for a new command processor and closes the stream on the associated pipe.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::pclose(FILE* _Stream) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_pclose(_Stream);
#else
	return ::pclose(_Stream);
#endif
}

// Loads and executes new child processes.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::execds(const char* _Application, const char* _Directory, const char* _Param) noexcept
{
	auto		vResult = -1;
	auto		vArgs = XanaduParseCombinedArgString(_Param ? _Param : "");
	auto		vCount = vArgs.size() + 2;
	auto		vList = (char**)Xanadu::malloc(vCount);
	if(vList)
	{
		Xanadu::memset(vList, 0, sizeof(char*) * vCount);
		vList[0] = Xanadu::strdup(_Application);

		// 开始格式化参数
		auto		vArgIndex = 1;
		for(auto vIterator = vArgs.begin(); vIterator != vArgs.end(); ++vIterator)
		{
			if(!vIterator->empty())
			{
				vList[vArgIndex] = (char*)Xanadu::malloc(vIterator->size() + 1);
				Xanadu::strcpy(vList[vArgIndex], vIterator->data());
				vList[vArgIndex][vIterator->size()] = '\0';
			}
			++vArgIndex;
		}
	}

	// 我们需要改变工作目录
	Xanadu::chdir(_Directory);

	// 在这里调用exec系列函数
#if defined(_XANADU_SYSTEM_WINDOWS)
	vResult = ::_execv(_Application, vList);
#else
	vResult = ::execv(_Application, vList);
#endif

	// 释放参数列表
	if(vList)
	{
		Xanadu::strfree(vList[0]);
		for(auto vIndex = 1U; vIndex < vCount; ++vIndex)
		{
			Xanadu::free(vList[vIndex]);
		}
		Xanadu::free(vList);
	}
	return vResult;
}

// causes abnormal program termination (without cleaning up)
XANADU_CORE_EXPORT void XANADUAPI Xanadu::abort() noexcept
{
	std::abort();
}

// causes normal program termination with cleaning up
XANADU_CORE_EXPORT void XANADUAPI Xanadu::exit(int _Status) noexcept
{
	std::exit(_Status);
}

// causes quick program termination without completely cleaning up
XANADU_CORE_EXPORT void XANADUAPI Xanadu::quick_exit(int _ExitCode) noexcept
{
	std::quick_exit(_ExitCode);
}

// registers a function to be called on std::exit() invocation
XANADU_CORE_EXPORT int XANADUAPI Xanadu::atexit(_Function_atexit _Function) noexcept
{
	return std::atexit(_Function);
}

// registers a function to be called on quick_exit invocation
XANADU_CORE_EXPORT int XANADUAPI Xanadu::at_quick_exit(_Function_at_quick_exit _Function) noexcept
{
	return std::at_quick_exit(_Function);
}

// This function returns the process identifier of the calling process.
XANADU_CORE_EXPORT unsigned long XANADUAPI Xanadu::GetCurrentProcessId() noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::GetCurrentProcessId();
#else
	return static_cast<unsigned long>(Xanadu::getpid());
#endif
}

// This function returns the process identifier of the calling process.
XANADU_CORE_EXPORT long XANADUAPI Xanadu::getpid() noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return static_cast<long>(::GetCurrentProcessId());
#else
	return ::getpid();
#endif
}

// Kill the process with the specified ID
XANADU_CORE_EXPORT int XANADUAPI Xanadu::kill(long _ProcessID, int _Signal) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	auto		vSync = FALSE;
	auto		vProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, _ProcessID);
	if(vProcess)
	{
		vSync = ::TerminateProcess(vProcess, _Signal);
		CloseHandle(vProcess);
	}
	return vSync == FALSE ? -1 : 0;
#else
	return ::kill(_ProcessID, _Signal);
#endif
}

// Gets the current working directory.
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::getcwd(char* _Buffer, size_t _Size) noexcept
{
	if(_Buffer)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return ::_getcwd(_Buffer, _Size);
#else
		return ::getcwd(_Buffer, _Size);
#endif
	}
	return nullptr;
}

// Gets the current working directory.
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wgetcwd(wchar_t* _Buffer, size_t _Size) noexcept
{
	if(_Buffer)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return ::_wgetcwd(_Buffer, _Size);
#else
		auto		vSync = static_cast<wchar_t*>(nullptr);
		auto		vNChar = (char*)Xanadu::malloc(_Size);
		if(vNChar)
		{
			if(::getcwd(vNChar, _Size))
			{
				auto		vWChar = Xanadu::strntow(vNChar);
				if(vWChar)
				{
					Xanadu::wmemcpy(_Buffer, vWChar, _Size);
					vSync = _Buffer;
					Xanadu::wcsfree(vWChar);
				}
			}
			Xanadu::free(vNChar);
		}
		// errno = ENOMEM;
		return vSync;
#endif
	}
	return nullptr;
}

// Changes the current directory for the current process.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::chdir(const char* _Dirname) noexcept
{
	if(_Dirname)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return Xanadu::SetCurrentDirectoryA(_Dirname) ? 0 : -1;
#else
		return ::chdir(_Dirname);
#endif
	}
	return -1;
}

// Changes the current directory for the current process.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wchdir(const wchar_t* _Dirname) noexcept
{
	if(_Dirname)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return Xanadu::SetCurrentDirectoryW(_Dirname) ? 0 : -1;
#else
		auto		vNDirname = Xanadu::strwton(_Dirname);
		if(vNDirname)
		{
			auto		vChdir = ::chdir(vNDirname);
			Xanadu::strfree(vNDirname);
			return vChdir;
		}
		return ENOMEM;
#endif
	}
	return -1;
}

// Gets the current working directory.
XANADU_CORE_EXPORT unsigned long XANADUAPI Xanadu::GetCurrentDirectoryA(unsigned long _Length, char* _Buffer) noexcept
{
	if(_Buffer && _Length)
	{
		Xanadu::memset(_Buffer, 0, _Length);
#if defined(_XANADU_SYSTEM_WINDOWS)
		return ::GetCurrentDirectoryA(_Length, _Buffer);
#else
		if(Xanadu::getcwd(_Buffer, _Length))
		{
			return Xanadu::strlen(_Buffer);
		}
		return 0;
#endif
	}
	return 0;
}

// Gets the current working directory.
XANADU_CORE_EXPORT unsigned long XANADUAPI Xanadu::GetCurrentDirectoryW(unsigned long _Length, wchar_t* _Buffer) noexcept
{
	if(_Buffer && _Length)
	{
		Xanadu::wmemset(_Buffer, 0, _Length);
#if defined(_XANADU_SYSTEM_WINDOWS)
		return ::GetCurrentDirectoryW(_Length, _Buffer);
#else
		char		vABuffer[XANADU_PATH] = {0};
		if(Xanadu::getcwd(vABuffer, XANADU_PATH))
		{
			auto	vWBuffer = Xanadu::strntow(vABuffer);
			if(vWBuffer)
			{
				Xanadu::wcsncpy(_Buffer, vWBuffer, _Length);
				Xanadu::wcsfree(vWBuffer);
				return Xanadu::wcslen(_Buffer);
			}
		}
		return 0;
#endif
	}
	return 0;
}

// Changes the current directory for the current process.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::SetCurrentDirectoryA(const char* _PathName) noexcept
{
	if(_PathName)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return ::SetCurrentDirectoryA(_PathName);
#else
		return  Xanadu::chdir(_PathName) == 0 ? 1 : 0;
#endif
	}
	return 0;
}

// Changes the current directory for the current process.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::SetCurrentDirectoryW(const wchar_t* _PathName) noexcept
{
	if(_PathName)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return ::SetCurrentDirectoryW(_PathName);
#else
		return Xanadu::wchdir(_PathName) == 0 ? 1 : 0;
#endif
	}
	return 0;
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Thread operation
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// This function returns the thread identifier
XANADU_CORE_EXPORT unsigned long XANADUAPI Xanadu::GetCurrentThreadId() noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::GetCurrentThreadId();
#else
	return (unsigned long)(Xanadu::gettid());
#endif
}

// This function returns the thread identifier
XANADU_CORE_EXPORT pthread_t XANADUAPI Xanadu::gettid() noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return (pthread_t)(Xanadu::GetCurrentThreadId());
#else
	return ::pthread_self();
#endif
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Program support utilities
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// Calls the host environment's command processor (e.g. /bin/sh, cmd.exe, command.com) with the parameter command.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::system(const char* _Command) noexcept
{
	if(_Command)
	{
		return std::system(_Command);
	}
	return -1;
}

// Calls the host environment's command processor (e.g. /bin/sh, cmd.exe, command.com) with the parameter command.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wsystem(const wchar_t* _Command) noexcept
{
	if(_Command)
	{
		auto 		vNCommand = Xanadu::strwton(_Command);
		if(vNCommand)
		{
			auto 		vResult = std::system(vNCommand);
			Xanadu::strfree(vNCommand);
			return vResult;
		}
	}
	return -1;
}

// Returns a pointer to the textual description of the system error code errnum
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::strerror(int _Error) noexcept
{
	return std::strerror(_Error);
}

// Returns a pointer to the textual description of the system error code errnum
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wcserror(int _Error) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_wcserror(_Error);
#else
	static wchar_t*		_staticStringError = nullptr;
	auto			vMessage = std::strerror(_Error);
	if(vMessage)
	{
		if(_staticStringError)
		{
			Xanadu::wcsfree(_staticStringError);
			_staticStringError = nullptr;
		}
		_staticStringError = Xanadu::strntow(vMessage);
		return _staticStringError;
	}
	return nullptr;
#endif
}

// be used to direct the operating system to flush all file system data to disk
XANADU_CORE_EXPORT void XANADUAPI Xanadu::sync() noexcept
{
#if !defined(_XANADU_SYSTEM_WINDOWS)
	::sync();
#endif
}

// get an identifier for the current host
XANADU_CORE_EXPORT long long XANADUAPI Xanadu::gethostid() noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	auto		vHostID = 0ULL;
	auto 		vLength = (ULONG)(sizeof(IP_ADAPTER_ADDRESSES));
	auto 		vAddresses = (IP_ADAPTER_ADDRESSES*)Xanadu::malloc(vLength);
	if(vAddresses)
	{
		// 对GetAdaptersAddresses进行初始调用，以获得所需要的内存大小
		if(::GetAdaptersAddresses(AF_UNSPEC, 0, nullptr, vAddresses, &vLength) == ERROR_BUFFER_OVERFLOW)
		{
			Xanadu::free(vAddresses);
			vAddresses = (IP_ADAPTER_ADDRESSES*)Xanadu::malloc(vLength);
			if(vAddresses)
			{
				if(::GetAdaptersAddresses(AF_UNSPEC, 0, nullptr, vAddresses, &vLength) == NO_ERROR)
				{
					// 如果成功，从接收到的数据中取出第一个网卡，并转换为HostID
					for(auto vIterator = vAddresses; vIterator && vHostID == 0ULL; vIterator = vIterator->Next)
					{
						// 确保MAC地址的长度为 00-00-00-00-00-00
						if(vIterator->PhysicalAddressLength == 6)
						{
							for(auto vIndex = 0; vIndex < 6; ++vIndex)
							{
								vHostID = vHostID << 8;
								vHostID += vIterator->PhysicalAddress[vIndex];
							}
						}
					}
				}
				Xanadu::free(vAddresses);
			}
		}
		else
		{
			Xanadu::free(vAddresses);
		}
	}
	return vHostID;
#else
	return static_cast<int64S>(gethostid());
#endif
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Memory map file
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

#if !defined(FILE_MAP_EXECUTE)
#define FILE_MAP_EXECUTE    0x0020
#endif

#if defined(_XANADU_COMPILE_MSVC)
static int __map_mman_error(const DWORD _Error, const int _Default)
{
	XANADU_UNPARAMETER(_Default);
	if(_Error == 0)
	{
		return 0;
	}
	return _Error;
}

static DWORD __map_mmap_prot_page(const int _Prot)
{
	auto		vProtect = DWORD(0);
	if(_Prot == PROT_NONE)
	{
		return vProtect;
	}
	if((_Prot & PROT_EXEC) != 0)
	{
		vProtect = ((_Prot & PROT_WRITE) != 0) ? PAGE_EXECUTE_READWRITE : PAGE_EXECUTE_READ;
	}
	else
	{
		vProtect = ((_Prot & PROT_WRITE) != 0) ? PAGE_READWRITE : PAGE_READONLY;
	}
	return vProtect;
}

static DWORD __map_mmap_prot_file(const int _Prot)
{
	auto		vDesiredAccess = DWORD(0);
	if(_Prot == PROT_NONE)
	{
		return vDesiredAccess;
	}
	if((_Prot & PROT_READ) != 0)
	{
		vDesiredAccess |= FILE_MAP_READ;
	}
	if((_Prot & PROT_WRITE) != 0)
	{
		vDesiredAccess |= FILE_MAP_WRITE;
	}
	if((_Prot & PROT_EXEC) != 0)
	{
		vDesiredAccess |= FILE_MAP_EXECUTE;
	}
	return vDesiredAccess;
}
#endif

// creates  a  new  mapping  in the virtual address space of the calling process.
XANADU_CORE_EXPORT void* XANADUAPI Xanadu::mmap(void* _Addr, size_t _Length, int _Prot, int _Flags, int _Fildes, off_t _Off) noexcept
{
#if defined(_XANADU_COMPILE_MSVC)
	XANADU_UNPARAMETER(_Addr);

	auto		vFileMap = static_cast<HANDLE>(INVALID_HANDLE_VALUE);
	auto		vHandle = static_cast<HANDLE>(INVALID_HANDLE_VALUE);
	auto		vMap = MAP_FAILED;
	auto		vFileOffsetLow = static_cast<DWORD>(_Off);
	auto		vFileOffsetHigh = static_cast<DWORD>(0);
	auto		vProtect = __map_mmap_prot_page(_Prot);
	auto		vDesiredAccess = __map_mmap_prot_file(_Prot);
	auto		vMaxSize = _Off + (off_t)_Length;
	auto		vMaxSizeLow = static_cast<DWORD>(vMaxSize);
	auto		vMaxSizeHigh = static_cast<DWORD>(0);

	errno = 0;

	if(_Length == 0 || (_Flags & MAP_FIXED) != 0/* Unsupported flag combinations */ || _Prot == PROT_EXEC/* Usupported protection combinations */)
	{
		errno = EINVAL;
		return MAP_FAILED;
	}

	vHandle = ((_Flags & MAP_ANONYMOUS) == 0) ? (HANDLE)_get_osfhandle(_Fildes) : INVALID_HANDLE_VALUE;

	if((_Flags & MAP_ANONYMOUS) == 0 && vHandle == INVALID_HANDLE_VALUE)
	{
		errno = EBADF;
		return MAP_FAILED;
	}

	vFileMap = CreateFileMappingA(vHandle, nullptr, vProtect, vMaxSizeHigh, vMaxSizeLow, nullptr);

	if(vFileMap == nullptr)
	{
		errno = __map_mman_error(GetLastError(), EPERM);
		return MAP_FAILED;
	}

	vMap = MapViewOfFile(vFileMap, vDesiredAccess, vFileOffsetHigh, vFileOffsetLow, _Length);

	CloseHandle(vFileMap);

	if(vMap == nullptr)
	{
		errno = __map_mman_error(GetLastError(), EPERM);
		return MAP_FAILED;
	}
	return vMap;
#else
	return ::mmap(_Addr, _Length, _Prot, _Flags, _Fildes, _Off);
#endif
}

// deletes the mappings for the specified address range
XANADU_CORE_EXPORT int XANADUAPI Xanadu::munmap(void* _Addr, size_t _Length) noexcept
{
#if defined(_XANADU_COMPILE_MSVC)
	XANADU_UNPARAMETER(_Length);

	if(UnmapViewOfFile(_Addr))
	{
		return 0;
	}
	errno = __map_mman_error(GetLastError(), EPERM);
	return -1;
#else
	return ::munmap(_Addr, _Length);
#endif
}

// changes  protection  for the calling process's memory page(s) containing any part of the address range in the interval [addr, addr+len-1].
XANADU_CORE_EXPORT int XANADUAPI Xanadu::mprotect(void* _Addr, size_t _Length, int _Prot) noexcept
{
#if defined(_XANADU_COMPILE_MSVC)
	auto		vNewProtect = __map_mmap_prot_page(_Prot);
	auto		vOldProtect = DWORD(0);

	if(VirtualProtect(_Addr, _Length, vNewProtect, &vOldProtect))
	{
		return 0;
	}
	errno = __map_mman_error(GetLastError(), EPERM);
	return -1;
#else
	return ::mprotect(_Addr, _Length, _Prot);
#endif
}

// flushes changes made to the in-core copy of a file that was mapped into memory using mmap back to the filesystem.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::msync(void* _Addr, size_t _Length, int _Flags) noexcept
{
#if defined(_XANADU_COMPILE_MSVC)
	XANADU_UNPARAMETER(_Flags);

	if(FlushViewOfFile(_Addr, _Length))
	{
		return 0;
	}
	errno = __map_mman_error(GetLastError(), EPERM);
	return -1;
#else
	return ::msync(_Addr, _Length, _Flags);
#endif
}

// lock part or all of the calling process's virtual address space into RAM
XANADU_CORE_EXPORT int XANADUAPI Xanadu::mlock(const void* _Addr, size_t _Length) noexcept
{
#if defined(_XANADU_COMPILE_MSVC)
	if(VirtualLock((LPVOID)_Addr, _Length))
	{
		return 0;
	}
	errno = __map_mman_error(GetLastError(), EPERM);
	return -1;
#else
	return ::mlock(_Addr, _Length);
#endif
}

// unlocking part  or  all  of  the  calling process's  virtual address space
XANADU_CORE_EXPORT int XANADUAPI Xanadu::munlock(const void* _Addr, size_t _Length) noexcept
{
#if defined(_XANADU_COMPILE_MSVC)
	if(VirtualUnlock((LPVOID)_Addr, _Length))
	{
		return 0;
	}
	errno = __map_mman_error(GetLastError(), EPERM);
	return -1;
#else
	return ::munlock(_Addr, _Length);
#endif
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Filesystem operation
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// Check file properties
XANADU_CORE_EXPORT int XANADUAPI Xanadu::access(const char* _Path, int _Mode) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_access(_Path, _Mode);
#else
	return ::access(_Path, _Mode);
#endif
}

// Check file properties
XANADU_CORE_EXPORT int XANADUAPI Xanadu::waccess(const wchar_t* _Path, int _Mode) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_waccess(_Path, _Mode);
#else
	auto		vNPath = Xanadu::strwton(_Path);
	auto		vSync = Xanadu::access(vNPath, _Mode);
	Xanadu::strfree(vNPath);
	return vSync;
#endif
}

// Associate the stream with a file that was previously opened for low-level I/O.
XANADU_CORE_EXPORT FILE* XANADUAPI Xanadu::fdopen(int _Fildes, const char* _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Mode, nullptr);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_fdopen(_Fildes, _Mode);
#else
	return ::fdopen(_Fildes, _Mode);
#endif
}

// Associate the stream with a file that was previously opened for low-level I/O.
XANADU_CORE_EXPORT FILE* XANADUAPI Xanadu::wfdopen(int _Fildes, const wchar_t* _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Mode, nullptr);

	auto 		vNMode = Xanadu::strwton(_Mode);
	auto 		vHandle = Xanadu::fdopen(_Fildes, vNMode);
	Xanadu::strfree(vNMode);
	return vHandle;
}

// Reallocate the file pointer
XANADU_CORE_EXPORT FILE* XANADUAPI Xanadu::freopen(const char* _Filename, const char* _Mode, FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Filename, nullptr);
	XANADU_CHECK_RETURN(_Mode, nullptr);
	XANADU_CHECK_RETURN(_Stream, nullptr);

#if defined(_XANADU_SYSTEM_WINDOWS)
	auto		vHandle = static_cast<FILE*>(nullptr);
	freopen_s(&vHandle, _Filename, _Mode, _Stream);
	return vHandle;
#else
	return ::freopen(_Filename, _Mode, _Stream);
#endif
}

// Reallocate the file pointer
XANADU_CORE_EXPORT FILE* XANADUAPI Xanadu::wfreopen(const wchar_t* _Filename, const wchar_t* _Mode, FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Filename, nullptr);
	XANADU_CHECK_RETURN(_Mode, nullptr);
	XANADU_CHECK_RETURN(_Stream, nullptr);

	auto 		vNFilename = Xanadu::strwton(_Filename);
	auto 		vNMode = Xanadu::strwton(_Mode);
	auto		vHandle = Xanadu::freopen(vNFilename, vNMode, _Stream);
	Xanadu::strfree(vNFilename);
	Xanadu::strfree(vNMode);
	return vHandle;
}

// Open file
XANADU_CORE_EXPORT FILE* XANADUAPI Xanadu::fopen(const char* _File, const char* _Mode) noexcept
{
	XANADU_CHECK_RETURN(_File, nullptr);
	XANADU_CHECK_RETURN(_Mode, nullptr);

#if defined(_XANADU_SYSTEM_WINDOWS)
	auto		vHandle = static_cast<FILE*>(nullptr);
	fopen_s(&vHandle, _File, _Mode);
	return vHandle;
#else
	return ::fopen(_File, _Mode);
#endif
}

// Open file
XANADU_CORE_EXPORT FILE* XANADUAPI Xanadu::wfopen(const wchar_t* _File, const wchar_t* _Mode) noexcept
{
	XANADU_CHECK_RETURN(_File, nullptr);
	XANADU_CHECK_RETURN(_Mode, nullptr);

#if defined(_XANADU_SYSTEM_WINDOWS)
	auto		vHandle = static_cast<FILE*>(nullptr);
	::_wfopen_s(&vHandle, _File, _Mode);
	return vHandle;
#else
	auto 		vNFile = Xanadu::strwton(_File);
	auto 		vNMode = Xanadu::strwton(_Mode);
	auto		vHandle = Xanadu::fopen(vNFile, vNMode);
	Xanadu::strfree(vNFile);
	Xanadu::strfree(vNMode);
	return vHandle;
#endif
}

// Moves the file pointer to a specified location.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::fseek(FILE* _Stream, long long _Offset, int _Origin) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_fseeki64(_Stream, _Offset, _Origin);
#else
	return ::fseek(_Stream, _Offset, _Origin);
#endif
}

// Gets the current position of a file pointer.
XANADU_CORE_EXPORT long long XANADUAPI Xanadu::ftell(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_ftelli64(_Stream);
#else
	return ::ftell(_Stream);
#endif
}

// Reads data from a stream.
XANADU_CORE_EXPORT size_t XANADUAPI Xanadu::fread(void* _Buffer, size_t _Size, size_t _Count, FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, 0);
	XANADU_CHECK_RETURN(_Stream, 0);

	return ::fread(_Buffer, _Size, _Count, _Stream);
}

// Reads data from a stream.
XANADU_CORE_EXPORT bool XANADUAPI Xanadu::fread(FILE* _Stream, void* _Buffer, size_t _Size) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, false);
	XANADU_CHECK_RETURN(_Stream, false);

	auto		vAlready = static_cast<size_t>(0U);
	while(vAlready < _Size)
	{
		auto	vSync = Xanadu::fread(((char*)(_Buffer)) + vAlready, 1, _Size - vAlready, _Stream);
		if(0U < vSync)
		{
			vAlready += vSync;
		}
		else
		{
			break;
		}
	};
	return vAlready == _Size;
}

// Writes data to a stream.
XANADU_CORE_EXPORT size_t XANADUAPI Xanadu::fwrite(const void* _Buffer, size_t _Size, size_t _Count, FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, 0);
	XANADU_CHECK_RETURN(_Stream, 0);

	return ::fwrite(_Buffer, _Size, _Count, _Stream);
}

// Writes data to a stream.
XANADU_CORE_EXPORT bool XANADUAPI Xanadu::fwrite(FILE* _Stream, const void* _Buffer, size_t _Size) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, false);
	XANADU_CHECK_RETURN(_Stream, false);

	auto		vAlready = static_cast<size_t>(0U);
	while(vAlready < _Size)
	{
		auto	vSync = Xanadu::fwrite(((const char*)(_Buffer)) + vAlready, 1, _Size - vAlready, _Stream);
		if(0U < vSync)
		{
			vAlready += vSync;
		}
		else
		{
			break;
		}
	};
	return vAlready == _Size;
}

// Flushes a stream.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::fflush(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

	return ::fflush(_Stream);
}

// Sync a stream.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::fsync(int _Fildes) noexcept
{
	XANADU_CHECK_RETURN(_Fildes, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return 0;
#else
	return ::fsync(_Fildes);
#endif
}

// Read a character from a stream.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::fgetc(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

	return ::fgetc(_Stream);
}

// Get a string from a stream.
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::fgets(char* _Buffer, int _MaxCount, FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, nullptr);
	XANADU_CHECK_RETURN(_Stream, nullptr);

	return ::fgets(_Buffer, _MaxCount, _Stream);
}

// Gets the file handle associated with a stream.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::fileno(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_fileno(_Stream);
#else
	return ::fileno(_Stream);
#endif
}

// Tests for end-of-file on a stream.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::feof(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

	return ::feof(_Stream);
}

// Tests for an error on a stream.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::ferror(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

	return ::ferror(_Stream);
}

// Closes a stream
XANADU_CORE_EXPORT int XANADUAPI Xanadu::fclose(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

	return ::fclose(_Stream);
}

// Deletes a directory.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::rmdir(const char* _Path) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_rmdir(_Path);
#else
	return ::rmdir(_Path);
#endif
}

// Deletes a directory.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wrmdir(const wchar_t* _Path) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_wrmdir(_Path);
#else
	auto		vNPath = Xanadu::strwton(_Path);
	auto		vSync = Xanadu::rmdir(vNPath);
	Xanadu::strfree(vNPath);
	return vSync;
#endif
}

// Creates a new directory.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::mkdir(const char* _Path, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	XANADU_UNPARAMETER(_Mode);
	return ::_mkdir(_Path);
#else
	auto		vSync = ::mkdir(_Path, _Mode);
	if(0 == vSync)
	{
		Xanadu::chmod(_Path, _Mode);
	}
	return vSync;
#endif
}

// Creates a new directory.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wmkdir(const wchar_t* _Path, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	XANADU_UNPARAMETER(_Mode);
	return ::_wmkdir(_Path);
#else
	auto		vNPath = Xanadu::strwton(_Path);
	auto		vSync = Xanadu::mkdir(vNPath, _Mode);
	if(0 == vSync)
	{
		Xanadu::chmod(vNPath, _Mode);
	}
	Xanadu::strfree(vNPath);
	return vSync;
#endif
}

// Changes the file-permission settings.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::chmod(const char* _Path, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_chmod(_Path, _Mode);
#else
	return ::chmod(_Path, _Mode);
#endif
}

// Changes the file-permission settings.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wchmod(const wchar_t* _Path, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_wchmod(_Path, _Mode);
#else
	auto		vNPath = Xanadu::strwton(_Path);
	auto		vSync = Xanadu::chmod(vNPath, _Mode);
	Xanadu::strfree(vNPath);
	return vSync;
#endif
}

// Delete a file.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::remove(const char* _Path) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

	return ::remove(_Path);
}

// Delete a file.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wremove(const wchar_t* _Path) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_wremove(_Path);
#else
	auto		vNPath = Xanadu::strwton(_Path);
	auto		vSync = Xanadu::remove(vNPath);
	Xanadu::strfree(vNPath);
	return vSync;
#endif
}

// Rename a file or directory.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::rename(const char* _Old, const char* _New) noexcept
{
	XANADU_CHECK_RETURN(_Old, -1);
	XANADU_CHECK_RETURN(_New, -1);

	return ::rename(_Old, _New);
}

// Rename a file or directory.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wrename(const wchar_t* _Old, const wchar_t* _New) noexcept
{
	XANADU_CHECK_RETURN(_Old, -1);
	XANADU_CHECK_RETURN(_New, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_wrename(_Old, _New);
#else
	auto		vNOld = Xanadu::strwton(_Old);
	auto		vNNew = Xanadu::strwton(_New);
	auto		vSync = Xanadu::rename(vNOld, vNNew);
	Xanadu::strfree(vNOld);
	Xanadu::strfree(vNNew);
	return vSync;
#endif
}

// Get file information according to file pointer
XANADU_CORE_EXPORT int XANADUAPI Xanadu::fstat64(int _FileHandle, XStat64* _Stat) noexcept
{
	XANADU_CHECK_RETURN(_FileHandle, -1);
	XANADU_CHECK_RETURN(_Stat, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_fstat64(_FileHandle, _Stat);
#else
	return ::fstat64(_FileHandle, _Stat);
#endif
}

// Get file information according to file path
XANADU_CORE_EXPORT int XANADUAPI Xanadu::stat64(const char* _FileName, XStat64* _Stat) noexcept
{
	XANADU_CHECK_RETURN(_FileName, -1);
	XANADU_CHECK_RETURN(_Stat, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_stat64(_FileName, _Stat);
#else
	return ::stat64(_FileName, _Stat);
#endif
}

// Get file information according to file path
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wstat64(const wchar_t* _FileName, XStat64* _Stat) noexcept
{
	XANADU_CHECK_RETURN(_FileName, -1);
	XANADU_CHECK_RETURN(_Stat, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::_wstat64(_FileName, _Stat);
#else
	auto		vSync = -1;
	auto		vNFileName = Xanadu::strwton(_FileName);
	if(vNFileName)
	{
		vSync = Xanadu::stat64(vNFileName, _Stat);
		Xanadu::strfree(vNFileName);
	}
	return vSync;
#endif
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Xanadu: Filesystem operation extend
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// Get file size
XANADU_CORE_EXPORT unsigned long long XANADUAPI Xanadu::fsize(const char* _FilePath) noexcept
{
	XANADU_CHECK_RETURN(_FilePath, -1);

	XStat64		vFileStatus{};
	if(0 == Xanadu::stat64(_FilePath, &vFileStatus))
	{
		return vFileStatus.st_size;
	}
	return 0;
}

// Get file size
XANADU_CORE_EXPORT unsigned long long XANADUAPI Xanadu::wfsize(const wchar_t* _FilePath) noexcept
{
	XANADU_CHECK_RETURN(_FilePath, -1);

	XStat64		vFileStatus{};
	if(0 == Xanadu::wstat64(_FilePath, &vFileStatus))
	{
		return vFileStatus.st_size;
	}
	return 0;
}

// Copy file data.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::fcopy(const char* _ExistingFileName, const char* _NewFileName) noexcept
{
	XANADU_CHECK_RETURN(_ExistingFileName, -1);
	XANADU_CHECK_RETURN(_NewFileName, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	// Prioritize system API calls
	if(::CopyFileA(_ExistingFileName, _NewFileName, FALSE))
	{
		return 0;
	}
#endif

	auto		vNExistingFileName = Xanadu::strntow(_ExistingFileName);
	auto		vNNewFileName = Xanadu::strntow(_NewFileName);
	auto		vSync = Xanadu::wfcopy(vNExistingFileName, vNNewFileName);
	Xanadu::wcsfree(vNExistingFileName);
	Xanadu::wcsfree(vNNewFileName);
	return vSync;
}

// Copy file data.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wfcopy(const wchar_t* _ExistingFileName, const wchar_t* _NewFileName) noexcept
{
	XANADU_CHECK_RETURN(_ExistingFileName, -1);
	XANADU_CHECK_RETURN(_NewFileName, -1);

#if defined(_XANADU_SYSTEM_WINDOWS)
	// Prioritize system API calls
	if(::CopyFileW(_ExistingFileName, _NewFileName, FALSE))
	{
		return 0;
	}
#endif

	// 按字节拷贝文件
	auto		vSync = -1;
	auto		vLength = static_cast<size_t>(XANADU_SIZE_MB);
	auto 		vBuffer = (char*)Xanadu::malloc(vLength);
	auto		vFileSource = Xanadu::wfopen(_ExistingFileName, L"rb");
	auto		vFileTarget = Xanadu::wfopen(_NewFileName, L"wb");
	auto		vSourceSize = static_cast<size_t>(Xanadu::wfsize(_ExistingFileName));
	auto 		vCurrentRead = static_cast<size_t>(0U);
	if(vFileSource && vFileTarget && vBuffer)
	{
		if(0 == vSourceSize)
		{
			vSync = 0;
		}
		// 循环读取
		while(vSourceSize > vCurrentRead)
		{
			Xanadu::memset(vBuffer, 0, vLength);
			// 当前需要读多少数据
			auto		vReadSize = ((vSourceSize - vCurrentRead) > vLength) ? vLength : (vSourceSize - vCurrentRead);
			if(!Xanadu::fread(vFileSource, vBuffer, vReadSize))
			{
				break;
			}
			vCurrentRead += vReadSize;
			// 写入目标文件
			if(!Xanadu::fwrite(vFileTarget, vBuffer, vReadSize))
			{
				break;
			}
			if(vCurrentRead == vSourceSize)
			{
				vSync = 0;
				break;
			}
		};
	}
	// 关闭文件
	Xanadu::fclose(vFileSource);
	Xanadu::fclose(vFileTarget);
	vFileTarget = nullptr;
	vFileTarget = nullptr;
	Xanadu::free(vBuffer);

	return vSync;
}

// Format path. Replace \\ with /, removing the last bit of /.
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::fmtpath(const char* _Path) noexcept
{
	XANADU_CHECK_RETURN(_Path, nullptr);

	auto		vCopyPath = Xanadu::strdup(_Path);
	auto		vPathLength = Xanadu::strlen(vCopyPath);
	for(auto vIndex = 0U; vIndex < vPathLength; ++vIndex)
	{
		if(vCopyPath[vIndex] == '\\')
		{
			vCopyPath[vIndex] = '/';
		}
	}
	if (vPathLength > 0 && vCopyPath[vPathLength - 1] == '/')
	{
		vCopyPath[vPathLength - 1] = '\0';
	}
	return vCopyPath;
}

// Format path. Replace \\ with /, removing the last bit of /.
XANADU_CORE_EXPORT wchar_t* XANADUAPI Xanadu::wfmtpath(const wchar_t* _Path) noexcept
{
	XANADU_CHECK_RETURN(_Path, nullptr);

	auto		vCopyPath = Xanadu::wcsdup(_Path);
	auto		vPathLength = Xanadu::wcslen(vCopyPath);
	for(auto vIndex = 0U; vIndex < vPathLength; ++vIndex)
	{
		if(vCopyPath[vIndex] == L'\\')
		{
			vCopyPath[vIndex] = L'/';
		}
	}
	if (vPathLength > 0 && vCopyPath[vPathLength - 1] == L'/')
	{
		vCopyPath[vPathLength - 1] = L'\0';
	}
	return vCopyPath;
}

// Create a multi-level directory.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::mkpath(const char* _Directory, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Directory, -1);

	char		vTemp[XANADU_PATH] = { 0 };
	auto		vDirectory = Xanadu::fmtpath(_Directory);
	auto		vLength = Xanadu::strlen(vDirectory);
	auto		vSync = -1;

	// The path cannot be too long or too short
	if(XANADU_PATH <= vLength || vLength <= 0)
	{
		return -1;
	}

	// Now the loop is created
	for (auto vIndex = 0U; vIndex < vLength; ++vIndex)
	{
		vTemp[vIndex] = _Directory[vIndex];
		if (vTemp[vIndex] == '\\' || vTemp[vIndex] == '/')
		{
			if (Xanadu::access(vTemp, F_OK) != 0)
			{
				vSync = Xanadu::mkdir(vTemp, _Mode);
				if (vSync != 0 && errno != EEXIST)
				{
					return vSync;
				}
			}
		}
	}
	vSync = Xanadu::mkdir(vTemp, _Mode);
	Xanadu::strfree(vDirectory);
	if (vSync != 0 && errno == EEXIST)
	{
		return 0;
	}
	return vSync;
}

// Create a multi-level directory.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wmkpath(const wchar_t* _Directory, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Directory, -1);

	wchar_t		vTemp[XANADU_PATH] = { 0 };
	auto		vDirectory = Xanadu::wfmtpath(_Directory);
	auto		vLength = Xanadu::wcslen(vDirectory);
	auto		vSync = -1;

	// The path cannot be too long or too short
	if(XANADU_PATH <= vLength || vLength <= 0)
	{
		return -1;
	}

	// Now the loop is created
	for (auto vIndex = 0U; vIndex < vLength; ++vIndex)
	{
		vTemp[vIndex] = _Directory[vIndex];
		if (vTemp[vIndex] == L'\\' || vTemp[vIndex] == L'/')
		{
			if (Xanadu::waccess(vTemp, F_OK) != 0)
			{
				vSync = Xanadu::wmkdir(vTemp, _Mode);
				if (vSync != 0 && errno != EEXIST)
				{
					return vSync;
				}
			}
		}
	}
	vSync = Xanadu::wmkdir(vTemp, _Mode);
	Xanadu::wcsfree(vDirectory);
	if (vSync != 0 && errno == EEXIST)
	{
		return 0;
	}
	return vSync;
}

// Directory traverse
XANADU_CORE_EXPORT int XANADUAPI Xanadu::traversedir(const char* _Directory, _XFunctionTraverseDirectoryA _Function, void* _UserData) noexcept
{
	XANADU_CHECK_RETURN(_Directory, -1);

	auto		vDirectory = Xanadu::fmtpath(_Directory);
	auto		vSync = -1;
#if defined(_XANADU_SYSTEM_WINDOWS)
	auto 		vFindData = WIN32_FIND_DATAA();
	char		vFilePath[XANADU_PATH] = {0};
	Xanadu::strcpy(vFilePath, vDirectory);
	Xanadu::strcat(vFilePath, "/*");

	auto		vHandle = FindFirstFileA(vFilePath, &vFindData);
	if(vHandle == INVALID_HANDLE_VALUE)
	{
		return 1;
	}
	else
	{
		vSync = 0;
		do
		{
			auto		vFileInfo = XANADU_RUNTIME_FILE_INFO_A();
			Xanadu::memset(&vFileInfo, 0, sizeof(XANADU_RUNTIME_FILE_INFO_A));
			Xanadu::strcpy(vFileInfo.path, vDirectory);
			Xanadu::strcat(vFileInfo.path, "/");
			Xanadu::strcat(vFileInfo.path, vFindData.cFileName);
			Xanadu::strcpy(vFileInfo.name, vFindData.cFileName);
			vFileInfo.isDir = vFindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;

			if(_Function)
			{
				if(!_Function(&vFileInfo, _UserData))
				{
					break;
				}
			}
		}
		while(FindNextFileA(vHandle, &vFindData));
		::FindClose(vHandle);
	}
#else
	auto 		vHandle = ::opendir(vDirectory);
	auto		vDirEntry = static_cast<struct dirent*>(nullptr);

	if (vHandle)
	{
		vSync = 0;
		vDirEntry = ::readdir(vHandle);
		do
		{
			auto		vFileInfo = XANADU_RUNTIME_FILE_INFO_A();
			Xanadu::memset(&vFileInfo, 0, sizeof(XANADU_RUNTIME_FILE_INFO_A));
			Xanadu::strcpy(vFileInfo.path, vDirectory);
			Xanadu::strcat(vFileInfo.path, "/");
			Xanadu::strcat(vFileInfo.path, vDirEntry->d_name);
			Xanadu::strcpy(vFileInfo.name, vDirEntry->d_name);
			vFileInfo.isDir = vDirEntry->d_type & DT_DIR;

			if(_Function)
			{
				if(false == _Function(&vFileInfo, _UserData))
				{
					break;
				}
			}
			vDirEntry = ::readdir(vHandle);
		}while(vDirEntry);
		::closedir(vHandle);
	}

#endif
	Xanadu::strfree(vDirectory);
	return vSync;
}

// Directory traverse
XANADU_CORE_EXPORT int XANADUAPI Xanadu::wtraversedir(const wchar_t* _Directory, _XFunctionTraverseDirectoryW _Function, void* _UserData) noexcept
{
	XANADU_CHECK_RETURN(_Directory, -1);

	auto		vDirectory = Xanadu::wfmtpath(_Directory);
	auto		vSync = -1;
#if defined(_XANADU_SYSTEM_WINDOWS)
	auto 		vFindData = WIN32_FIND_DATAW();
	wchar_t		vFilePath[XANADU_PATH] = {0};
	Xanadu::wcscpy(vFilePath, vDirectory);
	Xanadu::wcscat(vFilePath, L"/*");

	auto		vHandle = FindFirstFileW(vFilePath, &vFindData);
	if(vHandle == INVALID_HANDLE_VALUE)
	{
		return 1;
	}
	else
	{
		vSync = 0;
		do
		{
			auto		vFileInfo = XANADU_RUNTIME_FILE_INFO_W();
			Xanadu::memset(&vFileInfo, 0, sizeof(XANADU_RUNTIME_FILE_INFO_A));
			Xanadu::wcscpy(vFileInfo.path, vDirectory);
			Xanadu::wcscat(vFileInfo.path, L"/");
			Xanadu::wcscat(vFileInfo.path, vFindData.cFileName);
			Xanadu::wcscpy(vFileInfo.name, vFindData.cFileName);
			vFileInfo.isDir = vFindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;

			if(_Function)
			{
				if(!_Function(&vFileInfo, _UserData))
				{
					break;
				}
			}
		}
		while(FindNextFileW(vHandle, &vFindData));
		::FindClose(vHandle);
	}
#else
	auto		vDirectoryA = Xanadu::strwton(vDirectory);
	auto 		vHandle = ::opendir(vDirectoryA);
	auto		vDirEntry = static_cast<struct dirent*>(nullptr);

	if (vHandle)
	{
		vSync = 0;
		vDirEntry = ::readdir(vHandle);
		do
		{
			auto		vFileNameW = Xanadu::strntow(vDirEntry->d_name);
			auto		vFileInfo = XANADU_RUNTIME_FILE_INFO_W();
			Xanadu::memset(&vFileInfo, 0, sizeof(XANADU_RUNTIME_FILE_INFO_W));
			Xanadu::wcscpy(vFileInfo.path, vDirectory);
			Xanadu::wcscat(vFileInfo.path, L"/");
			Xanadu::wcscat(vFileInfo.path, vFileNameW);
			Xanadu::wcscpy(vFileInfo.name, vFileNameW);
			vFileInfo.isDir = vDirEntry->d_type & DT_DIR;

			Xanadu::wcsfree(vFileNameW);
			if(_Function)
			{
				if(!_Function(&vFileInfo, _UserData))
				{
					break;
				}
			}
			vDirEntry = ::readdir(vHandle);
		}while(vDirEntry);
		::closedir(vHandle);
	}
	Xanadu::strfree(vDirectoryA);
#endif
	Xanadu::wcsfree(vDirectory);
	return vSync;
}





// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------
// Socket operation
// ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------

// retrieves host information corresponding to a host name from a host database.
XANADU_CORE_EXPORT struct hostent* XANADUAPI Xanadu::gethostbyname(const char* _Name) noexcept
{
	XANADU_CHECK_RETURN(_Name, nullptr);

	return ::gethostbyname(_Name);
}

// creates a socket that is bound to a specific service provider.
XANADU_CORE_EXPORT SOCKET XANADUAPI Xanadu::socket(int _Family, int _Type, int _Protocol) noexcept
{
	return ::socket(_Family, _Type, _Protocol);
}

// permits an incoming connection attempt on a socket.
XANADU_CORE_EXPORT SOCKET XANADUAPI Xanadu::accept(SOCKET _Socket, struct sockaddr* _Address, socklen_t* _Length) noexcept
{
	XANADU_CHECK_RETURN(_Address, (SOCKET)SOCKET_ERROR);
	XANADU_CHECK_RETURN(_Length, (SOCKET)SOCKET_ERROR);

	return ::accept(_Socket, _Address, _Length);
}

// associates a local address with a socket.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::bind(SOCKET _Socket, const struct sockaddr* _Address, socklen_t _Length) noexcept
{
	XANADU_CHECK_RETURN(_Address, SOCKET_ERROR);

	return ::bind(_Socket, _Address, _Length);
}

// close socket
XANADU_CORE_EXPORT int XANADUAPI Xanadu::socketclose(SOCKET _Socket) noexcept
{
	if (_Socket > 0)
	{
#if defined(_XANADU_SYSTEM_WINDOWS)
		return ::closesocket(_Socket);
#else
		return ::close(_Socket);
#endif
	}
	return -1;
}

// establishes a connection to a specified socket.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::connect(SOCKET _Socket, const struct sockaddr* _Address, socklen_t _Length) noexcept
{
	XANADU_CHECK_RETURN(_Address, SOCKET_ERROR);

	return ::connect(_Socket, _Address, _Length);
}

// retrieves the address of the peer to which a socket is connected.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::getpeername(SOCKET _Socket, struct sockaddr* _Address, socklen_t* _Length) noexcept
{
	XANADU_CHECK_RETURN(_Address, SOCKET_ERROR);
	XANADU_CHECK_RETURN(_Length, SOCKET_ERROR);

	return ::getpeername(_Socket, _Address, _Length);
}

// retrieves the local name for a socket.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::getsockname(SOCKET _Socket, struct sockaddr* _Address, socklen_t* _Length) noexcept
{
	XANADU_CHECK_RETURN(_Address, SOCKET_ERROR);
	XANADU_CHECK_RETURN(_Length, SOCKET_ERROR);

	return ::getsockname(_Socket, _Address, _Length);
}

// gets a socket option.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::getsockopt(SOCKET _Socket, int _Level, int _OptName, void* _OptValue, socklen_t* _OptLength) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::getsockopt(_Socket, _Level, _OptName, (char*)_OptValue, _OptLength);
#else
	return ::getsockopt(_Socket, _Level, _OptName, _OptValue, _OptLength);
#endif
}

// sets a socket option.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::setsockopt(SOCKET _Socket, int _Level, int _OptName, const void* _OptValue, socklen_t _OptLength) noexcept
{
#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::setsockopt(_Socket, _Level, _OptName, (const char*)_OptValue, _OptLength);
#else
	return ::setsockopt(_Socket, _Level, _OptName, _OptValue, _OptLength);
#endif
}

// converts a string containing an (Ipv4) Internet Protocol dotted address into a proper address for the in_addr structure.
XANADU_CORE_EXPORT struct in_addr XANADUAPI Xanadu::inet_addr(const char* _CP) noexcept
{
	struct in_addr		vAddress{};
	vAddress.s_addr = ::inet_addr(_CP);
	return vAddress;
}

// converts an (Ipv4) Internet network address into a string in Internet standard dotted format.
XANADU_CORE_EXPORT char* XANADUAPI Xanadu::inet_ntoa(struct in_addr _IN) noexcept
{
	return ::inet_ntoa(_IN);
}

// places a socket at a state where it is listening for an incoming connection.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::listen(SOCKET _Socket, int _Backlog) noexcept
{
	return ::listen(_Socket, _Backlog);
}

// receives data from a connected socket.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::recv(SOCKET _Socket, void* _Buffer, int _Length, int _Flags) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, SOCKET_ERROR);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::recv(_Socket, (char*)_Buffer, _Length, _Flags);
#else
	return ::recv(_Socket, _Buffer, _Length, _Flags);
#endif
}

// receives a datagram and stores the source address.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::recvfrom(SOCKET _Socket, void* _Buffer, int _Length, int _Flags, struct sockaddr* _From, socklen_t* _Fromlen) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, SOCKET_ERROR);
	XANADU_CHECK_RETURN(_From, SOCKET_ERROR);
	XANADU_CHECK_RETURN(_Fromlen, SOCKET_ERROR);
#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::recvfrom(_Socket, (char*)_Buffer, _Length, _Flags, _From, _Fromlen);
#else
	return ::recvfrom(_Socket, _Buffer, _Length, _Flags, _From, _Fromlen);
#endif
}

// sends data on a connected socket.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::send(SOCKET _Socket, const void* _Buffer, int _Length, int _Flags) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, SOCKET_ERROR);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::send(_Socket, (const char*)_Buffer, _Length, _Flags);
#else
	return ::send(_Socket, _Buffer, _Length, _Flags);
#endif
}

// sends data to a specific destination.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::sendto(SOCKET _Socket, const void* _Buffer, int _Length, int _Flags, const struct sockaddr* _To, socklen_t _Tolen) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, SOCKET_ERROR);
	XANADU_CHECK_RETURN(_To, SOCKET_ERROR);

#if defined(_XANADU_SYSTEM_WINDOWS)
	return ::sendto(_Socket, (const char*)_Buffer, _Length, _Flags, _To, _Tolen);
#else
	return ::sendto(_Socket, _Buffer, _Length, _Flags, _To, _Tolen);
#endif
}

// disables sends or receives on a socket.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::shutdown(SOCKET _Socket, int _Now) noexcept
{
	XANADU_CHECK_RETURN(_Socket > 0, -1);

	return ::shutdown(_Socket, _Now);
}

// determines the status of one or more sockets, waiting if necessary, to perform synchronous I/O.
XANADU_CORE_EXPORT int XANADUAPI Xanadu::select(int _Fds, fd_set* _ReadFds, fd_set* _WriteFds, fd_set* _ExceptFds, const struct timeval* _Timeout) noexcept
{
	XANADU_CHECK_RETURN(_Fds > 0, -1);

	return ::select(_Fds, _ReadFds, _WriteFds, _ExceptFds, _Timeout);
}

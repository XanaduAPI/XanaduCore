#ifndef			_XANADU_CORE_XRUNTIME_H_
#define			_XANADU_CORE_XRUNTIME_H_

#include <XanaduCore/XHeader.h>


// C memory management library
namespace Xanadu
{
	// Allocates size bytes of uninitialized storage.
	// https://en.cppreference.com/w/cpp/memory/c/malloc
	XANADU_CORE_EXPORT void* XANADUAPI malloc(std::size_t _Size) noexcept;

	// Allocates memory for an array of num objects of size size and initializes it to all bits zero.
	// https://en.cppreference.com/w/cpp/memory/c/calloc
	XANADU_CORE_EXPORT void* XANADUAPI calloc(std::size_t _Number, std::size_t _Size) noexcept;

	// Reallocates the given area of memory.
	// https://en.cppreference.com/w/cpp/memory/c/realloc
	XANADU_CORE_EXPORT void* XANADUAPI realloc(void* _Block, size_t _Size) noexcept;

	// Deallocates the space previously allocated by malloc, calloc, or realloc.
	// https://en.cppreference.com/w/cpp/memory/c/free
	XANADU_CORE_EXPORT void XANADUAPI free(void* _Memory) noexcept;
}





// Character array manipulation
namespace Xanadu
{
	// searches an array for the first occurrence of a character
	// https://en.cppreference.com/w/cpp/string/byte/memchr
	XANADU_CORE_EXPORT const void* XANADUAPI memchr(const void* _Buf, int _Val, std::size_t _Count) noexcept;

	// searches an array for the first occurrence of a character
	// https://en.cppreference.com/w/cpp/string/wide/wmemchr
	XANADU_CORE_EXPORT const wchar_t* XANADUAPI wmemchr(const wchar_t* _Buf, wchar_t _Val, std::size_t _Count) noexcept;

	// searches an array for the first occurrence of a character
	// https://en.cppreference.com/w/cpp/string/byte/memchr
	XANADU_CORE_EXPORT void* XANADUAPI memchr(void* _Buf, int _Val, std::size_t _Count) noexcept;

	// searches an array for the first occurrence of a character
	// https://en.cppreference.com/w/cpp/string/wide/wmemchr
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wmemchr(wchar_t* _Buf, wchar_t _Val, std::size_t _Count) noexcept;

	// compare the values of _Buf1 and _Buf2 by byte, up to _Size bytes.
	// https://en.cppreference.com/w/cpp/string/byte/memcmp
	XANADU_CORE_EXPORT int XANADUAPI memcmp(const void* _Buf1, const void* _Buf2, std::size_t _Size) noexcept;

	// compare the values of _Buf1 and _Buf2 by byte, up to _Size bytes.
	// https://en.cppreference.com/w/cpp/string/wide/wmemcmp
	XANADU_CORE_EXPORT int XANADUAPI wmemcmp(const wchar_t* _Buf1, const wchar_t* _Buf2, std::size_t _Size) noexcept;

	// Sets the first num bytes of the block of memory pointed by ptr to the specified value.
	// https://en.cppreference.com/w/cpp/string/byte/memset
	XANADU_CORE_EXPORT void* XANADUAPI memset(void* _Buffer, int _Value, std::size_t _Size) noexcept;

	// Sets the first num bytes of the block of memory pointed by ptr to the specified value.
	// https://en.cppreference.com/w/cpp/string/wide/wmemset
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wmemset(wchar_t* _Buffer, wchar_t _Value, std::size_t _Size) noexcept;

	// Copies size bytes from the object pointed to by src to the object pointed to by dest.
	// https://en.cppreference.com/w/cpp/string/byte/memcpy
	XANADU_CORE_EXPORT void* XANADUAPI memcpy(void* _Dest, const void* _Src, std::size_t _Size) noexcept;

	// Copies size bytes from the object pointed to by src to the object pointed to by dest.
	// https://en.cppreference.com/w/cpp/string/wide/wmemcpy
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wmemcpy(wchar_t* _Dest, const wchar_t* _Src, std::size_t _Size) noexcept;

	// Copies size bytes from the object pointed to by src to the object pointed to by dest.
	// https://en.cppreference.com/w/cpp/string/byte/memcpy
	XANADU_CORE_EXPORT void* XANADUAPI memcpy(void* _Dest, std::size_t _Length, const void* _Src, std::size_t _Size) noexcept;

	// Copies size bytes from the object pointed to by src to the object pointed to by dest.
	// https://en.cppreference.com/w/cpp/string/wide/wmemcpy
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wmemcpy(wchar_t* _Dest, std::size_t _Length, const wchar_t* _Src, std::size_t _Size) noexcept;

	// Copies count characters from the object pointed to by src to the object pointed to by dest.
	// https://en.cppreference.com/w/cpp/string/byte/memmove
	XANADU_CORE_EXPORT void* XANADUAPI memmove(void* _Dest, const void* _Src, std::size_t _Size) noexcept;

	// Copies count characters from the object pointed to by src to the object pointed to by dest.
	// https://en.cppreference.com/w/cpp/string/wide/wmemmove
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wmemmove(wchar_t* _Dest, const wchar_t* _Src, std::size_t _Size) noexcept;
}





// Character classification
namespace Xanadu
{
	// checks if a character is alphanumeric.
	// Non-zero value if the character is an alphanumeric character, 0 otherwise.
	// https://en.cppreference.com/w/cpp/string/byte/isalnum
	XANADU_CORE_EXPORT int XANADUAPI isalnum(int _Char) noexcept;

	// checks if a wide character is alphanumeric.
	// Non-zero value if the character is an alphanumeric character, 0 otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswalnum
	XANADU_CORE_EXPORT int XANADUAPI iswalnum(std::wint_t _Char) noexcept;

	// checks if a character is alphabetic.
	// Non-zero value if the character is an alphabetic character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/byte/isalpha
	XANADU_CORE_EXPORT int XANADUAPI isalpha(int _Char) noexcept;

	// checks if a wide character is alphabetic.
	// Non-zero value if the character is an alphabetic character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswalpha
	XANADU_CORE_EXPORT int XANADUAPI iswalpha(std::wint_t _Char) noexcept;

	// checks if a character is lowercase.
	// Non-zero value if the character is a lowercase letter, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/byte/islower
	XANADU_CORE_EXPORT int XANADUAPI islower(int _Char) noexcept;

	// checks if a wide character is lowercase.
	// Non-zero value if the character is a lowercase letter, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswlower
	XANADU_CORE_EXPORT int XANADUAPI iswlower(std::wint_t _Char) noexcept;

	// checks if a character is an uppercase character.
	// Non-zero value if the character is an uppercase letter, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/byte/isupper
	XANADU_CORE_EXPORT int XANADUAPI isupper(int _Char) noexcept;

	// checks if a wide character is an uppercase character.
	// Non-zero value if the character is an uppercase letter, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswupper
	XANADU_CORE_EXPORT int XANADUAPI iswupper(std::wint_t _Char) noexcept;

	// checks if a character is a digit.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/byte/isdigit
	XANADU_CORE_EXPORT int XANADUAPI isdigit(int _Char) noexcept;

	// checks if a wide character is a digit.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswdigit
	XANADU_CORE_EXPORT int XANADUAPI iswdigit(std::wint_t _Char) noexcept;

	// checks if a character is a hexadecimal character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/byte/isxdigit
	XANADU_CORE_EXPORT int XANADUAPI isxdigit(int _Char) noexcept;

	// checks if a wide character is a hexadecimal character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswxdigit
	XANADU_CORE_EXPORT int XANADUAPI iswxdigit(std::wint_t _Char) noexcept;

	// checks if a character is a control character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/byte/iscntrl
	XANADU_CORE_EXPORT int XANADUAPI iscntrl(int _Char) noexcept;

	// checks if a wide character is a control character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswcntrl
	XANADU_CORE_EXPORT int XANADUAPI iswcntrl(std::wint_t _Char) noexcept;

	// checks if a character is a graphical character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/byte/isgraph
	XANADU_CORE_EXPORT int XANADUAPI isgraph(int _Char) noexcept;

	// checks if a wide character is a graphical character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswgraph
	XANADU_CORE_EXPORT int XANADUAPI iswgraph(std::wint_t _Char) noexcept;

	// checks if a character is a space character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/byte/isspace
	XANADU_CORE_EXPORT int XANADUAPI isspace(int _Char) noexcept;

	// checks if a wide character is a space character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswspace
	XANADU_CORE_EXPORT int XANADUAPI iswspace(std::wint_t _Char) noexcept;

	// checks if a character is a blank character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/byte/isblank
	XANADU_CORE_EXPORT int XANADUAPI isblank(int _Char) noexcept;

	// checks if a wide character is a blank character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswblank
	XANADU_CORE_EXPORT int XANADUAPI iswblank(std::wint_t _Char) noexcept;

	// checks if a character is a printing character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/byte/isprint
	XANADU_CORE_EXPORT int XANADUAPI isprint(int _Char) noexcept;

	// checks if a wide character is a printing character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswprint
	XANADU_CORE_EXPORT int XANADUAPI iswprint(std::wint_t _Char) noexcept;

	// checks if a character is a punctuation character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/byte/ispunct
	XANADU_CORE_EXPORT int XANADUAPI ispunct(int _Char) noexcept;

	// checks if a wide character is a punctuation character.
	// Non-zero value if the character is a numeric character, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswpunct
	XANADU_CORE_EXPORT int XANADUAPI iswpunct(std::wint_t _Char) noexcept;

	// classifies a wide character according to the specified LC_CTYPE category
	// Non-zero if the character ch has the property identified by desc in LC_CTYPE facet of the current C locale, zero otherwise.
	// https://en.cppreference.com/w/cpp/string/wide/iswctype
	XANADU_CORE_EXPORT int XANADUAPI iswctype(std::wint_t _Char, std::wctype_t _Desc) noexcept;

	// looks up a character classification category in the current C locale
	// https://en.cppreference.com/w/cpp/string/wide/wctype
	XANADU_CORE_EXPORT std::wctype_t XANADUAPI wctype(const char* _String) noexcept;
}






// Character manipulation
namespace Xanadu
{
	// converts a character to lowercase
	// https://en.cppreference.com/w/cpp/string/byte/tolower
	XANADU_CORE_EXPORT int XANADUAPI tolower(int _Char) noexcept;

	// Converts the given wide character to lowercase
	// https://en.cppreference.com/w/cpp/string/wide/towlower
	XANADU_CORE_EXPORT std::wint_t XANADUAPI towlower(std::wint_t _Char) noexcept;

	// converts a character to uppercase
	// https://en.cppreference.com/w/cpp/string/byte/toupper
	XANADU_CORE_EXPORT int XANADUAPI toupper(int _Char) noexcept;

	// Converts the given wide character to uppercase
	// https://en.cppreference.com/w/cpp/string/wide/towupper
	XANADU_CORE_EXPORT std::wint_t XANADUAPI towupper(std::wint_t _Char) noexcept;

	// performs character mapping according to the specified LC_CTYPE mapping category
	// https://en.cppreference.com/w/cpp/string/wide/towctrans
	XANADU_CORE_EXPORT std::wint_t XANADUAPI towctrans(std::wint_t _WChar, std::wctrans_t _Desc) noexcept;

	// looks up a character mapping category in the current C locale
	// https://en.cppreference.com/w/cpp/string/wide/wctrans
	XANADU_CORE_EXPORT std::wctrans_t XANADUAPI wctrans(const char* _String) noexcept;
}





// Conversions to numeric formats
namespace Xanadu
{
	// converts a byte string to a floating point value.
	// https://en.cppreference.com/w/cpp/string/byte/atof
	XANADU_CORE_EXPORT double XANADUAPI atof(const char* _String) noexcept;

	// converts a byte string to a floating point value.
	XANADU_CORE_EXPORT double XANADUAPI wtof(const wchar_t* _String) noexcept;

	// converts a byte string to an integer value.
	// https://en.cppreference.com/w/cpp/string/byte/atoi
	XANADU_CORE_EXPORT int XANADUAPI atoi(const char* _String) noexcept;

	// converts a byte string to an integer value.
	XANADU_CORE_EXPORT int XANADUAPI wtoi(const wchar_t* _String) noexcept;

	// converts a byte string to an integer value.
	// https://en.cppreference.com/w/cpp/string/byte/atol
	XANADU_CORE_EXPORT long XANADUAPI atol(const char* _String) noexcept;

	// converts a byte string to an integer value.
	XANADU_CORE_EXPORT long XANADUAPI wtol(const wchar_t* _String) noexcept;

	// converts a byte string to an integer value.
	// https://en.cppreference.com/w/cpp/string/byte/atoll
	XANADU_CORE_EXPORT long long XANADUAPI atoll(const char* _String) noexcept;

	// converts a byte string to an integer value.
	XANADU_CORE_EXPORT long long XANADUAPI wtoll(const wchar_t* _String) noexcept;

	// converts a byte string to an integer value.
	// https://en.cppreference.com/w/cpp/string/byte/strtol
	XANADU_CORE_EXPORT long XANADUAPI strtol(const char* _String, char** _StrEnd, int _Base) noexcept;

	// converts a wide string to an integer value
	// https://en.cppreference.com/w/cpp/string/wide/wcstol
	XANADU_CORE_EXPORT long XANADUAPI wcstol(const wchar_t* _String, wchar_t** _StrEnd, int _Base) noexcept;

	// converts a byte string to an integer value.
	// https://en.cppreference.com/w/cpp/string/byte/strtoll
	XANADU_CORE_EXPORT long long XANADUAPI strtoll(const char* _String, char** _StrEnd, int _Base) noexcept;

	// converts a wide string to an integer value.
	// https://en.cppreference.com/w/cpp/string/wide/wcstoll
	XANADU_CORE_EXPORT long long XANADUAPI wcstoll(const wchar_t* _String, wchar_t** _StrEnd, int _Base) noexcept;

	// converts a byte string to an unsigned integer value.
	// https://en.cppreference.com/w/cpp/string/byte/strtoul
	XANADU_CORE_EXPORT unsigned long XANADUAPI strtoul(const char* _String, char** _StrEnd, int _Base) noexcept;

	// converts a wide string to an unsigned integer value.
	// https://en.cppreference.com/w/cpp/string/wide/wcstoul
	XANADU_CORE_EXPORT unsigned long XANADUAPI wcstoul(const wchar_t* _String, wchar_t** _StrEnd, int _Base) noexcept;

	// converts a byte string to an unsigned integer value.
	// https://en.cppreference.com/w/cpp/string/byte/strtoull
	XANADU_CORE_EXPORT unsigned long long XANADUAPI strtoull(const char* _String, char** _StrEnd, int _Base) noexcept;

	// converts a wide string to an unsigned integer value.
	// https://en.cppreference.com/w/cpp/string/wide/wcstoull
	XANADU_CORE_EXPORT unsigned long long XANADUAPI wcstoull(const wchar_t* _String, wchar_t** _StrEnd, int _Base) noexcept;

	// converts a byte string to a floating point value.
	// https://en.cppreference.com/w/cpp/string/byte/strtof
	XANADU_CORE_EXPORT float XANADUAPI strtof(const char* _String, char** _StrEnd) noexcept;

	// converts a wide string to a floating point value.
	// https://en.cppreference.com/w/cpp/string/wide/wcstof
	XANADU_CORE_EXPORT float XANADUAPI wcstof(const wchar_t* _String, wchar_t** _StrEnd) noexcept;

	// converts a byte string to a floating point value.
	// https://en.cppreference.com/w/cpp/string/byte/strtod
	XANADU_CORE_EXPORT double XANADUAPI strtod(const char* _String, char** _StrEnd) noexcept;

	// converts a wide string to a floating point value.
	// https://en.cppreference.com/w/cpp/string/wide/wcstod
	XANADU_CORE_EXPORT double XANADUAPI wcstod(const wchar_t* _String, wchar_t** _StrEnd) noexcept;

	// converts a byte string to a floating point value.
	// https://en.cppreference.com/w/cpp/string/byte/strtold
	XANADU_CORE_EXPORT long double XANADUAPI strtold(const char* _String, char** _StrEnd) noexcept;

	// converts a wide string to a floating point value.
	// https://en.cppreference.com/w/cpp/string/wide/wcstold
	XANADU_CORE_EXPORT long double XANADUAPI wcstold(const wchar_t* _String, wchar_t** _StrEnd) noexcept;

	// converts a byte string to std::intmax_t.
	// https://en.cppreference.com/w/cpp/string/byte/strtoimax
	XANADU_CORE_EXPORT std::intmax_t XANADUAPI strtoimax(const char* _String, char** _StrEnd, int _Base) noexcept;

	// converts a wide string to std::intmax_t.
	// https://en.cppreference.com/w/cpp/string/wide/wcstoimax
	XANADU_CORE_EXPORT std::intmax_t XANADUAPI wcstoimax(const wchar_t* _String, wchar_t** _StrEnd, int _Base) noexcept;

	// converts a byte string to std::uintmax_t.
	// https://en.cppreference.com/w/cpp/string/byte/strtoumax
	XANADU_CORE_EXPORT std::uintmax_t XANADUAPI strtoumax(const char* _String, char** _StrEnd, int _Base) noexcept;

	// converts a wide string to std::uintmax_t.
	// https://en.cppreference.com/w/cpp/string/wide/wcstoumax
	XANADU_CORE_EXPORT std::uintmax_t XANADUAPI wcstoumax(const wchar_t* _String, wchar_t** _StrEnd, int _Base) noexcept;
}





// String manipulation
namespace Xanadu
{
	// copies one string to another
	// https://en.cppreference.com/w/cpp/string/byte/strcpy
	XANADU_CORE_EXPORT char* XANADUAPI strcpy(char* _Dest, const char* _Src) noexcept;

	// copies one string to another
	XANADU_CORE_EXPORT char* XANADUAPI strcpy(char* _Dest, std::size_t _Length, const char* _Src) noexcept;

	// copies one wide string to another
	// https://en.cppreference.com/w/cpp/string/wide/wcscpy
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcscpy(wchar_t* _Dest, const wchar_t* _Src) noexcept;

	// copies one wide string to another
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcscpy(wchar_t* _Dest, std::size_t _Length, const wchar_t* _Src) noexcept;

	// copies a certain amount of characters from one string to another
	// https://en.cppreference.com/w/cpp/string/byte/strncpy
	XANADU_CORE_EXPORT char* XANADUAPI strncpy(char* _Dest, const char* _Src, std::size_t _Count) noexcept;

	// copies a certain amount of characters from one string to another
	XANADU_CORE_EXPORT char* XANADUAPI strncpy(char* _Dest, std::size_t _Length, const char* _Src, std::size_t _Count) noexcept;

	// copies a certain amount of wide characters from one string to another
	// https://en.cppreference.com/w/cpp/string/wide/wcsncpy
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcsncpy(wchar_t* _Dest, const wchar_t* _Src, std::size_t _Count) noexcept;

	// copies a certain amount of wide characters from one string to another
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcsncpy(wchar_t* _Dest, std::size_t _Length, const wchar_t* _Src, std::size_t _Count) noexcept;

	// concatenates two strings
	// https://en.cppreference.com/w/cpp/string/byte/strcat
	XANADU_CORE_EXPORT char* XANADUAPI strcat(char* _Dest, const char* _Src) noexcept;

	// concatenates two strings
	XANADU_CORE_EXPORT char* XANADUAPI strcat(char* _Dest, std::size_t _Length, const char* _Src) noexcept;

	// appends a copy of one wide string to another
	// https://en.cppreference.com/w/cpp/string/wide/wcsncat
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcscat(wchar_t* _Dest, const wchar_t* _Src) noexcept;

	// appends a copy of one wide string to another
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcscat(wchar_t* _Dest, std::size_t _Length, const wchar_t* _Src) noexcept;

	// concatenates a certain amount of characters of two strings
	// https://en.cppreference.com/w/cpp/string/byte/strncat
	XANADU_CORE_EXPORT char* XANADUAPI strncat(char* _Dest, const char* _Src, std::size_t _Count) noexcept;

	// concatenates a certain amount of characters of two strings
	XANADU_CORE_EXPORT char* XANADUAPI strncat(char* _Dest, std::size_t _Length, const char* _Src, std::size_t _Count) noexcept;

	// appends a certain amount of wide characters from one wide string to another
	// https://en.cppreference.com/w/cpp/string/wide/wcsncat
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcsncat(wchar_t* _Dest, const wchar_t* _Src, std::size_t _Count) noexcept;

	// appends a certain amount of wide characters from one wide string to another
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcsncat(wchar_t* _Dest, std::size_t _Length, const wchar_t* _Src, std::size_t _Count) noexcept;

	// transform a string so that strcmp would produce the same result as strcoll
	// https://en.cppreference.com/w/cpp/string/byte/strxfrm
	XANADU_CORE_EXPORT std::size_t XANADUAPI strxfrm(char* _Dest, const char* _Src, std::size_t _Count) noexcept;

	// transform a wide string so that wcscmp would produce the same result as wcscoll
	// https://en.cppreference.com/w/cpp/string/wide/wcsxfrm
	XANADU_CORE_EXPORT std::size_t XANADUAPI wcsxfrm(wchar_t* _Dest, const wchar_t* _Src, std::size_t _Count) noexcept;
}





// String examination
namespace Xanadu
{
	// returns the length of a given string
	// https://en.cppreference.com/w/cpp/string/byte/strlen
	XANADU_CORE_EXPORT std::size_t XANADUAPI strlen(const char* _String) noexcept;

	// returns the length of a wide string
	// https://en.cppreference.com/w/cpp/string/wide/wcslen
	XANADU_CORE_EXPORT std::size_t XANADUAPI wcslen(const wchar_t* _String) noexcept;

	// compares two strings
	// https://en.cppreference.com/w/cpp/string/byte/strcmp
	XANADU_CORE_EXPORT int XANADUAPI strcmp(const char* lhs, const char* rhs) noexcept;

	// compares two wide strings
	// https://en.cppreference.com/w/cpp/string/wide/wcscmp
	XANADU_CORE_EXPORT int XANADUAPI wcscmp(const wchar_t* lhs, const wchar_t* rhs) noexcept;

	// compares a certain number of characters from two strings
	// https://en.cppreference.com/w/cpp/string/byte/strncmp
	XANADU_CORE_EXPORT int XANADUAPI strncmp(const char* lhs, const char* rhs, std::size_t _Count) noexcept;

	// compares a certain amount of characters from two wide strings
	// https://en.cppreference.com/w/cpp/string/wide/wcsncmp
	XANADU_CORE_EXPORT int XANADUAPI wcsncmp(const wchar_t* lhs, const wchar_t* rhs, std::size_t _Count) noexcept;

	// compares two strings in accordance to the current locale
	// https://en.cppreference.com/w/cpp/string/byte/strcoll
	XANADU_CORE_EXPORT int XANADUAPI strcoll(const char* lhs, const char* rhs) noexcept;

	// compares two wide strings in accordance to the current locale
	// https://en.cppreference.com/w/cpp/string/wide/wcscoll
	XANADU_CORE_EXPORT int XANADUAPI wcscoll(const wchar_t* lhs, const wchar_t* rhs) noexcept;

	// finds the first occurrence of a character
	// https://en.cppreference.com/w/cpp/string/byte/strchr
	XANADU_CORE_EXPORT const char* XANADUAPI strchr(const char* _String, int _Char) noexcept;

	// finds the first occurrence of a wide character in a wide string
	// https://en.cppreference.com/w/cpp/string/wide/wcschr
	XANADU_CORE_EXPORT const wchar_t* XANADUAPI wcschr(const wchar_t* _String, wchar_t _Char) noexcept;

	// finds the first occurrence of a character
	// https://en.cppreference.com/w/cpp/string/byte/strchr
	XANADU_CORE_EXPORT char* XANADUAPI strchr(char* _String, int _Char) noexcept;

	// finds the first occurrence of a wide character in a wide string
	// https://en.cppreference.com/w/cpp/string/wide/wcschr
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcschr(wchar_t* _String, wchar_t _Char) noexcept;

	// finds the last occurrence of a character
	// https://en.cppreference.com/w/cpp/string/byte/strrchr
	XANADU_CORE_EXPORT const char* XANADUAPI strrchr(const char* _String, int _Char) noexcept;

	// finds the first occurrence of a wide character in a wide string
	// https://en.cppreference.com/w/cpp/string/wide/wcsrchr
	XANADU_CORE_EXPORT const wchar_t* XANADUAPI wcsrchr(const wchar_t* _String, wchar_t _Char) noexcept;

	// finds the last occurrence of a character
	// https://en.cppreference.com/w/cpp/string/byte/strrchr
	XANADU_CORE_EXPORT char* XANADUAPI strrchr(char* _String, int _Char) noexcept;

	// finds the first occurrence of a wide character in a wide string
	// https://en.cppreference.com/w/cpp/string/wide/wcsrchr
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcsrchr(wchar_t* _String, wchar_t _Char) noexcept;

	// returns the length of the maximum initial segment that consists of only the characters found in another byte string
	// https://en.cppreference.com/w/cpp/string/byte/strspn
	XANADU_CORE_EXPORT size_t XANADUAPI strspn(const char* _Dest, const char* _String) noexcept;

	// returns the length of the maximum initial segment that consists of only the wide characters found in another wide string
	// https://en.cppreference.com/w/cpp/string/wide/wcsspn
	XANADU_CORE_EXPORT size_t XANADUAPI wcsspn(const wchar_t* _Dest, const wchar_t* _String) noexcept;

	// returns the length of the maximum initial segment that consists of only the characters not found in another byte string
	// https://en.cppreference.com/w/cpp/string/byte/strcspn
	XANADU_CORE_EXPORT size_t XANADUAPI strcspn(const char* _Dest, const char* _String) noexcept;

	// returns the length of the maximum initial segment that consists of only the wide not found in another wide string
	// https://en.cppreference.com/w/cpp/string/wide/wcscspn
	XANADU_CORE_EXPORT std::size_t XANADUAPI wcscspn(const wchar_t* _Dest, const wchar_t* _String) noexcept;

	// finds the first location of any character from a set of separators
	// https://en.cppreference.com/w/cpp/string/byte/strpbrk
	XANADU_CORE_EXPORT const char* XANADUAPI strpbrk(const char* _Dest, const char* _BreakSet) noexcept;

	// finds the first location of any wide character in one wide string, in another wide string
	// https://en.cppreference.com/w/cpp/string/wide/wcspbrk
	XANADU_CORE_EXPORT const wchar_t* XANADUAPI wcspbrk(const wchar_t* _Dest, const wchar_t* _BreakSet) noexcept;

	// finds the first location of any character from a set of separators
	// https://en.cppreference.com/w/cpp/string/byte/strpbrk
	XANADU_CORE_EXPORT char* XANADUAPI strpbrk(char* _Dest, const char* _BreakSet) noexcept;

	// finds the first location of any wide character in one wide string, in another wide string
	// https://en.cppreference.com/w/cpp/string/wide/wcspbrk
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcspbrk(wchar_t* _Dest, const wchar_t* _BreakSet) noexcept;

	// finds the first occurrence of a substring of characters
	// https://en.cppreference.com/w/cpp/string/byte/strstr
	XANADU_CORE_EXPORT const char* XANADUAPI strstr(const char* _String, const char* _SubStr) noexcept;

	// finds the first occurrence of a wide string within another wide string
	// https://en.cppreference.com/w/cpp/string/wide/wcsstr
	XANADU_CORE_EXPORT const wchar_t* XANADUAPI wcsstr(const wchar_t* _String, const wchar_t* _SubStr) noexcept;

	// finds the first occurrence of a substring of characters
	// https://en.cppreference.com/w/cpp/string/byte/strstr
	XANADU_CORE_EXPORT char* XANADUAPI strstr(char* _String, const char* _SubStr) noexcept;

	// finds the first occurrence of a wide string within another wide string
	// https://en.cppreference.com/w/cpp/string/wide/wcsstr
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcsstr(wchar_t* _String, const wchar_t* _SubStr) noexcept;

	// finds the next token in a byte string
	// https://en.cppreference.com/w/cpp/string/byte/strtok
	XANADU_CORE_EXPORT char* XANADUAPI strtok(char* _String, const char* _Delim) noexcept;

	// finds the next token in a wide string
	// https://en.cppreference.com/w/cpp/string/wide/wcstok
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcstok(wchar_t* _String, const wchar_t* _Delim, wchar_t** _Ptr) noexcept;
}





// Xanadu: String extend
namespace Xanadu
{
	// Ignore case comparison strings
	XANADU_CORE_EXPORT int XANADUAPI strcasecmp(const char* _String1, const char* _String2) noexcept;

	// Ignore case comparison strings
	XANADU_CORE_EXPORT int XANADUAPI wcscasecmp(const wchar_t* _String1, const wchar_t* _String2) noexcept;

	// Copy a string
	XANADU_CORE_EXPORT char* XANADUAPI strdup(const char* _String) noexcept;

	// Copy a string
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcsdup(const wchar_t* _String) noexcept;

	// Releases a string created by strdup
	XANADU_CORE_EXPORT void XANADUAPI strfree(char* _String) noexcept;

	// Releases a string created by wcsdup
	XANADU_CORE_EXPORT void XANADUAPI wcsfree(wchar_t* _String) noexcept;

	// Convert string to lowercase
	XANADU_CORE_EXPORT char* XANADUAPI strlower(char* _String) noexcept;

	// Convert string to lowercase
	XANADU_CORE_EXPORT char* XANADUAPI strlower(char* _String, size_t _Count) noexcept;

	// Convert string to uppercase
	XANADU_CORE_EXPORT char* XANADUAPI strupper(char* _String) noexcept;

	// Convert string to uppercase
	XANADU_CORE_EXPORT char* XANADUAPI strupper(char* _String, size_t _Count) noexcept;

	// Convert string to lowercase
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcslower(wchar_t* _String) noexcept;

	// Convert string to lowercase
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcslower(wchar_t* _String, size_t _Count) noexcept;

	// Convert string to uppercase
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcsupper(wchar_t* _String) noexcept;

	// Convert string to uppercase
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcsupper(wchar_t* _String, size_t _Count) noexcept;

	// Convert UNICODE string to ASCII, Need to call strfree release
	XANADU_CORE_EXPORT char* XANADUAPI strwtoa(const wchar_t* _String) noexcept;

	// Convert UNICODE string to UTF-8, Need to call strfree release
	XANADU_CORE_EXPORT char* XANADUAPI strwtou(const wchar_t* _String) noexcept;

	// Convert UNICODE string to Native String(Windows:ASCII/Other:UTF-8), Need to call strfree release
	XANADU_CORE_EXPORT char* XANADUAPI strwton(const wchar_t* _String) noexcept;

	// Convert ASCII string to UNICODE, Need to call wcsfree release
	XANADU_CORE_EXPORT wchar_t* XANADUAPI stratow(const char* _String) noexcept;

	// Convert UTF-8 string to UNICODE, Need to call wcsfree release
	XANADU_CORE_EXPORT wchar_t* XANADUAPI strutow(const char* _String) noexcept;

	// Convert Native String(Windows:ASCII/Other:UTF-8) string to UNICODE, Need to call wcsfree release
	XANADU_CORE_EXPORT wchar_t* XANADUAPI strntow(const char* _String) noexcept;
}





// Compute absolute value
namespace Xanadu
{
	// Returns the absolute value of the specified value.
	// http://www.cplusplus.com/reference/cmath/abs
	XANADU_CORE_EXPORT char XANADUAPI abs(char _X) noexcept;

	// Returns the absolute value of the specified value.
	// http://www.cplusplus.com/reference/cmath/abs
	XANADU_CORE_EXPORT short XANADUAPI abs(short _X) noexcept;

	// Returns the absolute value of the specified value.
	// http://www.cplusplus.com/reference/cmath/abs
	XANADU_CORE_EXPORT int XANADUAPI abs(int _X) noexcept;

	// Returns the absolute value of the specified value.
	// http://www.cplusplus.com/reference/cmath/abs
	XANADU_CORE_EXPORT long XANADUAPI abs(long _X) noexcept;

	// Returns the absolute value of the specified value.
	// http://www.cplusplus.com/reference/cmath/abs
	XANADU_CORE_EXPORT long long XANADUAPI abs(long long _X) noexcept;

	// Returns the absolute value of the specified value.
	// http://www.cplusplus.com/reference/cmath/abs
	XANADU_CORE_EXPORT float XANADUAPI abs(float _X) noexcept;

	// Returns the absolute value of the specified value.
	// http://www.cplusplus.com/reference/cmath/abs
	XANADU_CORE_EXPORT double XANADUAPI abs(double _X) noexcept;

	// Returns the absolute value of the specified value.
	// http://www.cplusplus.com/reference/cmath/abs
	XANADU_CORE_EXPORT long double XANADUAPI abs(long double _X) noexcept;
}





// Dynamic library operation
namespace Xanadu
{
	// Loading dynamic library
	XANADU_CORE_EXPORT HANDLE XANADUAPI LoadLibraryA(const char* _LibraryFile) noexcept;

	// Loading dynamic library
	XANADU_CORE_EXPORT HANDLE XANADUAPI LoadLibraryW(const wchar_t* _LibraryFile) noexcept;

	// Finding function address from dynamic library
	XANADU_CORE_EXPORT void* XANADUAPI GetProcAddress(HANDLE _Handle, const char* _ProcName) noexcept;

	// Close dynamic library
	XANADU_CORE_EXPORT bool XANADUAPI FreeLibrary(HANDLE _Handle) noexcept;

	// Loading dynamic library
	XANADU_CORE_EXPORT HANDLE XANADUAPI dlopen(const char* _LibraryFile, int _Mode) noexcept;

	// Finding function address from dynamic library
	XANADU_CORE_EXPORT void* XANADUAPI dlsym(HANDLE _Handle, const char* _ProcName) noexcept;

	// Close dynamic library
	XANADU_CORE_EXPORT int XANADUAPI dlclose(HANDLE _Handle) noexcept;
}





// C library locales
namespace Xanadu
{
	// gets and sets the current C locale
	XANADU_CORE_EXPORT char* XANADUAPI setlocale(int _Category, const char* _Locale) noexcept;
}





// Multibyte/wide character conversions
namespace Xanadu
{
	// converts a wide string to narrow multibyte character string
	// https://en.cppreference.com/w/cpp/string/multibyte/wcstombs
	XANADU_CORE_EXPORT std::size_t XANADUAPI wcstombs(char* _MBS, const wchar_t* _WCS, std::size_t _Length) noexcept;

	// converts a narrow multibyte character string to wide string
	// https://en.cppreference.com/w/cpp/string/multibyte/mbstowcs
	XANADU_CORE_EXPORT std::size_t XANADUAPI mbstowcs(wchar_t* _WCS, const char* _MBS, std::size_t _Length) noexcept;
}





// C random library
namespace Xanadu
{
	// seeds pseudo-random number generator
	// https://en.cppreference.com/w/cpp/numeric/random/srand
	XANADU_CORE_EXPORT void XANADUAPI srand(unsigned int _Seed) noexcept;

	// generates a pseudo-random number
	// https://en.cppreference.com/w/cpp/numeric/random/rand
	XANADU_CORE_EXPORT int XANADUAPI rand() noexcept;
}





// C sleep library
namespace Xanadu
{
	// Sleep by the specified number of seconds
	XANADU_CORE_EXPORT unsigned int XANADUAPI sleep(unsigned int _Seconds) noexcept;

	// Sleep by the specified number of milliseconds
	XANADU_CORE_EXPORT unsigned int XANADUAPI msleep(unsigned int _Milliseconds) noexcept;

	// Sleep by the specified number of microseconds
	XANADU_CORE_EXPORT unsigned int XANADUAPI usleep(unsigned int _Microseconds) noexcept;
}





// Time manipulation
// https://en.cppreference.com/w/cpp/chrono/c
namespace Xanadu
{
	// computes the difference between times
	XANADU_CORE_EXPORT double XANADUAPI difftime(std::time_t _TimeEnd, std::time_t _TimeBegin) noexcept;

	// returns the current time of the system as time since epoch
	XANADU_CORE_EXPORT std::time_t XANADUAPI time(std::time_t* _Arg) noexcept;

	// returns raw processor clock time since the program is started
	XANADU_CORE_EXPORT std::clock_t XANADUAPI clock() noexcept;
}





// Format conversions
// https://en.cppreference.com/w/cpp/chrono/c
namespace Xanadu
{
	// converts a tm object to a textual representation
	XANADU_CORE_EXPORT char* XANADUAPI asctime(const std::tm* _Time) noexcept;

	// converts a time_t object to a textual representation
	XANADU_CORE_EXPORT char* XANADUAPI ctime(const std::time_t* _Time) noexcept;

	// converts a tm object to custom textual representation
	XANADU_CORE_EXPORT std::size_t XANADUAPI strftime(char* _String, std::size_t _Count, const char* _Format, const std::tm* _Time) noexcept;

	// converts a tm object to custom wide string textual representation
	XANADU_CORE_EXPORT std::size_t XANADUAPI wcsftime(wchar_t* _String, std::size_t _Count, const wchar_t* _Format, const std::tm* _Time) noexcept;

	// converts time since epoch to calendar time expressed as Universal Coordinated Time
	XANADU_CORE_EXPORT std::tm* XANADUAPI gmtime(const std::time_t* _Time) noexcept;

	// converts time since epoch to calendar time expressed as local time
	XANADU_CORE_EXPORT std::tm* XANADUAPI localtime(const std::time_t* _Time) noexcept;

	// converts calendar time to time since epoch
	XANADU_CORE_EXPORT std::time_t XANADUAPI mktime(std::tm* _Time) noexcept;
}





// Process operation
// https://en.cppreference.com/w/cpp/utility/program
namespace Xanadu
{
	// Creates a pipe and executes a command.
	XANADU_CORE_EXPORT FILE* XANADUAPI popen(const char* _Command, const char* _Mode) noexcept;

	// Waits for a new command processor and closes the stream on the associated pipe.
	XANADU_CORE_EXPORT int XANADUAPI pclose(FILE* _Stream) noexcept;

	// Loads and executes new child processes.
	XANADU_CORE_EXPORT int XANADUAPI execds(const char* _Application, const char* _Directory, const char* _Param) noexcept;

	// causes abnormal program termination (without cleaning up)
	XANADU_CORE_EXPORT void XANADUAPI abort() noexcept;

	// causes normal program termination with cleaning up
	XANADU_CORE_EXPORT void XANADUAPI exit(int _Status) noexcept;

	// registers a function to be called on std::exit() invocation
	typedef void(XANADUAPI* _Function_atexit)(void);
	XANADU_CORE_EXPORT int XANADUAPI atexit(_Function_atexit _Function) noexcept;

	// This function returns the process identifier of the calling process.
	XANADU_CORE_EXPORT unsigned long XANADUAPI GetCurrentProcessId() noexcept;

	// This function returns the process identifier of the calling process.
	XANADU_CORE_EXPORT long XANADUAPI getpid() noexcept;

	// Kill the process with the specified ID
	XANADU_CORE_EXPORT int XANADUAPI kill(long _ProcessID, int _Signal) noexcept;

	// Gets the current working directory.
	XANADU_CORE_EXPORT char* XANADUAPI getcwd(char* _Buffer, size_t _Size) noexcept;

	// Gets the current working directory.
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wgetcwd(wchar_t* _Buffer, size_t _Size) noexcept;

	// Changes the current directory for the current process.
	XANADU_CORE_EXPORT int XANADUAPI chdir(const char* _Dirname) noexcept;

	// Changes the current directory for the current process.
	XANADU_CORE_EXPORT int XANADUAPI wchdir(const wchar_t* _Dirname) noexcept;

	// Gets the current working directory.
	XANADU_CORE_EXPORT unsigned long XANADUAPI GetCurrentDirectoryA(unsigned long _Length, char* _Buffer) noexcept;

	// Gets the current working directory.
	XANADU_CORE_EXPORT unsigned long XANADUAPI GetCurrentDirectoryW(unsigned long _Length, wchar_t* _Buffer) noexcept;

	// Changes the current directory for the current process.
	XANADU_CORE_EXPORT int XANADUAPI SetCurrentDirectoryA(const char* _PathName) noexcept;

	// Changes the current directory for the current process.
	XANADU_CORE_EXPORT int XANADUAPI SetCurrentDirectoryW(const wchar_t* _PathName) noexcept;
}





// Thread operation
#if defined(_XANADU_SYSTEM_WINDOWS)
typedef			unsigned long						pthread_t;
#endif
namespace Xanadu
{
	// This function returns the thread identifier
	XANADU_CORE_EXPORT unsigned long XANADUAPI GetCurrentThreadId() noexcept;

	// This function returns the thread identifier
	XANADU_CORE_EXPORT pthread_t XANADUAPI gettid() noexcept;
}





// Program support utilities
// https://en.cppreference.com/w/cpp/utility/program/system
namespace Xanadu
{
	// Calls the host environment's command processor (e.g. /bin/sh, cmd.exe, command.com) with the parameter command.
	XANADU_CORE_EXPORT int XANADUAPI system(const char* _Command) noexcept;

	// Calls the host environment's command processor (e.g. /bin/sh, cmd.exe, command.com) with the parameter command.
	XANADU_CORE_EXPORT int XANADUAPI wsystem(const wchar_t* _Command) noexcept;

	// Returns a pointer to the textual description of the system error code errnum
	XANADU_CORE_EXPORT char* XANADUAPI strerror(int _Error) noexcept;

	// Returns a pointer to the textual description of the system error code errnum
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wcserror(int _Error) noexcept;

	// be used to direct the operating system to flush all file system data to disk
	XANADU_CORE_EXPORT void XANADUAPI sync() noexcept;

	// get an identifier for the current host
	XANADU_CORE_EXPORT long long XANADUAPI gethostid() noexcept;
};





// Memory map file
#if defined(_XANADU_COMPILE_MSVC)

#define PROT_NONE       0
#define PROT_READ       1
#define PROT_WRITE      2
#define PROT_EXEC       4

#define MAP_FILE        0
#define MAP_SHARED      1
#define MAP_PRIVATE     2
#define MAP_TYPE        0xf
#define MAP_FIXED       0x10
#define MAP_ANONYMOUS   0x20
#define MAP_ANON        MAP_ANONYMOUS

#define MAP_FAILED      ((void *)-1)

// Flags for msync
#define MS_ASYNC        1
#define MS_SYNC         2
#define MS_INVALIDATE   4

#endif
namespace Xanadu
{
	// creates  a  new  mapping  in the virtual address space of the calling process.
	XANADU_CORE_EXPORT void* XANADUAPI mmap(void* _Addr, size_t _Length, int _Prot, int _Flags, int _Fildes, off_t _Off) noexcept;

	// deletes the mappings for the specified address range
	XANADU_CORE_EXPORT int XANADUAPI munmap(void* _Addr, size_t _Length) noexcept;

	// changes  protection  for the calling process's memory page(s) containing any part of the address range in the interval [addr, addr+len-1].
	XANADU_CORE_EXPORT int XANADUAPI mprotect(void* _Addr, size_t _Length, int _Prot) noexcept;

	// flushes changes made to the in-core copy of a file that was mapped into memory using mmap back to the filesystem.
	XANADU_CORE_EXPORT int XANADUAPI msync(void* _Addr, size_t _Length, int _Flags) noexcept;

	// lock part or all of the calling process's virtual address space into RAM
	XANADU_CORE_EXPORT int XANADUAPI mlock(const void* _Addr, size_t _Length) noexcept;

	// unlocking part  or  all  of  the  calling process's  virtual address space
	XANADU_CORE_EXPORT int XANADUAPI munlock(const void* _Addr, size_t _Length) noexcept;
}




// Filesystem operation
#if defined(_XANADU_SYSTEM_WINDOWS)
#define			R_OK							4			// Read-only
#define			W_OK							2			// Write-only
#define			X_OK							1			// The executable
#define			F_OK							0			// Existence only

#define			S_IRWXU							0000700			// RWX mask for owner
#define			S_IRUSR							0000400			// R for owner
#define			S_IWUSR							0000200			// W for owner
#define			S_IXUSR							0000100			// X for owner

#define			S_IRWXG							0000070			// RWX mask for group
#define			S_IRGRP							0000040			// R for group
#define			S_IWGRP							0000020			// W for group
#define			S_IXGRP							0000010			// X for group

#define			S_IRWXO							0000007			// RWX mask for other
#define			S_IROTH							0000004			// R for other
#define			S_IWOTH							0000002			// W for other
#define			S_IXOTH							0000001			// X for other

#define			S_ISUID							0004000			// set user id on execution
#define			S_ISGID							0002000			// set group id on execution
#define			S_ISVTX							0001000			// save swapped text even after use
#endif
#if defined(_XANADU_SYSTEM_WINDOWS)
typedef			struct _stat64						XStat64;
#else
typedef			struct stat64						XStat64;
#endif
namespace Xanadu
{
	// Check file properties
	XANADU_CORE_EXPORT int XANADUAPI access(const char* _Path, int _Mode) noexcept;

	// Check file properties
	XANADU_CORE_EXPORT int XANADUAPI waccess(const wchar_t* _Path, int _Mode) noexcept;

	// Associate the stream with a file that was previously opened for low-level I/O.
	XANADU_CORE_EXPORT FILE* XANADUAPI fdopen(int _Fildes, const char* _Mode) noexcept;

	// Associate the stream with a file that was previously opened for low-level I/O.
	XANADU_CORE_EXPORT FILE* XANADUAPI wfdopen(int _Fildes, const wchar_t* _Mode) noexcept;

	// Reallocate the file pointer
	XANADU_CORE_EXPORT FILE* XANADUAPI freopen(const char* _Filename, const char* _Mode, FILE* _Stream) noexcept;

	// Reallocate the file pointer
	XANADU_CORE_EXPORT FILE* XANADUAPI wfreopen(const wchar_t* _Filename, const wchar_t* _Mode, FILE* _Stream) noexcept;

	// Open file
	XANADU_CORE_EXPORT FILE* XANADUAPI fopen(const char* _File, const char* _Mode) noexcept;

	// Open file
	XANADU_CORE_EXPORT FILE* XANADUAPI wfopen(const wchar_t* _File, const wchar_t* _Mode) noexcept;

	// Moves the file pointer to a specified location.
	XANADU_CORE_EXPORT int XANADUAPI fseek(FILE* _Stream, long long _Offset, int _Origin) noexcept;

	// Gets the current position of a file pointer.
	XANADU_CORE_EXPORT long long XANADUAPI ftell(FILE* _Stream) noexcept;

	// Reads data from a stream.
	XANADU_CORE_EXPORT size_t XANADUAPI fread(void* _Buffer, size_t _Size, size_t _Count, FILE* _Stream) noexcept;

	// Reads data from a stream.
	XANADU_CORE_EXPORT bool XANADUAPI fread(FILE* _Stream, void* _Buffer, size_t _Size) noexcept;

	// Writes data to a stream.
	XANADU_CORE_EXPORT size_t XANADUAPI fwrite(const void* _Buffer, size_t _Size, size_t _Count, FILE* _Stream) noexcept;

	// Writes data to a stream.
	XANADU_CORE_EXPORT bool XANADUAPI fwrite(FILE* _Stream, const void* _Buffer, size_t _Size) noexcept;

	// Flushes a stream.
	XANADU_CORE_EXPORT int XANADUAPI fflush(FILE* _Stream) noexcept;

	// Sync a stream.
	XANADU_CORE_EXPORT int XANADUAPI fsync(int _Fildes) noexcept;

	// Read a character from a stream.
	XANADU_CORE_EXPORT int XANADUAPI fgetc(FILE* _Stream) noexcept;

	// Get a string from a stream.
	XANADU_CORE_EXPORT char* XANADUAPI fgets(char* _Buffer, int _MaxCount, FILE* _Stream) noexcept;

	// Gets the file handle associated with a stream.
	XANADU_CORE_EXPORT int XANADUAPI fileno(FILE* _Stream) noexcept;

	// Tests for end-of-file on a stream.
	XANADU_CORE_EXPORT int XANADUAPI feof(FILE* _Stream) noexcept;

	// Tests for an error on a stream.
	XANADU_CORE_EXPORT int XANADUAPI ferror(FILE* _Stream) noexcept;

	// Closes a stream
	XANADU_CORE_EXPORT int XANADUAPI fclose(FILE* _Stream) noexcept;

	// Deletes a directory.
	XANADU_CORE_EXPORT int XANADUAPI rmdir(const char* _Path) noexcept;

	// Deletes a directory.
	XANADU_CORE_EXPORT int XANADUAPI wrmdir(const wchar_t* _Path) noexcept;

	// Creates a new directory. This call integrates the chmod operation internally
	XANADU_CORE_EXPORT int XANADUAPI mkdir(const char* _Path, int _Mode = 0755) noexcept;

	// Creates a new directory. This call integrates the chmod operation internally
	XANADU_CORE_EXPORT int XANADUAPI wmkdir(const wchar_t* _Path, int _Mode = 0755) noexcept;

	// Changes the file-permission settings.
	XANADU_CORE_EXPORT int XANADUAPI chmod(const char* _Path, int _Mode = 0755) noexcept;

	// Changes the file-permission settings.
	XANADU_CORE_EXPORT int XANADUAPI wchmod(const wchar_t* _Path, int _Mode = 0755) noexcept;

	// Delete a file.
	XANADU_CORE_EXPORT int XANADUAPI remove(const char* _Path) noexcept;

	// Delete a file.
	XANADU_CORE_EXPORT int XANADUAPI wremove(const wchar_t* _Path) noexcept;

	// Rename a file or directory.
	XANADU_CORE_EXPORT int XANADUAPI rename(const char* _Old, const char* _New) noexcept;

	// Rename a file or directory.
	XANADU_CORE_EXPORT int XANADUAPI wrename(const wchar_t* _Old, const wchar_t* _New) noexcept;

	// Get file information according to file pointer
	XANADU_CORE_EXPORT int XANADUAPI fstat64(int _FileHandle, XStat64* _Stat) noexcept;

	// Get file information according to file path
	XANADU_CORE_EXPORT int XANADUAPI stat64(const char* _FileName, XStat64* _Stat) noexcept;

	// Get file information according to file path
	XANADU_CORE_EXPORT int XANADUAPI wstat64(const wchar_t* _FileName, XStat64* _Stat) noexcept;
}





// Xanadu: Filesystem operation extend

// File information (ASCII)
typedef struct _XANADU_RUNTIME_FILE_INFO_A
{
	char 			path[XANADU_PATH];		// The file path
	char 			name[XANADU_PATH];		// The file name
	bool			isDir;				// Is it a directory
}XANADU_RUNTIME_FILE_INFO_A;

// File information (UNICODE)
typedef struct _XANADU_RUNTIME_FILE_INFO_W
{
	wchar_t 		path[XANADU_PATH];		// The file path
	wchar_t 		name[XANADU_PATH];		// The file name
	bool			isDir;				// Is it a directory
}XANADU_RUNTIME_FILE_INFO_W;

#ifdef UNICODE
#define	XANADU_RUNTIME_FILE_INFO				XANADU_RUNTIME_FILE_INFO_W
#else
#define	XANADU_RUNTIME_FILE_INFO				XANADU_RUNTIME_FILE_INFO_A
#endif

// A pointer to a callback function while traversing a directory
typedef bool(XANADUAPI *_XFunctionTraverseDirectoryA)(const XANADU_RUNTIME_FILE_INFO_A* _FileInfo, void* _UserData);
typedef bool(XANADUAPI *_XFunctionTraverseDirectoryW)(const XANADU_RUNTIME_FILE_INFO_W* _FileInfo, void* _UserData);

namespace Xanadu
{
	// Get file size
	XANADU_CORE_EXPORT unsigned long long XANADUAPI fsize(const char* _FilePath) noexcept;

	// Get file size
	XANADU_CORE_EXPORT unsigned long long XANADUAPI wfsize(const wchar_t* _FilePath) noexcept;

	// Copy file data. The maximum buffer size is 1MB(XANADU_SIZE_MB)
	XANADU_CORE_EXPORT int XANADUAPI fcopy(const char* _ExistingFileName, const char* _NewFileName) noexcept;

	// Copy file data. The maximum buffer size is 1MB(XANADU_SIZE_MB)
	XANADU_CORE_EXPORT int XANADUAPI wfcopy(const wchar_t* _ExistingFileName, const wchar_t* _NewFileName) noexcept;

	// Format path. Replace \\ with /, removing the last bit of /.
	XANADU_CORE_EXPORT char* XANADUAPI fmtpath(const char* _Path) noexcept;

	// Format path. Replace \\ with /, removing the last bit of /.
	XANADU_CORE_EXPORT wchar_t* XANADUAPI wfmtpath(const wchar_t* _Path) noexcept;

	// Create a multi-level directory.
	XANADU_CORE_EXPORT int XANADUAPI mkpath(const char* _Directory, int _Mode) noexcept;

	// Create a multi-level directory.
	XANADU_CORE_EXPORT int XANADUAPI wmkpath(const wchar_t* _Directory, int _Mode) noexcept;

	// Directory traverse
	XANADU_CORE_EXPORT int XANADUAPI traversedir(const char* _Directory, _XFunctionTraverseDirectoryA _Function, void* _UserData) noexcept;

	// Directory traverse
	XANADU_CORE_EXPORT int XANADUAPI wtraversedir(const wchar_t* _Directory, _XFunctionTraverseDirectoryW _Function, void* _UserData) noexcept;
}





// Socket operation
#ifndef _XANADU_SYSTEM_WINDOWS
typedef			int							SOCKET;
#define			INVALID_SOCKET						(SOCKET)(~0)
#define			SOCKET_ERROR						(SOCKET)(-1)
#endif
namespace Xanadu
{
	// retrieves host information corresponding to a host name from a host database.
	XANADU_CORE_EXPORT struct hostent* XANADUAPI gethostbyname(const char* _Name) noexcept;

	// creates a socket that is bound to a specific service provider.
	XANADU_CORE_EXPORT SOCKET XANADUAPI socket(int _Family, int _Type, int _Protocol) noexcept;

	// permits an incoming connection attempt on a socket.
	XANADU_CORE_EXPORT SOCKET XANADUAPI accept(SOCKET _Socket, struct sockaddr* _Address, socklen_t* _Length) noexcept;

	// associates a local address with a socket.
	XANADU_CORE_EXPORT int XANADUAPI bind(SOCKET _Socket, const struct sockaddr* _Address, socklen_t _Length) noexcept;

	// close socket
	XANADU_CORE_EXPORT int XANADUAPI socketclose(SOCKET _Socket) noexcept;

	// establishes a connection to a specified socket.
	XANADU_CORE_EXPORT int XANADUAPI connect(SOCKET _Socket, const struct sockaddr* _Address, socklen_t _Length) noexcept;

	// retrieves the address of the peer to which a socket is connected.
	XANADU_CORE_EXPORT int XANADUAPI getpeername(SOCKET _Socket, struct sockaddr* _Address, socklen_t* _Length) noexcept;

	// retrieves the local name for a socket.
	XANADU_CORE_EXPORT int XANADUAPI getsockname(SOCKET _Socket, struct sockaddr* _Address, socklen_t* _Length) noexcept;

	// gets a socket option.
	XANADU_CORE_EXPORT int XANADUAPI getsockopt(SOCKET _Socket, int _Level, int _OptName, void* _OptValue, socklen_t* _OptLength) noexcept;

	// sets a socket option.
	XANADU_CORE_EXPORT int XANADUAPI setsockopt(SOCKET _Socket, int level, int _OptName, const void* _OptValue, socklen_t _OptLength) noexcept;

	// converts a string containing an (Ipv4) Internet Protocol dotted address into a proper address for the in_addr structure.
	XANADU_CORE_EXPORT struct in_addr XANADUAPI inet_addr(const char* _CP) noexcept;

	// converts an (Ipv4) Internet network address into a string in Internet standard dotted format.
	XANADU_CORE_EXPORT char* XANADUAPI inet_ntoa(struct in_addr _IN) noexcept;

	// places a socket at a state where it is listening for an incoming connection.
	XANADU_CORE_EXPORT int XANADUAPI listen(SOCKET _Socket, int _Backlog) noexcept;

	// receives data from a connected socket.
	XANADU_CORE_EXPORT int XANADUAPI recv(SOCKET _Socket, void* _Buffer, int _Length, int _Flags) noexcept;

	// receives a datagram and stores the source address.
	XANADU_CORE_EXPORT int XANADUAPI recvfrom(SOCKET _Socket, void* _Buffer, int _Length, int _Flags, struct sockaddr* _From, socklen_t* _Fromlen) noexcept;

	// sends data on a connected socket.
	XANADU_CORE_EXPORT int XANADUAPI send(SOCKET _Socket, const void* _Buffer, int _Length, int _Flags) noexcept;

	// sends data to a specific destination.
	XANADU_CORE_EXPORT int XANADUAPI sendto(SOCKET _Socket, const void* _Buffer, int _Length, int _Flags, const struct sockaddr* _To, socklen_t _Tolen) noexcept;

	// disables sends or receives on a socket.
	XANADU_CORE_EXPORT int XANADUAPI shutdown(SOCKET _Socket, int _Now) noexcept;

	// determines the status of one or more sockets, waiting if necessary, to perform synchronous I/O.
	XANADU_CORE_EXPORT int XANADUAPI select(int _Fds, fd_set* _ReadFds, fd_set* _WriteFds, fd_set* _ExceptFds, struct timeval* _Timeout) noexcept;
};

#endif

































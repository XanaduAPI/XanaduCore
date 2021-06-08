#include <XanaduRuntime/Memory.h>
#include <cstdlib>
#include <cstring>

// 分配内存块
XANADU_RUNTIME_EXPORT void* XANADUAPI Xanadu::malloc(size_t _Size) noexcept
{
	return Xanadu::memset(std::malloc(_Size), 0, _Size);
}

// 在内存的动态存储区中分配 _Count 个长度为 _Size 的连续空间
XANADU_RUNTIME_EXPORT void* XANADUAPI Xanadu::calloc(size_t _Count, size_t _Size) noexcept
{
	return std::calloc(_Count, _Size);
}

// 重新分配内存块
XANADU_RUNTIME_EXPORT void* XANADUAPI Xanadu::realloc(void* _Block, size_t _Size) noexcept
{
	return Xanadu::memset(std::realloc(_Block, _Size), 0, _Size);
}

// 释放内存块，可以释放由 malloc()、calloc()、realloc() 等函数申请的内存空间
XANADU_RUNTIME_EXPORT void XANADUAPI Xanadu::free(void* _Memory) noexcept
{
	XANADU_CHECK_RETURN(_Memory);

	return std::free(_Memory);
}

// 从 _Buf 所指内存区域的前 _MaxCount 个字节查找字符 _Val
XANADU_RUNTIME_EXPORT const void* XANADUAPI Xanadu::memchr(const void* _Buf, int _Val, size_t _MaxCount) noexcept
{
	XANADU_CHECK_RETURN(_Buf, nullptr);

	return std::memchr(_Buf, _Val, _MaxCount);
}

// 按字节比较 _Buf1 和 _Buf2 的值，最多比较 _Size 个字节
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::memcmp(const void* _Buf1, const void* _Buf2, size_t _Size) noexcept
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

// 从 _Src 的起始位置开始拷贝 _Size 个字节到 _Dst 中
XANADU_RUNTIME_EXPORT void* XANADUAPI Xanadu::memcpy(void* _Dst, const void* _Src, size_t _Size) noexcept
{
	XANADU_CHECK_RETURN(_Dst, nullptr);
	XANADU_CHECK_RETURN(_Src, nullptr);

	return std::memcpy(_Dst, _Src, _Size);
}

// 从 _Src 的起始位置开始拷贝 _Size 个字节到 _Dst 中
XANADU_RUNTIME_EXPORT void* XANADUAPI Xanadu::memcpy(void* _Dst, size_t _Length, const void* _Src, size_t _Size) noexcept
{
	XANADU_UNPARAMETER(_Length);

	return Xanadu::memcpy(_Dst, _Src, _Size);
}

// 将 _Size 字节的字符从 _Src 复制到 _Dst
XANADU_RUNTIME_EXPORT void* XANADUAPI Xanadu::memmove(void* _Dst, const void* _Src, size_t _Size) noexcept
{
	XANADU_CHECK_RETURN(_Dst, nullptr);
	XANADU_CHECK_RETURN(_Src, nullptr);

	return std::memmove(_Dst, _Src, _Size);
}

// 将 _Buffer 的最多 _Size 个长度的内存设置为字符 _Value
XANADU_RUNTIME_EXPORT void* XANADUAPI Xanadu::memset(void* _Buffer, int _Value, size_t _Size) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, nullptr);

	return std::memset(_Buffer, _Value, _Size);
}

// 从 _Buf 所指内存区域的前 _MaxCount 个字节查找字符 _Val
XANADU_RUNTIME_EXPORT const wchar_t* XANADUAPI Xanadu::wmemchr(const wchar_t* _S, wchar_t _C, size_t _N) noexcept
{
	XANADU_CHECK_RETURN(_S, nullptr);

	for(; 0 < _N; ++_S, --_N)
	{
		if(*_S == _C)
		{
			return (const wchar_t*)_S;
		}
	}
	return nullptr;
}

// 按字节比较 _Buf1 和 _Buf2 的值，最多比较 _Size 个字节
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wmemcmp(const wchar_t* _S1, const wchar_t* _S2, size_t _N) noexcept
{
	if (_S1 == _S2)
	{
		return 0;
	}
	if (_S1 && _S2)
	{
		for(; 0 < _N; ++_S1, ++_S2, --_N)
		{
			if(*_S1 != *_S2)
			{
				return *_S1 < *_S2 ? -1 : 1;
			}
		}
		return 0;
	}
	else if(_S1)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

// 从 _Src 的起始位置开始拷贝 _Size 个字节到 _Dst 中
XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wmemcpy(wchar_t* _S1, const wchar_t* _S2, size_t _N) noexcept
{
	XANADU_CHECK_RETURN(_S1, nullptr);
	XANADU_CHECK_RETURN(_S2, nullptr);

	return (wchar_t*)std::memcpy(_S1, _S2, _N * sizeof(wchar_t));
}

// 从 _Src 的起始位置开始拷贝 _Size 个字节到 _Dst 中
XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wmemcpy(wchar_t* _Dst, size_t _Length, const wchar_t* _Src, size_t _Size) noexcept
{
	XANADU_UNPARAMETER(_Length);

	return Xanadu::wmemcpy(_Dst, _Src, _Size);
}

// 将 _Size 字节的字符从 _Src 复制到 _Dst
XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wmemmove(wchar_t* _S1, const wchar_t* _S2, size_t _N) noexcept
{
	XANADU_CHECK_RETURN(_S1, nullptr);
	XANADU_CHECK_RETURN(_S2, nullptr);

	return (wchar_t*)std::memmove(_S1, _S2, _N * sizeof(wchar_t));
}

// 将 _Buffer 的最多 _Size 个长度的内存设置为字符 _Value
XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wmemset(wchar_t* _S, wchar_t _C, size_t _N) noexcept
{
	XANADU_CHECK_RETURN(_S, nullptr);

	auto		_Su = _S;
	for(; 0 < _N; ++_Su, --_N)
	{
		*_Su = _C;
	}
	return _S;
}

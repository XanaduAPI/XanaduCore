#ifndef			_XANADU_RUNTIME_MEMORY_H_
#define			_XANADU_RUNTIME_MEMORY_H_

#include <XanaduRuntime/Header.h>

#define			XANADU_MALLOC(_Size)					Xanadu::malloc(_Size)
#define			XANADU_FREE(_Value)					if(_Value){ Xanadu::free(_Value); _Value = nullptr;}

namespace Xanadu
{
	// <summary>
	// 分配内存块
	// </summary>
	// <param name="_Size">要分配的字节</param>
	// <returns>如果成功 malloc（）函数将返回指向已分配内存的指针。如果有错误，则返回空指针并将 errno 设置为 ENOMEM</returns>
	XANADU_RUNTIME_EXPORT void* XANADUAPI malloc(size_t _Size) noexcept;

	// <summary>
	// 在内存的动态存储区中分配 _Count 个长度为 _Size 的连续空间
	// </summary>
	// <param name="_Count">元素的个数</param>
	// <param name="_Size">每个元素的字节长度</param>
	// <returns>如果成功 calloc（）函数将返回指向已分配内存的指针。如果有错误，则返回空指针并将 errno 设置为 ENOMEM</returns>
	XANADU_RUNTIME_EXPORT void* XANADUAPI calloc(size_t _Count, size_t _Size) noexcept;

	// <summary>
	// 重新分配内存块
	// </summary>
	// <param name="_Block">以前申请的内存块指针</param>
	// <param name="_Size">新的大小 (以字节为单位)</param>
	// <returns>如果成功 realloc（）函数将返回指向已分配内存的指针。如果有错误，则返回空指针并将 errno 设置为 ENOMEM，但输入指针仍然有效</returns>
	XANADU_RUNTIME_EXPORT void* XANADUAPI realloc(void* _Block, size_t _Size) noexcept;

	// <summary>
	// 释放内存块，可以释放由 malloc()、calloc()、realloc() 等函数申请的内存空间
	// </summary>
	// <param name="_Memory">以前申请的内存块指针</param>
	// <returns>无</returns>
	XANADU_RUNTIME_EXPORT void XANADUAPI free(void* _Memory) noexcept;

	// <summary>
	// 从 _Buf 所指内存区域的前 _MaxCount 个字节查找字符 _Val
	// </summary>
	// <param name="_Buf">缓冲区的指针</param>
	// <param name="_Val">查找的字符</param>
	// <param name="_MaxCount">查找的字符数</param>
	// <returns>如果成功，则返回 _Buf 指向 _Val 的第一个位置。否则返回 NULL</returns>
	XANADU_RUNTIME_EXPORT const void* XANADUAPI memchr(const void* _Buf, int _Val, size_t _MaxCount) noexcept;

	// <summary>
	// 按字节比较 _Buf1 和 _Buf2 的值，最多比较 _Size 个字节
	// </summary>
	// <param name="_Buf1">指向内存块1的指针</param>
	// <param name="_Buf2">指向内存块2的指针</param>
	// <param name="_Size">要被比较的字节数</param>
	// <returns>如果返回值 < 0，则表示 _Buf1 小于 _Buf2</returns>
	// <returns>如果返回值 > 0，则表示 _Buf1 大于 _Buf2</returns>
	// <returns>如果返回值 = 0，则表示 _Buf1 等于 _Buf2</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI memcmp(const void* _Buf1, const void* _Buf2, size_t _Size) noexcept;

	// <summary>
	// 从 _Src 的起始位置开始拷贝 _Size 个字节到 _Dst 中
	// </summary>
	// <param name="_Dst">指向用于存储复制内容的目标数组</param>
	// <param name="_Src">指向要复制的数据源</param>
	// <param name="_Size">要被复制的字节数</param>
	// <returns>返回指向 _Dst 的指针</returns>
	XANADU_RUNTIME_EXPORT void* XANADUAPI memcpy(void* _Dst, const void* _Src, size_t _Size) noexcept;

	// <summary>
	// 从 _Src 的起始位置开始拷贝 _Size 个字节到 _Dst 中
	// </summary>
	// <param name="_Dst">指向用于存储复制内容的目标数组</param>
	// <param name="_Length">指示 _Dst 的长度</param>
	// <param name="_Src">指向要复制的数据源</param>
	// <param name="_Size">要被复制的字节数</param>
	// <returns>返回指向 _Dst 的指针</returns>
	XANADU_RUNTIME_EXPORT void* XANADUAPI memcpy(void* _Dst, size_t _Length, const void* _Src, size_t _Size) noexcept;

	// <summary>
	// 将 _Size 字节的字符从 _Src 复制到 _Dst
	// 如果源区域和目标区域的某些区域重叠，memmove会确保在覆盖重叠区域中的原始源字节被复制
	// 但是当目标区域与源区域没有重叠则和memcpy函数功能相同
	// </summary>
	// <param name="_Dst">指向用于存储复制内容的目标数组</param>
	// <param name="_Src">指向要复制的数据源</param>
	// <param name="_Size">要被复制的字节数</param>
	// <returns>返回指向 _Dst 的指针</returns>
	XANADU_RUNTIME_EXPORT void* XANADUAPI memmove(void* _Dst, const void* _Src, size_t _Size) noexcept;

	// <summary>
	// 将 _Buffer 的最多 _Size 个长度的内存设置为字符 _Value
	// 这个函数通常为新申请的内存做初始化工作
	// </summary>
	// <param name="_Buffer">指向要设置的内存地址</param>
	// <param name="_Value">要设置的值</param>
	// <param name="_Size">要设置的字节数</param>
	// <returns>返回指向 _Dst 的指针</returns>
	XANADU_RUNTIME_EXPORT void* XANADUAPI memset(void* _Buffer, int _Value, size_t _Size) noexcept;

	// <summary>
	// 从 _Buf 所指内存区域的前 _MaxCount 个字节查找字符 _Val
	// memchr() 的宽字节版本
	// </summary>
	// <param name="_S">缓冲区的指针</param>
	// <param name="_C">查找的字符</param>
	// <param name="_N">查找的字符数</param>
	// <returns>如果成功，则返回 _Buf 指向 _Val 的第一个位置。否则返回 NULL</returns>
	XANADU_RUNTIME_EXPORT const wchar_t* XANADUAPI wmemchr(const wchar_t* _S, wchar_t _C, size_t _N) noexcept;

	// <summary>
	// 按字节比较 _Buf1 和 _Buf2 的值，最多比较 _Size 个字节
	// memcmp() 的宽字节版本
	// </summary>
	// <param name="_S1">指向内存块1的指针</param>
	// <param name="_S2">指向内存块2的指针</param>
	// <param name="_N">要被比较的字节数</param>
	// <returns>如果返回值 < 0，则表示 _Buf1 小于 _Buf2</returns>
	// <returns>如果返回值 > 0，则表示 _Buf1 大于 _Buf2</returns>
	// <returns>如果返回值 = 0，则表示 _Buf1 等于 _Buf2</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI wmemcmp(const wchar_t* _S1, const wchar_t* _S2, size_t _N) noexcept;

	// <summary>
	// 从 _Src 的起始位置开始拷贝 _Size 个字节到 _Dst 中
	// memcpy() 的宽字节版本
	// </summary>
	// <param name="_S1">指向用于存储复制内容的目标数组</param>
	// <param name="_S2">指向要复制的数据源</param>
	// <param name="_N">要被复制的字节数</param>
	// <returns>返回指向 _S1 的指针</returns>
	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wmemcpy(wchar_t* _S1, const wchar_t* _S2, size_t _N) noexcept;

	// <summary>
	// 从 _Src 的起始位置开始拷贝 _Size 个字节到 _Dst 中
	// memcpy() 的宽字节版本
	// </summary>
	// <param name="_S1">指向用于存储复制内容的目标数组</param>
	// <param name="_Length">指示 _Dst 的长度</param>
	// <param name="_S2">指向要复制的数据源</param>
	// <param name="_N">要被复制的字节数</param>
	// <returns>返回指向 _S1 的指针</returns>
	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wmemcpy(wchar_t* _S1, size_t _Length, const wchar_t* _S2, size_t _N) noexcept;

	// <summary>
	// 将 _Size 字节的字符从 _Src 复制到 _Dst
	// 如果源区域和目标区域的某些区域重叠，memmove会确保在覆盖重叠区域中的原始源字节被复制
	// 但是当目标区域与源区域没有重叠则和memcpy函数功能相同
	// memmove() 的宽字节版本
	// </summary>
	// <param name="_S1">指向用于存储复制内容的目标数组</param>
	// <param name="_S2">指向要复制的数据源</param>
	// <param name="_N">要被复制的字节数</param>
	// <returns>返回指向 _S1 的指针</returns>
	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wmemmove(wchar_t* _S1, const wchar_t* _S2, size_t _N) noexcept;

	// <summary>
	// 将 _Buffer 的最多 _Size 个长度的内存设置为字符 _Value
	// 这个函数通常为新申请的内存做初始化工作
	// memset() 的宽字节版本
	// </summary>
	// <param name="_S">指向要设置的内存地址</param>
	// <param name="_C">要设置的值</param>
	// <param name="_N">要设置的字节数</param>
	// <returns>返回指向 _S 的指针</returns>
	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wmemset(wchar_t* _S, wchar_t _C, size_t _N) noexcept;
};

#endif

#ifndef			_XANADU_RUNTIME_SYSTEM_H_
#define			_XANADU_RUNTIME_SYSTEM_H_

#include <XanaduRuntime/Header.h>

namespace Xanadu
{
	// <summary>
	// 执行命令。
	// </summary>
	// <param name="_Command">要执行的命令。</param>
	// <returns>如果command为NULL并且找到了命令解释器，则返回非零值。如果找不到命令解释器，则返回0并将errno设置为ENOENT。
	// 如果command不为NULL，则系统返回命令解释器返回的值。仅当命令解释器返回值0时，它才返回值0。返回值-1表示错误，并且errno设置为以下值之一：</returns>
	// <returns>E2BIG: 参数列表（取决于系统）太大。</returns>
	// <returns>ENOENT: 找不到命令解释器。</returns>
	// <returns>ENOEXEC: 由于格式无效，因此无法执行命令解释器文件。</returns>
	// <returns>ENOMEM: 没有足够的内存来执行命令；或可用内存已损坏；或存在无效的块，这表示进行调用的进程未正确分配。</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI system(const char* _Command) noexcept;

	// <summary>
	// 执行命令。
	// </summary>
	// <param name="_Command">要执行的命令。</param>
	// <returns>如果command为NULL并且找到了命令解释器，则返回非零值。如果找不到命令解释器，则返回0并将errno设置为ENOENT。
	// 如果command不为NULL，则系统返回命令解释器返回的值。仅当命令解释器返回值0时，它才返回值0。返回值-1表示错误，并且errno设置为以下值之一：</returns>
	// <returns>E2BIG: 参数列表（取决于系统）太大。</returns>
	// <returns>ENOENT: 找不到命令解释器。</returns>
	// <returns>ENOEXEC: 由于格式无效，因此无法执行命令解释器文件。</returns>
	// <returns>ENOMEM: 没有足够的内存来执行命令；或可用内存已损坏；或存在无效的块，这表示进行调用的进程未正确分配。</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI wsystem(const wchar_t* _Command) noexcept;

	// <summary>
	// 获取系统错误消息字符串
	// </summary>
	// <param name="_Error">错误号。</param>
	// <returns>所有这些函数都在运行时拥有的线程本地存储缓冲区中返回一个指向错误消息字符串的指针。以后在同一线程上的调用可以覆盖此字符串。</returns>
	XANADU_RUNTIME_EXPORT char* XANADUAPI strerror(int _Error) noexcept;

	// <summary>
	// 获取系统错误消息字符串
	// </summary>
	// <param name="_Error">错误号。</param>
	// <returns>所有这些函数都在运行时拥有的线程本地存储缓冲区中返回一个指向错误消息字符串的指针。以后在同一线程上的调用可以覆盖此字符串。</returns>
	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wcserror(int _Error) noexcept;

	// <summary>
	// 强制将块缓存区中修改写入磁盘。
	// 内核将这些信息保存在内核中，以减少系统所需的磁盘I/O传输数量。
	// 由于缓存中的信息在系统崩溃后丢失，用户进程更新(8)频繁地发出sync()调用(大约每30秒)。
	//
	// 在Windows中没有调用任何函数。
	// </summary>
	// <returns></returns>
	XANADU_RUNTIME_EXPORT void XANADUAPI sync() noexcept;

	// <summary>
	// 获取本机的HostID
	// 在Windows上则由第一张网卡地址转换而成
	// </summary>
	// <returns>一个48位的整型表示的HostID</returns>
	XANADU_RUNTIME_EXPORT long long XANADUAPI gethostid() noexcept;
};

namespace Xanadu
{
	// <summary>
	// 检索当前进程的当前工作目录。
	// </summary>
	// <param name="_Buffer">路径的存储位置。</param>
	// <param name="_Size">路径的最大长度（以char为单位）</param>
	// <returns>返回指向缓冲区的指针。返回值NULL表示错误，并且errno设置为ENOMEM（表示没有足够的内存来分配_Size字节）（当将NULL参数指定为缓冲区时），或者设置为ERANGE（表示路径长于_Size字符）。</returns>
	XANADU_RUNTIME_EXPORT char* XANADUAPI getcwd(char* _Buffer, size_t _Size) noexcept;

	// <summary>
	// 检索当前进程的当前工作目录。
	// </summary>
	// <param name="_Buffer">路径的存储位置。</param>
	// <param name="_Size">路径的最大长度（以wchar_t为单位）</param>
	// <returns>返回指向缓冲区的指针。返回值NULL表示错误，并且errno设置为ENOMEM（表示没有足够的内存来分配_Size字节）（当将NULL参数指定为缓冲区时），或者设置为ERANGE（表示路径长于_Size字符）。</returns>
	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wgetcwd(wchar_t* _Buffer, size_t _Size) noexcept;

	// <summary>
	// 更改当前进程的当前工作目录。
	// </summary>
	// <param name="_Dirname">新工作目录的路径。</param>
	// <returns>如果成功，这些函数将返回0值。返回值-1表示失败。</returns>
	// <returns>如果找不到指定的路径，则将errno设置为 ENOENT。</returns>
	// <returns>如果dirname为NULL，则将errno设置为 EINVAL，并且该函数返回-1。 </returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI chdir(const char* _Dirname) noexcept;

	// <summary>
	// 更改当前进程的当前工作目录。
	// </summary>
	// <param name="_Dirname">新工作目录的路径。</param>
	// <returns>如果成功，这些函数将返回0值。返回值-1表示失败。</returns>
	// <returns>如果找不到指定的路径，则将errno设置为 ENOENT。</returns>
	// <returns>如果dirname为NULL，则将errno设置为 EINVAL，并且该函数返回-1。 </returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI wchdir(const wchar_t* _Dirname) noexcept;

	// <summary>
	// 检索当前进程的当前工作目录。
	// </summary>
	// <param name="_Length">当前目录字符串的缓冲区长度，以char为单位。缓冲区长度必须包含用于终止空字符的空间。</param>
	// <param name="_Buffer">指向接收当前目录字符串的缓冲区的指针。该以空值结尾的字符串指定当前目录的绝对路径。若要确定所需的缓冲区大小，请将此参数设置为NULL，并将_Length参数设置为0。</param>
	// <returns>如果函数成功，则返回值指定写入缓冲区的字符数，不包括终止的空字符。</returns>
	// <returns>如果函数失败，则返回值为零。要获取扩展的错误信息，请调用GetLastError。</returns>
	// <returns>如果_Buffer指向的缓冲区不够大，则返回值以字符（包括以空终止的字符）指定缓冲区的所需大小。</returns>
	XANADU_RUNTIME_EXPORT unsigned long XANADUAPI GetCurrentDirectoryA(unsigned long _Length, char* _Buffer) noexcept;

	// <summary>
	// 检索当前进程的当前工作目录。
	// </summary>
	// <param name="_Length">当前目录字符串的缓冲区长度，以wchar_t为单位。缓冲区长度必须包含用于终止空字符的空间。</param>
	// <param name="_Buffer">指向接收当前目录字符串的缓冲区的指针。该以空值结尾的字符串指定当前目录的绝对路径。若要确定所需的缓冲区大小，请将此参数设置为NULL，并将_Length参数设置为0。</param>
	// <returns>如果函数成功，则返回值指定写入缓冲区的字符数，不包括终止的空字符。</returns>
	// <returns>如果函数失败，则返回值为零。要获取扩展的错误信息，请调用GetLastError。</returns>
	// <returns>如果_Buffer指向的缓冲区不够大，则返回值以字符（包括以空终止的字符）指定缓冲区的所需大小。</returns>
	XANADU_RUNTIME_EXPORT unsigned long XANADUAPI GetCurrentDirectoryW(unsigned long _Length, wchar_t* _Buffer) noexcept;

	// <summary>
	// 更改当前进程的当前工作目录。
	// </summary>
	// <param name="_PathName">新的当前目录的路径。此参数可以指定相对路径或完整路径。无论哪种情况，都会计算指定目录的完整路径并将其存储为当前目录。</param>
	// <returns>如果函数成功，则返回值为非零。</returns>
	// <returns>如果函数失败，则返回值为零。</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI SetCurrentDirectoryA(const char* _PathName) noexcept;

	// <summary>
	// 更改当前进程的当前工作目录。
	// </summary>
	// <param name="_PathName">新的当前目录的路径。此参数可以指定相对路径或完整路径。无论哪种情况，都会计算指定目录的完整路径并将其存储为当前目录。</param>
	// <returns>如果函数成功，则返回值为非零。</returns>
	// <returns>如果函数失败，则返回值为零。</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI SetCurrentDirectoryW(const wchar_t* _PathName) noexcept;
};

#endif

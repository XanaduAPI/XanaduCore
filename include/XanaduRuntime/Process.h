#ifndef			_XANADU_RUNTIME_PROCESS_H_
#define			_XANADU_RUNTIME_PROCESS_H_

#include <XanaduRuntime/Header.h>

namespace Xanadu
{
	// <summary>
	// 该函数返回调用进程的进程标识符。
	// </summary>
	// <returns>返回调用进程的进程标识符。</returns>
	XANADU_RUNTIME_EXPORT unsigned long XANADUAPI GetCurrentProcessId() noexcept;

	// <summary>
	// 该函数返回调用进程的进程标识符。
	// 这个ID保证是唯一的，并且对于构造临时文件名很有用。
	// </summary>
	// <returns>返回调用进程的进程ID。</returns>
	XANADU_RUNTIME_EXPORT long XANADUAPI getpid() noexcept;

	// <summary>
	// 杀死PID指定的进程
	// </summary>
	// <param name="_ProcessID">进程ID</param>
	// <param name="_Signal">要发送的信号</param>
	// <returns>成功返回0。否则，返回-1</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI kill(long _ProcessID, int _Signal) noexcept;
};

namespace Xanadu
{
	// <summary>
	// 运行外部程序。
	// </summary>
	// <param name="_Application">应用程序的完整路径。</param>
	// <param name="_Directory">要设置的运行目录。</param>
	// <param name="_Param">格式化的参数。</param>
	// <returns>如果成功了，没有任何返回。如果失败，则返回-1</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI execds(const char* _Application, const char* _Directory, const char* _Param) noexcept;

	// <summary>
	// 终止进程的调用过程。
	// </summary>
	// <param name="_Status">退出状态码。</param>
	// <returns>无</returns>
	XANADU_RUNTIME_EXPORT void XANADUAPI exit(int _Status) noexcept;

	// <summary>
	// 创建一个管道。然后异步执行命令处理程序的派生副本，并使用命令作为命令行。
	// </summary>
	// <param name="_Command">待执行的命令。</param>
	// <param name="_Mode">返回流的模式。</param>
	// <returns>返回与已创建管道的一端相关联的流。</returns>
	// <returns>管道的另一端与衍生命令的标准输入或标准输出相关联。</returns>
	// <returns>函数在出错时返回NULL。</returns>
	// <returns>如果错误是由无效参数引起的，errno被设置为EINVAL。</returns>
	XANADU_RUNTIME_EXPORT FILE* XANADUAPI popen(const char* _Command, const char* _Mode) noexcept;

	// <summary>
	// 查找由相关的popen()调用启动的命令处理程序的进程ID。在新的命令处理程序上执行_cwait调用，并在关联的管道上关闭流。
	// </summary>
	// <param name="_Stream">之前popen()调用返回的值。</param>
	// <returns>返回终止命令处理器的退出状态，如果发生错误则返回-1。</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI pclose(FILE* _Stream) noexcept;
};

#endif

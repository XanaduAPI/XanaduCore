#include <XanaduRuntime/Process.h>
#include <XanaduRuntime/Memory.h>
#include <XanaduRuntime/String.h>
#include <XanaduRuntime/System.h>

#include <list>
#include <string>

static std::list<std::string> XanaduParseCombinedArgString(const std::string& _Program)
{
	auto		vArgs = std::list<std::string>();
	auto 		vTemp = std::string();
	auto		vQuoteCount = 0;
	auto		vInQuote = false;

	// handle quoting. tokens can be surrounded by double quotes
	// "hello world". three consecutive double quotes represent
	// the quote character itself.
	for (auto vIndex = 0U; vIndex < _Program.size(); ++vIndex)
	{
		if (_Program.at(vIndex) == '\"')
		{
			++vQuoteCount;
			if (vQuoteCount == 3)
			{
				// third consecutive quote
				vQuoteCount = 0;
				vTemp += _Program.at(vIndex);
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
		if (!vInQuote && _Program.at(vIndex) == ' ')
		{
			if (!vTemp.empty())
			{
				vArgs.push_back(vTemp);
				vTemp.clear();
			}
		}
		else
		{
			vTemp += _Program.at(vIndex);
		}
	}
	if (!vTemp.empty())
	{
		vArgs.push_back(vTemp);
	}
	return vArgs;
}


// 该函数返回调用进程的进程标识符。
XANADU_RUNTIME_EXPORT unsigned long XANADUAPI Xanadu::GetCurrentProcessId() noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return ::GetCurrentProcessId();
#else
	return static_cast<unsigned long>(Xanadu::getpid());
#endif
}

// 该函数返回调用进程的进程标识符。
XANADU_RUNTIME_EXPORT long XANADUAPI Xanadu::getpid() noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return static_cast<long>(::GetCurrentProcessId());
#else
	return ::getpid();
#endif
}

// 杀死PID指定的进程
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::kill(long _ProcessID, int _Signal) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
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






// 运行外部程序。
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::execds(const char* _Application, const char* _Directory, const char* _Param) noexcept
{
	auto		vResult = -1;
	auto		vArgs = XanaduParseCombinedArgString(_Param ? _Param : "");
	auto		vCount = vArgs.size() + 2;
	auto		vList = (char**)XANADU_MALLOC(vCount);
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
				vList[vArgIndex] = (char*)XANADU_MALLOC(vIterator->size() + 1);
				Xanadu::strcpy(vList[vArgIndex], vIterator->data());
				vList[vArgIndex][vIterator->size()] = '\0';
			}
			++vArgIndex;
		}
	}

	// 我们需要改变工作目录
	Xanadu::chdir(_Directory);

	// 在这里调用exec系列函数
#if defined(XANADU_SYSTEM_WINDOWS)
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

// 终止进程的调用过程。
XANADU_RUNTIME_EXPORT void XANADUAPI Xanadu::exit(int _Status) noexcept
{
	::exit(_Status);
}

// 创建一个管道。然后异步执行命令处理程序的派生副本，并使用命令作为命令行。
XANADU_RUNTIME_EXPORT FILE* XANADUAPI Xanadu::popen(const char* _Command, const char* _Mode) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_popen(_Command, _Mode);
#else
	return ::popen(_Command, _Mode);
#endif
}

// 查找由相关的popen()调用启动的命令处理程序的进程ID。在新的命令处理程序上执行_cwait调用，并在关联的管道上关闭流。
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::pclose(FILE* _Stream) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_pclose(_Stream);
#else
	return ::pclose(_Stream);
#endif
}

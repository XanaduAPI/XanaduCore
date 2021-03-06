#ifndef			_XANADU_CORE_STREAM_H_
#define			_XANADU_CORE_STREAM_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>

enum ENUM_XANADU_DEBUG_LEVEL
{
	EXANADU_DEBUG_LEVEL_FULL = 0,
	EXANADU_DEBUG_LEVEL_INFO,
	EXANADU_DEBUG_LEVEL_WARNING,
	EXANADU_DEBUG_LEVEL_ERROR,
};

// Xanadu Class Stream
class XANADU_CORE_EXPORT XStream
{
public:
	XStream() noexcept;

	virtual ~XStream() noexcept;

public:
	// 启用日志级别
	static void setDebugLevel(ENUM_XANADU_DEBUG_LEVEL _Level = EXANADU_DEBUG_LEVEL_FULL) noexcept;

public:
	// 输出日志
	static void Output(const char* _Format, ...) noexcept;

	// 输出日志
	static void Output(const wchar_t* _Format, ...) noexcept;

	// 输出日志
	static void Output(const XString& _Format) noexcept;

public:
	// 输出日志:INFO
	static void Info(const char* _Format, ...) noexcept;

	// 输出日志:INFO
	static void Info(const wchar_t* _Format, ...) noexcept;

	// 输出日志:INFO
	static void Info(const XString& _Format) noexcept;;

public:
	// 输出日志:WARNING
	static void Warning(const char* _Format, ...) noexcept;

	// 输出日志:WARNING
	static void Warning(const wchar_t* _Format, ...) noexcept;

	// 输出日志:WARNING
	static void Warning(const XString& _Format) noexcept;

public:
	// 输出日志:ERROR
	static void Error(const char* _Format, ...) noexcept;

	// 输出日志:ERROR
	static void Error(const wchar_t* _Format, ...) noexcept;

	// 输出日志:ERROR
	static void Error(const XString& _Format) noexcept;
};

#ifdef XANADU_SYSTEM_WINDOWS
#define			XANADU_OUTPUT(_Format, ...)				XStream::Output(_Format, __VA_ARGS__)
#define			XANADU_INFO(_Format, ...)				XStream::Info(_Format, __VA_ARGS__)
#define			XANADU_WARNING(_Format, ...)				XStream::Warning(_Format, __VA_ARGS__)
#define			XANADU_ERROR(_Format, ...)				XStream::Error(_Format, __VA_ARGS__)
#else
#define			XANADU_OUTPUT						XStream::Output
#define			XANADU_INFO						XStream::Info
#define			XANADU_WARNING						XStream::Warning
#define			XANADU_ERROR						XStream::Error
#endif // XANADU_SYSTEM_WINDOWS

#endif // _XANADU_CORE_STREAM_H_

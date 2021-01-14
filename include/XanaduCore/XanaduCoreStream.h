//
// Created by Administrator on 2021/1/14.
//

#ifndef			_XANADU_CORE_STREAM_H_
#define			_XANADU_CORE_STREAM_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>

//Xanadu Class Stream
class XANADU_CORE_EXPORT XStream
{
public:
	XStream() XANADU_NOTHROW;

	virtual ~XStream() XANADU_NOTHROW;

public:
	//输出日志
	XANADU_DEPRECATED static void Output(const char* _Format, ...) XANADU_NOTHROW;

	//输出日志
	static void Output(const wchar_t* _Format, ...) XANADU_NOTHROW;

	//输出日志
	static void Output(const XString& _Format) XANADU_NOTHROW;

public:
	//输出日志:INFO
	XANADU_DEPRECATED static void Info(const char* _Format, ...) XANADU_NOTHROW;

	//输出日志:INFO
	static void Info(const wchar_t* _Format, ...) XANADU_NOTHROW;

	//输出日志:INFO
	static void Info(const XString& _Format) XANADU_NOTHROW;;

public:
	//输出日志:WARNING
	XANADU_DEPRECATED static void Warning(const char* _Format, ...) XANADU_NOTHROW;

	//输出日志:WARNING
	static void Warning(const wchar_t* _Format, ...) XANADU_NOTHROW;

	//输出日志:WARNING
	static void Warning(const XString& _Format) XANADU_NOTHROW;

public:
	//输出日志:ERROR
	XANADU_DEPRECATED static void Error(const char* _Format, ...) XANADU_NOTHROW;

	//输出日志:ERROR
	static void Error(const wchar_t* _Format, ...) XANADU_NOTHROW;

	//输出日志:ERROR
	static void Error(const XString& _Format) XANADU_NOTHROW;
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
#endif//XANADU_SYSTEM_WINDOWS

#endif /// _XANADU_CORE_STREAM_H_

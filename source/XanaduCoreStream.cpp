﻿//
// Created by Administrator on 2021/1/14.
//

#include <XanaduCore/XanaduCoreStream.h>
#include <XanaduCore/XanaduCoreDateTime.h>

#define			XANADU_LOG_MAX_LENGTH			10240

#ifdef XANADU_SYSTEM_WINDOWS
#ifdef _DEBUG
#define			XANADU_OUTPUT_ENABLED
#endif//_DEBUG
#else
#define			XANADU_OUTPUT_ENABLED
#endif//XANADU_SYSTEM_WINDOWS

XStream::XStream() XANADU_NOTHROW
{
}

XStream::~XStream() XANADU_NOTHROW
{
}




//输出日志
XANADU_DEPRECATED void XStream::Output(const char* _Format, ...) XANADU_NOTHROW
{
#ifdef XANADU_OUTPUT_ENABLED
	char		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(char) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
		va_start(vArgs, _Format);
#ifdef XANADU_SYSTEM_WINDOWS
	vsprintf_s(vBuffer, _Format, vArgs);
#else
	vsnprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
#endif//XANADU_SYSTEM_WINDOWS
		va_end(vArgs);

#ifdef XANADU_SYSTEM_WINDOWS
	XStream::Output(XString::FromAString(vBuffer));
#else
	XStream::Output(XString::FromUString(vBuffer));
#endif//XANADU_SYSTEM_WINDOWS
#else
	XANADU_UNPARAMETER(_Format);
#endif//XANADU_OUTPUT_ENABLED
}


//输出日志
void XStream::Output(const wchar_t* _Format, ...) XANADU_NOTHROW
{
#ifdef XANADU_OUTPUT_ENABLED
	wchar_t		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
		va_start(vArgs, _Format);
#ifdef XANADU_SYSTEM_WINDOWS
	wvsprintfW(vBuffer, _Format, vArgs);
#else
	vswprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
#endif//XANADU_SYSTEM_WINDOWS
		va_end(vArgs);

	auto		vOutputString = XString(L"[") + XDateTime::CurrentToString() + XString(L"]") + XString(L" ") + vBuffer + XString(L"\n");
	wprintf(vOutputString.data());
#ifdef XANADU_SYSTEM_WINDOWS
	OutputDebugStringW(vOutputString.data());
#endif//XANADU_SYSTEM_WINDOWS

#else
	XANADU_UNPARAMETER(_Format);
#endif//XANADU_OUTPUT_ENABLED
}

//输出日志
void XStream::Output(const XString& _Format) XANADU_NOTHROW
{
	XStream::Output(_Format.data());
}





//输出日志:INFO
XANADU_DEPRECATED void XStream::Info(const char* _Format, ...) XANADU_NOTHROW
{
#ifdef XANADU_OUTPUT_ENABLED
	char		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(char) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
		va_start(vArgs, _Format);
#ifdef XANADU_SYSTEM_WINDOWS
	vsprintf_s(vBuffer, _Format, vArgs);
#else
	vsnprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
#endif//XANADU_SYSTEM_WINDOWS
		va_end(vArgs);

#ifdef XANADU_SYSTEM_WINDOWS
	XStream::Info(XString::FromAString(vBuffer));
#else
	XStream::Info(XString::FromUString(vBuffer));
#endif//XANADU_SYSTEM_WINDOWS
#else
	XANADU_UNPARAMETER(_Format);
#endif//XANADU_OUTPUT_ENABLED
}

//输出日志:INFO
void XStream::Info(const wchar_t* _Format, ...) XANADU_NOTHROW
{
#ifdef XANADU_OUTPUT_ENABLED
	wchar_t		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
		va_start(vArgs, _Format);
#ifdef XANADU_SYSTEM_WINDOWS
	wvsprintfW(vBuffer, _Format, vArgs);
#else
	vswprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
#endif//XANADU_SYSTEM_WINDOWS
		va_end(vArgs);

	XStream::Output(XString(L"[INFO]") + XString(L" ") + vBuffer);
#else
	XANADU_UNPARAMETER(_Format);
#endif//XANADU_OUTPUT_ENABLED
}

//输出日志:INFO
void XStream::Info(const XString& _Format) XANADU_NOTHROW
{
	XStream::Info(_Format.data());
}





//输出日志:WARNING
XANADU_DEPRECATED void XStream::Warning(const char* _Format, ...) XANADU_NOTHROW
{
#ifdef XANADU_OUTPUT_ENABLED
	char		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(char) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
		va_start(vArgs, _Format);
#ifdef XANADU_SYSTEM_WINDOWS
	vsprintf_s(vBuffer, _Format, vArgs);
#else
	vsnprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
#endif//XANADU_SYSTEM_WINDOWS
		va_end(vArgs);

#ifdef XANADU_SYSTEM_WINDOWS
	XStream::Warning(XString::FromAString(vBuffer));
#else
	XStream::Warning(XString::FromUString(vBuffer));
#endif//XANADU_SYSTEM_WINDOWS
#else
	XANADU_UNPARAMETER(_Format);
#endif//XANADU_OUTPUT_ENABLED
}

//输出日志:WARNING
void XStream::Warning(const wchar_t* _Format, ...) XANADU_NOTHROW
{
#ifdef XANADU_OUTPUT_ENABLED
	wchar_t		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
		va_start(vArgs, _Format);
#ifdef XANADU_SYSTEM_WINDOWS
	wvsprintfW(vBuffer, _Format, vArgs);
#else
	vswprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
#endif//XANADU_SYSTEM_WINDOWS
		va_end(vArgs);

	XStream::Output(XString(L"[WARNING]") + XString(L" ") + vBuffer);
#else
	XANADU_UNPARAMETER(_Format);
#endif//XANADU_OUTPUT_ENABLED
}

//输出日志:WARNING
void XStream::Warning(const XString& _Format) XANADU_NOTHROW
{
	XStream::Warning(_Format.data());
}





//输出日志:ERROR
XANADU_DEPRECATED void XStream::Error(const char* _Format, ...) XANADU_NOTHROW
{
#ifdef XANADU_OUTPUT_ENABLED
	char		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(char) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
		va_start(vArgs, _Format);
#ifdef XANADU_SYSTEM_WINDOWS
	vsprintf_s(vBuffer, _Format, vArgs);
#else
	vsnprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
#endif//XANADU_SYSTEM_WINDOWS
		va_end(vArgs);

#ifdef XANADU_SYSTEM_WINDOWS
	XStream::Error(XString::FromAString(vBuffer));
#else
	XStream::Error(XString::FromUString(vBuffer));
#endif//XANADU_SYSTEM_WINDOWS
#else
	XANADU_UNPARAMETER(_Format);
#endif//XANADU_OUTPUT_ENABLED
}

//输出日志:ERROR
void XStream::Error(const wchar_t* _Format, ...) XANADU_NOTHROW
{
	wchar_t		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
		va_start(vArgs, _Format);
#ifdef XANADU_SYSTEM_WINDOWS
	wvsprintfW(vBuffer, _Format, vArgs);
#else
	vswprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
#endif//XANADU_SYSTEM_WINDOWS
		va_end(vArgs);

	XStream::Output(XString(L"[ERROR]") + XString(L" ") + vBuffer);
}

//输出日志:ERROR
void XStream::Error(const XString& _Format) XANADU_NOTHROW
{
	XStream::Error(_Format.data());
}
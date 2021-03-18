#include <XanaduCore/XStream.h>
#include <XanaduCore/XDateTime.h>

#define			XANADU_LOG_MAX_LENGTH			10240

#ifdef XANADU_SYSTEM_WINDOWS
#ifdef _DEBUG
#define			XANADU_OUTPUT_ENABLED
#endif // _DEBUG
#else
#define			XANADU_OUTPUT_ENABLED
#endif // XANADU_SYSTEM_WINDOWS

static ENUM_XANADU_DEBUG_LEVEL			_StaticDebugLevel = EXANADU_DEBUG_LEVEL_FULL;

XStream::XStream() noexcept
{
}

XStream::~XStream() noexcept
{
}




// 启用日志级别
void XStream::setDebugLevel(ENUM_XANADU_DEBUG_LEVEL _Level) noexcept
{
	_StaticDebugLevel = _Level;
}




// 输出日志
XANADU_DEPRECATED void XStream::Output(const char* _Format, ...) noexcept
{
#ifdef XANADU_OUTPUT_ENABLED
	char		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(char) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
	va_start(vArgs, _Format);
	vsnprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
	va_end(vArgs);

	XStream::Output(XString::fromNString(vBuffer));
#else
	XANADU_UNPARAMETER(_Format);
#endif // XANADU_OUTPUT_ENABLED
}


// 输出日志
void XStream::Output(const wchar_t* _Format, ...) noexcept
{
#ifdef XANADU_OUTPUT_ENABLED
	wchar_t		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
	va_start(vArgs, _Format);
	vswprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
	va_end(vArgs);

	auto		vOutputString = XString(L"[") + XDateTime::currentMillisecondToString() + XString(L"]") + XString(L" ") + vBuffer + XString(L"\n");
	wprintf(vOutputString.data());
#ifdef XANADU_SYSTEM_WINDOWS
	OutputDebugStringW(vOutputString.data());
#endif // XANADU_SYSTEM_WINDOWS

#else
	XANADU_UNPARAMETER(_Format);
#endif // XANADU_OUTPUT_ENABLED
}

// 输出日志
void XStream::Output(const XString& _Format) noexcept
{
	XStream::Output(_Format.data());
}





// 输出日志:INFO
XANADU_DEPRECATED void XStream::Info(const char* _Format, ...) noexcept
{
#ifdef XANADU_OUTPUT_ENABLED
	char		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(char) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
	va_start(vArgs, _Format);
	vsnprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
	va_end(vArgs);

	XStream::Info(XString::fromNString(vBuffer));
#else
	XANADU_UNPARAMETER(_Format);
#endif // XANADU_OUTPUT_ENABLED
}

// 输出日志:INFO
void XStream::Info(const wchar_t* _Format, ...) noexcept
{
#ifdef XANADU_OUTPUT_ENABLED
	wchar_t		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
	va_start(vArgs, _Format);
	vswprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
	va_end(vArgs);

	XStream::Output(XString(L"[INFO]") + XString(L" ") + vBuffer);
#else
	XANADU_UNPARAMETER(_Format);
#endif // XANADU_OUTPUT_ENABLED
}

// 输出日志:INFO
void XStream::Info(const XString& _Format) noexcept
{
	XStream::Info(_Format.data());
}





// 输出日志:WARNING
XANADU_DEPRECATED void XStream::Warning(const char* _Format, ...) noexcept
{
#ifdef XANADU_OUTPUT_ENABLED
	char		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(char) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
	va_start(vArgs, _Format);
	vsnprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
	va_end(vArgs);

	XStream::Warning(XString::fromNString(vBuffer));
#else
	XANADU_UNPARAMETER(_Format);
#endif // XANADU_OUTPUT_ENABLED
}

// 输出日志:WARNING
void XStream::Warning(const wchar_t* _Format, ...) noexcept
{
#ifdef XANADU_OUTPUT_ENABLED
	wchar_t		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
	va_start(vArgs, _Format);
	vswprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
	va_end(vArgs);

	XStream::Output(XString(L"[WARNING]") + XString(L" ") + vBuffer);
#else
	XANADU_UNPARAMETER(_Format);
#endif // XANADU_OUTPUT_ENABLED
}

// 输出日志:WARNING
void XStream::Warning(const XString& _Format) noexcept
{
	XStream::Warning(_Format.data());
}





// 输出日志:ERROR
XANADU_DEPRECATED void XStream::Error(const char* _Format, ...) noexcept
{
#ifdef XANADU_OUTPUT_ENABLED
	char		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(char) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
	va_start(vArgs, _Format);
	vsnprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
	va_end(vArgs);

	XStream::Error(XString::fromNString(vBuffer));
#else
	XANADU_UNPARAMETER(_Format);
#endif // XANADU_OUTPUT_ENABLED
}

// 输出日志:ERROR
void XStream::Error(const wchar_t* _Format, ...) noexcept
{
	wchar_t		vBuffer[XANADU_LOG_MAX_LENGTH] = { 0 };
	Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * XANADU_LOG_MAX_LENGTH);
	va_list		vArgs;
	va_start(vArgs, _Format);
	vswprintf(vBuffer, XANADU_LOG_MAX_LENGTH, _Format, vArgs);
	va_end(vArgs);

	XStream::Output(XString(L"[ERROR]") + XString(L" ") + vBuffer);
}

// 输出日志:ERROR
void XStream::Error(const XString& _Format) noexcept
{
	XStream::Error(_Format.data());
}

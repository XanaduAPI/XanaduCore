#ifndef			_XANADU_CORE_NATIVE_H_
#define			_XANADU_CORE_NATIVE_H_

#include <XanaduCore/XanaduCoreHeader.h>

// Native platform type definition
#ifndef XANADU_SYSTEM_WINDOWS
typedef signed char			INT8;
typedef signed char*			PINT8;
typedef signed short			INT16;
typedef signed short*			PINT16;
typedef signed int			INT32;
typedef signed int*			PINT32;
typedef signed long long		INT64;
typedef signed long long*		PINT64;
typedef unsigned char			UINT8;
typedef unsigned char*			PUINT8;
typedef unsigned short			UINT16;
typedef unsigned short*			PUINT16;
typedef unsigned int			UINT32;
typedef unsigned int*			PUINT32;
typedef unsigned long long		UINT64;
typedef unsigned long long*		PUINT64;

typedef char				CHAR;
typedef wchar_t				WCHAR;
typedef short				SHORT;
typedef int				INT;
typedef long				LONG;
typedef unsigned char			BYTE;
typedef unsigned int			UINT;
typedef	unsigned long			ULONG;
typedef	unsigned long long		ULONGLONG;

typedef unsigned short			WORD;
typedef unsigned long			DWORD;

typedef float				FLOAT;

typedef int				INT_PTR;
typedef int*				PINT_PTR;
typedef unsigned int			UINT_PTR;
typedef unsigned int*			PUINT_PTR;
typedef long				LONG_PTR;
typedef long*				PLONG_PTR;
typedef unsigned long			ULONG_PTR;
typedef unsigned long*			PULONG_PTR;
typedef unsigned int*			PUINT;
typedef	HANDLE				HWND;
typedef long				WPARAM;
typedef long				LPARAM;
typedef long				LRESULT;
typedef	long				HRESULT;
typedef	HANDLE				HKEY;

// 坐标定义
typedef struct tagPOINT
{
	long	x;
	long	y;
}POINT, *PPOINT, *NPPOINT, *LPPOINT;

// 消息结构
typedef struct tagMSG
{
	HWND				hwnd;
	unsigned int			message;
	WPARAM				wParam;
	LPARAM				lParam;
	unsigned long			time;
	POINT				pt;
#ifdef _MAC
	unsigned long			lPrivate;
#endif
}MSG, *LPMSG;

// 文件时间
typedef struct _FILETIME
{
	DWORD				dwLowDateTime;
	DWORD				dwHighDateTime;
}FILETIME, *PFILETIME, *LPFILETIME;
#endif // XANADU_SYSTEM_WINDOWS
#ifdef XANADU_SYSTEM_LINUX
typedef unsigned int 			BOOL;
#endif // XANADU_SYSTEM_LINUX

// Native platform macro definition
#ifndef XANADU_SYSTEM_WINDOWS
#define			WM_USER							0x0400
#define			PM_NOREMOVE						0x0000
#define			PM_REMOVE						0x0001
#define			PM_NOYIELD						0x0002
#define			INVALID_HANDLE_VALUE					((HANDLE)(LONG_PTR)-1)
#define			STATUS_INVALID_HANDLE					((DWORD )0xC0000008L)
#define			ERROR_SUCCESS						0L
#define			S_OK							((HRESULT)0L)
#define			S_FALSE							((HRESULT)1L)
#endif // XANADU_SYSTEM_WINDOWS
#ifdef XANADU_SYSTEM_LINUX
#define			TRUE							1
#define			FALSE							0
#endif // XANADU_SYSTEM_LINUX

// Native platform-dependent function implementation
#ifndef XANADU_SYSTEM_WINDOWS
// 从调用线程的消息队列里取得一个消息并将其放于指定的结构。
// 此函数可取得与指定窗口联系的消息和由PostThreadMessage寄送的线程消息。
// 此函数接收一定范围的消息值。GetMessage不接收属于其他线程或应用程序的消息。
// 获取消息成功后，线程将从消息队列中删除该消息。
// 函数会一直等待直到有消息到来才有返回值。
XANADU_CORE_EXPORT BOOL XANADUAPI GetMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);

// 检查线程消息队列，并将该消息（如果存在）放于指定的结构
XANADU_CORE_EXPORT BOOL XANADUAPI PeekMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);

// 将一个队列消息放入（寄送）到指定线程的消息队列里，不等待线程处理消息就返回
XANADU_CORE_EXPORT BOOL XANADUAPI PostThreadMessageW(DWORD _ThreadID, UINT Msg, WPARAM wParam, LPARAM lParam);

#endif // XANADU_SYSTEM_WINDOWS

///创建注册表项
XANADU_CORE_EXPORT bool PlatformRegeditCreate(HKEY _Key, const wchar_t* _SubKey);

#endif // _XANADU_CORE_NATIVE_H_

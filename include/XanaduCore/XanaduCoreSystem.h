﻿//
// Created by Administrator on 2021/1/20.
//

#ifndef			_XANADU_CORE_SYSTEM_H_
#define			_XANADU_CORE_SYSTEM_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreString.h>

#define			XANADU_OS_VERSION_UNKNOWN				0x00000000

#define			XANADU_OS_VERSION_WINDOWS_VISTA				0x00060000
#define			XANADU_OS_VERSION_WINDOWS_2008				0x00060001
#define			XANADU_OS_VERSION_WINDOWS_7				0x00060100
#define			XANADU_OS_VERSION_WINDOWS_2008_R2			0x00060101
#define			XANADU_OS_VERSION_WINDOWS_8				0x00060200
#define			XANADU_OS_VERSION_WINDOWS_2012				0x00060201
#define			XANADU_OS_VERSION_WINDOWS_8_1				0x00060300
#define			XANADU_OS_VERSION_WINDOWS_2012_R2			0x00060301
#define			XANADU_OS_VERSION_WINDOWS_10				0x00100000
#define			XANADU_OS_VERSION_WINDOWS_2016				0x00100001

#define			XANADU_OS_VERSION_LINUX_1404				0x00140400
#define			XANADU_OS_VERSION_LINUX_1410				0x00141000
#define			XANADU_OS_VERSION_LINUX_1504				0x00150400
#define			XANADU_OS_VERSION_LINUX_1510				0x00151000
#define			XANADU_OS_VERSION_LINUX_1604				0x00160400
#define			XANADU_OS_VERSION_LINUX_1610				0x00161000
#define			XANADU_OS_VERSION_LINUX_1704				0x00170400
#define			XANADU_OS_VERSION_LINUX_1710				0x00171000
#define			XANADU_OS_VERSION_LINUX_1804				0x00180400
#define			XANADU_OS_VERSION_LINUX_1810				0x00181000
#define			XANADU_OS_VERSION_LINUX_1904				0x00190400
#define			XANADU_OS_VERSION_LINUX_1910				0x00191000
#define			XANADU_OS_VERSION_LINUX_2004				0x00200400
#define			XANADU_OS_VERSION_LINUX_2010				0x00201000
#define			XANADU_OS_VERSION_LINUX_2104				0x00210400
#define			XANADU_OS_VERSION_LINUX_2110				0x00211000

#define			XANADU_OS_VERSION_MACOS_1012				0x00101200
#define			XANADU_OS_VERSION_MACOS_1013				0x00101300
#define			XANADU_OS_VERSION_MACOS_1014				0x00101400
#define			XANADU_OS_VERSION_MACOS_1015				0x00101500
#define			XANADU_OS_VERSION_MACOS_1100				0x00110000
#define			XANADU_OS_VERSION_MACOS_1101				0x00110100

//Xanadu Class System
class XANADU_CORE_EXPORT XSystem
{
public:
	XSystem() XANADU_NOTHROW;

	virtual ~XSystem() XANADU_NOTHROW;

public:
	/// The current version of the operating system
	static int64S SystemVersion() XANADU_NOTHROW;

	/// The name of the user who is now logged in
	static XString CurrentUser() XANADU_NOTHROW;

	/// Computer name
	static XString HostName() XANADU_NOTHROW;

	/// Gets the directory for the current user
	static XString UserHome() XANADU_NOTHROW;

	/// Whether the operating system is 32-bit
	static bool IsX86() XANADU_NOTHROW;

	/// Whether the operating system is 64-bit
	static bool IsX64() XANADU_NOTHROW;

	/// Whether the operating system is a server version
	static bool IsServer() XANADU_NOTHROW;

	/// Whether the operating system is a desktop version
	static bool IsDesktop() XANADU_NOTHROW;

	/// Native System String
	static XString NativeString() XANADU_NOTHROW;

	/// Native Build Version
	static XString BuildVersion() XANADU_NOTHROW;

	/// The CPUID of the current computer
	static XString CPUID() XANADU_NOTHROW;

	/// The hard disk ID of the current computer
	static XString DiskID() XANADU_NOTHROW;

	/// A string unique to the current computer
	static XString OnlyString() XANADU_NOTHROW;
};

#endif /// _XANADU_CORE_SYSTEM_H_

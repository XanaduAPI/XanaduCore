#include <XanaduRuntime/FileSystem.h>
#include <XanaduRuntime/String.h>
#include <XanaduRuntime/Memory.h>

XANADU_RUNTIME_EXPORT FILE* XANADUAPI Xanadu::fdopen(int _Fildes, const char* _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Mode, nullptr);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_fdopen(_Fildes, _Mode);
#else
	return ::fdopen(_Fildes, _Mode);
#endif
}

XANADU_RUNTIME_EXPORT FILE* XANADUAPI Xanadu::wfdopen(int _Fildes, const wchar_t* _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Mode, nullptr);

	auto 		vNMode = Xanadu::strwton(_Mode);
	auto 		vHandle = Xanadu::fdopen(_Fildes, vNMode);
	Xanadu::strfree(vNMode);
	return vHandle;
}

XANADU_RUNTIME_EXPORT FILE* XANADUAPI Xanadu::freopen(const char* _Filename, const char* _Mode, FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Filename, nullptr);
	XANADU_CHECK_RETURN(_Mode, nullptr);
	XANADU_CHECK_RETURN(_Stream, nullptr);

#if defined(XANADU_SYSTEM_WINDOWS)
	auto		vHandle = static_cast<FILE*>(nullptr);
	freopen_s(&vHandle, _Filename, _Mode, _Stream);
	return vHandle;
#else
	return ::freopen(_Filename, _Mode, _Stream);
#endif
}

XANADU_RUNTIME_EXPORT FILE* XANADUAPI Xanadu::wfreopen(const wchar_t* _Filename, const wchar_t* _Mode, FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Filename, nullptr);
	XANADU_CHECK_RETURN(_Mode, nullptr);
	XANADU_CHECK_RETURN(_Stream, nullptr);

	auto 		vNFilename = Xanadu::strwton(_Filename);
	auto 		vNMode = Xanadu::strwton(_Mode);
	auto		vHandle = Xanadu::freopen(vNFilename, vNMode, _Stream);
	Xanadu::strfree(vNFilename);
	Xanadu::strfree(vNMode);
	return vHandle;
}

XANADU_RUNTIME_EXPORT FILE* XANADUAPI Xanadu::fopen(const char* _File, const char* _Mode) noexcept
{
	XANADU_CHECK_RETURN(_File, nullptr);
	XANADU_CHECK_RETURN(_Mode, nullptr);

#if defined(XANADU_SYSTEM_WINDOWS)
	auto		vHandle = static_cast<FILE*>(nullptr);
	fopen_s(&vHandle, _File, _Mode);
	return vHandle;
#else
	return ::fopen(_File, _Mode);
#endif
}

XANADU_RUNTIME_EXPORT FILE* XANADUAPI Xanadu::wfopen(const wchar_t* _File, const wchar_t* _Mode) noexcept
{
	XANADU_CHECK_RETURN(_File, nullptr);
	XANADU_CHECK_RETURN(_Mode, nullptr);

#if defined(XANADU_SYSTEM_WINDOWS)
	auto		vHandle = static_cast<FILE*>(nullptr);
	::_wfopen_s(&vHandle, _File, _Mode);
	return vHandle;
#else
	auto 		vNFile = Xanadu::strwton(_File);
	auto 		vNMode = Xanadu::strwton(_Mode);
	auto		vHandle = Xanadu::fopen(vNFile, vNMode);
	Xanadu::strfree(vNFile);
	Xanadu::strfree(vNMode);
	return vHandle;
#endif
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::fseek(FILE* _Stream, long long _Offset, int _Origin) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_fseeki64(_Stream, _Offset, _Origin);
#else
	return ::fseek(_Stream, _Offset, _Origin);
#endif
}

XANADU_RUNTIME_EXPORT long long XANADUAPI Xanadu::ftell(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_ftelli64(_Stream);
#else
	return ::ftell(_Stream);
#endif
}

XANADU_RUNTIME_EXPORT size_t XANADUAPI Xanadu::fread(void* _Buffer, size_t _Size, size_t _Count, FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, 0);
	XANADU_CHECK_RETURN(_Stream, 0);

	return ::fread(_Buffer, _Size, _Count, _Stream);
}

XANADU_RUNTIME_EXPORT bool XANADUAPI Xanadu::fread(FILE* _Stream, void* _Buffer, size_t _Size) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, false);
	XANADU_CHECK_RETURN(_Stream, false);

	auto		vAlready = static_cast<size_t>(0U);
	while(vAlready < _Size)
	{
		auto	vSync = Xanadu::fread(((char*)(_Buffer)) + vAlready, 1, _Size - vAlready, _Stream);
		if(0U < vSync)
		{
			vAlready += vSync;
		}
		else
		{
			break;
		}
	};
	return vAlready == _Size;
}

XANADU_RUNTIME_EXPORT size_t XANADUAPI Xanadu::fwrite(const void* _Buffer, size_t _Size, size_t _Count, FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, 0);
	XANADU_CHECK_RETURN(_Stream, 0);

	return ::fwrite(_Buffer, _Size, _Count, _Stream);
}

XANADU_RUNTIME_EXPORT bool XANADUAPI Xanadu::fwrite(FILE* _Stream, const void* _Buffer, size_t _Size) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, false);
	XANADU_CHECK_RETURN(_Stream, false);

	auto		vAlready = static_cast<size_t>(0U);
	while(vAlready < _Size)
	{
		auto	vSync = Xanadu::fwrite(((const char*)(_Buffer)) + vAlready, 1, _Size - vAlready, _Stream);
		if(0U < vSync)
		{
			vAlready += vSync;
		}
		else
		{
			break;
		}
	};
	return vAlready == _Size;
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::fflush(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

	return ::fflush(_Stream);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::fsync(int _Fildes) noexcept
{
	XANADU_CHECK_RETURN(_Fildes, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return 0;
#else
	return ::fsync(_Fildes);
#endif
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::fgetc(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

	return ::fgetc(_Stream);
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::fgets(char* _Buffer, int _MaxCount, FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, nullptr);
	XANADU_CHECK_RETURN(_Stream, nullptr);

	return ::fgets(_Buffer, _MaxCount, _Stream);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::fileno(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_fileno(_Stream);
#else
	return ::fileno(_Stream);
#endif
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::feof(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

	return ::feof(_Stream);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::ferror(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

	return ::ferror(_Stream);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::fclose(FILE* _Stream) noexcept
{
	XANADU_CHECK_RETURN(_Stream, -1);

	return ::fclose(_Stream);
}

// Deletes a directory.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::rmdir(const char* _Path) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_rmdir(_Path);
#else
	return ::rmdir(_Path);
#endif
}

// Deletes a directory.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wrmdir(const wchar_t* _Path) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_wrmdir(_Path);
#else
	auto		vNPath = Xanadu::strwton(_Path);
	auto		vSync = Xanadu::rmdir(vNPath);
	Xanadu::strfree(vNPath);
	return vSync;
#endif
}

// Creates a new directory.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::mkdir(const char* _Path, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	XANADU_UNPARAMETER(_Mode);
	return ::_mkdir(_Path);
#else
	auto		vSync = ::mkdir(_Path, _Mode);
	if(0 == vSync)
	{
		Xanadu::chmod(_Path, _Mode);
	}
	return vSync;
#endif
}

// Creates a new directory.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wmkdir(const wchar_t* _Path, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	XANADU_UNPARAMETER(_Mode);
	return ::_wmkdir(_Path);
#else
	auto		vNPath = Xanadu::strwton(_Path);
	auto		vSync = Xanadu::mkdir(vNPath, _Mode);
	if(0 == vSync)
	{
		Xanadu::chmod(vNPath, _Mode);
	}
	Xanadu::strfree(vNPath);
	return vSync;
#endif
}

// Changes the file-permission settings.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::chmod(const char* _Path, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_chmod(_Path, _Mode);
#else
	return ::chmod(_Path, _Mode);
#endif
}

// Changes the file-permission settings.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wchmod(const wchar_t* _Path, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_wchmod(_Path, _Mode);
#else
	auto		vNPath = Xanadu::strwton(_Path);
	auto		vSync = Xanadu::chmod(vNPath, _Mode);
	Xanadu::strfree(vNPath);
	return vSync;
#endif
}

// Delete a file.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::remove(const char* _Path) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

	return ::remove(_Path);
}

// Delete a file.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wremove(const wchar_t* _Path) noexcept
{
	XANADU_CHECK_RETURN(_Path, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_wremove(_Path);
#else
	auto		vNPath = Xanadu::strwton(_Path);
	auto		vSync = Xanadu::remove(vNPath);
	Xanadu::strfree(vNPath);
	return vSync;
#endif
}

// Rename a file or directory.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::rename(const char* _Old, const char* _New) noexcept
{
	XANADU_CHECK_RETURN(_Old, -1);
	XANADU_CHECK_RETURN(_New, -1);

	return ::rename(_Old, _New);
}

// Rename a file or directory.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wrename(const wchar_t* _Old, const wchar_t* _New) noexcept
{
	XANADU_CHECK_RETURN(_Old, -1);
	XANADU_CHECK_RETURN(_New, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_wrename(_Old, _New);
#else
	auto		vNOld = Xanadu::strwton(_Old);
	auto		vNNew = Xanadu::strwton(_New);
	auto		vSync = Xanadu::rename(vNOld, vNNew);
	Xanadu::strfree(vNOld);
	Xanadu::strfree(vNNew);
	return vSync;
#endif
}







XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::fstat64(int _FileHandle, XStat64* _Stat) noexcept
{
	XANADU_CHECK_RETURN(_FileHandle, -1);
	XANADU_CHECK_RETURN(_Stat, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_fstat64(_FileHandle, _Stat);
#else
	return ::fstat64(_FileHandle, _Stat);
#endif
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::stat64(const char* _FileName, XStat64* _Stat) noexcept
{
	XANADU_CHECK_RETURN(_FileName, -1);
	XANADU_CHECK_RETURN(_Stat, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_stat64(_FileName, _Stat);
#else
	return ::stat64(_FileName, _Stat);
#endif
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wstat64(const wchar_t* _FileName, XStat64* _Stat) noexcept
{
	XANADU_CHECK_RETURN(_FileName, -1);
	XANADU_CHECK_RETURN(_Stat, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_wstat64(_FileName, _Stat);
#else
	auto		vSync = -1;
	auto		vNFileName = Xanadu::strwton(_FileName);
	if(vNFileName)
	{
		vSync = Xanadu::stat64(vNFileName, _Stat);
		Xanadu::strfree(vNFileName);
	}
	return vSync;
#endif
}








// Get file size
XANADU_RUNTIME_EXPORT unsigned long long XANADUAPI Xanadu::fsize(const char* _FilePath) noexcept
{
	XANADU_CHECK_RETURN(_FilePath, -1);

	XStat64		vFileStatus{};
	if(0 == Xanadu::stat64(_FilePath, &vFileStatus))
	{
		return vFileStatus.st_size;
	}
	return 0;
}

// Get file size
XANADU_RUNTIME_EXPORT unsigned long long XANADUAPI Xanadu::wfsize(const wchar_t* _FilePath) noexcept
{
	XANADU_CHECK_RETURN(_FilePath, -1);

	XStat64		vFileStatus{};
	if(0 == Xanadu::wstat64(_FilePath, &vFileStatus))
	{
		return vFileStatus.st_size;
	}
	return 0;
}

// Copy file data.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::fcopy(const char* _ExistingFileName, const char* _NewFileName) noexcept
{
	XANADU_CHECK_RETURN(_ExistingFileName, -1);
	XANADU_CHECK_RETURN(_NewFileName, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	// Prioritize system API calls
	if(::CopyFileA(_ExistingFileName, _NewFileName, FALSE))
	{
		return 0;
	}
#endif

	auto		vNExistingFileName = Xanadu::strntow(_ExistingFileName);
	auto		vNNewFileName = Xanadu::strntow(_NewFileName);
	auto		vSync = Xanadu::wfcopy(vNExistingFileName, vNNewFileName);
	Xanadu::wcsfree(vNExistingFileName);
	Xanadu::wcsfree(vNNewFileName);
	return vSync;
}

// Copy file data.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wfcopy(const wchar_t* _ExistingFileName, const wchar_t* _NewFileName) noexcept
{
	XANADU_CHECK_RETURN(_ExistingFileName, -1);
	XANADU_CHECK_RETURN(_NewFileName, -1);

#if defined(XANADU_SYSTEM_WINDOWS)
	// Prioritize system API calls
	if(::CopyFileW(_ExistingFileName, _NewFileName, FALSE))
	{
		return 0;
	}
#endif

	// 按字节拷贝文件
	auto		vSync = -1;
	auto		vLength = static_cast<size_t>(XANADU_SIZE_MB);
	auto 		vBuffer = (char*)XANADU_MALLOC(vLength);
	auto		vFileSource = Xanadu::wfopen(_ExistingFileName, L"rb");
	auto		vFileTarget = Xanadu::wfopen(_NewFileName, L"wb");
	auto		vSourceSize = static_cast<size_t>(Xanadu::wfsize(_ExistingFileName));
	auto 		vCurrentRead = static_cast<size_t>(0U);
	if(vFileSource && vFileTarget && vBuffer)
	{
		if(0 == vSourceSize)
		{
			vSync = 0;
		}
		// 循环读取
		while(vSourceSize > vCurrentRead)
		{
			Xanadu::memset(vBuffer, 0, vLength);
			// 当前需要读多少数据
			auto		vReadSize = ((vSourceSize - vCurrentRead) > vLength) ? vLength : (vSourceSize - vCurrentRead);
			if(!Xanadu::fread(vFileSource, vBuffer, vReadSize))
			{
				break;
			}
			vCurrentRead += vReadSize;
			// 写入目标文件
			if(!Xanadu::fwrite(vFileTarget, vBuffer, vReadSize))
			{
				break;
			}
			if(vCurrentRead == vSourceSize)
			{
				vSync = 0;
				break;
			}
		};
	}
	// 关闭文件
	Xanadu::fclose(vFileSource);
	Xanadu::fclose(vFileTarget);
	vFileTarget = nullptr;
	vFileTarget = nullptr;
	XANADU_FREE(vBuffer);

	return vSync;
}









// Format path. Replace \\ with /, removing the last bit of /.
XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::fmtpath(const char* _Path) noexcept
{
	XANADU_CHECK_RETURN(_Path, nullptr);

	auto		vCopyPath = Xanadu::strdup(_Path);
	auto		vPathLength = Xanadu::strlen(vCopyPath);
	for(auto vIndex = 0U; vIndex < vPathLength; ++vIndex)
	{
		if(vCopyPath[vIndex] == '\\')
		{
			vCopyPath[vIndex] = '/';
		}
	}
	if (vPathLength > 0 && vCopyPath[vPathLength - 1] == '/')
	{
		vCopyPath[vPathLength - 1] = '\0';
	}
	return vCopyPath;
}

// Format path. Replace \\ with /, removing the last bit of /.
XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI Xanadu::wfmtpath(const wchar_t* _Path) noexcept
{
	XANADU_CHECK_RETURN(_Path, nullptr);

	auto		vCopyPath = Xanadu::wcsdup(_Path);
	auto		vPathLength = Xanadu::wcslen(vCopyPath);
	for(auto vIndex = 0U; vIndex < vPathLength; ++vIndex)
	{
		if(vCopyPath[vIndex] == L'\\')
		{
			vCopyPath[vIndex] = L'/';
		}
	}
	if (vPathLength > 0 && vCopyPath[vPathLength - 1] == L'/')
	{
		vCopyPath[vPathLength - 1] = L'\0';
	}
	return vCopyPath;
}

// Create a multi-level directory.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::mkpath(const char* _Directory, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Directory, -1);

	char		vTemp[XANADU_PATH] = { 0 };
	auto		vDirectory = Xanadu::fmtpath(_Directory);
	auto		vLength = Xanadu::strlen(vDirectory);
	auto		vSync = -1;

	// The path cannot be too long or too short
	if(XANADU_PATH <= vLength || vLength <= 0)
	{
		return -1;
	}

	// Now the loop is created
	for (auto vIndex = 0U; vIndex < vLength; ++vIndex)
	{
		vTemp[vIndex] = _Directory[vIndex];
		if (vTemp[vIndex] == '\\' || vTemp[vIndex] == '/')
		{
			if (Xanadu::access(vTemp, F_OK) != 0)
			{
				vSync = Xanadu::mkdir(vTemp, _Mode);
				if (vSync != 0 && errno != EEXIST)
				{
					return vSync;
				}
			}
		}
	}
	vSync = Xanadu::mkdir(vTemp, _Mode);
	Xanadu::strfree(vDirectory);
	if (vSync != 0 && errno == EEXIST)
	{
		return 0;
	}
	return vSync;
}

// Create a multi-level directory.
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wmkpath(const wchar_t* _Directory, int _Mode) noexcept
{
	XANADU_CHECK_RETURN(_Directory, -1);

	wchar_t		vTemp[XANADU_PATH] = { 0 };
	auto		vDirectory = Xanadu::wfmtpath(_Directory);
	auto		vLength = Xanadu::wcslen(vDirectory);
	auto		vSync = -1;

	// The path cannot be too long or too short
	if(XANADU_PATH <= vLength || vLength <= 0)
	{
		return -1;
	}

	// Now the loop is created
	for (auto vIndex = 0U; vIndex < vLength; ++vIndex)
	{
		vTemp[vIndex] = _Directory[vIndex];
		if (vTemp[vIndex] == L'\\' || vTemp[vIndex] == L'/')
		{
			if (Xanadu::waccess(vTemp, F_OK) != 0)
			{
				vSync = Xanadu::wmkdir(vTemp, _Mode);
				if (vSync != 0 && errno != EEXIST)
				{
					return vSync;
				}
			}
		}
	}
	vSync = Xanadu::wmkdir(vTemp, _Mode);
	Xanadu::wcsfree(vDirectory);
	if (vSync != 0 && errno == EEXIST)
	{
		return 0;
	}
	return vSync;
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::access(const char* _Path, int _Mode) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_access(_Path, _Mode);
#else
	return ::access(_Path, _Mode);
#endif
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::waccess(const wchar_t* _Path, int _Mode) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return ::_waccess(_Path, _Mode);
#else
	auto		vNPath = Xanadu::strwton(_Path);
	auto		vSync = Xanadu::access(vNPath, _Mode);
	Xanadu::strfree(vNPath);
	return vSync;
#endif
}








// Directory traverse
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::traversedir(const char* _Directory, _XFunctionTraverseDirectoryA _Function, void* _UserData) noexcept
{
	XANADU_CHECK_RETURN(_Directory, -1);

	auto		vDirectory = Xanadu::fmtpath(_Directory);
	auto		vSync = -1;
#if defined(XANADU_SYSTEM_WINDOWS)
	auto 		vFindData = WIN32_FIND_DATAA();
	char		vFilePath[XANADU_PATH] = {0};
	Xanadu::strcpy(vFilePath, vDirectory);
	Xanadu::strcat(vFilePath, "/*");

	auto		vHandle = FindFirstFileA(vFilePath, &vFindData);
	if(vHandle == INVALID_HANDLE_VALUE)
	{
		return 1;
	}
	else
	{
		vSync = 0;
		do
		{
			auto		vFileInfo = XANADU_RUNTIME_FILE_INFO_A();
			Xanadu::memset(&vFileInfo, 0, sizeof(XANADU_RUNTIME_FILE_INFO_A));
			Xanadu::strcpy(vFileInfo.path, vDirectory);
			Xanadu::strcat(vFileInfo.path, "/");
			Xanadu::strcat(vFileInfo.path, vFindData.cFileName);
			Xanadu::strcpy(vFileInfo.name, vFindData.cFileName);
			vFileInfo.isDir = vFindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;

			if(_Function)
			{
				if(!_Function(&vFileInfo, _UserData))
				{
					break;
				}
			}
		}
		while(FindNextFileA(vHandle, &vFindData));
		::FindClose(vHandle);
	}
#else
	auto 		vHandle = ::opendir(vDirectory);
	auto		vDirEntry = static_cast<struct dirent*>(nullptr);

	if (vHandle)
	{
		vSync = 0;
		vDirEntry = ::readdir(vHandle);
		do
		{
			auto		vFileInfo = XANADU_RUNTIME_FILE_INFO_A();
			Xanadu::memset(&vFileInfo, 0, sizeof(XANADU_RUNTIME_FILE_INFO_A));
			Xanadu::strcpy(vFileInfo.path, vDirectory);
			Xanadu::strcat(vFileInfo.path, "/");
			Xanadu::strcat(vFileInfo.path, vDirEntry->d_name);
			Xanadu::strcpy(vFileInfo.name, vDirEntry->d_name);
			vFileInfo.isDir = vDirEntry->d_type & DT_DIR;

			if(_Function)
			{
				if(false == _Function(&vFileInfo, _UserData))
				{
					break;
				}
			}
			vDirEntry = ::readdir(vHandle);
		}while(vDirEntry);
		::closedir(vHandle);
	}

#endif
	Xanadu::strfree(vDirectory);
	return vSync;
}

// Directory traverse
XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::wtraversedir(const wchar_t* _Directory, _XFunctionTraverseDirectoryW _Function, void* _UserData) noexcept
{
	XANADU_CHECK_RETURN(_Directory, -1);

	auto		vDirectory = Xanadu::wfmtpath(_Directory);
	auto		vSync = -1;
#if defined(XANADU_SYSTEM_WINDOWS)
	auto 		vFindData = WIN32_FIND_DATAW();
	wchar_t		vFilePath[XANADU_PATH] = {0};
	Xanadu::wcscpy(vFilePath, vDirectory);
	Xanadu::wcscat(vFilePath, L"/*");

	auto		vHandle = FindFirstFileW(vFilePath, &vFindData);
	if(vHandle == INVALID_HANDLE_VALUE)
	{
		return 1;
	}
	else
	{
		vSync = 0;
		do
		{
			auto		vFileInfo = XANADU_RUNTIME_FILE_INFO_W();
			Xanadu::memset(&vFileInfo, 0, sizeof(XANADU_RUNTIME_FILE_INFO_A));
			Xanadu::wcscpy(vFileInfo.path, vDirectory);
			Xanadu::wcscat(vFileInfo.path, L"/");
			Xanadu::wcscat(vFileInfo.path, vFindData.cFileName);
			Xanadu::wcscpy(vFileInfo.name, vFindData.cFileName);
			vFileInfo.isDir = vFindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;

			if(_Function)
			{
				if(!_Function(&vFileInfo, _UserData))
				{
					break;
				}
			}
		}
		while(FindNextFileW(vHandle, &vFindData));
		::FindClose(vHandle);
	}
#else
	auto		vDirectoryA = Xanadu::strwton(vDirectory);
	auto 		vHandle = ::opendir(vDirectoryA);
	auto		vDirEntry = static_cast<struct dirent*>(nullptr);

	if (vHandle)
	{
		vSync = 0;
		vDirEntry = ::readdir(vHandle);
		do
		{
			auto		vFileNameW = Xanadu::strntow(vDirEntry->d_name);
			auto		vFileInfo = XANADU_RUNTIME_FILE_INFO_W();
			Xanadu::memset(&vFileInfo, 0, sizeof(XANADU_RUNTIME_FILE_INFO_W));
			Xanadu::wcscpy(vFileInfo.path, vDirectory);
			Xanadu::wcscat(vFileInfo.path, L"/");
			Xanadu::wcscat(vFileInfo.path, vFileNameW);
			Xanadu::wcscpy(vFileInfo.name, vFileNameW);
			vFileInfo.isDir = vDirEntry->d_type & DT_DIR;

			Xanadu::wcsfree(vFileNameW);
			if(_Function)
			{
				if(!_Function(&vFileInfo, _UserData))
				{
					break;
				}
			}
			vDirEntry = ::readdir(vHandle);
		}while(vDirEntry);
		::closedir(vHandle);
	}
	Xanadu::strfree(vDirectoryA);
#endif
	Xanadu::wcsfree(vDirectory);
	return vSync;
}

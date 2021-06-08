#ifndef			_XANADU_RUNTIME_FILESYSTEM_H_
#define			_XANADU_RUNTIME_FILESYSTEM_H_

#include <XanaduRuntime/Header.h>

#if defined(XANADU_SYSTEM_WINDOWS)
#define			R_OK							4			// Read-only
#define			W_OK							2			// Write-only
#define			X_OK							1			// The executable
#define			F_OK							0			// Existence only

#define			S_IRWXU							0000700			// RWX mask for owner
#define			S_IRUSR							0000400			// R for owner
#define			S_IWUSR							0000200			// W for owner
#define			S_IXUSR							0000100			// X for owner

#define			S_IRWXG							0000070			// RWX mask for group
#define			S_IRGRP							0000040			// R for group
#define			S_IWGRP							0000020			// W for group
#define			S_IXGRP							0000010			// X for group

#define			S_IRWXO							0000007			// RWX mask for other
#define			S_IROTH							0000004			// R for other
#define			S_IWOTH							0000002			// W for other
#define			S_IXOTH							0000001			// X for other

#define			S_ISUID							0004000			// set user id on execution
#define			S_ISGID							0002000			// set group id on execution
#define			S_ISVTX							0001000			// save swapped text even after use
#endif

namespace Xanadu
{
	XANADU_RUNTIME_EXPORT FILE* XANADUAPI fdopen(int _Fildes, const char* _Mode) noexcept;

	XANADU_RUNTIME_EXPORT FILE* XANADUAPI wfdopen(int _Fildes, const wchar_t* _Mode) noexcept;

	XANADU_RUNTIME_EXPORT FILE* XANADUAPI freopen(const char* _Filename, const char* _Mode, FILE* _Stream) noexcept;

	XANADU_RUNTIME_EXPORT FILE* XANADUAPI wfreopen(const wchar_t* _Filename, const wchar_t* _Mode, FILE* _Stream) noexcept;

	XANADU_RUNTIME_EXPORT FILE* XANADUAPI fopen(const char* _File, const char* _Mode) noexcept;

	XANADU_RUNTIME_EXPORT FILE* XANADUAPI wfopen(const wchar_t* _File, const wchar_t* _Mode) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI fseek(FILE* _Stream, long long _Offset, int _Origin) noexcept;

	XANADU_RUNTIME_EXPORT long long XANADUAPI ftell(FILE* _Stream) noexcept;

	XANADU_RUNTIME_EXPORT size_t XANADUAPI fread(void* _Buffer, size_t _Size, size_t _Count, FILE* _Stream) noexcept;

	XANADU_RUNTIME_EXPORT bool XANADUAPI fread(FILE* _Stream, void* _Buffer, size_t _Size) noexcept;

	XANADU_RUNTIME_EXPORT size_t XANADUAPI fwrite(const void* _Buffer, size_t _Size, size_t _Count, FILE* _Stream) noexcept;

	XANADU_RUNTIME_EXPORT bool XANADUAPI fwrite(FILE* _Stream, const void* _Buffer, size_t _Size) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI fflush(FILE* _Stream) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI fsync(int _Fildes) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI fgetc(FILE* _Stream) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI fgets(char* _Buffer, int _MaxCount, FILE* _Stream) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI fileno(FILE* _Stream) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI feof(FILE* _Stream) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI ferror(FILE* _Stream) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI fclose(FILE* _Stream) noexcept;

	// <summary>
	// Deletes a directory.
	// </summary>
	// <param name="_Path">Path of the directory to be removed.</param>
	// <returns>Each of these functions returns 0 if the directory is successfully deleted. A return value of –1 indicates an error and errno is set to one of the following values.</returns>
	// <returns>ENOTEMPTY : Given path is not a directory, the directory is not empty, or the directory is either the current working directory or the root directory.</returns>
	// <returns>ENOENT : Path is invalid.</returns>
	// <returns>EACCES : A program has an open handle to the directory.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI rmdir(const char* _Path) noexcept;

	// <summary>
	// Deletes a directory.
	// </summary>
	// <param name="_Path">Path of the directory to be removed.</param>
	// <returns>Each of these functions returns 0 if the directory is successfully deleted. A return value of –1 indicates an error and errno is set to one of the following values.</returns>
	// <returns>ENOTEMPTY : Given path is not a directory, the directory is not empty, or the directory is either the current working directory or the root directory.</returns>
	// <returns>ENOENT : Path is invalid.</returns>
	// <returns>EACCES : A program has an open handle to the directory.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI wrmdir(const wchar_t* _Path) noexcept;

	// <summary>
	// Creates a new directory.
	// This call integrates the chmod operation internally
	// </summary>
	// <param name="_Path">Path for a new directory.</param>
	// <param name="_Mode">Permission setting for the file.</param>
	// <returns>Each of these functions returns the value 0 if the new directory was created. On an error, the function returns –1 and sets errno as follows.</returns>
	// <returns>EEXIST : Directory was not created because dirname is the name of an existing file, directory, or device.</returns>
	// <returns>ENOENT : Path was not found.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI mkdir(const char* _Path, int _Mode = 0755) noexcept;

	// <summary>
	// Creates a new directory.
	// This call integrates the chmod operation internally
	// </summary>
	// <param name="_Path">Path for a new directory.</param>
	// <param name="_Mode">Permission setting for the file.</param>
	// <returns>Each of these functions returns the value 0 if the new directory was created. On an error, the function returns –1 and sets errno as follows.</returns>
	// <returns>EEXIST : Directory was not created because dirname is the name of an existing file, directory, or device.</returns>
	// <returns>ENOENT : Path was not found.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI wmkdir(const wchar_t* _Path, int _Mode = 0755) noexcept;

	// <summary>
	// Changes the file-permission settings.
	// </summary>
	// <param name="_Path">Name of the existing file.</param>
	// <param name="_Mode">Permission setting for the file.</param>
	// <returns>These functions return 0 if the permission setting is successfully changed. A return value of –1 indicates failure.</returns>
	// <returns>ENOENT : The specified file could not be found.</returns>
	// <returns>EINVAL : A parameter is invalid.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI chmod(const char* _Path, int _Mode = 0755) noexcept;

	// <summary>
	// Changes the file-permission settings.
	// </summary>
	// <param name="_Path">Name of the existing file.</param>
	// <param name="_Mode">Permission setting for the file.</param>
	// <returns>These functions return 0 if the permission setting is successfully changed. A return value of –1 indicates failure.</returns>
	// <returns>ENOENT : The specified file could not be found.</returns>
	// <returns>EINVAL : A parameter is invalid.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI wchmod(const wchar_t* _Path, int _Mode = 0755) noexcept;

	// <summary>
	// Delete a file.
	// </summary>
	// <param name="_Path">Path of file to be removed.</param>
	// <returns>Each of these functions returns 0 if the file is successfully deleted. Otherwise, it returns -1 and sets errno.</returns>
	// <returns>EACCES : indicate that the path specifies a read-only file or the file is open.</returns>
	// <returns>ENOENT : indicate that the filename or path was not found or that the path specifies a directory.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI remove(const char* _Path) noexcept;

	// <summary>
	// Delete a file.
	// </summary>
	// <param name="_Path">Path of file to be removed.</param>
	// <returns>Each of these functions returns 0 if the file is successfully deleted. Otherwise, it returns -1 and sets errno.</returns>
	// <returns>EACCES : indicate that the path specifies a read-only file or the file is open.</returns>
	// <returns>ENOENT : indicate that the filename or path was not found or that the path specifies a directory.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI wremove(const wchar_t* _Path) noexcept;

	// <summary>
	// Rename a file or directory.
	// </summary>
	// <param name="_Old">Pointer to old name.</param>
	// <param name="_New">Pointer to new name.</param>
	// <returns>Each of these functions returns 0 if it is successful. On an error, the function returns a nonzero value and sets errno to one of the following values.</returns>
	// <returns>EACCES : File or directory specified by _New already exists or could not be created (invalid path); or _Old is a directory and _New specifies a different path.</returns>
	// <returns>ENOENT : File or path specified by _Old not found.</returns>
	// <returns>EINVAL : Name contains invalid characters.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI rename(const char* _Old, const char* _New) noexcept;

	// <summary>
	// Rename a file or directory.
	// </summary>
	// <param name="_Old">Pointer to old name.</param>
	// <param name="_New">Pointer to new name.</param>
	// <returns>Each of these functions returns 0 if it is successful. On an error, the function returns a nonzero value and sets errno to one of the following values.</returns>
	// <returns>EACCES : File or directory specified by _New already exists or could not be created (invalid path); or _Old is a directory and _New specifies a different path.</returns>
	// <returns>ENOENT : File or path specified by _Old not found.</returns>
	// <returns>EINVAL : Name contains invalid characters.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI wrename(const wchar_t* _Old, const wchar_t* _New) noexcept;
};


#if defined(XANADU_SYSTEM_WINDOWS)
typedef			struct _stat64						XStat64;
#else
typedef			struct stat64						XStat64;
#endif

namespace Xanadu
{
	XANADU_RUNTIME_EXPORT int XANADUAPI fstat64(int _FileHandle, XStat64* _Stat) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI stat64(const char* _FileName, XStat64* _Stat) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI wstat64(const wchar_t* _FileName, XStat64* _Stat) noexcept;
};

namespace Xanadu
{
	// <summary>
	// Get file size
	// </summary>
	// <param name="_FilePath">Specify the path to the file.</param>
	// <param name="_NewFileName">The name of the new file.</param>
	// <returns>If the function succeeds, Return file size.</returns>
	// <returns>If the function fails, the return value is zero.</returns>
	XANADU_RUNTIME_EXPORT unsigned long long XANADUAPI fsize(const char* _FilePath) noexcept;

	// <summary>
	// Get file size
	// </summary>
	// <param name="_FilePath">Specify the path to the file.</param>
	// <param name="_NewFileName">The name of the new file.</param>
	// <returns>If the function succeeds, Return file size.</returns>
	// <returns>If the function fails, the return value is zero.</returns>
	XANADU_RUNTIME_EXPORT unsigned long long XANADUAPI wfsize(const wchar_t* _FilePath) noexcept;

	// <summary>
	// Copy file data.
	// The maximum buffer size is 1MB(XANADU_SIZE_MB)
	// </summary>
	// <param name="_ExistingFileName">The name of an existing file.</param>
	// <param name="_NewFileName">The name of the new file.</param>
	// <returns>If the function succeeds, the return value is zero.</returns>
	// <returns>If the function fails, the return value is nonzero.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI fcopy(const char* _ExistingFileName, const char* _NewFileName) noexcept;

	// <summary>
	// Copy file data.
	// The maximum buffer size is 1MB(XANADU_SIZE_MB)
	// </summary>
	// <param name="_ExistingFileName">The name of an existing file.</param>
	// <param name="_NewFileName">The name of the new file.</param>
	// <returns>If the function succeeds, the return value is zero.</returns>
	// <returns>If the function fails, the return value is nonzero.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI wfcopy(const wchar_t* _ExistingFileName, const wchar_t* _NewFileName) noexcept;
};

namespace Xanadu
{
	// <summary>
	// Format path. Replace \\ with /, removing the last bit of /.
	// </summary>
	// <param name="_Path">A path name.</param>
	// <returns>Returns the formatted path, which needs to be freed with strfree().</returns>
	XANADU_RUNTIME_EXPORT char* XANADUAPI fmtpath(const char* _Path) noexcept;

	// <summary>
	// Format path. Replace \\ with /, removing the last bit of /.
	// </summary>
	// <param name="_Path">A path name.</param>
	// <returns>Returns the formatted path, which needs to be freed with wcsfree().</returns>
	XANADU_RUNTIME_EXPORT wchar_t* XANADUAPI wfmtpath(const wchar_t* _Path) noexcept;

	// <summary>
	// Create a multi-level directory.
	// </summary>
	// <param name="_Directory">The absolute path to a directory.</param>
	// <returns>Returns 0 on success and -1 on failure.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI mkpath(const char* _Directory, int _Mode) noexcept;

	// <summary>
	// Create a multi-level directory.
	// </summary>
	// <param name="_Directory">The absolute path to a directory.</param>
	// <returns>Returns 0 on success and -1 on failure.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI wmkpath(const wchar_t* _Directory, int _Mode) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI access(const char* _Path, int _Mode) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI waccess(const wchar_t* _Path, int _Mode) noexcept;
};

// File information (ASCII)
typedef struct _XANADU_RUNTIME_FILE_INFO_A
{
	char 			path[XANADU_PATH];		// The file path
	char 			name[XANADU_PATH];		// The file name
	bool			isDir;				// Is it a directory
}XANADU_RUNTIME_FILE_INFO_A;

// File information (UNICODE)
typedef struct _XANADU_RUNTIME_FILE_INFO_W
{
	wchar_t 		path[XANADU_PATH];		// The file path
	wchar_t 		name[XANADU_PATH];		// The file name
	bool			isDir;				// Is it a directory
}XANADU_RUNTIME_FILE_INFO_W;

#ifdef UNICODE
#define	XANADU_RUNTIME_FILE_INFO				XANADU_RUNTIME_FILE_INFO_W
#else
#define	XANADU_RUNTIME_FILE_INFO				XANADU_RUNTIME_FILE_INFO_A
#endif

// A pointer to a callback function while traversing a directory
typedef bool(XANADUAPI *_XFunctionTraverseDirectoryA)(const XANADU_RUNTIME_FILE_INFO_A* _FileInfo, void* _UserData);
typedef bool(XANADUAPI *_XFunctionTraverseDirectoryW)(const XANADU_RUNTIME_FILE_INFO_W* _FileInfo, void* _UserData);

namespace Xanadu
{
	// <summary>
	// Directory traverse
	// </summary>
	// <param name="_Directory">The absolute path to a directory.</param>
	// <param name="_Function">The caller needs a function pointer to receive the data.</param>
	// <param name="_UserData">The data that the caller needs to transfer.</param>
	// <returns>Returns 0 on success and -1 on failure.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI traversedir(const char* _Directory, _XFunctionTraverseDirectoryA _Function, void* _UserData) noexcept;

	// <summary>
	// Directory traverse
	// </summary>
	// <param name="_Directory">The absolute path to a directory.</param>
	// <param name="_Function">The caller needs a function pointer to receive the data.</param>
	// <param name="_UserData">The data that the caller needs to transfer.</param>
	// <returns>Returns 0 on success and -1 on failure.</returns>
	XANADU_RUNTIME_EXPORT int XANADUAPI wtraversedir(const wchar_t* _Directory, _XFunctionTraverseDirectoryW _Function, void* _UserData) noexcept;
};

#endif

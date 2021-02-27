#include <XanaduCore/XanaduCoreFileInfo.h>


class XFileInfoPrivate
{
public:
	XString					_SourcePath;
	XString					_AbsolutePath;
};



/// Overload Initialize
XFileInfo::XFileInfo() XANADU_NOTHROW
{
	this->_Info = XANADU_NEW XFileInfoPrivate();
	this->_Info->_SourcePath = L"";
	this->_Info->_AbsolutePath = L"";
}

/// Overload Initialize
XFileInfo::XFileInfo(const XString& _Filepath) XANADU_NOTHROW
{
	this->_Info = XANADU_NEW XFileInfoPrivate();
	this->_Info->_SourcePath = _Filepath;
	this->_Info->_AbsolutePath = XFileInfo::ToAbsolutePath(_Filepath);
}

/// Overload Initialize
XFileInfo::XFileInfo(const XFileInfo& _Fileinfo) XANADU_NOTHROW
{
	this->_Info = XANADU_NEW XFileInfoPrivate();
	this->_Info->_SourcePath = _Fileinfo._Info->_SourcePath;
	this->_Info->_AbsolutePath = _Fileinfo._Info->_AbsolutePath;
}

/// Virtual destructor
XFileInfo::~XFileInfo() XANADU_NOTHROW
{
	XANADU_DELETE_PTR(this->_Info);
}




/// Overload Operator =
XFileInfo& XFileInfo::operator = (const XString& _Filepath) XANADU_NOTHROW
{
	this->_Info->_SourcePath = _Filepath;
	this->_Info->_AbsolutePath = XFileInfo::ToAbsolutePath(_Filepath);
	return *this;
}

/// Overload Operator =
XFileInfo& XFileInfo::operator = (const XFileInfo& _Fileinfo) XANADU_NOTHROW
{
	this->_Info->_SourcePath = _Fileinfo._Info->_SourcePath;
	this->_Info->_AbsolutePath = _Fileinfo._Info->_AbsolutePath;
	return *this;
}

/// move assignment
XFileInfo& XFileInfo::operator = (XFileInfo&& _Fileinfo) XANADU_NOTHROW
{
	XANADU_DELETE_PTR(this->_Info);
	this->_Info = _Fileinfo._Info;
	_Fileinfo._Info = XANADU_NEW XFileInfoPrivate();
	return *this;
}






/// Convert to an absolute path
XString XFileInfo::ToAbsolutePath(const XString& _Filepath) XANADU_NOTHROW
{
	auto		vFilepath = _Filepath;
	vFilepath.replace(L'\\', L'/');
	auto		vStatusAbsolute = false;
#ifdef XANADU_SYSTEM_WINDOWS
	if(vFilepath.size() >= 2 && vFilepath[1] == L':')
	{
		vStatusAbsolute = true;
	}
#else
	if(vFilepath.size() >= 1 && vFilepath[0] == L'/')
	{
		vStatusAbsolute = true;
	}
#endif /// XANADU_SYSTEM_WINDOWS
	if(vFilepath.size() >= 1)
	{
		if(vFilepath[vFilepath.size() - 1] == L'/')
		{
			vFilepath[vFilepath.size() - 1] = L'\0';
		}
	}
	/// When the path is not absolute, preface it with the current directory
	if(false == vStatusAbsolute)
	{
		wchar_t 	vDirectory[XANADU_PATH] = {0};
		Xanadu::GetCurrentDirectoryW(XANADU_PATH, vDirectory);
		vFilepath = XString(vDirectory).replace(L'\\', L'/') + L'/' + vFilepath;
	}
	/// On the basis of . and .. Building an absolute path
	/// TODO : Temporary unrealized
	return vFilepath;
}

/// Convert to an relative path
XString XFileInfo::ToRelativePath(const XString& _Filepath) XANADU_NOTHROW
{
	return _Filepath;
}






/// Check if the file exists
bool XFileInfo::exists() const XANADU_NOTHROW
{
	return 0 == Xanadu::waccess(this->_Info->_AbsolutePath.data(), F_OK);
}

XString XFileInfo::filePath() const XANADU_NOTHROW
{
	return this->_Info->_AbsolutePath;
}

XString XFileInfo::absoluteFilePath() const XANADU_NOTHROW
{
	return this->_Info->_AbsolutePath;
}

XString XFileInfo::fileName() const XANADU_NOTHROW
{
	auto		vPos = this->_Info->_AbsolutePath.rfind(L'/');
	if (vPos != XString::npos)
	{
		return this->_Info->_AbsolutePath.substr(vPos + 1);
	}
	return L"";
}

XString XFileInfo::baseName() const XANADU_NOTHROW
{
	auto		vFilename = this->fileName();
	auto		vPos = vFilename.find(L'.');
	if (vPos != XString::npos)
	{
		return vFilename.left(vPos);
	}
	return vFilename;
}

XString XFileInfo::completeBaseName() const XANADU_NOTHROW
{
	auto		vFilename = this->fileName();
	auto		vPos = vFilename.rfind(L'.');
	if (vPos != XString::npos)
	{
		return vFilename.left(vPos);
	}
	return vFilename;
}

XString XFileInfo::suffix() const XANADU_NOTHROW
{
	if (this->isFile())
	{
		auto		vFilename = this->fileName();
		auto		vPos = vFilename.rfind(L'.');
		if (vPos != XString::npos)
		{
			return vFilename.substr(vPos + 1);
		}
		return vFilename;
	}
	return L"";
}

XString XFileInfo::completeSuffix() const XANADU_NOTHROW
{
	if (this->isFile())
	{
		auto		vFilename = this->fileName();
		auto		vPos = vFilename.find(L'.');
		if (vPos != XString::npos)
		{
			return vFilename.substr(vPos + 1);
		}
		return vFilename;
	}
	return L"";
}

XString XFileInfo::path() const XANADU_NOTHROW
{
	return this->absolutePath();
}

XString XFileInfo::absolutePath() const XANADU_NOTHROW
{
	if(false == this->_Info->_SourcePath.empty())
	{
		auto		vPathSuffix = this->_Info->_SourcePath.at(this->_Info->_SourcePath.size() - 1);
		if(vPathSuffix == L'/' || vPathSuffix == L'\\')
		{
			return this->_Info->_AbsolutePath;
		}
	}
	return this->absoluteDir();
}

XString XFileInfo::dir() const XANADU_NOTHROW
{
	return this->absoluteDir();
}

XString XFileInfo::absoluteDir() const XANADU_NOTHROW
{
	auto		vPos = this->_Info->_AbsolutePath.rfind(L'/');
	if (vPos != XString::npos)
	{
		return this->_Info->_AbsolutePath.left(vPos);
	}
	return L"";
}

bool XFileInfo::isFile() const XANADU_NOTHROW
{
	return !this->isDir();
}

bool XFileInfo::isDir() const XANADU_NOTHROW
{
#ifdef XANADU_SYSTEM_WINDOWS
	if(::GetFileAttributesW(this->_Info->_AbsolutePath.data()) & FILE_ATTRIBUTE_DIRECTORY)
	{
		return true;
	}
#else
	struct stat64	vFileStatus;
	auto		vUFilepath = this->_Info->_AbsolutePath.toNString();
	if(0 == stat64(vUFilepath.data(),&vFileStatus))
	{
		return S_ISDIR (vFileStatus.st_mode);
	}
#endif /// XANADU_SYSTEM_WINDOWS
	return false;
}

int64S XFileInfo::size() const XANADU_NOTHROW
{
#ifdef XANADU_SYSTEM_WINDOWS
	struct _stat64	vFileStatus;
	if(0 == _wstat64(this->_Info->_AbsolutePath.data(),&vFileStatus))
	{
		return vFileStatus.st_size;
	}
#else
	struct stat64	vFileStatus;
	auto		vUFilepath = this->_Info->_AbsolutePath.toNString();
	if(0 == stat64(vUFilepath.data(),&vFileStatus))
	{
		return vFileStatus.st_size;
	}
#endif /// XANADU_SYSTEM_WINDOWS
	return 0;
}






/// Check if the file exists
bool XFileInfo::exists(const XString& _Filepath) XANADU_NOTHROW
{
	auto		vFileInfo = XFileInfo(_Filepath);
	return vFileInfo.exists();
}

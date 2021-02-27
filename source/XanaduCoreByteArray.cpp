//
// Created by Administrator on 2020/12/31.
//

#include <XanaduCore/XanaduCoreByteArray.h>
#include <XanaduCore/XanaduCoreBase64.h>

static char				_StaticIndexBeyond = '\0';

/// Check for Base64 characters
bool XanaduByteArrayIsBase64(unsigned char _Char)
{
	return (isalnum(_Char) || (_Char == '+') || (_Char == '/'));
}

unsigned char XanaduByteArrayHexToInt8U(char _Char)
{
	if ((_Char >= 'A') && (_Char <= 'Z'))
	{
		return _Char - 'A' + 10;
	}
	else if ((_Char >= 'a') && (_Char <= 'z'))
	{
		return _Char - 'a' + 10;
	}
	else if ((_Char >= '0') && (_Char <= '9'))
	{
		return _Char - '0';
	}
	return 0;
};

/// Check if the character is blank
bool XanaduByteArrayIsSpace(char _Char)
{
	if(_Char == ' ' || _Char == '\t' || _Char == '\n' || _Char == '\v' || _Char == '\f' || _Char == '\r')
	{
		return true;
	}
	return false;
};



/// Constructors
XByteArray::XByteArray() XANADU_NOTHROW : XAllocator()
{
}

/// Constructors
XByteArray::XByteArray(const char* _Memory, size_type _Size) XANADU_NOTHROW : XAllocator()
{
	XAllocator::MemoryAppend(_Memory, _Size == XByteArray::npos ? Xanadu::strlen(_Memory) : _Size);
}

/// Constructors
XByteArray::XByteArray(size_type _Size, char _Char) XANADU_NOTHROW : XAllocator(_Size, _Char)
{
	XAllocator::MemoryAppend(_Size, _Char);
}

/// Constructors
XByteArray::XByteArray(size_type _Size) XANADU_NOTHROW : XAllocator(_Size)
{
}

/// Constructors
XByteArray::XByteArray(const XByteArray& _Bytes) XANADU_NOTHROW : XAllocator(_Bytes.data(), _Bytes.size())
{
}

/// Destructor
XByteArray::~XByteArray() XANADU_NOTHROW
{
}


/// operator overload =
XByteArray& XByteArray::operator = (const char* _Memory) XANADU_NOTHROW
{
	this->MemoryCopy(_Memory, Xanadu::strlen(_Memory));
	return *this;
}

/// operator overload =
XByteArray& XByteArray::operator = (const XByteArray& _Bytes) XANADU_NOTHROW
{
	this->MemoryCopy(_Bytes);
	return *this;
}

/// operator overload =
XByteArray& XByteArray::operator = (XByteArray&& _Other) XANADU_NOTHROW
{
	this->MemoryMove(_Other);
	return *this;
}



/// operator overload +
XByteArray XByteArray::operator + (char _Char) const XANADU_NOTHROW
{
	auto		vTempBytes = *this;
	vTempBytes.MemoryAppend(1, _Char);
	return vTempBytes;
}

/// operator overload +
XByteArray XByteArray::operator + (const char* _Memory) const XANADU_NOTHROW
{
	auto		vTempBytes = *this;
	vTempBytes.MemoryAppend(_Memory, Xanadu::strlen(_Memory));
	return vTempBytes;
}

/// operator overload +
XByteArray XByteArray::operator + (const XByteArray& _Bytes) const XANADU_NOTHROW
{
	auto		vTempBytes = *this;
	vTempBytes.MemoryAppend(_Bytes);
	return vTempBytes;
}



/// operator overload +=
XByteArray& XByteArray::operator += (char _Char) XANADU_NOTHROW
{
	this->MemoryAppend(1, _Char);
	return *this;
}

/// operator overload +=
XByteArray& XByteArray::operator += (const char* _Memory) XANADU_NOTHROW
{
	this->MemoryAppend(_Memory, Xanadu::strlen(_Memory));
	return *this;
}

/// operator overload +=
XByteArray& XByteArray::operator += (const XByteArray& _Bytes) XANADU_NOTHROW
{
	this->MemoryAppend(_Bytes);
	return *this;
}




/// operator overload ==
bool XByteArray::operator == (const char* _Memory)const  XANADU_NOTHROW
{
	return 0 == this->compare(_Memory);
}

/// operator overload ==
bool XByteArray::operator == (const XByteArray& _Bytes)const  XANADU_NOTHROW
{
	return 0 == this->compare(_Bytes);
}





/// Get data pointer
char* XByteArray::data() XANADU_NOTHROW
{
	return static_cast<char*>(XAllocator::MemoryAddress());
}

/// Get data const pointer
const char* XByteArray::data() const XANADU_NOTHROW
{
	return static_cast<const char*>(XAllocator::MemoryAddress());
}

/// Get data size
XByteArray::size_type XByteArray::size() const XANADU_NOTHROW
{
	return XAllocator::MemoryLength();
}

/// Get Data size
XByteArray::size_type XByteArray::length() const XANADU_NOTHROW
{
	return this->size();
}

/// resize
void XByteArray::resize(size_type _Size) XANADU_NOTHROW
{
	this->MemoryResize(_Size);
}

/// Truncates the byte array at index position pos. If pos is beyond the end of the array, nothing happens.
void XByteArray::truncate(size_type _Index) XANADU_NOTHROW
{
	this->MemoryTruncate(_Index);
}

/// Fills a character to the specified length of space, or if -1, all of it
XByteArray& XByteArray::fill(char _Char, size_type _Size) XANADU_NOTHROW
{
	if (_Size > this->size())
	{
		_Size = this->size();
	}
	for (auto vIndex = 0ULL; vIndex < _Size; ++vIndex)
	{
		this->operator[](vIndex) = _Char;
	}
	return *this;
}

/// Get the current capacity
XByteArray::size_type XByteArray::capacity() const XANADU_NOTHROW
{
	return this->MemoryCapacity();
}

/// Check for null values
bool XByteArray::empty() const XANADU_NOTHROW
{
	return this->MemoryIsEmpty();
}

/// Check if there is a value
bool XByteArray::exist() const XANADU_NOTHROW
{
	return this->MemoryIsExist();
}





/// Read by subscript
char XByteArray::at(size_type _Index) const XANADU_NOTHROW
{
	if (_Index < size())
	{
		return data()[_Index];
	}
	return '\0';
}

/// Get the first one
char& XByteArray::front() XANADU_NOTHROW
{
	return operator[](0);
}

/// Get the first one
char XByteArray::front() const XANADU_NOTHROW
{
	return this->at(0);
}

/// Get the last one
char& XByteArray::back() XANADU_NOTHROW
{
	return operator[](this->size() - 1);
}

/// Get the last one
char XByteArray::back() const XANADU_NOTHROW
{
	return this->at(this->size() - 1);
}

/// Read by subscript
char& XByteArray::operator [] (size_type _Index) XANADU_NOTHROW
{
	if (_Index < size())
	{
		return data()[_Index];
	}
	return _StaticIndexBeyond;
}

/// Read by subscript
char XByteArray::operator [] (size_type _Index) const XANADU_NOTHROW
{
	return this->at(_Index);
}





/// Iterator operation
XByteArray::iterator XByteArray::begin() XANADU_NOTHROW
{
	return this->data();
}

/// Iterator operation
XByteArray::const_iterator XByteArray::begin() const XANADU_NOTHROW
{
	return this->data();
}

/// Iterator operation
XByteArray::const_iterator XByteArray::cbegin() const XANADU_NOTHROW
{
	return this->data();
}

/// Iterator operation
XByteArray::const_iterator XByteArray::constBegin() const XANADU_NOTHROW
{
	return this->data();
}

/// Iterator operation
XByteArray::iterator XByteArray::end() XANADU_NOTHROW
{
	return this->data() + this->size();
}

/// Iterator operation
XByteArray::const_iterator XByteArray::end() const XANADU_NOTHROW
{
	return this->data() + this->size();
}

/// Iterator operation
XByteArray::const_iterator XByteArray::cend() const XANADU_NOTHROW
{
	return this->data() + this->size();
}

/// Iterator operation
XByteArray::const_iterator XByteArray::constEnd() const XANADU_NOTHROW
{
	return this->data() + this->size();
}

/// Iterator operation
XByteArray::reverse_iterator XByteArray::rbegin() XANADU_NOTHROW
{
	return reverse_iterator(end());
}

/// Iterator operation
XByteArray::reverse_iterator XByteArray::rend() XANADU_NOTHROW
{
	return reverse_iterator(begin());
}

/// Iterator operation
XByteArray::const_reverse_iterator XByteArray::rbegin() const XANADU_NOTHROW
{
	return const_reverse_iterator(end());
}

/// Iterator operation
XByteArray::const_reverse_iterator XByteArray::rend() const XANADU_NOTHROW
{
	return const_reverse_iterator(begin());
}

/// Iterator operation
XByteArray::const_reverse_iterator XByteArray::crbegin() const XANADU_NOTHROW
{
	return const_reverse_iterator(end());
}

/// Iterator operation
XByteArray::const_reverse_iterator XByteArray::crend() const XANADU_NOTHROW
{
	return const_reverse_iterator(begin());
}





/// Vector compatibility: increments to the last bit
void XByteArray::push_back(char _Char) XANADU_NOTHROW
{
	this->append(_Char);
}

/// Vector compatibility: increments to the last bit
void XByteArray::push_back(const char* _Memory) XANADU_NOTHROW
{
	this->append(_Memory);
}

/// Vector compatibility: increments to the last bit
void XByteArray::push_back(const XByteArray& _Bytes) XANADU_NOTHROW
{
	this->append(_Bytes);
}

/// Vector compatible: increments to the first
void XByteArray::push_front(char _Char) XANADU_NOTHROW
{
	this->prepend(_Char);
}

/// Vector compatible: increments to the first
void XByteArray::push_front(const char* _Memory) XANADU_NOTHROW
{
	this->prepend(_Memory);
}

/// Vector compatible: increments to the first
void XByteArray::push_front(const XByteArray& _Bytes) XANADU_NOTHROW
{
	this->prepend(_Bytes);
}





/// Add at the front
XByteArray& XByteArray::prepend(char _Char) XANADU_NOTHROW
{
	return this->insert(0, _Char);
}

/// Add at the front
XByteArray& XByteArray::prepend(size_type _Count, char _Char) XANADU_NOTHROW
{
	return this->insert(0, _Count, _Char);
}

/// Add at the front
XByteArray& XByteArray::prepend(const char* _String) XANADU_NOTHROW
{
	return this->insert(0, _String);
}

/// Add at the front
XByteArray& XByteArray::prepend(const char* _String, size_type _Length) XANADU_NOTHROW
{
	return this->insert(0, _String, _Length);
}

/// Add at the front
XByteArray& XByteArray::prepend(const XByteArray& _Bytes) XANADU_NOTHROW
{
	return this->insert(0, _Bytes);
}

/// Add at the end
XByteArray& XByteArray::append(char _Char) XANADU_NOTHROW
{
	return this->insert(this->size(), _Char);
}

/// Add at the end
XByteArray& XByteArray::append(size_type _Count, char _Char) XANADU_NOTHROW
{
	return this->insert(this->size(), _Count, _Char);
}

/// Add at the end
XByteArray& XByteArray::append(const char* _String) XANADU_NOTHROW
{
	return this->insert(this->size(), _String);
}

/// Add at the end
XByteArray& XByteArray::append(const char* _String, size_type _Length) XANADU_NOTHROW
{
	return this->insert(this->size(), _String, _Length);
}

/// Add at the end
XByteArray& XByteArray::append(const XByteArray& _Bytes) XANADU_NOTHROW
{
	return this->insert(this->size(), _Bytes);
}

/// Insert by pos
XByteArray& XByteArray::insert(size_type _Index, char _Char) XANADU_NOTHROW
{
	return this->insert(_Index, 1, _Char);
}

/// Insert by pos
XByteArray& XByteArray::insert(size_type _Index, size_type _Count, char _Char) XANADU_NOTHROW
{
	if(_Count > 0)
	{
		auto		vSize = static_cast<unsigned int>(_Count);
		auto		vBuffer = XANADU_NEW char[vSize + 1];
		if(vBuffer)
		{
			Xanadu::memset(vBuffer, _Char, _Count);
			vBuffer[_Count] = '\0';
			this->insert(_Index, vBuffer);
			XANADU_DELETE_ARR(vBuffer);
		}
	}
	return *this;
}

/// Insert by pos
XByteArray& XByteArray::insert(size_type _Index, const char* _String) XANADU_NOTHROW
{
	return this->insert(_Index, _String, Xanadu::strlen(_String));
}

/// Insert by pos
XByteArray& XByteArray::insert(size_type _Index, const char* _String, size_type _Length) XANADU_NOTHROW
{
	if (_String && _Length > 0)
	{
		_Index = XAllocator::MemoryPosFix(_Index);
		this->MemoryInsert(_Index, _String, _Length);
	}
	return *this;
}

/// Insert by pos
XByteArray& XByteArray::insert(size_type _Index, const XByteArray& _Bytes) XANADU_NOTHROW
{
	return this->insert(_Index, _Bytes.data(), _Bytes.size());
}






/// Delete the specified length of data from the specified pos
XByteArray& XByteArray::remove(size_type _Index, size_type _Length) XANADU_NOTHROW
{
	this->MemoryRemove(_Index, _Length);
	return *this;
}

/// Delete the specified length of data from the specified pos
XByteArray& XByteArray::remove(const char _Char) XANADU_NOTHROW
{
	char		vBuffer[2] = {0};
	vBuffer[0] = _Char;
	vBuffer[1] = '\0';
	return this->remove(vBuffer);
}

/// Delete the specified length of data from the specified pos
XByteArray& XByteArray::remove(const char* _Memory) XANADU_NOTHROW
{
	return this->remove(_Memory, Xanadu::strlen(_Memory));
}

/// Delete the specified length of data from the specified pos
XByteArray& XByteArray::remove(const char* _Memory, size_type _Size) XANADU_NOTHROW
{
	if(_Size = XByteArray::npos)
	{
		_Size = Xanadu::strlen(_Memory);
	}
	if (_Memory && _Size > 0)
	{
		auto		vFind = this->find(_Memory, 0);
		while (vFind != XByteArray::npos)
		{
			this->remove(vFind, _Size);
			vFind = this->find(_Memory, vFind);
		};
	}
	return *this;
}

/// Delete the specified length of data from the specified pos
XByteArray& XByteArray::remove(const XByteArray& _Bytes) XANADU_NOTHROW
{
	return this->remove(_Bytes.data(), _Bytes.size());
}






/// Replace data
XByteArray& XByteArray::replace(size_type _Index, size_type _Length, const char* _After) XANADU_NOTHROW
{
	return this->replace(_Index, _Length, _After, Xanadu::strlen(_After));
}

/// Replace data
XByteArray& XByteArray::replace(size_type _Index, size_type _Length, const char* _After, size_type _Asize) XANADU_NOTHROW
{
	this->MemoryReplace(_Index, _Length, _After, _Asize);
	return *this;
}

/// Replace data
XByteArray& XByteArray::replace(size_type _Index, size_type _Length, const XByteArray& _Bytes) XANADU_NOTHROW
{
	return this->replace(_Index, _Length, _Bytes.data(), _Bytes.size());
}

/// Replace data
XByteArray& XByteArray::replace(char _Before, const char* _After) XANADU_NOTHROW
{
	char 		vBuffer[2] = {_Before, '\0'};
	return this->replace(vBuffer, Xanadu::strlen(vBuffer), _After, Xanadu::strlen(_After));
}

/// Replace data
XByteArray& XByteArray::replace(char _Before, const XByteArray& _After) XANADU_NOTHROW
{
	char 		vBuffer[2] = {_Before, '\0'};
	return this->replace(vBuffer, Xanadu::strlen(vBuffer), _After.data(), _After.size());
}

/// Replace data
XByteArray& XByteArray::replace(const char* _Before, const char* _After) XANADU_NOTHROW
{
	return this->replace(_Before, Xanadu::strlen(_Before), _After, Xanadu::strlen(_After));
}

/// Replace data
XByteArray& XByteArray::replace(const char* _Before, size_type _Bsize, const char* _After, size_type _Asize) XANADU_NOTHROW
{
	auto		vIndex = 0LL;
	while (_Before && _Bsize > 0 && _After && _Asize >= 0)
	{
		auto		vPos = this->MemoryFind(vIndex, _Before, _Bsize);
		if (XByteArray::npos == vPos)
		{
			break;
		}
		this->MemoryReplace(vPos, _Bsize, _After, _Asize);
		vIndex += _Asize;
	};
	return *this;
}

/// Replace data
XByteArray& XByteArray::replace(const XByteArray& _Before, const XByteArray& _After) XANADU_NOTHROW
{
	return this->replace(_Before.data(), _Before.size(), _After.data(), _After.size());
}

/// Replace data
XByteArray& XByteArray::replace(const XByteArray& _Before, const char* _After) XANADU_NOTHROW
{
	return this->replace(_Before.data(), _Before.size(), _After, Xanadu::strlen(_After));
}

/// Replace data
XByteArray& XByteArray::replace(const char* _Before, const XByteArray& _After) XANADU_NOTHROW
{
	return this->replace(_Before, Xanadu::strlen(_Before), _After.data(), _After.size());
}

/// Replace data
XByteArray& XByteArray::replace(char _Before, char _After) XANADU_NOTHROW
{
	char 		vBuffer1[2] = {_Before, '\0'};
	char 		vBuffer2[2] = {_After, '\0'};
	return this->replace(vBuffer1, Xanadu::strlen(vBuffer1), vBuffer2, Xanadu::strlen(vBuffer2));
}





/// Get the data on the left by length
XByteArray XByteArray::left(size_type _Length) const XANADU_NOTHROW
{
	if (_Length > 0)
	{
		if (_Length >= this->size())
		{
			return *this;
		}
		else
		{
			return XByteArray(this->data(), _Length);
		}
	}
	return XByteArray();
}

/// Get the data on the right by length
XByteArray XByteArray::right(size_type _Length) const XANADU_NOTHROW
{
	if (_Length > 0)
	{
		if (_Length >= this->size())
		{
			return *this;
		}
		else
		{
			return XByteArray(this->data() + (this->size() - _Length), _Length);
		}
	}
	return XByteArray();
}

/// Retrieve the middle data by length
XByteArray XByteArray::mid(size_type _Index, size_type _Length) const XANADU_NOTHROW
{
	auto		vPos = XAllocator::MemoryPosFix(_Index);
	if (_Length >= this->size() || _Index + _Length >= this->size())
	{
		return XByteArray(this->data() + _Index, this->size() - _Index);
	}
	return XByteArray(this->data() + vPos, _Length);
}





/// Check if the head is the same
bool XByteArray::startsWith(char _Char) const XANADU_NOTHROW
{
	return this->startsWith(XByteArray(_Char));
}

/// Check if the head is the same
bool XByteArray::startsWith(const char* _Memory) const XANADU_NOTHROW
{
	return this->startsWith(XByteArray(_Memory, Xanadu::strlen(_Memory)));
}

/// Check if the head is the same
bool XByteArray::startsWith(const XByteArray& _Bytes) const XANADU_NOTHROW
{
	if (this->size() >= _Bytes.size() && _Bytes.exist())
	{
		for(auto vIndex = 0ULL; vIndex < _Bytes.size(); ++vIndex)
		{
			if(this->operator[](vIndex) != _Bytes.operator[](vIndex))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

/// Check if the tails are the same
bool XByteArray::endsWith(char _Char) const XANADU_NOTHROW
{
	return this->endsWith(XByteArray(_Char));
}

/// Check if the tails are the same
bool XByteArray::endsWith(const char* _Memory) const XANADU_NOTHROW
{
	return this->endsWith(XByteArray(_Memory, Xanadu::strlen(_Memory)));
}

/// Check if the tails are the same
bool XByteArray::endsWith(const XByteArray& _Bytes) const XANADU_NOTHROW
{
	if (this->size() >= _Bytes.size() && _Bytes.exist())
	{
		for(auto vIndex = 0ULL; vIndex < _Bytes.size(); ++vIndex)
		{
			if(this->operator[](vIndex + this->size() - _Bytes.size()) != _Bytes.operator[](vIndex))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}






/// Find in positive order from the specified location
XByteArray::size_type XByteArray::find(char _Char, size_type _From) const XANADU_NOTHROW
{
	char		vBuffer[2] = {_Char, '\0'};
	return this->find(XByteArray(vBuffer, 1), _From);
}

/// Find in positive order from the specified location
XByteArray::size_type XByteArray::find(const char* _Memory, size_type _From) const XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Memory, XByteArray::npos);

	return this->find(XByteArray(_Memory, Xanadu::strlen(_Memory)), _From);
}

/// Find in positive order from the specified location
XByteArray::size_type XByteArray::find(const XByteArray& _Bytes, size_type _From) const XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Bytes.size(), XByteArray::npos);

	return XAllocator::MemoryFind(_From, _Bytes.data(), _Bytes.size());
}

/// Find in reverse order from the specified location
XByteArray::size_type XByteArray::rfind(char _Char, size_type _From) const XANADU_NOTHROW
{
	char		vBuffer[2] = {_Char, '\0'};
	return this->rfind(XByteArray(vBuffer, 1), _From);
}

/// Find in reverse order from the specified location
XByteArray::size_type XByteArray::rfind(const char* _Memory, size_type _From) const XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Memory, XByteArray::npos);

	return this->rfind(XByteArray(_Memory, Xanadu::strlen(_Memory)), _From);
}

/// Find in reverse order from the specified location
XByteArray::size_type XByteArray::rfind(const XByteArray& _Bytes, size_type _From) const XANADU_NOTHROW
{
	XANADU_CHECK_RETURN(_Bytes.size(), XByteArray::npos);

	return XAllocator::MemoryReverseFind(_From, _Bytes.data(), _Bytes.size());
}





/// Find in positive order from the specified location
XByteArray::size_type XByteArray::indexOf(char _Char, size_type _From) const XANADU_NOTHROW
{
	return this->find(_Char, _From);
}

/// Find in positive order from the specified location
XByteArray::size_type XByteArray::indexOf(const char* _Memory, size_type _From) const XANADU_NOTHROW
{
	return this->find(_Memory, _From);
}

/// Find in positive order from the specified location
XByteArray::size_type XByteArray::indexOf(const XByteArray& _Bytes, size_type _From) const XANADU_NOTHROW
{
	return this->find(_Bytes, _From);
}

/// Find in reverse order from the specified location
XByteArray::size_type XByteArray::lastIndexOf(char _Char, size_type _From) const XANADU_NOTHROW
{
	return this->rfind(_Char, _From);
}

/// Find in reverse order from the specified location
XByteArray::size_type XByteArray::lastIndexOf(const char* _Memory, size_type _From) const XANADU_NOTHROW
{
	return this->rfind(_Memory, _From);
}

/// Find in reverse order from the specified location
XByteArray::size_type XByteArray::lastIndexOf(const XByteArray& _Bytes, size_type _From) const XANADU_NOTHROW
{
	return this->rfind(_Bytes, _From);
}






/// Check for inclusion
bool XByteArray::contains(char _Char) const XANADU_NOTHROW
{
	return this->find(_Char, 0);
}

/// Check for inclusion
bool XByteArray::contains(const char* _Memory) const XANADU_NOTHROW
{
	return this->find(_Memory, 0);
}

/// Check for inclusion
bool XByteArray::contains(const XByteArray& _Bytes) const XANADU_NOTHROW
{
	return this->find(_Bytes, 0);
}

/// Check if they are the same
int XByteArray::compare(const char* _Memory, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return this->compare(XByteArray(_Memory), _XCS);
}

/// Check if they are the same
int XByteArray::compare(const XByteArray& _Bytes, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	if (this->empty() && _Bytes.empty())
	{
		return 0;
	}
	if(this->empty())
	{
		return -1;
	}
	if(_Bytes.empty())
	{
		return 1;
	}

	if (_XCS == Xanadu::CaseSensitive)
	{
		return this->toUpper().compare(_Bytes.toUpper(), Xanadu::CaseInsensitive);
	}
	else
	{
		auto		vLength = this->length() <= _Bytes.length() ? this->length() : _Bytes.length();
		auto 		vCompare = Xanadu::memcmp(this->data(), _Bytes.data(), vLength);
		if(0 == vCompare)
		{
			vCompare = static_cast<int>(this->length() - _Bytes.length());
		}
		return vCompare;
	}
}






/// Check if it's lowercase
bool XByteArray::isLower() const XANADU_NOTHROW
{
	for (auto vIndex = 0ULL; vIndex < this->size(); ++vIndex)
	{
		if ('A' <= this->operator[](vIndex) && this->operator[](vIndex) <= 'Z')
		{
			return false;
		}
	}
	return true;
}

/// Check if it's uppercase
bool XByteArray::isUpper() const XANADU_NOTHROW
{
	for (auto vIndex = 0ULL; vIndex < this->size(); ++vIndex)
	{
		if ('a' <= this->operator[](vIndex) && this->operator[](vIndex) <= 'z')
		{
			return false;
		}
	}
	return true;
}

/// Convert to lowercase
XByteArray XByteArray::toLower() const XANADU_NOTHROW
{
	auto		vBytes = XByteArray();
	for (auto vIndex = 0ULL; vIndex < this->size(); ++vIndex)
	{
		auto		vChar = this->operator[](vIndex);
		if ('A' <= this->operator[](vIndex) && this->operator[](vIndex) <= 'Z')
		{
			vChar = Xanadu::tolower(vChar);
		}
		vBytes.append(vChar);
	}
	return vBytes;
}

/// Convert to uppercase
XByteArray XByteArray::toUpper() const XANADU_NOTHROW
{
	auto		vBytes = XByteArray();
	for (auto vIndex = 0ULL; vIndex < this->size(); ++vIndex)
	{
		auto		vChar = this->operator[](vIndex);
		if ('a' <= this->operator[](vIndex) && this->operator[](vIndex) <= 'z')
		{
			vChar = Xanadu::toupper(vChar);
		}
		vBytes.append(vChar);
	}
	return vBytes;
}

/// Remove start and end whitespace strings ('\t','\n','\v','\f','\r','_')
XByteArray XByteArray::trimmed() const XANADU_NOTHROW
{
	auto		vBeginPos = 0ULL;
	auto		vEndPos = this->size() - 1;
	/// Positive sequence check
	for (vBeginPos = 0ULL; vBeginPos < this->size(); ++vBeginPos)
	{
		if (XanaduByteArrayIsSpace(this->operator[](vBeginPos)))
		{
			break;
		}
	}
	/// Check order
	for (vEndPos = this->size() - 1; vEndPos >= 0; --vEndPos)
	{
		if (XanaduByteArrayIsSpace(this->operator[](vBeginPos)))
		{
			break;
		}
	}
	if (vBeginPos >= vEndPos)
	{
		return this->mid(vBeginPos, vEndPos - vBeginPos);
	}
	return XByteArray();
}

/// Remove beginning, middle, and end whitespace strings ('\t','\n','\v','\f','\r','_')
XByteArray XByteArray::simplified() const XANADU_NOTHROW
{
	auto		vBytes = this->trimmed();
	auto		vResult = XByteArray();
	auto		vExistSpace = false;
	for (auto vIndex = 0ULL; vIndex < vBytes.size(); ++vIndex)
	{
		if (XanaduByteArrayIsSpace(vBytes.operator[](vIndex)))
		{
			vExistSpace = true;
		}
		else
		{
			if (vExistSpace)
			{
				vResult.append(' ');
				vExistSpace = false;
			}
			vResult.append(vBytes.operator[](vIndex));
		}
	}
	return vResult;
}

/// split
std::list<XByteArray> XByteArray::split(const char _Char) const XANADU_NOTHROW
{
	char		vBuffer[2] = {0};
	vBuffer[0] = _Char;
	vBuffer[1] = '\0';
	return this->split(vBuffer, 1ULL);
}

/// split
std::list<XByteArray> XByteArray::split(const char* _Memory) const XANADU_NOTHROW
{
	return this->split(XByteArray(_Memory, Xanadu::strlen(_Memory)));
}

/// split
std::list<XByteArray> XByteArray::split(const char* _Memory, size_type _Size) const XANADU_NOTHROW
{
	return this->split(XByteArray(_Memory, _Size));
}

/// split
std::list<XByteArray> XByteArray::split(const XByteArray& _Bytes) const XANADU_NOTHROW
{
	auto		vHeaderArray = std::list<XByteArray>();
	auto		vLast = static_cast<size_type>(0ULL);
	auto		vSplitIndex = this->indexOf(_Bytes, vLast);
	while(vSplitIndex != XByteArray::npos && _Bytes.exist())
	{
		vHeaderArray.push_back(this->mid(vLast, vSplitIndex - vLast));
		vLast = vSplitIndex + 2;
		vSplitIndex = this->indexOf(_Bytes, vLast);
	}
	vHeaderArray.push_back(this->mid(vLast));

	return vHeaderArray;
}









/// Convert to Base64
XByteArray XByteArray::toBase64() const XANADU_NOTHROW
{
	return XCryptoBase64::Encode(this->data(), this->size());
}

/// Convert to HEX
XByteArray XByteArray::toHex() const XANADU_NOTHROW
{
	auto		vTarget = XByteArray(this->size() * 2);
	char		vBufferHex[3] = {0};
	for (auto vIndex = 0U; vIndex < this->size(); ++vIndex)
	{
		sprintf(vBufferHex, "%02X", (int8U)this->at(vIndex));
		vTarget[vIndex * 2 + 0] = vBufferHex[0];
		vTarget[vIndex * 2 + 1] = vBufferHex[1];
	}
	return vTarget;
}

/// Format from memory
XByteArray XANADUAPI XByteArray::fromMemory(const char* _Memory, size_type _Size) XANADU_NOTHROW
{
	return XByteArray(_Memory, _Size);
}

/// Format from Base64
XByteArray XANADUAPI XByteArray::fromBase64(const void* _Memory, size_type _Size) XANADU_NOTHROW
{
	return XCryptoBase64::Decode(_Memory, _Size);
}

/// Format from Base64
XByteArray XANADUAPI XByteArray::fromBase64(const XByteArray& _Bytes) XANADU_NOTHROW
{
	return XByteArray::fromBase64(_Bytes.data(), _Bytes.size());
}

/// Format from HEX
XByteArray XANADUAPI XByteArray::fromHex(const void* _Memory, size_type _Size) XANADU_NOTHROW
{
	if (nullptr == _Memory)
	{
		return XByteArray();
	}
	if(_Size == XByteArray::npos)
	{
		_Size = Xanadu::strlen(static_cast<const char*>(_Memory));
	}

	auto		vBuffer = static_cast<const char*>(_Memory);
	auto		vLength = _Size / 2;
	auto		vTarget = XByteArray(vLength);
	if(_Memory && _Size > 0)
	{
		for (auto vIndex = 0ULL; vIndex < vLength; ++vIndex)
		{
			auto		vHexLeft = XanaduByteArrayHexToInt8U(vBuffer[vIndex * 2 + 0]);
			auto		vHexRight = XanaduByteArrayHexToInt8U(vBuffer[vIndex * 2 + 1]);

			vTarget[vIndex] = vHexLeft * 16 + vHexRight;
		}
	}
	return vTarget;
}

/// Format from HEX
XByteArray XANADUAPI XByteArray::fromHex(const XByteArray& _Bytes) XANADU_NOTHROW
{
	return XByteArray::fromHex(_Bytes.data(), _Bytes.size());
}

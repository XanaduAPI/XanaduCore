#include <XanaduCore/XByteArray.h>
#include <XanaduCore/XBase64.h>

static char				_StaticIndexBeyond = '\0';

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

// Check if the character is blank
bool XanaduByteArrayIsSpace(char _Char)
{
	if(_Char == ' ' || _Char == '\t' || _Char == '\n' || _Char == '\v' || _Char == '\f' || _Char == '\r')
	{
		return true;
	}
	return false;
};



// Constructors
XByteArray::XByteArray() noexcept : XAllocator()
{
}

// Constructors
XByteArray::XByteArray(const char* _Memory, size_type _Size) noexcept : XAllocator()
{
	XAllocator::memoryAppend(_Memory, _Size == XByteArray::npos ? Xanadu::strlen(_Memory) : _Size);
}

// Constructors
XByteArray::XByteArray(size_type _Size, char _Char) noexcept : XAllocator(_Size, _Char)
{
	XAllocator::memoryAppend(_Size, _Char);
}

// Constructors
XByteArray::XByteArray(size_type _Size) noexcept : XAllocator(_Size)
{
}

// Constructors
XByteArray::XByteArray(const XByteArray& _Bytes) noexcept : XAllocator(_Bytes.data(), _Bytes.size())
{
}

// Destructor
XByteArray::~XByteArray() noexcept
{
}


// operator overload =
XByteArray& XByteArray::operator = (const char* _Memory) noexcept
{
	this->memoryCopy(_Memory, Xanadu::strlen(_Memory));
	return *this;
}

// operator overload =
XByteArray& XByteArray::operator = (const XByteArray& _Bytes) noexcept
{
	this->memoryCopy(_Bytes);
	return *this;
}

// operator overload =
XByteArray& XByteArray::operator = (XByteArray&& _Other) noexcept
{
	this->memoryMove(_Other);
	return *this;
}



// operator overload +
XByteArray XByteArray::operator + (char _Char) const noexcept
{
	auto		vTempBytes = *this;
	vTempBytes.memoryAppend(1, _Char);
	return vTempBytes;
}

// operator overload +
XByteArray XByteArray::operator + (const char* _Memory) const noexcept
{
	auto		vTempBytes = *this;
	vTempBytes.memoryAppend(_Memory, Xanadu::strlen(_Memory));
	return vTempBytes;
}

// operator overload +
XByteArray XByteArray::operator + (const XByteArray& _Bytes) const noexcept
{
	auto		vTempBytes = *this;
	vTempBytes.memoryAppend(_Bytes);
	return vTempBytes;
}



// operator overload +=
XByteArray& XByteArray::operator += (char _Char) noexcept
{
	this->memoryAppend(1, _Char);
	return *this;
}

// operator overload +=
XByteArray& XByteArray::operator += (const char* _Memory) noexcept
{
	this->memoryAppend(_Memory, Xanadu::strlen(_Memory));
	return *this;
}

// operator overload +=
XByteArray& XByteArray::operator += (const XByteArray& _Bytes) noexcept
{
	this->memoryAppend(_Bytes);
	return *this;
}




// operator overload ==
bool XByteArray::operator == (const char* _Memory) const  noexcept
{
	return 0 == this->compare(_Memory);
}

// operator overload ==
bool XByteArray::operator == (const XByteArray& _Bytes) const  noexcept
{
	return 0 == this->compare(_Bytes);
}





// operator overload !=
bool XByteArray::operator != (const char* _Memory) const  noexcept
{
	return 0 != this->compare(_Memory);
}

// operator overload !=
bool XByteArray::operator != (const XByteArray& _Bytes) const  noexcept
{
	return 0 != this->compare(_Bytes);
}





// Get data pointer
char* XByteArray::data() noexcept
{
	return static_cast<char*>(XAllocator::memoryAddress());
}

// Get data const pointer
const char* XByteArray::data() const noexcept
{
	return static_cast<const char*>(XAllocator::memoryAddress());
}

// Get data size
XByteArray::size_type XByteArray::size() const noexcept
{
	return XAllocator::memoryLength();
}

// Get Data size
XByteArray::size_type XByteArray::length() const noexcept
{
	return this->size();
}

// resize
void XByteArray::resize(size_type _Size) noexcept
{
	this->memoryResize(_Size);
}

// Truncates the byte array at index position pos. If pos is beyond the end of the array, nothing happens.
void XByteArray::truncate(size_type _Index) noexcept
{
	this->memoryTruncate(_Index);
}

// Fills a character to the specified length of space, or if -1, all of it
XByteArray& XByteArray::fill(char _Char, size_type _Size) noexcept
{
	if (_Size > this->size())
	{
		_Size = this->size();
	}
	for (XByteArray::size_type vIndex = 0U; vIndex < _Size; ++vIndex)
	{
		this->operator[](vIndex) = _Char;
	}
	return *this;
}

// Get the current capacity
XByteArray::size_type XByteArray::capacity() const noexcept
{
	return this->memoryCapacity();
}

// Check for null values
bool XByteArray::empty() const noexcept
{
	return this->memoryIsEmpty();
}

// Check if there is a value
bool XByteArray::exist() const noexcept
{
	return this->memoryIsExist();
}





// read by subscript
char XByteArray::at(size_type _Index) const noexcept
{
	if (_Index < this->size())
	{
		return this->data()[_Index];
	}
	return '\0';
}

// Get the first one
char& XByteArray::front() noexcept
{
	return operator[](0);
}

// Get the first one
char XByteArray::front() const noexcept
{
	return this->at(0);
}

// Get the last one
char& XByteArray::back() noexcept
{
	return operator[](this->size() - 1);
}

// Get the last one
char XByteArray::back() const noexcept
{
	return this->at(this->size() - 1);
}

// read by subscript
char& XByteArray::operator [] (size_type _Index) noexcept
{
	if (_Index < this->size())
	{
		return this->data()[_Index];
	}
	return _StaticIndexBeyond;
}

// read by subscript
char XByteArray::operator [] (size_type _Index) const noexcept
{
	return this->at(_Index);
}





// Iterator operation
XByteArray::iterator XByteArray::begin() noexcept
{
	return this->data();
}

// Iterator operation
XByteArray::const_iterator XByteArray::begin() const noexcept
{
	return this->data();
}

// Iterator operation
XByteArray::const_iterator XByteArray::cbegin() const noexcept
{
	return this->data();
}

// Iterator operation
XByteArray::const_iterator XByteArray::constBegin() const noexcept
{
	return this->data();
}

// Iterator operation
XByteArray::iterator XByteArray::end() noexcept
{
	return this->data() + this->size();
}

// Iterator operation
XByteArray::const_iterator XByteArray::end() const noexcept
{
	return this->data() + this->size();
}

// Iterator operation
XByteArray::const_iterator XByteArray::cend() const noexcept
{
	return this->data() + this->size();
}

// Iterator operation
XByteArray::const_iterator XByteArray::constEnd() const noexcept
{
	return this->data() + this->size();
}

// Iterator operation
XByteArray::reverse_iterator XByteArray::rbegin() noexcept
{
	return reverse_iterator(this->end());
}

// Iterator operation
XByteArray::reverse_iterator XByteArray::rend() noexcept
{
	return reverse_iterator(this->begin());
}

// Iterator operation
XByteArray::const_reverse_iterator XByteArray::rbegin() const noexcept
{
	return const_reverse_iterator(this->end());
}

// Iterator operation
XByteArray::const_reverse_iterator XByteArray::rend() const noexcept
{
	return const_reverse_iterator(this->begin());
}

// Iterator operation
XByteArray::const_reverse_iterator XByteArray::crbegin() const noexcept
{
	return const_reverse_iterator(this->end());
}

// Iterator operation
XByteArray::const_reverse_iterator XByteArray::crend() const noexcept
{
	return const_reverse_iterator(this->begin());
}





// Vector compatibility: increments to the last bit
void XByteArray::push_back(char _Char) noexcept
{
	this->append(_Char);
}

// Vector compatibility: increments to the last bit
void XByteArray::push_back(const char* _Memory) noexcept
{
	this->append(_Memory);
}

// Vector compatibility: increments to the last bit
void XByteArray::push_back(const XByteArray& _Bytes) noexcept
{
	this->append(_Bytes);
}

// Vector compatible: increments to the first
void XByteArray::push_front(char _Char) noexcept
{
	this->prepend(_Char);
}

// Vector compatible: increments to the first
void XByteArray::push_front(const char* _Memory) noexcept
{
	this->prepend(_Memory);
}

// Vector compatible: increments to the first
void XByteArray::push_front(const XByteArray& _Bytes) noexcept
{
	this->prepend(_Bytes);
}





// Add at the front
XByteArray& XByteArray::prepend(char _Char) noexcept
{
	return this->insert(0ULL, _Char);
}

// Add at the front
XByteArray& XByteArray::prepend(size_type _Count, char _Char) noexcept
{
	return this->insert(0ULL, _Count, _Char);
}

// Add at the front
XByteArray& XByteArray::prepend(const char* _String) noexcept
{
	return this->insert(0ULL, _String);
}

// Add at the front
XByteArray& XByteArray::prepend(const char* _String, size_type _Length) noexcept
{
	return this->insert(0ULL, _String, _Length);
}

// Add at the front
XByteArray& XByteArray::prepend(const XByteArray& _Bytes) noexcept
{
	return this->insert(0ULL, _Bytes);
}

// Add at the end
XByteArray& XByteArray::append(char _Char) noexcept
{
	return this->insert(this->size(), _Char);
}

// Add at the end
XByteArray& XByteArray::append(size_type _Count, char _Char) noexcept
{
	return this->insert(this->size(), _Count, _Char);
}

// Add at the end
XByteArray& XByteArray::append(const char* _String) noexcept
{
	return this->insert(this->size(), _String);
}

// Add at the end
XByteArray& XByteArray::append(const char* _String, size_type _Length) noexcept
{
	return this->insert(this->size(), _String, _Length);
}

// Add at the end
XByteArray& XByteArray::append(const XByteArray& _Bytes) noexcept
{
	return this->insert(this->size(), _Bytes);
}

// Insert by pos
XByteArray& XByteArray::insert(size_type _Index, char _Char) noexcept
{
	return this->insert(_Index, 1, _Char);
}

// Insert by pos
XByteArray& XByteArray::insert(size_type _Index, size_type _Count, char _Char) noexcept
{
	if(_Count > 0ULL)
	{
		auto		vBuffer = XANADU_NEW char[_Count + 1];
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

// Insert by pos
XByteArray& XByteArray::insert(size_type _Index, const char* _String) noexcept
{
	return this->insert(_Index, _String, Xanadu::strlen(_String));
}

// Insert by pos
XByteArray& XByteArray::insert(size_type _Index, const char* _String, size_type _Length) noexcept
{
	if (_String && _Length > 0ULL)
	{
		_Index = XAllocator::memoryFixSize(_Index);
		this->memoryInsert(_Index, _String, _Length);
	}
	return *this;
}

// Insert by pos
XByteArray& XByteArray::insert(size_type _Index, const XByteArray& _Bytes) noexcept
{
	return this->insert(_Index, _Bytes.data(), _Bytes.size());
}






// Delete the specified length of data from the specified pos
XByteArray& XByteArray::remove(size_type _Index, size_type _Length) noexcept
{
	this->memoryRemove(_Index, _Length);
	return *this;
}

// Delete the specified length of data from the specified pos
XByteArray& XByteArray::remove(const char _Char) noexcept
{
	char 		vBuffer[2] = {_Char, '\0'};
	return this->remove(vBuffer);
}

// Delete the specified length of data from the specified pos
XByteArray& XByteArray::remove(const char* _Memory) noexcept
{
	return this->remove(_Memory, Xanadu::strlen(_Memory));
}

// Delete the specified length of data from the specified pos
XByteArray& XByteArray::remove(const char* _Memory, size_type _Size) noexcept
{
	if(_Size == XByteArray::npos)
	{
		_Size = Xanadu::strlen(_Memory);
	}
	if (_Memory && _Size > 0ULL)
	{
		auto		vFind = this->find(_Memory, 0ULL);
		while (vFind != XByteArray::npos)
		{
			this->remove(vFind, _Size);
			vFind = this->find(_Memory, vFind);
		};
	}
	return *this;
}

// Delete the specified length of data from the specified pos
XByteArray& XByteArray::remove(const XByteArray& _Bytes) noexcept
{
	return this->remove(_Bytes.data(), _Bytes.size());
}






// Replace data
XByteArray& XByteArray::replace(size_type _Index, size_type _Length, const char* _After) noexcept
{
	return this->replace(_Index, _Length, _After, Xanadu::strlen(_After));
}

// Replace data
XByteArray& XByteArray::replace(size_type _Index, size_type _Length, const char* _After, size_type _Asize) noexcept
{
	this->memoryReplace(_Index, _Length, _After, _Asize);
	return *this;
}

// Replace data
XByteArray& XByteArray::replace(size_type _Index, size_type _Length, const XByteArray& _Bytes) noexcept
{
	return this->replace(_Index, _Length, _Bytes.data(), _Bytes.size());
}

// Replace data
XByteArray& XByteArray::replace(char _Before, const char* _After) noexcept
{
	char 		vBuffer[2] = {_Before, '\0'};
	return this->replace(vBuffer, Xanadu::strlen(vBuffer), _After, Xanadu::strlen(_After));
}

// Replace data
XByteArray& XByteArray::replace(char _Before, const XByteArray& _After) noexcept
{
	char 		vBuffer[2] = {_Before, '\0'};
	return this->replace(vBuffer, Xanadu::strlen(vBuffer), _After.data(), _After.size());
}

// Replace data
XByteArray& XByteArray::replace(const char* _Before, const char* _After) noexcept
{
	return this->replace(_Before, Xanadu::strlen(_Before), _After, Xanadu::strlen(_After));
}

// Replace data
XByteArray& XByteArray::replace(const char* _Before, size_type _Bsize, const char* _After, size_type _Asize) noexcept
{
	auto		vIndex = static_cast<size_type>(0U);
	while (_Before && _Bsize > 0ULL && _After && _Asize > 0ULL)
	{
		auto		vPos = this->memoryFind(vIndex, _Before, _Bsize);
		if (XByteArray::npos == vPos)
		{
			break;
		}
		this->memoryReplace(vPos, _Bsize, _After, _Asize);
		vIndex += _Asize;
	};
	return *this;
}

// Replace data
XByteArray& XByteArray::replace(const XByteArray& _Before, const XByteArray& _After) noexcept
{
	return this->replace(_Before.data(), _Before.size(), _After.data(), _After.size());
}

// Replace data
XByteArray& XByteArray::replace(const XByteArray& _Before, const char* _After) noexcept
{
	return this->replace(_Before.data(), _Before.size(), _After, Xanadu::strlen(_After));
}

// Replace data
XByteArray& XByteArray::replace(const char* _Before, const XByteArray& _After) noexcept
{
	return this->replace(_Before, Xanadu::strlen(_Before), _After.data(), _After.size());
}

// Replace data
XByteArray& XByteArray::replace(char _Before, char _After) noexcept
{
	char 		vBuffer1[2] = {_Before, '\0'};
	char 		vBuffer2[2] = {_After, '\0'};
	return this->replace(vBuffer1, Xanadu::strlen(vBuffer1), vBuffer2, Xanadu::strlen(vBuffer2));
}





// Get the data on the left by length
XByteArray XByteArray::left(size_type _Length) const noexcept
{
	if (_Length > 0ULL)
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

// Get the data on the right by length
XByteArray XByteArray::right(size_type _Length) const noexcept
{
	if (_Length > 0ULL)
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

// Retrieve the middle data by length
XByteArray XByteArray::mid(size_type _Index, size_type _Length) const noexcept
{
	auto		vPos = XAllocator::memoryFixSize(_Index);
	if (_Length >= this->size() || _Index + _Length >= this->size())
	{
		return XByteArray(this->data() + _Index, this->size() - _Index);
	}
	return XByteArray(this->data() + vPos, _Length);
}





// Check if the head is the same
bool XByteArray::startsWith(char _Char) const noexcept
{
	return this->startsWith(XByteArray(_Char));
}

// Check if the head is the same
bool XByteArray::startsWith(const char* _Memory) const noexcept
{
	return this->startsWith(XByteArray(_Memory, Xanadu::strlen(_Memory)));
}

// Check if the head is the same
bool XByteArray::startsWith(const XByteArray& _Bytes) const noexcept
{
	if (this->size() >= _Bytes.size() && _Bytes.exist())
	{
		for(XByteArray::size_type vIndex = 0U; vIndex < _Bytes.size(); ++vIndex)
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

// Check if the tails are the same
bool XByteArray::endsWith(char _Char) const noexcept
{
	return this->endsWith(XByteArray(_Char));
}

// Check if the tails are the same
bool XByteArray::endsWith(const char* _Memory) const noexcept
{
	return this->endsWith(XByteArray(_Memory, Xanadu::strlen(_Memory)));
}

// Check if the tails are the same
bool XByteArray::endsWith(const XByteArray& _Bytes) const noexcept
{
	if (this->size() >= _Bytes.size() && _Bytes.exist())
	{
		for(XByteArray::size_type vIndex = 0U; vIndex < _Bytes.size(); ++vIndex)
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






// find in positive order from the specified location
XByteArray::size_type XByteArray::find(char _Char, size_type _From) const noexcept
{
	char		vBuffer[2] = {_Char, '\0'};
	return this->find(XByteArray(vBuffer, 1ULL), _From);
}

// find in positive order from the specified location
XByteArray::size_type XByteArray::find(const char* _Memory, size_type _From) const noexcept
{
	if(_Memory)
	{
		return this->find(XByteArray(_Memory, Xanadu::strlen(_Memory)), _From);
	}
	return XByteArray::npos;
}

// find in positive order from the specified location
XByteArray::size_type XByteArray::find(const XByteArray& _Bytes, size_type _From) const noexcept
{
	XANADU_CHECK_RETURN(_Bytes.size(), XByteArray::npos);

	return XAllocator::memoryFind(_From, _Bytes.data(), _Bytes.size());
}

// find in reverse order from the specified location
XByteArray::size_type XByteArray::rfind(char _Char, size_type _From) const noexcept
{
	char		vBuffer[2] = {_Char, '\0'};
	return this->rfind(XByteArray(vBuffer, 1ULL), _From);
}

// find in reverse order from the specified location
XByteArray::size_type XByteArray::rfind(const char* _Memory, size_type _From) const noexcept
{
	if(_Memory)
	{
		return this->rfind(XByteArray(_Memory, Xanadu::strlen(_Memory)), _From);
	}
	return XByteArray::npos;
}

// find in reverse order from the specified location
XByteArray::size_type XByteArray::rfind(const XByteArray& _Bytes, size_type _From) const noexcept
{
	if(_Bytes.exist())
	{
		return XAllocator::memoryReverseFind(_From, _Bytes.data(), _Bytes.size());
	}
	return XByteArray::npos;
}





// find in positive order from the specified location
XByteArray::size_type XByteArray::indexOf(char _Char, size_type _From) const noexcept
{
	return this->find(_Char, _From);
}

// find in positive order from the specified location
XByteArray::size_type XByteArray::indexOf(const char* _Memory, size_type _From) const noexcept
{
	return this->find(_Memory, _From);
}

// find in positive order from the specified location
XByteArray::size_type XByteArray::indexOf(const XByteArray& _Bytes, size_type _From) const noexcept
{
	return this->find(_Bytes, _From);
}

// find in reverse order from the specified location
XByteArray::size_type XByteArray::lastIndexOf(char _Char, size_type _From) const noexcept
{
	return this->rfind(_Char, _From);
}

// find in reverse order from the specified location
XByteArray::size_type XByteArray::lastIndexOf(const char* _Memory, size_type _From) const noexcept
{
	return this->rfind(_Memory, _From);
}

// find in reverse order from the specified location
XByteArray::size_type XByteArray::lastIndexOf(const XByteArray& _Bytes, size_type _From) const noexcept
{
	return this->rfind(_Bytes, _From);
}






// Check for inclusion
bool XByteArray::contains(char _Char) const noexcept
{
	return this->find(_Char, 0ULL);
}

// Check for inclusion
bool XByteArray::contains(const char* _Memory) const noexcept
{
	return this->find(_Memory, 0ULL);
}

// Check for inclusion
bool XByteArray::contains(const XByteArray& _Bytes) const noexcept
{
	return this->find(_Bytes, 0ULL);
}

// Check if they are the same
int XByteArray::compare(const char* _Memory, Xanadu::CaseSensitivity _XCS) const noexcept
{
	return this->compare(XByteArray(_Memory), _XCS);
}

// Check if they are the same
int XByteArray::compare(const XByteArray& _Bytes, Xanadu::CaseSensitivity _XCS) const noexcept
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






// Check if it's lowercase
bool XByteArray::isLower() const noexcept
{
	for (XByteArray::size_type vIndex = 0U; vIndex < this->size(); ++vIndex)
	{
		if ('A' <= this->operator[](vIndex) && this->operator[](vIndex) <= 'Z')
		{
			return false;
		}
	}
	return true;
}

// Check if it's uppercase
bool XByteArray::isUpper() const noexcept
{
	for (XByteArray::size_type vIndex = 0U; vIndex < this->size(); ++vIndex)
	{
		if ('a' <= this->operator[](vIndex) && this->operator[](vIndex) <= 'z')
		{
			return false;
		}
	}
	return true;
}

// Convert to lowercase
XByteArray XByteArray::toLower() const noexcept
{
	auto		vBytes = XByteArray();
	for (XByteArray::size_type vIndex = 0U; vIndex < this->size(); ++vIndex)
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

// Convert to uppercase
XByteArray XByteArray::toUpper() const noexcept
{
	auto		vBytes = XByteArray();
	for (XByteArray::size_type vIndex = 0U; vIndex < this->size(); ++vIndex)
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

// remove start and end whitespace strings ('\t','\n','\v','\f','\r','_')
XByteArray XByteArray::trimmed() const noexcept
{
	auto		vBeginPos = static_cast<size_type>(0U);
	auto		vEndPos = this->size() - 1U;
	// Positive sequence check
	for (; vBeginPos < this->size(); ++vBeginPos)
	{
		if (XanaduByteArrayIsSpace(this->operator[](vBeginPos)))
		{
			break;
		}
	}
	// Check order
	for (; vEndPos != XByteArray::npos; --vEndPos)
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

// remove beginning, middle, and end whitespace strings ('\t','\n','\v','\f','\r','_')
XByteArray XByteArray::simplified() const noexcept
{
	auto		vBytes = this->trimmed();
	auto		vResult = XByteArray();
	auto		vExistSpace = false;
	for (XByteArray::size_type vIndex = 0U; vIndex < vBytes.size(); ++vIndex)
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





// Format ByteArray (char* [%s]) (wchar_t* [%ls])
XByteArray XANADUAPI XByteArray::format(const char* _Format, ...) noexcept
{
	auto		vBytes = XByteArray();
	auto		vBuffer = XANADU_NEW char[XANADU_SIZE_KB * 10];
	if(vBuffer)
	{
		Xanadu::memset(vBuffer, 0, sizeof(char) * XANADU_SIZE_KB * 10);
		va_list		vArgs;
		va_start(vArgs, _Format);
		vsnprintf(vBuffer, XANADU_SIZE_KB * 10 - 1, _Format, vArgs);
		va_end(vArgs);

		vBytes = vBuffer;
		XANADU_DELETE_ARR(vBuffer);
	}
	return vBytes;
}








// split
std::list<XByteArray> XByteArray::split(char _Char) const noexcept
{
	char		vBuffer[2] = {_Char, '\0'};
	return this->split(vBuffer, 1ULL);
}

// split
std::list<XByteArray> XByteArray::split(const char* _Memory) const noexcept
{
	return this->split(XByteArray(_Memory, Xanadu::strlen(_Memory)));
}

// split
std::list<XByteArray> XByteArray::split(const char* _Memory, size_type _Size) const noexcept
{
	return this->split(XByteArray(_Memory, _Size));
}

// split
std::list<XByteArray> XByteArray::split(const XByteArray& _Bytes) const noexcept
{
	auto		vHeaderArray = std::list<XByteArray>();
	auto		vLast = static_cast<size_type>(0U);
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









// Convert to Base64
XByteArray XByteArray::toBase64() const noexcept
{
	return XBase64::encode(this->data(), this->size());
}

// Convert to HEX
XByteArray XByteArray::toHex() const noexcept
{
	auto		vTarget = XByteArray(this->size() * 2);
	char		vBufferHex[3] = {0};
	for (XByteArray::size_type vIndex = 0U; vIndex < this->size(); ++vIndex)
	{
		sprintf(vBufferHex, "%02X", (int8U)this->at(vIndex));
		vTarget[vIndex * 2 + 0] = vBufferHex[0];
		vTarget[vIndex * 2 + 1] = vBufferHex[1];
	}
	return vTarget;
}

// Format from memory
XByteArray XANADUAPI XByteArray::fromMemory(const char* _Memory, size_type _Size) noexcept
{
	return XByteArray(_Memory, _Size);
}

// Format from Base64
XByteArray XANADUAPI XByteArray::fromBase64(const void* _Memory, size_type _Size) noexcept
{
	return XBase64::decode(_Memory, _Size);
}

// Format from Base64
XByteArray XANADUAPI XByteArray::fromBase64(const XByteArray& _Bytes) noexcept
{
	return XByteArray::fromBase64(_Bytes.data(), _Bytes.size());
}

// Format from HEX
XByteArray XANADUAPI XByteArray::fromHex(const void* _Memory, size_type _Size) noexcept
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
	if(_Size > 0ULL)
	{
		for (XByteArray::size_type vIndex = 0U; vIndex < vLength; ++vIndex)
		{
			auto		vHexLeft = XanaduByteArrayHexToInt8U(vBuffer[vIndex * 2 + 0]);
			auto		vHexRight = XanaduByteArrayHexToInt8U(vBuffer[vIndex * 2 + 1]);

			vTarget[vIndex] = vHexLeft * 16 + vHexRight;
		}
	}
	return vTarget;
}

// Format from HEX
XByteArray XANADUAPI XByteArray::fromHex(const XByteArray& _Bytes) noexcept
{
	return XByteArray::fromHex(_Bytes.data(), _Bytes.size());
}

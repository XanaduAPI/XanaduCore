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



// 构造
XByteArray::XByteArray() noexcept : XAllocator()
{
}

// 构造
XByteArray::XByteArray(const char* _Memory, size_type _Size) noexcept : XAllocator()
{
	XAllocator::memoryAppend(_Memory, _Size == XByteArray::npos ? Xanadu::strlen(_Memory) : _Size);
}

// 构造
XByteArray::XByteArray(size_type _Size, char _Char) noexcept : XAllocator(_Size, _Char)
{
}

// 构造
XByteArray::XByteArray(size_type _Size) noexcept : XAllocator(_Size)
{
}

// 构造
XByteArray::XByteArray(const XByteArray& _Bytes) noexcept : XAllocator(_Bytes.data(), _Bytes.size())
{
}

// 虚析构
XByteArray::~XByteArray() noexcept
{
}


// 操作符重载 =
XByteArray& XByteArray::operator = (const char* _Memory) noexcept
{
	this->memoryCopy(_Memory, Xanadu::strlen(_Memory));
	return *this;
}

// 操作符重载 =
XByteArray& XByteArray::operator = (const XByteArray& _Bytes) noexcept
{
	this->memoryCopy(_Bytes);
	return *this;
}

// 操作符重载 =
XByteArray& XByteArray::operator = (XByteArray&& _Other) noexcept
{
	this->memoryMove(_Other);
	return *this;
}



// 操作符重载 +
XByteArray XByteArray::operator + (char _Char) const noexcept
{
	auto		vTempBytes = *this;
	vTempBytes.memoryAppend(1, _Char);
	return vTempBytes;
}

// 操作符重载 +
XByteArray XByteArray::operator + (const char* _Memory) const noexcept
{
	auto		vTempBytes = *this;
	vTempBytes.memoryAppend(_Memory, Xanadu::strlen(_Memory));
	return vTempBytes;
}

// 操作符重载 +
XByteArray XByteArray::operator + (const XByteArray& _Bytes) const noexcept
{
	auto		vTempBytes = *this;
	vTempBytes.memoryAppend(_Bytes);
	return vTempBytes;
}



// 操作符重载 +=
XByteArray& XByteArray::operator += (char _Char) noexcept
{
	this->memoryAppend(1, _Char);
	return *this;
}

// 操作符重载 +=
XByteArray& XByteArray::operator += (const char* _Memory) noexcept
{
	this->memoryAppend(_Memory, Xanadu::strlen(_Memory));
	return *this;
}

// 操作符重载 +=
XByteArray& XByteArray::operator += (const XByteArray& _Bytes) noexcept
{
	this->memoryAppend(_Bytes);
	return *this;
}




// 操作符重载 ==
bool XByteArray::operator == (const char* _Memory) const noexcept
{
	return this->compare(_Memory) == 0;
}

// 操作符重载 ==
bool XByteArray::operator == (const XByteArray& _Bytes) const noexcept
{
	return this->compare(_Bytes) == 0;
}

// 操作符重载 !=
bool XByteArray::operator != (const char* _Memory) const noexcept
{
	return this->compare(_Memory) != 0;
}

// 操作符重载 !=
bool XByteArray::operator != (const XByteArray& _Bytes) const noexcept
{
	return this->compare(_Bytes) != 0;
}

// 操作符重载 <
bool XByteArray::operator < (const char* _Memory) const noexcept
{
	return this->compare(_Memory) < 0;
}

// 操作符重载 <
bool XByteArray::operator < (const XByteArray& _Bytes) const noexcept
{
	return this->compare(_Bytes) < 0;
}

// 操作符重载 >
bool XByteArray::operator > (const char* _Memory) const noexcept
{
	return this->compare(_Memory) > 0;
}

// 操作符重载 >
bool XByteArray::operator > (const XByteArray& _Bytes) const noexcept
{
	return this->compare(_Bytes) > 0;
}

// 操作符重载 <=
bool XByteArray::operator <= (const char* _Memory) const noexcept
{
	return this->compare(_Memory) <= 0;
}

// 操作符重载 <=
bool XByteArray::operator <= (const XByteArray& _Bytes) const noexcept
{
	return this->compare(_Bytes) <= 0;
}

// 操作符重载 >=
bool XByteArray::operator >= (const char* _Memory) const noexcept
{
	return this->compare(_Memory) >= 0;
}

// 操作符重载 >=
bool XByteArray::operator >= (const XByteArray& _Bytes) const noexcept
{
	return this->compare(_Bytes) >= 0;
}



// 获取数据指针
char* XByteArray::data() noexcept
{
	return static_cast<char*>(XAllocator::memoryAddress());
}

// 获取常量数据指针
const char* XByteArray::data() const noexcept
{
	return static_cast<const char*>(XAllocator::memoryAddress());
}

// 获取数据长度
XByteArray::size_type XByteArray::size() const noexcept
{
	return XAllocator::memoryLength();
}

// 获取数据长度
XByteArray::size_type XByteArray::length() const noexcept
{
	return this->size();
}

// 调整大小
void XByteArray::resize(size_type _Size) noexcept
{
	this->memoryResize(_Size);
}

// 从 _Index 截断字节数组的下标位置。如果 _Index 超出了数组的末尾，则什么也不会发生。
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

// 获取当前容量
XByteArray::size_type XByteArray::capacity() const noexcept
{
	return this->memoryCapacity();
}

// 检查是否为空，当长度为0时返回true
bool XByteArray::empty() const noexcept
{
	return this->memoryIsEmpty();
}

// 检查是否有值，当长度不为0时返回true
bool XByteArray::exist() const noexcept
{
	return this->memoryIsExist();
}





// 按下标读取数据
char XByteArray::at(size_type _Index) const noexcept
{
	if (_Index < this->size())
	{
		return this->data()[_Index];
	}
	return '\0';
}

// 得到第一位的数据
char& XByteArray::front() noexcept
{
	return operator[](0);
}

// 得到第一位的数据
char XByteArray::front() const noexcept
{
	return this->at(0);
}

// 得到最后一位的数据
char& XByteArray::back() noexcept
{
	return operator[](this->size() - 1);
}

// 得到最后一位的数据
char XByteArray::back() const noexcept
{
	return this->at(this->size() - 1);
}

// 按下标读取数据
char& XByteArray::operator [] (size_type _Index) noexcept
{
	if (_Index < this->size())
	{
		return this->data()[_Index];
	}
	return _StaticIndexBeyond;
}

// 按下标读取数据
char XByteArray::operator [] (size_type _Index) const noexcept
{
	return this->at(_Index);
}





// 迭代器操作
XByteArray::iterator XByteArray::begin() noexcept
{
	return this->data();
}

// 迭代器操作
XByteArray::const_iterator XByteArray::begin() const noexcept
{
	return this->data();
}

// 迭代器操作
XByteArray::const_iterator XByteArray::cbegin() const noexcept
{
	return this->data();
}

// 迭代器操作
XByteArray::const_iterator XByteArray::constBegin() const noexcept
{
	return this->data();
}

// 迭代器操作
XByteArray::iterator XByteArray::end() noexcept
{
	return this->data() + this->size();
}

// 迭代器操作
XByteArray::const_iterator XByteArray::end() const noexcept
{
	return this->data() + this->size();
}

// 迭代器操作
XByteArray::const_iterator XByteArray::cend() const noexcept
{
	return this->data() + this->size();
}

// 迭代器操作
XByteArray::const_iterator XByteArray::constEnd() const noexcept
{
	return this->data() + this->size();
}

// 迭代器操作
XByteArray::reverse_iterator XByteArray::rbegin() noexcept
{
	return reverse_iterator(this->end());
}

// 迭代器操作
XByteArray::reverse_iterator XByteArray::rend() noexcept
{
	return reverse_iterator(this->begin());
}

// 迭代器操作
XByteArray::const_reverse_iterator XByteArray::rbegin() const noexcept
{
	return const_reverse_iterator(this->end());
}

// 迭代器操作
XByteArray::const_reverse_iterator XByteArray::rend() const noexcept
{
	return const_reverse_iterator(this->begin());
}

// 迭代器操作
XByteArray::const_reverse_iterator XByteArray::crbegin() const noexcept
{
	return const_reverse_iterator(this->end());
}

// 迭代器操作
XByteArray::const_reverse_iterator XByteArray::crend() const noexcept
{
	return const_reverse_iterator(this->begin());
}





// Vector兼容:从结尾添加数据
void XByteArray::push_back(char _Char) noexcept
{
	this->append(_Char);
}

// Vector兼容:从结尾添加数据
void XByteArray::push_back(const char* _Memory) noexcept
{
	this->append(_Memory);
}

// Vector兼容:从结尾添加数据
void XByteArray::push_back(const XByteArray& _Bytes) noexcept
{
	this->append(_Bytes);
}

// Vector兼容:从开头添加数据
void XByteArray::push_front(char _Char) noexcept
{
	this->prepend(_Char);
}

// Vector兼容:从开头添加数据
void XByteArray::push_front(const char* _Memory) noexcept
{
	this->prepend(_Memory);
}

// Vector兼容:从开头添加数据
void XByteArray::push_front(const XByteArray& _Bytes) noexcept
{
	this->prepend(_Bytes);
}





// 从开头添加数据
XByteArray& XByteArray::prepend(char _Char) noexcept
{
	return this->insert(0ULL, _Char);
}

// 从开头添加数据
XByteArray& XByteArray::prepend(size_type _Count, char _Char) noexcept
{
	return this->insert(0ULL, _Count, _Char);
}

// 从开头添加数据
XByteArray& XByteArray::prepend(const char* _String) noexcept
{
	return this->insert(0ULL, _String);
}

// 从开头添加数据
XByteArray& XByteArray::prepend(const char* _String, size_type _Length) noexcept
{
	return this->insert(0ULL, _String, _Length);
}

// 从开头添加数据
XByteArray& XByteArray::prepend(const XByteArray& _Bytes) noexcept
{
	return this->insert(0ULL, _Bytes);
}

// 从结尾添加数据
XByteArray& XByteArray::append(char _Char) noexcept
{
	return this->insert(this->size(), _Char);
}

// 从结尾添加数据
XByteArray& XByteArray::append(size_type _Count, char _Char) noexcept
{
	return this->insert(this->size(), _Count, _Char);
}

// 从结尾添加数据
XByteArray& XByteArray::append(const char* _String) noexcept
{
	return this->insert(this->size(), _String);
}

// 从结尾添加数据
XByteArray& XByteArray::append(const char* _String, size_type _Length) noexcept
{
	return this->insert(this->size(), _String, _Length);
}

// 从结尾添加数据
XByteArray& XByteArray::append(const XByteArray& _Bytes) noexcept
{
	return this->insert(this->size(), _Bytes);
}

// 从指定的位置插入数据
XByteArray& XByteArray::insert(size_type _Index, char _Char) noexcept
{
	return this->insert(_Index, 1, _Char);
}

// 从指定的位置插入数据
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

// 从指定的位置插入数据
XByteArray& XByteArray::insert(size_type _Index, const char* _String) noexcept
{
	return this->insert(_Index, _String, Xanadu::strlen(_String));
}

// 从指定的位置插入数据
XByteArray& XByteArray::insert(size_type _Index, const char* _String, size_type _Length) noexcept
{
	if (_String && _Length > 0ULL)
	{
		_Index = XAllocator::memoryFixSize(_Index);
		this->memoryInsert(_Index, _String, _Length);
	}
	return *this;
}

// 从指定的位置插入数据
XByteArray& XByteArray::insert(size_type _Index, const XByteArray& _Bytes) noexcept
{
	return this->insert(_Index, _Bytes.data(), _Bytes.size());
}






// 从指定的位置删除指定长度的数据
XByteArray& XByteArray::remove(size_type _Index, size_type _Length) noexcept
{
	this->memoryRemove(_Index, _Length);
	return *this;
}

// 删除与参数相同的数据
XByteArray& XByteArray::remove(const char _Char) noexcept
{
	char 		vBuffer[2] = {_Char, '\0'};
	return this->remove(vBuffer);
}

// 删除与参数相同的数据
XByteArray& XByteArray::remove(const char* _Memory) noexcept
{
	return this->remove(_Memory, Xanadu::strlen(_Memory));
}

// 删除与参数相同的数据
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

// 删除与参数相同的数据
XByteArray& XByteArray::remove(const XByteArray& _Bytes) noexcept
{
	return this->remove(_Bytes.data(), _Bytes.size());
}






// 替换指定的数据
XByteArray& XByteArray::replace(size_type _Index, size_type _Length, const char* _After) noexcept
{
	return this->replace(_Index, _Length, _After, Xanadu::strlen(_After));
}

// 替换指定的数据
XByteArray& XByteArray::replace(size_type _Index, size_type _Length, const char* _After, size_type _Asize) noexcept
{
	this->memoryReplace(_Index, _Length, _After, _Asize);
	return *this;
}

// 替换指定的数据
XByteArray& XByteArray::replace(size_type _Index, size_type _Length, const XByteArray& _Bytes) noexcept
{
	return this->replace(_Index, _Length, _Bytes.data(), _Bytes.size());
}

// 替换指定的数据
XByteArray& XByteArray::replace(char _Before, const char* _After) noexcept
{
	char 		vBuffer[2] = {_Before, '\0'};
	return this->replace(vBuffer, Xanadu::strlen(vBuffer), _After, Xanadu::strlen(_After));
}

// 替换指定的数据
XByteArray& XByteArray::replace(char _Before, const XByteArray& _After) noexcept
{
	char 		vBuffer[2] = {_Before, '\0'};
	return this->replace(vBuffer, Xanadu::strlen(vBuffer), _After.data(), _After.size());
}

// 替换指定的数据
XByteArray& XByteArray::replace(const char* _Before, const char* _After) noexcept
{
	return this->replace(_Before, Xanadu::strlen(_Before), _After, Xanadu::strlen(_After));
}

// 替换指定的数据
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

// 替换指定的数据
XByteArray& XByteArray::replace(const XByteArray& _Before, const XByteArray& _After) noexcept
{
	return this->replace(_Before.data(), _Before.size(), _After.data(), _After.size());
}

// 替换指定的数据
XByteArray& XByteArray::replace(const XByteArray& _Before, const char* _After) noexcept
{
	return this->replace(_Before.data(), _Before.size(), _After, Xanadu::strlen(_After));
}

// 替换指定的数据
XByteArray& XByteArray::replace(const char* _Before, const XByteArray& _After) noexcept
{
	return this->replace(_Before, Xanadu::strlen(_Before), _After.data(), _After.size());
}

// 替换指定的数据
XByteArray& XByteArray::replace(char _Before, char _After) noexcept
{
	char 		vBuffer1[2] = {_Before, '\0'};
	char 		vBuffer2[2] = {_After, '\0'};
	return this->replace(vBuffer1, Xanadu::strlen(vBuffer1), vBuffer2, Xanadu::strlen(vBuffer2));
}





// 按长度获取左边的数据
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

// 按长度获取右边的数据
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

// 按长度获取中间的数据
XByteArray XByteArray::mid(size_type _Index, size_type _Length) const noexcept
{
	auto		vPos = XAllocator::memoryFixSize(_Index);
	if(vPos < this->size())
	{
		if(_Length == XByteArray::npos || vPos + _Length >= this->size())
		{
			return XByteArray(this->data() + vPos, this->size() - vPos);
		}
		else
		{
			return XByteArray(this->data() + vPos, _Length);
		}
	}
	return XByteArray(this->data() + vPos, _Length);
}



// 倒序
XByteArray& XByteArray::reverse() noexcept
{
	if(this->size() <= 1)
	{
		return *this;
	}
	auto		vSize = this->size() / 2;
	auto		vTemp = static_cast<char>(0);
	for(auto vIndex = 0U; vIndex <= vSize; ++vIndex)
	{
		vTemp = this->data()[vIndex];
		this->data()[vIndex] = this->data()[this->size() - 1 - vIndex];
		this->data()[this->size() - 1 - vIndex] = vTemp;
	}
	return *this;
}

// 倒序
XByteArray XByteArray::reverse() const noexcept
{
	if(this->size() <= 1)
	{
		return *this;
	}
	auto		vBytes = XByteArray(this->size());
	for(auto vIndex = 0U; vIndex != this->size(); ++vIndex)
	{
		vBytes[this->size() - 1 - vIndex] = this->data()[vIndex];
	}
	return vBytes;
}



// 检查头部是否相同
bool XByteArray::startsWith(char _Char) const noexcept
{
	return this->startsWith(XByteArray(_Char));
}

// 检查头部是否相同
bool XByteArray::startsWith(const char* _Memory) const noexcept
{
	return this->startsWith(XByteArray(_Memory, Xanadu::strlen(_Memory)));
}

// 检查头部是否相同
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

// 检查尾部是否相同
bool XByteArray::endsWith(char _Char) const noexcept
{
	return this->endsWith(XByteArray(_Char));
}

// 检查尾部是否相同
bool XByteArray::endsWith(const char* _Memory) const noexcept
{
	return this->endsWith(XByteArray(_Memory, Xanadu::strlen(_Memory)));
}

// 检查尾部是否相同
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






// 从指定位置按正序查找
XByteArray::size_type XByteArray::find(char _Char, size_type _From) const noexcept
{
	char		vBuffer[2] = {_Char, '\0'};
	return this->find(XByteArray(vBuffer, 1ULL), _From);
}

// 从指定位置按正序查找
XByteArray::size_type XByteArray::find(const char* _Memory, size_type _From) const noexcept
{
	if(_Memory)
	{
		return this->find(XByteArray(_Memory, Xanadu::strlen(_Memory)), _From);
	}
	return XByteArray::npos;
}

// 从指定位置按正序查找
XByteArray::size_type XByteArray::find(const XByteArray& _Bytes, size_type _From) const noexcept
{
	XANADU_CHECK_RETURN(_Bytes.size(), XByteArray::npos);

	return XAllocator::memoryFind(_From, _Bytes.data(), _Bytes.size());
}

// 从指定位置按倒序查找
XByteArray::size_type XByteArray::rfind(char _Char, size_type _From) const noexcept
{
	char		vBuffer[2] = {_Char, '\0'};
	return this->rfind(XByteArray(vBuffer, 1ULL), _From);
}

// 从指定位置按倒序查找
XByteArray::size_type XByteArray::rfind(const char* _Memory, size_type _From) const noexcept
{
	if(_Memory)
	{
		return this->rfind(XByteArray(_Memory, Xanadu::strlen(_Memory)), _From);
	}
	return XByteArray::npos;
}

// 从指定位置按倒序查找
XByteArray::size_type XByteArray::rfind(const XByteArray& _Bytes, size_type _From) const noexcept
{
	if(_Bytes.exist())
	{
		return XAllocator::memoryReverseFind(_From, _Bytes.data(), _Bytes.size());
	}
	return XByteArray::npos;
}





// 检查是否包含指定的内容
bool XByteArray::contains(char _Char) const noexcept
{
	return this->find(_Char, 0ULL);
}

// 检查是否包含指定的内容
bool XByteArray::contains(const char* _Memory) const noexcept
{
	return this->find(_Memory, 0ULL);
}

// 检查是否包含指定的内容
bool XByteArray::contains(const XByteArray& _Bytes) const noexcept
{
	return this->find(_Bytes, 0ULL);
}

// 检查它们是否相同 (默认大小写敏感)
int XByteArray::compare(const char* _Memory, Xanadu::CaseSensitivity _XCS) const noexcept
{
	return this->compare(XByteArray(_Memory), _XCS);
}

// 检查它们是否相同 (默认大小写敏感)
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





// 检查是否全部是小写字符
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

// 检查是否全部是大写字符
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

// 转换至小写
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

// 转换至大写
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

// 删除开始和结束空白字符
XByteArray XByteArray::trimmed() const noexcept
{
	auto		vBeginPos = static_cast<size_type>(0U);
	auto		vEndPos = this->size() - 1U;
	// Positive sequence check
	for (; vBeginPos < this->size(); ++vBeginPos)
	{
		if (XByteArray::isSpace(this->operator[](vBeginPos)))
		{
			break;
		}
	}
	// Check order
	for (; vEndPos != XByteArray::npos; --vEndPos)
	{
		if (XByteArray::isSpace(this->operator[](vBeginPos)))
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

// 删除开头、中间和结尾空白字符
XByteArray XByteArray::simplified() const noexcept
{
	auto		vBytes = this->trimmed();
	auto		vResult = XByteArray();
	auto		vExistSpace = false;
	for (XByteArray::size_type vIndex = 0U; vIndex < vBytes.size(); ++vIndex)
	{
		if (XByteArray::isSpace(vBytes.operator[](vIndex)))
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



// 判断字符是否是 ('\t','\n','\v','\f','\r','_') 中的一个
bool XByteArray::isSpace(char _Char) noexcept
{
	if(_Char == ' ' || _Char == '\t' || _Char == '\n' || _Char == '\v' || _Char == '\f' || _Char == '\r')
	{
		return true;
	}
	return false;
}

// 格式化 ByteArray (char* [%s]) (wchar_t* [%ls])
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





// 按指定数据分割数组
std::list<XByteArray> XByteArray::split(char _Char) const noexcept
{
	char		vBuffer[2] = {_Char, '\0'};
	return this->split(vBuffer, 1ULL);
}

// 按指定数据分割数组
std::list<XByteArray> XByteArray::split(const char* _Memory) const noexcept
{
	return this->split(XByteArray(_Memory, Xanadu::strlen(_Memory)));
}

// 按指定数据分割数组
std::list<XByteArray> XByteArray::split(const char* _Memory, size_type _Size) const noexcept
{
	return this->split(XByteArray(_Memory, _Size));
}

// 按指定数据分割数组
std::list<XByteArray> XByteArray::split(const XByteArray& _Bytes) const noexcept
{
	auto		vHeaderArray = std::list<XByteArray>();
	auto		vLast = static_cast<size_type>(0U);
	auto		vSplitIndex = this->find(_Bytes, vLast);
	while(vSplitIndex != XByteArray::npos && _Bytes.exist())
	{
		vHeaderArray.push_back(this->mid(vLast, vSplitIndex - vLast));
		vLast = vSplitIndex + 2;
		vSplitIndex = this->find(_Bytes, vLast);
	}
	vHeaderArray.push_back(this->mid(vLast));

	return vHeaderArray;
}





// 转换至 Base64
XByteArray XByteArray::toBase64() const noexcept
{
	return XBase64::encode(this->data(), this->size());
}

// 转换至 HEX ，默认大写
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

// 从内存构建对象
XByteArray XANADUAPI XByteArray::fromMemory(const char* _Memory, size_type _Size) noexcept
{
	return XByteArray(_Memory, _Size);
}

// 从 Base64 构建对象
XByteArray XANADUAPI XByteArray::fromBase64(const void* _Memory, size_type _Size) noexcept
{
	return XBase64::decode(_Memory, _Size);
}

// 从 Base64 构建对象
XByteArray XANADUAPI XByteArray::fromBase64(const XByteArray& _Bytes) noexcept
{
	return XByteArray::fromBase64(_Bytes.data(), _Bytes.size());
}

// 从 HEX 构建对象
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

			vTarget[vIndex] = static_cast<char>(vHexLeft * 16 + vHexRight);
		}
	}
	return vTarget;
}

// 从 HEX 构建对象
XByteArray XANADUAPI XByteArray::fromHex(const XByteArray& _Bytes) noexcept
{
	return XByteArray::fromHex(_Bytes.data(), _Bytes.size());
}

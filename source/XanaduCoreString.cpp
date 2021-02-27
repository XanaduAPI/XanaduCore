#include <XanaduCore/XanaduCoreString.h>

#define				XANADU_STRING_FORMAT_LENGTH			102400
#define				XANADU_STRING_REDUNDANCY			128



/// const_iterator
XString::const_iterator::const_iterator() {}

XString::const_iterator::const_iterator(String_iterator_type p) : current(p) {}

const wchar_t& XString::const_iterator::operator[](int _Index) const
{
	return _randomAccess(_Index);
}

const wchar_t& XString::const_iterator::operator* () const
{
	return retrieve();
}

XString::const_iterator& XString::const_iterator::operator++ ()
{
	_increment();
	return *this;
}

XString::const_iterator XString::const_iterator::operator++ (int)
{
	const_iterator old = *this;
	_increment();
	return old;
}

XString::const_iterator& XString::const_iterator::operator-- ()
{
	_decrement();
	return *this;
}

XString::const_iterator XString::const_iterator::operator-- (int)
{
	const_iterator old = *this;
	_decrement();
	return old;
}

bool XString::const_iterator::operator == (const XString::const_iterator& _String2) const
{
	return current.first == _String2.current.first && current.pos == _String2.current.pos;
}

bool XString::const_iterator::operator != (const XString::const_iterator& _String2) const
{
	return !(*this == _String2);
}

XString::const_iterator XString::const_iterator::operator+ (size_type i)
{
	const_iterator vReturn;
	_add(vReturn, i);
	return vReturn;
}

XString::const_iterator XString::const_iterator::operator- (size_type i)
{
	const_iterator vReturn;
	_subtract(vReturn, i);
	return vReturn;
}


/// protected const_iterator function 
wchar_t& XString::const_iterator::retrieve() const
{
	return *(current.first + current.pos);
}

void XString::const_iterator::_increment()
{
	if(current.pos > *current.size)
	{
		throw;
	}
	++current.pos;
}

void XString::const_iterator::_decrement()
{
	if(current.pos == 0)
	{
		throw;
	}
	--current.pos;
}

wchar_t& XString::const_iterator::_randomAccess(size_type i) const
{
	if(i < 0 || i >= *current.size)
	{
		throw;
	}
	return *(current.first + i);
}

void XString::const_iterator::_add(const_iterator& vReturn, size_type i)
{
	if(current.pos + i > *current.size)
	{ ///  beyond end
		throw;
	}
	vReturn = *this;
	vReturn.current.pos += i;
}

void XString::const_iterator::_subtract(const_iterator& vReturn, size_type i)
{
	if(current.pos < i)
	{ ///  if _Pos will be less than zero
		throw;
	}
	vReturn = *this;
	vReturn.current.pos -= i;
}


/// iterator
XString::iterator::iterator() : _myBase() {}

XString::iterator::iterator(String_iterator_type p) : _myBase(p) {}

wchar_t& XString::iterator::operator[](int i)
{
	return _myBase::_randomAccess(i);
}

const wchar_t& XString::iterator::operator[](int i) const
{
	return _myBase::operator[](i);
}

wchar_t& XString::iterator::operator* ()
{
	return _myBase::retrieve();
}

const wchar_t& XString::iterator::operator* () const
{
	return _myBase::operator*();
}

XString::iterator& XString::iterator::operator++ ()
{
	_myBase::_increment();
	return *this;
}

XString::iterator XString::iterator::operator++ (int)
{
	iterator old = *this;
	_myBase::_increment();
	return old;
}

XString::iterator& XString::iterator::operator-- ()
{
	_myBase::_decrement();
	return *this;
}

XString::iterator XString::iterator::operator-- (int)
{
	iterator old = *this;
	_myBase::_decrement();
	return old;
}

XString::iterator XString::iterator::operator+ (size_type i)
{
	iterator vReturn;
	_add(vReturn, i);
	return vReturn;
}

XString::iterator XString::iterator::operator- (size_type i)
{
	iterator vReturn;
	_subtract(vReturn, i);
	return vReturn;
}


/// const_reverse_iterator Private
XString::const_reverse_iterator::const_reverse_iterator() : _myBase() {}

XString::const_reverse_iterator::const_reverse_iterator(String_iterator_type p) : _myBase(p) {}

const wchar_t& XString::const_reverse_iterator::operator[](int i) const
{
	return _myBase::operator[](i);
}

const wchar_t& XString::const_reverse_iterator::operator* () const
{
	return _myBase::operator*();
}

XString::const_reverse_iterator& XString::const_reverse_iterator::operator++ ()
{
	_increment();
	return *this;
}

XString::const_reverse_iterator XString::const_reverse_iterator::operator++ (int)
{
	const_reverse_iterator old = *this;
	_increment();
	return old;
}

XString::const_reverse_iterator& XString::const_reverse_iterator::operator-- ()
{
	_decrement();
	return *this;
}

XString::const_reverse_iterator XString::const_reverse_iterator::operator-- (int)
{
	const_reverse_iterator old = *this;
	_decrement();
	return old;
}

XString::const_reverse_iterator XString::const_reverse_iterator::operator+ (size_type i)
{
	const_reverse_iterator vReturn;
	_add(vReturn, i);
	return vReturn;
}

XString::const_reverse_iterator XString::const_reverse_iterator::operator- (size_type i)
{
	const_reverse_iterator vReturn;
	_subtract(vReturn, i);
	return vReturn;
}


/// protected functions
void XString::const_reverse_iterator::_increment()
{
	if(_myBase::current.pos == 0)
	{
		_myBase::current.pos = *_myBase::current.size;
		return;
	}
	else if(current.pos == *current.size)
	{
		throw;
	}
	_myBase::_decrement();
}

void XString::const_reverse_iterator::_decrement()
{
	if(current.pos == *_myBase::current.size)
	{
		_myBase::current.pos = 0;
		return;
	}
	if(current.pos + 1 == *_myBase::current.size)
	{
		throw;
	}
	_myBase::_increment();
}

void XString::const_reverse_iterator::_add(const_reverse_iterator& vReturn, size_type i)
{
	if(current.pos == *_myBase::current.size && !i)
	{
		throw;
	}
	if(current.pos == i - 1)
	{
		_myBase::current.pos = *_myBase::current.size;
		return;
	}
	else if(current.pos < i - 1)
	{
		throw;
	}

	vReturn = *this;
	vReturn.current.pos -= i;
}

void XString::const_reverse_iterator::_subtract(const_reverse_iterator& vReturn, size_type i)
{
	if(*_myBase::current.size <= _myBase::current.pos + i) ///  moved past reverse first element 
		throw;

	vReturn = *this;
	vReturn.current.pos += i;
}


/// Reverse iterator
XString::reverse_iterator::reverse_iterator() : _myBase() {}

XString::reverse_iterator::reverse_iterator(String_iterator_type p) : _myBase(p) {}

wchar_t& XString::reverse_iterator::operator[](int i)
{
	return _myBase::_randomAccess(i);
}

const wchar_t& XString::reverse_iterator::operator[](int i) const
{
	return _myBase::operator[](i);
}

wchar_t& XString::reverse_iterator::operator* ()
{
	return _myBase::retrieve();
}

const wchar_t& XString::reverse_iterator::operator* () const
{
	return _myBase::operator*();
}

XString::reverse_iterator& XString::reverse_iterator::operator++ ()
{
	_myBase::_increment();
	return *this;
}

XString::reverse_iterator XString::reverse_iterator::operator++ (int)
{
	reverse_iterator old = *this;
	_myBase::_increment();
	return old;
}

XString::reverse_iterator& XString::reverse_iterator::operator-- ()
{
	_myBase::_decrement();
	return *this;
}

XString::reverse_iterator XString::reverse_iterator::operator-- (int)
{
	reverse_iterator old = *this;
	_myBase::_decrement();
	return old;
}

XString::reverse_iterator XString::reverse_iterator::operator+ (size_type i)
{
	reverse_iterator vReturn;
	_myBase::_add(vReturn, i);
	return vReturn;
}

XString::reverse_iterator XString::reverse_iterator::operator- (size_type i)
{
	reverse_iterator vReturn;
	_myBase::_subtract(vReturn, i);
	return vReturn;
}








XString::XString() XANADU_NOTHROW
{
	this->_memory_malloc(0);
}

XString::XString(wchar_t _Char) XANADU_NOTHROW
{
	this->_memory_malloc(0);
	this->_string_append(_Char);
}

XString::XString(const wchar_t* _String) XANADU_NOTHROW
{
	this->_memory_malloc(0);

	auto	vLength = Xanadu::wcslen(_String);
	if(_String && vLength > 0)
	{
		this->_string_append(_String, vLength);
	}
}

XString::XString(const wchar_t* _String, size_type _Length) XANADU_NOTHROW
{
	this->_memory_malloc(0);

	if(_Length == XString::npos)
	{
		_Length = Xanadu::wcslen(_String);
	}
	if(_String && _Length > 0)
	{
		this->_string_append(_String, _Length);
	}
}

XString::XString(const XString& _String) XANADU_NOTHROW
{
	this->_memory_malloc(0);

	if(_String._string_length > 0)
	{
		this->_string_append(_String._string_data, _String._string_length);
	}
}

XString::XString(XString&& _String) XANADU_NOTHROW
{
	*this = std::move(_String);
}

XString::XString(const WString& _String) XANADU_NOTHROW
{
	this->_memory_malloc(0);

	if(_String.size() > 0)
	{
		this->_string_append(_String.data(), _String.size());
	}
}

XString::~XString() XANADU_NOTHROW
{
	this->_memory_free();
}



/// copy assignment
XString& XString::operator = (wchar_t _Char) XANADU_NOTHROW
{
	this->_memory_free();
	this->_string_append(_Char);
	return *this;
}

/// copy assignment
XString& XString::operator = (const wchar_t* _String) XANADU_NOTHROW
{
	this->_memory_free();
	this->_string_append(_String, Xanadu::wcslen(_String));
	return *this;
}

/// copy assignment
XString& XString::operator = (const WString& _String) XANADU_NOTHROW
{
	this->_memory_free();
	this->_string_append(_String.data(), _String.size());
	return *this;
}

/// copy assignment
XString& XString::operator = (const XString& _String) XANADU_NOTHROW
{
	if(this != &_String)
	{
		this->_memory_free();
		this->_string_append(_String._string_data, _String._string_length);
	}
	return *this;
}

/// move assignment
XString& XString::operator = (XString&& _String) XANADU_NOTHROW
{
	if(this != &_String)
	{
		this->_memory_free();
		this->_string_data = _String._string_data;
		this->_string_length = _String._string_length;
		this->_string_capacity = _String._string_capacity;
		_String._string_data = nullptr;
		_String._string_length = 0;
		_String._string_capacity = 0;
		_String._memory_malloc(0);
	}
	return *this;
}



/// memory operator new
void XString::_memory_malloc(size_type _Size) XANADU_NOTHROW
{
	this->_memory_free();
	if(_Size == XString::npos)
	{
		this->_memory_malloc(0);
	}
	else
	{
		auto		vSize = static_cast<unsigned int>(_Size);
		this->_string_data = XANADU_NEW wchar_t[vSize + XANADU_STRING_REDUNDANCY];
		if(this->_string_data)
		{
			this->_string_capacity = _Size + XANADU_STRING_REDUNDANCY;
			Xanadu::wmemset(this->_string_data, 0, this->_string_capacity);
		}
		else
		{
			this->_string_length = 0;
			this->_string_capacity = 0;
		}
	}
}

/// memory operator append
void XString::_memory_append(size_type _Size) XANADU_NOTHROW
{
	if(_Size != XString::npos)
	{
		/// 保存原来的数据
		auto		_temp_malloc = false;
		auto		_temp_data = this->_string_data;
		auto		_temp_length = this->_string_length;
		/// 当容量减去长度小于要增加的数量时，分配一次内存
		if(this->_string_capacity - this->_string_length <= _Size)
		{
			this->_string_data = nullptr;
			this->_string_length = 0;
			_temp_malloc = true;
			this->_memory_free();
			this->_memory_malloc(_temp_length + _Size);
		}
		/// 当原来存在数据时，把数据拷贝回内存，并释放以前的块
		if(_temp_data && _temp_length > 0 && _temp_malloc)
		{
			Xanadu::wmemcpy(this->_string_data, _temp_data, _temp_length);
			this->_string_length = _temp_length;
			XANADU_DELETE_ARR(_temp_data);
		}
	}
}

/// memory operator resize
void XString::_memory_resize(size_type _Size) XANADU_NOTHROW
{
	if(_Size != XString::npos)
	{
		if(this->_string_length != _Size)
		{
			/// 保存原来的数据
			auto		_temp_data = this->_string_data;
			auto		_temp_length = this->_string_length > _Size ? _Size : this->_string_length;
			/// 重新申请一块内存
			this->_memory_free();
			this->_memory_malloc(_Size);
			/// 当原来存在数据时，把数据拷贝回内存，并释放以前的块
			if(_temp_data && _temp_length > 0)
			{
				Xanadu::wmemcpy(this->_string_data, _temp_data, _temp_length);
				this->_string_length = _temp_length;
				XANADU_DELETE_ARR(_temp_data);
			}
		}
		else
		{
			return;
		}
	}
}

/// memory operator delete
void XString::_memory_free() XANADU_NOTHROW
{
	XANADU_DELETE_ARR(this->_string_data);
	this->_string_data = nullptr;
	this->_string_length = 0LL;
	this->_string_capacity = 0LL;
}



/// private append wchar_t
void XString::_string_append(wchar_t _Char) XANADU_NOTHROW
{
	this->_memory_append(1);
	this->_string_data[this->_string_length] = _Char;
	this->_string_length += 1;
}

/// private append const wchar_t*
void XString::_string_append(const wchar_t* _String, size_type _Size) XANADU_NOTHROW
{
	if(_Size == XString::npos)
	{
		_Size = Xanadu::wcslen(_String);
	}
	if(_Size == 0 && nullptr == _string_data)
	{
		_memory_malloc(0);
	}
	if(_String && _Size > 0)
	{
		_memory_append(_Size);
		Xanadu::wmemcpy(this->_string_data + this->_string_length, _String, _Size);
		this->_string_length += _Size;
	}
}

/// private search wchar_t
XString::size_type XString::_string_search(wchar_t _Char, size_type _Begin, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	if(_Begin == XString::npos)
	{
		_Begin = 0;
	}
	if(Xanadu::CaseInsensitive == _XCS)
	{
		_Char = ::towupper(_Char);
	}
	auto		vPos = XString::npos;
	if(this->_string_data && this->_string_length < _Begin)
	{
		for(auto vIndex = _Begin; vIndex < this->_string_length; ++vIndex)
		{
			if(Xanadu::CaseInsensitive == _XCS)
			{
				if(::towupper(this->_string_data[vIndex]) == _Char)
				{
					return vIndex;
				}
			}
			else
			{
				if(this->_string_data[vIndex] == _Char)
				{
					return vIndex;
				}
			}
		}
	}
	return vPos;
}

/// private search const wchar_t*
XString::size_type XString::_string_search(const wchar_t* _String, size_type _Size, size_type _Begin, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	if(_Size == XString::npos)
	{
		_Size = Xanadu::wcslen(_String);
	}
	if(_Begin == XString::npos)
	{
		_Begin = 0;
	}
	auto		vPos = XString::npos;
	auto		vSubstr = static_cast<wchar_t*>(nullptr);
	if(this->_string_data && this->_string_length > _Begin && _Size > 0)
	{
		if(Xanadu::CaseInsensitive == _XCS)
		{
			auto		_temp_string = this->toUpper();
			auto		_temp_substr = XString(_String, _Size).toUpper();
			vSubstr = Xanadu::wcsstr(_temp_string._string_data + _Begin, _temp_substr._string_data);
			if(vSubstr)
			{
				vPos = vSubstr - _temp_string._string_data;
			}
		}
		else
		{
			vSubstr = Xanadu::wcsstr(this->_string_data + _Begin, _String);
			if(vSubstr)
			{
				vPos = vSubstr - this->_string_data;
			}
		}
	}
	return vPos;
}

/// private insert wchar_t
void XString::_string_insert(size_type _Pos, wchar_t _Char) XANADU_NOTHROW
{
	if(_Pos == XString::npos)
	{
		_Pos = 0;
	}
	if(this->_string_data && this->_string_length)
	{
		if(_Pos >= this->_string_length)
		{
			this->_string_append(_Char);
		}
		else
		{
			Xanadu::wmemmove(this->_string_data + _Pos, this->_string_data + _Pos + 1, this->_string_length - _Pos);
			this->_string_data[_Pos] = _Char;
			this->_string_length += 1;
		}
	}
	else
	{
		this->_string_append(_Char);
	}
}

/// private insert const wchar_t*
void XString::_string_insert(size_type _Pos, const wchar_t* _String, size_type _Size) XANADU_NOTHROW
{
	if(_Size == XString::npos)
	{
		_Size = Xanadu::wcslen(_String);
	}
	if(_Pos == XString::npos)
	{
		_Pos = 0;
	}
	if(nullptr == _String || 0ULL == _Size)
	{
		return;
	}
	if(this->_string_data && this->_string_length)
	{
		if(_Pos >= this->_string_length)
		{
			this->_string_append(_String, _Size);
		}
		else
		{
			Xanadu::wmemmove(this->_string_data + _Pos + _Size, this->_string_data + _Pos, this->_string_length - _Pos);
			Xanadu::wmemmove(this->_string_data + _Pos, _String, _Size);
			this->_string_length += _Size;
		}
	}
	else
	{
		this->_string_append(_String, _Size);
	}
}

/// private remove
void XString::_string_remove(size_type _Pos, size_type _Length) XANADU_NOTHROW
{
	if(_Pos == XString::npos)
	{
		_Pos = 0;
	}
	if(_Length <= 0)
	{
		return;
	}
	if(this->_string_data && this->_string_length)
	{
		if(this->_string_length > _Pos)
		{
			if(_Pos + _Length >= this->_string_length)
			{
				Xanadu::wmemset(this->_string_data + _Pos, 0, _Length);
			}
			else
			{
				Xanadu::wmemmove(this->_string_data + _Pos, this->_string_data + _Pos + _Length, this->_string_length - _Pos - _Length);
				Xanadu::wmemset(this->_string_data + (this->_string_length - _Length), 0, _Length);
			}
			this->_string_length -= _Length;
		}
	}
}

/// private compare
int32S XString::_string_compare(const wchar_t* _String, size_type _Size, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	if(Xanadu::CaseInsensitive == _XCS)
	{
		return Xanadu::wcscmp(this->toUpper()._string_data, XString(_String, _Size).toUpper()._string_data);
	}
	else
	{
		return Xanadu::wcscmp(this->_string_data, _String);
	}
}



/// 查找
XString::XString::size_type XString::_find(const wchar_t* _String, size_type _Length, size_type _Pos) const XANADU_NOTHROW
{
	auto		vReturn = npos;
	if(_Pos == npos)
	{
		_Pos = _string_length - 1;
	}
	for(; _Pos <= _string_length - _Length; ++_Pos)
	{
		if(operator[](_Pos) == *_String && _compare(_String, _Length, _Pos))
		{
			vReturn = _Pos;
			break;
		}
	}
	return vReturn;
}

/// 反向查找
XString::XString::size_type XString::_rfind(const wchar_t* _String, size_type _Length, size_type _Pos) const XANADU_NOTHROW
{
	auto		vReturn = XString::npos;
	if(_Pos == XString::npos || _Pos + _Length > _string_length + 1)
	{
		_Pos = _string_length - _Length + 1;
	}
	for(auto vIndex = _Pos; 0 <= vIndex; --vIndex)
	{
		if(operator[](vIndex) == *_String && _compare(_String, _Length, vIndex))
		{
			vReturn = vIndex;
			break;
		}
	}
	return vReturn;
}

/// 查找并比较
bool XString::_compare(const wchar_t* _String, size_type _Length, size_type _Pos) const XANADU_NOTHROW
{
	if(_Pos == XString::npos)
	{
		_Pos = 0ULL;
	}
	for(auto vIndex = _Pos; vIndex < _Length; ++vIndex)
	{
		if(operator[](_Pos + vIndex) != *(_String + vIndex))
		{
			return false;
		}
	}
	return true;
}



/// cxx iterator private
XString::String_iterator_type XString::_ibegin() const XANADU_NOTHROW
{
	return String_iterator_type(_string_data, &_string_length, 0);
}

/// cxx iterator private
XString::String_iterator_type XString::_end() const XANADU_NOTHROW
{
	return String_iterator_type(_string_data, &_string_length, _string_length);
}

/// cxx iterator private
XString::String_iterator_type XString::_rbegin() const XANADU_NOTHROW
{
	return String_iterator_type(_string_data, &_string_length, _string_length - 1);
}

/// cxx iterator private
XString::size_type XString::_getLength(const XString::const_iterator _First, const XString::const_iterator _Second) XANADU_NOTHROW
{
	if(_First.current.first != _Second.current.first)
	{
		return 0;
	}
	if(_First.current.pos > _Second.current.pos)
	{
		return 0;
	}
	return _Second.current.pos - _First.current.pos;
}




/// cxx iterator function
XString::iterator XString::begin() XANADU_NOTHROW
{
	return this->_ibegin();
}

/// cxx iterator function
XString::const_iterator XString::begin() const XANADU_NOTHROW
{
	return this->_ibegin();
}

/// cxx iterator function
XString::iterator XString::end() XANADU_NOTHROW
{
	return this->_end();
}

/// cxx iterator function
XString::const_iterator XString::end() const XANADU_NOTHROW
{
	return this->_end();
}

/// cxx iterator function
XString::const_iterator XString::cbegin() const XANADU_NOTHROW
{
	return this->_ibegin();
}

/// cxx iterator function
XString::const_iterator XString::cend() const XANADU_NOTHROW
{
	return this->_end();
}

/// cxx iterator function
XString::reverse_iterator XString::rbegin() XANADU_NOTHROW
{
	return this->_rbegin();
}

/// cxx iterator function
XString::const_reverse_iterator XString::rbegin() const XANADU_NOTHROW
{
	return this->_rbegin();
}

/// cxx iterator function
XString::reverse_iterator XString::rend() XANADU_NOTHROW
{
	return this->_end();
}

/// cxx iterator function
XString::const_reverse_iterator XString::rend() const XANADU_NOTHROW
{
	return this->_end();
}

/// cxx iterator function
XString::const_reverse_iterator XString::crbegin() const XANADU_NOTHROW
{
	return this->_rbegin();
}

/// cxx iterator function
XString::const_reverse_iterator XString::crend() const XANADU_NOTHROW
{
	return this->_end();
}



/// string buffer
wchar_t* XString::data() XANADU_NOTHROW
{
	return this->_string_data;
}

/// string buffer
const wchar_t* XString::data() const XANADU_NOTHROW
{
	return this->_string_data;
}

/// string length
XString::size_type XString::length() const XANADU_NOTHROW
{
	return this->_string_length;
}

/// string length
XString::size_type XString::size() const XANADU_NOTHROW
{
	return this->length();
}

/// buffer capacity
XString::size_type XString::capacity() const XANADU_NOTHROW
{
	return this->_string_capacity;
}

/// buffer clear
void XString::clear() XANADU_NOTHROW
{
	this->_memory_free();
}

/// buffer is null
bool XString::empty() const XANADU_NOTHROW
{
	if(this->data() && this->size() > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/// Check if there is a value
bool XString::exist() const XANADU_NOTHROW
{
	return !this->empty();
}

/// swap string
void XString::swap(XString& _String) XANADU_NOTHROW
{
	XString		vTemp = std::move(*this);
	*this = std::move(_String);
	_String = std::move(vTemp);
}

/// max_size
XString::size_type XString::max_size() const XANADU_NOTHROW
{
	return 0xFFFFFFFFFFLL;
}

/// resize
void XString::resize(size_type _Length) XANADU_NOTHROW
{
	this->_memory_resize(_Length);
}

/// resize
void XString::resize(size_type _Length, wchar_t _Char) XANADU_NOTHROW
{
	this->_memory_resize(_Length);
	for(auto vIndex = 0ULL; vIndex < this->_string_length && this->_string_data; ++vIndex)
	{
		operator[](vIndex) = _Char;
	}
}

/// Truncates the byte array at index position pos. If pos is beyond the end of the array, nothing happens.
void XString::truncate(size_type _Index) XANADU_NOTHROW
{
	if (_Index < this->size())
	{
		this->resize(_Index);
	}
}




/// 元素访问 (1)
const wchar_t& XString::operator [] (size_type _Index) const
{
	return *(this->_string_data + _Index);
}

/// 元素访问 (2)
wchar_t& XString::operator [] (size_type _Index)
{
	return *(this->_string_data + _Index);
}

/// 元素访问 (3)
const wchar_t& XString::at(size_type _Index) const
{
	if(this->_string_length <= _Index)
	{
		throw;
	}
	return operator[](_Index);
}

/// 元素访问 (4)
wchar_t& XString::at(size_type _Index)
{
	if(this->_string_length <= _Index)
	{
		throw;
	}
	return operator[](_Index);
}

/// 元素访问 (5)
const wchar_t& XString::front() const
{
	return operator[](0);
}

/// 元素访问 (6)
wchar_t& XString::front()
{
	return operator[](0);
}

/// 元素访问 (7)
const wchar_t& XString::back() const
{
	return operator[](this->size() - 1);
}

/// 元素访问 (8)
wchar_t& XString::back()
{
	return operator[](this->size() - 1);
}


/// cxx push_back (1)
void XString::push_back(wchar_t _Char) XANADU_NOTHROW
{
	this->append(_Char);
}

/// cxx push_back (2)
void XString::push_back(const wchar_t* _String, size_type _Size) XANADU_NOTHROW
{
	this->append(_String, _Size);
}

/// cxx push_back (3)
void XString::push_back(const XString& _String) XANADU_NOTHROW
{
	this->append(_String);
}

/// cxx 删除最后一个元素
XString& XString::pop_back() XANADU_NOTHROW
{
	if(this->size())
	{
		operator[](size() - 1) = L'\0';
	}
	return *this;
}


/// operator append (1)
XString& XString::operator += (wchar_t _Char) XANADU_NOTHROW
{
	wchar_t		vBuffer[2] = { 0 };
	vBuffer[0] = _Char;
	this->_string_append(vBuffer);
	return *this;
}

/// operator append (2)
XString& XString::operator += (const wchar_t* _String) XANADU_NOTHROW
{
	this->_string_append(_String);
	return *this;
}

/// operator append (3)
XString& XString::operator += (const XString& _String) XANADU_NOTHROW
{
	this->_string_append(_String._string_data, _String._string_length);
	return *this;
}




/// 比较运算符 (1)
bool XString::operator == (const wchar_t* _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String, Xanadu::wcslen(_String)) == 0;
}

/// 比较运算符 (1)
bool XString::operator == (const XString& _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String._string_data, _String._string_length) == 0;
}

/// 比较运算符 (2)
bool XString::operator != (const wchar_t* _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String, Xanadu::wcslen(_String)) != 0;
}

/// 比较运算符 (2)
bool XString::operator != (const XString& _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String._string_data, _String._string_length) != 0;
}

/// 比较运算符 (3)
bool XString::operator < (const wchar_t* _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String, Xanadu::wcslen(_String)) < 0;
}

/// 比较运算符 (3)
bool XString::operator < (const XString& _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String._string_data, _String._string_length) < 0;
}

/// 比较运算符 (4)
bool XString::operator > (const wchar_t* _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String, Xanadu::wcslen(_String)) > 0;
}

/// 比较运算符 (4)
bool XString::operator > (const XString& _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String._string_data, _String._string_length) > 0;
}

/// 比较运算符 (5)
bool XString::operator <= (const wchar_t* _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String, Xanadu::wcslen(_String)) <= 0;
}

/// 比较运算符 (5)
bool XString::operator <= (const XString& _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String._string_data, _String._string_length) <= 0;
}

/// 比较运算符 (6)
bool XString::operator >= (const wchar_t* _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String, Xanadu::wcslen(_String)) >= 0;
}

/// 比较运算符 (6)
bool XString::operator >= (const XString& _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String._string_data, _String._string_length) >= 0;
}







/// Convert : To ASCII
AString XString::toAString() const XANADU_NOTHROW
{
	auto		vAString = AString("");
	if(data() && size())
	{
		auto	vCurrLocale = AString(Xanadu::setlocale(LC_ALL, NULL));

		Xanadu::setlocale(LC_ALL, "chs");

		auto	_DestSize = static_cast<unsigned int>(4 * size() + 1);
		auto	_Dest = XANADU_NEW char[_DestSize];
		Xanadu::memset(_Dest, 0, _DestSize);
		Xanadu::wcstombs(_Dest, data(), _DestSize);

		vAString = _Dest;
		XANADU_DELETE_ARR(_Dest);

		Xanadu::setlocale(LC_ALL, vCurrLocale.data());
	}
	return vAString;
}

/// Convert : To UNICODE
WString XString::toWString() const XANADU_NOTHROW
{
	return WString(data() ? data() : L"");
}

/// Convert : To UTF-8
UString XString::toUString() const XANADU_NOTHROW
{
	auto	vReturn = UString("");
	try
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> vConvert;
		vReturn = vConvert.to_bytes(data() ? data() : L"");
	}
	catch(const std::exception& _Except)
	{
		std::cerr << _Except.what() << std::endl;
	}
	return vReturn;
}

/// Convert : To Native String
NString XString::toNString() const XANADU_NOTHROW
{
#ifdef XANADU_SYSTEM_WINDOWS
	return toAString();
#else
	return toUString();
#endif/// XANADU_SYSTEM_WINDOWS
}

/// Convert : To XByteArray
XByteArray XString::toBytes() const XANADU_NOTHROW
{
	auto		vUString = this->toUString();
	return XByteArray(vUString.data(), vUString.size());
}

/// Convert : To URL Encode
UString XString::toURL() const XANADU_NOTHROW
{
	auto		vDecode = toUString();
	auto		vEncode = UString();
	for(auto vIterator = vDecode.begin(); vIterator != vDecode.end(); ++vIterator)
	{
		auto	vChar = (*vIterator);
		if(((vChar >= 'A') && (vChar <= 'Z')) || ((vChar >= 'a') && (vChar <= 'z')) || ((vChar >= '0') && (vChar <= '9')))
		{
			vEncode.append(1, vChar);
		}
		else if(vChar == ' ')
		{
			vEncode.append("%20");
		}
		else if(vChar == '.' || vChar == '-' || vChar == '_' || vChar == '*' || vChar == ':' || vChar == '/' || vChar == ',')
		{
			vEncode.append(1, vChar);
		}
		else if(vChar == '&' || vChar == '?' || vChar == '=')
		{
			vEncode.append(1, vChar);
		}
		else
		{
			char	_Buffer[16] = { 0 };
			sprintf(_Buffer, "%%%02X", (unsigned char)vChar);
			vEncode.append(_Buffer);
		}
	}
	return vEncode;
}

/// Convert:To ASCII
AString XANADUAPI XString::toAString(const XString& _String) XANADU_NOTHROW
{
	return _String.toAString();
}

/// Convert:To UNICODE
WString XANADUAPI XString::toWString(const XString& _String) XANADU_NOTHROW
{
	return _String.toWString();
}

/// Convert:To UTF-8
UString XANADUAPI XString::toUString(const XString& _String) XANADU_NOTHROW
{
	return _String.toUString();
}

/// Convert : To Native String
NString XANADUAPI XString::toNString(const XString& _String) XANADU_NOTHROW
{
	return _String.toNString();
}

/// Convert : To XByteArray
XByteArray XANADUAPI XString::toBytes(const XString& _String) XANADU_NOTHROW
{
	return _String.toBytes();
}

/// Convert : To URL Encode
UString XANADUAPI XString::toURL(const XString& _String) XANADU_NOTHROW
{
	return _String.toURL();
}

/// Convert : From ASCII
XString XANADUAPI XString::fromAString(const AString& _AString) XANADU_NOTHROW
{
	auto		vXString = XString(L"");
	if(_AString.data() && _AString.size())
	{
		auto	vCurrLocale = AString(Xanadu::setlocale(LC_ALL, NULL));

		Xanadu::setlocale(LC_ALL, "chs");

		auto	_Dsize = static_cast<unsigned int>(_AString.size() + 1);
		auto	_Dest = XANADU_NEW wchar_t[_Dsize];
		Xanadu::wmemset(_Dest, 0, _Dsize);
		Xanadu::mbstowcs(_Dest, _AString.data(), _Dsize);

		vXString = _Dest;
		XANADU_DELETE_ARR(_Dest);

		Xanadu::setlocale(LC_ALL, vCurrLocale.data());
	}
	return vXString;
}

/// Convert : From UNICODE
XString XANADUAPI XString::fromWString(const WString& _XString) XANADU_NOTHROW
{
	return XString(_XString.data());
}

/// Convert : From UTF-8
XString XANADUAPI XString::fromUString(const UString& _UString) XANADU_NOTHROW
{
	auto		vReturn = XString(L"");
	try
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> vConvert;
		vReturn = vConvert.from_bytes(_UString);
	}
	catch(const std::exception& _Except)
	{
		std::cerr << _Except.what() << std::endl;
	}
	return vReturn;
}

/// Convert:From Latin_1(ISO 8859-1)
XString XANADUAPI XString::fromLString(const LString& _LString) XANADU_NOTHROW
{
	auto		_UString = UString();
	for(auto vIterator = _LString.begin(); vIterator != _LString.end(); ++vIterator)
	{
		auto	vChar = (*vIterator);
		if(vChar < 0x80)
		{
			_UString.push_back(vChar);
		}
		else
		{
			_UString.push_back(0xc0 | (vChar & 0xc0) >> 6);
			_UString.push_back(0x80 | (vChar & 0x3f));
		}
	}
	return fromUString(_UString);
}

/// Convert : From Native String
XString XANADUAPI XString::fromNString(const NString& _NString) XANADU_NOTHROW
{
#ifdef XANADU_SYSTEM_WINDOWS
	return XString::fromAString(_NString);
#else
	return XString::fromUString(_NString);
#endif/// XANADU_SYSTEM_WINDOWS
}

/// Convert : From XByteArray
XString XANADUAPI XString::fromBytes(const XByteArray& _Bytes) XANADU_NOTHROW
{
	return XString::fromUString(UString(_Bytes.data(), _Bytes.size()));
}

/// Convert:From URL Encode
XString XANADUAPI XString::fromURL(const UString& _URL) XANADU_NOTHROW
{
	auto		vEncode = _URL;
	auto		vDecode = UString();

	auto		Function_Hex2Num = [](char _Char)->int
	{
		if(_Char >= '0' && _Char <= '9')
		{
			return _Char - '0';
		}
		if(_Char >= 'a' && _Char <= 'z')
		{
			return _Char - 'a' + 10;
		}
		if(_Char >= 'A' && _Char <= 'Z')
		{
			return _Char - 'A' + 10;
		}
		return '0';
	};

	for(auto vIterator = vEncode.begin(); vIterator != vEncode.end(); ++vIterator)
	{
		auto	_Char = (*vIterator);
		switch(_Char)
		{
			case '%':
				if((vIterator + 2) != vEncode.end())
				{
					auto	_Char1 = Function_Hex2Num(*(vIterator + 1));
					auto	_Char2 = Function_Hex2Num(*(vIterator + 2));
					if((_Char1 != '0') && (_Char2 != '0'))
					{
						vDecode.append(1, (char)((_Char1 << 4) | _Char2));
					}
					vIterator += 2;
				}
				break;
			default:
				vDecode.append(1, _Char);
				break;
		}
	}
	return fromUString(vDecode);
}

/// convert to upper
XString XString::toUpper() const XANADU_NOTHROW
{
	if(this->data() && this->size())
	{
		auto		vUpper = WString(data());
		std::transform(vUpper.begin(), vUpper.end(), vUpper.begin(), ::towupper);
		return vUpper.data();
	}
	return *this;
}

/// convert to lower
XString XString::toLower() const XANADU_NOTHROW
{
	if(this->data() && this->size())
	{
		auto		vLower = WString(data());
		std::transform(vLower.begin(), vLower.end(), vLower.begin(), ::towlower);
		return vLower.data();
	}
	return *this;
}


/// Format String (char* [%S]) (wchar_t* [%s][%ls][%ws])
XString XANADUAPI XString::format(const wchar_t* _Format, ...) XANADU_NOTHROW
{
	auto		vString = XString();
	auto		vBuffer = XANADU_NEW wchar_t[XANADU_SIZE_KB * 10];
	if(vBuffer)
	{
		Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * XANADU_SIZE_KB * 10);
		va_list		vArgs;
		va_start(vArgs, _Format);
		vswprintf(vBuffer, XANADU_SIZE_KB * 10, _Format, vArgs);
		va_end(vArgs);

		vString = vBuffer;
		XANADU_DELETE_ARR(vBuffer);
	}
	return vString;
}


/// Sub String
XString XString::substr(size_type _Pos, size_type _Length) const XANADU_NOTHROW
{
	if(_Pos < this->size())
	{
		return XString(this->data() + _Pos, this->size() > _Length ? _Length : XString::npos);
	}
	else
	{
		return XString();
	}
}

/// Sub String
XString XString::left(size_type _Pos) const XANADU_NOTHROW
{
	return this->substr(0, _Pos);
}

/// Sub String
XString XString::right(size_type _Pos) const XANADU_NOTHROW
{
	return this->substr(size() - _Pos, XString::npos);
}

/// Retrieve the middle data by length
XString XString::mid(size_type _Pos, size_type _Size) const XANADU_NOTHROW
{
	return this->substr(_Pos, _Size);
}

/// Middle String
XString XString::middle(const XString& _Left, const XString& _Right, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	auto		vPosLeft = this->_string_search(_Left._string_data, _Left._string_length, 0, _XCS);
	if(XString::npos != vPosLeft)
	{
		vPosLeft += _Left._string_length;
		auto		vPosRight = this->_string_search(_Right._string_data, _Right._string_length, vPosLeft, _XCS);
		if(XString::npos != vPosRight)
		{
			return substr(vPosLeft, vPosRight - vPosLeft);
		}
	}
	return XString();
}




/// XString Find(1)
XString::XString::size_type XString::find(const XString& _String, size_type _Pos) const XANADU_NOTHROW
{
	return this->_find(_String._string_data, _String._string_length, _Pos);
}

/// XString Find(2)
XString::XString::size_type XString::find(const wchar_t* _String, size_type _Pos) const XANADU_NOTHROW
{
	return this->_find(_String, Xanadu::wcslen(_String), _Pos);
}

/// XString Find(3)
XString::XString::size_type XString::find(const wchar_t* _String, size_type _Length, size_type _Pos) const XANADU_NOTHROW
{
	return this->_find(_String, _Length, _Pos);
}

/// XString Find(4)
XString::XString::size_type XString::find(wchar_t _Char, size_type _Pos) const XANADU_NOTHROW
{
	return this->_find(&_Char, 1, _Pos);
}


/// Reverse Find(1)
XString::XString::size_type XString::rfind(const XString& _String, size_type _Pos) const XANADU_NOTHROW
{
	return this->_rfind(_String._string_data, _String._string_length, _Pos);
}

/// Reverse Find(2)
XString::XString::size_type XString::rfind(const wchar_t* _String, size_type _Pos) const XANADU_NOTHROW
{
	return  this->_rfind(_String, Xanadu::wcslen(_String), _Pos);
}

/// Reverse Find(3)
XString::XString::size_type XString::rfind(const wchar_t* _String, size_type _Length, size_type _Pos) const XANADU_NOTHROW
{
	return this->_rfind(_String, _Length, _Pos);
}

/// Reverse Find(4)
XString::XString::size_type XString::rfind(wchar_t _Char, size_type _Pos) const XANADU_NOTHROW
{
	return this->_rfind(&_Char, 1, _Pos);
}


/// Index Of (1)
XString::XString::size_type XString::indexOf(const XString& _String, size_type _Pos) const XANADU_NOTHROW
{
	return this->find(_String, _Pos);
}

/// Index Of (2)
XString::XString::size_type XString::indexOf(const wchar_t* _String, size_type _Pos) const XANADU_NOTHROW
{
	return this->find(_String, _Pos);
}

/// Index Of (3)
XString::XString::size_type XString::indexOf(const wchar_t* _String, size_type _Length, size_type _Pos) const XANADU_NOTHROW
{
	return this->find(_String, _Length, _Pos);
}

/// Index Of (4)
XString::XString::size_type XString::indexOf(wchar_t _Char, size_type _Pos) const XANADU_NOTHROW
{
	return this->find(&_Char, 1, _Pos);
}


/// Last Index Of (1)
XString::XString::size_type XString::lastIndexOf(const XString& _String, size_type _Pos) const XANADU_NOTHROW
{
	return this->rfind(_String, _Pos);
}

/// Last Index Of (2)
XString::XString::size_type XString::lastIndexOf(const wchar_t* _String, size_type _Pos) const XANADU_NOTHROW
{
	return this->rfind(_String, Xanadu::wcslen(_String), _Pos);
}

/// Last Index Of (3)
XString::XString::size_type XString::lastIndexOf(const wchar_t* _String, size_type _Length, size_type _Pos) const XANADU_NOTHROW
{
	return this->rfind(_String, _Length, _Pos);
}

/// Last Index Of (4)
XString::XString::size_type XString::lastIndexOf(wchar_t _Char, size_type _Pos) const XANADU_NOTHROW
{
	return this->rfind(&_Char, 1, _Pos);
}




/// contains substring
bool XString::contains(wchar_t _Char, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	wchar_t		vBuffer[2] = { _Char, 0 };
	return this->contains(vBuffer, 1, _XCS);
}

/// contains substring
bool XString::contains(const wchar_t* _String, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return this->contains(_String, Xanadu::wcslen(_String), _XCS);
}

/// contains substring
bool XString::contains(const wchar_t* _String, size_type _Size, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return this->_string_search(_String, _Size, 0, _XCS) != XString::npos ? true : false;
}

/// contains substring
bool XString::contains(const XString& _String, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return this->contains(_String._string_data, _String._string_length, _XCS);
}





/// compare substring
int XString::compare(wchar_t _Char, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	wchar_t		vBuffer[2] = { _Char, 0 };
	return this->compare(vBuffer, 1, _XCS);
}

/// compare substring
int XString::compare(const wchar_t* _String, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return this->compare(_String, Xanadu::wcslen(_String), _XCS);
}

/// compare substring
int XString::compare(const wchar_t* _String, size_type _Size, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return this->_string_compare(_String, _Size, _XCS);
}

/// compare substring
int XString::compare(const XString& _String, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return this->compare(_String._string_data, _String._string_length, _XCS);
}




/// append (1)
XString& XString::append(wchar_t _Char) XANADU_NOTHROW
{
	wchar_t		vBuffer[2] = { _Char, 0 };
	return this->append(vBuffer);
}

/// append (2)
XString& XString::append(const wchar_t* _String, size_type _Size) XANADU_NOTHROW
{
	if(_Size == XString::npos)
	{
		_Size = Xanadu::wcslen(_String);
	}
	this->_string_append(_String, _Size);
	return *this;
}

/// append (3)
XString& XString::append(const XString& _String) XANADU_NOTHROW
{
	return this->append(_String._string_data, _String._string_length);
}




/// string insert wchar_t
XString& XString::insert(size_type _Pos, wchar_t _Char) XANADU_NOTHROW
{
	this->_string_insert(_Pos, _Char);
	return *this;
}

/// string insert wchar_t
XString& XString::insert(size_type _Pos, size_type _Count, wchar_t _Char) XANADU_NOTHROW
{
	for(auto vIndex = 0ULL; vIndex < _Count; ++vIndex)
	{
		this->_string_insert(_Pos, _Char);
	}
	return *this;
}

/// string insert const wchar_t*
XString& XString::insert(size_type _Pos, const wchar_t* _String, size_type _Length) XANADU_NOTHROW
{
	this->_string_insert(_Pos, _String, _Length);
	return *this;
}

/// string insert XString
XString& XString::insert(size_type _Pos, const XString& _String) XANADU_NOTHROW
{
	this->_string_insert(_Pos, _String._string_data, _String._string_length);
	return *this;
}



/// string remove (1)
XString& XString::remove(size_type _Pos, size_type _Length) XANADU_NOTHROW
{
	this->_string_remove(_Pos, _Length);
	return *this;
}

/// string remove (2)
XString& XString::remove(wchar_t _Char, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	auto		vPos = XString::npos;
	do
	{
		vPos = this->_string_search(_Char, vPos, _XCS);
		if(XString::npos != vPos)
		{
			this->_string_remove(vPos, 1);
			vPos += 1;
		}
	} while(XString::npos != vPos);
	return *this;
}

/// string remove (3)
XString& XString::remove(const wchar_t* _String, size_type _Length, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	auto		vPos = XString::npos;
	if(_Length == XString::npos)
	{
		_Length = Xanadu::wcslen(_String);
	}
	do
	{
		vPos = this->_string_search(_String, _Length, vPos, _XCS);
		if(XString::npos != vPos)
		{
			this->_string_remove(vPos, _Length);
		}
	} while(XString::npos != vPos);
	return *this;
}

/// string remove (4)
XString& XString::remove(const XString& _String, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	return this->remove(_String._string_data, _String._string_length, _XCS);
}



/// string replace
XString& XString::replace(size_type _Pos, size_type _Length, wchar_t _After) XANADU_NOTHROW
{
	this->remove(_Pos, _Length);
	this->insert(_Pos, _After);
	return *this;
}

/// string replace
XString& XString::replace(size_type _Pos, size_type _Length, const wchar_t* _After, size_type _LengthA) XANADU_NOTHROW
{
	this->remove(_Pos, _Length);
	this->insert(_Pos, _After, _LengthA);
	return *this;
}

/// string replace
XString& XString::replace(size_type _Pos, size_type _Length, const XString& _After) XANADU_NOTHROW
{
	this->remove(_Pos, _Length);
	this->insert(_Pos, _After._string_data, _After._string_length);
	return *this;
}

/// string replace
XString& XString::replace(wchar_t _Before, wchar_t _After, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	wchar_t		vStringA[2] = { _After, 0 };
	return replace(_Before, XString(vStringA), _XCS);
}

/// string replace
XString& XString::replace(wchar_t _Before, const wchar_t* _After, size_type _LengthA, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	wchar_t		vStringB[2] = { _Before, 0 };
	return this->replace(XString(vStringB), _After, _LengthA, _XCS);
}

/// string replace
XString& XString::replace(wchar_t _Before, const XString& _After, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	wchar_t		vStringB[2] = { _Before, 0 };
	return this->replace(XString(vStringB), _After._string_data, _After._string_length, _XCS);
}

/// string replace
XString& XString::replace(const wchar_t* _Before, size_type _LengthB, wchar_t _After, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	wchar_t		vStringA[2] = { _After, 0 };
	return this->replace(_Before, _LengthB, XString(vStringA), _XCS);
}

/// string replace
XString& XString::replace(const wchar_t* _Before, size_type _LengthB, const wchar_t* _After, size_type _LengthA, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	auto		vPos = XString::npos;
	do
	{
		vPos = this->_string_search(_Before, _LengthB, vPos, _XCS);
		if(XString::npos != vPos)
		{
			this->remove(vPos, _LengthB);
			this->insert(vPos, _After, _LengthA);
			vPos += _LengthA;
		}
	} while(XString::npos != vPos);
	return *this;
}

/// string replace
XString& XString::replace(const wchar_t* _Before, size_type _LengthB, const XString& _After, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	return this->replace(_Before, _LengthB, _After._string_data, _After._string_length, _XCS);
}

/// string replace
XString& XString::replace(const XString& _Before, wchar_t _After, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	wchar_t		vStringA[2] = { _After, 0 };
	return this->replace(_Before._string_data, _Before._string_length, XString(vStringA), _XCS);
}

/// string replace
XString& XString::replace(const XString& _Before, const wchar_t* _After, size_type _LengthA, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	return this->replace(_Before._string_data, _Before._string_length, _After, _LengthA, _XCS);
}

/// string replace
XString& XString::replace(const XString& _Before, const XString& _After, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	return this->replace(_Before._string_data, _Before._string_length, _After._string_data, _After._string_length, _XCS);
}





/// isSpace
bool XString::isSpace(wchar_t _Char) XANADU_NOTHROW
{
	if(_Char == L' ' || _Char == L'\t' || _Char == L'\n' || _Char == L'\v' || _Char == L'\f' || _Char == L'\r')
	{
		return true;
	}
	return false;
}

/// simplified
XString XString::simplified() const XANADU_NOTHROW
{
	auto		vString = XString();
	auto		vNumber = 0;
	auto		vBegin = true;
	for(auto vIndex = 0ULL; vIndex < size(); ++vIndex)
	{
		if(XString::isSpace(data()[vIndex]))
		{
			++vNumber;
		}
		else
		{
			if(false == vBegin)
			{
				if(vNumber)
				{
					vString.push_back(L' ');
				}
			}
			vString.push_back(data()[vIndex]);

			vNumber = 0;
			vBegin = false;
		}
	}
	return vString;
}





/// string to int16S
int16S XString::toInt16S(bool* _Ok, int _Base) const XANADU_NOTHROW
{
	return static_cast<int16S>(this->toInt64S(_Ok, _Base));
}

/// string to int16U
int16U XString::toInt16U(bool* _Ok, int _Base) const XANADU_NOTHROW
{
	return static_cast<int16U>(this->toInt64U(_Ok, _Base));
}

/// string to int32S
int32S XString::toInt32S(bool* _Ok, int _Base) const XANADU_NOTHROW
{
	return static_cast<int32S>(this->toInt64S(_Ok, _Base));
}

/// string to int32U
int32U XString::toInt32U(bool* _Ok, int _Base) const XANADU_NOTHROW
{
	return static_cast<int32U>(this->toInt64U(_Ok, _Base));
}

/// string to size_type
XString::size_type XString::toInt64S(bool* _Ok, int _Base) const XANADU_NOTHROW
{
	auto		vEnd = static_cast<wchar_t*>(nullptr);
	auto		vValue = static_cast<size_type>(std::wcstol(data(), &vEnd, _Base));

	if(_Ok)
	{
		if(vEnd && vEnd[0] == L'\0')
		{
			*_Ok = true;
		}
		else
		{
			*_Ok = false;
		}
	}

	return vValue;
}

/// string to size_type
XString::size_type XString::toInt64U(bool* _Ok, int _Base) const XANADU_NOTHROW
{
	auto		vEnd = static_cast<wchar_t*>(nullptr);
	auto		vValue = static_cast<size_type>(std::wcstoul(data(), &vEnd, _Base));

	if(_Ok)
	{
		if(vEnd && vEnd[0] == L'\0')
		{
			*_Ok = true;
		}
		else
		{
			*_Ok = false;
		}
	}

	return vValue;
}

/// string to float
float XString::toFloat(bool* _Ok) const XANADU_NOTHROW
{
	auto		vEnd = static_cast<wchar_t*>(nullptr);
	auto		vValue = std::wcstof(data(), &vEnd);

	if(_Ok)
	{
		if(vEnd && vEnd[0] == L'\0')
		{
			*_Ok = true;
		}
		else
		{
			*_Ok = false;
		}
	}

	return vValue;
}

/// string to double
double XString::toDouble(bool* _Ok) const XANADU_NOTHROW
{
	auto		vEnd = static_cast<wchar_t*>(nullptr);
	auto		vValue = std::wcstod(data(), &vEnd);

	if(_Ok)
	{
		if(vEnd && vEnd[0] == L'\0')
		{
			*_Ok = true;
		}
		else
		{
			*_Ok = false;
		}
	}

	return vValue;
}




/// string form number
XString& XString::setNumber(int16S _Value, int32S _Base) XANADU_NOTHROW
{
	this->setNumber(static_cast<size_type>(_Value), _Base);
	return *this;
}

/// string form number
XString& XString::setNumber(int16U _Value, int32S _Base) XANADU_NOTHROW
{
	this->setNumber(static_cast<size_type>(_Value), _Base);
	return *this;
}

/// string form number
XString& XString::setNumber(int32S _Value, int32S _Base) XANADU_NOTHROW
{
	this->setNumber(static_cast<size_type>(_Value), _Base);
	return *this;
}

/// string form number
XString& XString::setNumber(int32U _Value, int32S _Base) XANADU_NOTHROW
{
	this->setNumber(static_cast<size_type>(_Value), _Base);
	return *this;
}

/// string form number
XString& XString::setNumber(int64S _Value, int32S _Base) XANADU_NOTHROW
{
	if(2 <= _Base && _Base <= 36)
	{
		*this = std::to_wstring(_Value).data();
	}
	return *this;
}

/// string form number
XString& XString::setNumber(int64U _Value, int32S _Base) XANADU_NOTHROW
{
	if(2 <= _Base && _Base <= 36)
	{
		*this = std::to_wstring(_Value).data();
	}
	return *this;
}

/// string form number
XString& XString::setNumber(float _Value, char _Format, int32S _Prec) XANADU_NOTHROW
{
	XANADU_UNPARAMETER(_Format);
	XANADU_UNPARAMETER(_Prec);

	*this = std::to_wstring(_Value).data();
	return *this;
}

/// string form number
XString& XString::setNumber(double _Value, char _Format, int32S _Prec) XANADU_NOTHROW
{
	XANADU_UNPARAMETER(_Format);
	XANADU_UNPARAMETER(_Prec);

	*this = std::to_wstring(_Value).data();
	return *this;
}




/// string form number
XString XString::number(int16S _Value, int32S _Base) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.setNumber(_Value, _Base);
	return vValue;
}

/// string form number
XString XString::number(int16U _Value, int32S _Base) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.setNumber(_Value, _Base);
	return vValue;
}

/// string form number
XString XString::number(int32S _Value, int32S _Base) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.setNumber(_Value, _Base);
	return vValue;
}

/// string form number
XString XString::number(int32U _Value, int32S _Base) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.setNumber(_Value, _Base);
	return vValue;
}

/// string form number
XString XString::number(int64S _Value, int32S _Base) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.setNumber(_Value, _Base);
	return vValue;
}

/// string form number
XString XString::number(size_type _Value, int32S _Base) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.setNumber(_Value, _Base);
	return vValue;
}

/// string form number
XString XString::number(double _Value, char _Format, int32S _Prec) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.setNumber(_Value, _Format, _Prec);
	return vValue;
}












/// XString Swap
XANADU_CORE_EXPORT void swap(XString& _String1, XString& _String2) XANADU_NOTHROW
{
	_String1.swap(_String2);
}

/// XString Merged
XANADU_CORE_EXPORT XString operator+ (const XString& _StringLeft, const XString& _StringRight) XANADU_NOTHROW
{
	XString		vReturn = _StringLeft;
	vReturn += _StringRight;
	return vReturn;
}

/// XString Merged
XANADU_CORE_EXPORT XString operator+ (const XString& _StringLeft, const wchar_t* _StringRight) XANADU_NOTHROW
{
	XString		vReturn = _StringLeft;
	vReturn += _StringRight;
	return vReturn;
}

/// XString Merged
XANADU_CORE_EXPORT XString operator+ (const wchar_t* _StringLeft, const XString& _StringRight) XANADU_NOTHROW
{
	XString		vReturn = _StringLeft;
	vReturn += _StringRight;
	return vReturn;
}

/// XString Merged
XANADU_CORE_EXPORT XString operator+ (const XString& _StringLeft, wchar_t _CharRight) XANADU_NOTHROW
{
	XString		vReturn = _StringLeft;
	vReturn += _CharRight;
	return vReturn;
}

/// XString Merged
XANADU_CORE_EXPORT XString operator+ (wchar_t _CharLeft, const XString& _StringRight) XANADU_NOTHROW
{
	XString		vReturn = _StringRight;
	vReturn += _CharLeft;
	return vReturn;
}

/// XString Out
XANADU_CORE_EXPORT std::wostream& operator<< (std::wostream& _OStream, const XString& _String) XANADU_NOTHROW
{
	for(auto vIndex = 0ULL; vIndex < _String.length(); ++vIndex)
	{
		_OStream << _String[vIndex];
	}
	return _OStream;
}

/// XString In
XANADU_CORE_EXPORT std::wistream& operator>> (std::wistream& _IStream, XString& _String) XANADU_NOTHROW
{
	_String.clear();
	do
	{
		auto	vChar = static_cast<wchar_t>(_IStream.get());
		if(vChar == L'\n' || vChar == L' ')
		{
			break;
		}
		_String.push_back(vChar);
	} while(true);
	return _IStream;
}

/// XString in line
XANADU_CORE_EXPORT std::wistream& getline(std::wistream& _IStream, XString& _String, wchar_t _Delim) XANADU_NOTHROW
{
	_String.clear();
	do
	{
		auto	vChar = static_cast<wchar_t>(_IStream.get());
		if(vChar == _Delim)
		{
			break;
		}
		_String.push_back(vChar);
	} while(true);
	return _IStream;
}

/// XString in line
XANADU_CORE_EXPORT std::wistream& getline(std::wistream& _IStream, XString& _String) XANADU_NOTHROW
{
	return getline(_IStream, _String, L'\n');
}

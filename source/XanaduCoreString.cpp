#include <XanaduCore/XanaduCoreString.h>

#define				XANADU_STRING_FORMAT_LENGTH			102400
#define				XANADU_STRING_REDUNDANCY			128



//const_iterator
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


//protected const_iterator function 
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
	{ // beyond end
		throw;
	}
	vReturn = *this;
	vReturn.current.pos += i;
}

void XString::const_iterator::_subtract(const_iterator& vReturn, size_type i)
{
	if(current.pos < i)
	{ // if _Pos will be less than zero
		throw;
	}
	vReturn = *this;
	vReturn.current.pos -= i;
}


//iterator
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


//const_reverse_iterator Private
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


//protected functions
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
	if(*_myBase::current.size <= _myBase::current.pos + i) // moved past reverse first element 
		throw;

	vReturn = *this;
	vReturn.current.pos += i;
}


//Reverse iterator
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
	_memory_malloc(0);
}

XString::XString(wchar_t _Char) XANADU_NOTHROW
{
	_memory_malloc(0);
	_string_append(_Char);
}

XString::XString(const wchar_t* _String) XANADU_NOTHROW
{
	_memory_malloc(0);

	auto	vLength = Xanadu::wcslen(_String);
	if(_String && vLength > 0)
	{
		_string_append(_String, vLength);
	}
}

XString::XString(const wchar_t* _String, int64S _Length) XANADU_NOTHROW
{
	_memory_malloc(0);

	if(_Length < 0)
	{
		_Length = Xanadu::wcslen(_String);
	}
	if(_String && _Length > 0)
	{
		_string_append(_String, _Length);
	}
}

XString::XString(const XString& _String) XANADU_NOTHROW
{
	_memory_malloc(0);

	if(_String._string_length > 0)
	{
		_string_append(_String._string_data, _String._string_length);
	}
}

XString::XString(XString&& _String) XANADU_NOTHROW
{
	*this = std::move(_String);
}

XString::XString(const WString& _String) XANADU_NOTHROW
{
	_memory_malloc(0);

	if(_String.size() > 0)
	{
		_string_append(_String.data(), _String.size());
	}
}

XString::~XString() XANADU_NOTHROW
{
	_memory_free();
}



//copy assignment
XString& XString::operator = (wchar_t _Char) XANADU_NOTHROW
{
	_memory_free();
	_string_append(_Char);
	return *this;
}

//copy assignment
XString& XString::operator = (const wchar_t* _String) XANADU_NOTHROW
{
	_memory_free();
	_string_append(_String, Xanadu::wcslen(_String));
	return *this;
}

//copy assignment
XString& XString::operator = (const WString& _String) XANADU_NOTHROW
{
	_memory_free();
	_string_append(_String.data(), _String.size());
	return *this;
}

//copy assignment
XString& XString::operator = (const XString& _String) XANADU_NOTHROW
{
	if(this != &_String)
	{
		_memory_free();
		_string_append(_String._string_data, _String._string_length);
	}
	return *this;
}

//move assignment
XString& XString::operator = (XString&& _String) XANADU_NOTHROW
{
	if(this != &_String)
	{
		_memory_free();
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



//memory operator new
void XString::_memory_malloc(int64S _Size) XANADU_NOTHROW
{
	_memory_free();
	if(_Size >= 0)
	{
		_string_data = XANADU_NEW wchar_t[_Size + XANADU_STRING_REDUNDANCY];
		if(_string_data)
		{
			_string_capacity = _Size + XANADU_STRING_REDUNDANCY;
			Xanadu::wmemset(_string_data, 0, _string_capacity);
		}
		else
		{
			_string_length = 0;
			_string_capacity = 0;
		}
	}
	else
	{
		_memory_malloc(0);
	}
}

//memory operator append
void XString::_memory_append(int64S _Size) XANADU_NOTHROW
{
	if(_Size > 0)
	{
		//保存原来的数据
		auto		_temp_malloc = false;
		auto		_temp_data = this->_string_data;
		auto		_temp_length = this->_string_length;
		//当容量减去长度小于要增加的数量时，分配一次内存
		if(this->_string_capacity - this->_string_length <= _Size)
		{
			this->_string_data = nullptr;
			this->_string_length = 0;
			_temp_malloc = true;
			_memory_free();
			_memory_malloc(_temp_length + _Size);
		}
		//当原来存在数据时，把数据拷贝回内存，并释放以前的块
		if(_temp_data && _temp_length > 0 && _temp_malloc)
		{
			Xanadu::wmemcpy(this->_string_data, _temp_data, _temp_length);
			this->_string_length = _temp_length;
			XANADU_DELETE_ARR(_temp_data);
		}
	}
}

//memory operator resize
void XString::_memory_resize(int64S _Size) XANADU_NOTHROW
{
	if(_Size > 0)
	{
		if(this->_string_length != _Size)
		{
			//保存原来的数据
			auto		_temp_data = this->_string_data;
			auto		_temp_length = this->_string_length > _Size ? _Size : this->_string_length;
			//重新申请一块内存
			_memory_free();
			_memory_malloc(_Size);
			//当原来存在数据时，把数据拷贝回内存，并释放以前的块
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

//memory operator delete
void XString::_memory_free() XANADU_NOTHROW
{
	XANADU_DELETE_ARR(_string_data);
	_string_data = nullptr;
	_string_length = 0LL;
	_string_capacity = 0LL;
}



//private append wchar_t
void XString::_string_append(wchar_t _Char) XANADU_NOTHROW
{
	_memory_append(1);
	this->_string_data[this->_string_length] = _Char;
	this->_string_length += 1;
}

//private append const wchar_t*
void XString::_string_append(const wchar_t* _String, int64S _Size) XANADU_NOTHROW
{
	if(_Size < 0LL)
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

//private search wchar_t
int64S XString::_string_search(wchar_t _Char, int64S _Begin, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	if(_Begin < 0)
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

//private search const wchar_t*
int64S XString::_string_search(const wchar_t* _String, int64S _Size, int64S _Begin, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	if(_Size < 0)
	{
		_Size = Xanadu::wcslen(_String);
	}
	if(_Begin < 0)
	{
		_Begin = 0;
	}
	auto		vPos = XString::npos;
	auto		vSubstr = static_cast<wchar_t*>(nullptr);
	if(this->_string_data && this->_string_length > _Begin && _Size > 0)
	{
		if(Xanadu::CaseInsensitive == _XCS)
		{
			auto		_temp_string = this->ToUpper();
			auto		_temp_substr = XString(_String, _Size).ToUpper();
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

//private insert wchar_t
void XString::_string_insert(int64S _Pos, wchar_t _Char) XANADU_NOTHROW
{
	if(_Pos < 0)
	{
		_Pos = 0;
	}
	if(this->_string_data && this->_string_length)
	{
		if(_Pos >= this->_string_length)
		{
			_string_append(_Char);
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
		_string_append(_Char);
	}
}

//private insert const wchar_t*
void XString::_string_insert(int64S _Pos, const wchar_t* _String, int64S _Size) XANADU_NOTHROW
{
	if(_Size < 0)
	{
		_Size = Xanadu::wcslen(_String);
	}
	if(_Pos < 0)
	{
		_Pos = 0;
	}
	if(nullptr == _String || 0LL == _Size)
	{
		return;
	}
	if(this->_string_data && this->_string_length)
	{
		if(_Pos >= this->_string_length)
		{
			_string_append(_String, _Size);
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
		_string_append(_String, _Size);
	}
}

//private remove
void XString::_string_remove(int64S _Pos, int64S _Length) XANADU_NOTHROW
{
	if(_Pos < 0)
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

//private compare
int64S XString::_string_compare(const wchar_t* _String, int64S _Size, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	if(Xanadu::CaseInsensitive == _XCS)
	{
		return Xanadu::wcscmp(this->ToUpper()._string_data, XString(_String, _Size).ToUpper()._string_data);
	}
	else
	{
		return Xanadu::wcscmp(this->_string_data, _String);
	}
}



//查找
XString::size_type XString::_find(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW
{
	auto		vReturn = npos;
	if(_Pos == npos)
	{
		_Pos = _string_length - 1;
	}
	for(; _Pos <= _string_length - _Length; ++_Pos)
	{
		if(operator[](_Pos) == *_String && _find_compare(_String, _Length, _Pos))
		{
			vReturn = _Pos;
			break;
		}
	}
	return vReturn;
}

//反向查找
XString::size_type XString::_rfind(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW
{
	auto		vReturn = npos;
	if(_Pos == npos || _Pos + _Length > _string_length + 1)
	{
		_Pos = _string_length - _Length + 1;
	}
	for(auto vIndex = _Pos; 0 <= vIndex; --vIndex)
	{
		if(operator[](vIndex) == *_String && _find_compare(_String, _Length, vIndex))
		{
			vReturn = vIndex;
			break;
		}
	}
	return vReturn;
}

//查找并比较
bool XString::_find_compare(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW
{
	for(auto vIndex = 1LL; vIndex < _Length; ++vIndex)
	{
		if(operator[](_Pos + vIndex) != *(_String + vIndex))
		{
			return false;
		}
	}
	return true;
}

//找到第一个
XString::size_type XString::_find_first_of(const wchar_t* _String, int64S _Length, size_type _Pos, bool _IsTrue) const XANADU_NOTHROW
{
	auto		vReturn = npos;
	if(_Pos == npos)
	{
		_Pos = _string_length - 1;
	}
	for(; _Pos < _string_length; ++_Pos)
	{
		if(_find_of_compare(_String, _Length, _Pos, _IsTrue))
		{
			vReturn = _Pos;
			break;
		}
	}
	return vReturn;
}

//找到最后一个
XString::size_type XString::_find_last_of(const wchar_t* _String, int64S _Length, size_type _Pos, bool _IsTrue) const XANADU_NOTHROW
{
	auto		vReturn = npos;
	if(_Pos == npos)
	{
		_Pos = _string_length - 1;
	}
	for(auto vIndex = _Pos; 0 <= vIndex; --vIndex)
	{
		if(_find_of_compare(_String, _Length, vIndex, _IsTrue))
		{
			vReturn = vIndex;
			break;
		}
	}
	return vReturn;
}

//查找/比较
bool XString::_find_of_compare(const wchar_t* _String, int64S _Length, size_type _Pos, bool _IsTrue) const XANADU_NOTHROW
{
	for(auto vIndex = 0; vIndex < _Length; ++vIndex)
	{
		if(operator[](_Pos) == *(_String + vIndex))
		{
			return _IsTrue;
		}
	}
	return !_IsTrue;
}




//cxx iterator private
XString::String_iterator_type XString::_ibegin() const XANADU_NOTHROW
{
	return String_iterator_type(_string_data, &_string_length, 0);
}

//cxx iterator private
XString::String_iterator_type XString::_end() const XANADU_NOTHROW
{
	return String_iterator_type(_string_data, &_string_length, _string_length);
}

//cxx iterator private
XString::String_iterator_type XString::_rbegin() const XANADU_NOTHROW
{
	return String_iterator_type(_string_data, &_string_length, _string_length - 1);
}

//cxx iterator private
int64S XString::_getLength(const XString::const_iterator _First, const XString::const_iterator _Second) XANADU_NOTHROW
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




//cxx iterator function
XString::iterator XString::begin() XANADU_NOTHROW
{
	return _ibegin();
}

//cxx iterator function
XString::const_iterator XString::begin() const XANADU_NOTHROW
{
	return _ibegin();
}

//cxx iterator function
XString::iterator XString::end() XANADU_NOTHROW
{
	return _end();
}

//cxx iterator function
XString::const_iterator XString::end() const XANADU_NOTHROW
{
	return _end();
}

//cxx iterator function
XString::const_iterator XString::cbegin() const XANADU_NOTHROW
{
	return _ibegin();
}

//cxx iterator function
XString::const_iterator XString::cend() const XANADU_NOTHROW
{
	return _end();
}

//cxx iterator function
XString::reverse_iterator XString::rbegin() XANADU_NOTHROW
{
	return _rbegin();
}

//cxx iterator function
XString::const_reverse_iterator XString::rbegin() const XANADU_NOTHROW
{
	return _rbegin();
}

//cxx iterator function
XString::reverse_iterator XString::rend() XANADU_NOTHROW
{
	return _end();
}

//cxx iterator function
XString::const_reverse_iterator XString::rend() const XANADU_NOTHROW
{
	return _end();
}

//cxx iterator function
XString::const_reverse_iterator XString::crbegin() const XANADU_NOTHROW
{
	return _rbegin();
}

//cxx iterator function
XString::const_reverse_iterator XString::crend() const XANADU_NOTHROW
{
	return _end();
}



//string buffer
wchar_t* XString::data() XANADU_NOTHROW
{
	return _string_data;
}

//string buffer
const wchar_t* XString::data() const XANADU_NOTHROW
{
	return _string_data;
}

//string length
int64S XString::length() const XANADU_NOTHROW
{
	return _string_length;
}

//string length
int64S XString::size() const XANADU_NOTHROW
{
	return length();
}

//buffer capacity
int64S XString::capacity() const XANADU_NOTHROW
{
	return _string_capacity;
}

//buffer clear
void XString::clear() XANADU_NOTHROW
{
	_memory_free();
}

//buffer is null
bool XString::empty() const XANADU_NOTHROW
{
	if(data() && size() > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//swap string
void XString::swap(XString& _String) XANADU_NOTHROW
{
	XString		vTemp = std::move(*this);
	*this = std::move(_String);
	_String = std::move(vTemp);
}

//max_size
int64S XString::max_size() const XANADU_NOTHROW
{
	return 0xFFFFFFFFFFLL;
}

//resize
void XString::resize(int64S _Length) XANADU_NOTHROW
{
	_memory_resize(_Length);
}

//resize
void XString::resize(int64S _Length, wchar_t _Char) XANADU_NOTHROW
{
	_memory_resize(_Length);
	for(auto vIndex = 0; vIndex < _string_length && _string_data; ++vIndex)
	{
		operator[](vIndex) = _Char;
	}
}




//元素访问 (1)
const wchar_t& XString::operator [] (int64S _Index) const
{
	return *(_string_data + _Index);
}

//元素访问 (2)
wchar_t& XString::operator [] (int64S _Index)
{
	return *(_string_data + _Index);
}

//元素访问 (3)
const wchar_t& XString::at(int64S _Index) const
{
	if(_Index < 0 || _string_length <= _Index)
	{
		throw;
	}
	return operator[](_Index);
}

//元素访问 (4)
wchar_t& XString::at(int64S _Index)
{
	if(_Index < 0 || _string_length <= _Index)
	{
		throw;
	}
	return operator[](_Index);
}

//元素访问 (5)
const wchar_t& XString::front() const
{
	return operator[](0);
}

//元素访问 (6)
wchar_t& XString::front()
{
	return operator[](0);
}

//元素访问 (7)
const wchar_t& XString::back() const
{
	return operator[](_string_length - 1);
}

//元素访问 (8)
wchar_t& XString::back()
{
	return operator[](_string_length - 1);
}


//cxx push_back (1)
void XString::push_back(wchar_t _Char) XANADU_NOTHROW
{
	append(_Char);
}

//cxx push_back (2)
void XString::push_back(const wchar_t* _String, int64S _Size) XANADU_NOTHROW
{
	append(_String, _Size);
}

//cxx push_back (3)
void XString::push_back(const XString& _String) XANADU_NOTHROW
{
	append(_String);
}

//cxx 删除最后一个元素
XString& XString::pop_back() XANADU_NOTHROW
{
	if(length())
	{
		operator[](length() - 1) = L'\0';
	}
	return *this;
}


//operator append (1)
XString& XString::operator += (wchar_t _Char) XANADU_NOTHROW
{
	wchar_t		vBuffer[2] = { 0 };
	vBuffer[0] = _Char;
	this->_string_append(vBuffer);
	return *this;
}

//operator append (2)
XString& XString::operator += (const wchar_t* _String) XANADU_NOTHROW
{
	this->_string_append(_String);
	return *this;
}

//operator append (3)
XString& XString::operator += (const XString& _String) XANADU_NOTHROW
{
	this->_string_append(_String._string_data, _String._string_length);
	return *this;
}




//比较运算符 (1)
bool XString::operator == (const wchar_t* _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String, Xanadu::wcslen(_String)) == 0;
}

//比较运算符 (1)
bool XString::operator == (const XString& _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String._string_data, _String._string_length) == 0;
}

//比较运算符 (2)
bool XString::operator != (const wchar_t* _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String, Xanadu::wcslen(_String)) != 0;
}

//比较运算符 (2)
bool XString::operator != (const XString& _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String._string_data, _String._string_length) != 0;
}

//比较运算符 (3)
bool XString::operator < (const wchar_t* _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String, Xanadu::wcslen(_String)) < 0;
}

//比较运算符 (3)
bool XString::operator < (const XString& _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String._string_data, _String._string_length) < 0;
}

//比较运算符 (4)
bool XString::operator > (const wchar_t* _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String, Xanadu::wcslen(_String)) > 0;
}

//比较运算符 (4)
bool XString::operator > (const XString& _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String._string_data, _String._string_length) > 0;
}

//比较运算符 (5)
bool XString::operator <= (const wchar_t* _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String, Xanadu::wcslen(_String)) <= 0;
}

//比较运算符 (5)
bool XString::operator <= (const XString& _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String._string_data, _String._string_length) <= 0;
}

//比较运算符 (6)
bool XString::operator >= (const wchar_t* _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String, Xanadu::wcslen(_String)) >= 0;
}

//比较运算符 (6)
bool XString::operator >= (const XString& _String) const XANADU_NOTHROW
{
	return this->_string_compare(_String._string_data, _String._string_length) >= 0;
}







//Convert : To ASCII
AString XString::ToAString() const XANADU_NOTHROW
{
	auto		vAString = AString("");
	if(data() && size())
	{
		auto	vCurrLocale = AString(Xanadu::setlocale(LC_ALL, NULL));

		Xanadu::setlocale(LC_ALL, "chs");

		auto	_DestSize = static_cast<unsigned int>(2 * size() + 1);
		auto	_Dest = XANADU_NEW char[_DestSize];
		Xanadu::memset(_Dest, 0, _DestSize);
		Xanadu::wcstombs(_Dest, data(), _DestSize);

		vAString = _Dest;
		XANADU_DELETE_ARR(_Dest);

		Xanadu::setlocale(LC_ALL, vCurrLocale.data());
	}
	return vAString;
}

//Convert : To UNICODE
WString XString::ToWString() const XANADU_NOTHROW
{
	return WString(data());
}

//Convert : To UTF-8
UString XString::ToUString() const XANADU_NOTHROW
{
	auto	vReturn = UString("");
	try
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> vConvert;
		vReturn = vConvert.to_bytes(data());
	}
	catch(const std::exception& _Except)
	{
		std::cerr << _Except.what() << std::endl;
	}
	return vReturn;
}

#ifdef XANADU_SUPPORT_QT
//Convert : To QString
QString XString::ToQString() const XANADU_NOTHROW
{
	return QString::fromStdWString(data());
}
#endif /// XANADU_SUPPORT_QT

//Convert : To Native String
NString XString::ToNString() const XANADU_NOTHROW
{
#ifdef XANADU_SYSTEM_WINDOWS
	return ToAString();
#else
	return ToUString();
#endif//XANADU_SYSTEM_WINDOWS
}

#ifdef XANADU_SUPPORT_QT
//Convert : To QByteArray
QByteArray XString::ToBytes() const XANADU_NOTHROW
{
	auto		vUString = this->ToUString();
	return QByteArray(vUString.data(), vUString.size());
}
#endif /// XANADU_SUPPORT_QT

//Convert : To URL Encode
UString XString::ToURL() const XANADU_NOTHROW
{
	auto		vDecode = ToUString();
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

//Convert:To ASCII
AString XANADUAPI XString::ToAString(const XString& _String) XANADU_NOTHROW
{
	return _String.ToAString();
}

//Convert:To UNICODE
WString XANADUAPI XString::ToWString(const XString& _String) XANADU_NOTHROW
{
	return _String.ToWString();
}

//Convert:To UTF-8
UString XANADUAPI XString::ToUString(const XString& _String) XANADU_NOTHROW
{
	return _String.ToUString();
}

#ifdef XANADU_SUPPORT_QT
//Convert : To QString
QString XANADUAPI XString::ToQString(const XString& _String) XANADU_NOTHROW
{
	return _String.ToQString();
}
#endif /// XANADU_SUPPORT_QT

//Convert : To Native String
NString XANADUAPI XString::ToNString(const XString& _String) XANADU_NOTHROW
{
	return _String.ToNString();
}

#ifdef XANADU_SUPPORT_QT
//Convert : To QByteArray
QByteArray XANADUAPI XString::ToBytes(const XString& _String) XANADU_NOTHROW
{
	return _String.ToBytes();
}
#endif /// XANADU_SUPPORT_QT

//Convert : To URL Encode
UString XANADUAPI XString::ToURL(const XString& _String) XANADU_NOTHROW
{
	return _String.ToURL();
}

//Convert : From ASCII
XString XANADUAPI XString::FromAString(const AString& _AString) XANADU_NOTHROW
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

//Convert : From UNICODE
XString XANADUAPI XString::FromWString(const WString& _XString) XANADU_NOTHROW
{
	return XString(_XString.data());
}

//Convert : From UTF-8
XString XANADUAPI XString::FromUString(const UString& _UString) XANADU_NOTHROW
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

//Convert:From Latin_1(ISO 8859-1)
XString XANADUAPI XString::FromLString(const LString& _LString) XANADU_NOTHROW
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
	return FromUString(_UString);
}

#ifdef XANADU_SUPPORT_QT
//Convert : From QString
XString XANADUAPI XString::FromQString(const QString& _QString) XANADU_NOTHROW
{
	return XString(_QString.toStdWString().data());
}
#endif /// XANADU_SUPPORT_QT

//Convert : From Native String
XString XANADUAPI XString::FromNString(const NString& _QString) XANADU_NOTHROW
{
#ifdef XANADU_SYSTEM_WINDOWS
	return XString::FromAString(_QString);
#else
	return XString::FromUString(_QString);
#endif//XANADU_SYSTEM_WINDOWS
}

#ifdef XANADU_SUPPORT_QT
//Convert : From QByteArray
XString XANADUAPI XString::FromBytes(const QByteArray& _QByteArray) XANADU_NOTHROW
{
	return XString::FromUString(UString(_QByteArray.data(), _QByteArray.size()));
}
#endif /// XANADU_SUPPORT_QT

//Convert:From URL Encode
XString XANADUAPI XString::FromURL(const UString& _URL) XANADU_NOTHROW
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
	return FromUString(vDecode);
}

//convert to upper
XString XString::ToUpper() const XANADU_NOTHROW
{
	if(data() && size())
	{
		auto		vUpper = WString(data());
		std::transform(vUpper.begin(), vUpper.end(), vUpper.begin(), ::towupper);
		return vUpper.data();
	}
	return *this;
}

//convert to lower
XString XString::ToLower() const XANADU_NOTHROW
{
	if(data() && size())
	{
		auto		vLower = WString(data());
		std::transform(vLower.begin(), vLower.end(), vLower.begin(), ::towlower);
		return vLower.data();
	}
	return *this;
}


//Format String (char* [%S]) (wchar_t* [%s][%ls][%ws])
XString XANADUAPI XString::Format(const wchar_t* _Format, ...) XANADU_NOTHROW
{
	auto		vString = XString();
	auto		vBuffer = XANADU_NEW wchar_t[XANADU_SIZE_KB * 10];
	if(vBuffer)
	{
		Xanadu::memset(vBuffer, 0, sizeof(wchar_t) * XANADU_SIZE_KB * 10);
		va_list		vArgs;
		va_start(vArgs, _Format);
#ifdef XANADU_SYSTEM_WINDOWS
		wvsprintf(vBuffer, _Format, vArgs);
#else
		vswprintf(vBuffer, XANADU_SIZE_KB * 10, _Format, vArgs);
#endif//XANADU_SYSTEM_WINDOWS
		va_end(vArgs);

		vString = vBuffer;
		XANADU_DELETE_ARR(vBuffer);
	}
	return vString;
}


//Sub String
XString XString::substr(size_type _Pos, int64S _Length) const XANADU_NOTHROW
{
	if(_Pos < _string_length)
	{
		return XString(_string_data + _Pos, _string_length > _Length ? _Length : XString::npos);
	}
	else
	{
		return XString();
	}
}

//Sub String
XString XString::left(size_type _Pos) const XANADU_NOTHROW
{
	return substr(0, _Pos);
}

//Sub String
XString XString::right(size_type _Pos) const XANADU_NOTHROW
{
	return substr(size() - _Pos, XString::npos);
}

//Middle String
XString XString::middle(const XString& _Left, const XString& _Right, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	auto		vPosLeft = _string_search(_Left._string_data, _Left._string_length, 0, _XCS);
	if(XString::npos != vPosLeft)
	{
		vPosLeft += _Left._string_length;
		auto		vPosRight = _string_search(_Right._string_data, _Right._string_length, vPosLeft, _XCS);
		if(XString::npos != vPosRight)
		{
			return substr(vPosLeft, vPosRight - vPosLeft);
		}
	}
	return XString();
}




//XString Find(1)
XString::size_type XString::find(const XString& _String, size_type _Pos) const XANADU_NOTHROW
{
	return _find(_String._string_data, _String._string_length, _Pos);
}

//XString Find(2)
XString::size_type XString::find(const wchar_t* _String, size_type _Pos) const XANADU_NOTHROW
{
	return _find(_String, Xanadu::wcslen(_String), _Pos);
}

//XString Find(3)
XString::size_type XString::find(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW
{
	return _find(_String, _Length, _Pos);
}

//XString Find(4)
XString::size_type XString::find(wchar_t _Char, size_type _Pos) const XANADU_NOTHROW
{
	return _find(&_Char, 1, _Pos);
}


//Reverse Find(1)
XString::size_type XString::rfind(const XString& _String, size_type _Pos) const XANADU_NOTHROW
{
	return _rfind(_String._string_data, _String._string_length, _Pos);
}

//Reverse Find(2)
XString::size_type XString::rfind(const wchar_t* _String, size_type _Pos) const XANADU_NOTHROW
{
	return  _rfind(_String, Xanadu::wcslen(_String), _Pos);
}

//Reverse Find(3)
XString::size_type XString::rfind(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW
{
	return _rfind(_String, _Length, _Pos);
}

//Reverse Find(4)
XString::size_type XString::rfind(wchar_t _Char, size_type _Pos) const XANADU_NOTHROW
{
	return _rfind(&_Char, 1, _Pos);
}


//Index Of (1)
XString::size_type XString::indexOf(const XString& _String, size_type _Pos) const XANADU_NOTHROW
{
	return _find_first_of(_String._string_data, _String._string_length, _Pos, true);
}

//Index Of (2)
XString::size_type XString::indexOf(const wchar_t* _String, size_type _Pos) const XANADU_NOTHROW
{
	return _find_first_of(_String, Xanadu::wcslen(_String), _Pos, true);
}

//Index Of (3)
XString::size_type XString::indexOf(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW
{
	return _find_first_of(_String, _Length, _Pos, true);
}

//Index Of (4)
XString::size_type XString::indexOf(wchar_t _Char, size_type _Pos) const XANADU_NOTHROW
{
	return _find_first_of(&_Char, 1, _Pos, true);
}


//Last Index Of (1)
XString::size_type XString::lastIndexOf(const XString& _String, size_type _Pos) const XANADU_NOTHROW
{
	return _find_last_of(_String._string_data, _String._string_length, _Pos, true);
}

//Last Index Of (2)
XString::size_type XString::lastIndexOf(const wchar_t* _String, size_type _Pos) const XANADU_NOTHROW
{
	return _find_last_of(_String, Xanadu::wcslen(_String), _Pos, true);
}

//Last Index Of (3)
XString::size_type XString::lastIndexOf(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW
{
	return _find_last_of(_String, _Length, _Pos, true);
}

//Last Index Of (4)
XString::size_type XString::lastIndexOf(wchar_t _Char, size_type _Pos) const XANADU_NOTHROW
{
	return _find_last_of(&_Char, 1, _Pos, true);
}




//contains substring
bool XString::contains(wchar_t _Char, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	wchar_t		vBuffer[2] = { _Char, 0 };
	return contains(vBuffer, 1, _XCS);
}

//contains substring
bool XString::contains(const wchar_t* _String, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return contains(_String, Xanadu::wcslen(_String), _XCS);
}

//contains substring
bool XString::contains(const wchar_t* _String, int64S _Size, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return _string_search(_String, _Size, 0, _XCS) != XString::npos ? true : false;
}

//contains substring
bool XString::contains(const XString& _String, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return contains(_String._string_data, _String._string_length, _XCS);
}





//compare substring
int XString::compare(wchar_t _Char, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	wchar_t		vBuffer[2] = { _Char, 0 };
	return compare(vBuffer, 1, _XCS);
}

//compare substring
int XString::compare(const wchar_t* _String, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return compare(_String, Xanadu::wcslen(_String), _XCS);
}

//compare substring
int XString::compare(const wchar_t* _String, int64S _Size, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return _string_compare(_String, _Size, _XCS);
}

//compare substring
int XString::compare(const XString& _String, Xanadu::CaseSensitivity _XCS) const XANADU_NOTHROW
{
	return compare(_String._string_data, _String._string_length, _XCS);
}




//append (1)
XString& XString::append(wchar_t _Char) XANADU_NOTHROW
{
	wchar_t		vBuffer[2] = { _Char, 0 };
	return append(vBuffer);
}

//append (2)
XString& XString::append(const wchar_t* _String, int64S _Size) XANADU_NOTHROW
{
	if(_Size < 0)
	{
		_Size = Xanadu::wcslen(_String);
	}
	this->_string_append(_String, _Size);
	return *this;
}

//append (3)
XString& XString::append(const XString& _String) XANADU_NOTHROW
{
	return append(_String._string_data, _String._string_length);
}




//string insert wchar_t
XString& XString::insert(size_type _Pos, wchar_t _Char) XANADU_NOTHROW
{
	_string_insert(_Pos, _Char);
	return *this;
}

//string insert wchar_t
XString& XString::insert(size_type _Pos, int64U _Count, wchar_t _Char) XANADU_NOTHROW
{
	for(auto vIndex = 0ULL; vIndex < _Count; ++vIndex)
	{
		_string_insert(_Pos, _Char);
	}
	return *this;
}

//string insert const wchar_t*
XString& XString::insert(size_type _Pos, const wchar_t* _String, int64S _Length) XANADU_NOTHROW
{
	_string_insert(_Pos, _String, _Length);
	return *this;
}

//string insert XString
XString& XString::insert(size_type _Pos, const XString& _String) XANADU_NOTHROW
{
	_string_insert(_Pos, _String._string_data, _String._string_length);
	return *this;
}



//string remove (1)
XString& XString::remove(size_type _Pos, int64S _Length) XANADU_NOTHROW
{
	_string_remove(_Pos, _Length);
	return *this;
}

//string remove (2)
XString& XString::remove(wchar_t _Char, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	auto		vPos = XString::npos;
	do
	{
		vPos = _string_search(_Char, vPos, _XCS);
		if(XString::npos != vPos)
		{
			_string_remove(vPos, 1);
			vPos += 1;
		}
	} while(XString::npos != vPos);
	return *this;
}

//string remove (3)
XString& XString::remove(const wchar_t* _String, int64S _Length, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	auto		vPos = XString::npos;
	if(_Length < 0)
	{
		_Length = Xanadu::wcslen(_String);
	}
	do
	{
		vPos = _string_search(_String, _Length, vPos, _XCS);
		if(XString::npos != vPos)
		{
			_string_remove(vPos, _Length);
		}
	} while(XString::npos != vPos);
	return *this;
}

//string remove (4)
XString& XString::remove(const XString& _String, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	return remove(_String._string_data, _String._string_length, _XCS);
}



//string replace
XString& XString::replace(size_type _Pos, int64S _Length, wchar_t _After) XANADU_NOTHROW
{
	remove(_Pos, _Length);
	insert(_Pos, _After);
	return *this;
}

//string replace
XString& XString::replace(size_type _Pos, int64S _Length, const wchar_t* _After, int64S _LengthA) XANADU_NOTHROW
{
	remove(_Pos, _Length);
	insert(_Pos, _After, _LengthA);
	return *this;
}

//string replace
XString& XString::replace(size_type _Pos, int64S _Length, const XString& _After) XANADU_NOTHROW
{
	remove(_Pos, _Length);
	insert(_Pos, _After._string_data, _After._string_length);
	return *this;
}

//string replace
XString& XString::replace(wchar_t _Before, wchar_t _After, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	wchar_t		vStringA[2] = { _After, 0 };
	return replace(_Before, XString(vStringA), _XCS);
}

//string replace
XString& XString::replace(wchar_t _Before, const wchar_t* _After, int64S _LengthA, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	wchar_t		vStringB[2] = { _Before, 0 };
	return replace(XString(vStringB), _After, _LengthA, _XCS);
}

//string replace
XString& XString::replace(wchar_t _Before, const XString& _After, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	wchar_t		vStringB[2] = { _Before, 0 };
	return replace(XString(vStringB), _After._string_data, _After._string_length, _XCS);
}

//string replace
XString& XString::replace(const wchar_t* _Before, int64S _LengthB, wchar_t _After, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	wchar_t		vStringA[2] = { _After, 0 };
	return replace(_Before, _LengthB, XString(vStringA), _XCS);
}

//string replace
XString& XString::replace(const wchar_t* _Before, int64S _LengthB, const wchar_t* _After, int64S _LengthA, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	auto		vPos = XString::npos;
	do
	{
		vPos = _string_search(_Before, _LengthB, vPos, _XCS);
		if(XString::npos != vPos)
		{
			remove(vPos, _LengthB);
			insert(vPos, _After, _LengthA);
			vPos += _LengthA;
		}
	} while(XString::npos != vPos);
	return *this;
}

//string replace
XString& XString::replace(const wchar_t* _Before, int64S _LengthB, const XString& _After, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	return replace(_Before, _LengthB, _After._string_data, _After._string_length, _XCS);
}

//string replace
XString& XString::replace(const XString& _Before, wchar_t _After, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	wchar_t		vStringA[2] = { _After, 0 };
	return replace(_Before._string_data, _Before._string_length, XString(vStringA), _XCS);
}

//string replace
XString& XString::replace(const XString& _Before, const wchar_t* _After, int64S _LengthA, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	return replace(_Before._string_data, _Before._string_length, _After, _LengthA, _XCS);
}

//string replace
XString& XString::replace(const XString& _Before, const XString& _After, Xanadu::CaseSensitivity _XCS) XANADU_NOTHROW
{
	return replace(_Before._string_data, _Before._string_length, _After._string_data, _After._string_length, _XCS);
}





//isSpace
bool XString::isSpace(wchar_t _Char) XANADU_NOTHROW
{
	if(_Char == L' ' || _Char == L'\t' || _Char == L'\n' || _Char == L'\v' || _Char == L'\f' || _Char == L'\r')
	{
		return true;
	}
	return false;
}

//simplified
XString XString::simplified() const XANADU_NOTHROW
{
	auto		vString = XString();
	auto		vNumber = 0;
	auto		vBegin = true;
	for(auto vIndex = 0LL; vIndex < size(); ++vIndex)
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





//string to int16S
int16S XString::ToInt16S(bool* _Ok, int _Base) const XANADU_NOTHROW
{
	return static_cast<int16S>(ToInt64S(_Ok, _Base));
}

//string to int16U
int16U XString::ToInt16U(bool* _Ok, int _Base) const XANADU_NOTHROW
{
	return static_cast<int16U>(ToInt64S(_Ok, _Base));
}

//string to int32S
int32S XString::ToInt32S(bool* _Ok, int _Base) const XANADU_NOTHROW
{
	return static_cast<int32S>(ToInt64S(_Ok, _Base));
}

//string to int32U
int32U XString::ToInt32U(bool* _Ok, int _Base) const XANADU_NOTHROW
{
	return static_cast<int32U>(ToInt64S(_Ok, _Base));
}

//string to int64S
int64S XString::ToInt64S(bool* _Ok, int _Base) const XANADU_NOTHROW
{
	auto		vEnd = static_cast<wchar_t*>(nullptr);
	auto		vValue = static_cast<int64S>(std::wcstol(data(), &vEnd, _Base));

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

//string to int64U
int64U XString::ToInt64U(bool* _Ok, int _Base) const XANADU_NOTHROW
{
	auto		vEnd = static_cast<wchar_t*>(nullptr);
	auto		vValue = static_cast<int64U>(std::wcstoul(data(), &vEnd, _Base));

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

//string to float
float XString::ToFloat(bool* _Ok) const XANADU_NOTHROW
{
	auto		vEnd = static_cast<wchar_t*>(nullptr);
	auto		vValue = static_cast<int64U>(std::wcstof(data(), &vEnd));

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

//string to double
double XString::ToDouble(bool* _Ok) const XANADU_NOTHROW
{
	auto		vEnd = static_cast<wchar_t*>(nullptr);
	auto		vValue = static_cast<int64U>(std::wcstod(data(), &vEnd));

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




//string form number
XString& XString::SetNumber(int16S _Value, int32S _Base) XANADU_NOTHROW
{
	SetNumber(static_cast<int64S>(_Value), _Base);
	return *this;
}

//string form number
XString& XString::SetNumber(int16U _Value, int32S _Base) XANADU_NOTHROW
{
	SetNumber(static_cast<int64U>(_Value), _Base);
	return *this;
}

//string form number
XString& XString::SetNumber(int32S _Value, int32S _Base) XANADU_NOTHROW
{
	SetNumber(static_cast<int64S>(_Value), _Base);
	return *this;
}

//string form number
XString& XString::SetNumber(int32U _Value, int32S _Base) XANADU_NOTHROW
{
	SetNumber(static_cast<int64U>(_Value), _Base);
	return *this;
}

//string form number
XString& XString::SetNumber(int64S _Value, int32S _Base) XANADU_NOTHROW
{
	if(2 <= _Base && _Base <= 36)
	{
		*this = std::to_wstring(_Value).data();
	}
	return *this;
}

//string form number
XString& XString::SetNumber(int64U _Value, int32S _Base) XANADU_NOTHROW
{
	if(2 <= _Base && _Base <= 36)
	{
		*this = std::to_wstring(_Value).data();
	}
	return *this;
}

//string form number
XString& XString::SetNumber(float _Value, char _Format, int32S _Prec) XANADU_NOTHROW
{
	XANADU_UNPARAMETER(_Format);
	XANADU_UNPARAMETER(_Prec);

	*this = std::to_wstring(_Value).data();
	return *this;
}

//string form number
XString& XString::SetNumber(double _Value, char _Format, int32S _Prec) XANADU_NOTHROW
{
	XANADU_UNPARAMETER(_Format);
	XANADU_UNPARAMETER(_Prec);

	*this = std::to_wstring(_Value).data();
	return *this;
}




//string form number
XString XString::number(int16S _Value, int32S _Base) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.SetNumber(_Value, _Base);
	return vValue;
}

//string form number
XString XString::number(int16U _Value, int32S _Base) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.SetNumber(_Value, _Base);
	return vValue;
}

//string form number
XString XString::number(int32S _Value, int32S _Base) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.SetNumber(_Value, _Base);
	return vValue;
}

//string form number
XString XString::number(int32U _Value, int32S _Base) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.SetNumber(_Value, _Base);
	return vValue;
}

//string form number
XString XString::number(int64S _Value, int32S _Base) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.SetNumber(_Value, _Base);
	return vValue;
}

//string form number
XString XString::number(int64U _Value, int32S _Base) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.SetNumber(_Value, _Base);
	return vValue;
}

//string form number
XString XString::number(double _Value, char _Format, int32S _Prec) XANADU_NOTHROW
{
	auto		vValue = XString();
	vValue.SetNumber(_Value, _Format, _Prec);
	return vValue;
}












//XString Swap
XANADU_CORE_EXPORT void swap(XString& _String1, XString& _String2) XANADU_NOTHROW
{
	_String1.swap(_String2);
}

//XString Merged
XANADU_CORE_EXPORT XString operator+ (const XString& _StringLeft, const XString& _StringRight) XANADU_NOTHROW
{
	XString		vReturn = _StringLeft;
	vReturn += _StringRight;
	return vReturn;
}

//XString Merged
XANADU_CORE_EXPORT XString operator+ (const XString& _StringLeft, const wchar_t* _StringRight) XANADU_NOTHROW
{
	XString		vReturn = _StringLeft;
	vReturn += _StringRight;
	return vReturn;
}

//XString Merged
XANADU_CORE_EXPORT XString operator+ (const wchar_t* _StringLeft, const XString& _StringRight) XANADU_NOTHROW
{
	XString		vReturn = _StringLeft;
	vReturn += _StringRight;
	return vReturn;
}

//XString Merged
XANADU_CORE_EXPORT XString operator+ (const XString& _StringLeft, wchar_t _CharRight) XANADU_NOTHROW
{
	XString		vReturn = _StringLeft;
	vReturn += _CharRight;
	return vReturn;
}

//XString Merged
XANADU_CORE_EXPORT XString operator+ (wchar_t _CharLeft, const XString& _StringRight) XANADU_NOTHROW
{
	XString		vReturn = _StringRight;
	vReturn += _CharLeft;
	return vReturn;
}

//XString Out
XANADU_CORE_EXPORT std::wostream& operator<< (std::wostream& _OStream, const XString& _String) XANADU_NOTHROW
{
	for(auto vIndex = 0LL; vIndex < _String.length(); ++vIndex)
	{
		_OStream << _String[vIndex];
	}
	return _OStream;
}

//XString In
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

//XString in line
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

//XString in line
XANADU_CORE_EXPORT std::wistream& getline(std::wistream& _IStream, XString& _String) XANADU_NOTHROW
{
	return getline(_IStream, _String, L'\n');
}

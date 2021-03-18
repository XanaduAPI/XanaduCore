#ifndef			_XANADU_CORE_STRING_H_
#define			_XANADU_CORE_STRING_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XAllocator.h>
#include <XanaduCore/XByteArray.h>

// <summary>
// Here are some string type name definitions for the Xanadu series
// </summary>
typedef			wchar_t							XChar;
typedef			std::string						AString;
typedef			std::wstring						WString;
typedef			std::string						UString;
typedef			std::string						LString;
#ifdef XANADU_SYSTEM_WINDOWS
typedef			AString							NString;
#else
typedef			UString							NString;
#endif// XANADU_SYSTEM_WINDOWS

// The type of the Xanadu string
#define			XSTRING(_String)					L ## _String


// <summary>
// This string processing expects a better memory allocator
// I don't know how std::wstring makes Microsoft Visual Studio display only character contents and not member variables
// The iterator for this string class is not tested
// </summary>
class XANADU_CORE_EXPORT XString
{
public:
	using						size_type = XAllocator::size_type;
	static const size_type				npos = XAllocator::npos;

private:
	wchar_t*					_string_data = nullptr;
	size_type					_string_length = 0;
	size_type					_string_capacity = 0;

public:
	// String_iterator_type
	struct String_iterator_type
	{
		wchar_t* first;
		const size_type* size;
		size_type					pos;

		String_iterator_type(wchar_t* _First = nullptr, const size_type* _Size = nullptr, size_type _Pos = 0) : first(_First), size(_Size), pos(_Pos)
		{
		};
	};

	// const_iterator
	class const_iterator
	{
	public:
		const_iterator();
		const_iterator(String_iterator_type p);

		const wchar_t& operator* () const;
		const wchar_t& operator[] (int) const;
		const_iterator& operator++ ();
		const_iterator operator++ (int);
		const_iterator& operator-- ();
		const_iterator operator-- (int);

		bool operator == (const const_iterator& rhs) const;
		bool operator != (const const_iterator& rhs) const;

		const_iterator operator+ (size_type i);
		const_iterator operator- (size_type i);

	protected:
		String_iterator_type current;

		wchar_t& retrieve() const;
		void _increment();
		void _decrement();
		wchar_t& _randomAccess(size_type i) const;
		void _add(const_iterator& toReturn, size_type i);
		void _subtract(const_iterator& toReturn, size_type i);

		friend class XString;
	};

	// iterator
	class iterator : public const_iterator
	{
		using _myBase = const_iterator;
		friend class XString;
	public:
		iterator();
		iterator(String_iterator_type p);

		wchar_t& operator* ();
		const wchar_t& operator* () const;
		wchar_t& operator[] (int);
		const wchar_t& operator[] (int) const;

		iterator& operator++ ();
		iterator operator++ (int);
		iterator& operator-- ();
		iterator operator-- (int);
		iterator operator+ (size_type i);
		iterator operator- (size_type i);

	};

	using const_pointer = const_iterator;
	using pointer = iterator;

	// const_reverse_iterator
	class const_reverse_iterator : public const_iterator
	{
		using _myBase = const_iterator;
		friend class XString;
	public:
		const_reverse_iterator();
		const_reverse_iterator(String_iterator_type p);

		const wchar_t& operator* () const;
		const wchar_t& operator[] (int) const;

		const_reverse_iterator& operator++ ();
		const_reverse_iterator operator++ (int);
		const_reverse_iterator& operator-- ();
		const_reverse_iterator operator-- (int);

		const_reverse_iterator operator+ (size_type i);
		const_reverse_iterator operator- (size_type i);

	protected:
		void _increment();
		void _decrement();
		void _add(const_reverse_iterator& toReturn, size_type i);
		void _subtract(const_reverse_iterator& toReturn, size_type i);

	};

	// reverse_iterator
	class reverse_iterator : public const_reverse_iterator
	{
		using _myBase = const_reverse_iterator;
		friend class XString;
	public:
		reverse_iterator();
		reverse_iterator(String_iterator_type p);

		wchar_t& operator* ();
		const wchar_t& operator* () const;
		wchar_t& operator[] (int);
		const wchar_t& operator[] (int) const;

		reverse_iterator& operator++ ();
		reverse_iterator operator++ (int);
		reverse_iterator& operator-- ();
		reverse_iterator operator-- (int);
		reverse_iterator operator+ (size_type i);
		reverse_iterator operator- (size_type i);

	};

	using const_reverse_pointer = const_reverse_iterator;
	using reverse_pointer = reverse_iterator;

public:
	XString() noexcept;

	XString(wchar_t _Char) noexcept;

	XString(const wchar_t* _String) noexcept;

	XString(const wchar_t* _String, size_type _Length) noexcept;

	XString(const XString& _String) noexcept;

	XString(XString&& _String) noexcept;

	XString(const WString& _String) noexcept;

	virtual ~XString() noexcept;

public:
	// copy assignment
	virtual XString& operator = (wchar_t _Char) noexcept;

	// copy assignment
	virtual XString& operator = (const wchar_t* _String) noexcept;

	// copy assignment
	virtual XString& operator = (const WString& _String) noexcept;

	// copy assignment
	virtual XString& operator = (const XString& _String) noexcept;

	// move assignment
	virtual XString& operator = (XString&& _String) noexcept;

private:
	// memory operator new
	virtual void _memory_malloc(size_type _Size) noexcept;

	// memory operator append
	virtual void _memory_append(size_type _Size) noexcept;

	// memory operator resize
	virtual void _memory_resize(size_type _Size) noexcept;

	// memory operator delete
	virtual void _memory_free() noexcept;

private:
	// private append wchar_t
	virtual void _string_append(wchar_t _Char) noexcept;

	// private append const wchar_t*
	virtual void _string_append(const wchar_t* _String, size_type _Size = XString::npos) noexcept;

	// private search wchar_t
	virtual size_type _string_search(wchar_t _Char, size_type _Begin = 0LL, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// private search const wchar_t*
	virtual size_type _string_search(const wchar_t* _String, size_type _Size = XString::npos, size_type _Begin = 0LL, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// private insert wchar_t
	virtual void _string_insert(size_type _Pos, wchar_t _Char) noexcept;

	// private insert const wchar_t*
	virtual void _string_insert(size_type _Pos, const wchar_t* _String, size_type _Size = XString::npos) noexcept;

	// private remove
	virtual void _string_remove(size_type _Pos, size_type _Length) noexcept;

	// private compare
	virtual int32S _string_compare(const wchar_t* _String, size_type _Size = XString::npos, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

private:
	// 查找
	virtual size_type _find(const wchar_t* _String, size_type _Length, size_type _Pos) const noexcept;

	// 反向查找
	virtual size_type _rfind(const wchar_t* _String, size_type _Length, size_type _Pos) const noexcept;

	// 查找并比较
	virtual bool _compare(const wchar_t* _String, size_type _Length, size_type _Pos) const noexcept;

private:
	// cxx iterator private
	virtual String_iterator_type _ibegin() const noexcept;

	// cxx iterator private
	virtual XString::String_iterator_type _rbegin() const noexcept;

	// cxx iterator private
	virtual String_iterator_type _end() const noexcept;

	// cxx iterator private
	virtual size_type _getLength(const const_iterator _First, const const_iterator _Second) noexcept;

public:
	// cxx iterator function
	virtual iterator begin() noexcept;

	// cxx iterator function
	virtual const_iterator begin() const noexcept;

	// cxx iterator function
	virtual iterator end() noexcept;

	// cxx iterator function
	virtual const_iterator end() const noexcept;

	// cxx iterator function
	virtual const_iterator cbegin() const noexcept;

	// cxx iterator function
	virtual const_iterator cend() const noexcept;

	// cxx iterator function
	virtual reverse_iterator rbegin() noexcept;

	// cxx iterator function
	virtual const_reverse_iterator rbegin() const noexcept;

	// cxx iterator function
	virtual reverse_iterator rend() noexcept;

	// cxx iterator function
	virtual const_reverse_iterator rend() const noexcept;

	// cxx iterator function
	virtual const_reverse_iterator crbegin() const noexcept;

	// cxx iterator function
	virtual const_reverse_iterator crend() const noexcept;

public:
	// string buffer
	virtual wchar_t* data() noexcept;

	// string buffer
	virtual const wchar_t* data() const noexcept;

	// string length
	virtual size_type length() const noexcept;

	// string length
	virtual size_type size() const noexcept;

	// buffer capacity
	virtual size_type capacity() const noexcept;

	// buffer clear
	virtual void clear() noexcept;

	// buffer is null
	virtual bool empty() const noexcept;

	// Check if there is a value
	virtual bool exist() const noexcept;

	// swap string
	virtual void swap(XString& _String) noexcept;

	// max_size
	virtual size_type max_size() const noexcept;

	// resize
	virtual void resize(size_type _Length) noexcept;

	// resize
	virtual void resize(size_type _Length, wchar_t _Char) noexcept;

	// Truncates the byte array at index position pos. If pos is beyond the end of the array, nothing happens.
	virtual void truncate(size_type _Index) noexcept;

public:
	// 元素访问 (1)
	const wchar_t& operator [] (size_type _Index) const;

	// 元素访问 (2)
	wchar_t& operator [] (size_type _Index);

	// 元素访问 (3)
	const wchar_t& at(size_type _Index) const;

	// 元素访问 (4)
	wchar_t& at(size_type _Index);

	// 元素访问 (5)
	const wchar_t& front() const;

	// 元素访问 (6)
	wchar_t& front();

	// 元素访问 (7)
	const wchar_t& back() const;

	// 元素访问 (8)
	wchar_t& back();

public:
	// cxx push_back (1)
	virtual void push_back(wchar_t _Char) noexcept;

	// cxx push_back (2)
	virtual void push_back(const wchar_t* _String, size_type _Size = XString::npos) noexcept;

	// cxx push_back (3)
	virtual void push_back(const XString& _String) noexcept;

	// cxx 删除最后一个元素
	virtual XString& pop_back() noexcept;

public:
	// operator append (1)
	virtual XString& operator += (wchar_t _Char) noexcept;

	// operator append (2)
	virtual XString& operator += (const wchar_t* _String) noexcept;

	// operator append (3)
	virtual XString& operator += (const XString& _String) noexcept;

public:
	// 比较运算符 (1)
	virtual bool operator == (const wchar_t* _String)const  noexcept;

	// 比较运算符 (1)
	virtual bool operator == (const XString& _String)const  noexcept;

	// 比较运算符 (2)
	virtual bool operator != (const wchar_t* _String)const  noexcept;

	// 比较运算符 (2)
	virtual bool operator != (const XString& _String)const  noexcept;

	// 比较运算符 (3)
	virtual bool operator < (const wchar_t* _String)const  noexcept;

	// 比较运算符 (3)
	virtual bool operator < (const XString& _String)const  noexcept;

	// 比较运算符 (4)
	virtual bool operator > (const wchar_t* _String) const  noexcept;

	// 比较运算符 (4)
	virtual bool operator > (const XString& _String) const  noexcept;

	// 比较运算符 (5)
	virtual bool operator <= (const wchar_t* _String) const  noexcept;

	// 比较运算符 (5)
	virtual bool operator <= (const XString& _String) const  noexcept;

	// 比较运算符 (6)
	virtual bool operator >= (const wchar_t* _String) const  noexcept;

	// 比较运算符 (6)
	virtual bool operator >= (const XString& _String) const  noexcept;

public:
	// Convert : To ASCII
	virtual AString toAString() const noexcept;

	// Convert : To UNICODE
	virtual WString toWString() const noexcept;

	// Convert : To UTF-8
	virtual UString toUString() const noexcept;

	// Convert : To Native String
	virtual NString toNString() const noexcept;

	// Convert : To XByteArray
	virtual XByteArray toBytes() const noexcept;

	// Convert : To URL encode
	virtual UString toURL() const noexcept;

	// Convert : To ASCII
	static AString XANADUAPI toAString(const XString& _String) noexcept;

	// Convert : To UNICODE
	static WString XANADUAPI toWString(const XString& _String) noexcept;

	// Convert : To UTF-8
	static UString XANADUAPI toUString(const XString& _String) noexcept;

	// Convert : To Native String
	static NString XANADUAPI toNString(const XString& _String) noexcept;

	// Convert : To XByteArray
	static XByteArray XANADUAPI toBytes(const XString& _String) noexcept;

	// Convert : To URL encode
	static UString XANADUAPI toURL(const XString& _String) noexcept;

	// Convert:From ASCII
	static XString XANADUAPI fromAString(const AString& _AString) noexcept;

	// Convert:From UNICODE
	static XString XANADUAPI fromWString(const WString& _WString) noexcept;

	// Convert:From UTF-8
	static XString XANADUAPI fromUString(const UString& _UString) noexcept;

	// Convert : From Native String
	static XString XANADUAPI fromNString(const NString& _NString) noexcept;

	// Convert : From XByteArray
	static XString XANADUAPI fromBytes(const XByteArray& _Bytes) noexcept;

	// Convert:From URL encode
	static XString XANADUAPI fromURL(const UString& _URL) noexcept;

	// convert to upper
	virtual XString toUpper() const noexcept;

	// convert to lower
	virtual XString toLower() const noexcept;

public:
	// Format String (char* [%S]) (wchar_t* [%s][%ls][%ws])
	static XString XANADUAPI format(const wchar_t* _Format, ...) noexcept;

public:
	// Sub String
	virtual XString substr(size_type _Pos = 0, size_type _Length = XString::npos) const noexcept;

	// Sub String
	virtual XString left(size_type _Pos = XString::npos) const noexcept;

	// Sub String
	virtual XString right(size_type _Pos = 0) const noexcept;

	// Retrieve the middle data by length
	virtual XString mid(size_type _Pos, size_type _Size = XString::npos) const noexcept;

	// Middle String
	virtual XString middle(const XString& _Left, const XString& _Right, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

public:
	// Check if the head is the same
	virtual bool startsWith(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// Check if the head is the same
	virtual bool startsWith(const wchar_t* _Memory, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// Check if the head is the same
	virtual bool startsWith(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// Check if the tails are the same
	virtual bool endsWith(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// Check if the tails are the same
	virtual bool endsWith(const wchar_t* _Memory, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// Check if the tails are the same
	virtual bool endsWith(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

public:
	// find (1)
	virtual size_type find(const XString& _String, size_type _Pos = 0) const noexcept;

	// find (2)
	virtual size_type find(const wchar_t* _String, size_type _Pos = 0) const noexcept;

	// find (3)
	virtual size_type find(const wchar_t* _String, size_type _Length, size_type _Pos) const noexcept;

	// find (4)
	virtual size_type find(wchar_t _Char, size_type _Pos = 0) const noexcept;


	// Reverse find (1)
	virtual size_type rfind(const XString& _String, size_type _Pos = npos) const noexcept;

	// Reverse find (2)
	virtual size_type rfind(const wchar_t* _String, size_type _Pos = npos) const noexcept;

	// Reverse find (3)
	virtual size_type rfind(const wchar_t* _String, size_type _Length, size_type _Pos) const noexcept;

	// Reverse find (4)
	virtual size_type rfind(wchar_t _Char, size_type _Pos = npos) const noexcept;


	// Index Of (1)
	virtual size_type indexOf(const XString& _String, size_type _Pos = 0) const noexcept;

	// Index Of (2)
	virtual size_type indexOf(const wchar_t* _String, size_type _Pos = 0) const noexcept;

	// Index Of (3)
	virtual size_type indexOf(const wchar_t* _String, size_type _Length, size_type _Pos) const noexcept;

	// Index Of (4)
	virtual size_type indexOf(wchar_t _Char, size_type _Pos = 0) const noexcept;


	// Last Index Of (1)
	virtual size_type lastIndexOf(const XString& _String, size_type _Pos = XString::npos) const noexcept;

	// Last Index Of (2)
	virtual size_type lastIndexOf(const wchar_t* _String, size_type _Pos = XString::npos) const noexcept;

	// Last Index Of (3)
	virtual size_type lastIndexOf(const wchar_t* _String, size_type _Length, size_type _Pos) const noexcept;

	// Last Index Of (4)
	virtual size_type lastIndexOf(wchar_t _Char, size_type _Pos = XString::npos) const noexcept;

public:
	// contains substring
	virtual bool contains(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// contains substring
	virtual bool contains(const wchar_t* _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// contains substring
	virtual bool contains(const wchar_t* _String, size_type _Size, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// contains substring
	virtual bool contains(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

public:
	// compare substring
	virtual int compare(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// compare substring
	virtual int compare(const wchar_t* _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// compare substring
	virtual int compare(const wchar_t* _String, size_type _Size, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// compare substring
	virtual int compare(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

public:
	// append (1)
	virtual XString& append(wchar_t _Char) noexcept;

	// append (2)
	virtual XString& append(const wchar_t* _String, size_type _Size = XString::npos) noexcept;

	// append (3)
	virtual XString& append(const XString& _String) noexcept;

public:
	// string insert wchar_t
	virtual XString& insert(size_type _Pos, wchar_t _Char) noexcept;

	// string insert wchar_t
	virtual XString& insert(size_type _Pos, size_type _Count, wchar_t _Char) noexcept;

	// string insert const wchar_t*
	virtual XString& insert(size_type _Pos, const wchar_t* _String, size_type _Length) noexcept;

	// string insert XString
	virtual XString& insert(size_type _Pos, const XString& _String) noexcept;

public:
	// string remove (1)
	virtual XString& remove(size_type _Pos, size_type _Length) noexcept;

	// string remove (2)
	virtual XString& remove(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// string remove (3)
	virtual XString& remove(const wchar_t* _String, size_type _Length = XString::npos, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// string remove (4)
	virtual XString& remove(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

public:
	// string replace
	virtual XString& replace(size_type _Pos, size_type _Length, wchar_t _After) noexcept;

	// string replace
	virtual XString& replace(size_type _Pos, size_type _Length, const wchar_t* _After, size_type _LengthA) noexcept;

	// string replace
	virtual XString& replace(size_type _Pos, size_type _Length, const XString& _After) noexcept;

	// string replace
	virtual XString& replace(wchar_t _Before, wchar_t _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// string replace
	virtual XString& replace(wchar_t _Before, const wchar_t* _After, size_type _LengthA, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// string replace
	virtual XString& replace(wchar_t _Before, const XString& _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// string replace
	virtual XString& replace(const wchar_t* _Before, size_type _LengthB, wchar_t _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// string replace
	virtual XString& replace(const wchar_t* _Before, size_type _LengthB, const wchar_t* _After, size_type _LengthA, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// string replace
	virtual XString& replace(const wchar_t* _Before, size_type _LengthB, const XString& _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// string replace
	virtual XString& replace(const XString& _Before, wchar_t _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// string replace
	virtual XString& replace(const XString& _Before, const wchar_t* _After, size_type _LengthA, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// string replace
	virtual XString& replace(const XString& _Before, const XString& _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

public:
	// isSpace
	static bool isSpace(wchar_t _Char) noexcept;

	// simplified
	virtual XString simplified() const noexcept;

public:
	// string to int16S
	virtual int16S  toInt16S(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to int16U
	virtual int16U toInt16U(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to int32S
	virtual int32S toInt32S(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to int32U
	virtual int32U toInt32U(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to int64S
	virtual size_type toInt64S(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to size_type
	virtual size_type toInt64U(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to float
	virtual float toFloat(bool* _Ok = nullptr) const noexcept;

	// string to double
	virtual double toDouble(bool* _Ok = nullptr) const noexcept;

public:
	// string form number
	virtual XString& setNumber(int16S _Value, int32S _Base = 10) noexcept;

	// string form number
	virtual XString& setNumber(int16U _Value, int32S _Base = 10) noexcept;

	// string form number
	virtual XString& setNumber(int32S _Value, int32S _Base = 10) noexcept;

	// string form number
	virtual XString& setNumber(int32U _Value, int32S _Base = 10) noexcept;

	// string form number
	virtual XString& setNumber(int64S _Value, int32S _Base = 10) noexcept;

	// string form number
	virtual XString& setNumber(int64U _Value, int32S _Base = 10) noexcept;

	// string form number
	virtual XString& setNumber(float _Value, char _Format = 'g', int32S _Prec = 6) noexcept;

	// string form number
	virtual XString& setNumber(double _Value, char _Format = 'g', int32S _Prec = 6) noexcept;

public:
	// string form number
	static XString number(int16S _Value, int32S _Base = 10) noexcept;

	// string form number
	static XString number(int16U _Value, int32S _Base = 10) noexcept;

	// string form number
	static XString number(int32S _Value, int32S _Base = 10) noexcept;

	// string form number
	static XString number(int32U _Value, int32S _Base = 10) noexcept;

	// string form number
	static XString number(int64S _Value, int32S _Base = 10) noexcept;

	// string form number
	static XString number(size_type _Value, int32S _Base = 10) noexcept;

	// string form number
	static XString number(double _Value, char _Format = 'g', int32S _Prec = 6) noexcept;
};

// XString Swap
XANADU_CORE_EXPORT void swap(XString& _String1, XString& _String2) noexcept;

// XString Merged
XANADU_CORE_EXPORT XString operator + (const XString& _StringLeft, const XString& _StringRight) noexcept;

// XString Merged
XANADU_CORE_EXPORT XString operator + (const XString& _StringLeft, const wchar_t* _StringRight) noexcept;

// XString Merged
XANADU_CORE_EXPORT XString operator + (const wchar_t* _StringLeft, const XString& _StringRight) noexcept;

// XString Merged
XANADU_CORE_EXPORT XString operator + (const XString& _StringLeft, wchar_t _CharRight) noexcept;

// XString Merged
XANADU_CORE_EXPORT XString operator + (wchar_t _CharLeft, const XString& _StringRight) noexcept;

// XString Out
XANADU_CORE_EXPORT std::wostream& operator << (std::wostream& _OStream, const XString& _String) noexcept;

// XString In
XANADU_CORE_EXPORT std::wistream& operator >> (std::wistream& _IStream, XString& _String) noexcept;

// XString in line
XANADU_CORE_EXPORT std::wistream& getline(std::wistream& _IStream, XString& _String, wchar_t _Delim) noexcept;

// XString in line
XANADU_CORE_EXPORT std::wistream& getline(std::wistream& _IStream, XString& _String) noexcept;

#endif// _XANADU_CORE_STRING_H_

#ifndef			_XANADU_CORE_STRING_H_
#define			_XANADU_CORE_STRING_H_

#include <XanaduCore/XanaduCoreHeader.h>
#include <XanaduCore/XanaduCoreByteArray.h>

/// <summary>
/// Here are some string type name definitions for the Xanadu series
/// </summary>
typedef			wchar_t							XChar;
typedef			std::string						AString;
typedef			std::wstring						WString;
typedef			std::string						UString;
typedef			std::string						LString;
#ifdef XANADU_SYSTEM_WINDOWS
typedef			AString							NString;
#else
typedef			UString							NString;
#endif/// XANADU_SYSTEM_WINDOWS

/// The type of the Xanadu string
#define			XSTRING(_String)					L ## _String


/// <summary>
/// This string processing expects a better memory allocator
/// I don't know how std::wstring makes Microsoft Visual Studio display only character contents and not member variables
/// The iterator for this string class is not tested
/// </summary>
class XANADU_CORE_EXPORT XString
{
private:
	wchar_t*					_string_data = nullptr;
	int64S						_string_length = 0;
	int64S						_string_capacity = 0;

public:
	using						size_type = int64S;
	static const int64S				npos = -1LL;

public:
	//String_iterator_type
	struct String_iterator_type
	{
		wchar_t* first;
		const int64S* size;
		int64S					pos;

		String_iterator_type(wchar_t* _First = nullptr, const int64S* _Size = nullptr, int64S _Pos = 0) : first(_First), size(_Size), pos(_Pos)
		{
		};
	};

	//const_iterator
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

	//iterator
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

	//const_reverse_iterator
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

	//reverse_iterator
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
	XString() XANADU_NOTHROW;

	XString(wchar_t _Char) XANADU_NOTHROW;

	XString(const wchar_t* _String) XANADU_NOTHROW;

	XString(const wchar_t* _String, int64S _Length) XANADU_NOTHROW;

	XString(const XString& _String) XANADU_NOTHROW;

	XString(XString&& _String) XANADU_NOTHROW;

	XString(const WString& _String) XANADU_NOTHROW;

	virtual ~XString() XANADU_NOTHROW;

public:
	//copy assignment
	virtual XString& operator = (wchar_t _Char) XANADU_NOTHROW;

	//copy assignment
	virtual XString& operator = (const wchar_t* _String) XANADU_NOTHROW;

	//copy assignment
	virtual XString& operator = (const WString& _String) XANADU_NOTHROW;

	//copy assignment
	virtual XString& operator = (const XString& _String) XANADU_NOTHROW;

	//move assignment
	virtual XString& operator = (XString&& _String) XANADU_NOTHROW;

private:
	//memory operator new
	virtual void _memory_malloc(int64S _Size) XANADU_NOTHROW;

	//memory operator append
	virtual void _memory_append(int64S _Size) XANADU_NOTHROW;

	//memory operator resize
	virtual void _memory_resize(int64S _Size) XANADU_NOTHROW;

	//memory operator delete
	virtual void _memory_free() XANADU_NOTHROW;

private:
	//private append wchar_t
	virtual void _string_append(wchar_t _Char) XANADU_NOTHROW;

	//private append const wchar_t*
	virtual void _string_append(const wchar_t* _String, int64S _Size = XString::npos) XANADU_NOTHROW;

	//private search wchar_t
	virtual int64S _string_search(wchar_t _Char, int64S _Begin = 0LL, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

	//private search const wchar_t*
	virtual int64S _string_search(const wchar_t* _String, int64S _Size = XString::npos, int64S _Begin = 0LL, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

	//private insert wchar_t
	virtual void _string_insert(int64S _Pos, wchar_t _Char) XANADU_NOTHROW;

	//private insert const wchar_t*
	virtual void _string_insert(int64S _Pos, const wchar_t* _String, int64S _Size = XString::npos) XANADU_NOTHROW;

	//private remove
	virtual void _string_remove(int64S _Pos, int64S _Length) XANADU_NOTHROW;

	//private compare
	virtual int64S _string_compare(const wchar_t* _String, int64S _Size = XString::npos, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

private:
	//查找
	virtual size_type _find(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW;

	//反向查找
	virtual size_type _rfind(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW;

	//查找并比较
	virtual bool _find_compare(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW;

	//找到第一个
	virtual size_type _find_first_of(const wchar_t* _String, int64S _Length, size_type _Pos, bool _IsTrue) const XANADU_NOTHROW;

	//找到最后一个
	virtual size_type _find_last_of(const wchar_t* _String, int64S _Length, size_type _Pos, bool _IsTrue) const XANADU_NOTHROW;

	//查找/比较
	virtual bool _find_of_compare(const wchar_t* _String, int64S _Length, size_type _Pos, bool _IsTrue) const XANADU_NOTHROW;

private:
	//cxx iterator private
	virtual String_iterator_type _ibegin() const XANADU_NOTHROW;

	//cxx iterator private
	virtual XString::String_iterator_type _rbegin() const XANADU_NOTHROW;

	//cxx iterator private
	virtual String_iterator_type _end() const XANADU_NOTHROW;

	//cxx iterator private
	virtual int64S _getLength(const const_iterator _First, const const_iterator _Second) XANADU_NOTHROW;

public:
	//cxx iterator function
	virtual iterator begin() XANADU_NOTHROW;

	//cxx iterator function
	virtual const_iterator begin() const XANADU_NOTHROW;

	//cxx iterator function
	virtual iterator end() XANADU_NOTHROW;

	//cxx iterator function
	virtual const_iterator end() const XANADU_NOTHROW;

	//cxx iterator function
	virtual const_iterator cbegin() const XANADU_NOTHROW;

	//cxx iterator function
	virtual const_iterator cend() const XANADU_NOTHROW;

	//cxx iterator function
	virtual reverse_iterator rbegin() XANADU_NOTHROW;

	//cxx iterator function
	virtual const_reverse_iterator rbegin() const XANADU_NOTHROW;

	//cxx iterator function
	virtual reverse_iterator rend() XANADU_NOTHROW;

	//cxx iterator function
	virtual const_reverse_iterator rend() const XANADU_NOTHROW;

	//cxx iterator function
	virtual const_reverse_iterator crbegin() const XANADU_NOTHROW;

	//cxx iterator function
	virtual const_reverse_iterator crend() const XANADU_NOTHROW;

public:
	//string buffer
	virtual wchar_t* data() XANADU_NOTHROW;

	//string buffer
	virtual const wchar_t* data() const XANADU_NOTHROW;

	//string length
	virtual int64S length() const XANADU_NOTHROW;

	//string length
	virtual int64S size() const XANADU_NOTHROW;

	//buffer capacity
	virtual int64S capacity() const XANADU_NOTHROW;

	//buffer clear
	virtual void clear() XANADU_NOTHROW;

	//buffer is null
	virtual bool empty() const XANADU_NOTHROW;

	//swap string
	virtual void swap(XString& _String) XANADU_NOTHROW;

	//max_size
	virtual int64S max_size() const XANADU_NOTHROW;

	//resize
	virtual void resize(int64S _Length) XANADU_NOTHROW;

	//resize
	virtual void resize(int64S _Length, wchar_t _Char) XANADU_NOTHROW;

public:
	//元素访问 (1)
	const wchar_t& operator [] (int64S _Index) const;

	//元素访问 (2)
	wchar_t& operator [] (int64S _Index);

	//元素访问 (3)
	const wchar_t& at(int64S _Index) const;

	//元素访问 (4)
	wchar_t& at(int64S _Index);

	//元素访问 (5)
	const wchar_t& front() const;

	//元素访问 (6)
	wchar_t& front();

	//元素访问 (7)
	const wchar_t& back() const;

	//元素访问 (8)
	wchar_t& back();

public:
	//cxx push_back (1)
	virtual void push_back(wchar_t _Char) XANADU_NOTHROW;

	//cxx push_back (2)
	virtual void push_back(const wchar_t* _String, int64S _Size = XString::npos) XANADU_NOTHROW;

	//cxx push_back (3)
	virtual void push_back(const XString& _String) XANADU_NOTHROW;

	//cxx 删除最后一个元素
	virtual XString& pop_back() XANADU_NOTHROW;

public:
	//operator append (1)
	virtual XString& operator += (wchar_t _Char) XANADU_NOTHROW;

	//operator append (2)
	virtual XString& operator += (const wchar_t* _String) XANADU_NOTHROW;

	//operator append (3)
	virtual XString& operator += (const XString& _String) XANADU_NOTHROW;

public:
	//比较运算符 (1)
	virtual bool operator == (const wchar_t* _String)const  XANADU_NOTHROW;

	//比较运算符 (1)
	virtual bool operator == (const XString& _String)const  XANADU_NOTHROW;

	//比较运算符 (2)
	virtual bool operator != (const wchar_t* _String)const  XANADU_NOTHROW;

	//比较运算符 (2)
	virtual bool operator != (const XString& _String)const  XANADU_NOTHROW;

	//比较运算符 (3)
	virtual bool operator < (const wchar_t* _String)const  XANADU_NOTHROW;

	//比较运算符 (3)
	virtual bool operator < (const XString& _String)const  XANADU_NOTHROW;

	//比较运算符 (4)
	virtual bool operator > (const wchar_t* _String) const  XANADU_NOTHROW;

	//比较运算符 (4)
	virtual bool operator > (const XString& _String) const  XANADU_NOTHROW;

	//比较运算符 (5)
	virtual bool operator <= (const wchar_t* _String) const  XANADU_NOTHROW;

	//比较运算符 (5)
	virtual bool operator <= (const XString& _String) const  XANADU_NOTHROW;

	//比较运算符 (6)
	virtual bool operator >= (const wchar_t* _String) const  XANADU_NOTHROW;

	//比较运算符 (6)
	virtual bool operator >= (const XString& _String) const  XANADU_NOTHROW;

public:
	//Convert : To ASCII
	virtual AString ToAString() const XANADU_NOTHROW;

	//Convert : To UNICODE
	virtual WString ToWString() const XANADU_NOTHROW;

	//Convert : To UTF-8
	virtual UString ToUString() const XANADU_NOTHROW;

	//Convert : To Native String
	virtual NString ToNString() const XANADU_NOTHROW;

	//Convert : To XByteArray
	virtual XByteArray ToBytes() const XANADU_NOTHROW;

	//Convert : To URL Encode
	virtual UString ToURL() const XANADU_NOTHROW;

	//Convert : To ASCII
	static AString XANADUAPI ToAString(const XString& _String) XANADU_NOTHROW;

	//Convert : To UNICODE
	static WString XANADUAPI ToWString(const XString& _String) XANADU_NOTHROW;

	//Convert : To UTF-8
	static UString XANADUAPI ToUString(const XString& _String) XANADU_NOTHROW;

	//Convert : To Native String
	static NString XANADUAPI ToNString(const XString& _String) XANADU_NOTHROW;

	//Convert : To XByteArray
	static XByteArray XANADUAPI ToBytes(const XString& _String) XANADU_NOTHROW;

	//Convert : To URL Encode
	static UString XANADUAPI ToURL(const XString& _String) XANADU_NOTHROW;

	//Convert:From ASCII
	static XString XANADUAPI FromAString(const AString& _AString) XANADU_NOTHROW;

	//Convert:From UNICODE
	static XString XANADUAPI FromWString(const WString& _WString) XANADU_NOTHROW;

	//Convert:From UTF-8
	static XString XANADUAPI FromUString(const UString& _UString) XANADU_NOTHROW;

	//Convert:From Latin_1(ISO 8859-1)
	static XString XANADUAPI FromLString(const LString& _LString) XANADU_NOTHROW;

	//Convert : From Native String
	static XString XANADUAPI FromNString(const NString& _NString) XANADU_NOTHROW;

	//Convert : From XByteArray
	static XString XANADUAPI FromBytes(const XByteArray& _Bytes) XANADU_NOTHROW;

	//Convert:From URL Encode
	static XString XANADUAPI FromURL(const UString& _URL) XANADU_NOTHROW;

	//convert to upper
	virtual XString ToUpper() const XANADU_NOTHROW;

	//convert to lower
	virtual XString ToLower() const XANADU_NOTHROW;

public:
	//Format String (char* [%S]) (wchar_t* [%s][%ls][%ws])
	static XString XANADUAPI Format(const wchar_t* _Format, ...) XANADU_NOTHROW;

public:
	//Sub String
	virtual XString substr(size_type _Pos = 0, int64S _Length = XString::npos) const XANADU_NOTHROW;

	//Sub String
	virtual XString left(size_type _Pos = XString::npos) const XANADU_NOTHROW;

	//Sub String
	virtual XString right(size_type _Pos = 0) const XANADU_NOTHROW;

	//Middle String
	virtual XString middle(const XString& _Left, const XString& _Right, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

public:
	//Find (1)
	virtual size_type find(const XString& _String, size_type _Pos = 0) const XANADU_NOTHROW;

	//Find (2)
	virtual size_type find(const wchar_t* _String, size_type _Pos = 0) const XANADU_NOTHROW;

	//Find (3)
	virtual size_type find(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW;

	//Find (4)
	virtual size_type find(wchar_t _Char, size_type _Pos = 0) const XANADU_NOTHROW;


	//Reverse Find (1)
	virtual size_type rfind(const XString& _String, size_type _Pos = npos) const XANADU_NOTHROW;

	//Reverse Find (2)
	virtual size_type rfind(const wchar_t* _String, size_type _Pos = npos) const XANADU_NOTHROW;

	//Reverse Find (3)
	virtual size_type rfind(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW;

	//Reverse Find (4)
	virtual size_type rfind(wchar_t _Char, size_type _Pos = npos) const XANADU_NOTHROW;


	//Index Of (1)
	virtual size_type indexOf(const XString& _String, size_type _Pos = 0) const XANADU_NOTHROW;

	//Index Of (2)
	virtual size_type indexOf(const wchar_t* _String, size_type _Pos = 0) const XANADU_NOTHROW;

	//Index Of (3)
	virtual size_type indexOf(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW;

	//Index Of (4)
	virtual size_type indexOf(wchar_t _Char, size_type _Pos = 0) const XANADU_NOTHROW;


	//Last Index Of (1)
	virtual size_type lastIndexOf(const XString& _String, size_type _Pos = XString::npos) const XANADU_NOTHROW;

	//Last Index Of (2)
	virtual size_type lastIndexOf(const wchar_t* _String, size_type _Pos = XString::npos) const XANADU_NOTHROW;

	//Last Index Of (3)
	virtual size_type lastIndexOf(const wchar_t* _String, int64S _Length, size_type _Pos) const XANADU_NOTHROW;

	//Last Index Of (4)
	virtual size_type lastIndexOf(wchar_t _Char, size_type _Pos = XString::npos) const XANADU_NOTHROW;

public:
	//contains substring
	virtual bool contains(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

	//contains substring
	virtual bool contains(const wchar_t* _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

	//contains substring
	virtual bool contains(const wchar_t* _String, int64S _Size, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

	//contains substring
	virtual bool contains(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

public:
	//compare substring
	virtual int compare(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

	//compare substring
	virtual int compare(const wchar_t* _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

	//compare substring
	virtual int compare(const wchar_t* _String, int64S _Size, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

	//compare substring
	virtual int compare(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const XANADU_NOTHROW;

public:
	//append (1)
	virtual XString& append(wchar_t _Char) XANADU_NOTHROW;

	//append (2)
	virtual XString& append(const wchar_t* _String, int64S _Size = XString::npos) XANADU_NOTHROW;

	//append (3)
	virtual XString& append(const XString& _String) XANADU_NOTHROW;

public:
	//string insert wchar_t
	virtual XString& insert(size_type _Pos, wchar_t _Char) XANADU_NOTHROW;

	//string insert wchar_t
	virtual XString& insert(size_type _Pos, int64U _Count, wchar_t _Char) XANADU_NOTHROW;

	//string insert const wchar_t*
	virtual XString& insert(size_type _Pos, const wchar_t* _String, int64S _Length) XANADU_NOTHROW;

	//string insert XString
	virtual XString& insert(size_type _Pos, const XString& _String) XANADU_NOTHROW;

public:
	//string remove (1)
	virtual XString& remove(size_type _Pos, int64S _Length) XANADU_NOTHROW;

	//string remove (2)
	virtual XString& remove(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) XANADU_NOTHROW;

	//string remove (3)
	virtual XString& remove(const wchar_t* _String, int64S _Length = XString::npos, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) XANADU_NOTHROW;

	//string remove (4)
	virtual XString& remove(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) XANADU_NOTHROW;

public:
	//string replace
	virtual XString& replace(size_type _Pos, int64S _Length, wchar_t _After) XANADU_NOTHROW;

	//string replace
	virtual XString& replace(size_type _Pos, int64S _Length, const wchar_t* _After, int64S _LengthA) XANADU_NOTHROW;

	//string replace
	virtual XString& replace(size_type _Pos, int64S _Length, const XString& _After) XANADU_NOTHROW;

	//string replace
	virtual XString& replace(wchar_t _Before, wchar_t _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) XANADU_NOTHROW;

	//string replace
	virtual XString& replace(wchar_t _Before, const wchar_t* _After, int64S _LengthA, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) XANADU_NOTHROW;

	//string replace
	virtual XString& replace(wchar_t _Before, const XString& _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) XANADU_NOTHROW;

	//string replace
	virtual XString& replace(const wchar_t* _Before, int64S _LengthB, wchar_t _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) XANADU_NOTHROW;

	//string replace
	virtual XString& replace(const wchar_t* _Before, int64S _LengthB, const wchar_t* _After, int64S _LengthA, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) XANADU_NOTHROW;

	//string replace
	virtual XString& replace(const wchar_t* _Before, int64S _LengthB, const XString& _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) XANADU_NOTHROW;

	//string replace
	virtual XString& replace(const XString& _Before, wchar_t _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) XANADU_NOTHROW;

	//string replace
	virtual XString& replace(const XString& _Before, const wchar_t* _After, int64S _LengthA, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) XANADU_NOTHROW;

	//string replace
	virtual XString& replace(const XString& _Before, const XString& _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) XANADU_NOTHROW;

public:
	//isSpace
	static bool isSpace(wchar_t _Char) XANADU_NOTHROW;

	//simplified
	virtual XString simplified() const XANADU_NOTHROW;

public:
	//string to int16S
	virtual int16S  ToInt16S(bool* _Ok = nullptr, int _Base = 10) const XANADU_NOTHROW;

	//string to int16U
	virtual int16U ToInt16U(bool* _Ok = nullptr, int _Base = 10) const XANADU_NOTHROW;

	//string to int32S
	virtual int32S ToInt32S(bool* _Ok = nullptr, int _Base = 10) const XANADU_NOTHROW;

	//string to int32U
	virtual int32U ToInt32U(bool* _Ok = nullptr, int _Base = 10) const XANADU_NOTHROW;

	//string to int64S
	virtual int64S ToInt64S(bool* _Ok = nullptr, int _Base = 10) const XANADU_NOTHROW;

	//string to int64U
	virtual int64U ToInt64U(bool* _Ok = nullptr, int _Base = 10) const XANADU_NOTHROW;

	//string to float
	virtual float ToFloat(bool* _Ok = nullptr) const XANADU_NOTHROW;

	//string to double
	virtual double ToDouble(bool* _Ok = nullptr) const XANADU_NOTHROW;

public:
	//string form number
	virtual XString& SetNumber(int16S _Value, int32S _Base = 10) XANADU_NOTHROW;

	//string form number
	virtual XString& SetNumber(int16U _Value, int32S _Base = 10) XANADU_NOTHROW;

	//string form number
	virtual XString& SetNumber(int32S _Value, int32S _Base = 10) XANADU_NOTHROW;

	//string form number
	virtual XString& SetNumber(int32U _Value, int32S _Base = 10) XANADU_NOTHROW;

	//string form number
	virtual XString& SetNumber(int64S _Value, int32S _Base = 10) XANADU_NOTHROW;

	//string form number
	virtual XString& SetNumber(int64U _Value, int32S _Base = 10) XANADU_NOTHROW;

	//string form number
	virtual XString& SetNumber(float _Value, char _Format = 'g', int32S _Prec = 6) XANADU_NOTHROW;

	//string form number
	virtual XString& SetNumber(double _Value, char _Format = 'g', int32S _Prec = 6) XANADU_NOTHROW;

public:
	//string form number
	static XString number(int16S _Value, int32S _Base = 10) XANADU_NOTHROW;

	//string form number
	static XString number(int16U _Value, int32S _Base = 10) XANADU_NOTHROW;

	//string form number
	static XString number(int32S _Value, int32S _Base = 10) XANADU_NOTHROW;

	//string form number
	static XString number(int32U _Value, int32S _Base = 10) XANADU_NOTHROW;

	//string form number
	static XString number(int64S _Value, int32S _Base = 10) XANADU_NOTHROW;

	//string form number
	static XString number(int64U _Value, int32S _Base = 10) XANADU_NOTHROW;

	//string form number
	static XString number(double _Value, char _Format = 'g', int32S _Prec = 6) XANADU_NOTHROW;
};

//XString Swap
XANADU_CORE_EXPORT void swap(XString& _String1, XString& _String2) XANADU_NOTHROW;

//XString Merged
XANADU_CORE_EXPORT XString operator + (const XString& _StringLeft, const XString& _StringRight) XANADU_NOTHROW;

//XString Merged
XANADU_CORE_EXPORT XString operator + (const XString& _StringLeft, const wchar_t* _StringRight) XANADU_NOTHROW;

//XString Merged
XANADU_CORE_EXPORT XString operator + (const wchar_t* _StringLeft, const XString& _StringRight) XANADU_NOTHROW;

//XString Merged
XANADU_CORE_EXPORT XString operator + (const XString& _StringLeft, wchar_t _CharRight) XANADU_NOTHROW;

//XString Merged
XANADU_CORE_EXPORT XString operator + (wchar_t _CharLeft, const XString& _StringRight) XANADU_NOTHROW;

//XString Out
XANADU_CORE_EXPORT std::wostream& operator << (std::wostream& _OStream, const XString& _String) XANADU_NOTHROW;

//XString In
XANADU_CORE_EXPORT std::wistream& operator >> (std::wistream& _IStream, XString& _String) XANADU_NOTHROW;

//XString in line
XANADU_CORE_EXPORT std::wistream& getline(std::wistream& _IStream, XString& _String, wchar_t _Delim) XANADU_NOTHROW;

//XString in line
XANADU_CORE_EXPORT std::wistream& getline(std::wistream& _IStream, XString& _String) XANADU_NOTHROW;

#endif//_XANADU_CORE_STRING_H_

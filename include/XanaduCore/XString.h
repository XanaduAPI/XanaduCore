#ifndef			_XANADU_CORE_STRING_H_
#define			_XANADU_CORE_STRING_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XAllocator.h>
#include <XanaduCore/XByteArray.h>


// 这里有一些Xanadu系列的字符串类型名称定义
typedef			wchar_t							XChar;
typedef			std::string						AString;
typedef			std::wstring						WString;
typedef			std::string						UString;
typedef			std::string						LString;
#if defined(_XANADU_SYSTEM_WINDOWS)
typedef			AString							NString;
#else
typedef			UString							NString;
#endif

// Xanadu字符串的类型
#define			XSTRING(_String)					L ## _String


// <summary>
// 这个字符串处理需要一个更好的内存分配器
// 这个 XString 类的迭代器并未进行更多的测试
// </summary>
class XANADU_CORE_EXPORT XString
{
public:
	using						size_type = XAllocator::size_type;
	static const size_type				npos = XAllocator::npos;

private:
	wchar_t*					_string_data = nullptr;
	size_type					_string_length = 0U;
	size_type					_string_capacity = 0U;

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
	// 构造
	XString() noexcept;

	// 构造
	XString(wchar_t _Char) noexcept;

	// 构造
	XString(const wchar_t* _String) noexcept;

	// 构造
	XString(const wchar_t* _String, size_type _Length) noexcept;

	// 构造
	XString(const XString& _String) noexcept;

	// 构造
	XString(XString&& _String) noexcept;

	// 构造
	XString(const WString& _String) noexcept;

	// 虚析构
	virtual ~XString() noexcept;

public:
	// 操作符重载 =
	virtual XString& operator = (wchar_t _Char) noexcept;

	// 操作符重载 =
	virtual XString& operator = (const wchar_t* _String) noexcept;

	// 操作符重载 =
	virtual XString& operator = (const WString& _String) noexcept;

	// 操作符重载 =
	virtual XString& operator = (const XString& _String) noexcept;

	// 操作符重载 =
	virtual XString& operator = (XString&& _String) noexcept;

private:
	// 内存操作:申请
	virtual void _memory_malloc(size_type _Size) noexcept;

	// 内存操作:添加
	virtual void _memory_append(size_type _Size) noexcept;

	// 内存操作:重新定义大小
	virtual void _memory_resize(size_type _Size) noexcept;

	// 内存操作:释放
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
	// 获取字符串的数据指针
	virtual wchar_t* data() noexcept;

	// 获取字符串的常量数据指针
	virtual const wchar_t* data() const noexcept;

	// 获取字符串的数据长度
	virtual size_type length() const noexcept;

	// 获取字符串的数据长度
	virtual size_type size() const noexcept;

	// 获取字符串的数据容量
	virtual size_type capacity() const noexcept;

	// 以 0 清空所有空间
	virtual void clear() noexcept;

	// 检查是否为空，当长度为0时返回true
	virtual bool empty() const noexcept;

	// 检查是否有值，当长度不为0时返回true
	virtual bool exist() const noexcept;

	// 交换字符串
	virtual void swap(XString& _String) noexcept;

	// 获取允许的最大长度
	virtual size_type max_size() const noexcept;

	// 调整大小
	virtual void resize(size_type _Length) noexcept;

	// 调整大小
	virtual void resize(size_type _Length, wchar_t _Char) noexcept;

	// 截断字节数组的下标位置pos。如果pos超出了数组的末尾，则什么也不会发生。
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
	// 操作符重载 +=
	virtual XString& operator += (wchar_t _Char) noexcept;

	// 操作符重载 +=
	virtual XString& operator += (const wchar_t* _String) noexcept;

	// 操作符重载 +=
	virtual XString& operator += (const XString& _String) noexcept;

public:
	// 操作符重载 ==
	virtual bool operator == (const wchar_t* _String)const noexcept;

	// 操作符重载 ==
	virtual bool operator == (const XString& _String)const noexcept;

	// 操作符重载 !=
	virtual bool operator != (const wchar_t* _String)const noexcept;

	// 操作符重载 !=
	virtual bool operator != (const XString& _String)const noexcept;

	// 操作符重载 <
	virtual bool operator < (const wchar_t* _String)const noexcept;

	// 操作符重载 <
	virtual bool operator < (const XString& _String)const noexcept;

	// 操作符重载 >
	virtual bool operator > (const wchar_t* _String) const noexcept;

	// 操作符重载 >
	virtual bool operator > (const XString& _String) const noexcept;

	// 操作符重载 <=
	virtual bool operator <= (const wchar_t* _String) const noexcept;

	// 操作符重载 <=
	virtual bool operator <= (const XString& _String) const noexcept;

	// 操作符重载 >=
	virtual bool operator >= (const wchar_t* _String) const noexcept;

	// 操作符重载 >=
	virtual bool operator >= (const XString& _String) const noexcept;

public:
	// 转换至 ASCII 编码的字符串
	virtual AString toAString() const noexcept;

	// 转换至 UNICODE 编码的字符串
	virtual WString toWString() const noexcept;

	// 转换至 UTF-8 编码的字符串
	virtual UString toUString() const noexcept;

	// 转换至 本机( Windows : ASCII / Other : UTF-8 ) 编码的字符串
	virtual NString toNString() const noexcept;

	// 转换至 UTF-8 编码的 XByteArray
	virtual XByteArray toBytes() const noexcept;

	// 转换至 UTF-8 编码的 URL 类型字符串
	virtual UString toURL() const noexcept;

	// 转换至 ASCII 编码的字符串
	static AString XANADUAPI toAString(const XString& _String) noexcept;

	// 转换至 UNICODE 编码的字符串
	static WString XANADUAPI toWString(const XString& _String) noexcept;

	// 转换至 UTF-8 编码的字符串
	static UString XANADUAPI toUString(const XString& _String) noexcept;

	// 转换至 本机( Windows : ASCII / Other : UTF-8) 编码的字符串
	static NString XANADUAPI toNString(const XString& _String) noexcept;

	// 转换至 UTF-8 编码的 XByteArray
	static XByteArray XANADUAPI toBytes(const XString& _String) noexcept;

	// 转换至 UTF-8 编码的 URL 类型字符串
	static UString XANADUAPI toURL(const XString& _String) noexcept;

	// 从 ASCII 编码的字符串格式化
	static XString XANADUAPI fromAString(const AString& _AString) noexcept;

	// 从 UNICODE 编码的字符串格式化
	static XString XANADUAPI fromWString(const WString& _WString) noexcept;

	// 从 UTF-8 编码的字符串格式化
	static XString XANADUAPI fromUString(const UString& _UString) noexcept;

	// 从 本机( Windows : ASCII / Other : UTF-8) 编码的字符串格式化
	static XString XANADUAPI fromNString(const NString& _NString) noexcept;

	// 从 UTF-8 编码的 XByteArray 格式化
	static XString XANADUAPI fromBytes(const XByteArray& _Bytes) noexcept;

	// 从 UTF-8 编码的 URL 类型字符串格式化
	static XString XANADUAPI fromURL(const UString& _URL) noexcept;

	// 转换至大写
	virtual XString toUpper() const noexcept;

	// 转换至小写
	virtual XString toLower() const noexcept;

public:
	// 格式化字符串 (char* [%S]) (wchar_t* [%s][%ls][%ws])
	static XString XANADUAPI format(const wchar_t* _Format, ...) noexcept;

public:
	// 取出子字符串
	XString substr(size_type _Pos = 0ULL, size_type _Length = XString::npos) const noexcept;

	// 按长度获取左边的数据
	XString left(size_type _Pos = XString::npos) const noexcept;

	// 按长度获取右边的数据
	XString right(size_type _Pos = 0ULL) const noexcept;

	// 按长度获取中间的数据
	XString mid(size_type _Pos, size_type _Size = XString::npos) const noexcept;

	// 按匹配字符串获取中间的数据
	XString middle(const XString& _Left, const XString& _Right, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

public:
	// 检查头部是否相同
	bool startsWith(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// 检查头部是否相同
	bool startsWith(const wchar_t* _Memory, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// 检查头部是否相同
	bool startsWith(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// 检查尾部是否相同
	bool endsWith(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// 检查尾部是否相同
	bool endsWith(const wchar_t* _Memory, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// 检查尾部是否相同
	bool endsWith(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

public:
	// 从指定位置按正序查找
	size_type find(const XString& _String, size_type _Pos = 0) const noexcept;

	// 从指定位置按正序查找
	size_type find(const wchar_t* _String, size_type _Pos = 0) const noexcept;

	// 从指定位置按正序查找
	size_type find(const wchar_t* _String, size_type _Length, size_type _Pos) const noexcept;

	// 从指定位置按正序查找
	size_type find(wchar_t _Char, size_type _Pos = 0) const noexcept;


	// 从指定位置按倒序查找
	size_type rfind(const XString& _String, size_type _Pos = npos) const noexcept;

	// 从指定位置按倒序查找
	size_type rfind(const wchar_t* _String, size_type _Pos = npos) const noexcept;

	// 从指定位置按倒序查找
	size_type rfind(const wchar_t* _String, size_type _Length, size_type _Pos) const noexcept;

	// 从指定位置按倒序查找
	size_type rfind(wchar_t _Char, size_type _Pos = npos) const noexcept;

public:
	// 检查是否包含指定的内容
	bool contains(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// 检查是否包含指定的内容
	bool contains(const wchar_t* _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// 检查是否包含指定的内容
	bool contains(const wchar_t* _String, size_type _Size, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// 检查是否包含指定的内容
	bool contains(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

public:
	// 检查它们是否相同 (默认大小写敏感)
	int compare(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// 检查它们是否相同 (默认大小写敏感)
	int compare(const wchar_t* _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// 检查它们是否相同 (默认大小写敏感)
	int compare(const wchar_t* _String, size_type _Size, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// 检查它们是否相同 (默认大小写敏感)
	int compare(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

public:
	// 从结尾添加数据
	XString& append(wchar_t _Char) noexcept;

	// 从结尾添加数据
	XString& append(const wchar_t* _String, size_type _Size = XString::npos) noexcept;

	// 从结尾添加数据
	XString& append(const XString& _String) noexcept;

public:
	// 从指定的位置插入数据 wchar_t
	XString& insert(size_type _Pos, wchar_t _Char) noexcept;

	// 从指定的位置插入数据 wchar_t
	XString& insert(size_type _Pos, size_type _Count, wchar_t _Char) noexcept;

	// 从指定的位置插入数据 const wchar_t*
	XString& insert(size_type _Pos, const wchar_t* _String, size_type _Length) noexcept;

	// 从指定的位置插入数据 XString
	XString& insert(size_type _Pos, const XString& _String) noexcept;

public:
	// 从指定的位置删除指定长度的数据
	XString& remove(size_type _Pos, size_type _Length) noexcept;

	// 删除与参数相同的数据
	XString& remove(wchar_t _Char, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// 删除与参数相同的数据
	XString& remove(const wchar_t* _String, size_type _Length = XString::npos, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// 删除与参数相同的数据
	XString& remove(const XString& _String, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

public:
	// 替换指定的数据
	XString& replace(size_type _Pos, size_type _Length, wchar_t _After) noexcept;

	// 替换指定的数据
	XString& replace(size_type _Pos, size_type _Length, const wchar_t* _After, size_type _LengthA) noexcept;

	// 替换指定的数据
	XString& replace(size_type _Pos, size_type _Length, const XString& _After) noexcept;

	// 替换指定的数据
	XString& replace(wchar_t _Before, wchar_t _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// 替换指定的数据
	XString& replace(wchar_t _Before, const wchar_t* _After, size_type _LengthA, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// 替换指定的数据
	XString& replace(wchar_t _Before, const XString& _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// 替换指定的数据
	XString& replace(const wchar_t* _Before, size_type _LengthB, wchar_t _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// 替换指定的数据
	XString& replace(const wchar_t* _Before, size_type _LengthB, const wchar_t* _After, size_type _LengthA, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// 替换指定的数据
	XString& replace(const wchar_t* _Before, size_type _LengthB, const XString& _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// 替换指定的数据
	XString& replace(const XString& _Before, wchar_t _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// 替换指定的数据
	XString& replace(const XString& _Before, const wchar_t* _After, size_type _LengthA, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

	// 替换指定的数据
	XString& replace(const XString& _Before, const XString& _After, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) noexcept;

public:
	// 判断字符是否是空白字符 ('\t','\n','\v','\f','\r','_') 中的一个
	static bool isSpace(wchar_t _Char) noexcept;

	// 删除开头、中间和结尾空白字符
	virtual XString simplified() const noexcept;

public:
	// string to char
	char toChar(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to unsigned char
	unsigned char toUChar(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to short
	short toShort(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to unsigned short
	unsigned short toUShort(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to int
	int toInt(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to unsigned int
	unsigned int toUInt(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to long
	long toLong(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to unsigned long
	unsigned long toULong(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to long long
	long long toLLong(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to unsigned long long
	unsigned long long toULLong(bool* _Ok = nullptr, int _Base = 10) const noexcept;

	// string to float
	float toFloat(bool* _Ok) const noexcept;

	// string to double
	double toDouble(bool* _Ok) const noexcept;

public:

	// string form number
	XString& setNumber(char _Value, int _Base = 10) noexcept;

	// string form number
	XString& setNumber(unsigned char _Value, int _Base = 10) noexcept;

	// string form number
	XString& setNumber(short _Value, int _Base = 10) noexcept;

	// string form number
	XString& setNumber(unsigned short _Value, int _Base = 10) noexcept;

	// string form number
	XString& setNumber(int _Value, int _Base = 10) noexcept;

	// string form number
	XString& setNumber(unsigned int _Value, int _Base = 10) noexcept;

	// string form number
	XString& setNumber(long _Value, int _Base = 10) noexcept;

	// string form number
	XString& setNumber(unsigned long _Value, int _Base = 10) noexcept;

	// string form number
	XString& setNumber(long long _Value, int _Base = 10) noexcept;

	// string form number
	XString& setNumber(unsigned long long _Value, int _Base = 10) noexcept;

	// string form number
	XString& setNumber(float _Value, char _Format, int _Prec) noexcept;

	// string form number
	XString& setNumber(double _Value, char _Format, int _Prec) noexcept;

public:
	// string form number
	static XString number(char _Value, int _Base = 10) noexcept;

	// string form number
	static XString number(unsigned char _Value, int _Base = 10) noexcept;

	// string form number
	static XString number(short _Value, int _Base = 10) noexcept;

	// string form number
	static XString number(unsigned short _Value, int _Base = 10) noexcept;

	// string form number
	static XString number(int _Value, int _Base = 10) noexcept;

	// string form number
	static XString number(unsigned int _Value, int _Base = 10) noexcept;

	// string form number
	static XString number(long _Value, int _Base = 10) noexcept;

	// string form number
	static XString number(unsigned long _Value, int _Base = 10) noexcept;

	// string form number
	static XString number(long long _Value, int _Base = 10) noexcept;

	// string form number
	static XString number(unsigned long long _Value, int _Base = 10) noexcept;

	// string form number
	static XString number(float _Value, char _Format = 'g', int _Prec = 6) noexcept;

	// string form number
	static XString number(double _Value, char _Format = 'g', int _Prec = 6) noexcept;
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

#endif

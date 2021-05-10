#ifndef			_XANADU_CORE_BYTEARRAY_H_
#define			_XANADU_CORE_BYTEARRAY_H_

#include <XanaduCore/XHeader.h>
#include <XanaduCore/XAllocator.h>

// <summary>
// 一个字节数组工具
// </summary>
class XANADU_CORE_EXPORT XByteArray : private XAllocator
{
public:
	// 长度和pos的类型
	using						size_type = XAllocator::size_type;

public:
	// 没有找到匹配数据时返回的下标
	static const size_type				npos = XAllocator::npos;

public:
	// 构造
	XByteArray() noexcept;

	// 构造
	XByteArray(const char* _Memory, size_type _Size = XByteArray::npos) noexcept;

	// 构造
	XByteArray(size_type _Size, char _Char) noexcept;

	// 构造
	explicit XByteArray(size_type _Size) noexcept;

	// 构造
	XByteArray(const XByteArray& _Bytes) noexcept;

	// 虚析构
	virtual ~XByteArray() noexcept;

public:
	// 操作符重载 =
	XByteArray& operator = (const char* _Memory) noexcept;

	// 操作符重载 =
	XByteArray& operator = (const XByteArray& _Bytes) noexcept;

	// 操作符重载 =
	XByteArray& operator = (XByteArray&& _Other) noexcept;

public:
	// 操作符重载 +
	XByteArray operator + (char _Char) const noexcept;

	// 操作符重载 +
	XByteArray operator + (const char* _Memory) const noexcept;

	// 操作符重载 +
	XByteArray operator + (const XByteArray& _Bytes) const noexcept;

public:
	// 操作符重载 +=
	XByteArray& operator += (char _Char) noexcept;

	// 操作符重载 +=
	XByteArray& operator += (const char* _Memory) noexcept;

	// 操作符重载 +=
	XByteArray& operator += (const XByteArray& _Bytes) noexcept;

public:
	// 操作符重载 ==
	virtual bool operator == (const char* _Memory) const  noexcept;

	// 操作符重载 ==
	virtual bool operator == (const XByteArray& _Bytes) const  noexcept;

public:
	// 操作符重载 !=
	virtual bool operator != (const char* _Memory) const  noexcept;

	// 操作符重载 !=
	virtual bool operator != (const XByteArray& _Bytes) const  noexcept;

public:
	// 获取数据指针
	virtual char* data() noexcept;

	// 获取常量数据指针
	virtual const char* data() const noexcept;

	// 获取数据长度
	virtual size_type size() const noexcept;

	// 获取数据长度
	virtual size_type length() const noexcept;

	// 调整大小
	virtual void resize(size_type _Size) noexcept;

	// 从 _Index 截断字节数组的下标位置。如果 _Index 超出了数组的末尾，则什么也不会发生。
	virtual void truncate(size_type _Index) noexcept;

	// 填充一个字符到指定长度的空格，如果是 XByteArray::npos ，则全部填充
	virtual XByteArray& fill(char _Char, size_type _Size = XByteArray::npos) noexcept;

	// 获取当前容量
	virtual size_type capacity() const noexcept;

	// 检查是否为空，当长度为0时返回true
	virtual bool empty() const noexcept;

	// 检查是否有值，当长度不为0时返回true
	virtual bool exist() const noexcept;

public:
	// 按下标读取数据
	virtual char at(size_type _Index) const noexcept;

	// 得到第一位的数据
	virtual char front() const noexcept;

	// 得到第一位的数据
	virtual char& front() noexcept;

	// 得到最后一位的数据
	virtual char back() const noexcept;

	// 得到最后一位的数据
	virtual char& back() noexcept;

	// 按下标读取数据
	virtual char& operator[](size_type _Index) noexcept;

	// 按下标读取数据
	virtual char operator[](size_type _Index) const noexcept;

public:
	// Iterator type definition
	typedef char*					iterator;
	typedef const char*				const_iterator;
	typedef iterator				Iterator;
	typedef const_iterator				ConstIterator;
	typedef std::reverse_iterator<iterator>		reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;

	// 迭代器操作
	virtual iterator begin() noexcept;

	// 迭代器操作
	virtual const_iterator begin() const noexcept;

	// 迭代器操作
	virtual const_iterator cbegin() const noexcept;

	// 迭代器操作
	virtual const_iterator constBegin() const noexcept;

	// 迭代器操作
	virtual iterator end() noexcept;

	// 迭代器操作
	virtual const_iterator end() const noexcept;

	// 迭代器操作
	virtual const_iterator cend() const noexcept;

	// 迭代器操作
	virtual const_iterator constEnd() const noexcept;

	// 迭代器操作
	virtual reverse_iterator rbegin() noexcept;

	// 迭代器操作
	virtual reverse_iterator rend() noexcept;

	// 迭代器操作
	virtual const_reverse_iterator rbegin() const noexcept;

	// 迭代器操作
	virtual const_reverse_iterator rend() const noexcept;

	// 迭代器操作
	virtual const_reverse_iterator crbegin() const noexcept;

	// 迭代器操作
	virtual const_reverse_iterator crend() const noexcept;

public:
	// Vector兼容:从结尾添加数据
	virtual void push_back(char _Char) noexcept;

	// Vector兼容:从结尾添加数据
	virtual void push_back(const char* _Memory) noexcept;

	// Vector兼容:从结尾添加数据
	virtual void push_back(const XByteArray& _Bytes) noexcept;

	// Vector兼容:从开头添加数据
	virtual void push_front(char _Char) noexcept;

	// Vector兼容:从开头添加数据
	virtual void push_front(const char* _Memory) noexcept;

	// Vector兼容:从开头添加数据
	virtual void push_front(const XByteArray& _Bytes) noexcept;

public:
	// 从开头添加数据
	virtual XByteArray& prepend(char _Char) noexcept;

	// 从开头添加数据
	virtual XByteArray& prepend(size_type _Count, char _Char) noexcept;

	// 从开头添加数据
	virtual XByteArray& prepend(const char* _String) noexcept;

	// 从开头添加数据
	virtual XByteArray& prepend(const char* _String, size_type _Length) noexcept;

	// 从开头添加数据
	virtual XByteArray& prepend(const XByteArray& _Bytes) noexcept;

	// 从结尾添加数据
	virtual XByteArray& append(char _Char) noexcept;

	// 从结尾添加数据
	virtual XByteArray& append(size_type _Count, char _Char) noexcept;

	// 从结尾添加数据
	virtual XByteArray& append(const char* _String) noexcept;

	// 从结尾添加数据
	virtual XByteArray& append(const char* _String, size_type _Length) noexcept;

	// 从结尾添加数据
	virtual XByteArray& append(const XByteArray& _Bytes) noexcept;

	// 从指定的位置插入数据
	virtual XByteArray& insert(size_type _Index, char _Char) noexcept;

	// 从指定的位置插入数据
	virtual XByteArray& insert(size_type _Index, size_type _Count, char _Char) noexcept;

	// 从指定的位置插入数据
	virtual XByteArray& insert(size_type _Index, const char* _String) noexcept;

	// 从指定的位置插入数据
	virtual XByteArray& insert(size_type _Index, const char* _String, size_type _Length) noexcept;

	// 从指定的位置插入数据
	virtual XByteArray& insert(size_type _Index, const XByteArray& _Bytes) noexcept;

public:
	// 从指定的位置删除指定长度的数据
	virtual XByteArray& remove(size_type _Index, size_type _Length) noexcept;

	// 删除与参数相同的数据
	virtual XByteArray& remove(char _Char) noexcept;

	// 删除与参数相同的数据
	virtual XByteArray& remove(const char* _Memory) noexcept;

	// 删除与参数相同的数据
	virtual XByteArray& remove(const char* _Memory, size_type _Size) noexcept;

	// 删除与参数相同的数据
	virtual XByteArray& remove(const XByteArray& _Bytes) noexcept;

public:
	// 替换指定的数据
	virtual XByteArray& replace(size_type _Index, size_type _Length, const char* _After) noexcept;

	// 替换指定的数据
	virtual XByteArray& replace(size_type _Index, size_type _Length, const char* _After, size_type _Asize) noexcept;

	// 替换指定的数据
	virtual XByteArray& replace(size_type _Index, size_type _Length, const XByteArray& _Bytes) noexcept;

	// 替换指定的数据
	virtual XByteArray& replace(char _Before, const char* _After) noexcept;

	// 替换指定的数据
	virtual XByteArray& replace(char _Before, const XByteArray& _After) noexcept;

	// 替换指定的数据
	virtual XByteArray& replace(const char* _Before, const char* _After) noexcept;

	// 替换指定的数据
	virtual XByteArray& replace(const char* _Before, size_type _Bsize, const char* _After, size_type _Asize) noexcept;

	// 替换指定的数据
	virtual XByteArray& replace(const XByteArray& _Before, const XByteArray& _After) noexcept;

	// 替换指定的数据
	virtual XByteArray& replace(const XByteArray& _Before, const char* _After) noexcept;

	// 替换指定的数据
	virtual XByteArray& replace(const char* _Before, const XByteArray& _After) noexcept;

	// 替换指定的数据
	virtual XByteArray& replace(char _Before, char _After) noexcept;

public:
	// 按长度获取左边的数据
	virtual XByteArray left(size_type _Length) const noexcept;

	// 按长度获取右边的数据
	virtual XByteArray right(size_type _Length) const noexcept;

	// 按长度获取中间的数据
	virtual XByteArray mid(size_type _Index, size_type _Length = XByteArray::npos) const noexcept;

public:
	// 检查头部是否相同
	virtual bool startsWith(char _Char) const noexcept;

	// 检查头部是否相同
	virtual bool startsWith(const char* _Memory) const noexcept;

	// 检查头部是否相同
	virtual bool startsWith(const XByteArray& _Bytes) const noexcept;

	// 检查尾部是否相同
	virtual bool endsWith(char _Char) const noexcept;

	// 检查尾部是否相同
	virtual bool endsWith(const char* _Memory) const noexcept;

	// 检查尾部是否相同
	virtual bool endsWith(const XByteArray& _Bytes) const noexcept;

public:
	// 从指定位置按正序查找
	virtual size_type find(char _Char, size_type _From = 0U) const noexcept;

	// 从指定位置按正序查找
	virtual size_type find(const char* _Memory, size_type _From = 0U) const noexcept;

	// 从指定位置按正序查找
	virtual size_type find(const XByteArray& _Bytes, size_type _From = 0U) const noexcept;

	// 从指定位置按倒序查找
	virtual size_type rfind(char _Char, size_type _From = XByteArray::npos) const noexcept;

	// 从指定位置按倒序查找
	virtual size_type rfind(const char* _Memory, size_type _From = XByteArray::npos) const noexcept;

	// 从指定位置按倒序查找
	virtual size_type rfind(const XByteArray& _Bytes, size_type _From = XByteArray::npos) const noexcept;

public:
	// 检查是否包含指定的内容
	virtual bool contains(char _Char) const noexcept;

	// 检查是否包含指定的内容
	virtual bool contains(const char* _Memory) const noexcept;

	// 检查是否包含指定的内容
	virtual bool contains(const XByteArray& _Bytes) const noexcept;

	// 检查它们是否相同 (默认大小写敏感)
	virtual int compare(const char* _Memory, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

	// 检查它们是否相同 (默认大小写敏感)
	virtual int compare(const XByteArray& _Bytes, Xanadu::CaseSensitivity _XCS = Xanadu::CaseSensitive) const noexcept;

public:
	// 检查是否全部是小写字符
	virtual bool isLower() const noexcept;

	// 检查是否全部是大写字符
	virtual bool isUpper() const noexcept;

	// 转换至小写
	virtual XByteArray toLower() const noexcept;

	// 转换至大写
	virtual XByteArray toUpper() const noexcept;

	// 删除开始和结束空白字符
	virtual XByteArray trimmed() const noexcept;

	// 删除开头、中间和结尾空白字符
	virtual XByteArray simplified() const noexcept;

public:
	// 判断字符是否是空白字符 ('\t','\n','\v','\f','\r','_') 中的一个
	static bool isSpace(char _Char) noexcept;

	// 格式化 ByteArray (char* [%s]) (wchar_t* [%ls])
	static XByteArray XANADUAPI format(const char* _Format, ...) noexcept;

public:
	// 按指定数据分割数组
	virtual std::list<XByteArray> split(char _Char) const noexcept;

	// 按指定数据分割数组
	virtual std::list<XByteArray> split(const char* _Memory) const noexcept;

	// 按指定数据分割数组
	virtual std::list<XByteArray> split(const char* _Memory, size_type _Size) const noexcept;

	// 按指定数据分割数组
	virtual std::list<XByteArray> split(const XByteArray& _Bytes) const noexcept;

public:
	// 转换至 Base64
	virtual XByteArray toBase64() const noexcept;

	// 转换至 HEX ，默认大写
	virtual XByteArray toHex() const noexcept;

	// 从内存构建对象
	static XByteArray XANADUAPI fromMemory(const char* _Memory, size_type _Size) noexcept;

	// 从 Base64 构建对象
	static XByteArray XANADUAPI fromBase64(const void* _Memory, size_type _Size) noexcept;

	// 从 Base64 构建对象
	static XByteArray XANADUAPI fromBase64(const XByteArray& _Bytes) noexcept;

	// 从 HEX 构建对象
	static XByteArray XANADUAPI fromHex(const void* _Memory, size_type _Size = XByteArray::npos) noexcept;

	// 从 HEX 构建对象
	static XByteArray XANADUAPI fromHex(const XByteArray& _Bytes) noexcept;
};

#endif

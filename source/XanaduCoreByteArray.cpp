//
// Created by Administrator on 2020/12/31.
//

#include <XanaduCore/XanaduCoreByteArray.h>

static char				_StaticIndexBeyond = '\0';

static const char*			_StaticBase64String = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

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

/// Check for Base64 characters
unsigned char XanaduByteArrayFindBase64(unsigned char _Char)
{
	auto		vLength = Xanadu::strlen(_StaticBase64String);
	for(auto vIndex = 0U; vIndex < vLength; ++vIndex)
	{
		if(_StaticBase64String[vIndex] == _Char)
		{
			return static_cast<unsigned char>(vIndex);
		}
	}
	return static_cast<unsigned char>(-1);
}


/// Constructors
XByteArray::XByteArray() XANADU_NOTHROW : XAllocator()
{
}

/// Constructors
XByteArray::XByteArray(const char* _Memory, int _Size) XANADU_NOTHROW : XAllocator(_Memory, _Size)
{
}

/// Constructors
XByteArray::XByteArray(int _Size, char _Char) XANADU_NOTHROW : XAllocator(_Size, _Char)
{
}

/// Constructors
XByteArray::XByteArray(int _Size) XANADU_NOTHROW : XAllocator(_Size)
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
int32S XByteArray::size() const XANADU_NOTHROW
{
	return XAllocator::MemoryLength();
}



/// Read by subscript
char XByteArray::at(int64S _Index) const XANADU_NOTHROW
{
	if (0 <= _Index && _Index < size())
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
char& XByteArray::operator [] (int64S _Index) XANADU_NOTHROW
{
	if (0 <= _Index && _Index < size())
	{
		return data()[_Index];
	}
	return _StaticIndexBeyond;
}

/// Read by subscript
char XByteArray::operator [] (int64S _Index) const XANADU_NOTHROW
{
	return this->at(_Index);
}



/// Convert to Base64
XByteArray XByteArray::ToBase64() const XANADU_NOTHROW
{
	auto		vLength = this->size();
	auto 		vSource = (const unsigned char*)this->data();
	auto		vTarget = XByteArray();
	if(vSource)
	{
		int		vIndex = 0;
		int		vJ = 0;
		unsigned char	vArray3[3];
		unsigned char	vArray4[4];
		while(vLength--)
		{
			vArray3[vIndex++] = *(vSource++);
			if(vIndex == 3)
			{
				vArray4[0] = (vArray3[0] & 0xfc) >> 2;
				vArray4[1] = ((vArray3[0] & 0x03) << 4) + ((vArray3[1] & 0xf0) >> 4);
				vArray4[2] = ((vArray3[1] & 0x0f) << 2) + ((vArray3[2] & 0xc0) >> 6);
				vArray4[3] = vArray3[2] & 0x3f;
				for(vIndex = 0; (vIndex < 4); vIndex++)
				{
					vTarget += _StaticBase64String[vArray4[vIndex]];
				}
				vIndex = 0;
			}
		}
		if(vIndex)
		{
			for(vJ = vIndex; vJ < 3; vJ++)
			{
				vArray3[vJ] = '\0';
			}
			vArray4[0] = (vArray3[0] & 0xfc) >> 2;
			vArray4[1] = ((vArray3[0] & 0x03) << 4) + ((vArray3[1] & 0xf0) >> 4);
			vArray4[2] = ((vArray3[1] & 0x0f) << 2) + ((vArray3[2] & 0xc0) >> 6);
			vArray4[3] = vArray3[2] & 0x3f;
			for(vJ = 0; (vJ < vIndex + 1); vJ++)
			{
				vTarget += _StaticBase64String[vArray4[vJ]];
			}
			while((vIndex++ < 3))
			{
				vTarget += '=';
			}
		}
	}
	return vTarget;
}

/// Convert to HEX
XByteArray XByteArray::ToHex() const XANADU_NOTHROW
{
	auto		vTarget = XByteArray(this->size() * 2);
	char		vBufferHex[3] = {0};
	for (auto vIndex = 0; vIndex < this->size(); ++vIndex)
	{
		sprintf(vBufferHex, "%02X", this->at(vIndex));
		vTarget[vIndex * 2 + 0] = vBufferHex[0];
		vTarget[vIndex * 2 + 1] = vBufferHex[1];
	}
	return vTarget;
}

/// Format from memory
XByteArray XANADUAPI XByteArray::FromMemory(const char* _Memory, int _Size) XANADU_NOTHROW
{
	return XByteArray(_Memory, _Size);
}

/// Format from Base64
XByteArray XANADUAPI XByteArray::FromBase64(const void* _Memory, int _Size) XANADU_NOTHROW
{
	auto		vLength = _Size;
	auto 		vSource = (const unsigned char*)_Memory;
	auto		vTarget = XByteArray();
	if(vSource)
	{
		int		vIndex = 0;
		int		vJ = 0;
		int		vIn = 0;
		unsigned char	vArray4[4];
		unsigned char	vArray3[3];
		while(vLength-- && (vSource[vIn] != '=') && XanaduByteArrayIsBase64(vSource[vIn]))
		{
			vArray4[vIndex++] = vSource[vIn];
			vIn++;
			if(vIndex == 4)
			{
				for(vIndex = 0; vIndex < 4; vIndex++)
				{
					vArray4[vIndex] = XanaduByteArrayFindBase64(vArray4[vIndex]);
				}

				vArray3[0] = (vArray4[0] << 2) + ((vArray4[1] & 0x30) >> 4);
				vArray3[1] = ((vArray4[1] & 0xf) << 4) + ((vArray4[2] & 0x3c) >> 2);
				vArray3[2] = ((vArray4[2] & 0x3) << 6) + vArray4[3];

				for(vIndex = 0; (vIndex < 3); vIndex++)
				{
					vTarget += vArray3[vIndex];
				}
				vIndex = 0;
			}
		}
		if(vIndex)
		{
			for(vJ = vIndex; vJ < 4; vJ++)
			{
				vArray4[vJ] = 0;
			}
			for(vJ = 0; vJ < 4; vJ++)
			{
				vArray4[vJ] = XanaduByteArrayFindBase64(vArray4[vJ]);
			}
			vArray3[0] = (vArray4[0] << 2) + ((vArray4[1] & 0x30) >> 4);
			vArray3[1] = ((vArray4[1] & 0xf) << 4) + ((vArray4[2] & 0x3c) >> 2);
			vArray3[2] = ((vArray4[2] & 0x3) << 6) + vArray4[3];
			for(vJ = 0; (vJ < vIndex - 1); vJ++)
			{
				vTarget += vArray3[vJ];
			}
		}
	}
	return vTarget;
}

/// Format from Base64
XByteArray XANADUAPI XByteArray::FromBase64(const XByteArray& _Bytes) XANADU_NOTHROW
{
	return XByteArray::FromBase64(_Bytes.data(), _Bytes.size());
}

/// Format from HEX
XByteArray XANADUAPI XByteArray::FromHex(const void* _Memory, int _Size) XANADU_NOTHROW
{
	if (nullptr == _Memory || _Size <= 0)
	{
		return XByteArray();
	}

	auto		vBuffer = static_cast<const char*>(_Memory);
	auto		vLength = _Size / 2;
	auto		vTarget = XByteArray(vLength);
	if(_Memory && _Size > 0)
	{
		for (auto vIndex = 0; vIndex < vLength; ++vIndex)
		{
			auto		vHexLeft = XanaduByteArrayHexToInt8U(vBuffer[vIndex * 2 + 0]);
			auto		vHexRight = XanaduByteArrayHexToInt8U(vBuffer[vIndex * 2 + 1]);

			vTarget[vIndex] = vHexLeft * 16 + vHexRight;
		}
	}
	return vTarget;
}

/// Format from HEX
XByteArray XANADUAPI XByteArray::FromHex(const XByteArray& _Bytes) XANADU_NOTHROW
{
	return XByteArray::FromHex(_Bytes.data(), _Bytes.size());
}

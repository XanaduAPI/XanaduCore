//
// Created by Administrator on 2021/1/20.
//

#include <XanaduCore/XanaduCoreBase64.h>

static unsigned char _StaticAlphabetMap[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static unsigned char _StaticReverseMap[] =
{
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 62, 255, 255, 255, 63,
	52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 255, 255, 255, 255, 255, 255,
	255,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
	15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 255, 255, 255, 255, 255,
	255, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 255, 255, 255, 255, 255
};


/// Structure
XCryptoBase64::XCryptoBase64() XANADU_NOTHROW
{
}

/// Virtual destructor
XCryptoBase64::~XCryptoBase64() XANADU_NOTHROW
{
}




/// Encoded in BASE64
XByteArray XCryptoBase64::Encode(const void* _Memory, int64U _Length) XANADU_NOTHROW
{
	if(nullptr == _Memory || 0 == _Length)
	{
		return XByteArray();
	}
	auto		vSource = static_cast<const unsigned char*>(_Memory);
	auto		vBytes = XByteArray();
	auto		vIndex = 0ULL;
	for (vIndex = 0; vIndex + 3 <= _Length; vIndex += 3)
	{
		/// 取出第一个字符的前6位并找出对应的结果字符
		vBytes += _StaticAlphabetMap[vSource[vIndex] >> 2];
		/// 将第一个字符的后2位与第二个字符的前4位进行组合并找到对应的结果字符
		vBytes += _StaticAlphabetMap[((vSource[vIndex] << 4) & 0x30) | (vSource[vIndex + 1] >> 4)];
		/// 将第二个字符的后4位与第三个字符的前2位组合并找出对应的结果字符
		vBytes += _StaticAlphabetMap[((vSource[vIndex + 1] << 2) & 0x3c) | (vSource[vIndex + 2] >> 6)];
		/// 取出第三个字符的后6位并找出结果字符
		vBytes += _StaticAlphabetMap[vSource[vIndex + 2] & 0x3f];
	}

	if (vIndex < _Length)
	{
		auto		tail = _Length - vIndex;
		if (tail == 1)
		{
			vBytes += _StaticAlphabetMap[vSource[vIndex] >> 2];
			vBytes += _StaticAlphabetMap[(vSource[vIndex] << 4) & 0x30];
			vBytes += '=';
			vBytes += '=';
		}
		else //tail==2
		{
			vBytes += _StaticAlphabetMap[vSource[vIndex] >> 2];
			vBytes += _StaticAlphabetMap[((vSource[vIndex] << 4) & 0x30) | (vSource[vIndex + 1] >> 4)];
			vBytes += _StaticAlphabetMap[(vSource[vIndex + 1] << 2) & 0x3c];
			vBytes += '=';
		}
	}
	return vBytes;
}

/// Encoded in BASE64
XByteArray XCryptoBase64::Encode(const XByteArray& _Bytes) XANADU_NOTHROW
{
	return XCryptoBase64::Encode(_Bytes.data(), _Bytes.size());
}

/// Decoded in BASE64
XByteArray XCryptoBase64::Decode(const void* _Memory, int64U _Length) XANADU_NOTHROW
{
	if(nullptr == _Memory || 0 == _Length || (_Length % 4))
	{
		return XByteArray();
	}

	auto		vSource = static_cast<const unsigned char*>(_Memory);
	auto		vBytes = XByteArray();
	auto		vIndex = 0ULL;
	unsigned char	vQuad[4];
	for (vIndex = 0; vIndex < _Length; vIndex+=4)
	{
		for (auto k = 0ULL; k < 4ULL; ++k)
		{
			/// 分组，每组四个分别依次转换为base64表内的十进制数
			vQuad[k] = _StaticReverseMap[vSource[vIndex + k]];
		}
		/// assert(vQuad[0] < 64 && vQuad[1] < 64);
		/// 取出第一个字符对应base64表的十进制数的前6位与第二个字符对应base64表的十进制数的前2位进行组合
		vBytes += (vQuad[0] << 2) | (vQuad[1] >> 4);

		if (vQuad[2] >= 64)
		{
			break;
		}
		else if (vQuad[3] >= 64)
		{
			/// 取出第二个字符对应base64表的十进制数的后4位与第三个字符对应base64表的十进制数的前4位进行组合
			vBytes += (vQuad[1] << 4) | (vQuad[2] >> 2);
			break;
		}
		else
		{
			vBytes += (vQuad[1] << 4) | (vQuad[2] >> 2);
			/// 取出第三个字符对应base64表的十进制数的后2位与第4个字符进行组合
			vBytes += (vQuad[2] << 6) | vQuad[3];
		}
	}
	return vBytes;
}

/// Decoded in BASE64
XByteArray XCryptoBase64::Decode(const XByteArray& _Bytes) XANADU_NOTHROW
{
	return XCryptoBase64::Decode(_Bytes.data(), _Bytes.size());
}

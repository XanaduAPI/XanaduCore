//
// Created by Administrator on 2021/1/20.
//

#include <XanaduCore/XanaduCoreBase64.h>

// Structure
XBase64::XBase64() noexcept
{
}

// Virtual destructor
XBase64::~XBase64() noexcept
{
}




// Encoded in BASE64
XByteArray XBase64::encode(const void* _Memory, int64U _Length) noexcept
{
	if(nullptr == _Memory || 0 == _Length)
	{
		return XByteArray();
	}

	const char	vAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	auto		vByteArray = static_cast<const unsigned char*>(_Memory);
	auto		vPadchar = static_cast<const char>('=');
	auto		vPadLength = static_cast<int>(0);
	auto		vIndex = static_cast<int>(0);
	auto		vEncode = XByteArray((_Length + 2) / 3 * 4);
	char*		vBuffer = vEncode.data();
	while(vIndex < _Length)
	{
		// encode 3 bytes at a time
		auto		vChunk = static_cast<int>(0);
		vChunk |= int((unsigned char)(vByteArray[vIndex++])) << 16;
		if(vIndex == _Length)
		{
			vPadLength = 2;
		}
		else
		{
			vChunk |= int((unsigned char)(vByteArray[vIndex++])) << 8;
			if(vIndex == _Length)
			{
				vPadLength = 1;
			}
			else
			{
				vChunk |= int((unsigned char)(vByteArray[vIndex++]));
			}
		}

		auto		vValue1 = (vChunk & 0x00FC0000) >> 18;
		auto		vValue2 = (vChunk & 0x0003F000) >> 12;
		auto		vValue3 = (vChunk & 0x00000FC0) >> 6;
		auto		vValue4 = (vChunk & 0x0000003F);
		*vBuffer++ = vAlphabet[vValue1];
		*vBuffer++ = vAlphabet[vValue2];

		if(vPadLength > 1)
		{
			*vBuffer++ = vPadchar;
		}
		else
		{
			*vBuffer++ = vAlphabet[vValue3];
		}
		if(vPadLength > 0)
		{
			*vBuffer++ = vPadchar;
		}
		else
		{
			*vBuffer++ = vAlphabet[vValue4];
		}
	}
	vEncode.truncate(vBuffer - vEncode.data());
	return vEncode;
}

// Encoded in BASE64
XByteArray XBase64::encode(const XByteArray& _Bytes) noexcept
{
	return XBase64::encode(_Bytes.data(), _Bytes.size());
}

// Decoded in BASE64
XByteArray XBase64::decode(const void* _Memory, int64U _Length) noexcept
{
	if(nullptr == _Memory || 0 == _Length || (_Length % 4))
	{
		return XByteArray();
	}

	auto		vBase64 = static_cast<const unsigned char*>(_Memory);
	auto		vBuffer = static_cast<unsigned int>(0);
	auto		vBits = static_cast<int>(0);
	auto		vOffset = static_cast<int>(0);
	auto		vBytes = XByteArray((_Length * 3) / 4);

	for(auto vIndex = 0; vIndex < _Length; ++vIndex)
	{
		auto		vChar = static_cast<int>(vBase64[vIndex]);
		auto		vValue = static_cast<int>(0);

		if(vChar >= 'A' && vChar <= 'Z')
		{
			vValue = vChar - 'A';
		}
		else if(vChar >= 'a' && vChar <= 'z')
		{
			vValue = vChar - 'a' + 26;
		}
		else if(vChar >= '0' && vChar <= '9')
		{
			vValue = vChar - '0' + 52;
		}
		else if(vChar == '+')
		{
			vValue = 62;
		}
		else if(vChar == '/')
		{
			vValue = 63;
		}
		else
		{
			vValue = -1;
		}

		if(vValue != -1)
		{
			vBuffer = (vBuffer << 6) | vValue;
			vBits += 6;
			if(vBits >= 8)
			{
				vBits -= 8;
				vBytes[vOffset++] = vBuffer >> vBits;
				vBuffer &= (1 << vBits) - 1;
			}
		}
	}

	vBytes.truncate(vOffset);
	return vBytes;
}

// Decoded in BASE64
XByteArray XBase64::decode(const XByteArray& _Bytes) noexcept
{
	return XBase64::decode(_Bytes.data(), _Bytes.size());
}

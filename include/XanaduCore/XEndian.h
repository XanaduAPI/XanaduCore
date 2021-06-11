#ifndef			_XANADU_CORE_ENDIAN_H_
#define			_XANADU_CORE_ENDIAN_H_

#include <XanaduCore/XHeader.h>

///  <summary>
///  Big little XEndian convert
///  </summary>
class XANADU_CORE_EXPORT XEndian
{
public:
	// constructor
	XEndian() noexcept;

	// destructor
	virtual ~XEndian() noexcept;

public:
	// Check whether the operating system is in big-endian order
	static bool is_big() noexcept;

	// Check whether the operating system is in little-endian order
	static bool is_little() noexcept;

public:
	// reverse : memory
	static void reverse(void* _Memory, std::size_t _Size) noexcept;

public:
	// reverse : short
	static short reverse(short _Number) noexcept;

	// reverse : unsigned short
	static unsigned short reverse(unsigned short _Number) noexcept;

	// reverse : int
	static int reverse(int _Number) noexcept;

	// reverse : unsigned int
	static unsigned int reverse(unsigned int _Number) noexcept;

	// reverse : long
	static long reverse(long _Number) noexcept;

	// reverse : unsigned long
	static unsigned long reverse(unsigned long _Number) noexcept;

	// reverse : long long
	static long long reverse(long long _Number) noexcept;

	// reverse : unsigned short
	static unsigned long long reverse(unsigned long long _Number) noexcept;

public:
	// Conversion from native byte order to network byte order : short
	static short host_to_network(short _Number) noexcept;

	// Conversion from native byte order to network byte order : unsigned short
	static unsigned short host_to_network(unsigned short _Number) noexcept;

	// Conversion from native byte order to network byte order : int
	static int host_to_network(int _Number) noexcept;

	// Conversion from native byte order to network byte order : unsigned int
	static unsigned int host_to_network(unsigned int _Number) noexcept;

	// Conversion from native byte order to network byte order : long
	static long host_to_network(long _Number) noexcept;

	// Conversion from native byte order to network byte order : unsigned long
	static unsigned long host_to_network(unsigned long _Number) noexcept;

	// Conversion from native byte order to network byte order : long long
	static long long host_to_network(long long _Number) noexcept;

	// Conversion from native byte order to network byte order : unsigned short
	static unsigned long long host_to_network(unsigned long long _Number) noexcept;

public:
	// Conversion from network byte order to native byte order : short
	static short network_to_host(short _Number) noexcept;

	// Conversion from network byte order to native byte order : unsigned short
	static unsigned short network_to_host(unsigned short _Number) noexcept;

	// Conversion from network byte order to native byte order : int
	static int network_to_host(int _Number) noexcept;

	// Conversion from network byte order to native byte order : unsigned int
	static unsigned int network_to_host(unsigned int _Number) noexcept;

	// Conversion from network byte order to native byte order : long
	static long network_to_host(long _Number) noexcept;

	// Conversion from network byte order to native byte order : unsigned long
	static unsigned long network_to_host(unsigned long _Number) noexcept;

	// Conversion from network byte order to native byte order : long long
	static long long network_to_host(long long _Number) noexcept;

	// Conversion from network byte order to native byte order : unsigned short
	static unsigned long long network_to_host(unsigned long long _Number) noexcept;

public:
	// Conversion from native byte order to big-endian order : short
	static short host_to_big(short _Number) noexcept;

	// Conversion from native byte order to big-endian order : unsigned short
	static unsigned short host_to_big(unsigned short _Number) noexcept;

	// Conversion from native byte order to big-endian order : int
	static int host_to_big(int _Number) noexcept;

	// Conversion from native byte order to big-endian order : unsigned int
	static unsigned int host_to_big(unsigned int _Number) noexcept;

	// Conversion from native byte order to big-endian order : long
	static long host_to_big(long _Number) noexcept;

	// Conversion from native byte order to big-endian order : unsigned long
	static unsigned long host_to_big(unsigned long _Number) noexcept;

	// Conversion from native byte order to big-endian order : long long
	static long long host_to_big(long long _Number) noexcept;

	// Conversion from native byte order to big-endian order : unsigned short
	static unsigned long long host_to_big(unsigned long long _Number) noexcept;

public:
	// Conversion from big-endian order to native byte order : short
	static short big_to_host(short _Number) noexcept;

	// Conversion from big-endian order to native byte order : unsigned short
	static unsigned short big_to_host(unsigned short _Number) noexcept;

	// Conversion from big-endian order to native byte order : int
	static int big_to_host(int _Number) noexcept;

	// Conversion from big-endian order to native byte order : unsigned int
	static unsigned int big_to_host(unsigned int _Number) noexcept;

	// Conversion from big-endian order to native byte order : long
	static long big_to_host(long _Number) noexcept;

	// Conversion from big-endian order to native byte order : unsigned long
	static unsigned long big_to_host(unsigned long _Number) noexcept;

	// Conversion from big-endian order to native byte order : long long
	static long long big_to_host(long long _Number) noexcept;

	// Conversion from big-endian order to native byte order : unsigned short
	static unsigned long long big_to_host(unsigned long long _Number) noexcept;

public:
	// Conversion from native byte order to little-endian order : short
	static short host_to_little(short _Number) noexcept;

	// Conversion from native byte order to little-endian order : unsigned short
	static unsigned short host_to_little(unsigned short _Number) noexcept;

	// Conversion from native byte order to little-endian order : int
	static int host_to_little(int _Number) noexcept;

	// Conversion from native byte order to little-endian order : unsigned int
	static unsigned int host_to_little(unsigned int _Number) noexcept;

	// Conversion from native byte order to little-endian order : long
	static long host_to_little(long _Number) noexcept;

	// Conversion from native byte order to little-endian order : unsigned long
	static unsigned long host_to_little(unsigned long _Number) noexcept;

	// Conversion from native byte order to little-endian order : long long
	static long long host_to_little(long long _Number) noexcept;

	// Conversion from native byte order to little-endian order : unsigned short
	static unsigned long long host_to_little(unsigned long long _Number) noexcept;

public:
	// Conversion from little-endian order to native byte order : short
	static short little_to_host(short _Number) noexcept;

	// Conversion from little-endian order to native byte order : unsigned short
	static unsigned short little_to_host(unsigned short _Number) noexcept;

	// Conversion from little-endian order to native byte order : int
	static int little_to_host(int _Number) noexcept;

	// Conversion from little-endian order to native byte order : unsigned int
	static unsigned int little_to_host(unsigned int _Number) noexcept;

	// Conversion from little-endian order to native byte order : long
	static long little_to_host(long _Number) noexcept;

	// Conversion from little-endian order to native byte order : unsigned long
	static unsigned long little_to_host(unsigned long _Number) noexcept;

	// Conversion from little-endian order to native byte order : long long
	static long long little_to_host(long long _Number) noexcept;

	// Conversion from little-endian order to native byte order : unsigned short
	static unsigned long long little_to_host(unsigned long long _Number) noexcept;
};

#endif

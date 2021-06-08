#include <XanaduRuntime/Socket.h>



XANADU_RUNTIME_EXPORT struct hostent* XANADUAPI Xanadu::gethostbyname(const char* _Name) noexcept
{
	XANADU_CHECK_RETURN(_Name, nullptr);

	return ::gethostbyname(_Name);
}

XANADU_RUNTIME_EXPORT SOCKET XANADUAPI Xanadu::socket(int _Family, int _Type, int _Protocol) noexcept
{
	return ::socket(_Family, _Type, _Protocol);
}

XANADU_RUNTIME_EXPORT SOCKET XANADUAPI Xanadu::accept(SOCKET _Socket, struct sockaddr* _Address, socklen_t* _Length) noexcept
{
	XANADU_CHECK_RETURN(_Address, (SOCKET)SOCKET_ERROR);
	XANADU_CHECK_RETURN(_Length, (SOCKET)SOCKET_ERROR);

	return ::accept(_Socket, _Address, _Length);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::bind(SOCKET _Socket, const struct sockaddr* _Address, socklen_t _Length) noexcept
{
	XANADU_CHECK_RETURN(_Address, SOCKET_ERROR);

	return ::bind(_Socket, _Address, _Length);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::socketclose(SOCKET _Socket) noexcept
{
	if (_Socket > 0)
	{
#if defined(XANADU_SYSTEM_WINDOWS)
		return ::closesocket(_Socket);
#else
		return ::close(_Socket);
#endif
	}
	return -1;
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::connect(SOCKET _Socket, const struct sockaddr* _Address, socklen_t _Length) noexcept
{
	XANADU_CHECK_RETURN(_Address, SOCKET_ERROR);

	return ::connect(_Socket, _Address, _Length);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::getpeername(SOCKET _Socket, struct sockaddr* _Address, socklen_t* _Length) noexcept
{
	XANADU_CHECK_RETURN(_Address, SOCKET_ERROR);
	XANADU_CHECK_RETURN(_Length, SOCKET_ERROR);

	return ::getpeername(_Socket, _Address, _Length);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::getsockname(SOCKET _Socket, struct sockaddr* _Address, socklen_t* _Length) noexcept
{
	XANADU_CHECK_RETURN(_Address, SOCKET_ERROR);
	XANADU_CHECK_RETURN(_Length, SOCKET_ERROR);

	return ::getsockname(_Socket, _Address, _Length);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::getsockopt(SOCKET _Socket, int _Level, int _OptName, void* _OptValue, socklen_t* _OptLength) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return ::getsockopt(_Socket, _Level, _OptName, (char*)_OptValue, _OptLength);
#else
	return ::getsockopt(_Socket, _Level, _OptName, _OptValue, _OptLength);
#endif
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::setsockopt(SOCKET _Socket, int _Level, int _OptName, const void* _OptValue, socklen_t _OptLength) noexcept
{
#if defined(XANADU_SYSTEM_WINDOWS)
	return ::setsockopt(_Socket, _Level, _OptName, (const char*)_OptValue, _OptLength);
#else
	return ::setsockopt(_Socket, _Level, _OptName, _OptValue, _OptLength);
#endif
}

XANADU_RUNTIME_EXPORT struct in_addr XANADUAPI Xanadu::inet_addr(const char* _CP) noexcept
{
	struct in_addr		vAddress{};
	vAddress.s_addr = ::inet_addr(_CP);
	return vAddress;
}

XANADU_RUNTIME_EXPORT char* XANADUAPI Xanadu::inet_ntoa(struct in_addr _IN) noexcept
{
	return ::inet_ntoa(_IN);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::listen(SOCKET _Socket, int _Backlog) noexcept
{
	return ::listen(_Socket, _Backlog);
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::recv(SOCKET _Socket, void* _Buffer, int _Length, int _Flags) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, SOCKET_ERROR);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::recv(_Socket, (char*)_Buffer, _Length, _Flags);
#else
	return ::recv(_Socket, _Buffer, _Length, _Flags);
#endif
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::recvfrom(SOCKET _Socket, void* _Buffer, int _Length, int _Flags, struct sockaddr* _From, socklen_t* _Fromlen) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, SOCKET_ERROR);
	XANADU_CHECK_RETURN(_From, SOCKET_ERROR);
	XANADU_CHECK_RETURN(_Fromlen, SOCKET_ERROR);
#if defined(XANADU_SYSTEM_WINDOWS)
	return ::recvfrom(_Socket, (char*)_Buffer, _Length, _Flags, _From, _Fromlen);
#else
	return ::recvfrom(_Socket, _Buffer, _Length, _Flags, _From, _Fromlen);
#endif
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::send(SOCKET _Socket, const void* _Buffer, int _Length, int _Flags) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, SOCKET_ERROR);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::send(_Socket, (const char*)_Buffer, _Length, _Flags);
#else
	return ::send(_Socket, _Buffer, _Length, _Flags);
#endif
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::sendto(SOCKET _Socket, const void* _Buffer, int _Length, int _Flags, const struct sockaddr* _To, socklen_t _Tolen) noexcept
{
	XANADU_CHECK_RETURN(_Buffer, SOCKET_ERROR);
	XANADU_CHECK_RETURN(_To, SOCKET_ERROR);

#if defined(XANADU_SYSTEM_WINDOWS)
	return ::sendto(_Socket, (const char*)_Buffer, _Length, _Flags, _To, _Tolen);
#else
	return ::sendto(_Socket, _Buffer, _Length, _Flags, _To, _Tolen);
#endif
}

XANADU_RUNTIME_EXPORT int XANADUAPI Xanadu::shutdown(SOCKET _Socket, int _Now) noexcept
{
	XANADU_CHECK_RETURN(_Socket > 0, -1);

	return ::shutdown(_Socket, _Now);
}

#ifndef			_XANADU_RUNTIME_SOCKET_H_
#define			_XANADU_RUNTIME_SOCKET_H_

#include <XanaduRuntime/Header.h>

#ifndef XANADU_SYSTEM_WINDOWS
typedef			int							SOCKET;
#define			INVALID_SOCKET						(SOCKET)(~0)
#define			SOCKET_ERROR						(SOCKET)(-1)
#endif

namespace Xanadu
{
	XANADU_RUNTIME_EXPORT struct hostent* XANADUAPI gethostbyname(const char* _Name) noexcept;

	XANADU_RUNTIME_EXPORT SOCKET XANADUAPI socket(int _Family, int _Type, int _Protocol) noexcept;

	XANADU_RUNTIME_EXPORT SOCKET XANADUAPI accept(SOCKET _Socket, struct sockaddr* _Address, socklen_t* _Length) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI bind(SOCKET _Socket, const struct sockaddr* _Address, socklen_t _Length) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI socketclose(SOCKET _Socket) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI connect(SOCKET _Socket, const struct sockaddr* _Address, socklen_t _Length) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI getpeername(SOCKET _Socket, struct sockaddr* _Address, socklen_t* _Length) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI getsockname(SOCKET _Socket, struct sockaddr* _Address, socklen_t* _Length) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI getsockopt(SOCKET _Socket, int _Level, int _OptName, void* _OptValue, socklen_t* _OptLength) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI setsockopt(SOCKET _Socket, int level, int _OptName, const void* _OptValue, socklen_t _OptLength) noexcept;

	XANADU_RUNTIME_EXPORT struct in_addr XANADUAPI inet_addr(const char* _CP) noexcept;

	XANADU_RUNTIME_EXPORT char* XANADUAPI inet_ntoa(struct in_addr _IN) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI listen(SOCKET _Socket, int _Backlog) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI recv(SOCKET _Socket, void* _Buffer, int _Length, int _Flags) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI recvfrom(SOCKET _Socket, void* _Buffer, int _Length, int _Flags, struct sockaddr* _From, socklen_t* _Fromlen) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI send(SOCKET _Socket, const void* _Buffer, int _Length, int _Flags) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI sendto(SOCKET _Socket, const void* _Buffer, int _Length, int _Flags, const struct sockaddr* _To, socklen_t _Tolen) noexcept;

	XANADU_RUNTIME_EXPORT int XANADUAPI shutdown(SOCKET _Socket, int _Now) noexcept;
};

#endif

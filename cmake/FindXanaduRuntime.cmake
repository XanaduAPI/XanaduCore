# 辅助输出信息
message("now using FindXanaduRuntime.cmake find")

# 将头文件路径赋值给 XANADU_RUNTIME_INCLUDE
if (WIN32)
	FIND_PATH(XANADU_RUNTIME_INCLUDE XanaduRuntime/ C:/Xanadu/include/)
elseif (MINGW)
	FIND_PATH(XANADU_RUNTIME_INCLUDE XanaduRuntime/ /usr/include/)
elseif (APPLE)
	FIND_PATH(XANADU_RUNTIME_INCLUDE XanaduRuntime/ /usr/local/include/)
elseif (UNIX)
	FIND_PATH(XANADU_RUNTIME_INCLUDE XanaduRuntime/ /usr/include/)
endif ()

# 将 XanaduRuntime.lib 文件路径赋值给 XANADU_RUNTIME_LIBRARY
if (WIN32)
	FIND_PATH(XANADU_RUNTIME_LIBRARY XanaduRuntime.lib C:/Xanadu/lib/)
elseif (MINGW)
	FIND_PATH(XANADU_RUNTIME_LIBRARY XanaduRuntime.dll.a /usr/lib/)
elseif (APPLE)
	FIND_PATH(XANADU_RUNTIME_LIBRARY libXanaduRuntime.dylib /usr/local/lib/)
elseif (UNIX)
	FIND_PATH(XANADU_RUNTIME_LIBRARY libXanaduRuntime.so /usr/lib/)
endif ()

message("XANADU_RUNTIME_INCLUDE: ${XANADU_RUNTIME_INCLUDE}")
message("XANADU_RUNTIME_LIBRARY: ${XANADU_RUNTIME_LIBRARY}")

if(XANADU_RUNTIME_INCLUDE AND XANADU_RUNTIME_LIBRARY)
	# 设置变量结果
	set(XANADU_RUNTIME_FOUND TRUE)
endif(XANADU_RUNTIME_INCLUDE AND XANADU_RUNTIME_LIBRARY)

# 辅助输出信息
message("now using FindXanaduRuntime.cmake find")

# 将头文件路径赋值给 XANADU_RUNTIME_INCLUDE
IF (WIN32)
	FIND_PATH(XANADU_RUNTIME_INCLUDE XanaduRuntime/ C:/Xanadu/include/)
ELSEIF (MINGW)
	FIND_PATH(XANADU_RUNTIME_INCLUDE /usr/include/XanaduRuntime)
ELSEIF (APPLE)
	FIND_PATH(XANADU_RUNTIME_INCLUDE /usr/local/include/XanaduRuntime)
ELSEIF (UNIX)
	FIND_PATH(XANADU_RUNTIME_INCLUDE /usr/include/XanaduRuntime)
ENDIF (WIN32)

# 将 XanaduRuntime.lib 文件路径赋值给 XANADU_RUNTIME_LIBRARY
IF (WIN32)
	FIND_PATH(XANADU_RUNTIME_LIBRARY XanaduRuntime.lib C:/Xanadu/lib/)
ELSEIF (MINGW)
	FIND_PATH(XANADU_RUNTIME_LIBRARY XanaduRuntime.dll.a /usr/lib/)
ELSEIF (APPLE)
	FIND_PATH(XANADU_RUNTIME_LIBRARY XanaduRuntime.dylib /usr/lib/)
ELSEIF (UNIX)
	FIND_PATH(XANADU_RUNTIME_LIBRARY XanaduRuntime.so /usr/lib/)
ENDIF (WIN32)

message("XANADU_RUNTIME_INCLUDE: ${XANADU_RUNTIME_INCLUDE}")
message("XANADU_RUNTIME_LIBRARY: ${XANADU_RUNTIME_LIBRARY}")

if(XANADU_RUNTIME_INCLUDE AND XANADU_RUNTIME_LIBRARY)
	# 设置变量结果
	set(XANADU_RUNTIME_FOUND TRUE)
endif(XANADU_RUNTIME_INCLUDE AND XANADU_RUNTIME_LIBRARY)

# 辅助输出信息
message("now using FindXanaduCore.cmake find")

# 将头文件路径赋值给 XANADU_CORE_INCLUDE
if (WIN32)
	FIND_PATH(XANADU_CORE_INCLUDE XanaduCore/ C:/Xanadu/include/)
elseif (MINGW)
	FIND_PATH(XANADU_CORE_INCLUDE XanaduCore/ /usr/include/)
elseif (APPLE)
	FIND_PATH(XANADU_CORE_INCLUDE XanaduCore/ /usr/local/include/)
elseif (UNIX)
	FIND_PATH(XANADU_CORE_INCLUDE XanaduCore/ /usr/include/)
endif ()

# 将 XanaduCore.lib 文件路径赋值给 XANADU_CORE_LIBRARY
if (WIN32)
	FIND_PATH(XANADU_CORE_LIBRARY XanaduCore.lib C:/Xanadu/lib/)
elseif (MINGW)
	FIND_PATH(XANADU_CORE_LIBRARY XanaduCore.dll.a /usr/lib/)
elseif (APPLE)
	FIND_PATH(XANADU_CORE_LIBRARY libXanaduCore.dylib /usr/local/lib/)
elseif (UNIX)
	FIND_PATH(XANADU_CORE_LIBRARY libXanaduCore.so /usr/lib/)
endif ()

message("XANADU_CORE_INCLUDE: ${XANADU_CORE_INCLUDE}")
message("XANADU_CORE_LIBRARY: ${XANADU_CORE_LIBRARY}")

if(XANADU_CORE_INCLUDE AND XANADU_CORE_LIBRARY)
	# 设置变量结果
	set(XANADU_CORE_FOUND TRUE)
endif(XANADU_CORE_INCLUDE AND XANADU_CORE_LIBRARY)

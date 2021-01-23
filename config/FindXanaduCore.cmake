# Explain
message("using FindXanaduCore.cmake find")

# Find XANADU_CORE_INCLUDE
if (WIN32)
	find_path(XANADU_CORE_INCLUDE XanaduCore/ C:/Xanadu/include/)
elseif (MINGW)
	find_path(XANADU_CORE_INCLUDE XanaduCore/ /usr/include/)
elseif (APPLE)
	find_path(XANADU_CORE_INCLUDE XanaduCore/ /usr/local/include/)
elseif (UNIX)
	find_path(XANADU_CORE_INCLUDE XanaduCore/ /usr/include/)
endif ()

# Find XANADU_CORE_LIBRARY
if (WIN32)
	find_path(XANADU_CORE_LIBRARY XanaduCore.lib C:/Xanadu/lib/)
elseif (MINGW)
	find_path(XANADU_CORE_LIBRARY XanaduCore.dll.a /usr/lib/)
elseif (APPLE)
	find_path(XANADU_CORE_LIBRARY libXanaduCore.dylib /usr/local/lib/)
elseif (UNIX)
	find_path(XANADU_CORE_LIBRARY libXanaduCore.so /usr/lib/)
endif ()

message("XANADU_CORE_INCLUDE: ${XANADU_CORE_INCLUDE}")
message("XANADU_CORE_LIBRARY: ${XANADU_CORE_LIBRARY}")

# Setting
if(XANADU_CORE_INCLUDE AND XANADU_CORE_LIBRARY)
	set(XANADU_CORE_FOUND TRUE)
endif()

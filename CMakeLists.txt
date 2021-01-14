#CMake最低版本号要求
cmake_minimum_required(VERSION 3.8)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
message(${CMAKE_MODULE_PATH})

#项目依赖
find_package(XanaduRuntime REQUIRED)

#项目名称
project(XanaduCore)

#设置Debug后缀
set(CMAKE_DEBUG_POSTFIX "D")

#设置安装路径
message(STATUS "Operation System : ${CMAKE_SYSTEM}")
if (WIN32)
	message(STATUS "Current Platform : WIN32")
	set(CMAKE_INSTALL_PREFIX C:/Xanadu)
elseif (MINGW)
	message(STATUS "Current Platform : MINGW")
	set(CMAKE_INSTALL_PREFIX /usr)
elseif (APPLE)
	message(STATUS "Current Platform : APPLE")
	set(CMAKE_INSTALL_PREFIX /usr/local)
elseif (UNIX)
	message(STATUS "Current Platform : UNIX")
	set(CMAKE_INSTALL_PREFIX /usr)
endif ()


#C++支持
set(CMAKE_CXX_STANDARD 17)

#头文件搜索目录
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${XANADU_RUNTIME_INCLUDE})

#链接库搜索目录
link_directories(${XANADU_RUNTIME_LIBRARY})

#设置静态编译宏
#add_definitions(-DXANADU_CORE_BUILD_STATIC)
#设置导出宏
add_definitions(-DXANADU_CORE_LIB)

#包含源文件
aux_source_directory(./source SRC)

#设置输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#链接库
if (MINGW)
	link_libraries("stdc++")
endif()
if (MSVC AND CMAKE_BUILD_TYPE STREQUAL "Debug")
	link_libraries(XanaduRuntimeD)
else ()
	link_libraries(XanaduRuntime)
endif ()

#构建
add_library(XanaduCore SHARED ${SRC})
#target_link_libraries(XanaduCore debug XanaduRuntimeD)
#target_link_libraries(XanaduCore optimized XanaduRuntime)

#设置项目版本号
set_target_properties(XanaduCore PROPERTIES VERSION 0.1.7 SOVERSION 0)

#设置安装文件(静态库)
install(TARGETS XanaduCore ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
#设置安装文件(动态库)
install(TARGETS XanaduCore LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
#设置安装文件(可执行文件)
#install(TARGETS XanaduCore RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
#设置安装文件(与库关联的PUBLIC头文件)
#install(TARGETS XanaduCore PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
#设置安装文件(与库关联的PRIVATE头文件)
#install(TARGETS XanaduCore PRIVATE_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
#安装头文件
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/XanaduCore DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
#安装头文件
#install(FILES ${PROJECT_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

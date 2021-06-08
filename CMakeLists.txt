# CMake最低版本号要求
cmake_minimum_required(VERSION 3.8)


# 项目名称
project(XanaduCore VERSION 1.0.0)


# 输出提示信息
message(STATUS "Operation System : ${CMAKE_SYSTEM}")
message(STATUS "CMAKE_INSTALL_PREFIX : ${CMAKE_INSTALL_PREFIX}")


# 配置文件
configure_file("${CMAKE_SOURCE_DIR}/config/Find${PROJECT_NAME}.cmake.in" "${CMAKE_BINARY_DIR}/Find${PROJECT_NAME}.cmake")
configure_file("${CMAKE_SOURCE_DIR}/config/${PROJECT_NAME}.pc.in" "${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc")
configure_file("${CMAKE_SOURCE_DIR}/config/VersionInfo.rc.in" "${CMAKE_BINARY_DIR}/VersionInfo.rc")


# 设置模块搜索路径
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_INSTALL_PREFIX}/lib/cmake)


# 项目依赖
find_package(XanaduRuntime REQUIRED)


# C++支持
set(CMAKE_CXX_STANDARD 17)


# 头文件搜索目录
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${XANADU_RUNTIME_INCLUDE})


# 链接库搜索目录
link_directories(${XANADU_RUNTIME_LIBRARY})


# 设置静态编译宏
#add_definitions(-D_XANADU_CORE_BUILD_STATIC)
# 设置导出宏
add_definitions(-D_XANADU_CORE_BUILD_SHARED)
# 启用64位文件操作
add_definitions(-D_FILE_OFFSET_BITS=64)
# 设置异常输出宏
add_definitions(-D_XANADU_EXCEPTION_OUTPUT)
# 屏蔽一些CRT警告
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
# 设置 Debug 宏
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_definitions(-D_DEBUG)
	add_definitions(-D_XANADU_BUILD_DEBUG)
else ()
	add_definitions(-D_XANADU_BUILD_RELEASE)
endif ()


# 包含源文件
aux_source_directory(./source SRC)
aux_source_directory(./source/Hash SRC)
if (MSVC)
	list(APPEND SRC ${CMAKE_BINARY_DIR}/VersionInfo.rc)
endif ()


# 设置输出目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


# 链接库
if (MINGW)
	link_libraries("stdc++")
endif()
if (UNIX)
	link_libraries("pthread")
endif ()
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	link_libraries(XanaduRuntimeD)
else ()
	link_libraries(XanaduRuntime)
endif ()


# 构建
add_library(${PROJECT_NAME} SHARED ${SRC})


# 设置项目属性
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION 1.0.0 SOVERSION 1)
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX D)


# 设置安装文件(静态库)
install(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
# 设置安装文件(动态库)
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
# 设置安装文件(可执行文件)
#install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
# 设置安装文件(与库关联的PUBLIC头文件)
#install(TARGETS ${PROJECT_NAME} PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
# 设置安装文件(与库关联的PRIVATE头文件)
#install(TARGETS ${PROJECT_NAME} PRIVATE_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
# 安装头文件
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
# 安装头文件
#install(FILES ${PROJECT_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
# 配置模块文件
install(FILES ${CMAKE_BINARY_DIR}/Find${PROJECT_NAME}.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/cmake)
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.pc DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig)

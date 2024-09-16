cmake_minimum_required(VERSION 3.3.0)

project(config_parser VERSION 0.0.0 LANGUAGE CXX)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds not allowed. ")
endif()

# 指定c++版本
set(CMAKE_CXX_STANDARD 14)
# 默认导出compile_commands.json文件
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# debug版本加d后缀
set(CMAKE_DEBUG_POSTFIX "_debug")

message(STATUS "Started CMake for ${PROJECT_NAME} v${PROJECT_VERSION}...\n")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
message("install path " ${CMAKE_INSTALL_PREFIX})
cmake_minimum_required(VERSION 3.3.0)

project(config_parser VERSION 0.0.0 LANGUAGES CXX)

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

file(GLOB_RECURSE project_headers ./include/*.h)
file(GLOB_RECURSE project_sources ./src/*.cpp ./*.c)

include_directories(${PROJECT_SOURCE_DIR}/include
)

set(all_files ${project_headers}  ${project_sources})
source_group(TREE "${CMAKE_CURRENT_LIST_DIR}" FILES ${all_files})

add_library(${PROJECT_NAME} SHARED ${all_files})

install(FILES ${project_headers} DESTINATION ${PROJECT_SOURCE_DIR}/install/include/)
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/install/lib
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}//install/bin)

add_subdirectory(examples)

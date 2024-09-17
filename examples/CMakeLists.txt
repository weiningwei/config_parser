project(config_parser_demo)

set(publish_demo_bin_debug ${PROJECT_SOURCE_DIR}/../bin/debug)
set(publish_demo_bin_release ${PROJECT_SOURCE_DIR}/../bin/release)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${publish_demo_bin_debug})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${publish_demo_bin_release})

include_directories(${PROJECT_SOURCE_DIR}/../include())

add_executable(${PROJECT_NAME} 
    config_parser_demo.cpp)

target_link_libraries(${PROJECT_NAME} config_parser)
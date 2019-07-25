cmake_minimum_required(VERSION 3.10)
project(design_pattern)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} design_pattern_app)

target_include_directories(${PROJECT_NAME} PUBLIC include)
message("project[${PROJECT_NAME}]")

target_link_libraries(${PROJECT_NAME} design_pattern_module)


if (CMAKE_HOST_WIN32)
    INSTALL(TARGETS ${PROJECT_NAME} DESTINATION download/bin/win64)
elseif (CMAKE_HOST_APPLE)
    INSTALL(TARGETS ${PROJECT_NAME} DESTINATION download/bin/darwin)
elseif (CMAKE_HOST_UNIX)
    INSTALL(TARGETS ${PROJECT_NAME} DESTINATION download/bin/linux)
endif ()
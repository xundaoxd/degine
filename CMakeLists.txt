cmake_minimum_required(VERSION 3.17)
project(degine VERSION 0.0.1)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "Setting C++ standard to C++${CMAKE_CXX_STANDARD}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pipe")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -rdynamic -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-inline")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

add_subdirectory(degine/proto)

file(GLOB SRCS degine/*.cc degine/*.h)
add_library(degine ${SRCS})
target_include_directories(degine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(degine PUBLIC onnx)

add_subdirectory(example)


include(FetchContent)

FetchContent_Declare(
    onnx
    GIT_REPOSITORY https://github.com/onnx/onnx.git
    GIT_TAG        v1.15.0
)

FetchContent_Populate(onnx)

find_package(Protobuf REQUIRED)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${onnx_SOURCE_DIR}/onnx/onnx.proto)
add_library(onnx ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(onnx PUBLIC protobuf::libprotobuf)
target_include_directories(onnx PUBLIC ${CMAKE_CURRENT_BINARY_DIR})


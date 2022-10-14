cmake_minimum_required(VERSION 3.2)
project(IMAGE_PROCESSING)

enable_language(C CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/lib
    ${PROJECT_SOURCE_DIR}/test
    ${PROJECT_SOURCE_DIR}/examples
)

file(GLOB SOURCES "src/*.cpp")
add_library( engine ${SOURCES} )


add_executable(main.x examples/main.cpp)
add_executable(test.x test/main.cpp)
add_dependencies(test.x engine)
target_link_libraries(test.x engine)
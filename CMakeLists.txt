cmake_minimum_required(VERSION 3.0.0)

set(PROJECT kbcb)
set(CMAKE_C_FLAGS "${CMAKE_CFLAGS} -D${ENV} -DROOT=${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_LINK_LIBS libgit2.a)

include_directories(lib)
include_directories(include)

project(${PROJECT})

file(GLOB SOURCES "src/*.c")

add_executable(${PROJECT} ${SOURCES})
target_link_libraries(${PROJECT} ${PROJECT_LINK_LIBS})
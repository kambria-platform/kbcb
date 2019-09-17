cmake_minimum_required(VERSION 3.0.0)

set(PROJECT kbcb)
set(CMAKE_C_FLAGS "${CMAKE_CFLAGS} -D${ENV} -DROOT=${CMAKE_CURRENT_SOURCE_DIR}")

project(${PROJECT})

file(GLOB SOURCES "src/*.c")

add_executable(${PROJECT} ${SOURCES})
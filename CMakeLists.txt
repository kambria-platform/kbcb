cmake_minimum_required(VERSION 3.0.0)

set(PROJECT kbcb)
set(CMAKE_CXX_FLAGS "${CMAKE_CXXFLAGS} -D${ENV} -DSHARED=${SHARED} -DVER=${VER}")
set(VERSION 1)

project(${PROJECT})

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT} ${SOURCES})

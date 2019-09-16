cmake_minimum_required(VERSION 3.0.0)

set(PROJECT kbcb)

project(${PROJECT})

file(GLOB SOURCES "src/*.c")

add_executable(${PROJECT} ${SOURCES})
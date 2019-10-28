cmake_minimum_required(VERSION 3.10.0)

set(PROJECT kbcb)
set(LIBRARY kbcb.${VER})
set(CMAKE_CXX_FLAGS "${CMAKE_CXXFLAGS}")

project(${PROJECT})

file(GLOB SOURCES "src/*.cpp")
file(GLOB LIB "lib/*.cpp")
# file(GLOB HEADER "include/*.h")
file(GLOB DATADIR "src/hooks/*")

add_definitions(-DENV=${ENV})
add_definitions(-DSHARED=${SHARED})
add_definitions(-DVER=${VER})

# build target
include_directories(include)
add_library(${LIBRARY} ${LIB})
add_executable(${PROJECT} ${SOURCES})
target_link_libraries(${PROJECT} ${LIBRARY})

# install target
install(TARGETS ${PROJECT} DESTINATION bin)
# install(FILES ${HEADER} DESTINATION include)
install(FILES ${DATADIR} DESTINATION share/kbcb)

# uninstall target
if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

    add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

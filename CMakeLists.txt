cmake_minimum_required(VERSION 3.12.0)

set(PROJECT kbcb)
set(LIBRARY kbcb.${VER})
set(CMAKE_CXX_FLAGS "${CMAKE_CXXFLAGS}")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXXFLAGS} -D${ENV} -DSHARED=${SHARED} -DVER=${VER}")

project(${PROJECT})

file(GLOB SOURCES "src/*.cpp")
file(GLOB LIB "lib/*.cpp")
# file(GLOB HEADER "include/*.h")
file(GLOB SHARED "src/hooks/*")

add_compile_definitions(ENV=${ENV})
add_compile_definitions(SHARED=${SHARED})
add_compile_definitions(VER=${VER})

# build target
include_directories(include)
add_library(${LIBRARY} ${LIB})
add_executable(${PROJECT} ${SOURCES})
target_link_libraries(${PROJECT} ${LIBRARY})

# install target
install(TARGETS ${PROJECT} DESTINATION bin)
# install(FILES ${HEADER} DESTINATION include)
install(FILES ${SHARED} DESTINATION share/kbcb)

# uninstall target
if(NOT TARGET uninstall)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)

    add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

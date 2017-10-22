cmake_minimum_required(VERSION 3.3.0)
project(Grawlog VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD TRUE)

include(GoogleTest)
enable_testing()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

option(BUILD_DOCS "TODO: Build documentation" OFF)
option(BUILD_SPECS "TODO: Build scenario's" OFF)
option(BUILD_TESTS "Build tests" OFF)

set(DIR_BASE ${CMAKE_CURRENT_SOURCE_DIR})
set(DIR_INCLUDE ${DIR_BASE}/include)
set(DIR_SPECS ${DIR_BASE}/specs)
set(DIR_SRC ${DIR_BASE}/src)
set(DIR_TESTS ${DIR_BASE}/tests)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0z")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++1z")
else()
endif()

set(TARGET_NAME ${PROJECT_NAME})
set(TARGET_SOURCES
	${DIR_SRC}/Entry.cpp
	${DIR_SRC}/Logger.cpp
	${DIR_SRC}/ManagerImpl.cpp)

add_subdirectory(${DIR_SRC})
add_subdirectory(${DIR_SPECS})
add_subdirectory(${DIR_TESTS})

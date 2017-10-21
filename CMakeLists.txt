cmake_minimum_required(VERSION 3.3.0)
project(Grawlog VERSION 0.1.0 LANGUAGES CXX)

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

set(TARGET_NAME ${PROJECT_NAME})
set(TARGET_SOURCES
	${DIR_SRC}/Entry.cpp
	${DIR_SRC}/Logger.cpp
	${DIR_SRC}/ManagerImpl.cpp)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set(TARGET_COMPILER_FLAGS "${TARGET_COMPILER_FLAGS} /std:c++latest")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(TARGET_COMPILER_FLAGS "${TARGET_COMPILER_FLAGS} -std=c++17")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(TARGET_COMPILER_FLAGS "${TARGET_COMPILER_FLAGS} -std=gnu++1z")
else()
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TARGET_COMPILER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${TARGET_LINKED_FLAGS}")

add_subdirectory(${DIR_SRC})
add_subdirectory(${DIR_SPECS})
add_subdirectory(${DIR_TESTS})

cmake_minimum_required (VERSION 2.6)
find_package(Git QUIET)
project (elevator-sim CXX)

set(BUILD_HEADER_FILES_DIRECTORY "${PROJECT_SOURCE_DIR}/build/include/Elevator")
set(BUILD_LIB_FILES_DIRECTORY "${PROJECT_SOURCE_DIR}/build/lib")

#SET C++ 11
if (CMAKE_VERSION VERSION_LESS "3.1")
    add_definitions(-std=c++11)
else()
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    if(NOT CYGWIN)
        set(CMAKE_CXX_EXTENSIONS OFF)
    endif()
endif()

add_definitions(-g)

#GIT SUBMODULE INIT
if(GIT_FOUND AND EXISTS ".git")
    # Update submodules as needed
    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --remote --merge --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
        message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
    endif()
endif()

#BUILDING LIBRARY
file(GLOB ELEVATOR "${PROJECT_SOURCE_DIR}/libsrc/*.cpp")

file(GLOB ALL_HEADER_FILES "${PROJECT_SOURCE_DIR}/libsrc/*.hpp")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${BUILD_LIB_FILES_DIRECTORY})

include_directories("${PROJECT_SOURCE_DIR}/spdlog/include")

add_library(elevator-sim SHARED ${ELEVATOR})

file(COPY ${ALL_HEADER_FILES} DESTINATION ${BUILD_HEADER_FILES_DIRECTORY})

#LIBRARY BUILD COMPLETE



#BUILDING EXECUTABLE FOR SIMULATION

include_directories("${PROJECT_SOURCE_DIR}/build/include")
include_directories("${PROJECT_SOURCE_DIR}/spdlog/include")

link_directories("${PROJECT_SOURCE_DIR}/build/lib")
link_directories("/usr/lib64")

add_executable(simulation src/simulator.cpp)

target_link_libraries(simulation elevator-sim)

#EXECUTABLE BUILDING COMPLETE

# Set minimum required CMake version
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# Set project name
project(hello)

# set C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(MPI REQUIRED)
if(MPI_FOUND)
    include_directories(${MPI_INCLUDE_PATH})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MPI_COMPILE_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MPI_LINK_FLAGS}")
endif()

add_executable(hello hello.cpp)
target_link_libraries(hello ${MPI_LIBRARIES})

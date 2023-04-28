# Set minimum required CMake version
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

# Set project name
project(construct C)

# Set C11 standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

find_package(OpenMP REQUIRED)
if(OpenMP_C_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# Use file(GLOB ...) to wildcard source files
file(GLOB SOURCES "*.c")

# Loop over SOURCES and generate a separate executable for each file
foreach(SOURCE ${SOURCES})
  # Get the file name without extension
  get_filename_component(EXECUTABLE_NAME ${SOURCE} NAME_WE)

  # Add executable for current source file
  add_executable(${EXECUTABLE_NAME} ${SOURCE})
endforeach()

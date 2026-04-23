
cmake_minimum_required(VERSION 3.10)
project(str_problem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create an executable that will use our str class
add_executable(code main.cpp str.hpp)

# We need to tell CMake that str.hpp is a header file that should be considered
# for dependency tracking
set_property(SOURCE str.hpp PROPERTY HEADER_FILE_ONLY TRUE)

# Set compiler options for better warnings and optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

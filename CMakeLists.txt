cmake_minimum_required(VERSION 3.20)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# To get intellisense to find nanobind and other external libraries
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find Python
find_package(Python COMPONENTS Interpreter Development REQUIRED)

# ---------------------------------------------
# External Dependencies
# ---------------------------------------------
include(cmake/Dependencies.cmake)


# ---------------------------------------------
# Python Bindings
# ---------------------------------------------
add_subdirectory(bindings)

# Testing
enable_testing()
add_subdirectory(src)
add_subdirectory(tests)


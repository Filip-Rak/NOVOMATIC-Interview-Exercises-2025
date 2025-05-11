# Top level - CMakeLists.txt

# Project wide settings
cmake_minimum_required(VERSION 3.16)
project(NOVOMATIC_Interview-Exercises-2025 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

# Variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/external)

# Catch2 dependency
include(FetchContent)

FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.8.1
)
FetchContent_MakeAvailable(catch2)

# Sub CMakeLists
add_subdirectory(exercises/exercise1)
add_subdirectory(exercises/exercise2)
add_subdirectory(exercises/exercise3)

message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

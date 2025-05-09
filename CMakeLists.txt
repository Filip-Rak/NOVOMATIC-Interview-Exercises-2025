# Top level - CMakeLists.txt

cmake_minimum_required(VERSION 3.16)
project(NOVOMATIC_Interview-Exercises-2025 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
enable_testing()

add_library(catch2_amalgamated OBJECT external/catch2/catch_amalgamated.cpp)
target_include_directories(catch2_amalgamated INTERFACE external/catch2)

add_subdirectory(exercises/exercise1)
# add_subdirectory(exercises/exercise2)
# add_subdirectory(exercises/exercise3)

message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

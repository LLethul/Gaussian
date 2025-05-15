cmake_minimum_required(VERSION 3.20)

# Project name and C++ standard
project(gaussian LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Recursively find all source files in src/**
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/**.cpp ${CMAKE_SOURCE_DIR}/src/**.cxx ${CMAKE_SOURCE_DIR}/src/**.cc)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})
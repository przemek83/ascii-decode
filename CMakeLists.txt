cmake_minimum_required(VERSION 3.8)

project(ascii-decode
    LANGUAGES CXX 
    VERSION 1.0.0 
    DESCRIPTION "Simple ascii decoder." 
    HOMEPAGE_URL "https://github.com/przemek83/ascii-decode")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

configure_file(${CMAKE_SOURCE_DIR}/testFile.txt 
    ${CMAKE_BINARY_DIR}/testFile.txt COPYONLY)

add_executable(ascii-decode main.cpp)

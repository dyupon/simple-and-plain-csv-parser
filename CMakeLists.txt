cmake_minimum_required(VERSION 3.8)
project(csv_parser)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CSVReader.cpp CSVReader.h)
add_executable(csv_parser ${SOURCE_FILES})
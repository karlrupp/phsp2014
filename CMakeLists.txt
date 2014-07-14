cmake_minimum_required(VERSION 2.6)
project(OpenCLParameterStudy)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(OpenCL REQUIRED)

include_directories("./src/")
include_directories(".")

add_subdirectory(src)



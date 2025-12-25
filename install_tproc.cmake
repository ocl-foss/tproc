# // ============================================================= //
# // Open C++ Libraries.
# // Copyright (C) 2025, Amlal El Mahrouss and OCL Authors, licensed under BSD-3 license.
# // ============================================================= //

cmake_minimum_required(VERSION 3.30)

project(libocl VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

install(DIRECTORY include/ DESTINATION include)

message(STATUS "OCL.TProc has been installed.")

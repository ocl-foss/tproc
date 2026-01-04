# // ============================================================= //
# // Open C++ Libraries.
# // Copyright (C) 2025, Amlal El Mahrouss and OCL Authors, licensed under BSL license.
# // ============================================================= //

cmake_minimum_required(VERSION 3.30)

project(OCL)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if (INSTALL_OCL)
   include(install_tproc.cmake)
endif()

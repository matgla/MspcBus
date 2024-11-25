#
# CMakeLists.txt
#
# Copyright (c) 2024 Mateusz Stadnik <matgla@live.com>
#
# Distributed under the terms of the MIT License.
#


cmake_minimum_required(VERSION 3.31)

project (mspc_bus NONE)

find_program(yaspem yaspem.py)


if (NOT yaspem OR $ENV{YASPEM_FETCH_FROM_GIT}})
  include(FetchContent)

  FetchContent_Declare(
    yaspem
    GIT_REPOSITORY https://github.com/matgla/Yaspem.git
    GIT_TAG master)

  FetchContent_MakeAvailable(yaspem)

else ()
  cmake_path(GET yaspem PARENT_PATH yaspem_dir)
  message(STATUS "Populating locally available Yaspem: ${yaspem_dir}")
  set (yaspem_SOURCE_DIR ${yaspem_dir})
endif ()
   
list (APPEND CMAKE_MODULE_PATH ${yaspem_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/cmake) 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(yaspem)

setup_yaspem(
  YASPEM_SOURCE ${yaspem_SOURCE_DIR} OUTPUT_DIRECTORY
  ${CMAKE_CURRENT_BINARY_DIR}/packages PACKAGE_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/packages.json)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

find_package(picosdk REQUIRED)
include (cmake/preload/toolchains/pico_arm_cortex_m0plus_gcc)
include (cmake/Platform/PICO)
include (pico_sdk_init)

enable_language(C CXX)

message (STATUS "Setting configured: ${CONFIGURED}")
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

pico_sdk_init()

set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 23)

add_subdirectory(source)

add_subdirectory(examples)




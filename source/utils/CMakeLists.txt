#
# CMakeLists.txt
#
# Copyright (c) 2024 Mateusz Stadnik <matgla@live.com>
#
# Distributed under the terms of the MIT License.
#

add_library(mspc_bus_utils STATIC)

target_sources(mspc_bus_utils 
  PUBLIC 
    ${PROJECT_SOURCE_DIR}/include/utils/logger.h
  PRIVATE 
    logger.c
)

target_include_directories(mspc_bus_utils 
  PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
)

set (log_level "-1"
  )
if (ENABLE_LOGGER)
  if (${ENABLE_LOGGER} STREQUAL "info")
    set (log_level "1")
  elseif (${ENABLE_LOGGER} STREQUAL "warning")
    set (log_level "2")
  elseif (${ENABLE_LOGGER} STREQUAL "error")
    set (log_level "3")
  elseif (${ENABLE_LOGGER} STREQUAL "debug")
    set (log_level "0")
  endif ()

endif ()

target_compile_definitions(mspc_bus_utils 
  INTERFACE 
    -DMSPC_BUS_LOG_LEVEL=${log_level}
) 
 

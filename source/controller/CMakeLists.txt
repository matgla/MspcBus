#
# CMakeLists.txt
#
# Copyright (c) 2024 Mateusz Stadnik <matgla@live.com>
#
# Distributed under the terms of the MIT License.
#

add_library (mspc_bus_controller STATIC)

set (include_dir ${PROJECT_SOURCE_DIR}/include/controller)

target_sources (mspc_bus_controller 
  PUBLIC 
    ${include_dir}/controller.h
  PRIVATE 
    controller.c
)

target_link_libraries(mspc_bus_controller 
  PRIVATE    
    mspc_bus_utils 
)

target_include_directories(mspc_bus_controller 
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)


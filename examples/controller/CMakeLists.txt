#
# CMakeLists.txt
#
# Copyright (c) 2024 Mateusz Stadnik <matgla@live.com>
#
# Distributed under the terms of the MIT License.
#

add_executable(mspc_bus_example_controller)

target_sources(mspc_bus_example_controller 
  PRIVATE 
    main.cpp
)

target_link_libraries(mspc_bus_example_controller 
  PRIVATE 
    pico_stdlib
    mspc_bus_controller
)

pico_add_extra_outputs(mspc_bus_example_controller)

find_program(openocd_executable openocd)



add_custom_target(mspc_bus_example_controller_flash
  COMMAND 
    ${openocd_executable} -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000" -c "program $<TARGET_FILE:mspc_bus_example_controller> verify reset; reset run; exit"
  DEPENDS 
    mspc_bus_example_controller
  VERBATIM
)

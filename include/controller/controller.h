/**
 * controller.h
 *
 * Copyright (c) 2024 Mateusz Stadnik <matgla@live.com>
 *
 * Distributed under the terms of the MIT License.
 */

#pragma once

#include <stdbool.h>

// interface is in C, because maybe there will be a reason to use it in C based
// firmware

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef void (*chip_select)(bool enable);

void mspc_bus_controller_initialize_controller(int clock_pin);

// Detection uses bus in SPI mode
// It is necessary to determine what interface can be used (mainly bus size)
// All devices are in high-impedance mode and changes to output on request from
// controller
//
// Detection function takes functor to select peripheral, because bus owner may
// use analog multiplexers
void mspc_bus_controller_detect_device(chip_select device_select);

void mspc_bus_write_to_peripheral();

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

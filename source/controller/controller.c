/**
 * controller.c
 *
 * Copyright (c) 2024 Mateusz Stadnik <matgla@live.com>
 *
 * Distributed under the terms of the MIT License.
 */

#include "controller/controller.h"

#include <stddef.h>

#include "utils/logger.h"

void mspc_bus_controller_detect_device(chip_select device_select) {
  LOG_INFO("Detecting device on bus\n");
  if (device_select == NULL) {
    LOG_ERROR("Device selector cannot be null\n");
  }
  device_select(true);
  device_select(false);
}

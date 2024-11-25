/**
 * main.cpp
 *
 * Copyright (c) 2024 Mateusz Stadnik <matgla@live.com>
 *
 * Distributed under the terms of the MIT License.
 */

#include <cstdio>

#include "pico/stdlib.h"

#include "controller/controller.h"

#include "utils/logger.h"

int main() {
  stdio_init_all();

  printf("This is bus controller example code\n");

  LOG_DEBUG("Test log debug");
  LOG_INFO("Test log info");
  LOG_WARN("Test log warn");
  LOG_ERROR("Test log error");

  while (true) {
    mspc_bus_controller_detect_device([](bool enable) {
      printf("Select device: %s\n", enable ? "true" : "false");
    });
    sleep_ms(1000);
  }
}

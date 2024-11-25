/**
 * logger.c
 *
 * Copyright (c) 2024 Mateusz Stadnik <matgla@live.com>
 *
 * Distributed under the terms of the MIT License.
 */

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

void __mspc_bus_log(const char *level, const char *format, ...) {
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  printf("<%02d/%02d/%04d %02d:%02d:%02d> %s: ", timeinfo->tm_mday,
         timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour,
         timeinfo->tm_min, timeinfo->tm_sec, level);
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
  printf("\n");
}

/**
 * logger.h
 *
 * Copyright (c) 2024 Mateusz Stadnik <matgla@live.com>
 *
 * Distributed under the terms of the MIT License.
 */

#pragma once

// this is simple stdout logger enabled via macros

// internal log function, don't use it inside code
// otherwise logger won't be removed if disabled

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
void __mspc_bus_log(const char *level, const char *format, ...);
#ifdef __cplusplus
}
#endif // __cplusplus

#ifndef MSPC_BUS_LOG_LEVEL
#define MSPC_BUS_LOG_LEVEL -1
#endif

#if MSPC_BUS_LOG_LEVEL == 0
#define LOG_DEBUG(...) __mspc_bus_log("DBG", __VA_ARGS__)
#endif

#if MSPC_BUS_LOG_LEVEL <= 1
#define LOG_INFO(...) __mspc_bus_log("INF", __VA_ARGS__)
#endif

#if MSPC_BUS_LOG_LEVEL <= 2
#define LOG_WARN(...) __mspc_bus_log("WRN", __VA_ARGS__)
#endif

#if MSPC_BUS_LOG_LEVEL <= 3
#define LOG_ERROR(...) __mspc_bus_log("ERR", __VA_ARGS__)
#endif

#ifndef LOG_DEBUG
#define LOG_DEBUG(...)
#endif

#ifndef LOG_WARN
#define LOG_WARN(...)
#endif

#ifndef LOG_INFO
#define LOG_INFO(...)
#endif

#ifndef LOG_ERROR
#define LOG_ERROR(...)
#endif

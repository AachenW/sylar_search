#ifndef __SYLAR_UTIL_H__
#define __SYLAR_UTIL_H__

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <sys/types.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <unistd.h>
#include <vector>

namespace sylar {

pid_t GetThreadId();

uint32_t GetFiberId();

void Backtrace(std::vector<std::string>& bt, int size = 64, int skip = 1);

std::string BacktraceToString(int size = 64, int skip = 2, const std::string& prefix = "");

/// @brief 获取当前时间的毫秒
uint64_t GetCurrentMS();

/// @brief 获取当前时间的微秒 
uint64_t GetCurrentUS();
} // namespace sylar
#endif

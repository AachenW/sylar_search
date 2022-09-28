cmake_minimum_required(VERSION 3.0)
project(sylar)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O3 -std=c++11 -Wall -Wno-deprecated")

include_directories(.)

# find_library(YAMLCPP libyaml-cpp.a)
message("***", $(YAMLCPP))

add_library(sylar SHARED
    log.h
    singleton.h
    util.h
    config.h
    log.cc
    config.cc
    util.cc
)
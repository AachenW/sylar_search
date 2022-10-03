cmake_minimum_required(VERSION 3.0)
project(sylar)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../lib)

set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")
set(CMAKE_C_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")

include_directories(CMAKE_CURRENT_LIST/../)

find_package(Boost REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

message("***", $(YAMLCPP))

add_library(sylar SHARED
    config.h    
    fiber.h
    iomanager.h
    log.h
    marco.h
    mutex.h
    scheduler.h
    singleton.h
    sylar.h
    thread.h
    timer.h
    util.h
    config.cc
    fiber.cc
    iomanager.cc
    log.cc
    mutex.cc
    scheduler.cc
    thread.cc
    timer.cc
    util.cc
)

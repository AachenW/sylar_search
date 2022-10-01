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
    log.h
    singleton.h
    thread.h
    util.h
    config.cc
    log.cc
    thread.cc
    util.cc
)

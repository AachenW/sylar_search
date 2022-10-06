cmake_minimum_required(VERSION 3.0)
project(sylar)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../../lib)

set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")
set(CMAKE_C_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -fPIC -ggdb -std=c11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations")

set(INCDIRS . include)
set(SRCDIR src)
include_directories(${INCDIRS} ${SRCDIR})

find_package(Boost REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

message("***", $(YAMLCPP))

add_library(sylar SHARED
    include/address.h
    include/config.h    
    include/endian_sylar.h
    include/fd_manager.h
    include/fiber.h
    include/hook.h
    include/io_manager.h
    include/log.h
    include/marco.h
    include/mutex.h
    include/noncopyable.h
    include/scheduler.h
    include/singleton.h
    include/sylar.h
    include/thread.h
    include/timer.h
    include/util.h
    src/address.cc
    src/config.cc
    src/fd_manager.cc
    src/fiber.cc
    src/hook.cc
    src/io_manager.cc
    src/log.cc
    src/mutex.cc
    src/scheduler.cc
    src/thread.cc
    src/timer.cc
    src/util.cc
)

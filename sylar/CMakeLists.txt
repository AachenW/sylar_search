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
    include/byte_array.h
    include/config.h    
    include/endian_sylar.h
    include/fd_manager.h
    include/fiber.h
    include/hook.h
    include/http/http.h
    include/http/http_parser.h
    include/http/http_server.h
    include/http/http_session.h
    include/http/http11_common.h
    include/http/http11_parser.h
    include/http/httpclient_parser.h
    include/http/servlet.h
    include/io_manager.h
    include/log.h
    include/marco.h
    include/mutex.h
    include/noncopyable.h
    include/scheduler.h
    include/singleton.h
    include/socket.h
    include/stream.h
    include/streams/socket_stream.h
    include/tcp_server.h
    include/sylar.h
    include/thread.h
    include/timer.h
    include/util.h
    src/address.cc
    src/byte_array.cc
    src/config.cc
    src/fd_manager.cc
    src/fiber.cc
    src/hook.cc
    src/http/http.cc    
    src/http/http_parser.cc
    src/http/http_server.cc
    src/http/http_session.cc
    src/http/http11_parser.rl.cc
    src/http/httpclient_parser.rl.cc
    src/http/servlet.cc
    src/io_manager.cc
    src/log.cc
    src/mutex.cc
    src/scheduler.cc
    src/socket.cc
    src/stream.cc
    src/streams/socket_stream.cc
    src/tcp_server.cc
    src/thread.cc
    src/timer.cc
    src/util.cc
)

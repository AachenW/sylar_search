cmake_minimum_required(VERSION 3.0)

set(LIB_LIB
    sylar
    pthread
    ${YAMLCPP}
    )

include_directories(/home/edinw/workspace/sylar/lib/)
link_directories(/home/edinw/workspace/sylar/lib/)

include_directories(package/include)
include_directories(package/lib)

include_directories(CMAKE_CURRENT_LIST/../)

set(EXECUTABLE_OUTPUT_PATH  CMAKE_CURRENT_LIST/../bin)

add_executable(test01 test.cc)
add_dependencies(test01 sylar)
target_link_libraries(test01 ${LIB_LIB})

add_executable(test_config test_config.cc)
add_dependencies(test_config sylar)
target_link_libraries(test_config sylar ${LIB_LIB})
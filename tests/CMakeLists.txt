cmake_minimum_required(VERSION 3.0)

set(LIBS
    sylar
    pthread
#    ${YAMLCPP}
    )

include_directories(/home/edinw/workspace/sylar/lib/)
link_directories(/home/edinw/workspace/sylar/lib/)

include_directories(package/include)
include_directories(package/lib)

include_directories(CMAKE_CURRENT_LIST/../)

set(EXECUTABLE_OUTPUT_PATH  CMAKE_CURRENT_LIST/../bin)

add_executable(test_iomanager test_iomanager.cc)
# add_dependencies(test_iomanager sylar)
target_link_libraries(test_iomanager ${LIBS})
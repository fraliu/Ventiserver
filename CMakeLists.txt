#顶层Cmake，设置全局链接库以及添加子目录，和项目的头文件.h位置
#设置最低版本和项目名称
cmake_minimum_required(VERSION 3.0)
project(Ventiserver)
#target_include_directories(Ventiserver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/*)
#设置全局的c++标准
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED True)
include_directories(${CMAKE_SOURCE_DIR}/include)
message("The value of the variable is: ${CMAKE_SOURCE_DIR}")
# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)



add_executable(Ventiserver src/main.cpp)

add_subdirectory(src/logger)
target_link_libraries(Ventiserver PRIVATE log)

# 添加全局头文件搜索路径
#target_include_directories(Ventiserver
#        PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/include  # 指向 include 目录
#)

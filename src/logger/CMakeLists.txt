#获取当前目录下的所有源文件项目
file(GLOB LOG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

#创建静态库或共享库
add_library(log SHARED ${LOG_FILE})

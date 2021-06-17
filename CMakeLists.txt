# 版本限定 
cmake_minimum_required(version 3.0)
                   
# 项目名称 
set(PROJECT_NAME TokenizerTest)
project(${PROJECT_NAME}) 
# 设置编译器选项：O3优化，显示所有警告
set(CMAKE_C_FLAGS "$ENV{CFLAGS} -O3 -Wall") 
# 定义头文件的路径变量
set(INCLUDE_PATH /usr/local/include/) 
message(status "Include Path, ${INCLUDE_PATH}")
# 定义源文件路径变量
set(SOURCE_PATH ${PROJECT_SOURCE_DIR}/src) 
message(status "Source Path , ${SOURCE_PATH}") 
# 包含头文件路径
include_directories(${INCLUDE_PATH})
add_subdirectory(${SOURCE_PATH})

# 添加源文件路径下所有源文件存放到变量中(*.c && *.cpp)，当然也可以手动一个个文件添加进来
aux_source_directory(${SOURCE_PATH} SRC_LIST)

# 设置动态库输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib) 
message(status "Library Output Path, " ${PROJECT_BINARY_DIR/lib}) 
# 生成动态库(libmymath.so)
add_library(tokenizer SHARED ${SRC_LIST})

# 添加源文件列表变量
set(SRC_LIST ${PROJECT_SOURCE_DIR}/main.cpp)
# 打印编译目录和项目目录路径
message(status "This is BINARY dir " ${PROJECT_BINARY_DIR})
message(status "This is SOURCE dir " ${PROJECT_SOURCE_DIR})
# 生成可执行文件
add_executable(${PROJECT_NAME} ${SRC_LIST})
set(LINK_DIR /usr/local/lib)
message(status "Link Path, ${LINK_DIR}")
link_directories(${LINK_DIR})
target_link_libraries(${PROJECT_NAME} utf8proc)

# # 生成静态库（libmymath.a，target名字只能有一个，所以不能与动态库的名字一样）
# ADD_LIBRARY(mymath_static STATIC ${SRC_LIST})
# # 但是可以通过下面的命令更改静态库target生成的库名，这样就和动态库的名字一样的了
# set_TARGET_PROPERTIES(mymath_static PROPERTIES OUTPUT_NAME "mymath") 

#
# Created by gky on 19-4-26.
# Author:liuqingtong.dev@gmail.com
#

cmake_minimum_required(VERSION 3.14)
project(GKY_SR_API)

set(CMAKE_CXX_STANDARD 11)

# add Python.h header path
include_directories(/usr/include/python2.7)
#include_directories(/usr/include/boost)
# add python .so path
link_directories(/usr/lib/python2.7/config-x86_64-linux-gnu/)
#link_directories(/usr/lib)


#set(SOURCE_FILES main.cpp)
set(SOURCE_FILES example01.cpp)
add_executable(GKY_SR_API ${SOURCE_FILES})
# Dependent library
target_link_libraries(GKY_SR_API libpython2.7.so)

cmake_minimum_required(VERSION 3.13)
project(TD7 C)

set(CMAKE_C_STANDARD 99)

add_executable(TD7 main.c tree.c tree.h nodeTreeList.o nodeTreeQueueList.o)
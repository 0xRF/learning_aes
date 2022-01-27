cmake_minimum_required(VERSION 3.21)
project(learning_aes C)

set(CMAKE_C_STANDARD 23)

add_executable(learning_aes main.c rijindael.c)

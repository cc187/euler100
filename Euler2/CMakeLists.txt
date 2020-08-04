cmake_minimum_required(VERSION 3.17)
project(Euler2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pipe")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g") #-fsanitize=address
set(CMAKE_C_FLAGS_RELEASE  "-O3 -fomit-frame-pointer -march=native -Wno-strict-aliasing -DNDEBUG")
set(CMAKE_BUILD_TYPE_INIT "Release")

add_executable(Euler2 main.c enum.h)
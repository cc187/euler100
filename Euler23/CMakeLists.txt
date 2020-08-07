cmake_minimum_required(VERSION 3.9)
project(Euler23 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif ()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pipe")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g") #-fsanitize=address
set(CMAKE_C_FLAGS_RELEASE "-O3 -fomit-frame-pointer -march=native -Wno-strict-aliasing -DNDEBUG")


add_executable(Euler23 main.c)

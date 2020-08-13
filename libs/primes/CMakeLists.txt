cmake_minimum_required(VERSION 3.12)
project(primes C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pipe")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g") #-fsanitize=address
set(CMAKE_C_FLAGS_RELEASE  "-O3 -fomit-frame-pointer -march=native -Wno-strict-aliasing -DNDEBUG")
set(CMAKE_BUILD_TYPE_INIT "Release")

add_library(primes primes.c primes.h)
target_link_libraries(primes m)
target_include_directories(primes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
cmake_minimum_required(VERSION 3.12)
project(Euler50 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pipe")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g") #-fsanitize=address
set(CMAKE_C_FLAGS_RELEASE  "-O3 -fomit-frame-pointer -march=native -Wno-strict-aliasing -DNDEBUG")
set(CMAKE_BUILD_TYPE_INIT "Release")

add_subdirectory(
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib/primes
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib/primes/bin
)

add_executable(Euler50 main.c)
target_link_libraries(Euler50 PRIVATE m primes)
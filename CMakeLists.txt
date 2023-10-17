# VERSION
cmake_minimum_required(VERSION 3.15)

# PROJECT 
project(yiffy VERSION 1.0.0 DESCRIPTION "The terminal app for downloading/fetching images from e621/e926" LANGUAGES C)

# SOURCE CODE DIRECTORY
add_subdirectory(src)

# GCC OPTIONS
target_compile_options(yiffy PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
    -O2
    -g
    -std=c17
    -pthread
    -fstrict-aliasing
    -fstack-protector-strong
    -fno-strict-overflow
    -fno-delete-null-pointer-checks
    -fvisibility=hidden
    -Wformat=2
    -Wstrict-overflow=5
    -Wcast-align
)

# C STANDARD
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
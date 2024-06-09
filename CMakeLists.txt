# VERSION
cmake_minimum_required(VERSION 3.10)

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
    -pthread
    -fstrict-aliasing
    -fstack-protector-all
    -fstack-clash-protection
    -fcf-protection
    -fno-strict-overflow
    -fno-delete-null-pointer-checks
    -fvisibility=hidden
    -Wformat=2
    -Wformat-security
    -Wstrict-overflow=5
    -Wcast-align
    -D_FORTIFY_SOURCE=3
    -fPIE
    -pie
    -Wl,-z,relro
    -Wl,-z,now
    -fno-plt
)

# C STANDARD
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
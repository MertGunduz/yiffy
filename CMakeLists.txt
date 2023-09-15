# VERSION
cmake_minimum_required(VERSION 3.15)

# PROJECT 
project(yiffy VERSION 1.0.0 DESCRIPTION "The terminal app for downloading/fetching images from e621/e926" LANGUAGES C)

# SOURCE CODE DIRECTORY
add_subdirectory(src)

# C STANDARD
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
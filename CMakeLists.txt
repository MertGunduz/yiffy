# VERSION
cmake_minimum_required(VERSION 3.15)

# PROJECT 
project(yiffy VERSION 1.0.0 LANGUAGES C CXX)

# SOURCE CODE DIRECTORY
add_subdirectory(src)

# C STANDARD
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# CREATE DIRECTORY
file(MAKE_DIRECTORY $ENV{HOME}/.yiffy)

# CREATE CONFIG FILE
file(WRITE $ENV{HOME}/.yiffy/yiffy-config.txt "--website-generation=off\n--proxy=off\n--anonymous-download=off\n--nsfw=on\n")
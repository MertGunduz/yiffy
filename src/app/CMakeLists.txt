add_executable(yiffy yiffy.c)

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
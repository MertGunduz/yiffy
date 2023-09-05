# CREATING THE BINARY FILE
add_executable(yiffy yiffy.c)

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

# LINK THE LIBRARIES
target_link_libraries(yiffy yiffy-conf yiffy-search yiffy-text-menus yiffy-ui yiffy-messages cjson)

# CREATE DIRECTORY
install(
    CODE "file(MAKE_DIRECTORY \$ENV{HOME}/.yiffy)"
)

# CREATE CONFIG FILE
install(
    CODE "file(WRITE \$ENV{HOME}/.yiffy/yiffy-config.txt \"test:wgen:test:nsfw\")"
)

# INSTALL THE EXECUTABLE TO USR/BIN
install(
    TARGETS yiffy
    DESTINATION /usr/bin
)

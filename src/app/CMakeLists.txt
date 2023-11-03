# CREATING THE BINARY FILE
add_executable(yiffy yiffy.c)

# FIND NCURSES
find_package(Curses REQUIRED)

# LINK THE LIBRARIES
target_link_libraries(yiffy yiffy-conf yiffy-fetch yiffy-search yiffy-text-menus yiffy-messages cjson ${CURSES_LIBRARIES})

# CREATE DIRECTORY
set(dest_path "$ENV{HOME}/.yiffy")

file(
    MAKE_DIRECTORY "${dest_path}"
)

# CREATE CONFIG FILE
set(file_path "$ENV{HOME}/.yiffy/yiffy-config.txt")

install(SCRIPT 
    CODE "file(WRITE \"${file_path}\" \"perr:nsfw\")"
)

# INSTALL THE EXECUTABLE TO USR/BIN
install(
    TARGETS yiffy
    DESTINATION /usr/local/bin/
)

# CREATE THE BINARY FILE
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
    CODE "file(WRITE \"${file_path}\" \"plog:nsfw\")"
)

# INSTALL THE EXECUTABLE TO USR/LOCAL/BIN
install(TARGETS yiffy DESTINATION /usr/local/bin)

# Create and install the config file, ensuring it writes with the correct permissions
install(CODE "
    file(MAKE_DIRECTORY \"${dest_path}\")
    file(WRITE \"${dest_path}/yiffy-config.txt\" \"plog:nsfw\")
    execute_process(COMMAND chmod 755 \"${dest_path}\")
    execute_process(COMMAND chmod 755 \"${dest_path}/yiffy-config.txt\")
    execute_process(COMMAND chown $ENV{USER}:$ENV{USER} \"${dest_path}\")
    execute_process(COMMAND chown $ENV{USER}:$ENV{USER} \"${dest_path}/yiffy-config.txt\")
")

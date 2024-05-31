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

# CREATE CONFIG FILES
set(config_file_path "$ENV{HOME}/.yiffy/yiffy-config.txt")
set(credentials_file_path "$ENV{HOME}/.yiffy/yiffy-credentials.txt")

install(SCRIPT 
    CODE "file(WRITE \"${config_file_path}\" \"plog:nsfw\")"
)

install(SCRIPT 
    CODE "file(WRITE \"${credentials_file_path}\" \"\")"
)

# INSTALL THE EXECUTABLE TO USR/LOCAL/BIN
install(TARGETS yiffy DESTINATION /usr/local/bin)

# Create and install the config files, ensuring they write with the correct permissions
install(CODE "
    file(MAKE_DIRECTORY \"${dest_path}\")
    file(WRITE \"${dest_path}/yiffy-config.txt\" \"IS_NSFW=NO\nIMG_DISPLAY_COMMAND=ascii-image-converter\n\")
    file(WRITE \"${dest_path}/yiffy-credentials.txt\" \"API_KEY=\nUSERNAME=\n\")
    execute_process(COMMAND chmod 755 \"${dest_path}\")
    execute_process(COMMAND chmod 755 \"${dest_path}/yiffy-config.txt\")
    execute_process(COMMAND chmod 755 \"${dest_path}/yiffy-credentials.txt\")
    execute_process(COMMAND chown $ENV{USER}:$ENV{USER} \"${dest_path}\")
    execute_process(COMMAND chown $ENV{USER}:$ENV{USER} \"${dest_path}/yiffy-config.txt\")
    execute_process(COMMAND chown $ENV{USER}:$ENV{USER} \"${dest_path}/yiffy-credentials.txt\")
")

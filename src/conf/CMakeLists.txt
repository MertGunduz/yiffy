set(SOURCES
    conf_nsfw.c
    conf_img_viewer_command.c
    conf_uname.c
)

add_library(yiffy-conf STATIC ${SOURCES})
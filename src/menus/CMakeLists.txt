set(SOURCES
    show_website.c
    show_version.c
    show_github.c
    show_help.c
    show_config.c
)

add_library(yiffy-text-menus STATIC ${SOURCES})
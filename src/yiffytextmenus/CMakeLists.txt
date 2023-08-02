set(SOURCES
    showWebsite.c
    showVersion.c
    showGithub.c
)

add_library(yiffy-text-menus STATIC ${SOURCES})
set(SOURCES
    showWebsite.c
    showVersion.c
    showGithub.c
    showHelp.c
    showConfig.c
)

add_library(yiffy-text-menus STATIC ${SOURCES})
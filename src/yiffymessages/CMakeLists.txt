set(SOURCES
    onOffMessage.c
    unrecognizedArgumentMessage.c
    noArgumentValueMessage.c
    argcErrorMessage.c
    extraArgumentErrorMessage.c
    homeNotFoundErrorMessage.c
    fileOpenErrorMessage.c
)

add_library(yiffy-messages STATIC ${SOURCES})
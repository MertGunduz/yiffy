set(SOURCES
    onOffMessage.c
    unrecognizedArgumentMessage.c
    noArgumentValueMessage.c
    argcErrorMessage.c
    extraArgumentErrorMessage.c
)

add_library(yiffy-messages STATIC ${SOURCES})
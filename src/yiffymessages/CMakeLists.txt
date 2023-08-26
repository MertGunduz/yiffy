set(SOURCES
    onOffMessage.c
    unrecognizedArgumentMessage.c
    noArgumentValueMessage.c
    argcErrorMessage.c
    extraArgumentErrorMessage.c
    homeNotFoundErrorMessage.c
    fileOpenErrorMessage.c
    noJsonResponseErrorMessage.c
    jsonParseErrorMessage.c
)

add_library(yiffy-messages STATIC ${SOURCES})
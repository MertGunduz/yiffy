set(SOURCES
    onOffMessage.c
    unrecognizedArgumentMessage.c
    noArgumentValueMessage.c
    argcErrorMessage.c
)

add_library(yiffy-messages STATIC ${SOURCES})
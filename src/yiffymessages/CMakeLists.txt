set(SOURCES
    onOffMessage.c
    unrecognizedArgumentMessage.c
    noArgumentValueMessage.c
)

add_library(yiffy-messages STATIC ${SOURCES})
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
    noResultsFoundErrorMessage.c
    cjsonPtrErrorMessage.c
    mallocErrorMessage.c
)

add_library(yiffy-messages STATIC ${SOURCES})
set(SOURCES
    dfetch.c
    fetch.c
    aria2Download.c
)

add_library(yiffy-search STATIC ${SOURCES})
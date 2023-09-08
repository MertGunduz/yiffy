set(SOURCES
    fetch.c
    aria2_download.c
    search.c
)

add_library(yiffy-search STATIC ${SOURCES})
set(SOURCES
    fetch.c
    aria2_download.c
)

add_library(yiffy-fetch STATIC ${SOURCES})
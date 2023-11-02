set(SOURCES
    create_top_window.c
    create_posts_window.c
    create_info_window.c
    create_controls_window.c
    search.c
)

add_library(yiffy-ui STATIC ${SOURCES})
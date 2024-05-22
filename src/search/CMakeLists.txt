set(SOURCES
    init_ncurses.c
    set_window_title.c
    create_top_window.c
    create_posts_window.c
    create_post_tags_window.c
    create_controls_window.c
    search.c
)

add_library(yiffy-search STATIC ${SOURCES})
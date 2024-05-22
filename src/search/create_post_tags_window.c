/**
 * @file create_post_tags_window.c
 * 
 * @brief This file is used to create a new window to display post tags and adds it to the specified position
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 23/05/2024
*/

#include "yiffy_search.h"

/// @brief Creates a new window to display post tags and adds it to the specified position. 
/// @param window A pointer to the WINDOW where post tags will be displayed. 
/// @param posts_panel_height A pointer to an integer representing the height of the posts panel. 
void create_post_tags_window(WINDOW *window, int *posts_panel_height) 
{
    window = newwin(6, COLS, 3 + *posts_panel_height, 0);
    box(window, 0, 0);

    set_window_title(window, "POST-TAGS");

    refresh();
    wrefresh(window);
}
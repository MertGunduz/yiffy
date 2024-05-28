/**
 * @file create_posts_window.c
 * 
 * @brief This file is used to create a new window to display posts and adds it to the specified position.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 23/05/2024
*/

#include "yiffy_search.h"

/// @brief Creates a new window to display posts and adds it to the specified position. 
/// @param window A pointer to the WINDOW where posts will be displayed. 
/// @param posts_panel_height A pointer to an integer representing the height of the posts panel. 
void create_posts_window(WINDOW **window, int *posts_panel_height) 
{
    /* Create the posts window until information, taking 12 lines from it because the info and controls window line is 12. */
    *posts_panel_height = LINES - 12;

    *window = newwin(*posts_panel_height, COLS, 3, 0);
    box(*window, 0, 0);

    set_window_title(*window, "POSTS");

    refresh();
    wrefresh(*window);
}
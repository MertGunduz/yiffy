/**
 * @file create_posts_window.c
 * 
 * @brief This file is used to create the posts section of search tui.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/11/2023
*/

#include "yiffy_ui.h"

/**
 * @brief Creates the posts section of search tui.
 * 
 * @param win Manipulates the window to draw the posts section.
*/
void create_posts_window(WINDOW *win)
{
    if (win == NULL)
    {
        window_create_error_msg();
        endwin();
        exit(EXIT_FAILURE);
    }

    wattron(win, A_BOLD);
    box(win, 0, 0);
    wattroff(win, A_BOLD);

    mvwprintw(win, 0, 1, "POSTS");

    refresh();
    wrefresh(win);
}
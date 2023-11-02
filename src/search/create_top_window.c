/**
 * @file create_top_window.c
 * 
 * @brief This file is used to create the top header of search tui.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/11/2023
*/

#include "yiffy_search.h"

/**
 * @brief Creates the top header of search tui.
 * 
 * @param win Manipulates the window to draw the top header.
*/
void create_top_window(WINDOW *win)
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

    mvwprintw(win, 0, 1, "YIFFY");
    
    wattron(win, A_STANDOUT);
    mvwprintw(win, 1, 1, " E621.NET - NSFW - ASCII-IMAGE-CONVERTER ");
    wattroff(win, A_STANDOUT);

    refresh();
    wrefresh(win);
}

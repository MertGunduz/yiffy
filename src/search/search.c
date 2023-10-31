/**
 * @file search.c
 * 
 * @brief This file is used to interact with the terminal user interface version of yiffy, it provides download-list-search-info features to the users.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 31/10/2023
*/

#include "yiffy_search.h"

void search(char *tags)
{
    /* Start the ncurses based terminal user interface. */
    initscr();
    noecho();
    start_color();
    curs_set(0);

    /* Check if terminal supports colors. */
    if (!has_colors())
    {
        color_comp_error_msg();
        exit(EXIT_FAILURE);
    }

    /* Top bar part of TUI. */
    WINDOW *top_window = newwin(1, COLS, 0, 0);

    if (top_window == NULL)
    {
        window_create_error_msg();
        endwin();
        exit(EXIT_FAILURE);
    }
    
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    
    wbkgd(top_window, COLOR_PAIR(1));

    mvwprintw(top_window, 0, 1, "YIFFY");
    mvwprintw(top_window, 0, COLS - 18, "PRESS F1 FOR HELP");

    refresh();
    wrefresh(top_window);

    /* Close the search app. */
    getch();
    endwin();
}
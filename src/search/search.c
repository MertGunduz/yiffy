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

    /* Create the color. */
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    /* Top bar part of TUI. */
    WINDOW *top_window = newwin(3, COLS -1, 0, 1);

    if (top_window == NULL)
    {
        window_create_error_msg();
        endwin();
        exit(EXIT_FAILURE);
    }

    wattron(top_window, A_BOLD);
    box(top_window, 0, 0);
    wattroff(top_window, A_BOLD);

    mvwprintw(top_window, 0, 1, "YIFFY");
    mvwprintw(top_window, 0, COLS - 23, "PRESS CTRL+H FOR HELP");
    mvwprintw(top_window, 1, 2, "- E621.NET - NSFW SEARCH ON");

    refresh();
    wrefresh(top_window);

    /* Posts part of TUI. */
    WINDOW *posts_window = newwin(20, COLS - 1, 3, 1);

    if (posts_window == NULL)
    {
        window_create_error_msg();
        endwin();
        exit(EXIT_FAILURE);
    }

    wattron(posts_window, A_BOLD);
    box(posts_window, 0, 0);
    wattroff(posts_window, A_BOLD);

    mvwprintw(posts_window, 0, 1, "POSTS");

    refresh();
    wrefresh(posts_window);

    /* Close the search app. */
    getch();
    endwin();
}
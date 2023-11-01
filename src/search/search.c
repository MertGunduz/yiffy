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

static void create_top_window(WINDOW *win);
static void create_posts_window(WINDOW *win);
static void create_info_window(WINDOW *win);

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

    /* Top window part of TUI. */
    WINDOW *top_window = newwin(3, COLS -1, 0, 1);
    WINDOW *posts_window = newwin(20, COLS - 1, 3, 1);
    WINDOW *info_window = newwin(7, COLS - 1, 23, 1);

    /* Create the terminal user interface by calling functions. */
    create_top_window(top_window);
    create_posts_window(posts_window);
    create_info_window(info_window);

    /* Close the search app. */
    getch();
    endwin();
}

static void create_top_window(WINDOW *win)
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
    mvwprintw(win, 0, COLS - 23, "PRESS CTRL+H FOR HELP");
    mvwprintw(win, 1, 2, "- E621.NET - NSFW SEARCH ON");

    refresh();
    wrefresh(win);
}

static void create_posts_window(WINDOW *win)
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

static void create_info_window(WINDOW *win)
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

    mvwprintw(win, 0, 1, "INFORMATION");

    refresh();
    wrefresh(win);
}
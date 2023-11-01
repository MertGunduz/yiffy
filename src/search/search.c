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
static void create_controls_window(WINDOW *win);

void search(char *tags)
{
    initscr();
    noecho();
    start_color();
    curs_set(0);
    keypad(stdscr, TRUE);

    if (!has_colors())
    {
        color_comp_error_msg();
        endwin();
        exit(EXIT_FAILURE);
    }

    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    /* Windows for the ncurses TUI. */
    WINDOW *top_window = newwin(3, COLS - 1, 0, 1);
    WINDOW *posts_window = newwin(10 + (LINES - 23), COLS - 1, 3, 1);
    WINDOW *info_window = newwin(7, COLS - 1, 13 + (LINES - 23), 1);
    WINDOW *controls_window = newwin(3, COLS - 1, 20 + (LINES - 23), 1);

    // Redraw the windows
    create_top_window(top_window);
    create_posts_window(posts_window);
    create_info_window(info_window);
    create_controls_window(controls_window);
    
    int ch;
    do 
    {
        if (ch == KEY_RESIZE)
        {
            refresh(); // Refresh to get the updated values of LINES and COLS
            clear();   // Clear the screen

            // Recreate the windows with updated sizes and positions
            top_window = newwin(3, COLS - 1, 0, 1);
            posts_window = newwin(10 + (LINES - 23), COLS - 1, 3, 1);
            info_window = newwin(7, COLS - 1, 13 + (LINES - 23), 1);
            controls_window = newwin(3, COLS - 1, 20 + (LINES - 23), 1);

            // Redraw the windows
            create_top_window(top_window);
            create_posts_window(posts_window);
            create_info_window(info_window);
            create_controls_window(controls_window);
        }
    } while ((ch = getch()) != 'q');

    // Close the search app.
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

static void create_controls_window(WINDOW *win)
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

    mvwprintw(win, 0, 1, "CONTROLS");

    refresh();
    wrefresh(win);
}
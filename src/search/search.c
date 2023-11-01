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

WINDOW *top_window, *posts_window, *info_window, *controls_window;

static void init_ncurses();
static void create_ui();
static void init_ui();

void search(char *tags)
{
    /* Initialize the ncurses with the needed configurations. */
    init_ncurses();

    /* Creating the main color scheme. */
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    /* Create the windows and create user interface. */
    init_ui();
    create_ui();

    /* The main control system of yiffy. */
    int ch;
    do 
    {
        if (ch == KEY_RESIZE)
        {
            /* Refresh the screen. */
            refresh();
            
            /* Clear the screen. */
            clear(); 

            /* Recreate the windows with updated sizes/positions and create user interface */
            init_ui();
            create_ui();
        }
    } while ((ch = getch()) != 'q');

    /* Close the search system. */
    endwin();
}

static void init_ncurses()
{
    /* Initialize ncurses and do the required configurations. */
    initscr();
    noecho();
    start_color();
    curs_set(0);
    keypad(stdscr, TRUE);

    /* Checks the color compatibility of the terminal. If it does not support, exits with an error message. */
    if (!has_colors())
    {
        color_comp_error_msg();
        endwin();
        exit(EXIT_FAILURE);
    }
}

static void create_ui()
{
    create_top_window(top_window);
    create_posts_window(posts_window);
    create_info_window(info_window);
    create_controls_window(controls_window);
}

static void init_ui()
{
    top_window = newwin(3, COLS - 1, 0, 1);
    posts_window = newwin(10 + (LINES - 23), COLS - 1, 3, 1);
    info_window = newwin(7, COLS - 1, 13 + (LINES - 23), 1);
    controls_window = newwin(3, COLS - 1, 20 + (LINES - 23), 1);
}
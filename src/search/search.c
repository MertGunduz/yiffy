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
static void controls(WINDOW *win1, WINDOW *win2, WINDOW *win3, WINDOW *win4);

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

    /* Creating the main color scheme. */
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    /* Windows for the ncurses TUI. */
    WINDOW *top_window = newwin(3, COLS - 1, 0, 1);
    WINDOW *posts_window = newwin(10 + (LINES - 23), COLS - 1, 3, 1);
    WINDOW *info_window = newwin(7, COLS - 1, 13 + (LINES - 23), 1);
    WINDOW *controls_window = newwin(3, COLS - 1, 20 + (LINES - 23), 1);

    /* Draw the windows */
    create_top_window(top_window);
    create_posts_window(posts_window);
    create_info_window(info_window);
    create_controls_window(controls_window);
    
    /* The main control system of yiffy. */
    controls(top_window, posts_window, info_window, controls_window);

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
    
    wattron(win, A_STANDOUT);
    mvwprintw(win, 1, 1, " E621.NET - NSFW - ASCII-IMAGE-CONVERTER ");
    wattroff(win, A_STANDOUT);

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

    wmove(win, 1, 1);

    wattron(win, A_STANDOUT);
    wprintw(win, " S [SHOW] ");
    wattroff(win, A_STANDOUT);

    wprintw(win, "  ");

    wattron(win, A_STANDOUT);
    wprintw(win, " D [DOWNLOAD] ");
    wattroff(win, A_STANDOUT);

    wprintw(win, "  ");


    wattron(win, A_STANDOUT);
    wprintw(win, " P [PREV] ");
    wattroff(win, A_STANDOUT);

    wprintw(win, "  ");

    wattron(win, A_STANDOUT);
    wprintw(win, " N [NEXT] ");
    wattroff(win, A_STANDOUT);

    wprintw(win, "  ");

    wattron(win, A_STANDOUT);
    wprintw(win, " Q [QUIT] ");
    wattroff(win, A_STANDOUT);

    refresh();
    wrefresh(win);
}

static void controls(WINDOW *win1, WINDOW *win2, WINDOW *win3, WINDOW *win4)
{
    int ch;
    do 
    {
        if (ch == KEY_RESIZE)
        {
            refresh(); // Refresh to get the updated values of LINES and COLS
            clear();   // Clear the screen

            // Recreate the windows with updated sizes and positions
            win1 = newwin(3, COLS - 1, 0, 1);
            win2 = newwin(10 + (LINES - 23), COLS - 1, 3, 1);
            win3 = newwin(7, COLS - 1, 13 + (LINES - 23), 1);
            win4 = newwin(3, COLS - 1, 20 + (LINES - 23), 1);

            // Redraw the windows
            create_top_window(win1);
            create_posts_window(win2);
            create_info_window(win3);
            create_controls_window(win4);
        }
    } while ((ch = getch()) != 'q');
}
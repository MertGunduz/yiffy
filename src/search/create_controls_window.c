/**
 * @file create_controls_window.c
 * 
 * @brief This file is used to create the controls section of search tui.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/11/2023
*/

#include "yiffy_search.h"

/**
 * @brief Creates the controls section of search tui.
 * 
 * @param win Manipulates the window to draw the controls section.
*/
void create_controls_window(WINDOW *win)
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

/**
 * @file yiffy_search.h
 * 
 * @brief This header file is used to handle the UI and UX of search.c as a helper header file.
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 01/11/2023
*/

#ifndef YIFFY_UI_H
#define YIFFY_UI_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "../msg/yiffy_messages.h"

#define TOP_WINDOW_HEIGHT 3                                     ///< The height of top border window in search.c function.
#define POSTS_WINDOW_HEIGHT 10 + (getmaxy(stdscr) - 23)        ///< The height of posts window in search.c function.
#define INFO_WINDOW_HEIGHT 7                                    ///< The height of info window in search.c function.
#define CONTROLS_WINDOWS_HEIGHT 3                               ///< The height of controls window in search.c function.

#define FULL_LENGTH (getmaxx(stdscr)) - 1                       ///< The 100% length for windows.

#define TOP_WINDOW_LOCATION 0                                   ///< The start point of top window.
#define POSTS_WINDOW_LOCATION 3                                 ///< The start point of posts window.
#define INFO_WINDOW_LOCATION 13 + (getmaxy(stdscr) - 23)        ///< The start point of info window.
#define CONTROLS_WINDOW_LOCATION  20 + (getmaxy(stdscr) - 23)   ///< The start point of controls window.

void create_top_window(WINDOW *win);
void create_posts_window(WINDOW *win);
void create_info_window(WINDOW *win);
void create_controls_window(WINDOW *win);
void search(char *tags);

#endif /* YIFFY_UI_H */
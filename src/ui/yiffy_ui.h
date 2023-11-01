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

#include "../msg/yiffy_messages.h"

void create_top_window(WINDOW *win);
void create_posts_window(WINDOW *win);
void create_info_window(WINDOW *win);
void create_controls_window(WINDOW *win);

#endif /* YIFFY_UI_H */
/**
 * @file yiffy_search.h
 * 
 * @brief This header file is used to handle the UI and UX of search.c as a helper header file.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 01/11/2023
*/

#ifndef YIFFY_UI_H
#define YIFFY_UI_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "../fetch/yiffy_fetch.h"
#include "../msg/yiffy_messages.h"

/// @brief Stores the control name and key for displaying in the controls panel.
typedef struct
{
    char *control_full_name;
    char control_character;
} control;

/* Main search function. */
void search(char *tags);

/* Easier to use ncurses initialization function. */
void init_ncurses();

/* User Interface creation functions. */
void create_top_window(WINDOW *window);
void create_posts_window(WINDOW **window, int *posts_panel_height);
void create_post_tags_window(WINDOW *window, int *posts_panel_height);
void create_controls_window(WINDOW *window, int *posts_panel_height, control *controls, int total_controls);

/* Function for writing the titles to windows. */
void set_window_title(WINDOW *window, const char *title);

/* Function for writing the posts to posts window. */
void write_post(WINDOW *window, size_t post_i, cJSON *url);

#endif /* YIFFY_UI_H */
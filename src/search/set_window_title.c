/**
 * @file set_window_title.c
 * 
 * @brief This file is used to write title to the windows for the user interface.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 23/05/2024
*/

#include "yiffy_search.h"

/// @brief Writes a title to the top-left corner of the specified window.
/// @param window The window where the title will be displayed.
/// @param title The title string to be written.
void set_window_title(WINDOW *window, const char *title) 
{
    mvwprintw(window, 0, 1, "%s", title);
}

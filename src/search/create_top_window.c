/**
 * @file create_top_window.c
 * 
 * @brief This file is used to create a new top window to display the title and SFW/NSFW status.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 23/05/2024
*/

#include "yiffy_search.h"

/// @brief Creates a new top window to display the title and SFW/NSFW status. 
/// @param window A pointer to the WINDOW where the title and SFW/NSFW status will be displayed. 
/// @param is_nsfw A boolean indicating whether the content is NSFW (true) or SFW (false). 
void create_top_window(WINDOW *window, bool is_nsfw) 
{
    window = newwin(3, COLS, 0, 0);
    box(window, 0, 0);

    set_window_title(window, "YIFFY");

    /* Write the SFW-NSFW option in A_STANDOUT (bright) mod. */
    wattron(window, A_STANDOUT);
    if (is_nsfw) 
    {
        mvwprintw(window, 1, 1, " NSFW [E621.NET] - ASCII-IMAGE-CONVERTER ");
    } 
    else 
    {
        mvwprintw(window, 1, 1, " SFW [E926.NET] - ASCII-IMAGE-CONVERTER ");
    }
    wattroff(window, A_STANDOUT);

    refresh();
    wrefresh(window);
}
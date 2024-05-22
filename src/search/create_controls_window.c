/**
 * @file create_controls_window.c
 * 
 * @brief This file is used to create a new window to display the controls and adds it to the specified position. 
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 23/05/2024
*/

#include "yiffy_search.h"

/// @brief Creates a new window to display the controls and adds it to the specified position. 
/// @param window A pointer to the WINDOW where controls will be displayed.
/// @param posts_panel_height A pointer to an integer representing the height of the posts panel. 
/// @param controls An array of control structures, each containing a control character and a control full name. 
/// @param total_controls The total number of controls to be displayed. 
void create_controls_window(WINDOW *window, int *posts_panel_height, control *controls, int total_controls) 
{
    window = newwin(3, COLS, 9 + *posts_panel_height, 0);
    box(window, 0, 0);

    set_window_title(window, "CONTROLS");

    /* Move to the center line of controls window. */
    wmove(window, 1, 1);

    /* Write the controls. */
    for (size_t i = 0; i < total_controls; i++)
    {
        wattron(window, A_STANDOUT);
        wprintw(window, " %c [%s] ", controls[i].control_character, controls[i].control_full_name);
        wattroff(window, A_STANDOUT);
        
        /* Give a spacing to the controls. */
        wprintw(window, "  ");
    }

    refresh();
    wrefresh(window);
}
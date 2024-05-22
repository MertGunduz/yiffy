/**
 * @file init_ncurses.c
 * 
 * @brief This file initializes and configures the ncurses library for the needed user interface.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 23/05/2024
*/

#include "yiffy_search.h"

/// @brief Initializes the ncurses library and sets up the terminal UI.
void init_ncurses()
{
    /* Initialize ncurses and configure the terminal settings. */
    initscr();            // Start ncurses mode
    noecho();             // Do not echo input characters
    start_color();        // Enable color functionality
    curs_set(0);          // Hide the cursor
    keypad(stdscr, TRUE); // Enable function keys and arrow keys

    /* Check if the terminal supports colors. If not, display an error message and exit. */
    if (!has_colors())
    {
        color_comp_error_msg(); // Display color compatibility error message
        endwin();               // End ncurses mode
        exit(EXIT_FAILURE);     // Exit the program with a failure status
    }
}

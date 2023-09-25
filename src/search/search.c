/**
 * @file search.c
 * 
 * @brief This file is used to search over e621-e926 by using a terminal with the specified tags by user and outputs or outputs-downloads URLs.
 * 
 * This file is used to send a request to the search over the e621-e926 by using the API. It uses ncurses to provide the web-like experience.
 * 
 * @author Mehmet Mert Gunduz 
 *
 * @date 21/07/2023
*/

#include "yiffy_search.h"

#define COMMAND_UI_CHARS 125

/* The control handling struct. */
typedef struct
{
    char control_char;
    char *control_description;
} control;

/* All yiffy search control commands. */
control ui_controls[] = 
{
    {'<', "Prev"},
    {'>', "Next"},
    {'^', "Up  "},
    {'v', "Down"},
    {'S', "Show"},
    {'I', "Info"},
    {'G', "Get "},
    {'Q', "Quit"},
};

static void create_yiffy_controls_ui(int terminal_height, int terminal_width, int total_characters, control *controls);

/**
 * @brief Sends a request to search over the e621-e926 by using the API. It uses ncurses to provide the web-like experience. 
 * 
 * @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
*/
void search(char *tags)
{
    setlocale(LC_ALL, "");   ///< Set the locale to all.

    initscr();               ///< Initialize the library and setup the terminal.
    cbreak();                ///< Disable line buffering, get input instantly.
    noecho();                ///< Close the echo ability of user input to the screen.
    keypad(stdscr, TRUE);    ///< Enable special keys like CTRL, SHIFT.
    start_color();           ///< Enable the color ability.

    /* Set the color pair for control commands. */
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    int height, width, total_characters = 0;

    /* Get the screen size. */
    height = getmaxy(stdscr);
    width = getmaxx(stdscr);

    printw("%d", total_characters);

    create_yiffy_controls_ui(height, width, COMMAND_UI_CHARS, ui_controls);

    getch();
    endwin();
}

static void create_yiffy_controls_ui(int terminal_height, int terminal_width, int total_characters, control *controls)
{
    /* Two line control commands ui. */
    if (terminal_width > total_characters)
    {
        move(terminal_height - 1, 0);
        
        for (int i = 0; i < 8; i++)
        {
            attron(A_BOLD | COLOR_PAIR(1));
            printw("[%c]", controls[i].control_char);
            attroff(A_BOLD | COLOR_PAIR(1));

            printw(" %s      ", controls[i].control_description);        
        }
    }
    else
    {
        move(terminal_height - 2, 0);
        
        for (int i = 0; i < 4; i++)
        {
            attron(A_BOLD | COLOR_PAIR(1));
            printw("[%c]", controls[i].control_char);
            attroff(A_BOLD | COLOR_PAIR(1));

            printw(" %s      ", controls[i].control_description);        
        }

        move(terminal_height - 1, 0);
        
        for (int i = 4; i < 8; i++)
        {
            attron(A_BOLD | COLOR_PAIR(1));
            printw("[%c]", controls[i].control_char);
            attroff(A_BOLD | COLOR_PAIR(1));

            printw(" %s      ", controls[i].control_description);        
        }
    }
}
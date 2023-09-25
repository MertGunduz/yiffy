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

static void create_yiffy_controls_ui(int terminal_height, int terminal_width, void (*func)());
static void create_single_line_ui();
static void create_double_line_ui();

/* Menu type handling enum, selects the control bar line type. */
typedef enum 
{
    single_line,
    double_line
} ui_type;

/* The control handling struct. */
typedef struct
{
    char *control_char;
    char *control_description;
} control;

/* All yiffy search control commands. */
control ui_controls[] = 
{
    {" < ", "Prev Page"},
    {" > ", "Next Page"},
    {" ^ ", "Up"},
    {" v ", "Down"},
    {" S ", "Show"},
    {" I ", "Information"},
    {" D ", "Download"},
    {" Q ", "Quit"},
};

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

    int height, width, total_characters = 0;
    void (*func)();

    /* Get the screen size. */
    height = getmaxy(stdscr);
    width = getmaxx(stdscr);

    for (int i = 0; i < sizeof(ui_controls) / sizeof(ui_controls[0]); i++)
    {
        total_characters += strlen(ui_controls[i].control_char) + strlen(ui_controls[i].control_description);
    }

    printw("%d", total_characters);

    getch();
    endwin();
}

static void create_yiffy_controls_ui(int terminal_height, int terminal_width, void (*func)())
{
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    func();
}

static void create_single_line_ui()
{
    
}

static void create_double_line_ui() 
{

}
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

#define SINGLE_COMMAND_UI_CHARS 105
#define DOUBLE_COMMAND_UI_CHARS 50

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

static void create_yiffy_ui(int terminal_height, int terminal_width, control *controls, char *posts[]);
static void create_one_line_ui(int terminal_height, int terminal_width, control *controls);
static void create_double_line_ui(int terminal_height, int terminal_width, control *controls);
static char* fetch_posts();
static void space(int num);

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
    use_default_colors();    ///< Enable default colors
    curs_set(0);             ///< Close the cursor.

    /* Set the color pair for control commands. */
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    int height, width;

    /* Get the screen size. */
    height = getmaxy(stdscr);
    width = getmaxx(stdscr);

    create_yiffy_ui(height, width, ui_controls, NULL);

    getch();
    clear();
    endwin();
}

static void create_yiffy_ui(int terminal_height, int terminal_width, control *controls, char *posts[])
{
    /* Two line control commands ui. */
    if (terminal_width > SINGLE_COMMAND_UI_CHARS)
    {
        create_one_line_ui(terminal_height, terminal_width, controls);
    }
    else
    {
        create_double_line_ui(terminal_height, terminal_width, controls);
    }
}

static void create_one_line_ui(int terminal_height, int terminal_width, control *controls)
{
    /* This variable is used for setting the size of command controls to maximize the width of terminal. */
    int single_total_distance = terminal_width - SINGLE_COMMAND_UI_CHARS;
    single_total_distance = single_total_distance / 8;

    /* The list part of the ui. */
    for (int i = 0; i < terminal_height - 2; i++)
    {
        mvprintw(i, 0, "%d", i);
    }

    /* Go to the bottom of terminal to create the controls part. */
    move(terminal_height - 2, 0);
        
    /* Start writing the 8 commands to the bottom of terminal in a single line. */
    for (int i = 0; i < 8; i++)
    {
        /* Write the command characters with bold font and white background. */
        attron(COLOR_PAIR(1));
        printw("[%c]", controls[i].control_char);
        attroff(COLOR_PAIR(1));

        /* Write the command descriptions. */
        printw(" %s", controls[i].control_description);

        /* By default it gives 6 spaces to each command control element. Also, it includes more spaces to make the terminal responsive. */
        space(6 + single_total_distance);
    }

    /* Draw the command control panel borders. */
    mvhline(terminal_height - 3, 0, 0, terminal_width);
    mvhline(terminal_height - 1, 0, 0, terminal_width);
}

static void create_double_line_ui(int terminal_height, int terminal_width, control *controls)
{
    /* This variable is used for setting the size of command controls to maximize the width of terminal. */
    int double_total_distance = terminal_width - DOUBLE_COMMAND_UI_CHARS;
    double_total_distance = double_total_distance / 4;

    /* The list part of the ui. */
    for (int i = 0; i < terminal_height - 2; i++)
    {
        mvprintw(i, 0, "%d", i);
    }
    
    /* The list part of the code. */
    for (int i = 0; i < terminal_height - 2; i++)
    {
        mvprintw(i, 0, "%d", i);
    }

    /* Go to the bottom of terminal to create the controls part. */
    move(terminal_height - 3, 0);
        
    for (int i = 0; i < 4; i++)
    {
        /* Write the command characters with bold font and white background. */
        attron(A_BOLD | COLOR_PAIR(1));
        printw("[%c]", controls[i].control_char);
        attroff(A_BOLD | COLOR_PAIR(1));

        /* Write the command descriptions. */
        printw(" %s", controls[i].control_description);    

        /* By default it gives 6 spaces to each command control element. Also, it includes more spaces to make the terminal responsive. */
        space(6 + double_total_distance);   
    }

    /* Go to the second bottom line of terminal to create the controls part line 2. */
    move(terminal_height - 2, 0);
        
    for (int i = 4; i < 8; i++)
    {
        /* Write the command characters with bold font and white background. */
        attron(A_BOLD | COLOR_PAIR(1));
        printw("[%c]", controls[i].control_char);
        attroff(A_BOLD | COLOR_PAIR(1));

        /* Write the command descriptions. */
        printw(" %s", controls[i].control_description);        

        /* By default it gives 6 spaces to each command control element. Also, it includes more spaces to make the terminal responsive. */
        space(6 + double_total_distance);
    }

    /* Draw the command control panel borders. */
    mvhline(terminal_height - 4, 0, 0, terminal_width);
    mvhline(terminal_height - 1, 0, 0, terminal_width);
}

static char* fetch_posts(int total_lines)
{

}

static void space(int num)
{
    if (num != 0)
    {
        printw(" ");
        space(num - 1);
    }
}
/**
 * @file search.c
 * 
 * @brief This file is used to interact with the terminal user interface version of yiffy, it provides download-list-search-info features to the users.
 * 
 * This file is created by using mathematical calculations to give its look, it gets really complicated to read from scratch.
 * Since ncurses is a very old and low-level library, it can be daunting to understand the whole code by just reading it.
 * All it does in this code is generating UI, resizing system and placing the data to the windows.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 31/10/2023
*/

#include "yiffy_search.h"
#include "../fetch/yiffy_fetch.h"

#define MAX_FILE_PATH 256   ///< This macro is used to set the default size for getting the home directory file.
#define MAX_BUFFER_SIZE 512 ///< This macro is used to set the default size for reading the config file

static void init_ncurses();

void search(char *tags)
{
    /* Configuration file path and data buffer for configurations. */
    char config_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    /* The home path of the user. */
    char *home_path = getenv("HOME");

    /* Check if NSFW option on. */
    bool is_nsfw = false;

    if (home_path == NULL) 
    {
        no_home_error_msg();
        exit(EXIT_FAILURE);
    }

    sprintf(config_path, "%s/.yiffy/yiffy-config.txt", home_path);

    /* Read the configuration file (home/user/.yiffy/yiffy-config.txt) to execute the wanted process. */
    FILE *config = fopen(config_path, "r");

    if (config == NULL) 
    {
        file_open_error_msg(config);
        exit(EXIT_FAILURE);
    }

    size_t config_bytes = fread(buffer, 1, MAX_BUFFER_SIZE - 1, config); 
    buffer[config_bytes] = '\0';

    fclose(config);

    char *token = strtok(buffer, ":");

    while (token != NULL) 
    {
        if (strcmp(token, "nsfw") == 0) 
        {
            is_nsfw = true;
            break;
        }

        token = strtok(NULL, ":");
    }

    /* Initialize the wanted tui configurations like noecho, start_color, etc... */
    init_ncurses();

    /**********************************************************/
    /* Top panel, shows information about the configurations. */
    /**********************************************************/
    
    /* Create top window and apply box to give it borders. */
    WINDOW *top_panel = newwin(3, COLS, 0, 0);
    box(top_panel, 0, 0);

    /* Move to one right, gives it a better look. */
    wmove(top_panel, 0, 1);

    /* The logo in uppercase. */
    wprintw(top_panel, "YIFFY");

    /* Move to inside of top panel window. */
    wmove(top_panel, 1, 1);

    /* Make the top panel information bright. */
    wattron(top_panel, A_STANDOUT);
    if (is_nsfw)
    {
        wprintw(top_panel, " NSFW [E621.NET] - ASCII-IMAGE-CONVERTER ");
    }    
    else
    {
        wprintw(top_panel, " SFW [E926.NET] - ASCII-IMAGE-CONVERTER ");
    }
    wattroff(top_panel, A_STANDOUT);

    /* Refreshing the panel to show the updates to user. */
    refresh();
    wrefresh(top_panel);

    /*****************************************/
    /* Posts panel, shows the list of posts. */
    /*****************************************/
    
    /* Create posts window and apply box to give it borders. */
    int posts_panel_height = LINES - 12;

    WINDOW *posts_panel = newwin(posts_panel_height, COLS, 3, 0);
    box(posts_panel, 0, 0);

    /* Move to one right, gives it a better look. */
    wmove(posts_panel, 0, 1);

    /* The logo in uppercase. */
    wprintw(posts_panel, "POSTS");

    /* Refreshing the panel to show the updates to user. */
    refresh();
    wrefresh(posts_panel);

    /*****************************************************************/
    /* Information panel, shows information about the selected post. */
    /*****************************************************************/

    /* Create info window and apply box to give it borders. */
    WINDOW *info_panel = newwin(6, COLS, 3 + posts_panel_height, 0);
    box(info_panel, 0, 0);

    /* Move to one right, gives it a better look. */
    wmove(info_panel, 0, 1);

    /* The logo in uppercase. */
    wprintw(info_panel, "INFORMATION");

    /* Refreshing the panel to show the updates to user. */
    refresh();
    wrefresh(info_panel);

    /******************************************************************/
    /* Controls panel, shows information about the configurations. */
    /******************************************************************/

    /* Create info window and apply box to give it borders. */
    WINDOW *controls_panel = newwin(3, COLS, 9 + posts_panel_height, 0);
    box(controls_panel, 0, 0);

    /* Move to one right, gives it a better look. */
    wmove(controls_panel, 0, 1);

    /* The logo in uppercase. */
    wprintw(controls_panel, "CONTROLS");

    /* Refreshing the panel to show the updates to user. */
    refresh();
    wrefresh(controls_panel);

    getch();
    endwin();
}

static void init_ncurses()
{
    /* Initialize ncurses and do the required configurations. */
    initscr();
    noecho();
    start_color();
    curs_set(0);
    keypad(stdscr, TRUE);

    /* Checks the color compatibility of the terminal. If it does not support, exits with an error message. */
    if (!has_colors())
    {
        color_comp_error_msg();
        endwin();
        exit(EXIT_FAILURE);
    }
}
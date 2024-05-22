/**
 * @file search.c
 * 
 * @brief This file is used to interact with the terminal user interface version of yiffy, providing download, list, search, travel, and selected post tags features.
 * 
 * It uses ncurses to generate the UI, handle resizing, and place data in windows named panels in this code.
 * 
 * @date 31/10/2023
*/

#include <ncurses.h>

#include "yiffy_search.h"
#include "../fetch/yiffy_fetch.h"

#define MAX_FILE_PATH 256   ///< This macro is used to set the default size for getting the home directory file.
#define MAX_BUFFER_SIZE 512 ///< This macro is used to set the default size for reading the config file.

/// @brief Stores the control name and key for displaying in the controls panel.
typedef struct
{
    char *control_full_name;
    char control_character;
} control;

control controls[] = 
{
    {"SHOW", 'S'},
    {"DOWNLOAD", 'D'},
    {"PREV", 'P'},
    {"NEXT", 'N'},
    {"QUIT", 'Q'}
};

WINDOW *top_panel;
WINDOW *posts_panel;
WINDOW *post_tags_panel;
WINDOW *controls_panel;

/// @brief Indicates whether the NSFW option is enabled.
bool is_nsfw;

/// @brief Height of the posts panel in the user interface.
int posts_panel_height;

static void init_ncurses();
static void set_panel_title(WINDOW *window, const char *title);
static void create_top_panel();
static void create_posts_panel();
static void create_post_tags_panel();
static void create_controls_panel();
static void create_panels();

/// @brief Creates a ncurses-based user interface to show, download, search and travel the e621/e926 by using curl api calls and aria2c tool.
/// @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --search "anthro+fur+male+smile".
void search(char *tags) 
{
    /* Configuration file path and data buffer for configurations. */
    char config_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    /* The home path of the user. */
    char *home_path = getenv("HOME");

    /* Check if the NSFW option is enabled. */
    is_nsfw = false;

    if (home_path == NULL) 
    {
        no_home_error_msg();
        exit(EXIT_FAILURE);
    }

    sprintf(config_path, "%s/.yiffy/yiffy-config.txt", home_path);

    /* Read the configuration file (~/.yiffy/yiffy-config.txt) to execute the desired process. */
    FILE *config = fopen(config_path, "r");

    if (config == NULL) 
    {
        file_open_error_msg();
        exit(EXIT_FAILURE);
    }

    size_t config_bytes = fread(buffer, 1, MAX_BUFFER_SIZE - 1, config); 
    buffer[config_bytes] = '\0';

    fclose(config);

    /* Parse the configuration to check for NSFW option. */
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

    /* Create the ncurses-based user interface. */
    init_ncurses();
    create_panels();

    /* Download the first page of posts with prompted tags. */
    aria2_download(tags, 1, is_nsfw, posts_panel_height);

    getch();
    endwin();
}

/// @brief Initialize ncurses, check color compatibility and perform necessary configurations for the user interface.
static void init_ncurses()
{
    /* Initialize ncurses and do the required configurations. */
    initscr();
    noecho();
    start_color();
    curs_set(0);
    keypad(stdscr, TRUE);

    /* Check the color compatibility of the terminal. If it does not support, exit with an error message. */
    if (!has_colors())
    {
        color_comp_error_msg();
        endwin();
        exit(EXIT_FAILURE);
    }
}

/// @brief Writes a title to the top-left corner of the specified window.
/// @param window The window where the title will be displayed.
/// @param title The title string to be written.
static void set_panel_title(WINDOW *window, const char *title) 
{
    /* Write the panel title. */
    mvwprintw(window, 0, 1, "%s", title);
}

/// @brief Creates the top panel UI displaying basic information about the API in use.
static void create_top_panel() 
{
    top_panel = newwin(3, COLS, 0, 0);
    box(top_panel, 0, 0);

    set_panel_title(top_panel, "YIFFY");

    /* Write the SFW-NSFW option in A_STANDOUT (bright) mod. */
    wattron(top_panel, A_STANDOUT);
    if (is_nsfw) 
    {
        mvwprintw(top_panel, 1, 1, " NSFW [E621.NET] - ASCII-IMAGE-CONVERTER ");
    } 
    else 
    {
        mvwprintw(top_panel, 1, 1, " SFW [E926.NET] - ASCII-IMAGE-CONVERTER ");
    }
    wattroff(top_panel, A_STANDOUT);

    refresh();
    wrefresh(top_panel);
}

/// @brief Creates the UI for displaying posts related to tags provided as terminal arguments.
static void create_posts_panel() 
{
    /* Create the posts_panel until information, taking 12 lines from it because the info and controls panel line is 12. */
    posts_panel_height = LINES - 12;

    posts_panel = newwin(posts_panel_height, COLS, 3, 0);
    box(posts_panel, 0, 0);

    set_panel_title(posts_panel, "POSTS");

    refresh();
    wrefresh(posts_panel);
}

/// @brief Creates the post tags panel UI to display tags of selected post.
static void create_post_tags_panel() 
{
    post_tags_panel = newwin(6, COLS, 3 + posts_panel_height, 0);
    box(post_tags_panel, 0, 0);

    set_panel_title(post_tags_panel, "POST-TAGS");

    refresh();
    wrefresh(post_tags_panel);
}

/// @brief Creates the controls panel UI to display valid keys for controlling the program.
static void create_controls_panel() 
{
    controls_panel = newwin(3, COLS, 9 + posts_panel_height, 0);
    box(controls_panel, 0, 0);

    set_panel_title(controls_panel, "CONTROLS");

    /* Move to the center line of controls window. */
    wmove(controls_panel, 1, 1);

    /* Write the controls. */
    for (size_t i = 0; i < sizeof(controls) / sizeof(controls[0]); i++)
    {
        wattron(controls_panel, A_STANDOUT);
        wprintw(controls_panel, " %c [%s] ", controls[i].control_character, controls[i].control_full_name);
        wattroff(controls_panel, A_STANDOUT);
        
        /* Give a spacing to the controls. */
        wprintw(controls_panel, "  ");
    }

    refresh();
    wrefresh(controls_panel);
}

/// @brief Creates all the panels for the user interface.
static void create_panels() 
{
    create_top_panel();
    create_posts_panel();
    create_post_tags_panel();
    create_controls_panel();
}

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

control controls[] = 
{
    {"SHOW", 'S'},
    {"DOWNLOAD", 'D'},
    {"PREV", 'P'},
    {"NEXT", 'N'},
    {"QUIT", 'Q'}
};

WINDOW *top_window;
WINDOW *posts_window;
WINDOW *post_tags_window;
WINDOW *controls_window;

/// @brief Indicates whether the NSFW option is enabled.
bool is_nsfw;

/// @brief Height of the posts panel in the user interface.
int posts_panel_height;

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

    /* Initialize ncurses and configurations for the user interface. */
    init_ncurses();

    /* Create the ncurses-based user interfaces. */
    create_top_window(top_window, is_nsfw);
    create_posts_window(posts_window, &posts_panel_height);
    create_post_tags_window(post_tags_window, &posts_panel_height);
    create_controls_window(controls_window, &posts_panel_height, controls, sizeof(controls) / sizeof(controls[0]));

    /* Download the first page of posts with prompted tags. */
    aria2_download(tags, 1, is_nsfw, posts_panel_height);

    getch();
    endwin();
}

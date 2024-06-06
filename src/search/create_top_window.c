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

#define FILE_PATH 256   ///< This macro is used to set the default size for getting the home directory file.
#define BUFFER_SIZE 512 ///< This macro is used to set the default size for reading the config file.

static char *home_directory; ///< Stores the home directory as string.

static char file_path[FILE_PATH]; ///< Stores the file path for config and credentials files.
static char buffer[BUFFER_SIZE]; ///< Stores the configs and credentials one by one, used for parsing them by using fgets.

/// @brief Creates a new top window to display the title and SFW/NSFW status. 
/// @param window A pointer to the WINDOW where the title and SFW/NSFW status will be displayed. 
/// @param is_nsfw A boolean indicating whether the content is NSFW (true) or SFW (false). 
void create_top_window(WINDOW *window) 
{
    /* NSFW option boolean value. */
    bool is_nsfw = false;

   /* Get the home directory of the current user. */
    home_directory = getenv("HOME");

    if (home_directory == NULL) 
    {
        no_home_error_msg();
        exit(1);
    }

    /* Create the credentials file path. */
    sprintf(file_path, "%s/.yiffy/yiffy-config.txt", home_directory);

    FILE *config_file = fopen(file_path, "r");

    if (config_file == NULL)
    {
        file_open_error_msg();
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE - 1, config_file))
    {
        if (strcmp(buffer, "IS_NSFW=YES\n") == 0)
        {
            is_nsfw = true;
            break;
        }
    }

    fclose(config_file);

    /* Create the windows. */
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
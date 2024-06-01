/**
 * @file conf_img_viewer_command.c
 * 
 * @brief This file is used to configures the image viewer command system, the image viewer command is used to show images on terminal in search function.
 * 
 * This file goes to the /home/user/.yiffy/yiffy-config.txt and sets the IMG_DISPLAY_COMMAND with an image viewer command.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 31/05/2024
*/

#define FILE_PATH_SIZE 256   ///< This macro is used to set the default size for getting the home directory file.
#define BUFFER_SIZE 512 ///< This macro is used to set the default size for reading the config file.
#define FILE_SIZE 2048 ///< This macro is used to set the default size for the file.

static char *home_directory; ///< Stores the home directory as string.

static char file_path[FILE_PATH_SIZE]; ///< Stores the file path for config and credentials files.
static char buffer[BUFFER_SIZE]; ///< Stores the configs and credentials one by one, used for parsing them by using fgets.

static char ivcommand[256]; ///< Stores the image viewer command option string.

#include "yiffy_conf.h"

/**
 * @brief Configures the image viewer command system, the image viewer command is used to show images on terminal in search function.
 * 
 * @param argv This is the value that stores the command string.
*/
void conf_img_viewer_command(char *argv)
{
    printf("%s\n", argv);

    /* Create the image viewer command option string. */
    sprintf(ivcommand, "IMG_DISPLAY_COMMAND=%s\n", argv);

    /* Get the home directory of the current user. */
    home_directory = getenv("HOME");

    if (home_directory == NULL) 
    {
        no_home_error_msg();
        exit(1);
    }

    /* Create the configuration file path. */
    sprintf(file_path, "%s/.yiffy/yiffy-config.txt", home_directory);

    FILE *config_file = fopen(file_path, "r");

    if (config_file == NULL)
    {
        file_open_error_msg();
        exit(EXIT_FAILURE);
    }

    /* Read the entire file into memory */
    char file_content[FILE_SIZE];
    char *content_ptr = file_content;
    size_t content_length = 0;

    while (fgets(buffer, BUFFER_SIZE - 1, config_file))
    {
        if (strstr(buffer, "IMG_DISPLAY_COMMAND=") != NULL)
        {
            strcpy(buffer, ivcommand);
        }

        strcpy(content_ptr, buffer);

        content_ptr += strlen(buffer);
        content_length += strlen(buffer);
    }

    /* Close the config file for reading. */
    fclose(config_file);

    /* Write the modified content back to the file. */
    config_file = fopen(file_path, "w");

    if (config_file == NULL)
    {
        file_open_error_msg();
        exit(EXIT_FAILURE);
    }

    fwrite(file_content, sizeof(char), content_length, config_file);

    /* Close the config file for writing. */
    fclose(config_file);
}
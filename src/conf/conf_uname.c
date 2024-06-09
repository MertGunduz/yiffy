/**
 * @file conf_uname.c
 * 
 * @brief This file is used to configure the username option.
 * 
 * This file goes to the /home/user/.yiffy/yiffy-credentials.txt and sets the username for api account access.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 05/09/2023
*/

#include "yiffy_conf.h"

#define FILE_PATH_SIZE 256   ///< This macro is used to set the default size for getting the home directory file.
#define BUFFER_SIZE 512 ///< This macro is used to set the default size for reading the config file.
#define FILE_SIZE 2048 ///< This macro is used to set the default size for the file.

static char *home_directory; ///< Stores the home directory as string.

static char file_path[FILE_PATH_SIZE]; ///< Stores the file path for config and credentials files.
static char buffer[BUFFER_SIZE]; ///< Stores the configs and credentials one by one, used for parsing them by using fgets.

static char uname[256]; ///< Stores the username credential data string.

/**
 * @brief Configures the username option.
 * 
 * @param argv This is the value that stores the username.
*/
void conf_uname(char *argv)
{
    /* Create the username option string. */
    sprintf(uname, "UNAME=%s\n", argv);

    /* Get the home directory of the current user. */
    home_directory = getenv("HOME");

    if (home_directory == NULL) 
    {
        no_home_error_msg();
        exit(1);
    }

    /* Create the credentials file path. */
    sprintf(file_path, "%s/.yiffy/yiffy-credentials.txt", home_directory);

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
        if (strstr(buffer, "UNAME=") != NULL)
        {
            strcpy(buffer, uname);
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
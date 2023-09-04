/**
 * @file show_config.c
 * 
 * @brief This file is used to show current configurations of the app to the user.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 05/08/2023
*/

#define MAX_FILE_PATH 256
#define MAX_BUFFER_SIZE 512

#include "yiffy_text_menus.h"

/**
 * @brief Shows the yiffy configurations to user.
*/
void show_config()
{
    char file_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    /* Get the home directory of the current user. */
    char *home_directory = getenv("HOME");

    if (home_directory == NULL) 
    {
        no_home_error_msg();
        exit(1);
    }

    /* Create the configuration file path. */
    sprintf(file_path, "%s/.yiffy/yiffy-config.txt", home_directory);

    /* create file pointer */
    FILE *configurationFile = fopen(file_path, "r");

    if (configurationFile == NULL)
    {
        file_open_error_msg(configurationFile);
        exit(EXIT_FAILURE);
    }

    fscanf(configurationFile, "%s", buffer);

    /* Write the header to console. */
    fprintfH(stdout, "current yiffy configurations");

    char *token = strtok(buffer, ":");

    while (token != NULL)
    {
        fprintf(stdout, "- %s\n", token);
        token = strtok(NULL, ":");
    }

    fclose(configurationFile);
}
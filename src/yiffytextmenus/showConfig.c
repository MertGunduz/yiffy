/**
 * @file showConfig.c
 * 
 * @brief shows the configurations
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 05/08/2023
*/

#define MAX_FILE_PATH 256
#define MAX_BUFFER_SIZE 512

#include "yiffy-text-menus.h"

/// @brief shows the configurations
void showConfig()
{
    /* file path and line buffer */
    char file_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    /* take the home directory of the current user */
    char *home_directory = getenv("HOME");

    if (home_directory == NULL) 
    {
        homeNotFoundErrorMessage();
        exit(1);
    }

    /* create the file path */
    sprintf(file_path, "%s/.yiffy/yiffy-config.txt", home_directory);

    /* create file pointer */
    FILE *configurationFile = fopen(file_path, "r");

    if (configurationFile == NULL)
    {
        fileOpenErrorMessage();
        exit(1);
    }

    /* read and the content */
    fscanf(configurationFile, "%s", buffer);

    /* write the text ui */
    fprintfH(stdout, "current yiffy configurations");

    /* tokenize the configuration string */
    char *token = strtok(buffer, ":");

    while (token != NULL)
    {
        fprintf(stdout, "- %s\n", token);
        token = strtok(NULL, ":");
    }
}
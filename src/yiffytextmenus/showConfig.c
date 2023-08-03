/**
 * @file
 * 
 * @brief
 * 
 * @author
 * 
 * @date
*/

#define MAX_FILE_PATH 256
#define MAX_BUFFER_SIZE 512

#include "yiffy-text-menus.h"

/// @brief shows the configurations did by the user
void showConfig()
{
    /* file path and line buffer */
    char file_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    /* take the home directory of the current user */
    char *home_directory = getenv("HOME");

    if (home_directory == NULL) {
        // error message function
        fprintf(stderr, "Error getting home directory\n");
    }

    /* create the file path */
    sprintf(file_path, "%s/.yiffy/yiffy-config.txt", home_directory);

    /* create file pointer */
    FILE *configurationFile = fopen(file_path, "r");

    if (configurationFile == NULL)
    {
        // error message function
        perror("Error opening file");
    }

    /* read and the content */
    fscanf(configurationFile, "%s", buffer);

    /* write the text ui */
    fprintf(stdout, "current yiffy configurations\n");
    fprintf(stdout, "----------------------------\n");

    /* tokenize the configuration string */
    char *token = strtok(buffer, ":");

    while (token != NULL)
    {
        fprintf(stdout, "- %s\n", token);
        token = strtok(NULL, ":");
    }
}
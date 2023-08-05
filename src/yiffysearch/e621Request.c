/**
 * @file e621Request.c
 * 
 * @brief sends request to e621 with the specified tags and takes response
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#define MAX_FILE_PATH 256
#define MAX_BUFFER_SIZE 512

#include "yiffy-search.h"

/// @brief sends request to e621 with the specified tags and takes response
/// @param tags 
/// @return the request url
char *e621Request(char *tagString)
{
    /* configuration booleans */
    bool isNsfw = false, isWgen = false, isProxy = false;

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

    /* tokenize the configuration string */
    char *token = strtok(buffer, ":");

    while (token != NULL)
    {
        if (strcmp(token, "nsfw") == 0)
        {
            isNsfw = true;
        }

        if (strcmp(token, "wgen") == 0)
        {
            isWgen = true;
        }

        if (strcmp(token, "proxy") == 0)
        {
            isProxy = true;
        }

        token = strtok(NULL, ":");
    }

    // check if proxy on, use with proxy bridge


    // check if nsfw on send request to e621 if not send to e926

    // check if wgen on, if yes generate website ui

    return tagString; 
}
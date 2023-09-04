/**
 * @file aria2Download.c
 * 
 * @brief Downloads the JSON file by using aria2c, works with the system function. 
 * 
 * This file is used to set the request string by checking isNSFW parameter, and downloads the JSON file from e621/e926 API by using aria2c.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/08/2023
*/

#include "yiffy_search.h"

/// @brief downloads the API response by using aria2c, works with a system call
/// @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
/// @param page This is the value that is passed to the API to get results from the specified pages.
/// @param isNsfw This is the boolean value that checks the NSFW option. If true, sets the request string for e621 otherwise sets for e926.
void aria2Download(char *tags, int page, bool isNsfw)
{
    char *requestString = (char*)malloc(256 * sizeof(char));

    if (requestString == NULL)
    {
        malloc_error_msg();
        exit(EXIT_FAILURE);
    }

    /* Set the string for NSFW or SFW option by checking the isNsfw parameter. */
    if (isNsfw)
    {
        sprintf(requestString, "aria2c \"https://e621.net/posts.json?limit=20&page=%d&tags=%s\" -o posts.json >/dev/null 2>&1", page, tags);
    }
    else
    {
        sprintf(requestString, "aria2c \"https://e926.net/posts.json?limit=20&page=%d&tags=%s\" -o posts.json >/dev/null 2>&1", page, tags);
    }

    /* Download the JSON and set a sleep(1) for signals. */
    int success = system(requestString);
    sleep(1);

    free(requestString);

    if (success == BAD_SYSTEM_FUNC_CALL)
    {
        system_func_error_msg();
        exit(EXIT_FAILURE);
    }
}
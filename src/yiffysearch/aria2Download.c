/**
 * @file aria2Download.c
 * 
 * @brief downloads the API response by using aria2c, works with a system call
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/08/2023
*/

#include "yiffy-search.h"

/// @brief downloads the API response by using aria2c, works with a system call
/// @param tags 
/// @param page 
/// @param isNsfw 
void aria2Download(char *tags, int page, bool isNsfw)
{
    char *requestString = (char*)malloc(256 * sizeof(char));

    if (requestString == NULL)
    {
        mallocErrorMessage();
        exit(EXIT_FAILURE);
    }

    if (isNsfw)
    {
        sprintf(requestString, "aria2c \"https://e621.net/posts.json?limit=20&page=%d&tags=%s\" -o posts.json >/dev/null 2>&1", page, tags);
    }
    else
    {
        sprintf(requestString, "aria2c \"https://e926.net/posts.json?limit=20&page=%d&tags=%s\" -o posts.json >/dev/null 2>&1", page, tags);
    }

    /* download the response and sleep for signals */
    int success = system(requestString);
    sleep(1);

    if (success == BAD_SYSTEM_FUNC_CALL)
    {
        /* gives information related to the system func call error */
        badSystemFuncErrorMessage();

        if (requestString != NULL)
        {
            free(requestString);
        }

        exit(EXIT_FAILURE);
    }

    if (requestString != NULL)
    {
        free(requestString);
    }
}
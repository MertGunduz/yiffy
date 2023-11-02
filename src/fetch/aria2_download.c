/**
 * @file aria2_download.c
 * 
 * @brief Downloads the JSON file by using aria2c, works with the system function. 
 * 
 * This file is used to set the request string by checking isNSFW parameter, and downloads the JSON file from e621/e926 API by using aria2c.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/08/2023
*/

#include "yiffy_fetch.h"

/// @brief downloads the API response by using aria2c, works with a system call
/// @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
/// @param page This is the value that is passed to the API to get results from the specified pages.
/// @param is_nsfw This is the boolean value that checks the NSFW option. If true, sets the request string for e621 otherwise sets for e926.
void aria2_download(char *tags, int page, bool is_nsfw, int lim)
{
    char *request_string = (char*)malloc(256 * sizeof(char));

    if (request_string == NULL)
    {
        malloc_error_msg();
        exit(EXIT_FAILURE);
    }

    /* Set the string for NSFW or SFW option by checking the isNsfw parameter. */
    if (is_nsfw)
    {
        sprintf(request_string, "aria2c \"https://e621.net/posts.json?limit=%d&page=%d&tags=%s\" -o posts.json >/dev/null 2>&1", lim, page, tags);
    }
    else
    {
        sprintf(request_string, "aria2c \"https://e926.net/posts.json?limit=%d&page=%d&tags=%s\" -o posts.json >/dev/null 2>&1", lim, page, tags);
    }

    /* Download the JSON and set a sleep(1) for signals. */
    int success = system(request_string);
    sleep(1);

    free(request_string);

    if (success == BAD_SYSTEM_FUNC_CALL)
    {
        system_func_error_msg();
        exit(EXIT_FAILURE);
    }
}
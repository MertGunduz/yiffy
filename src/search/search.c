/**
 * @file search.c
 * 
 * @brief This file is used to search over e621-e926 by using a terminal with the specified tags by user and outputs or outputs-downloads URLs.
 * 
 * This file is used to send a request to the search over the e621-e926 by using the API. It uses ncurses to provide the web-like experience.
 * 
 * @author Mehmet Mert Gunduz 
 *
 * @date 21/07/2023
*/

#include "yiffy_search.h"

/**
 * @brief Sends a request to search over the e621-e926 by using the API. It uses ncurses to provide the web-like experience. 
 * 
 * @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
 * @param page This is the value that is passed to the API to get results from the specified pages.
*/
void search(char *tags, int page)
{

}
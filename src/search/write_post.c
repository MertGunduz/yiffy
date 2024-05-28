/**
 * @file write_post.c
 * 
 * @brief This file is used to write posts to the posts window. 
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 28/05/2024
*/

#include "yiffy_search.h"

/// @brief Writes posts to the posts window. 
/// @param window Posts window.
/// @param post_i The index of the post.
/// @param url The url of the post with specified index.
void write_post(WINDOW *window, size_t post_i, cJSON *url)
{
    /* Make the first post blinking. */
    if (post_i == 0) 
    {
        wattron(window, A_STANDOUT);
    }
    
    /* Write the post URL. */
    mvwprintw(window, post_i + 1, 1, "%s", url->valuestring);
    
    /* Close the post blinking. */
    if (post_i == 0) 
    {
        wattroff(window, A_STANDOUT);
    }
}
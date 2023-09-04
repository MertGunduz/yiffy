/**
 * @file show_website.c
 * 
 * @brief This file is used to show yiffy website to the user.
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 01/08/2023
*/

#include "yiffy_text_menus.h"

/**
 * @brief Shows the yiffy website URL to user.
*/
void show_website()
{
    fprintf(stdout, "<https://mertgunduz.github.io/yiffy>\n\n");
    
    fprintfH(stdout, "website content and functionalities");
    fprintf(stdout, "you can find releases, updates, mail lists and news.\n");
    fprintf(stdout, "before contributing you can check the general guidelines.\n");
}
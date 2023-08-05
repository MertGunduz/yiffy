/**
 * @file showWebsite.c
 * 
 * @brief shows the website url 
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 01/08/2023
*/

#include "yiffy-text-menus.h"

/// @brief shows the website url 
void showWebsite()
{
    fprintf(stdout, "<https://mertgunduz.github.io/yiffy>\n\n");
    
    fprintfH(stdout, "website content and functionalities");
    fprintf(stdout, "you can find releases, updates, mail lists and news.\n");
    fprintf(stdout, "before contributing you can check the general guidelines.\n");
}
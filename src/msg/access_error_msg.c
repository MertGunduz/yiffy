/**
 * @file access_error_msg.c
 * 
 * @brief This file is used to give message about the accessibility to the e621/e926 api.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 02/10/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Gives message about the accessibility to the e621/e926 api.
*/ 
void access_error_msg()
{
    fprintf(stderr, "yiffy: can\'t access the e621/e926 API.\n");
    fprintf(stderr, "yiffy: please check if the website is down.\n");
}
/**
 * @file access_error_msg.c
 * 
 * @brief This file is used to check the accessibility to the e621/e926 api.
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Checks the accessibility to the e621/e926 api.
*/ 
void access_error_msg()
{
    fprintf(stderr, "yiffy: can\'t access the e621/e926 API.\n");
    fprintf(stderr, "yiffy: please check if the website is down or accessible.\n");
    fprintf(stderr, "yiffy: please use a VPN if e621/e926 is banned in your country.\n");
}
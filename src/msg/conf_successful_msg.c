/**
 * @file conf_successful_msg.c
 * 
 * @brief This file is used to show some information when cjson root gives error.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 05/09/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Shows some information when cjson root gives error.
 * 
 * @param option The config option (wgen, nsfw).
 * @param argv The config argument (on, off).
*/
void conf_successful_msg(char *option, char *argv)
{ 
    fprintf(stderr, "yiffy: %s is set to %s\n", option, argv);
}
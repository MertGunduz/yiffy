/**
 * @file system_func_error_msg.c
 * 
 * @brief This file is used to show some information when system function did not worked.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/08/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Shows some information when system function not works.
*/
void system_func_error_msg()
{ 
    fprintf(stderr, "yiffy: error executing the system command.\n");
    fprintf(stderr, "yiffy: aria2c command might not found, please check app, shell and permissions.\n");
}
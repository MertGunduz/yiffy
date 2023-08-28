/**
 * @file badSystemFuncErrorMessage.c
 * 
 * @brief it shows some information when system function didn't worked
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/08/2023
*/

#include "yiffy-messages.h"

/// @brief it shows some information when system function didn't worked
void badSystemFuncErrorMessage()
{ 
    fprintf(stderr, "yiffy: error executing the system command.\n");
    fprintf(stderr, "yiffy: aria2c command might not found, please check app, shell and permissions.\n");
}
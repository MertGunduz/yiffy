/**
 * @file cjson_error_msg.c
 * 
 * @brief This file is used to show some information when cjson root gives error.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/08/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Shows some information when cjson root gives error.
 * 
 * @param ptrError The CJSON generated error message.
*/
void cjson_error_msg(const char *ptr_error)
{ 
    fprintf(stderr, "yiffy: cjson root %s\n", ptrError);
}
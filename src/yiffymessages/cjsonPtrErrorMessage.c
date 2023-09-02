/**
 * @file cjsonPtrErrorMessage.c
 * 
 * @brief This file is used to show some information when cjson root gives error.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/08/2023
*/

#include "yiffy-messages.h"

/**
 * @brief Shows some information when cjson root gives error.
 * 
 * @param ptrError The CJSON generated error message.
*/
void cjsonPtrErrorMessage(const char *ptrError)
{ 
    fprintf(stderr, "yiffy: cjson root %s\n", ptrError);
}
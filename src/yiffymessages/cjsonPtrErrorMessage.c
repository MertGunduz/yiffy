/**
 * @file cjsonPtrErrorMessage.c
 * 
 * @brief it shows some information when cjson root gives error
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/08/2023
*/

#include "yiffy-messages.h"

/// @brief it shows some information when cjson root gives error
/// @param ptrError 
void cjsonPtrErrorMessage(const char *ptrError)
{ 
    fprintf(stderr, "yiffy: cjson root %s\n", ptrError);
}
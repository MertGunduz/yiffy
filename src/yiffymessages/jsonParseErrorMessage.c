/**
 * @file jsonParseErrorMessage.c
 * 
 * @brief outputs the error message when application can not parse the json content
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 26/08/2023
*/

#include "yiffy-messages.h"

/// @brief outputs the error message when application can not parse the json content
void jsonParseErrorMessage()
{
    fprintf(stderr, "yiffy: error parsing json file.\n");
    fprintf(stderr, "yiffy: check the read and write permissions.\n");
}
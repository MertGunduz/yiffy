/**
 * @file json_parse_error_msg.c
 * 
 * @brief This file is used to output the error message when application can not parse the JSON content.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 26/08/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Outputs the error message when application can not parse the JSON content.
*/ 
void json_parse_error_msg()
{
    fprintf(stderr, "yiffy: error parsing json file.\n");
    fprintf(stderr, "yiffy: check the read and write permissions.\n");
}
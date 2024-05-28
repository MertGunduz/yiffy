/**
 * @file post_error_msg.c
 * 
 * @brief This file is used to output the error when the parsing is faced with an error in the post section.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 28/05/2024
*/

#include "yiffy_messages.h"

/**
 * @brief Outputs the error when the parsing is faced with an error in the post section.
*/ 
void post_error_msg()
{
    fprintf(stderr, "yiffy: post data is not in correct format, not able to parse JSON.\n");
    fprintf(stderr, "yiffy: please try giving different tags.\n");
}
/**
 * @file posts_not_array_error_msg.c
 * 
 * @brief This file is used to output the error when the parsing is faced with an error in the posts section.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 28/05/2024
*/

#include "yiffy_messages.h"

/**
 * @brief Outputs the error when the parsing is faced with an error in the posts section.
*/ 
void posts_not_array_error_msg()
{
    fprintf(stderr, "yiffy: format is not in array type, not able to parse JSON.\n");
    fprintf(stderr, "yiffy: please try giving different tags.\n");
}
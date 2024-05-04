/**
 * @file extra_arg_error_msg.c
 * 
 * @brief This file is used to output the correct format for the prompted option when there is additional invalid argument.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 21/07/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Outputs the correct format for the prompted option when there is additional invalid argument.
 * 
 * @param argument The option prompted by the user. 
*/ 
void extra_arg_error_msg(char *argument)
{
    fprintf(stderr, "yiffy: please delete the argument value.\n");
    fprintf(stderr, "yiffy: the correct format is \"yiffy %s\".\n", argument);
}
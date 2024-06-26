/**
 * @file no_arg_value_msg.c
 * 
 * @brief This file is used to output the correct prompt format when there is no argument value. 
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 21/07/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Outputs the correct prompt format when there is no argument value. 
 * 
 * @param argument The option prompted by the user. 
*/
void no_arg_value_msg(char *argument)
{
    if (strcmp(argument, "--nsfw") == 0)
    {
        fprintf(stderr, "yiffy: please enter the argument value for \"%s\".\n", argument);
        fprintf(stderr, "yiffy: valid values for \"%s\" are on/off.\n", argument);
    }
    else if (strcmp(argument, "--search") == 0 || strcmp(argument, "--dfetch") == 0 || strcmp(argument, "--fetch") == 0 || strcmp(argument, "--ivcommand") == 0 || strcmp(argument, "--uname") == 0 || strcmp(argument, "--apikey") == 0)
    {
        fprintf(stderr, "yiffy: please enter the search tags.\n");
        fprintf(stderr, "yiffy: prompt \"man yiffy\" to read the user manual.\n");
    }
}
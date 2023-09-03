/**
 * @file noArgumentValueMessage.c
 * 
 * @brief This file is used to output the correct prompt format when there is no argument value. 
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Outputs the correct prompt format when there is no argument value. 
 * 
 * @param argument The option prompted by the user. 
*/
void noArgumentValueMessage(char *argument)
{
    if (strcmp(argument, "--wgen") == 0 || strcmp(argument, "--nsfw") == 0)
    {
        fprintf(stderr, "yiffy: please enter the argument value for \"%s\".\n", argument);
        fprintf(stderr, "yiffy: valid values for \"%s\" are on/off.\n", argument);
    }
    else if (strcmp(argument, "--search") == 0 || strcmp(argument, "--dfetch") == 0 || strcmp(argument, "--fetch") == 0)
    {
        fprintf(stderr, "yiffy: please enter the search tags.\n");
        fprintf(stderr, "yiffy: prompt \"man yiffy\" to read the user manual.\n");
    }
}
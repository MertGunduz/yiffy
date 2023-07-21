/**
 * @file noArgumentValueMessage.c
 * 
 * @brief outputs the correct prompt format when there is no argument value 
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#include "yiffy-messages.h"

/// @brief outputs the correct prompt format when there is no argument value 
/// @param argument 
void noArgumentValueMessage(char *argument)
{
    if (strcmp(argument, "--website-generation") == 0 || strcmp(argument, "--proxy") == 0 || strcmp(argument, "--nsfw") == 0)
    {
        fprintf(stderr, "yiffy: please enter the argument value for \"%s\".\n", argument);
        fprintf(stderr, "yiffy: valid values for \"%s\" are on/off.\n", argument);
    }
    else if (strcmp(argument, "--search") == 0)
    {
        fprintf(stderr, "yiffy: please enter the search tags.\n");
        fprintf(stderr, "yiffy: prompt \"man yiffy\" to read the user manual.\n");
    }
}
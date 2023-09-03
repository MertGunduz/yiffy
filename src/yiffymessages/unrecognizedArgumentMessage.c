/**
 * @file unrecognizedArgumentMessage.c
 * 
 * @brief This file is used to give information and output the command prompted by the user when it is not defined as a valid argument.
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Gives information and outputs the command prompted by the user when it is not defined as a valid argument.
 * 
 * @param argument The option prompted by the user.
*/
void unrecognizedArgumentMessage(char *argument)
{
    fprintf(stderr, "yiffy: unrecognized command line argument: \"%s\".\n", argument);
}
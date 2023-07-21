/**
 * @file unrecognizedArgumentMessage.c
 * 
 * @brief gives information and outputs the command prompted by the user when it is not defined as a valid argument
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#include "yiffy-messages.h"

/// @brief gives information and outputs the command prompted by the user when it is not defined as a valid argument
/// @param argument 
void unrecognizedArgumentMessage(char *argument)
{
    fprintf(stderr, "yiffy: unrecognized command line argument: \"%s\".\n", argument);
}
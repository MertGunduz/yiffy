/**
 * @file extraArgumentErrorMessage.c
 * 
 * @brief outputs the format for the argument when there is additional argument
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#include "yiffy-messages.h"

/// @brief outputs the format for the argument when there is additional argument
/// @param argument 
void extraArgumentErrorMessage(char *argument)
{
    fprintf(stderr, "yiffy: please delete the argument value.\n");
    fprintf(stderr, "yiffy: the correct format is \"yiffy %s\".\n", argument);
}
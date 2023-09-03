/**
 * @file onOffMessage.c
 * 
 * @brief This file is used to output the correct argument value (on/off) for specified arguments
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Outputs the correct argument value (on/off) for specified options.
 * 
 * @param argument The option prompted by the user.
*/ 
void onOffMessage(char *argument)
{
    fprintf(stderr, "yiffy: you have entered \"%s\" prompt as second argument.\n", argument);
    fprintf(stderr, "yiffy: please use \"on/off\" as second argument.\n");
}
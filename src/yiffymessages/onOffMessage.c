/**
 * @file onOffMessage.c
 * 
 * @brief outputs the correct argument value (on/off) for specified arguments
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#include "yiffy-messages.h"

/// @brief outputs the correct argument value (on/off) for specified arguments
/// @param argument 
void onOffMessage(char *argument)
{
    fprintf(stderr, "yiffy: you have entered \"%s\" prompt as second argument.\n", argument);
    fprintf(stderr, "yiffy: please use \"on/off\" as second argument.\n");
}
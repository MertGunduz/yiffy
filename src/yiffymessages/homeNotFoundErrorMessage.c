/**
 * @file homeNotFoundErrorMessage.c
 * 
 * @brief This file is used to output the home not found error when application can not access the $HOME environment variable.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 05/08/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Outputs the home not found error when application can not access the $HOME environment variable.
*/
void homeNotFoundErrorMessage()
{
    fprintf(stderr, "yiffy: error getting home directory.\n");
    fprintf(stderr, "yiffy: please check the home directory permissions and environment variables.\n");
}
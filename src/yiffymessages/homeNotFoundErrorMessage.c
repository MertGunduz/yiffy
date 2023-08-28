/**
 * @file homeNotFoundErrorMessage.c
 * 
 * @brief outputs the home not found error when application can not access the $home environment variable
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 05/08/2023
*/

#include "yiffy-messages.h"

/// @brief outputs the home not found error when application can not access the $home environment variable
void homeNotFoundErrorMessage()
{
    fprintf(stderr, "yiffy: error getting home directory.\n");
    fprintf(stderr, "yiffy: please check the home directory permissions and environment variables.\n");
}
/**
 * @file no_results_error_msg.c
 * 
 * @brief This file is used to output the error when there is no response from the API.
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 27/08/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Outputs the error when there is no response from the API.
*/ 
void no_results_error_msg()
{
    fprintf(stderr, "yiffy: couldn\'t find any related posts with the given tags.\n");
    fprintf(stderr, "yiffy: please try giving different tags.\n");
}
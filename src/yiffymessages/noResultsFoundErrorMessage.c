/**
 * @file noResultsFoundErrorMessage.c
 * 
 * @brief outputs the error when there is no response from the API
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 27/08/2023
*/

#include "yiffy-messages.h"

///  @brief outputs the error when there is no response from the API
/// @param argument 
void noResultsFoundErrorMessage()
{
    fprintf(stderr, "yiffy: couldn\'t find any related posts with the given tags.\n");
    fprintf(stderr, "yiffy: please try giving different tags.\n");
}
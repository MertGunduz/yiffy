/**
 * @file fileOpenErrorMessage.c
 * 
 * @brief it shows some information message to give user solutions
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 05/08/2023
*/

#include "yiffy-messages.h"

/// @brief it shows some information message to give user solutions
void fileOpenErrorMessage()
{ 
    fprintf(stderr, "yiffy: error opening the file.\n");
    fprintf(stderr, "yiffy: please check the file read permissions.\n");
}
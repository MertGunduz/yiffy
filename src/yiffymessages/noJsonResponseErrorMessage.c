/**
 * @file noJsonResponseErrorMessage.c
 * 
 * @brief outputs the error when there is no json file 
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 24/08/2023
*/

#include "yiffy-messages.h"

///  @brief outputs the error when there is no json file 
/// @param argument 
void noJsonResponseErrorMessage(FILE *jsonFile)
{
    fprintf(stderr, "yiffy: couldn\'t find the json response file.\n");
    fprintf(stderr, "yiffy: please try giving the file read-write permission to the working directory.\n");

    /* close the file after showing information */
    fclose(jsonFile);
}
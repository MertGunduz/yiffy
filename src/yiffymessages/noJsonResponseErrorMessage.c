/**
 * @file noJsonResponseErrorMessage.c
 * 
 * @brief This file is used to output the error when there is no JSON file. 
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 24/08/2023
*/

#include "yiffy-messages.h"

/**
 * @brief Outputs the error when there is no JSON file. 
 * 
 * @param jsonFile This is used to close the JSON file. 
*/
void noJsonResponseErrorMessage(FILE *jsonFile)
{
    fprintf(stderr, "yiffy: couldn\'t find the json response file.\n");
    fprintf(stderr, "yiffy: please try giving the file read-write permission to the working directory.\n");

    fclose(jsonFile);
}
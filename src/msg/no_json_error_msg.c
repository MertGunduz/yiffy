/**
 * @file no_json_error_msg.c
 * 
 * @brief This file is used to output the error when there is no JSON file. 
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 24/08/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Outputs the error when there is no JSON file. 
 * 
 * @param jsonFile This is used to close the JSON file. 
*/
void no_json_error_msg(FILE *json_file)
{
    fprintf(stderr, "yiffy: couldn\'t find the json response file.\n");
    fprintf(stderr, "yiffy: please try giving the file read-write permission to the working directory and run yiffy again.\n");

    fclose(json_file);
}
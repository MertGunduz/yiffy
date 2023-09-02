/**
 * @file fileOpenErrorMessage.c
 * 
 * @brief This file is used to show some information about file permissions when yiffy is not able to read file.  
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 05/08/2023
*/

#include "yiffy-messages.h"

/**
 * @brief Shows some information about file permissions when yiffy is not able to read file.  
 * 
 * @param file This is used to close the file. 
*/
void fileOpenErrorMessage(FILE *file)
{ 
    fprintf(stderr, "yiffy: error opening the file.\n");
    fprintf(stderr, "yiffy: please check the file read-write permissions.\n");

    fclose(file);
}
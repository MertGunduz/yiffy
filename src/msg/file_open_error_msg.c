/**
 * @file file_open_error_msg.c
 * 
 * @brief This file is used to show some information about file permissions when yiffy is not able to read file.  
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 05/08/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Shows some information about file permissions when yiffy is not able to read file.  
*/
void file_open_error_msg()
{ 
    fprintf(stderr, "yiffy: error opening the file.\n");
    fprintf(stderr, "yiffy: please check the file read-write permissions.\n");
}
/**
 * @file window_create_error_msg.c
 * 
 * @brief This file is used to give information about the window creation error.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 21/07/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Gives information about the window creation error.
*/
void window_create_error_msg()
{
    fprintf(stderr, "yiffy: couldn\'t create a window structure.\n");
    fprintf(stderr, "yiffy: you might be out of swap space or memory, please check memory.\n");
}
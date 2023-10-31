/**
 * @file color_comp_error_msg.c
 * 
 * @brief This file is used to show some information about the color compatibility of a terminal.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 31/10/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Shows some information about the color compatibility of a terminal.
*/
void color_comp_error_msg()
{ 
    fprintf(stderr, "yiffy: terminal does not support colors.\n");
    fprintf(stderr, "yiffy: please try in other terminals.\n");
}
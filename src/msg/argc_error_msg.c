/**
 * @file argc_error_msg.c
 * 
 * @brief This file is used to evaluate the argument count and give information if not in the requested format.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 21/07/2023
*/

#include "yiffy_messages.h"

/**
 * @brief Evaluates the argument count and gives information if not in the requested format.
 * 
 * @param argc This is the argument count value.
*/
void argc_error_msg(int argc)
{
    if (argc == 1)
    {
        fprintf(stderr, "yiffy: please enter more command line arguments.\n");
        fprintf(stderr, "yiffy: prompt \"man yiffy\" to read the user manual.\n");
    }
    else
    {
        fprintf(stderr, "yiffy: please enter less command line arguments.\n");
        fprintf(stderr, "yiffy: prompt \"man yiffy\" to read the user manual.\n");
    }
}
/**
 * @file mallocErrorMessage.c
 * 
 * @brief This file is used to show some information when yiffy cannot allocate memory.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 28/08/2023
*/

#include "yiffy_messages.h"

/** 
 * @brief Shows some information when yiffy cannot allocate memory.
*/ 
void mallocErrorMessage()
{ 
    fprintf(stderr, "yiffy: can\'t allocate memory for the processes.\n");
    fprintf(stderr, "yiffy: you might be out of swap space or memory, please check memory.\n");
}
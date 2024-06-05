/**
 * @file set_credentials_error_msg.c
 * 
 * @brief This file is used to give message if the credentials are not set in the credentials file.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 05/06/2024
*/

#include "yiffy_messages.h"

/**
 * @brief Gives message if the credentials are not set in the credentials file.
*/ 
void set_credentials_error_msg()
{
    fprintf(stderr, "yiffy: credentials are not set.\n");
    fprintf(stderr, "yiffy: please set your credentials to use search/fetch functionalities.\n");
}
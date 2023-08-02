/**
 * @file showGithub.c
 * 
 * @brief shows the github url
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/08/2023
*/

#include "yiffy-text-menus.h"

/// @brief shows the github url
void showGithub()
{
    fprintf(stdout, "<https://github.com/MertGunduz/yiffy>\n\n");
    fprintf(stdout, "contribution and issue creating links\n");
    fprintf(stdout, "-------------------------------------\n");
    fprintf(stdout, "go to <https://github.com/MertGunduz/mkhtml/issues/new> to open an issue.\n");
    fprintf(stdout, "go to <https://github.com/MertGunduz/mkhtml/issues> to view issues.\n");
}
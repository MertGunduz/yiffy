/**
 * @file show_github.c
 * 
 * @brief This file is used to show project github URL, current issues to the user.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 01/08/2023
*/

#include "yiffy_text_menus.h"

/**
 * @brief Shows the project github URL, current issues to user.
*/
void show_github()
{
    fprintf(stdout, "https://github.com/MertGunduz/yiffy\n\n");

    fprintf(stdout, "contribution and issue creating links\n");
    fprintf(stdout, "-------------------------------------\n");
    fprintf(stdout, "go to https://github.com/MertGunduz/yiffy/issues/new to open an issue.\n");
    fprintf(stdout, "go to https://github.com/MertGunduz/yiffy/issues to view issues.\n");
}

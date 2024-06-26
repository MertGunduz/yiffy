/**
 * @file show_version.c
 * 
 * @brief This file is used to show version of the app to the user.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 01/08/2023
*/

#include "yiffy_text_menus.h"

/**
 * @brief Shows the version of yiffy to user.
*/
void show_version()
{
    fprintf(stdout, "yiffy (e621-e926 terminal viewer) 1.0.0\n\n");
    
    fprintf(stdout, "technical details about yiffy\n");
    fprintf(stdout, "-----------------------------\n");
    fprintf(stdout, "gnu gpl version 3 <https://gnu.org/licenses/gpl.html> licensed and free to use.\n");
    fprintf(stdout, "you are free to use, change and redistribute it.\n");
    fprintf(stdout, "there is no warranty, to the extent permitted by law.\n");
}
/**
 * @file showVersion.c
 * 
 * @brief shows the version
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/08/2023
*/

#include "yiffy-text-menus.h"

/// @brief shows the version
void showVersion()
{
    fprintf(stdout, "yiffy (e621-e926 terminal viewer) 1.0.0\n\n");
    
    fprintfH(stdout, "technical details about yiffy");
    fprintf(stdout, "gnu gpl version 3 <https://gnu.org/licenses/gpl.html> licensed and free to use.\n");
    fprintf(stdout, "you are free to use, change and redistribute it.\n");
    fprintf(stdout, "there is no warranty, to the extent permitted by law.\n");
}
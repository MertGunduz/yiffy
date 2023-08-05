/**
 * @file fprintfH.c
 * 
 * @brief creates the text header for show menus
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 04/08/2023
*/

#include "yiffy-ui.h"

/// @brief creates the text header for show menus
void fprintfH(FILE *file, char *content)
{
    int size = strlen(content);

    fprintf(stdout, "%s", content); fprintf(stdout, "\n");

    for (int i = 0; i < size; i++)
    {
        fprintf(stdout, "-");
    }

    fprintf(stdout, "\n");
}
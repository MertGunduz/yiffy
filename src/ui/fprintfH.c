/**
 * @file fprintfH.c
 * 
 * @brief This file is used to create the text header.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 04/08/2023
*/

#include "yiffy_ui.h"

/**
 * @brief Create the text header.
 * 
 * @param file This is used for the file output, stdout, stderr or any file can be used.
 * @param content This is used to specify the content to write.
*/
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
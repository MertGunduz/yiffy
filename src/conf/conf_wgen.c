/**
 * @file conf_wgen.c
 * 
 * @brief This file is used to configure the wgen system. If on, it basically generates a collection website.
 * 
 * This file goes to the /home/user/.yiffy/yiffy-config.txt and sets the wgen function to on or off depending the option.
 * 
 * @date 05/09/2023
 * 
 * @author Mehmet Mert Gunduz
*/

#define MAX_FILE_PATH 256
#define MAX_BUFFER_SIZE 512

#include "yiffy_conf.h"

/**
 * @brief Configures the wgen system. If on, it basically generates a collection website.
 * 
 * @param argv This is the value that stores on/off.
*/
void conf_wgen(char *argv)
{
    char file_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    /* Operation boolean, used to check if it exists in the current configuration or not. */
    bool isWgenOn;

    /* To write or delete the configuration setting. Keyword (wgen) has got 4 characters. */
    int optionSize = 4;

    /* To set the index of the option. */
    int wgenIndex;

    /* Get the home directory of the current user. */
    char *home_directory = getenv("HOME");

    if (home_directory == NULL) 
    {
        no_home_error_msg();
        exit(1);
    }

    /* Create the configuration file path. */
    sprintf(file_path, "%s/.yiffy/yiffy-config.txt", home_directory);

    /* create file pointer */
    FILE *confReadWriteFile = fopen(file_path, "r+");

    if (confReadWriteFile == NULL)
    {
        file_open_error_msg(confReadWriteFile);
        exit(EXIT_FAILURE);
    }

    fscanf(confReadWriteFile, "%s", buffer);

    /* Close the conf read file. */
    fclose(confReadWriteFile);

    /* Get the buffer size. */
    int bufferSize = strlen(buffer); 

    /* Check if the wgen string exists. */
    char *string = strstr(buffer, "wgen");
    
    if (string != NULL)
    {
        /* Get the index of the wgen token. */
        wgenIndex = string - buffer;

        /* Set the boolean to true to make operations. */
        isWgenOn = true;
    }

    if (strcmp(argv, "on") == 0 && isWgenOn)
    {
        already_conf_msg("wgen", argv);
    }
    else if (strcmp(argv, "on") == 0 && !isWgenOn)
    {
        FILE *confAppendFile = fopen(file_path, "a");

        if (confAppendFile == NULL)
        {
            file_open_error_msg(confAppendFile);
            exit(EXIT_FAILURE);
        }

        fprintf(confAppendFile, ":wgen");

        fclose(confAppendFile);

        conf_successful_msg("wgen", argv);
    }
    else if (strcmp(argv, "off") == 0 && !isWgenOn)
    {
        already_conf_msg("wgen", argv);
    }
    else if (strcmp(argv, "off") == 0 && isWgenOn)
    {
        FILE *confWriteFile = fopen(file_path, "w");

        if (confWriteFile == NULL)
        {
            file_open_error_msg(confWriteFile);
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < bufferSize; i++)
        {
            if (wgenIndex == 0)
            {
                if (i == wgenIndex)
                {
                    i = i + optionSize;
                    continue;
                }
            }
            else
            {
                if (i == wgenIndex - 1)
                {
                    i = i + optionSize;
                    continue;
                } 
            }

            fputc(buffer[i], confWriteFile);
        }

        fclose(confWriteFile);

        conf_successful_msg("wgen", argv);
    }
}
/**
 * @file conf_nsfw.c
 * 
 * @brief This file is used to configure the nsfw system. Basically alters the request URL.
 * 
 * This file goes to the /home/user/.yiffy/yiffy-config.txt and sets the nsfw function to on or off depending the option.
 * 
 * @date 05/09/2023
 * 
 * @author Mehmet Mert Gunduz
*/

#define MAX_FILE_PATH 256
#define MAX_BUFFER_SIZE 512

#include "yiffy_conf.h"

/**
 * @brief Configures the nsfw system. Basically alters the request URL.
 * 
 * @param argv This is the value that stores on/off.
*/
void conf_nsfw(char *argv)
{
    char file_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    /* Operation boolean, used to check if it exists in the current configuration or not. */
    bool isNsfwOn;

    /* To write or delete the configuration setting. Keyword (nsfw) has got 4 characters. */
    int optionSize = 4;

    /* To set the index of the option. */
    int nsfwIndex;

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

    /* Check if the nsfw string exists. */
    char *string = strstr(buffer, "nsfw");
    
    if (string != NULL)
    {
        /* Get the index of the nsfw token. */
        nsfwIndex = string - buffer;

        /* Set the boolean to true to make operations. */
        isNsfwOn = true;
    }

    if (strcmp(argv, "on") == 0 && isNsfwOn)
    {
        already_conf_msg("nsfw", argv);
    }
    else if (strcmp(argv, "on") == 0 && !isNsfwOn)
    {
        FILE *confAppendFile = fopen(file_path, "a");

        if (confAppendFile == NULL)
        {
            file_open_error_msg(confAppendFile);
            exit(EXIT_FAILURE);
        }

        fprintf(confAppendFile, ":nsfw");

        fclose(confAppendFile);

        conf_successful_msg("nsfw", argv);
    }
    else if (strcmp(argv, "off") == 0 && !isNsfwOn)
    {
        already_conf_msg("nsfw", argv);
    }
    else if (strcmp(argv, "off") == 0 && isNsfwOn)
    {
        FILE *confWriteFile = fopen(file_path, "w");

        if (confWriteFile == NULL)
        {
            file_open_error_msg(confWriteFile);
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < bufferSize; i++)
        {
            if (nsfwIndex == 0 && i == nsfwIndex)
            {
                i = i + optionSize;
                continue;
            }
            else
            {
                if (i == nsfwIndex - 1)
                {
                    i = i + optionSize;
                    continue;
                } 
            }

            fputc(buffer[i], confWriteFile);
        }

        fclose(confWriteFile);

        conf_successful_msg("nsfw", argv);
    }
}
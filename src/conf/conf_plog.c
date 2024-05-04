/**
 * @file conf_plog.c
 * 
 * @brief This file is used to configure the plog system. If on, it basically generates a collection website.
 * 
 * This file goes to the /home/user/.yiffy/yiffy-config.txt and sets the plog function to on or off depending the option.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 05/09/2023
*/

#define MAX_FILE_PATH 256
#define MAX_BUFFER_SIZE 512

#include "yiffy_conf.h"

/**
 * @brief Configures the plog system. If on, it basically generates a collection website.
 * 
 * @param argv This is the value that stores on/off.
*/
void conf_plog(char *argv)
{
    char file_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    /* Operation boolean, used to check if it exists in the current configuration or not. */
    bool is_plog = false;

    /* To write or delete the configuration setting. Keyword (plog) has got 4 characters. */
    int option_size = 4;

    /* To set the index of the option. */
    int plog_index;

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
    FILE *conf_read_write_file = fopen(file_path, "r+");

    if (conf_read_write_file == NULL)
    {
        file_open_error_msg(conf_read_write_file);
        exit(EXIT_FAILURE);
    }

    fscanf(conf_read_write_file, "%s", buffer);

    /* Close the conf read file. */
    fclose(conf_read_write_file);

    /* Get the buffer size. */
    int buffer_size = strlen(buffer); 

    /* Check if the plog string exists. */
    char *string = strstr(buffer, "plog");
    
    if (string != NULL)
    {
        /* Get the index of the plog token. */
        plog_index = string - buffer;

        /* Set the boolean to true to make operations. */
        is_plog = true;
    }

    if (strcmp(argv, "on") == 0 && is_plog)
    {
        already_conf_msg("plog", argv);
    }
    else if (strcmp(argv, "on") == 0 && !is_plog)
    {
        FILE *conf_append_file = fopen(file_path, "a");

        if (conf_append_file == NULL)
        {
            file_open_error_msg(conf_append_file);
            exit(EXIT_FAILURE);
        }

        fprintf(conf_append_file, ":plog");

        fclose(conf_append_file);

        conf_successful_msg("plog", argv);
    }
    else if (strcmp(argv, "off") == 0 && !is_plog)
    {
        already_conf_msg("plog", argv);
    }
    else if (strcmp(argv, "off") == 0 && is_plog)
    {
        FILE *conf_write_file = fopen(file_path, "w");

        if (conf_write_file == NULL)
        {
            file_open_error_msg(conf_write_file);
            exit(EXIT_FAILURE);
        }

        for (size_t i = 0; i < buffer_size; i++)
        {
            if (plog_index == 0 && i == plog_index)
            {
                i = i + option_size;
                continue;
            }
            else
            {
                if (i == plog_index - 1)
                {
                    i = i + option_size;
                    continue;
                } 
            }

            fputc(buffer[i], conf_write_file);
        }

        fclose(conf_write_file);

        conf_successful_msg("plog", argv);
    }
}
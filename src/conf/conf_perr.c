/**
 * @file conf_perr.c
 * 
 * @brief This file is used to configure the perr system. If on, it basically generates a collection website.
 * 
 * This file goes to the /home/user/.yiffy/yiffy-config.txt and sets the perr function to on or off depending the option.
 * 
 * @date 05/09/2023
 * 
 * @author Mehmet Mert Gunduz
*/

#define MAX_FILE_PATH 256
#define MAX_BUFFER_SIZE 512

#include "yiffy_conf.h"

/**
 * @brief Configures the perr system. If on, it basically generates a collection website.
 * 
 * @param argv This is the value that stores on/off.
*/
void conf_perr(char *argv)
{
    char file_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    /* Operation boolean, used to check if it exists in the current configuration or not. */
    bool is_perr = false;

    /* To write or delete the configuration setting. Keyword (perr) has got 4 characters. */
    int option_size = 4;

    /* To set the index of the option. */
    int perr_index;

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

    /* Check if the perr string exists. */
    char *string = strstr(buffer, "perr");
    
    if (string != NULL)
    {
        /* Get the index of the perr token. */
        perr_index = string - buffer;

        /* Set the boolean to true to make operations. */
        is_perr = true;
    }

    if (strcmp(argv, "on") == 0 && is_perr)
    {
        already_conf_msg("perr", argv);
    }
    else if (strcmp(argv, "on") == 0 && !is_perr)
    {
        FILE *conf_append_file = fopen(file_path, "a");

        if (conf_append_file == NULL)
        {
            file_open_error_msg(conf_append_file);
            exit(EXIT_FAILURE);
        }

        fprintf(conf_append_file, ":perr");

        fclose(conf_append_file);

        conf_successful_msg("perr", argv);
    }
    else if (strcmp(argv, "off") == 0 && !is_perr)
    {
        already_conf_msg("perr", argv);
    }
    else if (strcmp(argv, "off") == 0 && is_perr)
    {
        FILE *conf_write_file = fopen(file_path, "w");

        if (conf_write_file == NULL)
        {
            file_open_error_msg(conf_write_file);
            exit(EXIT_FAILURE);
        }

        for (size_t i = 0; i < buffer_size; i++)
        {
            if (perr_index == 0 && i == perr_index)
            {
                i = i + option_size;
                continue;
            }
            else
            {
                if (i == perr_index - 1)
                {
                    i = i + option_size;
                    continue;
                } 
            }

            fputc(buffer[i], conf_write_file);
        }

        fclose(conf_write_file);

        conf_successful_msg("perr", argv);
    }
}
/**
 * @file show_config.c
 * 
 * @brief This file is used to show current configurations of the app to the user.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 05/08/2023
*/

#define MAX_FILE_PATH 256   ///< This macro is used to set the default size for getting the home directory file.
#define MAX_BUFFER_SIZE 512 ///< This macro is used to set the default size for reading the config file.

char *home_directory; ///< Stores the home directory as string.

char file_path[MAX_FILE_PATH]; ///< Stores the file path for config and credentials files.
char buffer[MAX_BUFFER_SIZE]; ///< Stores the configs and credentials one by one, used for parsing them by using fgets.

#include "yiffy_text_menus.h"

void write_configuration();
void write_credentials();
void write_config_and_credentials();

/// @brief Shows the yiffy configurations to user.
void show_config()
{
    /* Get the home directory of the current user. */
    home_directory = getenv("HOME");

    if (home_directory == NULL) 
    {
        no_home_error_msg();
        exit(1);
    }

    write_config_and_credentials();
}

/// @brief Reads the configuration file and writes the configs one by one.
void write_configuration()
{
    /* Create the configuration file path. */
    sprintf(file_path, "%s/.yiffy/yiffy-config.txt", home_directory);

    FILE *config_file = fopen(file_path, "r");

    if (config_file == NULL)
    {
        file_open_error_msg();
        exit(EXIT_FAILURE);
    }

    /* Write the configurations to terminal. */
    fprintf(stdout, "current yiffy configurations\n");
    fprintf(stdout, "----------------------------\n");

    while (fgets(buffer, MAX_BUFFER_SIZE - 1, config_file))
    {
        fprintf(stdout, "- %s", buffer);
    }

    fclose(config_file);
}

/// @brief Reads the credentials file and writes the credentials one by one.
void write_credentials()
{
    /* Create the configuration file path. */
    sprintf(file_path, "%s/.yiffy/yiffy-credentials.txt", home_directory);

    FILE *credentials_file = fopen(file_path, "r");

    if (credentials_file == NULL)
    {
        file_open_error_msg();
        exit(EXIT_FAILURE);
    }

    /* Write the credentials to terminal. */
    fprintf(stdout, "current yiffy credentials\n");
    fprintf(stdout, "-------------------------\n");

    while (fgets(buffer, MAX_BUFFER_SIZE - 1, credentials_file))
    {
        fprintf(stdout, "- %s", buffer);
    }

    fclose(credentials_file);
}

/// @brief Writes config and credentials and prints a space between them.
void write_config_and_credentials()
{
    write_configuration();
    
    fprintf(stdout, "\n");

    write_credentials();
}
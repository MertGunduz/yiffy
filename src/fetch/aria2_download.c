/**
 * @file aria2_download.c
 * 
 * @brief Downloads the JSON file by using aria2c, works with the system function. 
 * 
 * This file is used to set the request string by checking isNSFW parameter, and downloads the JSON file from e621/e926 API by using aria2c.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 28/08/2023
*/

#include "yiffy_fetch.h"

#define FILE_PATH 256   ///< This macro is used to set the default size for getting the home directory file.
#define BUFFER_SIZE 512 ///< This macro is used to set the default size for reading the config file
#define HOME_SIZE 512 ///< This macro is used to set the default size for home string.
#define CREDENTIAL_SIZE 128 /// < This macro is used to set the default size for credential strings.

static char config_file_path[FILE_PATH]; ///< Stores the config file path for config and credentials files.
static char credentials_file_path[FILE_PATH]; ///< Stores the credentials file path for config and credentials files.
static char buffer[BUFFER_SIZE]; ///< Stores the configs and credentials one by one, used for parsing them by using fgets.
static char uname[CREDENTIAL_SIZE]; ///< Stores the uname.
static char api_key[CREDENTIAL_SIZE]; ///< Stores the API key.

static FILE *config_file; ///< The file struct for managing operations on config file.
static FILE *credentials_file; ///< The file struct for managing operations on credentials file.

static bool get_nsfw();
static char *get_credential(char *credential);

/// @brief downloads the API response by using aria2c, works with a system call
/// @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
/// @param page This is the value that is passed to the API to get results from the specified pages.
/// @param is_nsfw This is the boolean value that checks the NSFW option. If true, sets the request string for e621 otherwise sets for e926.
void aria2_download(char *tags, int page, int lim)
{
    /* NSFW option for the API request. */
    bool is_nsfw = get_nsfw();

    /* Credentials for the API request. */
    strcpy(uname, get_credential("UNAME"));
    strcpy(api_key, get_credential("API_KEY"));

    /* Allocate space for request string. */
    char *request_string = (char*)malloc(256 * sizeof(char));

    if (request_string == NULL)
    {
        malloc_error_msg();
        exit(EXIT_FAILURE);
    }

    /* Set the string for NSFW or SFW option by checking the isNsfw parameter. */
    if (is_nsfw)
    {
        sprintf(request_string, "aria2c \"https://e621.net/posts.json?login=%s&api_key=%s&limit=%d&page=%d&tags=%s\" -o posts.json >/dev/null 2>&1", uname, api_key, lim, page, tags);
    }
    else
    {
        sprintf(request_string, "aria2c \"https://e926.net/posts.json?login=%s&api_key=%s&limit=%d&page=%d&tags=%s\" -o posts.json >/dev/null 2>&1", uname, api_key, lim, page, tags);
    }

    /* Download the JSON and set a sleep(1) for signals. */
    int success = system(request_string);
    sleep(1);

    free(request_string);

    if (success == BAD_SYSTEM_FUNC_CALL)
    {
        system_func_error_msg();
        exit(EXIT_FAILURE);
    }
}

/// @brief Sets the NSFW option by reading the config file.
/// @return Returns true if the option is set to YES, otherwise false.
static bool get_nsfw()
{
    /* Get the home environment. */
    char *home = getenv("HOME");

    if (home == NULL) 
    {
        no_home_error_msg();
        exit(EXIT_FAILURE);
    }

    sprintf(config_file_path, "%s/.yiffy/yiffy-config.txt", home);

    /* Read the configuration file (home/user/.yiffy/yiffy-config.txt) to execute the wanted process. */
    config_file = fopen(config_file_path, "r");

    if (config_file == NULL) 
    {
        file_open_error_msg();
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE - 1, config_file))
    {
        if (strcmp(buffer, "IS_NSFW=YES\n") == 0)
        {
            /* Close the config_file. */
            fclose(config_file);
            
            /* Return true if the IS_NSFW is YES. */
            return true;
        }
    }

    /* Close the config_file. */
    fclose(config_file);

    /* Return false if the IS_NSFW is NO. */
    return false;
}

/// @brief Gets the selected credential by reading the credentials file.
/// @param option The option to return (USERNAME, API_KEY).
/// @return Returns the selected credential.
static char *get_credential(char *option)
{
    /* Credential string to return. */
    char *credential;

    /* Get the home environment. */
    char *home = getenv("HOME");

    if (home == NULL) 
    {
        no_home_error_msg();
        exit(EXIT_FAILURE);
    }

    sprintf(credentials_file_path, "%s/.yiffy/yiffy-credentials.txt", home);

    /* Read the credentials file (home/user/.yiffy/yiffy-credentials.txt) to execute the wanted process. */
    credentials_file = fopen(credentials_file_path, "r");

    if (credentials_file == NULL) 
    {
        file_open_error_msg();
        exit(EXIT_FAILURE);
    }

    /* Read the credential. */
    while (fgets(buffer, BUFFER_SIZE - 1, credentials_file))
    {
        if (strstr(buffer, option))
        {
            /* Get the credential. */
            credential = strstr(buffer, "=");

            /* Increase the r_credential pointer index by 1 to get rid of equal sign. */
            credential++;

            break;
        }
    }

    /* Close the credentials file. */
    fclose(credentials_file);

    /* If the credential not null, return it. */
    if (strcmp(credential, "NULL\n") != 0)
    {
        /* Set the last \n to \0. */
        credential[strlen(credential) - 1] = '\0';

        return credential;
    }
    else
    {
        set_credentials_error_msg();
        exit(EXIT_FAILURE);
    }
}
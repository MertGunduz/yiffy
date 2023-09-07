/**
 * @file fetch.c
 * 
 * @brief This file is used to send requests to e621-e926 with the specified tags by user and outputs or outputs-downloads URLs.
 * 
 * This file is used to send a request to the fetch data from API and output the post URLs.
 * Fetch function is used to check the configuration files and send request to the API. After that it takes the response and checks if JSON file is in the right format.
 * Output function is used to read and parse the JSON file. Also outputs the URLs to the terminal or redirected path. 
 * 
 * @author Mehmet Mert Gunduz 
 *
 * @date 21/07/2023
*/

#define MAX_FILE_PATH 256 ///< This macro is used to set the default size for getting the home directory file.
#define MAX_BUFFER_SIZE 512 ///< This macro is used to set the default size for reading the config file
#define CONTENT_SIZE 262144 ///< This macro is used to set the default size for reading the JSON file that comes as a response from the API.

#include "yiffy_search.h"

static void output(char *json_content, char *command);

static int total_downloads = 0;

/**
 * @brief Reads the configuration file, sets the options and sends a request to e621-e926. After taking the response, it calls the output function to show the URLs. 
 * 
 * @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
 * @param page This is the value that is passed to the API to get results from the specified pages.
 * @param command This is the value that checks if to output or output-download the URLs.
*/
void fetch(char *tags, int page, char *command)
{
    char config_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    bool is_nsfw = false;

    char *home = getenv("HOME");

    if (home == NULL) 
    {
        no_home_error_msg();
        exit(EXIT_FAILURE);
    }

    sprintf(config_path, "%s/.yiffy/yiffy-config.txt", home);

    /* Read the configuration file (home/user/.yiffy/yiffy-config.txt) to execute the wanted process. */
    FILE *config = fopen(config_path, "r");

    if (config == NULL) 
    {
        file_open_error_msg(config);
        exit(EXIT_FAILURE);
    }

    size_t config_bytes = fread(buffer, 1, MAX_BUFFER_SIZE - 1, config); 
    buffer[config_bytes] = '\0';

    fclose(config);

    char *token = strtok(buffer, ":");

    while (token != NULL) 
    {
        if (strcmp(token, "nsfw") == 0) 
        {
            is_nsfw = true;
            break;
        }

        token = strtok(NULL, ":");
    }

    /* Download the JSON response. */
    aria2_download(tags, page, is_nsfw);

    /* Check if the JSON response downloaded. */
    FILE *response_json = fopen("posts.json", "r");

    if (response_json == NULL)
    {
        no_json_error_msg(response_json);
        exit(EXIT_FAILURE);
    }

    /* Allocate memory to store the JSON response content. */
    char *json_control_content = (char*)malloc(CONTENT_SIZE * sizeof(char));

    if (json_control_content == NULL)
    {
        malloc_error_msg();
        exit(EXIT_FAILURE);
    }
    
    size_t bytes_read = fread(json_control_content, 1, CONTENT_SIZE - 1, response_json);
    json_control_content[bytes_read] = '\0';

    fclose(response_json);

    /* Check if the JSON response is empty. */
    if (strcmp(json_control_content, "{\"posts\":[]}") == 0) 
    {
        if (total_downloads == 0)
        {
            no_results_error_msg();
        }
        
        free(json_control_content);

        remove("posts.json");
        
        exit(EXIT_FAILURE);
    }

    /* Output the URLs by using the current JSON file. */
    output(json_control_content, command);
}

/**
 * @brief Reads and parses the JSON file. Also outputs the URLs to the terminal or redirected path.
 * 
 * @param json_content This is the JSON content coming from the e621/e926 API.
 * @param command This is the data (--dfetch, --fetch) that is prompted by the user.
*/
static void output(char *json_content, char *command)
{
    /* Parse the JSON response data. */
    cJSON *root = cJSON_Parse(json_content);

    free(json_content);

    if (root == NULL) 
    {
        const char *error_ptr = cJSON_GetErrorPtr();
    
        if (error_ptr != NULL) 
        {
            cjson_error_msg(error_ptr);
        }
    
        json_parse_error_msg();
        cJSON_Delete(root);
        exit(EXIT_FAILURE);
    }

    /* Navigate to the posts array. */
    cJSON *posts_array = cJSON_GetObjectItemCaseSensitive(root, "posts");

    if (cJSON_IsArray(posts_array)) 
    {
        int total_posts = cJSON_GetArraySize(posts_array);

        // Iterate through the posts array.
        for (int i = 0; i < total_posts; i++) 
        {
            cJSON *post = cJSON_GetArrayItem(posts_array, i);
            cJSON *file = cJSON_GetObjectItemCaseSensitive(post, "file") ;
                
            if (cJSON_IsObject(file))
            {
                cJSON *file_url_obj = cJSON_GetObjectItemCaseSensitive(file, "url");

                /* Check if the url field exists and is a string. */
                if (cJSON_IsString(file_url_obj)) 
                {
                    const char *file_url = file_url_obj->valuestring;
                    
                    fprintf(stdout, "%s\n", file_url);

                    /* If the command is --dfetch download the fetched URLs. */
                    if (strcmp(command, "--dfetch") == 0)
                    {
                        /* Alloc for downloading process. */
                        char *download_command = (char*)malloc(256 * sizeof(char));

                        sprintf(download_command, "aria2c %s >/dev/null 2>&1", file_url);

                        int download_success = system(download_command);

                        if (download_success == BAD_SYSTEM_FUNC_CALL)
                        {
                            free(download_command);
                            exit(EXIT_FAILURE);
                        }

                        free(download_command);
                    }

                    /* Increase the total downloads, this is used to control if any posts downloaded. */
                    total_downloads++;
                }
            }
        }
    }

    /* Clean up cJSON object. */
    cJSON_Delete(root);

    /* Delete posts.json file. */
    remove("posts.json");
}
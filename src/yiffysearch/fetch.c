/**
 * @file fetch.c
 * 
 * @brief Sends request to e621-e926 with the specified tags by user and outputs URLs.
 * 
 * This file is used to send a request to the fetch data from API and output the post URLs.
 * Fetch function is used to check the configuration files and send request to the API. After that it takes the response and checks if JSON file is in the right format.
 * Output function is used to read and parse the JSON file. Also outputs the URLs to the terminal or redirected path. 
 * 
 * @author Mehmet Mert Gunduz 
 *
 * @date 21/07/2023
*/

#define MAX_FILE_PATH 256 ///< This macro is used for the home directory file path size.
#define MAX_BUFFER_SIZE 512 ///< This macro is used to set the size of an array which reads the config file.
#define CONTENT_SIZE 262144 ///< This macro is used to set the size of an array which reads the JSON file that comes as a response from the API.

#include "yiffy-search.h"

static void output();

static int totalDownloads = 0;

/**
 * @brief Reads the configuration file, sets the options and sends a request to e621-e926. After taking the response, it calls the output function to show the URLs to user. 
 * 
 * @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
 * @param page This is the value that is passed to the API to get results from the specified pages.
*/
void fetch(char *tags, int page)
{
    char file_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    bool isNsfw = false;

    char *home = getenv("HOME");

    if (home == NULL) 
    {
        homeNotFoundErrorMessage();
        exit(EXIT_FAILURE);
    }

    sprintf(file_path, "%s/.yiffy/yiffy-config.txt", home);

    /* Read the configuration file (home/user/.yiffy/yiffy-config.txt) to execute the wanted process. */
    FILE *config = fopen(file_path, "r");

    if (config == NULL) 
    {
        fileOpenErrorMessage(config);
        exit(EXIT_FAILURE);
    }

    size_t configBytes = fread(buffer, 1, MAX_BUFFER_SIZE - 1, config); 
    buffer[configBytes] = '\0';

    char *token = strtok(buffer, ":");

    while (token != NULL) 
    {
        if (strcmp(token, "nsfw") == 0) 
        {
            isNsfw = true;
        }

        token = strtok(NULL, ":");
    }

    /* Download the JSON response. */
    aria2Download(tags, page, isNsfw);

    /* Check if the JSON response downloaded. */
    FILE *responseJson = fopen("posts.json", "r");

    if (responseJson == NULL)
    {
        noJsonResponseErrorMessage(responseJson);
        exit(EXIT_FAILURE);
    }

    /* Allocate memory to store the JSON response content. */
    char *jsonControlContent = (char *)malloc(CONTENT_SIZE * sizeof(char));

    if (jsonControlContent == NULL)
    {
        mallocErrorMessage();
        exit(EXIT_FAILURE);
    }
    
    size_t bytesRead = fread(jsonControlContent, 1, CONTENT_SIZE - 1, responseJson);
    jsonControlContent[bytesRead] = '\0';

    /* Check if the JSON response is empty. */
    if (strcmp(jsonControlContent, "{\"posts\":[]}") == 0) 
    {
        if (totalDownloads == 0)
        {
            noResultsFoundErrorMessage();
        }
        
        free(jsonControlContent);
        fclose(responseJson);

        remove("posts.json");
        
        exit(EXIT_FAILURE);
    }

    /* Close the opened files for further processes. */
    fclose(config);
    fclose(responseJson);

    /* Free the memory. */
    free(jsonControlContent);

    /* Output the URLs by using the current JSON file. */
    output();
}

/**
 * @brief Reads and parses the JSON file. Also outputs the URLs to the terminal or redirected path.
*/
static void output()
{
    /* Allocate memory for JSON file. */
    char *jsonContent = (char*)malloc(CONTENT_SIZE * sizeof(char));

    /* Read the json file. */
    FILE *jsonFile = fopen("posts.json", "r");
        
    if (jsonFile == NULL)
    {
        fileOpenErrorMessage(jsonFile);
        exit(EXIT_FAILURE);
    }

    /* read the file and return bytes*/
    size_t bytesRead = fread(jsonContent, 1, CONTENT_SIZE - 1, jsonFile);
    jsonContent[bytesRead] = '\0';
    
    /* Parse the JSON response data. */
    cJSON *root = cJSON_Parse(jsonContent);

    if (root == NULL) 
    {
        const char *error_ptr = cJSON_GetErrorPtr();
    
        if (error_ptr != NULL) 
        {
            cjsonPtrErrorMessage(error_ptr);
        }
    
        jsonParseErrorMessage();
        free(jsonContent);
        cJSON_Delete(root);
        exit(EXIT_FAILURE);
    }

    /* Navigate to the posts array. */
    cJSON *posts_array = cJSON_GetObjectItemCaseSensitive(root, "posts");

    if (cJSON_IsArray(posts_array)) 
    {
        int num_posts = cJSON_GetArraySize(posts_array);

        // Iterate through the posts array.
        for (int i = 0; i < num_posts; i++) 
        {
            cJSON *post_obj = cJSON_GetArrayItem(posts_array, i);
            cJSON *file_obj = cJSON_GetObjectItemCaseSensitive(post_obj, "file") ;
                
            if (cJSON_IsObject(file_obj)) 
            {
                cJSON *fileUrlObj = cJSON_GetObjectItemCaseSensitive(file_obj, "url");

                /* Check if the url field exists and is a string. */
                if (cJSON_IsString(fileUrlObj)) 
                {
                    const char *file_url = fileUrlObj->valuestring;
                    
                    fprintf(stdout, "%s\n", file_url);

                    /* Increase the total downloads, this is used to control if any posts downloaded. */
                    totalDownloads++;
                }
            }
        }
    }

    /* Close the files. */
    fclose(jsonFile);

    /* Free memory. */
    free(jsonContent);

    /* Clean up cJSON object. */
    cJSON_Delete(root);

    /* Delete posts.json file. */
    remove("posts.json");
}
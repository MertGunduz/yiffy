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

#include "yiffy-search.h"

static void output(char *jsonContent, char *command);

static int totalDownloads = 0;

/**
 * @brief Reads the configuration file, sets the options and sends a request to e621-e926. After taking the response, it calls the output function to show the URLs. 
 * 
 * @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
 * @param page This is the value that is passed to the API to get results from the specified pages.
 * @param command This is the value that checks if to output or output-download the URLs.
*/
void fetch(char *tags, int page, char *command)
{
    char configPath[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    bool isNsfw = false;

    char *home = getenv("HOME");

    if (home == NULL) 
    {
        homeNotFoundErrorMessage();
        exit(EXIT_FAILURE);
    }

    sprintf(configPath, "%s/.yiffy/yiffy-config.txt", home);

    /* Read the configuration file (home/user/.yiffy/yiffy-config.txt) to execute the wanted process. */
    FILE *config = fopen(configPath, "r");

    if (config == NULL) 
    {
        fileOpenErrorMessage(config);
        exit(EXIT_FAILURE);
    }

    size_t configBytes = fread(buffer, 1, MAX_BUFFER_SIZE - 1, config); 
    buffer[configBytes] = '\0';

    fclose(config);

    char *token = strtok(buffer, ":");

    while (token != NULL) 
    {
        if (strcmp(token, "nsfw") == 0) 
        {
            isNsfw = true;
            break;
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
    char *jsonControlContent = (char*)malloc(CONTENT_SIZE * sizeof(char));

    if (jsonControlContent == NULL)
    {
        mallocErrorMessage();
        exit(EXIT_FAILURE);
    }
    
    size_t bytesRead = fread(jsonControlContent, 1, CONTENT_SIZE - 1, responseJson);
    jsonControlContent[bytesRead] = '\0';

    fclose(responseJson);

    /* Check if the JSON response is empty. */
    if (strcmp(jsonControlContent, "{\"posts\":[]}") == 0) 
    {
        if (totalDownloads == 0)
        {
            noResultsFoundErrorMessage();
        }
        
        free(jsonControlContent);

        remove("posts.json");
        
        exit(EXIT_FAILURE);
    }

    /* Output the URLs by using the current JSON file. */
    output(jsonControlContent, command);
}

/**
 * @brief Reads and parses the JSON file. Also outputs the URLs to the terminal or redirected path.
*/
static void output(char *jsonContent, char *command)
{
    /* Parse the JSON response data. */
    cJSON *root = cJSON_Parse(jsonContent);

    free(jsonContent);

    if (root == NULL) 
    {
        const char *errorPtr = cJSON_GetErrorPtr();
    
        if (errorPtr != NULL) 
        {
            cjsonPtrErrorMessage(errorPtr);
        }
    
        jsonParseErrorMessage();
        cJSON_Delete(root);
        exit(EXIT_FAILURE);
    }

    /* Navigate to the posts array. */
    cJSON *postsArray = cJSON_GetObjectItemCaseSensitive(root, "posts");

    if (cJSON_IsArray(postsArray)) 
    {
        int totalPosts = cJSON_GetArraySize(postsArray);

        // Iterate through the posts array.
        for (int i = 0; i < totalPosts; i++) 
        {
            cJSON *post = cJSON_GetArrayItem(postsArray, i);
            cJSON *file = cJSON_GetObjectItemCaseSensitive(post, "file") ;
                
            if (cJSON_IsObject(file)) 
            {
                cJSON *fileUrlObj = cJSON_GetObjectItemCaseSensitive(file, "url");

                /* Check if the url field exists and is a string. */
                if (cJSON_IsString(fileUrlObj)) 
                {
                    const char *fileURL = fileUrlObj->valuestring;
                    
                    fprintf(stdout, "%s\n", fileURL);

                    /* If the command is --dfetch download the fetched URLs. */
                    if (strcmp(command, "--dfetch") == 0)
                    {
                        /* Alloc for downloading process. */
                        char *downloadCommand = (char*)malloc(256 * sizeof(char));

                        sprintf(downloadCommand, "aria2c %s >/dev/null 2>&1", fileURL);

                        int downloadSuccess = system(downloadCommand);

                        if (downloadSuccess == BAD_SYSTEM_FUNC_CALL)
                        {
                            free(downloadCommand);
                            exit(EXIT_FAILURE);
                        }

                        free(downloadCommand);
                    }

                    /* Increase the total downloads, this is used to control if any posts downloaded. */
                    totalDownloads++;
                }
            }
        }
    }

    /* Clean up cJSON object. */
    cJSON_Delete(root);

    /* Delete posts.json file. */
    remove("posts.json");
}
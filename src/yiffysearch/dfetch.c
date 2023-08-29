/**
 * @file dfetch.c
 * 
 * @brief sends request to e621 with the specified tags and takes response
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 28/08/2023
*/

#define MAX_FILE_PATH 256
#define MAX_BUFFER_SIZE 512

#include "yiffy-search.h"

static void dDownload();

static int totalDownloads = 0;

/// @brief sends request to e621 with the specified tags and takes response
/// @param tagString
/// @param page
void dfetch(char *tags, int page)
{
    /* file path and buffer */
    char file_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    /* configuration booleans */
    bool isNsfw = false;

    /* take the home directory of the current user */
    char *home_directory = getenv("HOME");

    if (home_directory == NULL)
    {
        homeNotFoundErrorMessage();
        exit(EXIT_FAILURE);
    }

    /* create the file path for the /home/.yiffy/yiffy-config file to read the configurations */
    sprintf(file_path, "%s/.yiffy/yiffy-config.txt", home_directory);

    FILE *configurationFile = fopen(file_path, "r");

    if (configurationFile == NULL)
    {
        fileOpenErrorMessage(configurationFile);
        exit(EXIT_FAILURE);
    }

    /* read the configurations file (wgen:nsfw) */
    fscanf(configurationFile, "%s", buffer);

    /* tokenize the configuration string to get the data one by one */
    char *token = strtok(buffer, ":");

    while (token != NULL)
    {
        if (strcmp(token, "nsfw") == 0)
        {
            isNsfw = true;
        }

        token = strtok(NULL, ":");
    }

    /* download the response from e621/926 API */
    aria2Download(tags, page, isNsfw);

    /* check if the file exists */
    FILE *responseJson = fopen("posts.json", "r");

    /* return validation integer */
    if (responseJson == NULL)
    {
        noJsonResponseErrorMessage(responseJson);
        exit(EXIT_FAILURE);
    }

    /* allocate memory to store the content */
    char *jsonControlContent = (char *)malloc(262144 * sizeof(char));

    if (jsonControlContent == NULL)
    {
        mallocErrorMessage();
        exit(EXIT_FAILURE);
    }
    
    /* read the file and check if empty, put null terminator at the end */
    size_t bytesRead = fread(jsonControlContent, 1, 262143, responseJson);
    jsonControlContent[bytesRead] = '\0';

    /* check if there is no content related to the prompted tags, checks if json response empty */
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

    /* close the file */
    free(jsonControlContent);
    fclose(responseJson);

    /* download the sample posts by using the url's in the current json file */
    dDownload();
}

/// @brief downloads the sample posts to show in the terminal user interface
static void dDownload()
{
    /* memory allocation for whole json file */
    char *jsonContent = (char*)malloc(262144 * sizeof(char));

    /* read the json file */
    FILE *jsonFile = fopen("posts.json", "r");
        
    if (jsonFile == NULL)
    {
        fileOpenErrorMessage(jsonFile);
        exit(EXIT_FAILURE);
    }

    /* read the file and return bytes*/
    size_t bytesRead = fread(jsonContent, 1, 262143, jsonFile);

    /* null terminate the jsoncontent */
    jsonContent[bytesRead] = '\0';
    
    // Parse the JSON data
    cJSON *root = cJSON_Parse(jsonContent);

    if (root == NULL) 
    {
        const char *error_ptr = cJSON_GetErrorPtr();
    
        if (error_ptr != NULL) 
        {
            cjsonPtrErrorMessage(error_ptr);
        }
    
        jsonParseErrorMessage();
        cJSON_Delete(root);
        exit(EXIT_FAILURE);
    }

    /* Navigate to the "posts" array */
    cJSON *posts_array = cJSON_GetObjectItemCaseSensitive(root, "posts");

    if (cJSON_IsArray(posts_array)) 
    {
        int num_posts = cJSON_GetArraySize(posts_array);

        // Iterate through the "posts" array
        for (int i = 0; i < num_posts; i++) 
        {
            cJSON *post_obj = cJSON_GetArrayItem(posts_array, i);
            cJSON *file_obj = cJSON_GetObjectItemCaseSensitive(post_obj, "file") ;
                
            if (cJSON_IsObject(file_obj)) 
            {
                cJSON *fileUrlObj = cJSON_GetObjectItemCaseSensitive(file_obj, "url");

                // Check if the "url" field exists and is a string
                if (cJSON_IsString(fileUrlObj)) 
                {
                    const char *file_url = fileUrlObj->valuestring;
                    
                    fprintf(stdout, "%s\n", file_url);

                    /* alloc for downloading process*/
                    char *imageURL = (char*)malloc(256 * sizeof(char));

                    sprintf(imageURL, "aria2c %s >/dev/null 2>&1", file_url);

                    int downloadSuccess = system(imageURL);

                    if (downloadSuccess == BAD_SYSTEM_FUNC_CALL)
                    {
                        free(imageURL);
                        exit(EXIT_FAILURE);
                    }

                    /* free the memory after downloading the image by using the url */
                    free(imageURL);

                    /* increase the total downloads */
                    totalDownloads++;
                }
            }
        }
    }

    /* free memory */
    if (jsonContent != NULL)
    {
        free(jsonContent);
    }

    /* Clean up cJSON objects */
    if (root != NULL)
    {
        cJSON_Delete(root);
    }

    /* delete posts.json */
    remove("posts.json");
}
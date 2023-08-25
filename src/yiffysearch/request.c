/**
 * @file e621Request.c
 * 
 * @brief sends request to e621 with the specified tags and takes response
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#define MAX_FILE_PATH 256
#define MAX_BUFFER_SIZE 512

#include "yiffy-search.h"

static void download();

/// @brief sends request to e621 with the specified tags and takes response
/// @param tags 
/// @return the request url
void request(char *tagString)
{
    /* request string */
    char *requestString = (char*)malloc(256 * sizeof(char));

    /* configuration booleans */
    bool isNsfw = false;

    /* file path and line buffer */
    char file_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

    /* take the home directory of the current user */
    char *home_directory = getenv("HOME");

    if (home_directory == NULL) 
    {
        homeNotFoundErrorMessage();
        exit(EXIT_FAILURE);
    }

    /* create the file path */
    sprintf(file_path, "%s/.yiffy/yiffy-config.txt", home_directory);

    /* create file pointer */
    FILE *configurationFile = fopen(file_path, "r");

    if (configurationFile == NULL)
    {
        fileOpenErrorMessage();
        exit(EXIT_FAILURE);
    }

    /* read and the content */
    fscanf(configurationFile, "%s", buffer);

    /* tokenize the configuration string */
    char *token = strtok(buffer, ":");

    while (token != NULL)
    {
        if (strcmp(token, "nsfw") == 0)
        {
            isNsfw = true;
        }

        token = strtok(NULL, ":");
    }

    // check if nsfw on send request to e621 if not send to e926
    if (isNsfw)
    {
        sprintf(requestString, "aria2c \"https://e621.net/posts.json?limit=10&tags=%s\" -o posts.json >/dev/null 2>&1", tagString);
    }
    else
    {
        sprintf(requestString, "aria2c \"https://e926.net/posts.json?limit=10&tags=%s\" -o posts.json >/dev/null 2>&1", tagString);
    }

    /* send request to url */
    system(requestString);

    /* check if the file exists */
    FILE *responseJson = fopen("posts.json", "r");

    /* return validation integer */
    if (responseJson == NULL)
    {
        noJsonResponseErrorMessage();
        exit(EXIT_FAILURE);
    }

    /* close the file */
    fclose(responseJson);

    /* download the sample posts by using the url's in the current json file */
    download();
}

/// @brief downloads the sample posts to show in the terminal user interface
static void download()
{
    /* memory allocation for json file and posts */
    char *jsonContent = (char*)malloc(32768 * sizeof(char));
    //char *post = (char*)malloc(4096 * sizeof(char));
        
    /* read the json file */
    FILE *jsonFile = fopen("posts.json", "r");
        
    if (jsonFile == NULL)
    {
        fileOpenErrorMessage();
        exit(EXIT_FAILURE);
    }

    size_t bytesRead = fread(jsonContent, 1, 32767, jsonFile);

    if (bytesRead < 32767)
    {
        jsonContent[bytesRead] = '\0';
    }
    else
    {
        // create a message function for this
        fprintf(stderr, "File is too large for the buffer\n");
    }
        
    // Parse the JSON data
    cJSON *root = cJSON_Parse(jsonContent);
    if (root == NULL) {
        fprintf(stderr, "Error parsing JSON: %s\n", cJSON_GetErrorPtr());
        exit(EXIT_FAILURE);
    }

    // Navigate to the "posts" array
    cJSON *posts_array = cJSON_GetObjectItemCaseSensitive(root, "posts");
    
    if (cJSON_IsArray(posts_array)) 
    {
        int num_posts = cJSON_GetArraySize(posts_array);

        // Iterate through the "posts" array
        for (int i = 0; i < num_posts; i++) 
        {
            cJSON *post_obj = cJSON_GetArrayItem(posts_array, i);
            cJSON *sample_obj = cJSON_GetObjectItemCaseSensitive(post_obj, "sample");
                
            if (cJSON_IsObject(sample_obj)) 
            {
                cJSON *url_obj = cJSON_GetObjectItemCaseSensitive(sample_obj, "url");
                    
                // Check if the "url" field exists and is a string
                if (cJSON_IsString(url_obj)) 
                {
                    const char *sample_url = url_obj->valuestring;
                    printf("Sample URL for Post %d: %s\n", i + 1, sample_url);
                } 
                else 
                {
                    fprintf(stderr, "Error: 'url' field not found or not a string for post %d.\n", i + 1);
                }
            } 
            else 
            {
                fprintf(stderr, "Error: 'sample' field not found for post %d.\n", i + 1);
            }
        }
    } 
    else 
    {
        fprintf(stderr, "'posts' field is not an array.\n");
    }

    // Clean up cJSON objects
    cJSON_Delete(root);
}
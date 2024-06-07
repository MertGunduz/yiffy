/**
 * @file search.c
 * 
 * @brief This file is used to interact with the terminal user interface version of yiffy, providing download, list, search, travel, and selected post tags features.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 31/10/2023
*/

#include <ncurses.h>

#include "yiffy_search.h"

#define CONTENT_SIZE 524288 ///< This macro is used to set the default size for reading the JSON file that comes as a response from the API.

control controls[] = 
{
    {"SHOW", 'S'},
    {"DOWNLOAD", 'D'},
    {"PREV", 'P'},
    {"NEXT", 'N'},
    {"QUIT", 'Q'}
};

WINDOW *top_window;
WINDOW *posts_window;
WINDOW *post_tags_window;
WINDOW *controls_window;

/// @brief Height of the posts panel in the user interface.
static int posts_panel_height;

/// @brief The string for storing posts.json data.
static char json_string[CONTENT_SIZE];

/// @brief Creates a ncurses-based user interface to show, download, search and travel the e621/e926 by using curl api calls and aria2c tool.
/// @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --search "anthro+fur+male+smile".
void search(char *tags) 
{
    /* Initialize ncurses and configurations for the user interface. */
    init_ncurses();

    /* Create the ncurses-based user interfaces. */
    create_top_window(top_window);
    create_posts_window(&posts_window, &posts_panel_height);
    create_post_tags_window(&post_tags_window, &posts_panel_height);
    create_controls_window(controls_window, &posts_panel_height, controls, sizeof(controls) / sizeof(controls[0]));

    /* Download the first page of posts with prompted tags. */
    aria2_download(tags, 1, posts_panel_height);

    /* Read the posts.json file. */
    FILE *posts_json_file = fopen("posts.json", "r");

    if (posts_json_file == NULL)
    {
        no_json_error_msg();
        goto END;
    }

    fgets(json_string, CONTENT_SIZE - 1, posts_json_file);

    /* Close the file after reading and putting the data to json_string. */
    fclose(posts_json_file);

    /* Parse the JSON. */
    cJSON *json = cJSON_Parse(json_string);

    if (json == NULL)
    {
        json_parse_error_msg();
        goto END;
    }

    /* Get the posts array. */
    cJSON *posts = cJSON_GetObjectItem(json, "posts");

    if (!cJSON_IsArray(posts))
    {
        posts_not_array_error_msg();
        goto END;
    }

    /* Counter for writing posts. */
    size_t post_i = 0;

    /* Write the posts and tags to windows. */
    for (size_t i = 0; i < cJSON_GetArraySize(posts); i++)
    {
        /* Take the post with specified index. */
        cJSON *post = cJSON_GetArrayItem(posts, i);

        if (post == NULL)
        {
            post_error_msg();
            goto END;
        }

        /* Take the file object of the specified post. */
        cJSON *file_object = cJSON_GetObjectItem(post, "file");

        if (file_object == NULL)
        {
            fprintf(stderr, "File object not found in post %d\n", i);
            goto END;
        }

        /* Take the url of the of the specified post by parsing the data from file object. */
        cJSON *url = cJSON_GetObjectItem(file_object, "url");

    if (post_i == 0)
    {
        /* The tags object parsing. */
        cJSON *tags_object = cJSON_GetObjectItem(post, "tags");

        if (tags_object == NULL)
        {
            fprintf(stderr, "Tags object not found in post %d\n", i);
            goto END;
        }

        /* The general tags array parsing. */
        cJSON *general_tags = cJSON_GetObjectItem(tags_object, "general");
        
        wmove(post_tags_window, 1, 1);

        int line_counter = 0;
        int max_width = getmaxx(post_tags_window) - 2; // Get the window width, minus 2 for borders
        int max_height = 6; // Fixed height for the window
        int line_to_write = 1;

        if (cJSON_IsArray(general_tags))
        {   
            for (size_t j = 0; j < cJSON_GetArraySize(general_tags); j++)
            {
                cJSON *tag = cJSON_GetArrayItem(general_tags, j);

                for (size_t k = 0; k < strlen(tag->valuestring); k++)
                {
                    if (line_counter >= max_width)
                    {
                        line_to_write++;
                        if (line_to_write >= max_height) // Check for vertical overflow
                        {
                            break;
                        }
                        wmove(post_tags_window, line_to_write, 1);
                        line_counter = 0;
                    }

                    wprintw(post_tags_window, "%c", tag->valuestring[k]);
                    wrefresh(post_tags_window);  
                    line_counter++;
                }

                if (line_counter + 2 >= max_width) // Check if ", " will overflow
                {
                    line_to_write++;
                    if (line_to_write >= max_height) // Check for vertical overflow
                    {
                        break;
                    }
                    wmove(post_tags_window, line_to_write, 1);
                    line_counter = 0;
                }
                else
                {
                    wprintw(post_tags_window, ", ");
                    line_counter += 2;
                }

                if (line_to_write >= max_height) // Check for vertical overflow
                {
                    break;
                }
            }
        }
    }


        if (url != NULL && cJSON_IsString(url) && post_i != posts_panel_height - 2)
        {
            write_post(posts_window, post_i, url);
            wrefresh(posts_window);

            /* Increase post_i. */
            post_i++;
        }
    }

    wrefresh(posts_window);
    refresh();

    END:
    cJSON_Delete(json);
    getch();
    endwin();
}
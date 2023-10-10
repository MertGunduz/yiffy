/**
 * @file search.c
 * 
 * @brief This file is used to search over e621-e926 by using a terminal with the specified tags by user and outputs or outputs-downloads URLs.
 * 
 * This file is used to send a request to the search over the e621-e926 by using the API. It uses ncurses to provide the web-like experience.
 * 
 * @author Mehmet Mert Gunduz 
 *
 * @date 21/07/2023
*/

#include "yiffy_search.h"

#define SINGLE_COMMAND_UI_CHARS 105 ///< The total characters for one line UI.
#define DOUBLE_COMMAND_UI_CHARS 50  ///< The total characters for two lines UI.

#define MAX_FILE_PATH 256   ///< This macro is used to set the default size for getting the home directory file.
#define MAX_BUFFER_SIZE 512 ///< This macro is used to set the default size for reading the config file
#define CONTENT_SIZE 262144 ///< This macro is used to set the default size for reading the JSON file that comes as a response from the API.

/* The control handling struct. */
typedef struct
{
    char control_char;
    char *control_description;
} control;

/* All yiffy search control commands. */
control ui_controls[] = 
{
    {'B', "Back"},
    {'N', "Next"},
    {'U', "Up  "},
    {'D', "Down"},
    {'S', "Show"},
    {'I', "Info"},
    {'G', "Get "},
    {'Q', "Quit"},
};

static void create_yiffy_ui(int terminal_height, int terminal_width, control *controls, char *posts[]);
static void create_one_line_ui(int terminal_height, int terminal_width, control *controls);
static void create_double_line_ui(int terminal_height, int terminal_width, control *controls);
static void print_list(const char *filename, int page, int is_double);
static void numerator(int counter);
static void print_urls(cJSON *url);
static void space(int num);

/**
 * @brief Sends a request to search over the e621-e926 by using the API. It uses ncurses to provide the web-like experience. 
 * 
 * @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
*/
void search(char *tags)
{
    setlocale(LC_ALL, "");   ///< Set the locale to all.
    initscr();               ///< Initialize the library and setup the terminal.
    cbreak();                ///< Disable line buffering, get input instantly.
    noecho();                ///< Close the echo ability of user input to the screen.
    keypad(stdscr, TRUE);    ///< Enable special keys like CTRL, SHIFT.
    start_color();           ///< Enable the color ability.
    use_default_colors();    ///< Enable default colors
    curs_set(0);             ///< Close the cursor.

    /* Set the color pair for control commands. */
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    int height, width;      ///< Terminal size variables.
    bool is_nsfw = false;   ///< e621/e926 checker variable.
    int p = 0;              ///< The page system for search function.

    /* Get the screen size. */
    height = getmaxy(stdscr);
    width = getmaxx(stdscr);

    /* Pre-request configuration checks. */
    char config_path[MAX_FILE_PATH];
    char buffer[MAX_BUFFER_SIZE];

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

    /* Request posts from API. */
    aria2_download(tags, p, is_nsfw, height + 15);

    /* Create the UI. */
    create_yiffy_ui(height, width, ui_controls, NULL);

    getch();
    clear();
    endwin();
}

static void create_yiffy_ui(int terminal_height, int terminal_width, control *controls, char *posts[])
{
    /* Two line control commands ui. */
    if (terminal_width > SINGLE_COMMAND_UI_CHARS)
    {
        create_one_line_ui(terminal_height, terminal_width, controls);
        print_list("posts.json", 0, false);
    }
    else
    {
        create_double_line_ui(terminal_height, terminal_width, controls);
        print_list("posts.json", 0, true);
    }
}

static void create_one_line_ui(int terminal_height, int terminal_width, control *controls)
{
    /* This variable is used for setting the size of command controls to maximize the width of terminal. */
    int single_total_distance = terminal_width - SINGLE_COMMAND_UI_CHARS;
    single_total_distance = single_total_distance / 8;

    /* Go to the bottom of terminal to create the controls part. */
    move(terminal_height - 2, 0);
        
    /* Start writing the 8 commands to the bottom of terminal in a single line. */
    for (int i = 0; i < 8; i++)
    {
        /* Write the command characters with bold font and white background. */
        attron(COLOR_PAIR(1));
        printw("[%c]", controls[i].control_char);
        attroff(COLOR_PAIR(1));

        /* Write the command descriptions. */
        printw(" %s", controls[i].control_description);

        /* By default it gives 6 spaces to each command control element. Also, it includes more spaces to make the terminal responsive. */
        space(6 + single_total_distance);
    }

    /* Draw the command control panel borders. */
    mvhline(terminal_height - 3, 0, 0, terminal_width);
    mvhline(terminal_height - 1, 0, 0, terminal_width);
}

static void create_double_line_ui(int terminal_height, int terminal_width, control *controls)
{
    /* This variable is used for setting the size of command controls to maximize the width of terminal. */
    int double_total_distance = terminal_width - DOUBLE_COMMAND_UI_CHARS;
    double_total_distance = double_total_distance / 4;

    /* Go to the bottom of terminal to create the controls part. */
    move(terminal_height - 3, 0);
        
    for (int i = 0; i < 4; i++)
    {
        /* Write the command characters with bold font and white background. */
        attron(COLOR_PAIR(1));
        printw("[%c]", controls[i].control_char);
        attroff(COLOR_PAIR(1));

        /* Write the command descriptions. */
        printw(" %s", controls[i].control_description);

        /* By default it gives 6 spaces to each command control element. Also, it includes more spaces to make the terminal responsive. */
        space(6 + double_total_distance);
    }

    /* Go to the second bottom line of terminal to create the controls part line 2. */
    move(terminal_height - 2, 0);
        
    for (int i = 4; i < 8; i++)
    {
        /* Write the command characters with bold font and white background. */
        attron(COLOR_PAIR(1));
        printw("[%c]", controls[i].control_char);
        attroff(COLOR_PAIR(1));

        /* Write the command descriptions. */
        printw(" %s", controls[i].control_description);

        /* By default it gives 6 spaces to each command control element. Also, it includes more spaces to make the terminal responsive. */
        space(6 + double_total_distance);
    }

    /* Draw the command control panel borders. */
    mvhline(terminal_height - 4, 0, 0, terminal_width);
    mvhline(terminal_height - 1, 0, 0, terminal_width);
}

static void print_list(const char *filename, int page, int is_double)
{
    FILE *fp;
    char *json_string;
    long length;
    int ct = 1;

    move(0, 0);

    // Open the file
    fp = fopen(filename, "rb");
    if (fp == NULL) 
    {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Get the length of the file
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Read the file content into a string
    json_string = (char *)malloc((length+1) * sizeof(char));
    if (json_string == NULL) 
    {
        fprintf(stderr, "Could not allocate memory for JSON string\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fread(json_string, sizeof(char), length, fp);
    fclose(fp);
    json_string[length] = '\0';

    // Parse the JSON string
    cJSON *json = cJSON_Parse(json_string);

    if (json == NULL) 
    {
        fprintf(stderr, "Could not parse JSON\n");
        free(json_string);
        exit(EXIT_FAILURE);
    }

    // Fetch the data
    cJSON *posts = cJSON_GetObjectItemCaseSensitive(json, "posts");
    cJSON *post;
    cJSON_ArrayForEach(post, posts) 
    {
        cJSON *file = cJSON_GetObjectItemCaseSensitive(post, "file");
        cJSON *url = cJSON_GetObjectItemCaseSensitive(file, "url");
        
        if (url->valuestring != NULL)
        {
            /* Write the numbers. */
            numerator(ct);

            /* Write the URLs.*/
            print_urls(url);
            
            /* Increase the counter. */
            ct++;

            /* In double line UI structure, it needs minus 3. In one line structure, it needs minus 2. */
            if (ct == getmaxy(stdscr) - 2 - is_double)
            {
                getch();
            }
        }
    }

    // Clean up
    cJSON_Delete(json);
    free(json_string);
}

static void numerator(int counter)
{
    if (counter < 10)
    {
    printw("[0%d] - ", counter); 
    }
    else
    {
        printw("[%d] - ", counter); 
    }
}

static void print_urls(cJSON *url)
{
    for (int i = 8; i < 72; i++)
    {
        addch(url->valuestring[i]);
    }
    
    printw("\n");
}

static void space(int num)
{
    if (num != 0)
    {
        printw(" ");
        space(num - 1);
    }
}
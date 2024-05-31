/**
 * @file yiffy.c
 * 
 * @brief This is the main file and used to handle the arguments and execute the program by using external functions.
 * 
 * Main function is used to call the functions by using function pointers and pass arguments.
 * Argument_verify function is used to check the validity of the arguments like argv, argc.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 21/07/2023
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "../msg/yiffy_messages.h"
#include "../search/yiffy_search.h"
#include "../fetch/yiffy_fetch.h"
#include "../menus/yiffy_text_menus.h"
#include "../conf/yiffy_conf.h"

#define RECOGNIZED_ARGUMENT   true  ///< 
#define UNRECOGNIZED_ARGUMENT false ///< 
#define MISSING_ON_OFF        false ///< 
#define ARGC_QTY_ERROR        false ///< 
#define NO_ARG_VALUE          false ///< 
#define EXTRA_ARG_VALUE       false ///<

static bool argument_verify(int argument_count, char *arguments[]);
static bool is_api_accessible();
static void export_local_data();
static void import_local_data();
static void search_urls(char *tags);
static void fetch_urls(char *tags, char *command);

/**
 * @brief The general struct for handling the general arguments.
*/
struct general_option
{
    char *option;
    void (*function)(char *argv);
};

/**
 * @brief The general struct for handling the fetch arguments.
*/
struct fetch_option
{
    char *option;
    void (*function)(char *argv, char *command);
};

static struct general_option general_options[] =
{
    {"--help", show_help},
    {"--version", show_version},
    {"--github", show_github},
    {"--website", show_website},
    {"--config", show_config},
    {"--export", export_local_data},
    {"--import", import_local_data},
    {"--ivcommand", conf_img_viewer_command},
    {"--nsfw", conf_nsfw},
    {"--search", search_urls}
};

static struct fetch_option fetch_options[] =
{
    {"--fetch", fetch_urls},
    {"--dfetch", fetch_urls}
};

int main(int argc, char *argv[])
{
    if (argument_verify(argc, argv))
    {
        for (size_t i = 0; i < sizeof(fetch_options) / sizeof(fetch_options[0]); i++)
        {
            if (strcmp(argv[1], fetch_options[i].option) == 0)
            {
                void (*fetch_function)(char *argv, char *command) = fetch_options[i].function;
                fetch_function(argv[2], fetch_options[i].option);

                break;
            }
        }

        for (size_t i = 0; i < sizeof(general_options) / sizeof(general_options[0]); i++) 
        {
            if (strcmp(argv[1], general_options[i].option) == 0) 
            {
                void (*menu_func)(char *argv) = general_options[i].function;

                if (strcmp(general_options[i].option, "--search") == 0 || strcmp(general_options[i].option, "--nsfw") == 0 || strcmp(general_options[i].option, "--plog") == 0) /* THIRD ARGUMENT: tags [yiffy --search "blush+fox+male"]*/
                {
                    menu_func(argv[2]);
                }
                else /* NO THIRD ARGUMENT */
                {
                    menu_func(NULL);
                }

                break;
            }
        }
    }

    return 0;
}

/**
 * @brief Checks the argument count and arguments, if they are in the wanted format returns true .
 * 
 * Checks the validity of command line arguments provided to a program.
 * Supports two types of arguments, single argument options and two-argument options.
 * 
 * 
 * @param argument_count The number of command line arguments.
 * @param arguments The all arguments passed by the user.
 *
 * @return Returns an integer code indicating the result of argument validation.
*/
static bool argument_verify(int argument_count, char *arguments[])
{
    char *one_arguments[] = {"--help", "--version", "--github", "--website", "--config", "--export", "--import"};
    char *two_arguments[] = {"--ivcommand", "--nsfw", "--dfetch", "--fetch", "--search"};


    if (argument_count == 3)
    {
        /**
        * @section Two Arguments Handling
        *
        * It checks if the passed argument exists in the two_arguments array.
        * If the passed option is --dfetch, --fetch, --search or --ivcommand it returns true.
        * Also, if the passed option is one of the twoArgument options and includes on/off as the second option returns true.
        * If not, returns false and shows the user that the second option can only be on/off.
        * 
        * two_arguments they don't take on/off: --dfetch, --fetch, --search, --ivcommand.
        * two_arguments they take on/off: --nsfw.
        */
        for (size_t i = 0; i < sizeof(two_arguments) / sizeof(two_arguments[0]); i++)
        {
            if (strcmp(arguments[1], two_arguments[i]) == 0)
            {
                if (strcmp(arguments[2], "on") == 0 || strcmp(arguments[2], "off") == 0 || strcmp(arguments[1], "--dfetch") == 0 || strcmp(arguments[1], "--fetch") == 0 || strcmp(arguments[1], "--search") == 0 || strcmp(arguments[1], "--ivcommand") == 0)
                {
                    return RECOGNIZED_ARGUMENT; /* Return true. */
                }
                else
                {
                    on_off_msg(arguments[2]);
                    return MISSING_ON_OFF; /* Return false. */
                }
            }
        }

        /**
         * @section Two Arguments Extra Argument Error Handling
         * 
         * When user entered 2 options and the first one exists in the oneArguments array, then it will generate an error message and return false.
        */
        for (size_t i = 0; i < sizeof(one_arguments) / sizeof(one_arguments[0]); i++)
        {
            if (strcmp(arguments[1], one_arguments[i]) == 0)
            {
                extra_arg_error_msg(arguments[1]);
                return EXTRA_ARG_VALUE; /* Return false. */
            }
        }

        unrecognized_arg_msg(arguments[1]);
        return UNRECOGNIZED_ARGUMENT; /* Return false. */
    }
    else if (argument_count == 2)
    {
        /**
         * @section One Argument Handling
         * 
         * When user entered 1 option and the first one exists in the oneArguments array, it will return true.
        */
        for (size_t i = 0; i < sizeof(one_arguments) / sizeof(one_arguments[0]); i++)
        {
            if (strcmp(arguments[1], one_arguments[i]) == 0)
            {
                return RECOGNIZED_ARGUMENT; /* Return true. */
            }
        }

        /**
         * @section One Argument Handling twoArgument Option Error Handling 
         * 
         * When user entered 1 option and the first one exists in the two_arguments array, it will return false and generate an error message.
        */
        for (size_t i = 0; i < sizeof(two_arguments) / sizeof(two_arguments[0]); i++)
        {
            if (strcmp(arguments[1], two_arguments[i]) == 0)
            {
                no_arg_value_msg(arguments[1]);
                return NO_ARG_VALUE; /* Return false. */
            }
        }
        
        unrecognized_arg_msg(arguments[1]);
        return UNRECOGNIZED_ARGUMENT; /* Return false. */
    }
    else
    {
        /**
         * @section Invalid Argument Count Handling 
         * 
         * When user entered no options or more than 2 arguments, it will return false and generate an error message.
        */
        argc_error_msg(argument_count);
        return ARGC_QTY_ERROR; /* Return false. */
    }
}


/**
 * @brief Sends ping to the e621/e926 to check if it accessible.
*/
static bool is_api_accessible()
{
    /* Send the ping. */
    int ping_result = system("ping -c 1 e621.net >/dev/null 2>&1");

    if (ping_result == 0)
    {
        return true;
    }
    else
    {
        access_error_msg();
        exit(EXIT_FAILURE);
    }
}

/// @brief exports the app data as a string
static void export_local_data() 
{
    fprintf(stdout, "EXPORT MENU\n");
}

/// @brief imports the string and creates app data
static void import_local_data() 
{
    fprintf(stdout, "IMPORT MENU\n");
}

/**
 * @brief Calls the search function to use yiffy e621-e926 terminal.
 * 
 * @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
*/
static void search_urls(char *tags)
{   if (is_api_accessible())
    {
        search(tags);        
    }
}

/**
 * @brief Calls the fetch function in a loop to output or output-download URLs until there is no content anymore.
 * 
 * @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
*/
static void fetch_urls(char *tags, char *command)
{ 
    if (is_api_accessible())
    {
        int i = 1;
        while (true)
        {
            fetch(tags, i, command);
            i++;
        }
    }
}

/**
 * @file yiffy.c
 * 
 * @brief This is the main file and used to handle the arguments and execute the program by using external functions.
 * 
 * Main function is used to call the functions by using function pointers and pass arguments.
 * ArgumentVerify function is used to check the validity of the arguments like argv, argc.
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include "../cjson/cjson.h"
#include "../yiffymessages/yiffy-messages.h"
#include "../yiffysearch/yiffy-search.h"
#include "../yiffytextmenus/yiffy_text_menus.h"

#define RECOGNIZED_ARGUMENT   true
#define UNRECOGNIZED_ARGUMENT false
#define MISSING_ON_OFF        false
#define ARGC_QTY_ERROR        false
#define NO_ARG_VALUE          false
#define EXTRA_ARG_VALUE       false

static bool argumentVerify(int argumentCount, char *arguments[]);

static void exportLocalData();
static void importLocalData();
static void changeWebGenerationMode(char *onOff);
static void changeAdultMode(char *onOff);
static void searchURLS(char *tags);
static void fetchURLS(char *tags, char *command);

/**
 * @brief The general struct for handling the general arguments.
*/
struct generalOption
{
    char *option;
    void (*function)(char *argv);
};

/**
 * @brief The general struct for handling the fetch arguments.
*/
struct fetchOption
{
    char *option;
    void (*function)(char *argv, char *command);
};

static struct generalOption generalOptions[] =
{
    {"--help", showHelp},
    {"--version", showVersion},
    {"--github", showGithub},
    {"--website", showWebsite},
    {"--config", showConfig},
    {"--export", exportLocalData},
    {"--import", importLocalData},
    {"--wgen", changeWebGenerationMode},
    {"--nsfw", changeAdultMode},
    {"--search", searchURLS}
};

static struct fetchOption fetchOptions[] =
{
    {"--fetch", fetchURLS},
    {"--dfetch", fetchURLS}
};

int main(int argc, char *argv[])
{
    if (argumentVerify(argc, argv))
    {
        for (long unsigned int i = 0; i < sizeof(fetchOptions) / sizeof(fetchOptions[0]); i++)
        {
            if (strcmp(argv[1], fetchOptions[i].option) == 0)
            {
                void (*fetchFunction)(char *argv, char *command) = fetchOptions[i].function;

                if (strcmp(argv[1], fetchOptions[i].option) == 0)
                {
                    fetchFunction(argv[2], fetchOptions[i].option);
                }

                break;
            }
        }

        for (long unsigned int i = 0; i < sizeof(generalOptions) / sizeof(generalOptions[0]); i++) 
        {
            if (strcmp(argv[1], generalOptions[i].option) == 0) 
            {
                void (*menuFunc)(char *argv) = generalOptions[i].function;

                if (strcmp(generalOptions[i].option, "--search") == 0 || strcmp(generalOptions[i].option, "--nsfw") == 0 || strcmp(generalOptions[i].option, "--wgen") == 0) /* THIRD ARGUMENT: tags [yiffy --search "blush+fox+male"]*/
                {
                    menuFunc(argv[2]);
                }
                else /* NO THIRD ARGUMENT */
                {
                    menuFunc(NULL);
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
 * @param argumentCount The number of command line arguments.
 * @param arguments The all arguments passed by the user.
 *
 * @return Returns an integer code indicating the result of argument validation.
*/
static bool argumentVerify(int argumentCount, char *arguments[])
{
    char *oneArguments[] = {"--help", "--version", "--github", "--website", "--config", "--export", "--import"};
    char *twoArguments[] = {"--wgen", "--nsfw", "--dfetch", "--fetch", "--search"};


    if (argumentCount == 3)
    {
        /**
        * @section Two Arguments Handling
        *
        * It checks if the passed argument exists in the htwoArguments array.
        * If the passed option is --dfetch, --fetch or --search it returns true.
        * Also, if the passed option is one of the twoArgument options and includes on/off as the second option returns true.
        * If not, returns false and shows the user that the second option can only be on/off.
        * 
        * twoArguments they don't take on off: --dfetch, --fetch, --search.
        * twoArguments they take on/off: --wgen, --nsfw.
        */
        for (long unsigned int i = 0; i < sizeof(twoArguments) / sizeof(twoArguments[0]); i++)
        {
            if (strcmp(arguments[1], twoArguments[i]) == 0)
            {
                if (strcmp(arguments[2], "on") == 0 || strcmp(arguments[2], "off") == 0 || strcmp(arguments[1], "--dfetch") == 0 || strcmp(arguments[1], "--fetch") == 0 || strcmp(arguments[1], "--search") == 0)
                {
                    return RECOGNIZED_ARGUMENT; /* Return true. */
                }
                else
                {
                    onOffMessage(arguments[2]);
                    return MISSING_ON_OFF; /* Return false. */
                }
            }
        }

        /**
         * @section Two Arguments Extra Argument Error Handling
         * 
         * When user entered 2 options and the first one exists in the oneArguments array, then it will generate an error message and return false.
        */
        for (long unsigned int i = 0; i < sizeof(oneArguments) / sizeof(oneArguments[0]); i++)
        {
            if (strcmp(arguments[1], oneArguments[i]) == 0)
            {
                extraArgumentErrorMessage(arguments[1]);
                return EXTRA_ARG_VALUE; /* Return false. */
            }
        }

        unrecognizedArgumentMessage(arguments[1]);
        return UNRECOGNIZED_ARGUMENT; /* Return false. */
    }
    else if (argumentCount == 2)
    {
        /**
         * @section One Argument Handling
         * 
         * When user entered 1 option and the first one exists in the oneArguments array, it will return true.
        */
        for (long unsigned int i = 0; i < sizeof(oneArguments) / sizeof(oneArguments[0]); i++)
        {
            if (strcmp(arguments[1], oneArguments[i]) == 0)
            {
                return RECOGNIZED_ARGUMENT; /* Return true. */
            }
        }

        /**
         * @section One Argument Handling twoArgument Option Error Handling 
         * 
         * When user entered 1 option and the first one exists in the twoArguments array, it will return false and generate an error message.
        */
        for (long unsigned int i = 0; i < sizeof(twoArguments) / sizeof(twoArguments[0]); i++)
        {
            if (strcmp(arguments[1], twoArguments[i]) == 0)
            {
                noArgumentValueMessage(arguments[1]);
                return NO_ARG_VALUE; /* Return false. */
            }
        }
        
        unrecognizedArgumentMessage(arguments[1]);
        return UNRECOGNIZED_ARGUMENT; /* Return false. */
    }
    else
    {
        /**
         * @section Invalid Argument Count Handling 
         * 
         * When user entered no options or more than 2 arguments, it will return false and generate an error message.
        */
        argcErrorMessage(argumentCount);
        return ARGC_QTY_ERROR; /* Return false. */
    }
}

/// @brief exports the app data as a string
static void exportLocalData() 
{
    fprintf(stdout, "EXPORT MENU\n");
}

/// @brief imports the string and creates app data
static void importLocalData() 
{
    fprintf(stdout, "IMPORT MENU\n");
}

/// @brief opens/closes web generation system
static void changeWebGenerationMode(char *onOff)
{
    fprintf(stdout, "WEB GEN MENU %s\n", onOff);
}

/// @brief opens/closes nsfw option
static void changeAdultMode(char *onOff)
{
    fprintf(stdout, "NSFW MENU%s\n", onOff);
}

/**
 * @brief Calls the search function to use yiffy e621-e926 terminal.
 * @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
*/
static void searchURLS(char *tags)
{
    fprintf(stdout, "SEARCH MENU %s\n", tags);
}

/**
 * @brief Calls the fetch function in a loop to output or output-download URLs until there is no content anymore.
 * @param tags These are the e621-e926 tags prompted by the user as an argument value. Example: yiffy --fetch "anthro+fur+male+smile".
*/
static void fetchURLS(char *tags, char *command)
{ 
    int i = 1;
    while (true)
    {
        fetch(tags, i, command);
        i++;
    }
}

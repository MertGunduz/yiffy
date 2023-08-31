/**
 * @file yiffy.c
 * 
 * @brief the main application file of yiffy
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
#include "../yiffytextmenus/yiffy-text-menus.h"

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
static void searchURLS(char *tagstring);
static void fetchURLS(char *tagString, char *command);

/// @brief The general struct for handling the general arguments.
struct generalOption
{
    char *option;
    void (*function)(char *argv);
};

/// @brief The general struct for handling the fetch arguments.
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

/// @brief checks the argument count and arguments, if they are in the wanted format returns true 
/// @param argumentCount 
/// @param arguments 
/// @return true or false (bool)
static bool argumentVerify(int argumentCount, char *arguments[])
{
    char *oneArguments[] = {"--help", "--version", "--github", "--website", "--config", "--export", "--import"};
    char *twoArguments[] = {"--wgen", "--nsfw", "--dfetch", "--fetch", "--search"};

    if (argumentCount == 3)
    {
        for (long unsigned int i = 0; i < sizeof(twoArguments) / sizeof(twoArguments[0]); i++)
        {
            if (strcmp(arguments[1], twoArguments[i]) == 0)
            {
                if (strcmp(arguments[2], "on") == 0 || strcmp(arguments[2], "off") == 0 || strcmp(arguments[1], "--dfetch") == 0 || strcmp(arguments[1], "--fetch") == 0 || strcmp(arguments[1], "--search") == 0)
                {
                    return RECOGNIZED_ARGUMENT; /* return true; */
                }
                else
                {
                    onOffMessage(arguments[2]);
                    return MISSING_ON_OFF; /* return false; */
                }
            }
        }

        for (long unsigned int i = 0; i < sizeof(oneArguments) / sizeof(oneArguments[0]); i++)
        {
            if (strcmp(arguments[1], oneArguments[i]) == 0)
            {
                extraArgumentErrorMessage(arguments[1]);
                return EXTRA_ARG_VALUE; /* return false; */
            }
        }

        unrecognizedArgumentMessage(arguments[1]);
        return UNRECOGNIZED_ARGUMENT; /* return false; */
    }
    else if (argumentCount == 2)
    {
        for (long unsigned int i = 0; i < sizeof(oneArguments) / sizeof(oneArguments[0]); i++)
        {
            if (strcmp(arguments[1], oneArguments[i]) == 0)
            {
                return RECOGNIZED_ARGUMENT; /* return true; */
            }
        }

        for (long unsigned int i = 0; i < sizeof(twoArguments) / sizeof(twoArguments[0]); i++)
        {
            if (strcmp(arguments[1], twoArguments[i]) == 0)
            {
                noArgumentValueMessage(arguments[1]);
                return NO_ARG_VALUE; /* return false; */
            }
        }
        
        unrecognizedArgumentMessage(arguments[1]);
        return UNRECOGNIZED_ARGUMENT; /* return false; */
    }
    else
    {
        argcErrorMessage(argumentCount);
        return ARGC_QTY_ERROR; /* return false; */
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

/// @brief sends request and gets data from e621/926
/// @param tagstring 
static void searchURLS(char *tagstring)
{
    fprintf(stdout, "SEARCH MENU %s\n", tagstring);
}

/// @brief sends request and fetchs urls from e621/926
/// @param tagString 
static void fetchURLS(char *tagString, char *command)
{ 
    int i = 1;
    while (true)
    {
        fetch(tagString, i, command);
        i++;
    }
}

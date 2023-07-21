#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../yiffymessages/yiffy-messages.h"

#define RECOGNIZED_ARGUMENT   true
#define UNRECOGNIZED_ARGUMENT false
#define MISSING_ON_OFF        false
#define ARGC_QTY_ERROR        false
#define NO_ARG_VALUE          false
#define EXTRA_ARG_VALUE       false

static bool argumentVerify(int argumentCount, char *arguments[]);
static void showHelpMenu();
static void showVersionMenu();
static void showGithubMenu();
static void showWebsiteMenu();
static void showConfigMenu();
static void showExportMenu();
static void showImportMenu();
static void showWebGenMenu();
static void showProxyMenu();
static void showAnonymousDownloadMenu();
static void showNSFWMenu();

struct menuOption
{
    const char *option;
    void (*function)();
};

static struct menuOption menuOptions[] =
{
    {"--help", showHelpMenu},
    {"--version", showVersionMenu},
    {"--github", showGithubMenu},
    {"--website", showWebsiteMenu},
    {"--config", showConfigMenu},
    {"--export", showExportMenu},
    {"--import", showImportMenu},
    {"--website-generation", showWebGenMenu},
    {"--proxy", showProxyMenu},
    {"--anonymous-download", showAnonymousDownloadMenu},
    {"--nsfw", showNSFWMenu},
};

int main(int argc, char *argv[])
{
    if (argumentVerify(argc, argv))
    {
        for (long unsigned int i = 0; i < sizeof(menuOptions) / sizeof(menuOptions[0]); i++) {
            if (strcmp(argv[1], menuOptions[i].option) == 0) {
                void (*menuFunc)() = menuOptions[i].function;
                menuFunc();
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
    char *twoArguments[] = {"--website-generation", "--proxy", "--anonymous-download", "--nsfw"};

    if (argumentCount == 3)
    {
        for (long unsigned int i = 0; i < sizeof(twoArguments) / sizeof(twoArguments[0]); i++)
        {
            if (strcmp(arguments[1], twoArguments[i]) == 0)
            {
                if (strcmp(arguments[2], "on") == 0 || strcmp(arguments[2], "off") == 0)
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

static void showHelpMenu() {
    fprintf(stdout, "HELP MENU\n");
}

static void showVersionMenu() {
    fprintf(stdout, "VERSION MENU\n");
}

static void showGithubMenu() {
    fprintf(stdout, "GITHUB MENU\n");
}

static void showWebsiteMenu() {
    fprintf(stdout, "WEBSITE MENU\n");
}

static void showConfigMenu() {
    fprintf(stdout, "CONFIG MENU\n");
}

static void showExportMenu() {
    fprintf(stdout, "EXPORT MENU\n");
}

static void showImportMenu() {
    fprintf(stdout, "IMPORT MENU\n");
}

static void showWebGenMenu() {
    fprintf(stdout, "WEB GEN MENU\n");
}

static void showProxyMenu() {
    fprintf(stdout, "PROXY MENU\n");
}

static void showAnonymousDownloadMenu() {
    fprintf(stdout, "ANONYMOUS DOWNLOAD MENU\n");
}

static void showNSFWMenu() {
    fprintf(stdout, "NSFW MENU\n");
}
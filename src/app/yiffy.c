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

int main(int argc, char *argv[])
{
    if (argumentVerify(argc, argv))
    {
        if (strcmp(argv[1], "--help") == 0)
        {
            fprintf(stdout, "HELP MENU\n");
        }
        else if (strcmp(argv[1], "--version") == 0)
        {
            fprintf(stdout, "VERSION MENU\n");
        }
        else if (strcmp(argv[1], "--github") == 0)
        {
            fprintf(stdout, "GITHUB MENU\n");
        }    
        else if (strcmp(argv[1], "--website") == 0)
        {
            fprintf(stdout, "WEBSITE MENU\n");
        }
        else if (strcmp(argv[1], "--config") == 0)
        {
            fprintf(stdout, "CONFIG MENU\n");
        }
        else if (strcmp(argv[1], "--export") == 0)
        {
            fprintf(stdout, "EXPORT MENU\n");
        }
        else if (strcmp(argv[1], "--import") == 0)
        {
            fprintf(stdout, "IMPORT MENU\n");
        }
        else if (strcmp(argv[1], "--website-generation") == 0)
        {
            fprintf(stdout, "WEB GEN MENU\n");
        }
        else if (strcmp(argv[1], "--proxy") == 0)
        {
            fprintf(stdout, "PROXY MENU\n");
        }
        else if (strcmp(argv[1], "--anonymous-download") == 0)
        {
            fprintf(stdout, "ANONYMOUS DOWNLOAD MENU\n");
        }
        else if (strcmp(argv[1], "--nsfw") == 0)
        {
            fprintf(stdout, "NSFW MENU\n");
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
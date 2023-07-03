#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define FOUND          true
#define NOT_FOUND      false
#define NO_ON_OFF      false
#define ARGC_QTY_ERROR false

static bool argumentVerify(int argumentCount, char *arguments[]);

int main(int argc, char *argv[])
{
    if (argumentVerify(argc, argv))
    {
        fprintf(stdout, "|X|\n");
    }
}

/// @brief checks the argument count and arguments, if they are in the wanted format returns true 
/// @param argumentCount 
/// @param arguments 
/// @return true or false (bool)
static bool argumentVerify(int argumentCount, char *arguments[])
{
    char *oneArguments[] = {"--help", "--version", "--github", "--website", "--config"};
    char *twoArguments[] = {"--website-generation", "--proxy", "--anonymous-download"};

    if (argumentCount == 3)
    {
        for (long unsigned int i = 0; i < sizeof(twoArguments) / sizeof(twoArguments[0]); i++)
        {
            if (strcmp(arguments[1], twoArguments[i]) == 0)
            {
                if (strcmp(arguments[2], "on") == 0 || strcmp(arguments[2], "off") == 0)
                {
                    return FOUND; /* return true; */
                }
                else
                {
                    // on-off message
                    return NO_ON_OFF; /* return false; */
                }
            }
        }

        return NOT_FOUND; /* return false; */
    }
    else if (argumentCount == 2)
    {
        for (long unsigned int i = 0; i < sizeof(oneArguments) / sizeof(oneArguments[0]); i++)
        {
            if (strcmp(arguments[1], oneArguments[i]) == 0)
            {
                return FOUND; /* return true; */
            }
        }

        return NOT_FOUND; /* return false; */
    }
    else
    {
        return ARGC_QTY_ERROR; /* return false; */
    }
}
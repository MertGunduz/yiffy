#include <string.h>

#include "yiffy-messages.h"

void noArgumentValueMessage(char *argument)
{
    if (strcmp(argument, "--website-generation") == 0 || strcmp(argument, "--proxy") == 0 || strcmp(argument, "--nsfw") == 0)
    {
        fprintf(stderr, "yiffy: please enter the argument value for \"%s\".\n", argument);
        fprintf(stderr, "yiffy: valid values for \"%s\" are on/off.\n", argument);
    }
    else if (strcmp(argument, "--tags") == 0)
    {
        fprintf(stderr, "yiffy: please enter the search tags.\n");
        fprintf(stderr, "yiffy: prompt \"man yiffy\" to read the user manual.\n");
    }
}
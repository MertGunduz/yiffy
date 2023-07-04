#include <string.h>

#include "yiffy-messages.h"

void noArgumentValueMessage(char *argument)
{
    if (strcmp(argument, "--website-generation") == 0 || strcmp(argument, "--proxy") == 0 || strcmp(argument, "--anonymous-download") == 0)
    {
        fprintf(stdout, "yiffy: error: please enter the argument value for \"%s\".\n", argument);
        fprintf(stdout, "yiffy: valid values for \"%s\" are on/off.\n");
    }
}
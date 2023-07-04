#include "yiffy-messages.h"

void extraArgumentErrorMessage(char *argument)
{
    fprintf(stderr, "yiffy: please delete the argument value.\n");
    fprintf(stderr, "yiffy: the correct format is \"yiffy %s\".\n", argument);
}
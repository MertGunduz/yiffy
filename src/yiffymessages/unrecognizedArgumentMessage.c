#include "yiffy-messages.h"

void unrecognizedArgumentMessage(char *argument)
{
    fprintf(stderr, "yiffy: unrecognized command line argument: \"%s\".\n", argument);
}
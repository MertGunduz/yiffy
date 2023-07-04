#include "yiffy-messages.h"

void onOffMessage(char *argument)
{
    fprintf(stderr, "yiffy: you have entered \"%s\" prompt as second argument.\n", argument);
    fprintf(stderr, "yiffy: please use \"on/off\" as second argument.\n");
}
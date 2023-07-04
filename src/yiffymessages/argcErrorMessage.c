#include "yiffy-messages.h"

void argcErrorMessage(int argc)
{
    if (argc == 1)
    {
        fprintf(stderr, "yiffy: please enter more command line arguments.\n");
        fprintf(stderr, "yiffy: prompt \"man yiffy\" to read the user manual.\n");
    }
    else
    {
        fprintf(stderr, "yiffy: please enter less command line arguments.\n");
        fprintf(stderr, "yiffy: prompt \"man yiffy\" to read the user manual.\n");
    }
}
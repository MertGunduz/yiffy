#ifndef YIFFY_MESSAGES_H
#define YIFFY_MESSAGES_H

#include <stdio.h>

void onOffMessage(char *argument);
void unrecognizedArgumentMessage(char *argument);
void noArgumentValueMessage(char *argument);
void argcErrorMessage(int argc);

#endif /* YIFFY_MESSAGES_H */
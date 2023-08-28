/**
 * @file yiffy-messages.h
 * 
 * @brief the message output header for yiffy 
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#ifndef YIFFY_MESSAGES_H
#define YIFFY_MESSAGES_H

#include <stdio.h>
#include <string.h>

void onOffMessage(char *argument);
void unrecognizedArgumentMessage(char *argument);
void noArgumentValueMessage(char *argument);
void argcErrorMessage(int argc);
void extraArgumentErrorMessage(char *argument);
void homeNotFoundErrorMessage();
void fileOpenErrorMessage(FILE *file);
void noJsonResponseErrorMessage(FILE *jsonFile);
void jsonParseErrorMessage();
void noResultsFoundErrorMessage();
void cjsonPtrErrorMessage(const char *ptrError);
void mallocErrorMessage();
void badSystemFuncErrorMessage();

#endif /* YIFFY_MESSAGES_H */
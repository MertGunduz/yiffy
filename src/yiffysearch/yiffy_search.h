/**
 * @file yiffy_search.h
 * 
 * @brief This header file is used to handle the fetching and searching system.
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 01/08/2023
*/

#ifndef YIFFY_SEARCH_H
#define YIFFY_SEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#include "../yiffymessages/yiffy_messages.h"
#include "../cjson/cjson.h"

#define BAD_SYSTEM_FUNC_CALL -1

void fetch(char *tags, int page, char *command);
void aria2_download(char *tags, int page, bool isNsfw);

#endif /* YIFFY_SEARCH_H */
/**
 * @file yiffy-search.h
 * 
 * @brief the general search and use header for yiffy
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

#include "../yiffymessages/yiffy-messages.h"
#include "../cjson/cjson.h"

void fetch(char *tagString, int page);
void aria2Download(char *tags, int page, bool isNsfw);

#endif /* YIFFY_SEARCH_H */
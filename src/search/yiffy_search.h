/**
 * @file yiffy_search.h
 * 
 * @brief This header file is used to handle the UI and UX of search.c as a helper header file.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 01/11/2023
*/

#ifndef YIFFY_UI_H
#define YIFFY_UI_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "../msg/yiffy_messages.h"

void search(char *tags);

#endif /* YIFFY_UI_H */
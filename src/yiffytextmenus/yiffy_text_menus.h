/**
 * @file yiffy-text-menus.h
 * 
 * @brief the text based menu header for yiffy (show menu related part [showHelpMenu] [showVersionMenu] [showGithubMenu] [showWebsiteMenu] [showConfigMenu]) 
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 01/08/2023
*/

#ifndef YIFFY_TEXT_MENUS_H
#define YIFFY_TEXT_MENUS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../yiffyui/yiffy-ui.h"
#include "../yiffymessages/yiffy-messages.h"

void showWebsite();
void showVersion();
void showGithub();
void showHelp();
void showConfig();

#endif /* YIFFY_TEXT_MENUS_H */
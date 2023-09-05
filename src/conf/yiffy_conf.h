/**
 * @file yiffy_conf.h
 * 
 * @brief This header file is used to do configuration for yiffy.
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 04/09/2023
*/

#ifndef YIFFY_CONF_H
#define YIFFY_CONF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../msg/yiffy_messages.h"

void conf_wgen(char *argv);
void conf_nsfw(char *argv);

#endif /* YIFFY_CONF_H */
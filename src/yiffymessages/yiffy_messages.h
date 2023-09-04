/**
 * @file yiffy_messages.h
 * 
 * @brief This file is used to handle error and information messages. 
 * 
 * @author Mehmet Mert Gunduz 
 * 
 * @date 21/07/2023
*/

#ifndef YIFFY_MESSAGES_H
#define YIFFY_MESSAGES_H

#include <stdio.h>
#include <string.h>

void on_off_msg(char *argument);
void unrecognized_arg_msg(char *argument);
void no_arg_value_msg(char *argument);
void argc_error_msg(int argc);
void extra_arg_error_msg(char *argument);
void no_home_error_msg();
void file_open_error_msg(FILE *file);
void no_json_error_msg(FILE *jsonFile);
void json_parse_error_msg();
void no_results_error_msg();
void cjson_error_msg(const char *ptrError);
void malloc_error_msg();
void system_func_error_msg();

#endif /* YIFFY_MESSAGES_H */
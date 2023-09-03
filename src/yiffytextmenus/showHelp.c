/**
 * @file showHelp.c
 * 
 * @brief This file is used to show general help to the user by showing how to use the cli options.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/08/2023
*/

#include "yiffy_text_menus.h"

/**
 * @brief Shows the general help menu to user.
*/
void showHelp()
{
    fprintf(stdout, "usage: yiffy [OPTION]\n");
    fprintf(stdout, "use e621 and e926 from the terminal interface\n\n");

    fprintfH(stdout, "yiffy search tui argument");
    fprintf(stdout, "--search \"[TAGS]\"   opens a tui interface\n\n");

    fprintfH(stdout, "yiffy api fetch arguments");
    fprintf(stdout, "--fetch \"[TAGS]\"    fetches urls\n");
    fprintf(stdout, "--dfetch \"[TAGS]\"   fetches urls and downloads\n\n");

    fprintfH(stdout, "yiffy information menu arguments");
    fprintf(stdout, "--help              outputs the help menu\n"); 
    fprintf(stdout, "--version           outputs the version menu\n");
    fprintf(stdout, "--github            outputs the github menu\n");
    fprintf(stdout, "--website           outputs the website menu\n");
    fprintf(stdout, "--config            outputs the configuration menu\n\n");

    fprintfH(stdout, "yiffy data import-export arguments");
    fprintf(stdout, "--import            imports the data to program\n");
    fprintf(stdout, "--export            exports the data from program\n\n");

    fprintfH(stdout, "yiffy configuration and settings arguments");
    fprintf(stdout, "--nsfw \"[ON/OFF]\"     switches to nsfw/sfw options\n");
    fprintf(stdout, "--wgen \"[ON/OFF]\"     switches to wgen/non-wgen option\n");
}
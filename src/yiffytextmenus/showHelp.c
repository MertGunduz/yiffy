/**
 * @file showHelp.c
 * 
 * @brief shows help menu
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 01/08/2023
*/

#include "yiffy-text-menus.h"

/// @brief shows help menu
void showHelp()
{
    fprintf(stdout, "usage: yiffy [OPTION]\n");
    fprintf(stdout, "use e621 and e926 from the terminal interface\n\n");

    fprintfH(stdout, "yiffy search and use argument");
    fprintf(stdout, "--search \"[TAGS]\"\n\n");

    fprintfH(stdout, "yiffy information menu arguments");
    fprintf(stdout, "--help             output the help menu\n"); 
    fprintf(stdout, "--version          output the version menu\n");
    fprintf(stdout, "--github           output the github menu\n");
    fprintf(stdout, "--website          output the website menu\n");
    fprintf(stdout, "--config           output the configuration menu\n\n");

    fprintfH(stdout, "yiffy local data import-export arguments");
    fprintf(stdout, "--import           imports the data to program\n");
    fprintf(stdout, "--export           exports the data from program\n\n");

    fprintfH(stdout, "yiffy configuration and settings arguments");
    fprintf(stdout, "--nsfw [ON/OFF]    switches to nsfw/sfw options\n");
    fprintf(stdout, "--proxy [ON/OFF]   switches to proxy/non-proxy option\n");
    fprintf(stdout, "--wgen [ON/OFF]    switches to wgen/non-wgen option\n");
}
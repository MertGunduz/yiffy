/**
 * @file show_help.c
 * 
 * @brief This file is used to show general help to the user by showing how to use the cli options.
 * 
 * @author Mehmet Mert Gunduz (merttgg@gmail.com)
 * 
 * @date 01/08/2023
*/

#include "yiffy_text_menus.h"

/**
 * @brief Shows the general help menu to user.
*/
void show_help()
{
    fprintf(stdout, "usage: yiffy [option]\n");
    fprintf(stdout, "use e621 and e926 from the terminal interface\n\n");

    fprintf(stdout, "yiffy search tui argument\n");
    fprintf(stdout, "-------------------------\n");
    fprintf(stdout, "--search [tags]    opens a tui interface\n\n");

    fprintf(stdout, "yiffy api fetch arguments\n");
    fprintf(stdout, "-------------------------\n");
    fprintf(stdout, "--fetch [tags]     fetches urls\n");
    fprintf(stdout, "--dfetch [tags]    fetches urls and downloads\n\n");

    fprintf(stdout, "yiffy information menu arguments\n");
    fprintf(stdout, "--------------------------------\n");
    fprintf(stdout, "--help             outputs the help menu\n"); 
    fprintf(stdout, "--version          outputs the version\n");
    fprintf(stdout, "--github           outputs the github url\n");
    fprintf(stdout, "--config           outputs the configs-credentials\n\n");
    
    fprintf(stdout, "yiffy config and credential arguments\n");
    fprintf(stdout, "-------------------------------------\n");
    fprintf(stdout, "--nsfw [on/off]    switches to nsfw/sfw options\n");
    fprintf(stdout, "--ivcommand [cmd]  sets the image viewer command\n");
    fprintf(stdout, "--uname [uname]    sets the username\n");
    fprintf(stdout, "--apikey [apikey]  sets the api key\n");

}
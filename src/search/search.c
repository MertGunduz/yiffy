/**
 * @file search.c
 * 
 * @brief This file is used to interact with the terminal user interface version of yiffy, it provides download-list-search-info features to the users.
 * 
 * @author Mehmet Mert Gunduz
 * 
 * @date 31/10/2023
*/

#include "yiffy_search.h"

static void create_header_section();
static void create_posts_section();
static void create_textinfo_section();
static void create_info_section();
static void create_controls_section();

void search(char *tags)
{
    /* Start the ncurses based terminal user interface. */
    initscr();
    noecho();
    start_color();

    /* Check if terminal supports colors. */
    if (!has_colors())
    {
        color_comp_error_msg();
        exit(EXIT_FAILURE);
    }

    /* Close the search app. */
    getch();
    endwin();
}

static void create_header_section()
{

}

static void create_posts_section()
{

}

static void create_textinfo_section()
{

}

static void create_info_section()
{

}

static void create_controls_section()
{

}
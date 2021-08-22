#include <stdio.h>
#include <string.h>

#include "menu.h"

void
Display_Menu(char *db, char *user)
{
    printf("====================================================\n");
    printf("___  ___                _        _ _            _   \n");
    printf("|  \\/  |               | |      | (_)          | |  \n");
    printf("| .  . |_   _ ___  __ _| |   ___| |_  ___ _ __ | |_ \n");
    printf("| |\\/| | | | / __|/ _` | |  / __| | |/ _ \\ '_ \\| __|\n");
    printf("| |  | | |_| \\__ \\ (_| | | | (__| | |  __/ | | | |_ \n");
    printf("\\_|  |_/\\__, |___/\\__, |_|  \\___|_|_|\\___|_| |_|\\__|\n");
    printf("         __/ |       | |                            \n");
    printf("        |___/        |_|                        v1.0\n");
    printf("====================================================\n");
    printf("    Database: %s        User: %s                    \n", db, user);
    printf("====================================================\n");
    printf("    Type 'help' for help                            \n");
}

void
Get_Command_Menu(char *db)
{
    char command[100];
    printf("(%s)> ", db);
    scanf("%s", command);
}
#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

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
Help_Menu()
{
    printf("\nA C homework for mysql client\n");
    printf("List of client comands:\n");
    printf("create      Create tables\n");
    printf("insert      Insert columns\n");
    printf("select      Select columns from a table\n");
    printf("update      Update columns in a table\n");
    printf("delate      Delate columns in a table\n");
    printf("help        Print this help\n");
    printf("quit        Quit client\n\n");
}

int
Get_Command_Menu(MYSQL *mysql)
{
    char command[100];
    
    printf("(%s)> ", mysql->db);
    scanf("%s", command);
    
    if (!strcmp(command, "create")) {

    }
    else if(!strcmp(command, "insert")) {

    }
    else if(!strcmp(command, "select")) {
        
    }
    else if(!strcmp(command, "update")) {
        
    }
    else if(!strcmp(command, "delate")) {
        
    }
    else if(!strcmp(command, "help")) {
        Help_Menu();
    }
    else if(!strcmp(command, "quit")) {
        printf("Bye!\n");
        return 1;
    }
    else printf("Unknown command: %s\n", command);
}
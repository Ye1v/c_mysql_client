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
Help_Menu()
{
    printf("\nA C homework for mysql client\n");
    printf("List of client comands:\n");
    printf("create                  Create tables\n");
    printf("delate                  Delate columns in a table\n");
    printf("drop                    Drop tables\n");
    printf("help                    Print this help\n");
    printf("insert                  Insert columns\n");
    printf("quit                    Quit the client\n");
    printf("select <table>          Select columns from a table\n");
    printf("show                    Show tables in the database\n");
    printf("update                  Update columns in a table\n");
    printf("use <database>          Use another database\n\n");
}

int
Get_Command_Menu(char *db)
{
    char command[100];
    
    printf("[%s]> ", db);
    scanf("%s", command);
    
    if (!strcmp(command, "create")) {
        return Create_Menu;
    }
    else if(!strcmp(command, "delate")) {
        return Delate_Menu;
    }
    else if(!strcmp(command, "drop")) {
        return Drop_Menu;
    }
    else if(!strcmp(command, "help")) {
        Help_Menu();
    }
    else if(!strcmp(command, "insert")) {
        return Insert_Menu;
    }
    else if(!strcmp(command, "quit")) {
        printf("Bye!\n");
        return Quit_Menu;
    }
    else if(!strcmp(command, "select")) {
        return Select_Menu;
    }
    else if(!strcmp(command, "show")) {
        return Show_Menu;
    }
    else if(!strcmp(command, "use")) {
        return Use_Menu;
    }
    else if(!strcmp(command, "update")) {
        return Update_Menu;
    }
    else printf("Unknown command: %s\n", command);
}
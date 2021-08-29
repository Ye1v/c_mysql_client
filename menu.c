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
    printf("create <table_name> <colume_num> <colume_name1> <colume_type1> ...\n");
    printf("\t\t\tCreate tables\n");
    printf("delate <table_name> <where_clause>\n");
    printf("\t\t\tDelate columns in a table\n");
    printf("drop <table_name>\n");
    printf("\t\t\tDrop tables\n");
    printf("help\n");
    printf("\t\t\tPrint this help\n");
    printf("insert <table_name> <colume_num> <colume_name1> ... <colume_value1> ...\n");
    printf("\t\t\tInsert columns\n");
    printf("quit\n");
    printf("\t\t\tQuit the client\n");
    printf("select <table_name>\n");
    printf("\t\t\tSelect columns from a table\n");
    printf("show\n");
    printf("\t\t\tShow tables in the database\n");
    printf("update <table_name> <value_num> <field1=new-value1> ... <where_clause>\n");
    printf("\t\t\tUpdate columns in a table\n");
    printf("use <database>\n");
    printf("\t\t\tUse another database\n\n");
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
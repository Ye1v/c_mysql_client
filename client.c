#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <mysql/mysql.h>

#include "menu.h"

/* function declarations */
static void Create();
static void Delate();
static void Get_Command();
static void Insert();
static void Login();
static void Select();
static void Update();

/* variables */
static MYSQL Now_Sql;

/* function implementations */
void
Create()
{

}

void
Delate()
{

}

void
Get_Command()
{
    while (1) {   
        int command;
        if (command = (Get_Command_Menu(Now_Sql.db)) == 1) break;  
        else switch (command) {
            case Create_Menu:
                Create();
                break;
            case Insert_Menu:
                Insert();
                break;
            case Select_Menu:
                Select();
                break;
            case Update_Menu:
                Update();
                break;
            case Delate_Menu:
                Delate();
                break;

            default:
                break;
        }
    }
}
void
Insert()
{

}

void
Login()
{
    char host[20], user[50], *passwd, dbname[50];
    unsigned port;

    /* input */
    printf("please input your mysql host: ");
    scanf("%s", host);
    printf("please input your mysql port: ");
    scanf("%u", &port);
    printf("please input your mysql user: ");
    scanf("%s", user);
    passwd = getpass("please input your mysql password: ");
    printf("please input your mysql database's name: ");
    scanf("%s", dbname);

    /* connect */
    if (mysql_real_connect(&Now_Sql, host, user, passwd, dbname, port, NULL, 0) == NULL) {
        printf("mysql connection failed\n");
        fprintf(stderr, "%s\n", mysql_error(&Now_Sql));
        exit(1);
    }
    else {
        fprintf(stderr, "mysql connection successful!\n");
    }
}

void
Select()
{

}

void
Update()
{

}

int main(int argc, char *argv[])
{
    mysql_init(&Now_Sql);

    Login();
    Display_Menu(Now_Sql.db, Now_Sql.user);
    Get_Command();

    mysql_close(&Now_Sql);
    return 0;
}
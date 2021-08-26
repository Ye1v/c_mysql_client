#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <mysql/mysql.h>

#include "menu.h"

/* struct */
typedef struct Account Account;
struct Account {
    char host[20];
    char user[50];
    char *passwd;
    char dbname[50];
    unsigned port;
};

/* function declarations */
static void CreateTable();
static void Delate();
static void DropTable();
static void Get_Command();
static void Insert();
static void Login();
static void Select();
static void Use();
static void Update();

/* variables */
static MYSQL Now_Sql;
static MYSQL_STMT Now_Stmt;
static char *Query;
static Account Acc;

/* function implementations */
void
Create()
{
    Query = "create table ? (? ?, ? ?);"; 
}

void
Delate()
{

}

void
Drop()
{

}

void
Get_Command()
{
    while (1) {   
        int command = Get_Command_Menu(Now_Sql.db);
        
        switch (command) {
            case Create_Menu:
                Create();
                break;
            case Delate_Menu:
                Delate();
                break;
            case Insert_Menu:
                Insert();
                break;
            case Quit_Menu:
                exit(0);
            case Select_Menu:
                Select();
                break;
            case Use_Menu:
                Use();
                break;
            case Update_Menu:
                Update();
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
    /* input */
    printf("please input your mysql host: ");
    scanf("%s", Acc.host);
    printf("please input your mysql port: ");
    scanf("%u", &Acc.port);
    printf("please input your mysql user: ");
    scanf("%s", Acc.user);
    Acc.passwd = getpass("please input your mysql password: ");
    printf("please input your mysql database's name: ");
    scanf("%s", Acc.dbname);

    /* connect */
    if (mysql_real_connect(&Now_Sql, Acc.host, Acc.user, Acc.passwd, Acc.dbname, Acc.port, NULL, 0) == NULL) {
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
Use()
{
    mysql_close(&Now_Sql);
    mysql_init(&Now_Sql);

    printf("please input your mysql database's name: ");
    scanf("%s", Acc.dbname);

    if (mysql_real_connect(&Now_Sql, Acc.host, Acc.user, Acc.passwd, Acc.dbname, Acc.port, NULL, 0) == NULL) {
        printf("mysql connection failed\n");
        fprintf(stderr, "%s\n", mysql_error(&Now_Sql));
        exit(1);
    }
    else {
        fprintf(stderr, "mysql connection successful!\n");
        Display_Menu(Now_Sql.db, Now_Sql.user);
    }
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
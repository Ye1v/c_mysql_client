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
static int  Delate();
static void DropTable();
static void Get_Command();
static int  Insert();
static void Login();
static int  Select();
static int  Show();
static int  Use();
static int  Update();

/* variables */
static Account Acc;
static MYSQL_RES *Now_Res;
static MYSQL_ROW Now_Row;
static MYSQL Now_Sql;
static MYSQL_STMT *Now_Stmt;
static char *Query;

/* function implementations */
int
Create()
{
    Query = "create table ? (? ?, ? ?)"; 
}

int
Delate()
{
    
}

int
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
            case Show_Menu:
                Show();
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

int
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

int
Select()
{
    char table[20];
    MYSQL_BIND params[1];
    Query = "select * from ?";

    printf("input the Table: \n");
    scanf("%s", &table);

    memset(params, 0, sizeof(params));
    params[0].buffer_type = MYSQL_TYPE_STRING; 
    params[0].buffer = table;

    if(mysql_stmt_prepare(Now_Stmt, Query, strlen(Query))) { 
        fprintf(stderr, "mysql_stmt_prepare: %s\n", mysql_error(&Now_Sql)); 
        return -1; 
    }

    mysql_stmt_bind_result(Now_Stmt, params); 
    mysql_stmt_execute(Now_Stmt);
}

int
Show()
{
    Query = "show tables";

    if (mysql_query(&Now_Sql, Query)) {
          fprintf(stderr, "%s\n", mysql_error(&Now_Sql));
          return -1;
    }
    Now_Res = mysql_use_result(&Now_Sql);
    printf("MySQL Tables in database %s:\n", Now_Sql.db);
    while ((Now_Row = mysql_fetch_row(Now_Res)) != NULL)
        printf("%s \n", Now_Row[0]);

    mysql_free_result(Now_Res);
}
int
Use()
{
    mysql_close(&Now_Sql);
    mysql_init(&Now_Sql);

    printf("please input your mysql database's name: \n");
    scanf("%s", Acc.dbname);

    if (mysql_real_connect(&Now_Sql, Acc.host, Acc.user, Acc.passwd, Acc.dbname, Acc.port, NULL, 0) == NULL) {
        printf("mysql connection failed\n");
        fprintf(stderr, "%s\n", mysql_error(&Now_Sql));
        return -1;
    }
    else {
        fprintf(stderr, "mysql connection successful!\n");
        Display_Menu(Now_Sql.db, Now_Sql.user);
    }
}

int
Update()
{

}

int main(int argc, char *argv[])
{
    mysql_init(&Now_Sql);
    Now_Stmt = mysql_stmt_init(&Now_Sql);

    Login();
    Display_Menu(Now_Sql.db, Now_Sql.user);
    Get_Command();

    mysql_stmt_close(Now_Stmt);
    mysql_close(&Now_Sql);
}
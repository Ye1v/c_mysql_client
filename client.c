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
static int  CreateTable();
static int  Delate();
static int  DropTable();
static int  Execute();
static void Get_Command();
static int  Insert();
static void Login();
static void Print();
static int  Select();
static int  Show();
static int  Use();
static int  Update();

/* variables */
static Account Acc;
static MYSQL_RES *Now_Res;
static MYSQL_ROW Now_Row;
static MYSQL Now_Sql;
static char Query[100];

/* function implementations */
int
CreateTable()
{
    char table_name[50];
    char colume_name[50];
    char colume_type[50];
    int colume_num;

    strcpy(Query, "create table ");

    scanf("%s", table_name);
    strcat(Query, table_name);
    strcat(Query, " (");

    scanf("%d", &colume_num);
    while (colume_num--) {
        scanf("%s", colume_name);
        scanf("%s", colume_type);

        strcat(Query, colume_name);
        strcat(Query, " ");
        strcat(Query, colume_type);
        if (colume_num != 0)
            strcat(Query, ", ");
    }
    strcat(Query, ")");
    
    if (Execute() == -1)
        return -1;
}

int
Delate()
{
    
}

int
DropTable()
{
    char table_name[50];

    strcpy(Query, "drop table ");

    scanf("%s", table_name);
    strcat(Query, table_name);

    if (Execute() == -1)
        return -1;
}

int
Execute()
{
    if (mysql_query(&Now_Sql, Query)) {
          fprintf(stderr, "%s\n", mysql_error(&Now_Sql));
          return -1;
    }
}
void
Get_Command()
{
    while (1) {   
        int command = Get_Command_Menu(Now_Sql.db);
        
        switch (command) {
            case Create_Menu:
                CreateTable();
                break;
            case Delate_Menu:
                Delate();
                break;
            case Drop_Menu:
                DropTable();
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

void
Print()
{
    Now_Res = mysql_use_result(&Now_Sql);

    while ((Now_Row = mysql_fetch_row(Now_Res)) != NULL) {
        for (int i = 0; i < mysql_num_fields(Now_Res); i++) {
            printf("%s\t", Now_Row[i]);
        }
        printf("\n");
    }

    mysql_free_result(Now_Res);
}

int
Select()
{
    char table_name[10];

    strcpy(Query, "select * from ");
    scanf("%s", table_name);
    strcat(Query,table_name);
    
    if (Execute() == -1)
        return -1;
    Print();
}

int
Show()
{
    strcpy(Query, "show tables");

    printf("MySQL Tables in database %s:\n", Now_Sql.db);

    if (Execute() == -1)
        return -1;
    Print();
}

int
Use()
{
    mysql_close(&Now_Sql);
    mysql_init(&Now_Sql);

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

    Login();
    Display_Menu(Now_Sql.db, Now_Sql.user);
    Get_Command();

    mysql_close(&Now_Sql);
}
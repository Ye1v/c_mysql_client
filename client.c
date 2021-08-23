#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <mysql/mysql.h>

#include "menu.h"

/* function declarations */
static void Login(MYSQL *mysql);

/* function implementations */
void
Login(MYSQL *mysql)
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
    if (mysql_real_connect(mysql, host, user, passwd, dbname, port, NULL, 0) == NULL) {
        printf("mysql connection failed\n");
        fprintf(stderr, "%s\n", mysql_error(mysql));
        exit(1);
    }
    else {
        fprintf(stderr, "mysql connection successful !\n");
    }
}

/* variables */
MYSQL Now_Sql;

int main(int argc, char *argv[])
{
    mysql_init(&Now_Sql);
    Login(&Now_Sql);
    Display_Menu(Now_Sql.db, Now_Sql.user);
    while (1)
    {
        if (Get_Command_Menu(&Now_Sql) == 1) break;  
    }
    

    mysql_close(&Now_Sql);
    return 0;
}
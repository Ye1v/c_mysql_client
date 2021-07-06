#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mysql/mysql.h"
int main()
{
    MYSQL *conn = mysql_init(NULL);     //初始化服务器句柄
    /*登陆服务器*/
    if(!mysql_real_connect(conn, "localhost", "root", "myruby", "RUNOOB", 3306, NULL, 0))  
    {
        fprintf(stderr, "mysql_real_connect: %s\n", mysql_error(conn));
        return -1;
    }   
    MYSQL_STMT *stmt = mysql_stmt_init(conn); //创建MYSQL_STMT句柄 
    char *query = "insert into runoob_tbl values(?, ?, ?, ?);";
    if(mysql_stmt_prepare(stmt, query, strlen(query)))
    {
        fprintf(stderr, "mysql_stmt_prepare: %s\n", mysql_error(conn));
        return -1;
    }
    printf("id title author date: ");
    int id;
    char title[20];
    char author[20];
    char date[20];
    scanf("%d %s %s %s", &id, title, author, date);
    MYSQL_BIND params[4];
    memset(params, 0, sizeof(params));
    params[0].buffer_type = MYSQL_TYPE_LONG;
    params[0].buffer = &id;
    params[1].buffer_type = MYSQL_TYPE_STRING;
    params[1].buffer = title;
    params[1].buffer_length = strlen(title);  
    params[2].buffer_type = MYSQL_TYPE_STRING;
    params[2].buffer = author;
    params[2].buffer_length = strlen(author);
    params[3].buffer_type = MYSQL_TYPE_STRING;
    params[3].buffer = date;
    params[3].buffer_length = strlen(date);
    
    mysql_stmt_bind_param(stmt, params);
    mysql_stmt_execute(stmt);           //执行与语句句柄相关的预处理
    mysql_stmt_close(stmt);             
    mysql_close(conn);
    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mysql/mysql.h"
int main()
{
    MYSQL *conn = mysql_init(NULL);     //��ʼ�����������
    /*��½������*/
    if(!mysql_real_connect(conn, "localhost", "root", "myruby", "RUNOOB", 3306, NULL, 0))  
    {
        fprintf(stderr, "mysql_real_connect: %s\n", mysql_error(conn));
        return -1;
    }   

    MYSQL_STMT *stmt = mysql_stmt_init(conn); //����MYSQL_STMT���

    char *query = "select * from runoob_tbl;";
    if(mysql_stmt_prepare(stmt, query, strlen(query)))
    {
        fprintf(stderr, "mysql_stmt_prepare: %s\n", mysql_error(conn));
        return -1;
    }

    printf("id\t title\t author\t date\t:\n ");
    int id;
    char title[20];
    char author[20];
    char date[20];
    MYSQL_BIND params[4];
    memset(params, 0, sizeof(params));
    params[0].buffer_type = MYSQL_TYPE_LONG;
    params[0].buffer = &id;
    params[1].buffer_type = MYSQL_TYPE_STRING;
    params[1].buffer = title;
    params[1].buffer_length = 20;
    params[2].buffer_type = MYSQL_TYPE_STRING;
    params[2].buffer = author;
    params[2].buffer_length = 20;
    params[3].buffer_type = MYSQL_TYPE_STRING;
    params[3].buffer = date;
    params[3].buffer_length = 20;

    mysql_stmt_bind_result(stmt, params); //���ڽ�������е��������ݻ���ͳ��Ȼ���������󶨣�����
    mysql_stmt_execute(stmt);           //ִ�����������ص�Ԥ����
    mysql_stmt_store_result(stmt);      //�Ա������mysql_stmt_fetch()�����ܷ��ػ�������  

    while(mysql_stmt_fetch(stmt) == 0) //���ؽ�����е���һ��
    {
        printf("%d\t %s\t %s\t %s\t\n", id, title, author, date);
    }

    mysql_stmt_close(stmt);
    mysql_close(conn);

    return 0;
}

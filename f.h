#include<iostream>
#include<stdlib.h>
#include <mysql/mysql.h>
#include <string>

string user_name;	//变量声明
string user_server;
string user_passwd;
string user_db;
int  usr_port;
string databases;

int remake(void);    //函数声明
void connect(MYSQL *now_sql);
void insertData(MYSQL *now_sql);  //增
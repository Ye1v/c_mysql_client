#include<iostream>
#include<stdlib.h>
#include <mysql/mysql.h>
#include <string>
using namespace std;

string user_name;	//变量声明
string user_server;
string user_passwd;
string user_db;
int  usr_port;
string databases;

int remake(void);    //函数声明
void connect(MYSQL *now_sql);
int mysql_now(MYSQL *now_sql);
int insertData(MYSQL *now_sql);  //增
int  deleteName(MYSQL *now_sql); //删
int  updateByName(MYSQL *now_sql);  //改，也可以理解为更新字段，需要指定 
#include <iostream>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <string>
using namespace std;

//变量声明
string user_name;
string user_server;
string user_passwd;
string user_db;
int usr_port;
string databases;

//函数声明
int remake(void);//初始化内部
int connect(MYSQL *now_sql);//连接
int mysql_now(MYSQL *now_sql);//初始化数据库
int insertData(MYSQL *now_sql);  //增
int deleteName(MYSQL *now_sql); //删
int updateByName(MYSQL *now_sql);  //改，也可以理解为更新字段，需要指定
void quit(MYSQL * now_sql);//退出数据库

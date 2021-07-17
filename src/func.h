#ifndef _FUNC_H_
#define _FUNC_H_ 
//头文件
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <mysql/mysql.h>
#include <string>

using namespace std;

//变量声明
extern string user_name;
extern string user_server;
extern string user_passwd;
extern string user_db;
extern int usr_port;
extern string databases;

//函数声明
    ////后台函数
    int remake(void);//初始化内部
    int connect(MYSQL *now_sql);//连接
    int mysql_now(MYSQL *now_sql);//初始化数据库
    int insertData(MYSQL *now_sql);  //增
    int deleteName(MYSQL *now_sql);  //删
    int updateByName(MYSQL *now_sql);  //改，也可以理解为更新字段，需要指定
    void quit(MYSQL * now_sql);//退出数据库

    ////前台函数
    void Display_Menu();
    bool Run_Menu(MYSQL *sql, string command);
    void Help_Menu();
    string Input_Menu(string command);

#endif
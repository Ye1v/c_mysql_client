#include<iostream>
#include<stdlib.h>
#include <mysql/mysql.h>
#include <string>
class use_mysql
{
	public:
	    int remake(void);
};
class usr_in
{
	public: 
	   string usr_name;
	   string usr_server;
	   string usr_passwd;
	   string usr_db;
     	int  usr_port;
     string databases;
	   void name(void);
	   void server(void);
	   void passwd(void);
	   void db(void);
     void port(void);
};
void connect(MYSQL *now_sql);
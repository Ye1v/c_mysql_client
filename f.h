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
     string  usr_port;
     string databases;
	   void name(void);
	   void server(void);
	   void passwd(void);
     void port(void);
};
int connect(MYSQL *now_sql);


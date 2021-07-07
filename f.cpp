#include<f.h>
using namespace std;
void usr_in::name(void)
{
	cin >>usr_name;
	return ;
}
void usr_in::server(void)
{
	cin >>usr_server;
	return ;
}
void usr_in::passwd(void)
{
	cin >>usr_passwd;
	return ;
}
void usr_in::port(void)
{
	cin >>usr_port;
	return ;
}
void usr_in::db(void)
{
	cin >>usr_db;
	return ;
}
int use_mysql::remake(void)
{
  if (mysql_library_init(0, NULL, NULL)) 
  {
    exit(1);
  }
  mysql_library_end();
  return EXIT_SUCCESS;
}
int mysql_now(MYSQL *now_sql)
{
	bool boot;
	char c;
	MYSQL *now_sql;
	cout <<"正在进行初始化\n";
	if(use_mysql.remake()==0)
		cout <<"初始化成功"<<endl;
	else 
		{
			cout<<"初始化失败"<<endl;
			return 0;
		}
	cout <<"请输入连接的用户名、服务器、数据库名、密码:"<<endl;
	usr_in.name();
	usr_in.server();
	usr_in.passwd();
	usr_in.db();
	cout <<endl;
	cout <<"端口默认为3306，是否更改(N/y):"
	cin >> c;
	if(c=='y'||c=='Y') 
	{
		usr_in.port();
	}
	else 
	{
		usr_in.usr_port="3306";
	}
	
	cout <<"正在连接到mysql服务器"<<endl;	
	return 0;
}
int connect_sql(MYSQL *now_sql))
{
	if(NULL == mysql_real_connect(now_sql,usr_in.usr_server,usr_in.usr_name,usr_in.usr_passwd,usr_in.usr_db,usr_in.usr_port,NULL,0))
		{
			cout <<"连接到mysql服务器失败,错误代码为："<<mysql_error(&now_sql)<<endl;
		}
	cout <<"已成功连接到mysql服务器！"<<endl;
	
}

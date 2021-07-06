#include<f.h>
using namespace std;
int connect(MYSQL *now_sql)
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
	cout <<"请输入连接的用户名、服务器、密码:"<<endl;
	usr_in.name();
	usr_in.server();
	usr_in.passwd();
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
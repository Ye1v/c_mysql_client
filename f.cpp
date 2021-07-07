#include "f.h"
using namespace std;

int remake(void) 	//初始化
{
 	  if (mysql_library_init(0, NULL, NULL)) 
  	{
   	  exit(1);
  	}
  	mysql_library_end();
  	return EXIT_SUCCESS;
}

int mysql_now(MYSQL *now_sql)   //启动 
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
			return 0;  //失败返回 0
		}
	cout <<"请输入连接的用户名、服务器、数据库名、密码:"<<endl;
	cin >> user_name;
	cin >> user_server;
	cin >> user_db;
	cout << endl;
	cout << "端口默认为3306，是否更改(N/y):"
	cin >> c;
	if(c=='y'||c=='Y') 
	{
		usr_in.port();
	}
	else 
	{
		user_port="3306";
	}
	cout <<"正在连接到mysql服务器"<<endl;	
	return 1;  //执行结束返回 1  
}

int connect_sql(MYSQL *now_sql))
{
	if(NULL == mysql_real_connect(now_sql,user_server,user_name,user_passwd,user_db,user_port,NULL,0))
		{
			cout <<"连接到mysql服务器失败,错误代码为："<<mysql_error(&now_sql)<<endl;
			return 0; //失败返回 0
		}
	cout <<"已成功连接到mysql服务器！"<<endl;
	return 1;  //成功返回 1
}

int insertData(MYSQL *now_sql)  //增
{
    	if(NULL == now_sql )
       {
       	 printf("发生了一个错误\n");
         return 0;    //失败返回 0
       }
    	string SQL; 
    	string word;
    	cin >>word;   
    	sprintf(SQL, "INSERT INTO table1 %s VALUES ", word);
    	printf("%s\n", SQL);
   	 //执行SQL语句
   	 if(mysql_query(now_sql, SQL) !=0)
   	{
    	    printf("发生了一个错误:%s\n", mysql_error(now_sql));
		return 0; //失败返回 0
   	}
	   return 1;   //成功返回 1
}

int  deleteName(MYSQL *now_sql) //删
{
    	if(NULL == now_sql )
       {
       	  printf("发生了一个错误: \n");
          return 0;    //失败返回 0
       }
    	string word;
    	cin >>word;
    	string SQL;
    	sprintf(SQL, "delete from table1 WHERE name = '%s'", word);
    	printf("%s\n", SQL);

    //执行SQL语句
    	if(mysql_query(now_sql, SQL) !=0)
       {
        printf("发生了一个错误:%s\n", mysql_error(now_sql));
        return 0; //失败返回 0
       }	
	return 1; //成功返回 1
}


int  updateByName(MYSQL *now_sql)  //改，也可以理解为更新字段，需要指定 
{	
    if(NULL == now_sql )
    {
     	 printf("发生了一个错误\n");
         return 0;    //失败返回 0
    }
    string SQL;
    string word1;
    string word2;
    cin >>word1;
    cin >>word2;

   /* sprintf(SQL, "UPDATE table1 SET  sex = '%s' WHERE name = '%s'", word1,word2); 根据需求改 */
    printf("%s\n", SQL);

    //执行SQL语句
    if(mysql_query(now_sql, SQL) !=0)
    {
      	printf("发生了一个错误:%s\n", mysql_error(now_sql));
        return 0; //失败返回 0
    }
    return 1; //成功返回 1
}



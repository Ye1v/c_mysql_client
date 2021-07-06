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
int use_mysql::remake(void)
{
  if (mysql_library_init(0, NULL, NULL)) 
  {
    exit(1);
  }
  mysql_library_end();

  return EXIT_SUCCESS;

}


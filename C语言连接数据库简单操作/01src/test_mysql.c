#include <stdlib.h>
#include <stdio.h>
#include "mysql/mysql.h"

int main( int argc, char *argv[] )
{
        MYSQL *conn_ptr;
        conn_ptr = mysql_init( NULL );  /* ���ӳ�ʼ�� */
        if ( !conn_ptr )
        {
                fprintf( stderr, "mysql_init failed\n" );
                return(EXIT_FAILURE);
        }
        conn_ptr = mysql_real_connect( conn_ptr, "localhost", "root", "myruby", "test", 3306, NULL, 0 );/* ����ʵ������ */
        /* �����ֱ�Ϊ����ʼ�������Ӿ��ָ�룬������������IP�����û��������룬���ݿ�����0��NULL��0����������������Ĭ�ϰ�װmysql>>������²��ø� */
        if ( conn_ptr ){
                printf( "Connection success\n" );
        }
        else{
                printf( "Connection failed\n" );
        }

        mysql_close( conn_ptr ); /* �ر����� */

        return(EXIT_SUCCESS);
}

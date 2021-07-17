#include "func.h"
#include <mysql/mysql.h>
#include <string>

using namespace std;


int main(int argc, char **argv) {
    MYSQL *Now_DataBase; //当前操作数据库
    string Now_Command;

    if (mysql_now(Now_DataBase) && connect(Now_DataBase)) { //初始化并连接

        Display_Menu();
        while (true) {
            bool Flag = 0;
            Input_Menu(Now_Command);
            Flag = Run_Menu(Now_DataBase, Now_Command);
            if (Flag) break;
        }
    }

    mysql_close(Now_DataBase);
    return 0;
}

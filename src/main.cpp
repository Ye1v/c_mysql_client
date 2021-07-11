#include "f.h"

using namespace std;

class parser;
void Display_Menu(MYSQL *DB) { //展示菜单
    printf("====================================================\n"
            "___  ___                _        _ _            _   \n"
            "|  \\/  |               | |      | (_)          | |  \n"
            "| .  . |_   _ ___  __ _| |   ___| |_  ___ _ __ | |_ \n"
            "| |\\/| | | | / __|/ _` | |  / __| | |/ _ \\ '_ \\| __|\n"
            "| |  | | |_| \\__ \\ (_| | | | (__| | |  __/ | | | |_ \n"
            "\\_|  |_/\\__, |___/\\__, |_|  \\___|_|_|\\___|_| |_|\\__|\n"
            "         __/ |       | |                            \n"
            "        |___/        |_|                        v1.0\n"
            "====================================================\n"
            " 您的用户名:%s                                        \n"
            "====================================================\n"
            " 输入 -h 来获取帮助!\n",
            DB->user);
}

// string Choose_Menu() { //选择操作
//     string Choice;
//     return cin >> Choice;
// }

// void RunCode(string Choice) { //执行操作
//     if ()
// }

MYSQL *Now_DataBase; //当前操作数据库
int main(int argc, char **argv) {
    if (mysql_now(Now_DataBase) && connect(Now_DataBase)) { //初始化并连接
        Display_Menu(Now_DataBase);
        // RunCode(Choose_Menu(Now_DataBase));
    }
    return 0;
}

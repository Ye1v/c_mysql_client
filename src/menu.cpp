#include "func.h"

using namespace std;

void Display_Menu() { //展示菜单
    cout <<"====================================================\n"
            "___  ___                _        _ _            _   \n"
            "|  \\/  |               | |      | (_)          | |  \n"
            "| .  . |_   _ ___  __ _| |   ___| |_  ___ _ __ | |_ \n"
            "| |\\/| | | | / __|/ _` | |  / __| | |/ _ \\ '_ \\| __|\n"
            "| |  | | |_| \\__ \\ (_| | | | (__| | |  __/ | | | |_ \n"
            "\\_|  |_/\\__, |___/\\__, |_|  \\___|_|_|\\___|_| |_|\\__|\n"
            "         __/ |       | |                            \n"
            "        |___/        |_|                        v1.0\n"
            "====================================================\n"
            " 目前数据库:" << user_db <<
            "\n====================================================\n"
            " 输入 help 来获取帮助!\n";
}

string Input_Menu(string command) {
    cout << "(" << user_name << ")>"; 
    cin >> command;
    return command;
}

void Help_Menu() {
    cout << "" << endl;
}

bool Run_Menu(MYSQL *sql, string command) { //选择并运行操作
    if (/*command为help*/) Help_Menu();
    if (/*Choice为*/) insertData();
    if () deleteName();
    if () updateByName();
    if (/*Chioce为exit*/) return true;
    return false;
}



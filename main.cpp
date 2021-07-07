#include "f.h"

using namespace std;
/*
void Display_Menu() {//展示菜单

}
int (*Choose_Menu())(MYSQL* DataBase) {//选择操作

}
void RunCode() {//执行操作

}
*/
MYSQL* Now_DataBase;//当前操作数据库
int main(int argc, char** argv) {
    if (mysql_now(Now_DataBase) && connect(Now_DataBase)) {//初始化并连接
        //Display_Menu();
        //RunCode(Choose_Menu());
    }
    else {
        return 0;
    }
}

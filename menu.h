#ifndef MENU_H
#define MENU_H

void Display_Menu(char *db, char *user);
void Help_Menu();
int  Get_Command_Menu(MYSQL *mysql);

#endif
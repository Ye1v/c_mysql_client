#ifndef MENU_H
#define MENU_H

enum { create = 2, insert, select, update, delate };

void Display_Menu(char *db, char *user);
void Help_Menu();
int  Get_Command_Menu(char *db);

#endif
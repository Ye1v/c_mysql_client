#ifndef MENU_H
#define MENU_H

enum { Create_Menu = 2, Insert_Menu, Select_Menu, Update_Menu, Delate_Menu };

void Display_Menu(char *db, char *user);
void Help_Menu();
int  Get_Command_Menu(char *db);

#endif
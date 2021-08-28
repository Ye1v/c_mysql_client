#ifndef MENU_H
#define MENU_H

enum { Create_Menu, Delate_Menu, Drop_Menu, Insert_Menu,
       Quit_Menu, Select_Menu, Show_Menu, Use_Menu, Update_Menu };

void Display_Menu(char *db, char *user);
void Help_Menu();
int  Get_Command_Menu(char *db);

#endif
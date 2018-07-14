#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

#define ENTER 10
#define ESC 27

#define WHI_BLU 1
#define BLU_WHI 2
#define RED_WHI 3
#define BLK_BLU 4
#define YEL_BLU 5
//#define OK 3
#define CANCEL 4
#define OK_CANCEL 5
#define MENU_OK_ONLY 1000
#define MENU_OK_CANCEL 1001
#define MENU_INPUT 1002
#define MENU_SAVE_AS 1003
#define MENU_QUIT 1004
#define MENU_ABOUT 2000
#define MENU_HELP 2001
#define MENU_VERSION 2002
#define MENU_WIDTH 15 /*menu width*/
#define INPUT_SIZE 30 /*Max input string size*/
#define MNCANCEL 5000
char *menu1[]={"OK_ONLY","OK_CANCEL","INPUT","SAVE_AS","QUIT"};
char *menu2[]={"ABOUT","HELP","VERSION"};

void init_curses();		//初始化curses模式并设置颜色
void draw_menubar(WINDOW *menubar);//在窗口中打印信息
WINDOW **draw_menu(int start_col,char **menu,int itemCount,int width);
//四个参数 start_col:开始的列,menu:窗口内容,itemCount:窗口数量,width:窗口宽度
void delete_menu(WINDOW **items,int count);//删除窗口函数

int scroll_menu(WINDOW **items,int count,int menu_start_col);
//按方向键后,显示你选择的窗口,最后当你按下回车键时,返回你选择的窗口的窗口号

WINDOW **messagebox(char * topic, char * message,int type);
//显示消息函数,前两个参数是字符串,即要显示的信息,最后一个参数是消息类型
int msgrtn(WINDOW **msgbox);//消息框返回值,返回 OK 或 CANCEL

void del_box(WINDOW **box);//结束消息显示,删除窗口
void inputs(WINDOW **inpbox,int y,int x,char *str);//输入函数,在窗口inpbox下输入字符串strs
WINDOW **inpbox(char * topic, char * inputStr);
//char * topic :标题  char * inputStr:返回的输入信息

int inpboxrtn(WINDOW **inputbox);//输入函数中调用的,选择OK 还是CANCEL 
//下列为菜单中的函数,主要就是显示
void MNokonly();
void MNokcancel();
void MNinput(char *topic);
void MNsaveas();
int MNquit();
void MNabout();
void MNhelp();
void MNversion();

#endif














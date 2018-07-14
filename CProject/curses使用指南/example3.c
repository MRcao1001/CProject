/******************************************************
 	>File Name: 	example3.c
 	>Author: 		Tony
 	>Mail: 			494966849@qq.com
 	>Created Time:  2017年05月24日 星期三 10时56分33秒
******************************************************/

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

//进入curses模式
void init_curses()
{
	initscr();
	start_color();/**初始化颜色*/
	init_pair(WHI_BLU,COLOR_WHITE,COLOR_BLUE);/**set前景色和背景色model**/
	init_pair(BLU_WHI,COLOR_BLUE,COLOR_WHITE);
	init_pair(RED_WHI,COLOR_RED,COLOR_WHITE);
	init_pair(BLK_BLU,COLOR_BLACK,COLOR_BLUE);
	init_pair(YEL_BLU,COLOR_YELLOW,COLOR_BLUE);
	curs_set(0);/***设置光标不可见**/
	noecho();/**关闭回显**/
	keypad(stdscr,TRUE);/**使用curses.h所定义的特殊键必须将keypad设定为TRUE**/
}

//画窗口函数,主要是画横向和竖线
void draw_menubar(WINDOW *menubar)
{
	wbkgd(menubar,COLOR_PAIR(BLU_WHI));//设置窗口menubar为白底蓝字
	move(24,0);		//移动光标到某处,第一个参数,y轴坐标,第二个参数,X轴坐标
	hline(ACS_HLINE,80);//画横线,长度为80
	move(0,0);
	vline(ACS_VLINE,25);//左边的竖线
	move(0,79);
	vline(ACS_VLINE,25);//右边的竖线
	wmove(menubar,0,1);
	waddstr(menubar,"MENU_TEST");
	wattron(menubar,COLOR_PAIR(RED_WHI));/*COLOR::front:RED  bak:WHITE */
	waddstr(menubar,"(F3)");
	wattroff(menubar,COLOR_PAIR(RED_WHI));/**close FONT**/
	wmove(menubar,0,20);
	waddstr(menubar,"MENU_HELP");
	wattron(menubar,COLOR_PAIR(RED_WHI));
	waddstr(menubar,"(F2)");
	wattroff(menubar,COLOR_PAIR(RED_WHI));//wattroff():关闭窗口的颜色
}//需要注意的是wattron调用了另外一个不同的颜色对(序号3)以取代缺省的颜色对(序号2).记住2号颜色对在最开始就 由wbkgd设置成缺省的颜色对了.wattroff函数可以让我们切换到缺省的颜色对状态.


/**扩展接口:菜单数目及内容**/
//四个参数 start_col:窗口横坐标,menu:窗口内容数组,itemCount:窗口数量,width:窗口宽度
WINDOW **draw_menu(int start_col,char **menu,int itemCount,int width)
{
	int i;
	WINDOW **items;
	items=(WINDOW **)malloc((itemCount+1)*sizeof(WINDOW *));//给窗口开辟空间
	items[0]=newwin(itemCount+2,width+2,1,start_col);//建立窗口
	wbkgd(items[0],COLOR_PAIR(BLU_WHI));//设置窗口颜色,白底蓝字
	box(items[0],ACS_VLINE,ACS_HLINE);//窗口边框划线
	for(i=1;i<=itemCount;i++)
		items[i]=subwin(items[0],1,width,i+1,start_col+1);//建立多个窗口
	for (i=0;i<itemCount;i++)
		wprintw(items[i+1],"%s",menu[i]);//显示多个窗口中的信息
	wbkgd(items[1],COLOR_PAIR(WHI_BLU));/**childItem:front:WHITE,bak:BLUE**/
	wrefresh(items[0]);
	return items;
}

//删除窗口函数
void delete_menu(WINDOW **items,int count)
{
	int i;
	for (i=0;i<count;i++)
		delwin(items[i]);
	free(items);
}

//该函数负责显示你选择的窗口,最后当你按下回车键时,返回你选择的窗口的窗口号
int scroll_menu(WINDOW **items,int count,int menu_start_col)
{
	int key;
	int selected=0;
	while(1)
	{
  		key=getch();
  		if(key==KEY_DOWN || key==KEY_UP)//当按下方向键的上键或是下键时
 		{
    		wbkgd(items[selected+1],COLOR_PAIR(RED_WHI));//设置窗口颜色白底红字
    		wnoutrefresh(items[selected+1]);//刷新窗口
			if(key==KEY_DOWN)
        	{
        		selected=(selected+1) % count;//按下键找到下一个窗口
        	}
			else
        	{
        		selected=(selected+count-1) % count;//按上键找到上一个窗口
        	}
   			wbkgd(items[selected+1],COLOR_PAIR(WHI_BLU));//设置被找到窗口颜色为蓝底白字
   			wnoutrefresh(items[selected+1]);//刷新被找到的窗口颜色
   			doupdate();//刷新窗口函数
  		}
		else if (key==ESC)
 		{
    		return -1;
 		}
		else if (key==ENTER)//按下返回键时,返回窗口号的值
 		{
    		selected += (menu_start_col/20 + 1)*1000;/*改变返回值,*/
    		return selected;
  		}
	}/**while(1)**/
}

/*显示消息函数*/
/*topic:标题 message：信息*/
WINDOW **messagebox(char * topic, char * message,int type)
{
	int width,height;
	int i,j;
	int y, x;/*position of message box*/
	char *tmp;
	WINDOW **msgbox;
	width = strlen(message);
	if(width<20)
		width = 20;
	height=width/40+1;/*count of message line*/
	x = (80-width)/2;
	y = (20-height)/2;
	/****************
	if (width >40)
	 {width=40;
	 i=0;
	 memset(
	 while(message[i])
	  tmp[i]=
	  tmp[0]=
	****************/
	/*
	* ______________________________________
	*|TOPIC (1)                             |(0)
	*|             MESSAGE (2)              |
	*|             MESSAGE                  |
	*|             MESSAGE                  |
	*|         [OK](3) [CANCEL] (4)         |
	*|______________________________________|
	*/
	msgbox=(WINDOW **)malloc((5)*sizeof(WINDOW *));/*box+topic+msgbox+OK_CANCEL*/
	msgbox[0]=newwin(height+4,width+2,y,x);/**lines,rows,y,x**/
	wbkgd(msgbox[0],COLOR_PAIR(BLU_WHI));/**front:BLUE,bak:WHITE**/
	box(msgbox[0],ACS_VLINE,ACS_HLINE);/**draw box**/
	msgbox[1]=subwin(msgbox[0],1,width,y+1,x+1);
	msgbox[2]=subwin(msgbox[0],height,width,y+2,x+1);
	wbkgd(msgbox[1],COLOR_PAIR(YEL_BLU));/**topic::backcolor=BLUE,front=YELLOW**/
	wprintw(msgbox[1],"%s",topic);
	wprintw(msgbox[2],"%s",message);
	if (type == OK)
	{
		msgbox[3]=subwin(msgbox[0],1,6,y+3,x+(width-4)/2+1);
		wprintw(msgbox[3]," [OK] ");//OK button
		msgbox[4]=subwin(msgbox[0],1,1,y+3,x+1);//CANCEL button,here can't see
	}
	if (type == OK_CANCEL)
	{
		msgbox[3]=subwin(msgbox[0],1,6,y+3,x+3);
		wprintw(msgbox[3]," [OK] ");/*length=1,so +1 :)*/
		msgbox[4]=subwin(msgbox[0],1,10,y+3,x+width-10);
		wprintw(msgbox[4]," [CANCEL] ");
	}
	wbkgd(msgbox[OK],COLOR_PAIR(WHI_BLU));/*default choose OK*/
	wrefresh(msgbox[0]);
	return msgbox;
}

/*消息框返回值：OK or CANCEL*/
int msgrtn(WINDOW **msgbox)
{
	int key;
	int selected=3;
	while(1)
	{
		key=getch();
		if(key==KEY_LEFT || key==KEY_RIGHT)
 		{
    		wbkgd(msgbox[selected],COLOR_PAIR(BLU_WHI));//设置窗口为白底蓝字
    		wnoutrefresh(msgbox[selected]);//刷新窗口
   			if(key==KEY_LEFT)//左键时选择的是 OK
        	{
        		selected=OK;
        	}
   			else			//否则是取消
        	{
        		selected=CANCEL;
        	}
   			wbkgd(msgbox[selected],COLOR_PAIR(WHI_BLU));//设置窗口为蓝底白字
   			wnoutrefresh(msgbox[selected]);//刷新窗口
   			doupdate();
  		}
		else if(key==ESC)//按下ESC时,返回cancel
 		{
    		return CANCEL;
 		}
		else if(key==ENTER)//按下回车,返回你的选择
 		{
    		return selected;
 		}
		else if (key=='t')/*TAB KEY*/ //按下table键时
 		{
		    {
		    	wbkgd(msgbox[selected],COLOR_PAIR(BLU_WHI));//窗口为白底蓝字
		   		wnoutrefresh(msgbox[selected]);				//刷新屏幕
		    	selected = (selected == CANCEL) ? OK : CANCEL;
		    	wbkgd(msgbox[selected],COLOR_PAIR(WHI_BLU));//设置背景色为蓝底白字
		    	wnoutrefresh(msgbox[selected]);				//刷新屏幕
		    	doupdate();
        	}
 		}
	}/**while(1)**/
}
/*结束消息显示*/
/*功能：结束显示消息框，回收内存*/
/*删除窗口时偶尔会出现core dumped!!!!!!!!!!*/
void del_box(WINDOW **box)
{
	int i;
	for(i=0;i<=4;i++)
	{
		delwin(box[i]);
	}
	free(box);
}



void inputs(WINDOW **inpbox,int y,int x,char *str)
{
	int ch;
	char tmpstr[INPUT_SIZE];		//设置字符数组,大小为30
	int count=-1,flag=1;
	x=0;
	memset(tmpstr,' ',INPUT_SIZE);	//清空字符数组
	memset(str,' ',INPUT_SIZE);		//清空字符数组
	noecho();						//关闭字符回显,就是输入的字符不显示
	wmove(inpbox[2],0,1);			//移动到二号窗口的指定坐标处
	curs_set(TRUE);/***设置光标可见**/
	intrflush(inpbox[2],TRUE);
	wmove(inpbox[0],2,1);			//移至输入位置
	wrefresh(inpbox[2]);			//刷新二号窗口
	wrefresh(inpbox[0]);			//刷新0号窗口
	do{
		ch=getch();
        switch(ch)		//判断
        {
        	case KEY_UP:			//判断是否"↑"键被按下
        	case KEY_DOWN:          //判断是否"↓"键被按下
        	case KEY_RIGHT:         //判断是否"→"键被按下
        	case KEY_LEFT:          //判断是否"←"键被按下
                beep();
                break;				//屏蔽方向键
        	case ENTER:
       		case 't':               //判断是否 TAB 键被按下
                flag = 0;
                curs_set(FALSE);  	//关闭光标
                wbkgd(inpbox[3],COLOR_PAIR(WHI_BLU));
                wnoutrefresh(inpbox[3]);/*[OK] button choosed*/
                break;
        	case KEY_BACKSPACE:     //判断是否 BACKSPACE 键被按下
                if(count < 0 )
                {
                	beep();
                	break;
                }
                else
                {
                	count--;
                	mvwaddch(inpbox[2],0,--x,' ');//delete 一个字符
                	tmpstr[count] == ' ';
                	break;
                }
        	case ESC:            			//判断是否[ESC]键被按下
                flag = 0;
                memset(tmpstr,' ',INPUT_SIZE);//ESC取消所有输入
                break;
        	default:
                if(count >= INPUT_SIZE-1 )
                {
                	beep();
                }
                else
                {
                	mvwaddch(inpbox[2],0,x,ch); //如果不是特殊字符, 印出
                	count++;
                	tmpstr[count] = ch;
                	x++;
                }
                break;
        }
        wmove(inpbox[2],0,x);                 	//移动光标至现在位置
        wrefresh(inpbox[2]);
}while(flag==1);
	tmpstr[count+1]=' ';
	memcpy(str,tmpstr,strlen(tmpstr));			//字符串拷贝
}

/*输入框函数inputbox()*/
/*char * topic :标题  char * inputStr:返回的输入信息*/
WINDOW **inpbox(char * topic, char * inputStr)
{
	int width,height;
	int i,j;
	int y, x;/*position of message box*/
	WINDOW **inputbox;	//定义窗口数组
	width = INPUT_SIZE;	//宏定义的宽度,大小为30
	height=2;			//高度设置2
	x = (80-width)/2;
	y = (20-height)/2;
	inputbox=(WINDOW **)malloc((5)*sizeof(WINDOW *));//给窗口分配空间
	inputbox[0]=newwin(height+4,width+2,y,x);	//设置0号窗口的位置和大小
	wbkgd(inputbox[0],COLOR_PAIR(BLU_WHI));		//设置0号窗口的颜色为白底黑字
	box(inputbox[0],ACS_VLINE,ACS_HLINE);		//给窗口1画线
	inputbox[1]=subwin(inputbox[0],1,width,y+1,x+1);//设置1号窗口的位置和大小
	inputbox[2]=subwin(inputbox[0],1,width,y+2,x+1);//设置2号窗口的位置和大小
	wbkgd(inputbox[2],COLOR_PAIR(WHI_BLU));		//设置二号窗口的样色为蓝底白字
	wprintw(inputbox[1],"%s",topic);			//在一号窗口中打印标题
	inputbox[3]=subwin(inputbox[0],1,6,y+4,x+3);//设置三号窗口的大小和位置
	wprintw(inputbox[3]," [OK] ");				//在三号窗口中打印一个OK
	inputbox[4]=subwin(inputbox[0],1,10,y+4,x+width-10);//设置四号窗口的位置和大小
	wprintw(inputbox[4]," [CANCEL] ");			//在四号窗口中打印cancel
	wrefresh(inputbox[0]);						//刷新0号窗口
	inputs(inputbox,1,1,inputStr);		//输入函数在窗口inputbox下输入inputStr字符串
	return inputbox;							//返回一系列窗口
}
/*msgrtn()*/
/*消息框返回值：OK or CANCEL*/


int inpboxrtn(WINDOW **inputbox)
{
	int key;
	int selected=3;
	while(1)
	{
		key=getch();
		if(key==KEY_LEFT || key==KEY_RIGHT)	//按下左键或是右键
 		{ 
   			wbkgd(inputbox[selected],COLOR_PAIR(BLU_WHI));	//设置三号窗口为白底蓝字
    		wnoutrefresh(inputbox[selected]);//刷新三号窗口
   			if (key==KEY_LEFT)	//如果是左键,选择ok
        	{
        		selected=OK;
        	}
   			else				//否则选择取消
        	{
        		selected=CANCEL;
        	}
   			wbkgd(inputbox[selected],COLOR_PAIR(WHI_BLU));//设置selected窗口颜色为蓝底白字
   			wnoutrefresh(inputbox[selected]);//刷新窗口
   			doupdate();
  		}
		else if (key==ESC)
 		{
    		return CANCEL;
 		}
		else if (key==ENTER)
 		{
    		return selected;
 		}
		else if (key=='t')/*TAB KEY*/
		{
			wbkgd(inputbox[selected],COLOR_PAIR(BLU_WHI));
			wnoutrefresh(inputbox[selected]);
			selected = (selected == CANCEL) ? OK : CANCEL;//按下't',选择变为另一个选项,如果现在是CANCEL,则选择变为OK,如果现在选择是OK,则选择变为CANCEL,
			wbkgd(inputbox[selected],COLOR_PAIR(WHI_BLU));
			wnoutrefresh(inputbox[selected]);
			doupdate();
		}
	}
}


//////////////////////MENU Function菜单函数//////////////////////
//MENU_OK_ONLY
void MNokonly()
{
	int tmpkey;
	WINDOW **msgbox;
	msgbox = messagebox("OKONLY","OK_ONLY MENU",OK);//显示信息
	tmpkey=getch();
	del_box(msgbox);//删除窗口,回收空间
}


//MENU_OK_CANCEL
void MNokcancel()
{
	int selected_msg;
	WINDOW **msgbox;//定义窗口数组
	WINDOW *messagebar;
	messagebar=subwin(stdscr,1,79,23,1);
	werase(messagebar);//清空窗口
	wrefresh(messagebar);//刷新窗口
	msgbox = messagebox("OK_CANCEL","OK_CANCEL MENU",OK_CANCEL);//显示信息在窗口上
	selected_msg = msgrtn(msgbox);//确定选择的是ok还是cancel
	del_box(msgbox);			//删除窗口
	if(selected_msg == OK)
		wprintw(messagebar,"CHOOSE [OK]!");
	else if(selected_msg == CANCEL)
		wprintw(messagebar,"CHOOSE [CANCEL]!");
	delwin(messagebar);//删除窗口
}


//MENU_INPUT
//topic:input_box's topic
void MNinput(char *topic)
{
	int selected_msg;
	char *inputStr;			//需要输入的字符串
	WINDOW **inputbox;		//设置窗口数组
	WINDOW *messagebar;		//定义信息窗口
	messagebar=subwin(stdscr,1,79,23,1);//设置信息窗口大小
	werase(messagebar);		//清空信息窗口
	wrefresh(messagebar);	//刷新信息窗口
	inputStr = malloc(INPUT_SIZE*sizeof(char));//给字符串开辟空间,大小为30
	memset(inputStr,' ',INPUT_SIZE);	//字符串清零
	if(strlen(topic)==0) 
		topic = "Datech AnWin";
	inputbox = inpbox(topic,inputStr);
		            //inputs(inputbox,inputStr);
	selected_msg = inpboxrtn(inputbox);//选择OK 还是 CANCEL
	del_box(inputbox);	//删除窗口
	curs_set(0);		//设置图标不可见
	if(selected_msg == OK)
		wprintw(messagebar,"Input string is::[%s]",inputStr);
	else if(selected_msg == CANCEL)
		wprintw(messagebar,"User CANCELED!");
	free(inputStr);		//释放空间
	delwin(messagebar);	//删除窗口
}


//MENU_SAVE_AS
void MNsaveas()
{
	MNinput("Input File Name::");
}

//MENU_QUIT 1004  退出选项窗口
int MNquit()
{
	int selected_msg;
	WINDOW **msgbox;		//定义窗口数组
	WINDOW *messagebar;		//定义信息窗口
	messagebar=subwin(stdscr,1,79,23,1);	//定义信息窗口的位置和大小
	werase(messagebar);		//清空信息窗口
	wrefresh(messagebar);	//刷新信息窗口
	msgbox = messagebox("QUIT"," Are You Sure To Quit?",OK_CANCEL); //显示信息
	selected_msg = msgrtn(msgbox);	//选择窗口中的选项
	del_box(msgbox);	//删除窗口
	if(selected_msg == OK)		//选择 OK 返回ESC键的键值
	{
		return 27;//return 27(ESC)
	}
	else if(selected_msg == CANCEL) //否则选择变为cancel 返回5000
	{
		wprintw(messagebar,"User CANCELED!");//输出信息" 用户取消"
		delwin(messagebar);			//删除窗口
		return MNCANCEL;
	}
}
//about目录,一个界面 2000
void MNabout()
{
	int tmpkey;
	WINDOW **msgbox;	//定义窗口,在窗口中分别输入下列信息
	msgbox = messagebox("ABOUT","DaTech(C)AnWin 2004-08-23",OK);
	tmpkey=getch();		//阻塞函数,用户看到窗口中的信息
	del_box(msgbox);	//删除新创建的窗口
}

//help 目录,一个界面
void MNhelp()
{
	int tmpkey;	//定义变量,接收输入的键值
	WINDOW **msgbox;//定义窗口数组,里面函数有若干窗口
	msgbox = messagebox("HELP","Use F1~FX and UP/DOWN/LEFT/RIGHT key choose menu",OK);
	tmpkey=getch();
	del_box(msgbox);
}

//版本目录,一个界面
void MNversion()
{
	int tmpkey;
	WINDOW **msgbox;
	msgbox = messagebox("VERSION","DaTech(C)AnWin Version 1.0",OK);
	tmpkey=getch();
	del_box(msgbox);
}


int main()
{
	int key,tmpkey;
	int menuNo,itemNo;
	WINDOW *menubar,*messagebar;
	init_curses();
	bkgd(COLOR_PAIR(RED_WHI));//设置界面的背景色
	menubar=subwin(stdscr,1,80,0,0);	//菜单窗口
	messagebar=subwin(stdscr,1,79,23,1);//信息窗口
	draw_menubar(menubar);	//填写窗口的内容
	move(2,1);				//移动光标到下一处
	printw("Press F3 or F2 to open the menus. ");//显示提示信息
	printw("ESC quits.");
	refresh();//刷新屏幕
	do
	{
		int selected_item,selected_msg;
		WINDOW **menu_items;	//定义窗口数组
		key=getch();			//接收用户输入
		werase(messagebar);		//清空messagebar窗口中的内容
		wrefresh(messagebar);	//刷新messagebar窗口
		if (key==KEY_F(3))//按下F3键时
        {
        	menu_items=draw_menu(1,menu1,5,MENU_WIDTH);//按下F3时显示的窗口
/*WINDOW **draw_menu(int start_col,char **menu,int count,int width)*/
/**接口:start_col开始的列，**menu内容，count:菜单数目,width菜单宽度**/
       		selected_item=scroll_menu(menu_items,5,1);//返回的窗口号
       		delete_menu(menu_items,6);//删除menu_items中的6个窗口
        }
		else if (key==KEY_F(2))//按下F2键时
        {
		    menu_items=draw_menu(20,menu2,3,MENU_WIDTH);//按下F2时显示的窗口
		    selected_item=scroll_menu(menu_items,3,20);//你选择哪一个窗口,返回的窗口号
		    delete_menu(menu_items,4);//完成后删除这些窗口
        }
		if(selected_item<0)//如果没有选择会提示用户,你没有选择任何子窗口
        	wprintw(messagebar,"You haven't selected any child item");
		else
        {
		    touchwin(stdscr);	//更新窗口函数
		    refresh();			//刷新窗口
		    switch(selected_item)//selected_item:你选择的窗口号
        	{
/********************************
F3键时的几个case选项
*#define MENU_OK_ONLY 1000
*#define MENU_OK_CANCEL 1001
*#define MENU_INPUT 1002
*#define MENU_SAVE_AS 1003
*#define MENU_QUIT 1004

F2键时的几个case选项
*#define MENU_ABOUT 2000
*#define MENU_HELP 2001
*#define MENU_VERSION 2002
****************************/
       	    	case 1000://MENU_OK_ONLY
        			MNokonly();
        			selected_item = 0;
        			break;
        		case 1001://MENU_OK_CANCEL
        			MNokcancel();
        			selected_item = 0;
        			break;
        		case 1002://MENU_INPUT
        			MNinput("Topic_Input");//输入函数
        			selected_item = 0;
        			break;
       			case 1003://MENU_SAVE_AS
        			MNsaveas();
        			selected_item = 0;
        			break;
        		case MENU_QUIT:	//退出选项
					key = MNquit();
                	selected_item = 0;
                 	break;
        		case MENU_ABOUT://2000
					MNabout();	
                	selected_item = 0;
                	break;
        		case MENU_HELP://2001
               		MNhelp();
                	selected_item = 0;
                	break;
        		case MENU_VERSION://2002
                	MNversion();
                	selected_item = 0;
               		 break;
        	}
		}
        touchwin(stdscr);//更新窗口
        refresh();
}while(key!=ESC);		//当按下ESC键时,结束循环
	delwin(messagebar);	//删除显示信息的窗口
	delwin(menubar);	//删除菜单窗口
	endwin();			//关闭curses模式
	return 0;
}



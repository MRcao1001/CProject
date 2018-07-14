#include "play.h"

//进入curse模式
void init_curses(){
    initscr();
    //初始化颜色
    start_color();
    //初始化几种前景和背景
    init_pair(WHI_BLU,COLOR_WHITE,COLOR_BLUE);
    init_pair(BLU_WHI,COLOR_BLUE,COLOR_WHITE);
    init_pair(RED_WHI,COLOR_RED,COLOR_WHITE);
    init_pair(BLK_BLU,COLOR_BLACK,COLOR_BLUE);
    init_pair(YEL_BLU,COLOR_YELLOW,COLOR_BLUE);
    //设置光标不可见
    curs_set(0);
    //关闭输入显示
    noecho();
    //使用curses.h所定义的特殊键必须将keypad设定为TRUE
    keypad(stdscr,TRUE);
}

//绘制窗口
void draw_menubar(long user,long score){
    //设置窗口是白底蓝字
    //移动光标
    move(5,21);
    hline(ACS_HLINE,79);
    move(6,20);
    vline(ACS_VLINE,29);
    move(9,21);
    hline(ACS_HLINE,80);
    move(35,21);
    hline(ACS_HLINE,79);
    move(6,100);
    vline(ACS_VLINE,29);
    move(7,25);
    printw("USERNAME: %ld\t\tSCORE: %ld",user,score);
    move(36,21);
    
}


int main(int argc, char const *argv[])
{
    initscr();
    long user=1001;
    long score=36;
    draw_menubar(user,score);
    getch();
    endwin();
    return 0;
}

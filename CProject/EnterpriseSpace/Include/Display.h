#ifndef DISPLAY_H
#define DISPLAY_H
#include "../Include/PublicHeader.h"
#include "../Include/SmartInput.h"
#include <time.h>/*get local time*/
using namespace std;
class Display{
    public:
        Display();
        void ShowAppLogoFunction();/*显示程序头*/
        void ShowLoginPageFunction(int ModeChose);/*显示登陆提示*/
        void ShowRegPageFunction(int ModeChose);/*显示注册提示*/
        void ShowAppMenuFunction(int ModeChose);/*显示主菜单*/
        void ShowEPHelper();/*显示进入EP提示*/
        bool DoesItNeedToBeDisplayed;/*判断是否需要显示模式选择*/
        string userName;
        string LogTime;
        
    private:
};

#endif
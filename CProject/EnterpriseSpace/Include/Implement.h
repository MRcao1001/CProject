#ifndef IMPLEMENT_H
#define IMPLEMENT_H
#include "../Include/PublicHeader.h"
#include "../Include/Display.h"
#include "../Include/SmartInput.h"
#include "../Include/DataProcessing.h"
#include <time.h>
void Implement();
void Login(int modeChose);
void Register();
void Selection(const int &logRec, string &userName);
string getTime(int type);
//type 1: year;
//type 2: y+m
//type 3: y+m+d
//type 4: y+m+d+h+m+s
void getch();
double thisAccountCanBeUse(string &recod);
class UserLoginTime{
    public:
        UserLoginTime(){}
        string username;
        time_t loginTime;
};
#endif
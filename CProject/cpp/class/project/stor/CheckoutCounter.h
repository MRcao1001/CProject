#ifndef CHECKOUTCOUNTER_H
#define CHECKOUTCOUNTER_H
#include <iostream>
#include <string>

using namespace std;
class CheckOutCounter{
public:
    CheckOutCounter(
            int CollectMoney = 0,
            int Change = 0);
    const string &getGoodsName(int num);
    int getAmount();
    int getTurnover();
    void setTurnover(int money);
    void setAmount(string goodsName,int goodsNum);
private:
    int m_collectMoney;
    int m_change;
    int m_amount = 0;
    int Turnover = 0;
};
#endif
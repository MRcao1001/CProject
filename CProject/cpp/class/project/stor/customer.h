#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>

using namespace std;
class Customer{
public:
    Customer(
            int Cola = 0,
            int Bread = 0,
            int Paper = 0,
            int Cigarette = 0,
            int balance = 300);
    int showGoodsNum(string goodsNum);
    int showBalance();
    int pay(int num);
    void addToShoppingCarts(string goodsName, int goodsNum);
private:
    int m_cola;
    int m_bread;
    int m_paper;
    int m_cigarette;
    int m_balance;
};
#endif
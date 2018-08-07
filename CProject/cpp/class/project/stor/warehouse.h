#ifndef WAREHOSE_H
#define WAREHOSE_H
#include <iostream>
#include <string>

using namespace std;
class Warehose{
public:
    Warehose(
            int Cola = 1000,
            int Bread = 800,
            int Paper = 700,
            int Cigarette = 400);
    int getGoodsNum(string goodsName);
    void setGoodsNum(string goodsName,int goodsNum);
private:
    int m_cola;
    int m_bread;
    int m_paper;
    int m_cigarette;
};
#endif
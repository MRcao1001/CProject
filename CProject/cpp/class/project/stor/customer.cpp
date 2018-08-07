#include "customer.h"

Customer::Customer(int Cola,int Bread,int Paper,int Cigarette, int balance ){
    m_cola = Cola;
    m_bread = Bread;
    m_paper = Paper;
    m_cigarette = Cigarette;
    m_balance = balance;
}



int Customer::showGoodsNum(string goodsName){
    if(goodsName == "cola"){
        return m_cola;
    }
    if(goodsName == "bread"){
        return m_bread;
    }
    if(goodsName == "paper"){
        return m_paper;
    }
    if(goodsName == "cigarette"){
        return m_cigarette;
    }
    return  0;
}

int Customer::showBalance(){
    return m_balance;
}

int Customer::pay(int num){
    m_balance -= num;
    return m_balance;
}

void Customer::addToShoppingCarts(string goodsName, int goodsNum){
    if(goodsName == "cola"){
        m_cola += goodsNum;
        return;
    }
    if(goodsName == "bread"){
        m_bread += goodsNum;
        return;
    }
    if(goodsName == "paper"){
        m_paper += goodsNum;
        return;
    }
    if(goodsName == "cigarette"){
        m_cigarette += goodsNum;
        return;
    }
}
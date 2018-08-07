#include "CheckoutCounter.h"

CheckOutCounter::CheckOutCounter(int CollectMoney, int Change){
    m_collectMoney = CollectMoney;
    m_change = Change;
}


int CheckOutCounter::getAmount(){
    return m_amount;
}

int CheckOutCounter::getTurnover(){
    return Turnover;
}

void CheckOutCounter::setTurnover(int money){
    Turnover+=money;
    return;
}
void CheckOutCounter::setAmount(string goodsName, int goodsNum){
    if(goodsName == "cola"){
        m_amount += 3 *goodsNum;
        cout <<"尖叫"<<3*goodsNum<<endl;
        return;
    }
    if(goodsName == "bread"){
        m_amount += 5*goodsNum;
        cout <<"面包"<<5*goodsNum<<endl;
        return;
    }
    if(goodsName == "paper"){
        m_amount += 10*goodsNum;
        cout <<"餐巾纸"<<10*goodsNum<<endl;
        return;
    }
    if(goodsName == "cigarette"){
        m_amount += 60*goodsNum;
        cout <<"香烟"<<60*goodsNum<<endl;
        return;
    }
    if(goodsName == "all"){
        m_amount = 0;
        return;
    }
}
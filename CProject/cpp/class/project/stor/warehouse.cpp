#include "warehouse.h"

Warehose::Warehose(int Cola,int Bread,int Paper,int Cigarette){
    m_cola = Cola;
    m_bread = Bread;
    m_paper = Paper;
    m_cigarette = Cigarette;
}


int Warehose::getGoodsNum(string goodsName){
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

}

void Warehose::setGoodsNum(string goodsName, int goodsNum){
    if(goodsName == "cola"){
        m_cola -= goodsNum;
        return;
    }
    if(goodsName == "bread"){
        m_bread -= goodsNum;
        return;
    }
    if(goodsName == "paper"){
        m_paper -= goodsNum;
        return;
    }
    if(goodsName == "cigarette"){
        m_cigarette -= goodsNum;
        return;
    }
}
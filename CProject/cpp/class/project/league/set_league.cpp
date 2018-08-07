#include "set_league.h"

SetLeague::SetLeague(int number){
    //num_leagueNum = number;
    switch (number){
        case 1:{
            m_strName = "曲镜折跃";
            m_attact = 600;
            break;
        }
        case 2:{
            m_strName = "飞星乱入";
            m_attact = 800;
            break;
        }
        case 3:{
            m_strName = "星穹暴涨";
            m_attact = 650;
            break;
        }
        case 4:{
            m_strName = "星界束缚";
            m_attact = 550;
            break;
        }
        case 5:{
            m_strName = "镜花水月";
            m_attact = 950;
            break;
        }
        default:{
            m_strName = "平A";
            m_attact = 90;
            break;
        }
    }
}

const string &SetLeague::getName(){
    return m_strName;
}

int SetLeague::getAttack(){
    return m_attact;
}

// void SetLeague::setName(int &number){
    
// }
// void SetLeague::setAttack(int &number){
   
// }
#ifndef CHOSE_LEAGUE_H
#define CHOSE_LEAGUE_H

#include "set_league.h"

class ChoseLeague{
    
public:
    ChoseLeague(string  = "召唤师", int blood = 2000);
    void init();
    SetLeague *setLeague();
    void beAttacked(ChoseLeague &other);
    bool isLose();
    void win();
    void lose();

private:
    int m_number;
    string m_strName = "暗影岛的亡者";
    int m_blood = 1000;
    SetLeague *m_setLeague[3];
};

#endif
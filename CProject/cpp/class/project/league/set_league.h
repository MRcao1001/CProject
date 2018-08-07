#ifndef SET_LEAGUE_H
#define SET_LEAGUE_H

#include <iostream>
#include <string>
using namespace std;
class SetLeague
{
public:
    SetLeague(int number = 0);
    const string &getName();
    int getAttack();
    void setName(int &num);
    void setAttack(int &nuk);
private:
    int num_leagueNum;
    string m_strName = "平A";
    int m_attact = 90;
};

#endif
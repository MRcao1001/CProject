/*
 * @Author: MRcao on ubuntu18.04
 * @Date: 2018-08-01 15:51:32
 * @LastEditors: MRcao
 * @LastEditTime: 2018-08-01 16:14:45
 * @Description: 
 */
#include <iostream>
#include <string>

using namespace std;

struct npc{
    string strName;
    int blood;
    int attack;
    string strKill;

    void fun(){
        cout<<"玩家:"<<strName<<" 血量:"<<blood<<" 使用技能:"<<strKill<<" 攻击力:"<<attack<<endl;
    }

    npc(string Name, string kill, int inBlood, int inAttack){
        strName = Name;
        strKill = kill;
        blood = inBlood;
        attack = inAttack;
    }
};
    
main(int argc, char const *argv[])
{
    npc *newNpc[5] = {NULL};
    newNpc[0] = new npc("佐伊","飞星乱入",1700,800);
    newNpc[1] = new npc("乐芙兰","故技重施""",1700,800);
    newNpc[2] = new npc("莫甘娜","灵魂镣铐",1700,800);
    newNpc[3] = new npc("艾希","万箭齐发",1700,800);
    newNpc[4] = new npc("洛","惊鸿过隙",1700,800);
    
    newNpc[0]->fun();
    newNpc[1]->fun();
    newNpc[2]->fun();
    newNpc[3]->fun();
    newNpc[4]->fun();

    return 0;
}

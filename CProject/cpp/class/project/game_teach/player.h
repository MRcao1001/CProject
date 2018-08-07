#ifndef PLAYER_H
#define PLAYER_H

#include "weapon.h"

class Player
{
public:
	Player(string name = "npc"
		   , int blood = 1000);
	void init(); //武器初始化	
	Weapon *getWeapon();
	void beAttacked(Player &other);
	bool isLose();
	void win();
	void lose();

private:
	string m_strName;
	int m_iBlood;
	Weapon *m_weapon[3];
};

#endif

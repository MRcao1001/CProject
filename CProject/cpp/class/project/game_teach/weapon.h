#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
using namespace std;

class Weapon
{
public:
	Weapon(string name = "木剑", int attack=20);
	const string &getName();
	int getAttack();
	void setName(string &name);
	void setAttack(int attack);

private:
	string m_strName;
	int m_iAttack;
};

#endif

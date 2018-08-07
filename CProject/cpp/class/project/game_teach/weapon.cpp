#include "weapon.h"

Weapon::Weapon(string name, int attack)
{
	m_strName = name;
	m_iAttack = attack;
}

const string & Weapon::getName()
{
	return m_strName;
}

int Weapon::getAttack()
{
	return m_iAttack;
}

void Weapon::setName(string &name)
{
	m_strName = name;
}

void Weapon::setAttack(int attack)
{
	m_iAttack = attack;
}

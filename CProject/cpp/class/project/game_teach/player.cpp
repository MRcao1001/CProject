#include "player.h"
#include <time.h>
#include <stdlib.h>

Player::Player(string name, int blood)
{
	m_strName = name;
	m_iBlood = blood;

	init();  //初始化武器
}

void Player::init()
{
	string strName = "";
	int iAttack = 0;
	for (int i = 0; i<3; i++)
	{
		cout << "请输入武器的名字和攻击值:\n";
		cin >> strName >> iAttack;
		m_weapon[i] = new Weapon(strName, iAttack);
//		m_weapon[i].setName(strName);
//		m_weapon[i].setAttack(iAttack);
	}
}

Weapon* Player::getWeapon()
{
	srand((unsigned int)time(NULL));
	int i = rand()%3;
	return m_weapon[i];
}

void Player::beAttacked(Player &other)
{
	Weapon *weapon = other.getWeapon();
	int iDropBlood = 0;
	if (m_iBlood < weapon->getAttack())
	{
		iDropBlood = m_iBlood;
	}
	else
	{
		iDropBlood = weapon->getAttack();
	}
	m_iBlood -= iDropBlood;

	cout << m_strName << " 受到 " 
		 << other.m_strName << " 使用 " 
		 << weapon->getName() << " 攻击，掉了"
		 << iDropBlood << "点血，剩余血量为"
		 << m_iBlood << endl;
}

bool Player::isLose()
{
	bool bLose = false;
	if (0 == m_iBlood)
	{
		bLose = true;
	}
	return bLose;
}

void Player::win()
{
	cout << m_strName << "说:" << "我是第二，谁是第一?" << endl;
}

void Player::lose()
{
	cout << m_strName << "说:" << "我还会再回来的" << endl;
}





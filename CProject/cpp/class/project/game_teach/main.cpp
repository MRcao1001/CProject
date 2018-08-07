#include "player.h"
#include <unistd.h>

void play(Player &p1, Player &p2)
{
	bool bSign = false;
	while (true)
	{
		if (bSign)
		{
			p2.beAttacked(p1);
			if (p2.isLose())
			{
				p1.win();
				p2.lose();
				break;
			}
		}	
		else 
		{
			p1.beAttacked(p2);
			if (p1.isLose())
			{
				p2.win();
				p1.lose();
				break;
			}
		}
		bSign = !bSign;
		sleep(1);
	}
}

int main(void)
{
	Player p1("张三分", 3000);
	Player p2("王二狗", 3000);

	play(p1, p2);

	return 0;
}

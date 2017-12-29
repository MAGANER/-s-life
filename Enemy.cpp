#include "Enemy.h"

void Enemy::fuck_away()
{
	hero = ' ';
	cout << hero;
}
void Enemy::generate()
{
	int type_number = 1 + rand() % 2;
	if (type_number == 1)
	{
		current_x = 2 + rand() % 170;
		current_y = 2 + rand() % 50;
		type = "Goblin";
	    int class_number = 1 + rand() & 2;
		if (class_number == 1)
		{
			mob_class = "warrior";
			mana = 0;
			speed = 2;
			intellect = 5;
			strength = 10;
			armor = 10 + rand() % 50;
			damage = 10 + rand() % 60;

		}
		if (class_number == 2)
		{
			mob_class = "shaman";
			strength = 0;
			mana = 10;
			speed = 2;
			intellect = 10;
			strength = 0;
			armor = 10 + rand() % 30;
			damage = 20 + rand() % 70;

		}
	}
	if (type_number == 2)
	{
		type = "Ork";
		current_x = 2 + rand() % 170;
		current_y = 2 + rand() % 50;
		int class_number = 1 + rand() % 2;
		if (class_number == 1)
		{
			mob_class = "warrior";
			mana = 0;
			speed = 1;
			intellect = 4;
			strength = 20;
			armor = 10 + rand() % 80;
			damage = 30 + rand() % 90;

		}
		if (class_number == 2)
		{
			mob_class = "shaman";
			mana = 20;
			speed = 1;
			intellect = 15;
			strength = 6;
			armor = 20 + rand() % 50;
			damage = 20 + rand() % 60;
		}
	}
}
Enemy::Enemy()
{
	hero = '&';
	energy = 200;
}
Enemy::~Enemy()
{
}

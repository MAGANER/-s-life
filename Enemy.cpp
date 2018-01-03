#include "Enemy.h"

int Enemy::damage_target()
{
	return damage;
}
void Enemy::detect_target(int target_x,int target_y)
{
	if (target_y == return_y() && target_x > return_x())
	{
		unsigned int range = return_x() - target_x;
		if (range <= vision_range)
		{
			//target is righter
			direction_is_choosed = true;
			direction = 3;
			see_target = true;
		}
	}
	else if (target_y == return_y() && target_x < return_x())
	{
		unsigned int range = return_x() - target_x;
		if (range <= vision_range)
		{
			// target is lefter
			direction_is_choosed = true;
			direction = 4;
			see_target = true;
		}
	}
	else if (target_x == return_x() && target_y > return_y())
	{
		unsigned int range = return_y() - target_y;
		if (range <= vision_range)
		{
			//target is under
			direction_is_choosed = true;
			direction = 2;
			see_target = true;
		}
	}
	else if (target_x == return_x() && target_y < return_y())
	{
		unsigned int range = return_y() - target_y;
		if (range <= vision_range)
		{
			//target is above
			direction_is_choosed = true;
			direction = 1;
			see_target = true;
		}
	}
	else
	{
		direction_is_choosed = false;
		see_target = false;
	}
}
string Enemy::get_class()
{
	return mob_class;
}
int Enemy::get_health()
{
	return health;
}
void Enemy::go()
{
	if (direction_is_choosed == false)
	{
		direction = 1 + rand() % 4;
	}
	if (direction == 1)
	{
		//go up
		bool can_go = (return_y() - get_speed()) <0;
		if (!can_go)
		{
			set_y(return_y() - get_speed());
		}
		else {
			set_y(return_y());
		}
	}
	if (direction == 2)
	{
		//go down
		bool can_go = (return_y() + get_speed()) > 50;
		if (!can_go)
		{
			set_y(return_y() + get_speed());
		}
		else {
			set_y(return_y());
		}
	}
	if (direction == 3)
	{
		// go right
		bool can_go = (return_x() + get_speed()) > 170;
		if (!can_go)
		{
			set_x(return_x() + get_speed());
		}
		else {
			set_x(return_x()-1);
		}
	}
	if (direction == 4)
	{
		//go left
		bool can_go = (return_x() + get_speed()) < 0;
		if (!can_go)
		{
			set_x(return_x() - get_speed());
		}
		else {
			set_x(return_x()+1);
		}
	}
	--energy;
}
void Enemy::fuck_away()
{
	hero = ' ';
}
void Enemy::generate()
{
	int type_number = 1 + rand() % 2;
	if (type_number == 1)
	{
		vision_range = 5;
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
			armor = 1 + rand() % 5;
			damage = 2 + rand() % 7;

		}
		if (class_number == 2)
		{
			mob_class = "shaman";
			strength = 0;
			mana = 10;
			speed = 2;
			intellect = 10;
			strength = 0;
			armor = 1 + rand() % 5;
			damage = 2 + rand() % 13;

		}
	}
	if (type_number == 2)
	{
		vision_range = 7;
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
			armor = 1 + rand() % 8;
			damage = 3 + rand() % 9;

		}
		if (class_number == 2)
		{
			mob_class = "shaman";
			mana = 20;
			speed = 1;
			intellect = 15;
			strength = 6;
			armor = 2 + rand() % 5;
			damage = 2 + rand() % 6;
		}
	}
}
Enemy::Enemy()
{
	direction_is_choosed = false;
	see_target = false;
	hero = '&';
	energy = 200;
}
Enemy::~Enemy()
{
}

#pragma once
#include"stdafx.h"
#include"Object.h"
#include<vector>
class Player
{
private:
	char hero = '@';
	int current_x, current_y,old_x,old_y, health,mana,armor,damage;
public:
	void set_health(int health);
	int taken_items_weight;
	int energy;
	void die();
	int return_health();
	int return_mana();
	int return_armor();
	int return_damage();
	int return_old_x();
	int return_old_y();
	int return_x();
	int return_y();
	void set_x(int x);
	void set_y(int y);
	char return_hero();
	Player();
	~Player();
};


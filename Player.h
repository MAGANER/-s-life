#pragma once
#include"stdafx.h"
#include"Object.h"
#include<vector>
class Player
{
protected:
	char hero;
	int current_x, current_y,old_x,old_y, health,mana,armor,damage;
	int strength, speed, intellect;
public:
	void increase_energy();
	void increase_speed();
	void increase_intellect();
	void increase_strength();
	int get_energy();
	int get_speed();
	int get_intellect();
	int get_strength();
	void set_armor(int armor);
	void set_damage(int damage);
	void set_energy(int energy);
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


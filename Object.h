#pragma once
#include"stdafx.h"
class Object
{
private:
	int health, damage, armor;
	int x, y;
	char view;
	string type;
	int energy;
	int weight;
	int mana;
public:
	void become_used();
	bool show;
	bool equiped;
	void fuck_away();
	int get_mana();
	int get_weight();
	int get_energy();
	int get_x_pos();
	int get_y_pos();
	int get_health();
	int get_damage();
	int get_armor();
	char get_view();
	string get_type();
	void generate();
	Object();
	Object(int energy, int weight, int damage,int health,int armor,string type);
	~Object();
};


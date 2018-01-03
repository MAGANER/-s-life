#pragma once
#include "Player.h"
class Enemy :
	public Player
{
private:
	string type;
	string mob_class;
	int vision_range;
	bool direction_is_choosed;
public:
	int direction;
	bool see_target;
	int damage_target();
	void detect_target(int target_x, int target_y);
	string get_class();
	int get_health();
	void go();
	void generate();
	void fuck_away();
	Enemy();
	~Enemy();
};


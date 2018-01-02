#pragma once
#include "Player.h"
class Enemy :
	public Player
{
private:
	string type;
	string mob_class;
	bool see_target;
	int vision_range;
	int direction;
	bool direction_is_choosed;
public:
	void detect_target(int target_x, int target_y);
	int get_health();
	void go();
	void generate();
	void fuck_away();
	Enemy();
	~Enemy();
};


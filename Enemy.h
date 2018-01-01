#pragma once
#include "Player.h"
class Enemy :
	public Player
{
private:
	string type;
	string mob_class;
public:
	int get_health();
	void go();
	void generate();
	void fuck_away();
	Enemy();
	~Enemy();
};


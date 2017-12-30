#pragma once
#include "Player.h"
class Enemy :
	public Player
{
private:
	string type;
	string mob_class;
public:
	void go();
	void generate();
	void fuck_away();
	Enemy();
	~Enemy();
};


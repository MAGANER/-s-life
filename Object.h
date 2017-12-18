#pragma once
#include"stdafx.h"
class Object
{
private:
	int health, damage, armor;
	bool drawable; // it's drawble if character can see it
	int x, y;
	char view;
	string type;
	int shit;
public:

	int get_x_pos();
	int get_y_pos();
	int get_health();
	int get_damage();
	int get_armor();
	char get_view();
	string get_type();
	bool is_it_drawable();
	bool set_drawableness(bool drawableness);
	void generate();
	Object();
	~Object();
};


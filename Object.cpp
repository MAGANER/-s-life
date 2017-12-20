#include "Object.h"

int Object::get_x_pos()
{
	return x;
}
int Object::get_y_pos()
{
	return y;
}
int Object::get_health()
{
	return health;
}
int Object::get_damage()
{
	return damage;
}
int Object::get_armor()
{
	return armor;
}
char Object::get_view()
{
	return view;
}
string Object::get_type()
{
	return type;
}
void Object::generate()
{
	
	x = 1 + rand() % 170;
	y = 1 + rand() & 50;

	int just_number = 1 + rand() % 2;
	if (just_number == 1)
	{
		type = "food";
		damage = 1; // yeap, we can use food as weapon and armor
		armor = 1;
		int food_number = 1 + rand() % 3;
		if (food_number == 1)
		{
			// it's normal food
			int food_health = 1 + rand() & 50;
			health = food_health;
			view = 'F';
		}
		if (food_number == 2)
		{
			// it's shit
			armor = 0;
			damage = 3; // :Do u understand 
			view = '~';
		}
		if (food_number == 3)
		{
			//it's poisoned food
			int food_health = 1 + rand() & 50;
			health = -food_health;
			view = 'f';
		}
	}
	if (just_number == 2)
	{
		type == "plant";
		int plant_number = 1 + rand() % 3;
		if (plant_number == 1)
		{
			// it's herb
			view = '^';
		}
		if (plant_number == 2)
		{
			// it's flower
			view = 'D';
			int flower_type = 1 + rand() % 3;
			if (flower_type == 1)
			{
				// this flower can be used as reagent in alchemy for creating health potion
				health = 1 + rand() % 10;
				armor = 0;
				damage = 0;
			}
			if (flower_type == 2)
			{
				// this flower can be used as reagent in alchemy for creating armor potion
				health = 0;
				armor = 1 + rand() % 10;
				damage = 0;
			}
			if (flower_type == 3)
			{
				// this flower can be used as reagent in alchemy for creating damage potion
				health = 0;
				armor = 0;
				damage = 1 + rand() % 10;
			}
		}
	}
}
Object::Object()
{
	
}
Object::~Object()
{
}


#include "Player.h"

void Player::set_energy(int energy)
{
	this->energy = this->energy + energy;
}
void Player::set_health(int health)
{
	this->health = this->health + health;
}
void Player::die()
{
	health = health - taken_items_weight;
}
int Player::return_mana()
{
	return mana;
}
int Player::return_health()
{
	return health;
}
int Player::return_damage()
{
	return damage;
}
int Player::return_armor()
{
	return armor;
}
int Player::return_old_x()
{
	return old_x;
}
int Player::return_old_y()
{
	return old_y;
}
void Player::set_x(int x)
{
	old_y = current_y;
	old_x = current_x;
	current_x = x;
}
void Player::set_y(int y)
{
	old_x = current_x;
	old_y = current_y;
	current_y = y;
}
int Player::return_x()
{
	return current_x;
}
int Player::return_y()
{
	return current_y;
}
char Player::return_hero()
{
	return hero;
}
Player::Player()
{
	hero = '@';
	current_x = 4 + rand() & 50;
	current_y = 4 + rand() & 50;
	health = 100;
	damage = 1;
	armor = 10;
	mana = 10;
	energy = 100;
	taken_items_weight = 0;
}     


Player::~Player()
{
}

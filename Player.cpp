#include "Player.h"

void Player::become_fucking_smart()
{
	intellect = 666;
}
void Player::get_damaged(int damage)
{
	if(armor > 0)
	{
		armor = armor - damage;
		if (armor < 0)
		{
			armor = 0;
		}
	}
	else if (armor == 0 || armor < 0)
	{
		health = health - damage;
	}
}
void Player::increase_energy()
{
	energy++;
}
void Player::increase_intellect()
{
	 intellect++;
}
void Player::increase_speed()
{
	speed++;
}
void Player::increase_strength()
{
	strength++;
}
int Player::get_energy()
{
	return energy;
}
int Player::get_strength()
{
	return strength;
}
int Player::get_speed()
{
	return speed;
}
int Player::get_mana()
{
	return mana;
}
int Player::get_intellect()
{
	return intellect;
}
void Player::set_damage(int damage)
{
	this->damage = this->damage + damage;
}
void Player::set_armor(int armor)
{
	this->armor = this->armor + armor;
}
void Player::set_energy(int energy)
{
	this->energy = this->energy + energy;
}
void Player::set_health(int health)
{
	this->health = this->health + health;
}
void Player::set_mana(int mana)
{
	this->mana = this->mana + mana;
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
	speed = 1;
	intellect = 1;
	strength = 1;
	hero = '@';
	current_x = 4;
	current_y = 4;
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

#include"stdafx.h"
#include<stdio.h>
#include<conio.h>
#include"Map.h"
#include"Player.h"
#include<vector>
#include"Object.h"
#include"Inventory.h"

Inventory invt;
Player hero;

int turn = 0;
bool GAME = true;
bool clear_screen = true;

void draw_objects(vector<Object>& creatures);
void enter_command(vector<Object>& creatures);
void draw_game_info();
void draw_game_screen();
void main()
{
	// 1.get number of creatures
	// 2.create them
	srand(time(0));
	int creat_numb = 500 + rand() % 1000;
	vector<Object> creatures(creat_numb, Object());
	for (int counter = 0; counter < creatures.size(); counter++)
	{
		creatures[counter].generate();
	}

	// game cycle
	while (GAME)
	{
		// play if hero is alive
		if (hero.return_health() > 0)
		{
			if (clear_screen)
			{
				draw_objects(creatures);
				draw_game_info();
				draw_game_screen();
				enter_command(creatures);
				// more strength less decrease energy
				system("cls");
			}
			// die if hero hasn't energy else decrease energy
			if (hero.energy > 0)
			{
				hero.energy = hero.energy - 1 - hero.taken_items_weight;
			}
			else {
				hero.die();
			}

			// every 5 turn increase hero strength, energy
			int start_turn = 0; 
			int now_turn = turn;
			if (start_turn + 5 == turn)
			{
				start_turn = turn;
				hero.increase_strength();
				hero.increase_energy();
			}
		}
		else {
			cout << "                          GAME OVER!";
			break;
		}
		
		turn++;
	}

	_getch();
}
void draw_objects(vector<Object>& creatures)
{
	for (int counter = 0; counter < creatures.size(); counter++)
	{
		if (creatures[counter].show == true)
		{
			map[creatures[counter].get_y_pos()][creatures[counter].get_x_pos()] = creatures[counter].get_view();
		}
		else {
			map[creatures[counter].get_y_pos()][creatures[counter].get_x_pos()] = ' ';
		}
	}
}
void draw_game_screen()
{
	for (int line = 0; line < 59; line++)
	{
		for (int colomn = 0; colomn < 175; colomn++)
		{
			cout << map[line][colomn];
			map[hero.return_y()][hero.return_x()] = hero.return_hero();
		}
		cout << endl;
	}
}
void draw_game_info()
{
	cout << "                             " << "PERSONAL INFORMATION" << endl;
	cout << "HEALTH:" << hero.return_health()<<endl;
	cout << "DAMAGE:" << hero.return_damage() << endl;
	cout << "ARMOR:" << hero.return_armor() << endl;
	cout << "MANA:" << hero.return_mana() << endl;
	cout << "ENERGY:" << hero.energy << endl;
	cout << "TAKEN ITEMS' WEIGHT:" << hero.taken_items_weight << endl;
	cout << "TURN:" << turn << endl;
}
void enter_command(vector<Object>& creatures)
{
	cout << endl;
	cout << "COMMANDS:" << endl;
	string command, old_command;
	cin >> command;
	if (command == "go_up")
	{
		hero.set_y(hero.return_y() - hero.get_speed());
		map[hero.return_old_y()][hero.return_old_x()] = ' ';
		clear_screen = true;
	}
	else if (command == "go_down")
	{
		hero.set_y(hero.return_y() + hero.get_speed());
		map[hero.return_old_y()][hero.return_old_x()] = ' ';
		clear_screen = true;
	}
	else if (command == "go_right")
	{
		hero.set_x(hero.return_x() + hero.get_speed());
		map[hero.return_old_y()][hero.return_old_x()] = ' ';
		clear_screen = true;
	}
	else if (command == "go_left")
	{
		hero.set_x(hero.return_x() - hero.get_speed());
		map[hero.return_old_y()][hero.return_old_x()] = ' ';
		clear_screen = true;
	}
	else if (command == "take")
	{
		// character can take item if this item beside its
		for (int counter = 0; counter < creatures.size(); counter++)
		{
			if (hero.return_x() + 1 == creatures[counter].get_x_pos() && hero.return_y() == creatures[counter].get_y_pos())
			{
				hero.taken_items_weight = hero.taken_items_weight + creatures[counter].get_weight();
				invt.add_item(creatures, counter);
				creatures[counter].fuck_away();
				clear_screen = true;
			}
		}
	}
	else if (command == "show_invt")
	{
		invt.show_inventory();
		clear_screen = false;
		enter_command(creatures);
	}
	else if (command == "continue")
	{
		clear_screen = true;
	}
	else if (command == "use")
	{
		string using_type;
		int item_number;
		cout << "enter number of item you want to use:";
		cin >> item_number;
		cout << "enter what do you want to do with that:";
		cin >> using_type;
		if (invt.get_inventory_size() < item_number)
		{
			cout << "you have no " << item_number << "th item!" << endl;
		}
		else {
			if (using_type == "eat")
			{
				if (invt.get_type(item_number) == " stone" || invt.get_type(item_number) == "iron")
				{
					cout << "you can eat " << invt.get_type(item_number) << "!";
					enter_command(creatures);
					clear_screen = false;
				}
				else {
					hero.set_energy(invt.get_energy(item_number));
					hero.set_health(invt.get_health(item_number));
					// if we eat armor or weapon
					// so armor and weapon must be deleted
					// and their weight too
					if (invt.is_equiped(item_number))
					{
						hero.set_armor(-hero.return_armor());
						hero.set_damage(-hero.return_damage() + 1);
					}
					hero.taken_items_weight = hero.taken_items_weight - invt.get_weight(item_number);
					invt.delete_item(item_number);
				}
			}
			if (using_type == "equip")
			{
				string equipment_type;
				cout << "you want to use that as weapon or as armor:";
				cin >> equipment_type;
				if (equipment_type == "weapon")
				{
					hero.set_damage(invt.get_damage(item_number));
				}
				if (equipment_type == "armor")
				{
					hero.set_armor(invt.get_armor(item_number));
				}
				invt.set_equipedness(item_number);
			}
		}
		clear_screen = true;
	}
	else {
		cout << "no " << command << " command!";
		clear_screen = false;
		enter_command(creatures);
	}

}

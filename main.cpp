#include"stdafx.h"
#include<stdio.h>
#include<conio.h>
#include"Map.h"
#include"Player.h"
#include<vector>
#include"Object.h"

Player hero;

bool GAME = true;

void set_start_objects_poses(vector<Object>creatures);
void enter_command(vector<Object> creatures);
void draw_game_info();
void draw_game_screen();
void main()
{
	srand(time(0));
	int creat_numb = 50 + rand() % 100;
	vector<Object> creatures(creat_numb, Object());
	for (int i = 0; i < creatures.size(); i++)
	{
		creatures[i].generate();
	}
	set_start_objects_poses(creatures);

	while (GAME)
	{
		if (hero.return_health() > 0)
		{
			draw_game_info();
			draw_game_screen();
			enter_command(creatures);
			hero.energy = hero.energy - 1 - hero.taken_items_weight;
		}
		else {
			cout << "                                              " << "GAME OVER" << endl;
		}
	}

	_getch();
}
void set_start_objects_poses(vector<Object>creatures)
{
	for (int i = 0; i < creatures.size(); i++)
	{
		map[creatures[i].get_y_pos()][creatures[i].get_x_pos()] = creatures[i].get_view();
	}
}
void draw_game_screen()
{
	int creature_count = 0;
	for (int line = 0; line < 59; line++)
	{
		for (int colomn = 0; colomn < 175; colomn++)
		{
			cout << map[line][colomn];
			map[hero.return_y()][hero.return_x()] = hero.return_hero();
		}
		cout << endl;
		creature_count++;
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
}
void enter_command(vector<Object> creatures)
{
	cout << endl;
	cout << "COMMANDS:" << endl;
	string command;
	cin >> command;
	if (command == "go_up")
	{
		hero.set_y(hero.return_y() - 1);
		map[hero.return_old_y()][hero.return_old_x()] = ' ';
	}
	if (command == "go_down")
	{
		hero.set_y(hero.return_y() + 1);
		map[hero.return_old_y()][hero.return_old_x()] = ' ';
	}
	if (command == "go_right")
	{
		hero.set_x(hero.return_x() + 1);
		map[hero.return_old_y()][hero.return_old_x()] = ' ';
	}
	if (command == "go_left")
	{
		hero.set_x(hero.return_x() - 1);
		map[hero.return_old_y()][hero.return_old_x()] = ' ';
	}
	if (command == "take_item")
	{
		// character can take item if this item beside its

	}
	if (command == "gg")
	{
		for (int i = 0; i < creatures.size(); i++)
		{
		cout << creatures[i].get_x_pos() << endl;
			
		}
	}
	system("cls");
}

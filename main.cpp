#include"stdafx.h"
#include<conio.h>
#include"Map.h"
#include"Player.h"
#include<cstdlib>
Player hero;
bool GAME = true;

void enter_command();
void draw_game_info();
void draw_game_screen();
void main()
{
	while (GAME)
	{
		draw_game_info();
		draw_game_screen();
		enter_command();
	}

	_getch();
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
}
void enter_command()
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
	system("cls");
}
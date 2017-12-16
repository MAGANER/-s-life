#include"stdafx.h"
#include<conio.h>
#include"Map.h"

void enter_command();
void draw_game_info();
void draw_game_screen();
void main()
{
	draw_game_info();
	draw_game_screen();
	enter_command();


	_getch();
}
void draw_game_screen()
{
	for (int line = 0; line < 59; line++)
	{
		for (int colomn = 0; colomn < 175; colomn++)
		{
			cout << map[line][colomn];
		}
		cout << endl;
	}
}
void draw_game_info()
{
	cout << "                  " << "PERSONAL INFORMATION" << endl;
}
void enter_command()
{
	cout << endl;
}